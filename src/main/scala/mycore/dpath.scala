package njucore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import common.constant._
import common.instructions._
import common._

class DatToCtlIo extends Bundle() {
  val dec_inst = Output(UInt(XLEN.W))
  val exe_br_eq = Output(Bool())
  val exe_br_lt = Output(Bool())
  val exe_br_ltu = Output(Bool())
  val exe_br_type = Output(UInt(4.W))
  val exe_ctrl_dmem_val = Output(Bool())
  val csr_eret = Output(Bool())
  val inst_valid = Output(Bool())
  val data_valid = Output(Bool())
}

class DpathIo extends Bundle() {
  val ctl = Flipped(new CtlToDatIo())
  val dat = new DatToCtlIo()
  val imem = new MemPortIO(XLEN)
  val dmem = new MemPortIO(XLEN)
  val inst_mmio = Output(Bool())
  val data_mmio = Output(Bool())
}

class zzy_Dpath extends Module {
  val io = IO(new DpathIo())
  io := DontCare

  //**********************************
  // Pipeline State Registers

  // Instruction Fetch State
  val if_reg_pc            = RegInit(UInt(XLEN.W), START_ADDR)
  val inst_valid           = RegInit(false.B)
  val imm_data             = RegInit(0.asUInt(XLEN.W))

  // Instruction Decode State
  val dec_reg_valid        = RegInit(false.B)
  val dec_reg_inst         = RegInit(BUBBLE)
  val dec_reg_pc           = RegInit(0.asUInt(XLEN.W))

  val exe_reg_valid        = RegInit(false.B)
  val exe_reg_inst         = RegInit(BUBBLE)
  val exe_reg_pc           = RegInit(0.asUInt(XLEN.W))
  val exe_reg_wbaddr       = Reg(UInt(5.W))
  val exe_reg_rs1_addr     = Reg(UInt(5.W))
  val exe_reg_rs2_addr     = Reg(UInt(5.W))
  val exe_reg_op1_data     = Reg(UInt(XLEN.W))
  val exe_reg_op2_data     = Reg(UInt(XLEN.W))
  val exe_reg_rs2_data     = Reg(UInt(XLEN.W))
  val exe_reg_ctrl_br_type = RegInit(BR_N)
  val exe_reg_ctrl_op2_sel = Reg(UInt())
  val exe_reg_ctrl_alu_fun = Reg(UInt())
  val exe_reg_ctrl_wb_sel  = Reg(UInt())
  val exe_reg_ctrl_rf_wen  = RegInit(false.B)
  val exe_reg_ctrl_mem_val = RegInit(false.B)
  val exe_reg_ctrl_mem_fcn = RegInit(M_X)
  val exe_reg_ctrl_mem_typ = RegInit(MT_X)
  val exe_reg_ctrl_mem_wid = RegInit(MWD_X)
  val exe_reg_ctrl_csr_cmd = RegInit(CSR.N)

  // Memory State
  val mem_reg_valid        = RegInit(false.B)
  val mem_reg_pc           = Reg(UInt(XLEN.W))
  val mem_reg_inst         = Reg(UInt(XLEN.W))
  val mem_reg_alu_out      = Reg(UInt(XLEN.W))
  val mem_reg_wbaddr       = Reg(UInt())
  val mem_reg_rs1_addr     = Reg(UInt())
  val mem_reg_rs2_addr     = Reg(UInt())
  val mem_reg_op1_data     = Reg(UInt(XLEN.W))
  val mem_reg_op2_data     = Reg(UInt(XLEN.W))
  val mem_reg_rs2_data     = Reg(UInt(XLEN.W))
  val mem_reg_ctrl_rf_wen  = RegInit(false.B)
  val mem_reg_ctrl_mem_val = RegInit(false.B)
  val mem_reg_ctrl_mem_fcn = RegInit(M_X)
  val mem_reg_ctrl_mem_typ = RegInit(MT_X)
  val mem_reg_ctrl_wb_sel  = Reg(UInt())
  val mem_reg_ctrl_mem_wid = RegInit(MWD_X)
  val mem_reg_ctrl_csr_cmd = RegInit(CSR.N)
  val data_valid           = RegInit(false.B)
  val dmm_data_cache       = RegInit(0.asUInt(XLEN.W))
  val dmm_data             = RegInit(0.asUInt(XLEN.W))

