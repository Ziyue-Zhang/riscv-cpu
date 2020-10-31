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
}

class DpathIo extends Bundle() {
  val ctl = Flipped(new CtlToDatIo())
  val dat = new DatToCtlIo()
  val inst_readIO = new InstReadIO()
  val data_readIO = new DataReadIO()
  val data_writeIO = new DataWriteIO()
}

class Dpath extends Module {
  val io = IO(new DpathIo())
  io := DontCare

  //**********************************
  // Pipeline State Registers

  // Instruction Fetch State
  val if_reg_pc = RegInit(UInt(XLEN.W), START_ADDR)

  // Instruction Decode State
  val dec_reg_valid = RegInit(false.B)
  val dec_reg_inst = RegInit(BUBBLE)
  val dec_reg_pc = RegInit(0.asUInt(XLEN.W))

  val exe_reg_valid = RegInit(false.B)
  val exe_reg_inst = RegInit(BUBBLE)
  val exe_reg_pc = RegInit(0.asUInt(XLEN.W))
  val exe_reg_wbaddr = Reg(UInt(5.W))
  val exe_reg_rs1_addr = Reg(UInt(5.W))
  val exe_reg_rs2_addr = Reg(UInt(5.W))
  val exe_reg_op1_data = Reg(UInt(XLEN.W))
  val exe_reg_op2_data = Reg(UInt(XLEN.W))
  val exe_reg_rs2_data = Reg(UInt(XLEN.W))
  val exe_reg_ctrl_br_type  = RegInit(BR_N)
  val exe_reg_ctrl_op2_sel = Reg(UInt())
  val exe_reg_ctrl_alu_fun = Reg(UInt())
  val exe_reg_ctrl_wb_sel = Reg(UInt())
  val exe_reg_ctrl_rf_wen = RegInit(false.B)
  val exe_reg_ctrl_mem_val  = RegInit(false.B)
  val exe_reg_ctrl_mem_fcn  = RegInit(M_X)
  val exe_reg_ctrl_mem_typ  = RegInit(MT_X)
  val exe_reg_ctrl_csr_cmd = RegInit(CSR.N)

  // Memory State
  val mem_reg_valid = RegInit(false.B)
  val mem_reg_pc = Reg(UInt(XLEN.W))
  val mem_reg_inst = Reg(UInt(XLEN.W))
  val mem_reg_alu_out = Reg(UInt(XLEN.W))
  val mem_reg_wbaddr = Reg(UInt())
  val mem_reg_rs1_addr = Reg(UInt())
  val mem_reg_rs2_addr = Reg(UInt())
  val mem_reg_op1_data = Reg(UInt(XLEN.W))
  val mem_reg_op2_data = Reg(UInt(XLEN.W))
  val mem_reg_rs2_data = Reg(UInt(XLEN.W))
  val mem_reg_ctrl_rf_wen = RegInit(false.B)
  val mem_reg_ctrl_mem_val  = RegInit(false.B)
  val mem_reg_ctrl_mem_fcn  = RegInit(M_X)
  val mem_reg_ctrl_mem_typ  = RegInit(MT_X)
  val mem_reg_ctrl_wb_sel = Reg(UInt())
  val mem_reg_ctrl_csr_cmd = RegInit(CSR.N)
  val mem_reg_dram_data = RegInit(0.asUInt(XLEN.W))

  // Writeback State
  val wb_reg_valid = RegInit(false.B)
  val wb_reg_pc = Reg(UInt(XLEN.W))
  val wb_reg_inst = Reg(UInt(XLEN.W))
  val wb_reg_wbaddr = Reg(UInt())
  val wb_reg_wbdata = Reg(UInt(XLEN.W))
  val wb_reg_ctrl_rf_wen = RegInit(false.B)


