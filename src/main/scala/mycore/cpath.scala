package mycore


import chisel3._
import chisel3.util._


import common.constant._
import common.instructions._
import common.CSR
import common.MemPortIo

class CtlToDatIo extends Bundle()
{
   val dec_stall  = Output(Bool())    // stall IF/DEC stages (due to hazards)
   val exe_pc_sel = Output(UInt(2.W))
   val br_type    = Output(UInt(4.W))
   val if_kill    = Output(Bool())
   val dec_kill   = Output(Bool())
   val op1_sel    = Output(UInt(2.W))
   val op2_sel    = Output(UInt(3.W))
   val alu_fun    = Output(UInt(4.W))
   val wb_sel     = Output(UInt(2.W))
   val rf_wen     = Output(Bool())
   val mem_val    = Output(Bool())
   val mem_fcn    = Output(UInt(2.W))
   val mem_typ    = Output(UInt(3.W))
   val csr_cmd    = Output(UInt(CSR.SZ))
}

//定义cpath模块的端口
//Flipped是反转的作用，将DebugCPath()中定义的端口反过来，并在cpath模块中命名为dcpath，即input在这边边ouput
//dat是在DatToCtlIo()中声明端口的反端口
//ctl是CtlToDatIo()的调用，CtlToDatIo()在上面已经作了说明，用法是：ctl.exception、ctl.csr_cmd，某些信号在rtl中能找到对应的名字
class CpathIo() extends Bundle() 
{
   val dat  = Flipped(new DatToCtlIo())
   val ctl  = new CtlToDatIo()
}

//这个是主体部分                                                                                                                            
class cpath() extends Module
{                                                                                                                   
  //先声明一个io的端口，调用的就是上面的CpathIo()，并赋随机值
  val io = IO(new CpathIo())
  io := DontCare