  // Writeback State
  val wb_reg_valid         = RegInit(false.B)
  val wb_reg_pc            = Reg(UInt(XLEN.W))
  val wb_reg_inst          = Reg(UInt(XLEN.W))
  val wb_reg_wbaddr        = Reg(UInt())
  val wb_reg_wbdata        = Reg(UInt(XLEN.W))
  val wb_reg_ctrl_rf_wen   = RegInit(false.B)

  //********************************************************************************************************************
  // Instruction Fetch Stage
  val if_pc_next           = Wire(UInt(XLEN.W)) // next_pc
  val exe_brjmp_target     = Wire(UInt(XLEN.W))
  val exe_jump_reg_target  = Wire(UInt(XLEN.W))
  //val exception_target    = Wire(UInt(XLEN.W))
  val alu_stall = Wire(Bool())

  when ((!io.ctl.dec_stall && !io.ctl.full_stall && !alu_stall) || io.ctl.pipeline_kill)
  {
      if_reg_pc := if_pc_next
  }
  
  val if_pc_plus4 = if_reg_pc + 4.asUInt(XLEN.W) 
  
  if_pc_next := Mux(io.ctl.exe_pc_sel === PC_4,      if_pc_plus4,
                Mux(io.ctl.exe_pc_sel === PC_BRJMP,  exe_brjmp_target,
                Mux(io.ctl.exe_pc_sel === PC_JALR,   exe_jump_reg_target,
                BUBBLE))) 

  /*when (io.ctl.fencei && io.ctl.exe_pc_sel === PC_4 &&
         !io.ctl.dec_stall && !io.ctl.full_stall && !alu_stall && !io.ctl.pipeline_kill)
  {
      if_pc_next := if_reg_pc
  }*/

  io.inst_mmio := (if_reg_pc < 0x80000000L.U)

  when(io.imem.resp.valid === true.B){
    inst_valid := true.B
    imm_data  := io.imem.resp.bits.data
  }

  io.imem.req.valid       := !inst_valid
  //io.imem.req.valid       := true.B
  //io.imem.req.bits.addr   :=  Cat(if_reg_pc.asUInt()(XLEN-1, 3), Fill(3, 0.U))
  io.imem.req.bits.addr   := if_reg_pc
  io.imem.req.bits.data   := 0.U
  io.imem.req.bits.wr     := false.B
  io.imem.req.bits.msk    := 2.U

  val if_inst = Mux(if_reg_pc(2), imm_data(63,32), imm_data(31,0))  //模8余0或4
  
  when (io.ctl.pipeline_kill)
  {
      dec_reg_valid := false.B
      dec_reg_inst := BUBBLE
  }
  .elsewhen (!io.ctl.dec_stall && !io.ctl.full_stall && !alu_stall)
  {
      when (io.ctl.if_kill)
      {
         dec_reg_valid := false.B
         dec_reg_inst := BUBBLE
      }
      .otherwise
      {
         dec_reg_valid := true.B
         dec_reg_inst := if_inst
      }
 
      dec_reg_pc := if_reg_pc
      inst_valid := false.B
      imm_data   := 0.U
      data_valid := false.B
      //dmm_data   := 0.U
  }
  when(DEBUG){
  printf("pc=[%x] data_valid=[%d] inst=[%x] inst_valid=[%x] mem_en=[%d] full_stall=[%d]\n",if_reg_pc,data_valid,if_inst,inst_valid,io.dat.exe_ctrl_dmem_val,io.ctl.full_stall)
  }
  //assert(if_reg_pc =/= 0x400026d1L.U)
  //assert(if_reg_pc =/= 0x40002524L.U || io.dmem.resp.valid === 0.U)

