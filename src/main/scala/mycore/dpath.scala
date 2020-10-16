package mycore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

import common.constant._
import common._

class DatToCtlIo extends Bundle()
{
  val dec_inst   = Output(UInt(XLEN.W))
  val exe_br_eq   = Output(Bool())
  val exe_br_lt   = Output(Bool())
  val exe_br_ltu  = Output(Bool())
  val exe_br_type = Output(UInt(4.W))
}

class DpathIo extends Bundle()
{
  val instReadIO = new InstReadIO()
  val dataReadIO = new DataReadIO()
  val dataWriteIO = new DataWriteIO()
  val ctl  = Flipped(new CtlToDatIo())
  val dat  = new DatToCtlIo()
}

class dpath extends Module
{
  //先声明一个io的端口，调用上面的DpathIo()，并赋随机值
  val io = IO(new DpathIo())
  io := DontCare

  //***********************************************
  // Pipeline State Registers

  // Instruction Fetch State
  val if_reg_pc             = RegInit(START_ADDR - 4.U)
  val if_valid = RegInit(false.B)

  // Instruction Decode State
  val dec_reg_valid         = RegInit(false.B)
  val dec_reg_inst          = RegInit(BUBBLE)
  val dec_reg_pc            = RegInit(0.asUInt(XLEN.W))
  val dec_ready             = Wire(Bool())

  // Execute State
  val exe_reg_valid         = RegInit(false.B)
  val exe_reg_inst          = RegInit(BUBBLE)
  val exe_reg_pc            = RegInit(0.asUInt(XLEN.W))
  val exe_reg_wbaddr        = Reg(UInt(5.W))
  val exe_reg_rs1_addr      = Reg(UInt(5.W))
  val exe_reg_rs2_addr      = Reg(UInt(5.W))
  val exe_reg_op1_data      = Reg(UInt(XLEN.W))
  val exe_reg_op2_data      = Reg(UInt(XLEN.W))
  val exe_reg_rs2_data      = Reg(UInt(XLEN.W))
  val exe_reg_ctrl_br_type  = RegInit(BR_N)
  val exe_reg_ctrl_op2_sel  = Reg(UInt())
  val exe_reg_ctrl_alu_fun  = Reg(UInt())
  val exe_reg_ctrl_wb_sel   = Reg(UInt())
  val exe_reg_ctrl_rf_wen   = RegInit(false.B)
  val exe_reg_ctrl_mem_val  = RegInit(false.B)
  val exe_reg_ctrl_mem_fcn  = RegInit(M_X)
  val exe_reg_ctrl_mem_typ  = RegInit(MT_X)
  val exe_reg_ctrl_csr_cmd  = RegInit(CSR.N)
  val exe_ready             = Wire(Bool())

  // Memory State
  val mem_reg_valid         = RegInit(false.B)
  val mem_reg_pc            = Reg(UInt(XLEN.W))
  val mem_reg_inst          = Reg(UInt(XLEN.W))
  val mem_reg_alu_out       = Reg(Bits())
  val mem_reg_wbaddr        = Reg(UInt())
  val mem_reg_rs1_addr      = Reg(UInt())
  val mem_reg_rs2_addr      = Reg(UInt())
  val mem_reg_op1_data      = Reg(UInt(XLEN.W))
  val mem_reg_op2_data      = Reg(UInt(XLEN.W))
  val mem_reg_rs2_data      = Reg(UInt(XLEN.W))
  val mem_reg_ctrl_rf_wen   = RegInit(false.B)
  val mem_reg_ctrl_mem_val  = RegInit(false.B)
  val mem_reg_ctrl_mem_fcn  = RegInit(M_X)
  val mem_reg_ctrl_mem_typ  = RegInit(MT_X)
  val mem_reg_ctrl_wb_sel   = Reg(UInt())
  val mem_reg_ctrl_csr_cmd  = RegInit(CSR.N)
  val mem_ready             = Wire(Bool())

  // Writeback State
  val wb_reg_valid          = RegInit(false.B)
  val wb_reg_wbaddr         = Reg(UInt())
  val wb_reg_wbdata         = Reg(UInt(XLEN.W))
  val wb_reg_ctrl_rf_wen    = RegInit(false.B)
  val wb_ready              = Wire(Bool())