   // ListLookup就是查找表，对输入的数据io.dat.inst进行查找，与指令的操作码进行比较，当符合相应指令时，将相应的控制信号赋给csignals，并不是将指令数据直接赋给控制信号，控制信号是有差异的，BR_N  , OP1_X  ,  OP2_X  , ALU_X   , WB_X   , REN_0, MEN_0, M_X  , MT_X,  CSR.N代表的意义各不相同，具体的控制信号意义可以看consts.scala
   val csignals =
      ListLookup(io.dat.dec_inst,
                             List(N, BR_N  , OP1_X , OP2_X    , OEN_0, OEN_0, ALU_X   , WB_X  ,  REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
               Array(       /* val  |  BR  |  op1  |   op2     |  R1  |  R2  |  ALU    |  wb   | rf   | mem  | mem  | mask | csr | fence.i */
                            /* inst | type |   sel |    sel    |  oen |  oen |   fcn   |  sel  | wen  |  en  |  wr  | type | cmd |         */
                  LW     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_W, CSR.N, N),
                  LB     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_B, CSR.N, N),
                  LBU    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_BU,CSR.N, N),
                  LH     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_H, CSR.N, N),
                  LHU    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_HU,CSR.N, N),
                  SW     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_W, CSR.N, N),
                  SB     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_B, CSR.N, N),
                  SH     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_H, CSR.N, N),

                  AUIPC  -> List(Y, BR_N  , OP1_PC , OP2_UTYPE , OEN_0, OEN_0, ALU_ADD   ,WB_ALU,REN_1, MEN_0, M_X , MT_X,  CSR.N, N),
                  LUI    -> List(Y, BR_N  , OP1_X  , OP2_UTYPE , OEN_0, OEN_0, ALU_COPY_2,WB_ALU,REN_1, MEN_0, M_X , MT_X,  CSR.N, N),

                  ADDI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  ANDI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_AND , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  ORI    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_OR  , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  XORI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_XOR , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLTI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SLT , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLTIU  -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SLTU, WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLLI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SLL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SRAI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SRA , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SRLI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SRL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),

                  SLL    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SLL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  ADD    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_ADD , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SUB    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SUB , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLT    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SLT , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SLTU   -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SLTU, WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  AND    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_AND , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  OR     -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_OR  , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  XOR    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_XOR , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SRA    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SRA , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  SRL    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SRL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),

                  JAL    -> List(Y, BR_J  , OP1_RS1, OP2_UJTYPE, OEN_0, OEN_0, ALU_X   , WB_PC4, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  JALR   -> List(Y, BR_JR , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_X   , WB_PC4, REN_1, MEN_0, M_X  , MT_X, CSR.N, N),
                  BEQ    -> List(Y, BR_EQ , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BNE    -> List(Y, BR_NE , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BGE    -> List(Y, BR_GE , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BGEU   -> List(Y, BR_GEU, OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BLT    -> List(Y, BR_LT , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N),
                  BLTU   -> List(Y, BR_LTU, OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, CSR.N, N)
                  // we are already sequentially consistent, so no need to honor the fence instruction
                  ))
                  
   val (cs_val_inst: Bool) :: cs_br_type :: cs_op1_sel :: cs_op2_sel :: (cs_rs1_oen: Bool) :: (cs_rs2_oen: Bool) :: cs0 = csignals
   val cs_alu_fun :: cs_wb_sel :: (cs_rf_wen: Bool) :: (cs_mem_en: Bool) :: cs_mem_fcn :: cs_msk_sel :: cs_csr_cmd :: (cs_fencei: Bool) :: Nil = cs0
               
   // 利用cs_br_type的新值和io.dat.br_x中的返回值判断下一个pc是否为跳转的情况，为什么要用上io.dat.br_x? 因为某些循环会用到上次的值，例如要循环100次，判断cs_br_type知道指令为跳转指令，但不知道循环了多少次，所以需要用io.dat.br_x来记录
   // Branch Logic   
   val ctrl_exe_pc_sel = Mux(false.B                      , PC_EXC,
                         Mux(io.dat.exe_br_type === BR_N  , PC_4,
                         Mux(io.dat.exe_br_type === BR_NE , Mux(!io.dat.exe_br_eq,  PC_BRJMP, PC_4),
                         Mux(io.dat.exe_br_type === BR_EQ , Mux( io.dat.exe_br_eq,  PC_BRJMP, PC_4),
                         Mux(io.dat.exe_br_type === BR_GE , Mux(!io.dat.exe_br_lt,  PC_BRJMP, PC_4),
                         Mux(io.dat.exe_br_type === BR_GEU, Mux(!io.dat.exe_br_ltu, PC_BRJMP, PC_4),
                         Mux(io.dat.exe_br_type === BR_LT , Mux( io.dat.exe_br_lt,  PC_BRJMP, PC_4),
                         Mux(io.dat.exe_br_type === BR_LTU, Mux( io.dat.exe_br_ltu, PC_BRJMP, PC_4),
                         Mux(io.dat.exe_br_type === BR_J  , PC_BRJMP,
                         Mux(io.dat.exe_br_type === BR_JR , PC_JALR,
                                                            PC_4
                     ))))))))))

   val ifkill  = (ctrl_exe_pc_sel =/= PC_4) 
   val deckill = (ctrl_exe_pc_sel =/= PC_4)

   val stall   = Wire(Bool())

   val dec_rs1_addr = io.dat.dec_inst(19, 15)
   val dec_rs2_addr = io.dat.dec_inst(24, 20)
   val dec_wbaddr   = io.dat.dec_inst(11, 7)
   val dec_rs1_oen  = Mux(deckill, false.B, cs_rs1_oen)
   val dec_rs2_oen  = Mux(deckill, false.B, cs_rs2_oen)

   val exe_reg_wbaddr      = Reg(UInt())
   val mem_reg_wbaddr      = Reg(UInt())
   val wb_reg_wbaddr       = Reg(UInt())
   val exe_reg_ctrl_rf_wen = RegInit(false.B)
   val mem_reg_ctrl_rf_wen = RegInit(false.B)
   val wb_reg_ctrl_rf_wen  = RegInit(false.B)
   //val exe_reg_exception   = RegInit(false.B)

   //val exe_reg_is_csr = RegInit(false.B)

   // TODO rename stall==hazard_stall full_stall == cmiss_stall

   when (!stall)
   {
      when (deckill)
      {
         exe_reg_wbaddr      := 0.U
         exe_reg_ctrl_rf_wen := false.B
      }
      .otherwise
      {
         exe_reg_wbaddr      := dec_wbaddr
         exe_reg_ctrl_rf_wen := cs_rf_wen
      }
   }
   .elsewhen (stall)
   {
      // kill exe stage
      exe_reg_wbaddr      := 0.U
      exe_reg_ctrl_rf_wen := false.B
   }

   mem_reg_wbaddr      := exe_reg_wbaddr
   wb_reg_wbaddr       := mem_reg_wbaddr
   mem_reg_ctrl_rf_wen := exe_reg_ctrl_rf_wen
   wb_reg_ctrl_rf_wen  := mem_reg_ctrl_rf_wen

   val exe_inst_is_load = RegInit(false.B)

   exe_inst_is_load := cs_mem_en && (cs_mem_fcn === M_XRD)

   // Stall signal stalls instruction fetch & decode stages,
   // inserts NOP into execute stage,  and drains execute, memory, and writeback stages
   // stalls on I$ misses and on hazards

   stall := ((exe_inst_is_load) && (exe_reg_wbaddr === dec_rs1_addr) && (exe_reg_wbaddr =/= 0.U) && dec_rs1_oen) ||
            ((exe_inst_is_load) && (exe_reg_wbaddr === dec_rs2_addr) && (exe_reg_wbaddr =/= 0.U) && dec_rs2_oen)
 
   //将指令解码的控制信号分别赋给相应的端口，准备好送给dpath
   // Set the data-path control signals
   io.ctl.dec_stall  := stall
   io.ctl.exe_pc_sel := ctrl_exe_pc_sel
   io.ctl.br_type    := cs_br_type
   io.ctl.if_kill    := ifkill
   io.ctl.dec_kill   := deckill
   io.ctl.op1_sel    := cs_op1_sel
   io.ctl.op2_sel    := cs_op2_sel
   io.ctl.alu_fun    := cs_alu_fun
   io.ctl.wb_sel     := cs_wb_sel
   io.ctl.rf_wen     := cs_rf_wen

   io.ctl.mem_val    := cs_mem_en
   io.ctl.mem_fcn    := cs_mem_fcn
   io.ctl.mem_typ    := cs_msk_sel

   // convert CSR instructions with raddr1 == 0 to read-only CSR commands
   val rs1_addr = io.dat.dec_inst(RS1_MSB, RS1_LSB)
   val csr_ren = (cs_csr_cmd === CSR.S || cs_csr_cmd === CSR.C) && rs1_addr === 0.U
   io.ctl.csr_cmd := Mux(csr_ren, CSR.R, cs_csr_cmd)
}