  when(DEBUG){
    printf("IF : pc=[%x] inst=[%x] if_pc_next=[%x] pc_sel=[%d] e_bj_pc=[%x]\n", if_reg_pc, if_inst, if_pc_next, io.ctl.exe_pc_sel, exe_brjmp_target)
  }

  //********************************************************************************************************************
  // Decode Stage

  val dec_rs1_addr = dec_reg_inst(19, 15)
  val dec_rs2_addr = dec_reg_inst(24, 20)
  val dec_wbaddr   = dec_reg_inst(11, 7)


  // Register File
  val regfile = Module(new zzy_regfile())
  regfile.io.rs1_addr := dec_rs1_addr
  regfile.io.rs2_addr := dec_rs2_addr
  val rf_rs1_data = regfile.io.rs1_data
  val rf_rs2_data = regfile.io.rs2_data
  regfile.io.waddr := wb_reg_wbaddr 
  regfile.io.wdata := wb_reg_wbdata
  //assert(wb_reg_wbdata =/= 0x400026d1L.U)
  regfile.io.wen   := wb_reg_ctrl_rf_wen

  // immediates
  val imm_itype = dec_reg_inst(31, 20)
  val imm_stype = Cat(dec_reg_inst(31, 25), dec_reg_inst(11, 7))
  val imm_sbtype = Cat(dec_reg_inst(31), dec_reg_inst(7), dec_reg_inst(30, 25), dec_reg_inst(11, 8))
  val imm_utype = dec_reg_inst(31, 12)
  val imm_ujtype = Cat(dec_reg_inst(31), dec_reg_inst(19, 12), dec_reg_inst(20), dec_reg_inst(30, 21))

  val imm_z = Cat(Fill(27, 0.U), dec_reg_inst(19, 15))

  // sign-extend immediates
  val imm_itype_sext  = Cat(Fill(52, imm_itype(11)), imm_itype)
  val imm_stype_sext  = Cat(Fill(52, imm_stype(11)), imm_stype)
  val imm_sbtype_sext = Cat(Fill(51, imm_sbtype(11)), imm_sbtype, 0.U)
  val imm_utype_sext  = Cat(Fill(32, imm_utype(19)), imm_utype, Fill(12, 0.U))
  val imm_ujtype_sext = Cat(Fill(43, imm_ujtype(19)), imm_ujtype, 0.U)

  val dec_alu_op2 = MuxCase(0.U, Array(
    (io.ctl.op2_sel === OP2_RS2)    -> rf_rs2_data,
    (io.ctl.op2_sel === OP2_ITYPE)  -> imm_itype_sext,
    (io.ctl.op2_sel === OP2_STYPE)  -> imm_stype_sext,
    (io.ctl.op2_sel === OP2_SBTYPE) -> imm_sbtype_sext,
    (io.ctl.op2_sel === OP2_UTYPE)  -> imm_utype_sext,
    (io.ctl.op2_sel === OP2_UJTYPE) -> imm_ujtype_sext
  )).asUInt()

  // Bypass Muxes
  val exe_alu_out  = Wire(UInt(XLEN.W))
  val mem_wbdata   = Wire(UInt(XLEN.W))

  val dec_rs1_data = Wire(UInt(XLEN.W))
  val dec_op1_data = Wire(UInt(XLEN.W)) 
  val dec_op2_data = Wire(UInt(XLEN.W))
  val dec_rs2_data = Wire(UInt(XLEN.W)) 

  dec_rs1_data := MuxCase(rf_rs1_data, Array(
    ((exe_reg_wbaddr === dec_rs1_addr) && (dec_rs1_addr =/= 0.U) && exe_reg_ctrl_rf_wen) -> exe_alu_out,
    ((mem_reg_wbaddr === dec_rs1_addr) && (dec_rs1_addr =/= 0.U) && mem_reg_ctrl_rf_wen) -> mem_wbdata,
    ((wb_reg_wbaddr  === dec_rs1_addr) && (dec_rs1_addr =/= 0.U) && wb_reg_ctrl_rf_wen)  -> wb_reg_wbdata
  )) 