  //***********************************************
  // Instruction Fetch Stage
  val if_pc_next          = Wire(UInt(XLEN.W))
  val exe_brjmp_target    = Wire(UInt(XLEN.W))
  val exe_jump_reg_target = Wire(UInt(XLEN.W))

  if_reg_pc := if_pc_next

  val if_pc_plus4 = (if_reg_pc + 4.asUInt(XLEN.W))


  if_pc_next := Mux(io.ctl.exe_pc_sel === PC_4,      if_pc_plus4,
                Mux(io.ctl.exe_pc_sel === PC_BRJMP,  exe_brjmp_target,
                Mux(io.ctl.exe_pc_sel === PC_JALR,   exe_jump_reg_target,
                BUBBLE)))    


  // get inst
  io.instReadIO.addr := if_reg_pc
  io.instReadIO.en := true.B
  val if_inst = Wire(UInt(XLEN.W))
  if_inst := io.instReadIO.data

  // pass regs
  dec_reg_valid := true.B
  dec_reg_inst  := if_inst
  dec_reg_pc    := if_reg_pc
  
  //*******************************************************************************************************
  // Decode Stage
  val dec_rs1_addr = dec_reg_inst(19, 15)
  val dec_rs2_addr = dec_reg_inst(24, 20)
  val dec_wbaddr   = dec_reg_inst(11, 7)


  // Register File
  val regfile = Module(new REGFILE())
  regfile.io.rs1_addr := dec_rs1_addr
  regfile.io.rs2_addr := dec_rs2_addr
  val rf_rs1_data = regfile.io.rs1_data
  val rf_rs2_data = regfile.io.rs2_data
  regfile.io.waddr := wb_reg_wbaddr     // 三个写回级的信号
  regfile.io.wdata := wb_reg_wbdata
  regfile.io.wen   := wb_reg_ctrl_rf_wen


  // immediates
  val imm_itype  = dec_reg_inst(31,20)
  val imm_stype  = Cat(dec_reg_inst(31,25), dec_reg_inst(11,7))
  val imm_sbtype = Cat(dec_reg_inst(31), dec_reg_inst(7), dec_reg_inst(30, 25), dec_reg_inst(11,8))
  val imm_utype  = dec_reg_inst(31, 12)
  val imm_ujtype = Cat(dec_reg_inst(31), dec_reg_inst(19,12), dec_reg_inst(20), dec_reg_inst(30,21))

  val imm_z = Cat(Fill(27,0.U), dec_reg_inst(19,15))

  // sign-extend immediates
  val imm_itype_sext  = Cat(Fill(52,imm_itype(11)), imm_itype)
  val imm_stype_sext  = Cat(Fill(52,imm_stype(11)), imm_stype)
  val imm_sbtype_sext = Cat(Fill(51,imm_sbtype(11)), imm_sbtype, 0.U)
  val imm_utype_sext  = Cat(Fill(32,imm_utype(19)), imm_utype, Fill(12,0.U))  // TODO: 改其他的!
  val imm_ujtype_sext = Cat(Fill(43,imm_ujtype(19)), imm_ujtype, 0.U)


  // Operand 2 Mux
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

  val dec_op1_data = Wire(UInt(XLEN.W))
  val dec_op2_data = Wire(UInt(XLEN.W))
  val dec_rs2_data = Wire(UInt(XLEN.W))


  // Rely only on control interlocking to resolve hazards
  dec_op1_data := MuxCase(rf_rs1_data, Array(
    ((io.ctl.op1_sel === OP1_IMZ)) -> imm_z,
    ((io.ctl.op1_sel === OP1_PC))  -> dec_reg_pc
  ))
  dec_rs2_data := rf_rs2_data
  dec_op2_data := dec_alu_op2