  //******************************************************************************************************
  // Instruction Fetch Stage
  val if_pc_next = Wire(UInt(XLEN.W)) // next_pc
  val exe_brjmp_target = Wire(UInt(XLEN.W))
  val exe_jump_reg_target = Wire(UInt(XLEN.W))
  //  val exception_target    = Wire(UInt(XLEN.W))

  when (!io.ctl.dec_stall)
  {
      if_reg_pc := if_pc_next
  }
  
  val if_pc_plus4 = if_reg_pc + 4.asUInt(XLEN.W) 
  
  if_pc_next := Mux(io.ctl.exe_pc_sel === PC_4,      if_pc_plus4,
                Mux(io.ctl.exe_pc_sel === PC_BRJMP,  exe_brjmp_target,
                Mux(io.ctl.exe_pc_sel === PC_JALR,   exe_jump_reg_target,
                BUBBLE))) 
  
  io.inst_readIO.addr := if_reg_pc
  io.inst_readIO.en := true.B

  val if_inst = io.inst_readIO.data

  when (!io.ctl.dec_stall)
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
  }

  //DEBUG:
  printf("IF : pc=[%x] inst=[%x] if_pc_next=[%x] en=%d pc_sel=[%d] e_bj_pc=[%x]\n", if_reg_pc, if_inst, if_pc_next, io.inst_readIO.en, io.ctl.exe_pc_sel, exe_brjmp_target)


  //******************************************************************************************************
  // Decode Stage

  val dec_rs1_addr = dec_reg_inst(19, 15)
  val dec_rs2_addr = dec_reg_inst(24, 20)
  val dec_wbaddr = dec_reg_inst(11, 7)


  // Register File
  val regfile = Module(new regfile())
  regfile.io.rs1_addr := dec_rs1_addr
  regfile.io.rs2_addr := dec_rs2_addr
  val rf_rs1_data = regfile.io.rs1_data
  val rf_rs2_data = regfile.io.rs2_data
  regfile.io.waddr := wb_reg_wbaddr 
  regfile.io.wdata := wb_reg_wbdata
  regfile.io.wen   := wb_reg_ctrl_rf_wen


  // immediates
  val imm_itype = dec_reg_inst(31, 20)
  val imm_stype = Cat(dec_reg_inst(31, 25), dec_reg_inst(11, 7))
  val imm_sbtype = Cat(dec_reg_inst(31), dec_reg_inst(7), dec_reg_inst(30, 25), dec_reg_inst(11, 8))
  val imm_utype = dec_reg_inst(31, 12)
  val imm_ujtype = Cat(dec_reg_inst(31), dec_reg_inst(19, 12), dec_reg_inst(20), dec_reg_inst(30, 21))

  val imm_z = Cat(Fill(27, 0.U), dec_reg_inst(19, 15))

  // sign-extend immediates
  val imm_itype_sext = Cat(Fill(52, imm_itype(11)), imm_itype)
  val imm_stype_sext = Cat(Fill(52, imm_stype(11)), imm_stype)
  val imm_sbtype_sext = Cat(Fill(51, imm_sbtype(11)), imm_sbtype, 0.U)
  val imm_utype_sext = Cat(Fill(32, imm_utype(19)), imm_utype, Fill(12, 0.U))
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
  val dec_op1_data     = Wire(UInt(XLEN.W)) 
  val dec_op2_data     = Wire(UInt(XLEN.W))
  val dec_rs2_data     = Wire(UInt(XLEN.W)) 



  dec_rs1_data := MuxCase(rf_rs1_data, Array(
    ((exe_reg_wbaddr === dec_rs1_addr) && (dec_rs1_addr =/= 0.U) && exe_reg_ctrl_rf_wen) -> exe_alu_out,
    ((mem_reg_wbaddr === dec_rs1_addr) && (dec_rs1_addr =/= 0.U) && mem_reg_ctrl_rf_wen) -> mem_wbdata,
    ((wb_reg_wbaddr === dec_rs1_addr) && (dec_rs1_addr =/= 0.U) && wb_reg_ctrl_rf_wen)   -> wb_reg_wbdata
  )) 

  dec_op1_data := MuxCase(dec_rs1_data, Array(
    (io.ctl.op1_sel === OP1_IMZ)    -> imm_z,
    (io.ctl.op1_sel === OP1_PC)     -> dec_reg_pc
  )) 
  
  dec_op2_data := MuxCase(dec_alu_op2, Array(
    ((exe_reg_wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && exe_reg_ctrl_rf_wen && (io.ctl.op2_sel === OP2_RS2)) -> exe_alu_out,
    ((mem_reg_wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && mem_reg_ctrl_rf_wen && (io.ctl.op2_sel === OP2_RS2)) -> mem_wbdata,
    ((wb_reg_wbaddr === dec_rs2_addr)  && (dec_rs2_addr =/= 0.U) && wb_reg_ctrl_rf_wen  && (io.ctl.op2_sel === OP2_RS2)) -> wb_reg_wbdata
  ))

  dec_rs2_data := MuxCase(rf_rs2_data, Array(
    ((exe_reg_wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && exe_reg_ctrl_rf_wen) -> exe_alu_out,
    ((mem_reg_wbaddr === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && mem_reg_ctrl_rf_wen) -> mem_wbdata,
    ((wb_reg_wbaddr  === dec_rs2_addr) && (dec_rs2_addr =/= 0.U) && wb_reg_ctrl_rf_wen)  -> wb_reg_wbdata
  ))


  when (io.ctl.dec_stall)
  {
      // (kill exe stage)
      // insert NOP (bubble) into Execute stage on front-end stall (e.g., hazard clearing)
      exe_reg_valid         := false.B
      exe_reg_inst          := BUBBLE
      exe_reg_wbaddr        := 0.U
      exe_reg_ctrl_rf_wen   := false.B
      exe_reg_ctrl_mem_val  := false.B
      exe_reg_ctrl_mem_fcn  := M_X
      exe_reg_ctrl_csr_cmd  := CSR.N
      exe_reg_ctrl_br_type  := BR_N
  }
   .elsewhen(!io.ctl.dec_stall)
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
         exe_reg_ctrl_csr_cmd  := io.ctl.csr_cmd
         exe_reg_ctrl_br_type  := io.ctl.br_type
      }
   }


  printf("DEC: valid = %d pc=[%x] inst=[%x] op1=[%x] alu2=[%x] op2=[%x]\n", dec_reg_valid, dec_reg_pc, dec_reg_inst, dec_op1_data, dec_alu_op2, dec_op2_data)

  //******************************************************************************************************
  // Execute Stage
  val exe_alu_op1 = exe_reg_op1_data.asUInt()
  val exe_alu_op2 = exe_reg_op2_data.asUInt()

  // ALU
  val alu = Module(new alu)
  alu.io.op := exe_reg_ctrl_alu_fun 
  alu.io.src1 := exe_alu_op1
  alu.io.src2 := exe_alu_op2
  exe_alu_out := alu.io.res

  val exe_adder_out = (exe_alu_op1 + exe_alu_op2)(XLEN-1,0)

  val brjmp_offset    = exe_reg_op2_data
  exe_brjmp_target    := exe_reg_pc + brjmp_offset
  exe_jump_reg_target := exe_adder_out

  val exe_pc_plus4 = (exe_reg_pc + 4.U) (XLEN - 1, 0)

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
  mem_reg_ctrl_wb_sel   := exe_reg_ctrl_wb_sel
  mem_reg_ctrl_csr_cmd  := exe_reg_ctrl_csr_cmd




  printf("EXE: valid = %d pc=[%x] inst=[%x] bj_target = [%x]\n", exe_reg_valid, exe_reg_pc, exe_reg_inst, exe_brjmp_target)
 
  //******************************************************************************************************
  // Memory Stage
  val temp = exe_reg_ctrl_mem_fcn === M_XRD
  printf("read en %d\n",temp)
  io.data_readIO.en    := exe_reg_ctrl_mem_fcn === M_XRD   
  io.data_readIO.addr  := exe_alu_out.asUInt()
  mem_reg_dram_data    := io.data_readIO.data
  printf("MEM read data = [%x]\n", mem_reg_dram_data)

  // WB Mux
  mem_wbdata := MuxCase(mem_reg_alu_out, Array(
    (mem_reg_ctrl_wb_sel === WB_MEM) -> mem_reg_dram_data
  ))

  printf("MEM: valid = %d pc=[%x] inst=[%x] wb_sel=[%d] wbdata=[%x]\n", mem_reg_valid, mem_reg_pc, mem_reg_inst, mem_reg_ctrl_wb_sel, mem_wbdata)

  //******************************************************************************************************
  // Writeback Stage
    wb_reg_valid  := mem_reg_valid
    wb_reg_pc     := mem_reg_pc
    wb_reg_inst   := mem_reg_inst
    wb_reg_wbaddr := mem_reg_wbaddr
    wb_reg_wbdata := mem_wbdata
    wb_reg_ctrl_rf_wen := mem_reg_ctrl_rf_wen


  printf("WB : valid = %d pc=[%x] inst=[%x], mem_wbdata=[%x], mem_reg_wbaddr=[%d]\n", wb_reg_valid, wb_reg_pc, RegNext(mem_reg_inst), wb_reg_wbdata, wb_reg_wbaddr)

  //******************************************************************************************************
  // External Signals

  // datapath to controlpath outputs
  io.dat.dec_inst   := dec_reg_inst 
  io.dat.exe_br_eq  := (exe_reg_op1_data === exe_reg_rs2_data)
  io.dat.exe_br_lt  := (exe_reg_op1_data.asSInt() < exe_reg_rs2_data.asSInt())
  io.dat.exe_br_ltu := (exe_reg_op1_data.asUInt() < exe_reg_rs2_data.asUInt())
  io.dat.exe_br_type:= exe_reg_ctrl_br_type

  val writeData = MuxCase(exe_reg_rs2_data, Array(
    (exe_reg_ctrl_mem_typ === MT_B)  -> Fill(8, exe_reg_rs2_data( 7,0)),
    (exe_reg_ctrl_mem_typ === MT_H)  -> Fill(4, exe_reg_rs2_data(15,0)),
    (exe_reg_ctrl_mem_typ === MT_W)  -> Fill(2, exe_reg_rs2_data(31,0)),
    (exe_reg_ctrl_mem_typ === MT_D)  ->         exe_reg_rs2_data,
  ))    
  val writeMask = Wire(UInt(8.W))
  writeMask := (exe_reg_ctrl_mem_typ << exe_alu_out(2,0))(7,0)      

  io.data_writeIO.en   := exe_reg_ctrl_mem_fcn === M_XWR   
  io.data_writeIO.addr := exe_alu_out.asUInt()   
  io.data_writeIO.data := writeData     
  io.data_writeIO.mask := writeMask    
  printf("store:addr = [%x] en=%d data = [%x] mask = %b\n ", io.data_writeIO.addr, io.data_writeIO.en, io.data_writeIO.data, io.data_writeIO.mask)

  printf("pc=[%x] W[r%d=%x][%d] Op1=[r%d][%x] Op2=[r%d][%x] inst=[%x]\n\n",
    wb_reg_pc,
    wb_reg_wbaddr,
    wb_reg_wbdata,
    wb_reg_ctrl_rf_wen,
    RegNext(mem_reg_rs1_addr),
    RegNext(mem_reg_op1_data),
    RegNext(mem_reg_rs2_addr),
    RegNext(mem_reg_op2_data),
    wb_reg_inst)


  BoringUtils.addSource(wb_reg_pc, "diffTestPC")
  BoringUtils.addSource(wb_reg_valid, "diffTestValid")  
}