  dec_op1_data := MuxCase(dec_rs1_data, Array(
    (io.ctl.op1_sel === OP1_IMZ)    -> imm_z,
    (io.ctl.op1_sel === OP1_PC)     -> dec_reg_pc,
    (io.ctl.op1_sel === OP1_RS1W)   -> Cat(Fill(32, 0.U), dec_rs1_data(31,0))
  ))  
  
  dec_op2_data := MuxCase(dec_alu_op2, Array(
    ((exe_reg_wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && exe_reg_ctrl_rf_wen && (io.ctl.op2_sel === OP2_RS2)) -> exe_alu_out,
    ((mem_reg_wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && mem_reg_ctrl_rf_wen && (io.ctl.op2_sel === OP2_RS2)) -> mem_wbdata,
    ((wb_reg_wbaddr  === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && wb_reg_ctrl_rf_wen  && (io.ctl.op2_sel === OP2_RS2)) -> wb_reg_wbdata
  ))

  dec_rs2_data := MuxCase(rf_rs2_data, Array(
    ((exe_reg_wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && exe_reg_ctrl_rf_wen) -> exe_alu_out,
    ((mem_reg_wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && mem_reg_ctrl_rf_wen) -> mem_wbdata,
    ((wb_reg_wbaddr  === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && wb_reg_ctrl_rf_wen)  -> wb_reg_wbdata
  ))


  when ((io.ctl.dec_stall && !io.ctl.full_stall && !alu_stall) || io.ctl.pipeline_kill)
  {
      // (kill exe stage)
      // insert NOP (bubble) into Execute stage on front-end stall (e.g., hazard clearing)
      exe_reg_valid         := false.B
      exe_reg_inst          := BUBBLE
      exe_reg_wbaddr        := 0.U
      exe_reg_ctrl_rf_wen   := false.B
      exe_reg_ctrl_mem_val  := false.B
      exe_reg_ctrl_mem_fcn  := M_X
      exe_reg_ctrl_mem_wid  := MWD_X
      exe_reg_ctrl_csr_cmd  := CSR.N
      exe_reg_ctrl_br_type  := BR_N
  }
   .elsewhen(!io.ctl.dec_stall && !io.ctl.full_stall && !alu_stall)
  {
      // no stalling...
      exe_reg_pc            := dec_reg_pc
      exe_reg_rs1_addr      := dec_rs1_addr
      exe_reg_rs2_addr      := dec_rs2_addr
      exe_reg_op1_data      := dec_op1_data
      exe_reg_op2_data      := dec_op2_data
      exe_reg_rs2_data      := dec_rs2_data
      exe_reg_ctrl_op2_sel  := io.ctl.op2_sel
      exe_reg_ctrl_alu_fun  := io.ctl.alu_fun
      exe_reg_ctrl_wb_sel   := io.ctl.wb_sel

      when (io.ctl.dec_kill)
      {
         exe_reg_valid         := false.B
         exe_reg_inst          := BUBBLE
         exe_reg_wbaddr        := 0.U
         exe_reg_ctrl_rf_wen   := false.B
         exe_reg_ctrl_mem_val  := false.B
         exe_reg_ctrl_mem_fcn  := M_X
         exe_reg_ctrl_mem_wid  := MWD_X
         exe_reg_ctrl_csr_cmd  := CSR.N
         exe_reg_ctrl_br_type  := BR_N
      }
      .otherwise
      {
         exe_reg_valid         := dec_reg_valid
         exe_reg_inst          := dec_reg_inst
         exe_reg_wbaddr        := dec_wbaddr
         exe_reg_ctrl_rf_wen   := io.ctl.rf_wen
         exe_reg_ctrl_mem_val  := io.ctl.mem_val
         exe_reg_ctrl_mem_fcn  := io.ctl.mem_fcn
         exe_reg_ctrl_mem_typ  := io.ctl.mem_typ
         exe_reg_ctrl_mem_wid  := io.ctl.mem_wid
         exe_reg_ctrl_csr_cmd  := io.ctl.csr_cmd
         exe_reg_ctrl_br_type  := io.ctl.br_type
      }
   }

  when(DEBUG){
    printf("REG: wb_addr = %x, wb_data = %x, wen = %d\n",wb_reg_wbaddr, wb_reg_wbdata, wb_reg_ctrl_rf_wen)
    printf("DEC: valid = %d pc=[%x] inst=[%x] op1=[%x] alu2=[%x] op2=[%x]\n", dec_reg_valid, dec_reg_pc, dec_reg_inst, dec_op1_data, dec_alu_op2, dec_op2_data)
  }

  //********************************************************************************************************************
  // Execute Stage
  val exe_alu_op1 = exe_reg_op1_data.asUInt()
  val exe_alu_op2 = exe_reg_op2_data.asUInt()

  // ALU
  val alu = Module(new zzy_alu)
  alu.io.op := exe_reg_ctrl_alu_fun 
  alu.io.src1 := exe_alu_op1
  alu.io.src2 := exe_alu_op2
  alu_stall := alu.io.stall
  exe_alu_out := MuxCase(alu.io.res, Array(
      (exe_reg_ctrl_wb_sel === WB_ALUW)-> Cat(Fill(32, alu.io.res(31)), alu.io.res(31,0)),
  ))

  val exe_adder_out = (exe_alu_op1 + exe_alu_op2)(XLEN-1,0)

  val brjmp_offset    = exe_reg_op2_data
  exe_brjmp_target    := exe_reg_pc + brjmp_offset
  exe_jump_reg_target := exe_adder_out

  val exe_pc_plus4 = (exe_reg_pc + 4.U) (XLEN - 1, 0)
  
  when (io.ctl.pipeline_kill)
  {
      mem_reg_valid         := false.B
      mem_reg_inst          := BUBBLE
      mem_reg_ctrl_rf_wen   := false.B
      mem_reg_ctrl_mem_val  := false.B
      mem_reg_ctrl_csr_cmd  := false.B
  }
  .elsewhen (!io.ctl.full_stall && !alu_stall)
  {
      mem_reg_valid         := exe_reg_valid
      mem_reg_pc            := exe_reg_pc
      mem_reg_inst          := exe_reg_inst
      mem_reg_alu_out := MuxCase(exe_alu_out, Array(
          (exe_reg_ctrl_wb_sel === WB_PC4) -> exe_pc_plus4
      ))
      mem_reg_wbaddr        := exe_reg_wbaddr
      mem_reg_rs1_addr      := exe_reg_rs1_addr
      mem_reg_rs2_addr      := exe_reg_rs2_addr
      mem_reg_op1_data      := exe_reg_op1_data
      mem_reg_op2_data      := exe_reg_op2_data
      mem_reg_rs2_data      := exe_reg_rs2_data
      mem_reg_ctrl_rf_wen   := exe_reg_ctrl_rf_wen
      mem_reg_ctrl_mem_val  := exe_reg_ctrl_mem_val
      mem_reg_ctrl_mem_fcn  := exe_reg_ctrl_mem_fcn
      mem_reg_ctrl_mem_typ  := exe_reg_ctrl_mem_typ
      mem_reg_ctrl_mem_wid  := exe_reg_ctrl_mem_wid
      mem_reg_ctrl_wb_sel   := exe_reg_ctrl_wb_sel
      mem_reg_ctrl_csr_cmd  := exe_reg_ctrl_csr_cmd
      
      dmm_data              := dmm_data_cache
  }
  
  when(DEBUG){
    printf("ALU: op1 = %x, op2 = %x, res = %x\n",exe_alu_op1, exe_alu_op2, exe_alu_out)
    printf("EXE: valid = %d pc=[%x] inst=[%x] bj_target = [%x]\n", exe_reg_valid, exe_reg_pc, exe_reg_inst, exe_brjmp_target)
  }

  //********************************************************************************************************************
  // Memory Stage
  
  // Control Status Registers
   // The CSRFile can redirect the PC so it's easiest to put this in Execute for now.
  /*val csr = Module(new CSRfile)

  csr.io.inst := mem_reg_inst
  csr.io.csr_op := mem_reg_ctrl_csr_cmd
  csr.io.data_in := mem_reg_alu_out
  csr.io.has_exception := false.B
  csr.io.is_retire := false.B
  csr.io.has_stall := io.ctl.full_stall || alu_stall
  csr.io.in_mem_pc := mem_reg_pc
  csr.io.in_exe_pc := exe_reg_pc
  csr.io.in_dec_pc := dec_reg_pc
  csr.io.in_if_pc  := if_reg_pc

  io.dat.csr_eret  := csr.io.is_redir
  exception_target := csr.io.redir_target*/

  //io.data_readIO.en    := exe_reg_ctrl_mem_fcn === M_XRD   
  //io.data_readIO.addr  := Cat(exe_alu_out.asUIntio.dat.inst_valid := inst_valid)(XLEN-1, 3), Fill(3, 0.U)) 
  //dmm_data := io.dmem.resp.bits.data >> (exe_alu_out(2,0) << 3.U)
  when(io.dmem.resp.valid === true.B){
    data_valid     := true.B
    dmm_data_cache := io.dmem.resp.bits.data >> (exe_alu_out(2,0) << 3.U)
  }
  when(DEBUG){
    printf("MEM read data = [%x]\n", dmm_data)
  }

  val mem_data = MuxCase(dmm_data, Array(
    (mem_reg_ctrl_mem_wid === MWD_B ) -> Cat(Fill(56, dmm_data( 7)), dmm_data(7,0)),
    (mem_reg_ctrl_mem_wid === MWD_BU) -> Cat(Fill(56, 0.U         ), dmm_data(7,0)),
    (mem_reg_ctrl_mem_wid === MWD_H ) -> Cat(Fill(48, dmm_data(15)), dmm_data(15,0)),
    (mem_reg_ctrl_mem_wid === MWD_HU) -> Cat(Fill(48, 0.U         ), dmm_data(15,0)),
    (mem_reg_ctrl_mem_wid === MWD_W ) -> Cat(Fill(32, dmm_data(31)), dmm_data(31,0)),
    (mem_reg_ctrl_mem_wid === MWD_WU) -> Cat(Fill(32, 0.U         ), dmm_data(31,0)),
    (mem_reg_ctrl_mem_wid === MWD_D ) ->                             dmm_data
  ))

  // WB Mux
  mem_wbdata := MuxCase(mem_reg_alu_out, Array(
    (mem_reg_ctrl_wb_sel === WB_MEM) -> mem_data
  ))
 
  when(DEBUG){
    printf("MEM: valid = %d pc=[%x] inst=[%x] wb_sel=[%d] wbdata=[%x]\n", mem_reg_valid, mem_reg_pc, mem_reg_inst, mem_reg_ctrl_wb_sel, mem_wbdata)
  }

  //********************************************************************************************************************
  // Writeback Stage
  when (!io.ctl.full_stall && !alu_stall)
  {
      wb_reg_valid         := mem_reg_valid
      wb_reg_wbaddr        := mem_reg_wbaddr
      wb_reg_wbdata        := mem_wbdata
      wb_reg_pc            := mem_reg_pc
      wb_reg_inst          := mem_reg_inst
      wb_reg_ctrl_rf_wen   := mem_reg_ctrl_rf_wen
  }
  .otherwise
  {
      wb_reg_valid         := false.B
      //wb_reg_ctrl_rf_wen   := false.B
  }

  when(DEBUG){
    printf("WB : valid = %d pc=[%x] inst=[%x], mem_wbdata=[%x], mem_reg_wbaddr=[%d]\n", wb_reg_valid, wb_reg_pc, wb_reg_inst, wb_reg_wbdata, wb_reg_wbaddr)
  }

  //********************************************************************************************************************
  // External Signals

  // datapath to controlpath outputs
  io.dat.dec_inst    := dec_reg_inst 
  io.dat.exe_br_eq   := (exe_reg_op1_data === exe_reg_rs2_data)
  io.dat.exe_br_lt   := (exe_reg_op1_data.asSInt() < exe_reg_rs2_data.asSInt())
  io.dat.exe_br_ltu  := (exe_reg_op1_data.asUInt() < exe_reg_rs2_data.asUInt())
  io.dat.exe_br_type := exe_reg_ctrl_br_type

  io.dat.exe_ctrl_dmem_val := exe_reg_ctrl_mem_val

  io.dat.inst_valid := inst_valid
  io.dat.data_valid := data_valid

  val write_data = MuxCase(exe_reg_rs2_data, Array(
    (exe_reg_ctrl_mem_typ === MT_B)  -> Fill(8, exe_reg_rs2_data( 7,0)),
    (exe_reg_ctrl_mem_typ === MT_H)  -> Fill(4, exe_reg_rs2_data(15,0)),
    (exe_reg_ctrl_mem_typ === MT_W)  -> Fill(2, exe_reg_rs2_data(31,0)),
    (exe_reg_ctrl_mem_typ === MT_D)  ->         exe_reg_rs2_data
  ))    
  val write_mask = Wire(UInt(8.W))
  write_mask := (exe_reg_ctrl_mem_typ << exe_alu_out(2,0))(7,0)      //exe_alu_out为写地址

  io.data_mmio := (exe_alu_out.asUInt() < 0x80000000L.U)

  io.dmem.req.valid     := exe_reg_ctrl_mem_val && !data_valid && inst_valid
  //printf("is_mmio=[%d], dmem_req=[%d]\n",io.data_mmio,exe_reg_ctrl_mem_val && !data_valid && exe_reg_valid && inst_valid)
  //io.dmem.req.bits.addr := Mux(exe_alu_out >= "h8000_0000".U, Cat(exe_alu_out.asUInt()(XLEN-1, 3), Fill(3, 0.U)), exe_alu_out)
  //io.dmem.req.bits.addr := Cat(exe_alu_out.asUInt()(XLEN-1, 3), Fill(3, 0.U)) 
  io.dmem.req.bits.addr := exe_alu_out.asUInt()
  io.dmem.req.bits.data := write_data
  io.dmem.req.bits.wr   := exe_reg_ctrl_mem_fcn === M_XWR
  io.dmem.req.bits.msk  := MuxCase(3.U, Array(
    (exe_reg_ctrl_mem_typ === MT_B)  -> 0.U,
    (exe_reg_ctrl_mem_typ === MT_H)  -> 1.U,
    (exe_reg_ctrl_mem_typ === MT_W)  -> 2.U,
    (exe_reg_ctrl_mem_typ === MT_D)  -> 3.U,
  ))

  //io.data_mmio := (exe_alu_out.asUInt() < 0x80000000L.U) && exe_reg_ctrl_mem_val
  //io.data_writeIO.en   := exe_reg_ctrl_mem_fcn === M_XWR   
  //io.data_writeIO.addr := Cat(exe_alu_out.asUInt()(XLEN-1, 3), Fill(3, 0.U))   
  //io.data_writeIO.data := write_data     
  //io.data_writeIO.mask := write_mask
  when(DEBUG){    
    printf("store:addr = [%x] en=%d data = [%x] mask = %b\n ", io.dmem.req.bits.addr, io.dmem.req.valid, io.dmem.req.bits.data, io.dmem.req.bits.msk)
  }

  when(DEBUG){
    printf("pc=[%x]\n\n", wb_reg_pc)
  }

  BoringUtils.addSource(wb_reg_pc, "diffTestPC")
  BoringUtils.addSource(wb_reg_valid, "diffTestValid")  
}