   // 传递流水线
  exe_reg_pc            := dec_reg_pc
  exe_reg_rs1_addr      := dec_rs1_addr
  exe_reg_rs2_addr      := dec_rs2_addr
  exe_reg_op1_data      := dec_op1_data
  exe_reg_op2_data      := dec_op2_data
  exe_reg_rs2_data      := dec_rs2_data
  exe_reg_ctrl_op2_sel  := io.ctl.op2_sel
  exe_reg_ctrl_alu_fun  := io.ctl.alu_fun
  exe_reg_ctrl_wb_sel   := io.ctl.wb_sel

  exe_reg_valid         := dec_reg_valid
  exe_reg_inst          := dec_reg_inst
  exe_reg_wbaddr        := dec_wbaddr
  exe_reg_ctrl_rf_wen   := io.ctl.rf_wen
  exe_reg_ctrl_mem_val  := io.ctl.mem_val
  exe_reg_ctrl_mem_fcn  := io.ctl.mem_fcn
  exe_reg_ctrl_mem_typ  := io.ctl.mem_typ
//  exe_reg_ctrl_csr_cmd  := io.ctl.csr_cmd
  exe_reg_ctrl_br_type  := io.ctl.br_type

//******************************************************************************************************
  // Execute Stage

  val exe_alu_op1 = exe_reg_op1_data.asUInt()
  val exe_alu_op2 = exe_reg_op2_data.asUInt()

  // ALU
  val alu = Module(new alu)
  alu.io.op := exe_reg_ctrl_alu_fun    
  alu.io.src1   := exe_alu_op1
  alu.io.src2   := exe_alu_op2
  exe_alu_out   := alu.io.res
  val exe_adder_out = (exe_alu_op1 + exe_alu_op2)(XLEN-1,0)

  // Branch/Jump Target Calculation
  val brjmp_offset     = exe_reg_op2_data
  exe_brjmp_target    := exe_reg_pc + brjmp_offset
  exe_jump_reg_target := exe_adder_out

  // 传递流水线
  mem_reg_valid         := exe_reg_valid
  mem_reg_pc            := exe_reg_pc
  mem_reg_inst          := exe_reg_inst
  mem_reg_alu_out       := exe_alu_out
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

  printf("EXE: alu_op=[%x] alu_out=[%x] \n",alu.io.op,exe_alu_out)
  printf("EXE: pc=[%x] inst=[%x] \n",exe_reg_pc, exe_reg_inst)

  //******************************************************************************************************
  // Memory Stage

  // WB Mux
  mem_wbdata := MuxCase(mem_reg_alu_out, Array(
    (mem_reg_ctrl_wb_sel === WB_ALU) -> mem_reg_alu_out,
    (mem_reg_ctrl_wb_sel === WB_PC4) -> mem_reg_alu_out
//    (mem_reg_ctrl_wb_sel === WB_MEM) -> io.dmem.resp.bits.data
  ))

  printf("MEM: pc=[%x] inst=[%x] wb_sel=[%d] wbdata=[%x]\n", mem_reg_pc, mem_reg_inst, mem_reg_ctrl_wb_sel, mem_wbdata)

  //******************************************************************************************************
  // Writeback Stage

  wb_reg_valid         := mem_reg_valid
  wb_reg_wbaddr        := mem_reg_wbaddr
  wb_reg_wbdata        := mem_wbdata
  wb_reg_ctrl_rf_wen   := mem_reg_ctrl_rf_wen

  printf("WB : pc=[%x] inst=[%x]\n", RegNext(mem_reg_pc), RegNext(mem_reg_inst))

  //******************************************************************************************************
  // External Signals

  // datapath to controlpath outputs
  io.dat.dec_inst   := dec_reg_inst
  io.dat.exe_br_eq  := (exe_reg_op1_data === exe_reg_rs2_data)
  io.dat.exe_br_lt  := (exe_reg_op1_data.asSInt() < exe_reg_rs2_data.asSInt())
  io.dat.exe_br_ltu := (exe_reg_op1_data.asUInt() < exe_reg_rs2_data.asUInt())
  io.dat.exe_br_type:= exe_reg_ctrl_br_type
  
  // datapath to data memory outputs
  io.dataWriteIO.en := true.B
  io.dataWriteIO.addr := mem_reg_alu_out.asUInt()
  io.dataWriteIO.data := mem_reg_rs2_data     
}

 

