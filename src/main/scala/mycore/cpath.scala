package njucore

import chisel3._
import chisel3.util._
import common.CSR
import common.constant._
import common.instructions._

class CtlToDatIo extends Bundle(){
  val dec_stall  = Output(Bool())    // stall IF/DEC stages (due to hazards)
  val full_stall = Output(Bool())
  val exe_pc_sel = Output(UInt(2.W))
  val br_type    = Output(UInt(4.W))
  val if_kill    = Output(Bool())
  val dec_kill   = Output(Bool())
  val op1_sel    = Output(UInt(2.W))
  val op2_sel    = Output(UInt(3.W))
  val alu_fun    = Output(UInt(5.W))
  val wb_sel     = Output(UInt(3.W))
  val rf_wen     = Output(Bool())
  val mem_val    = Output(Bool())
  val mem_fcn    = Output(UInt(2.W))
  val mem_typ    = Output(UInt(8.W))
  val mem_wid    = Output(UInt(3.W))
  
  val csr_cmd = Output(UInt(csr_op_size)) 

  val fencei     = Output(Bool())    // pipeline is executing a fencei

  val pipeline_kill = Output(Bool()) // an exception occurred (detected in mem stage).
                                    // Kill the entire pipeline disregard stalls
                                    // and kill if,dec,exe stages
}

class CpathIO extends Bundle{
  val dat = Flipped(new DatToCtlIo())
  val ctl = new CtlToDatIo()

}

class Cpath extends Module{
  val io = IO(new CpathIO())
  io := DontCare

  val csignals =
      ListLookup(io.dat.dec_inst,
                             List(N, BR_N  , OP1_X , OP2_X    , OEN_0, OEN_0, ALU_X   , WB_X  ,  REN_0, MEN_0, M_X  , MT_X , MWD_X, csr_x, N),
               Array(       /* val  |  BR  |  op1  |   op2     |  R1  |  R2  |  ALU    |  wb   | rf   | mem  | mem  | mask | mem  | csr  | fence.i */
                            /* inst | type |   sel |    sel    |  oen |  oen |   fcn   |  sel  | wen  |  en  |  wr  | type | wide | cmd  |         */
                  LD     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_X, MWD_D , csr_x, N),
                  LW     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_X, MWD_W , csr_x, N),
                  LWU    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_X, MWD_WU, csr_x, N),
                  LB     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_X, MWD_B , csr_x, N),
                  LBU    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_X, MWD_BU, csr_x, N),
                  LH     -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_X, MWD_H , csr_x, N),
                  LHU    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_MEM, REN_1, MEN_1, M_XRD, MT_X, MWD_HU, csr_x, N),
                  SD     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_D, MWD_X , csr_x, N),
                  SW     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_W, MWD_X , csr_x, N),
                  SB     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_B, MWD_X , csr_x, N),
                  SH     -> List(Y, BR_N  , OP1_RS1, OP2_STYPE , OEN_1, OEN_1, ALU_ADD , WB_X  , REN_0, MEN_1, M_XWR, MT_H, MWD_X , csr_x, N),

                  AUIPC  -> List(Y, BR_N  , OP1_PC , OP2_UTYPE , OEN_0, OEN_0, ALU_ADD   ,WB_ALU,REN_1, MEN_0, M_X , MT_X, MWD_X ,  csr_x, N),
                  LUI    -> List(Y, BR_N  , OP1_X  , OP2_UTYPE , OEN_0, OEN_0, ALU_COPY_2,WB_ALU,REN_1, MEN_0, M_X , MT_X, MWD_X ,  csr_x, N),

                  ADDI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_ADD , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  ANDI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_AND , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  ORI    -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_OR  , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  XORI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_XOR , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SLTI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SLT , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SLTIU  -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SLTU, WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SLLI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SLL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SRAI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SRA , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SRLI   -> List(Y, BR_N  , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_SRL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),

                  SLL    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SLL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  ADD    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_ADD , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SUB    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SUB , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SLT    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SLT , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SLTU   -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SLTU, WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  AND    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_AND , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  OR     -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_OR  , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  XOR    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_XOR , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SRA    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SRA , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SRL    -> List(Y, BR_N  , OP1_RS1, OP2_RS2   , OEN_1, OEN_1, ALU_SRL , WB_ALU, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),

                  ADDIW  -> List(Y, BR_N  , OP1_RS1 , OP2_ITYPE, OEN_1, OEN_0, ALU_ADD , WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),  
                  SLLIW  -> List(Y, BR_N  , OP1_RS1W, OP2_ITYPE, OEN_1, OEN_0, ALU_SLL , WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SRLIW  -> List(Y, BR_N  , OP1_RS1W, OP2_ITYPE, OEN_1, OEN_0, ALU_SRL , WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SRAIW  -> List(Y, BR_N  , OP1_RS1W, OP2_ITYPE, OEN_1, OEN_0, ALU_SRAW, WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  ADDW   -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_ADD , WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SUBW   -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_SUB , WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SLLW   -> List(Y, BR_N  , OP1_RS1W, OP2_RS2  , OEN_1, OEN_1, ALU_SLL , WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SRAW   -> List(Y, BR_N  , OP1_RS1W, OP2_RS2  , OEN_1, OEN_1, ALU_SRAW, WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  SRLW   -> List(Y, BR_N  , OP1_RS1W, OP2_RS2  , OEN_1, OEN_1, ALU_SRL , WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),

                  JAL    -> List(Y, BR_J  , OP1_RS1, OP2_UJTYPE, OEN_0, OEN_0, ALU_X   , WB_PC4, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  JALR   -> List(Y, BR_JR , OP1_RS1, OP2_ITYPE , OEN_1, OEN_0, ALU_X   , WB_PC4, REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  BEQ    -> List(Y, BR_EQ , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  BNE    -> List(Y, BR_NE , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  BGE    -> List(Y, BR_GE , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  BGEU   -> List(Y, BR_GEU, OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  BLT    -> List(Y, BR_LT , OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  BLTU   -> List(Y, BR_LTU, OP1_RS1, OP2_SBTYPE, OEN_1, OEN_1, ALU_X   , WB_X  , REN_0, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),

                  MUL    -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_MUL  ,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  MULW   -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_MUL  ,WB_ALUW,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  MULH   -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_MULH ,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  MULHSU -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1,ALU_MULHSU,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  MULHU  -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_MULHU,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  DIV    -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_DIV  ,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  DIVUW  -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_DIVUW,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  DIVU   -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_DIVU ,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  DIVW   -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_DIVW ,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  REMW   -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_REMW ,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  REMUW  -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_REMUW,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  REM    -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_REM  ,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  REMU   -> List(Y, BR_N  , OP1_RS1 , OP2_RS2  , OEN_1, OEN_1, ALU_REMU ,WB_ALU ,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_x, N),
                  
                  CSRRWI -> List(Y, BR_N  , OP1_IMZ , OP2_X    , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_w, N),
                  CSRRSI -> List(Y, BR_N  , OP1_IMZ , OP2_X    , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_s, N),
                  CSRRW  -> List(Y, BR_N  , OP1_RS1 , OP2_X    , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_w, N),
                  CSRRS  -> List(Y, BR_N  , OP1_RS1 , OP2_X    , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_s, N),
                  CSRRC  -> List(Y, BR_N  , OP1_RS1 , OP2_X    , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_c, N),
                  CSRRCI -> List(Y, BR_N  , OP1_IMZ , OP2_X    , OEN_1, OEN_1, ALU_COPY_1,WB_CSR,REN_1, MEN_0, M_X  , MT_X, MWD_X , csr_c, N),

                  ECALL  -> List(Y, BR_N  , OP1_X   , OP2_X    , OEN_0, OEN_0, ALU_X     , WB_X ,REN_0, MEN_0, M_X  , MT_X, MWD_X ,csr_prv,N),
                  MRET   -> List(Y, BR_N  , OP1_X   , OP2_X    , OEN_0, OEN_0, ALU_X     , WB_X ,REN_0, MEN_0, M_X  , MT_X, MWD_X ,csr_prv,N),
                  SRET   -> List(Y, BR_N  , OP1_X   , OP2_X    , OEN_0, OEN_0, ALU_X     , WB_X ,REN_0, MEN_0, M_X  , MT_X, MWD_X ,csr_prv,N),
                  EBREAK -> List(Y, BR_N  , OP1_X   , OP2_X    , OEN_0, OEN_0, ALU_X     , WB_X ,REN_0, MEN_0, M_X  , MT_X, MWD_X ,csr_prv,N),
                  WFI    -> List(Y, BR_N  , OP1_X   , OP2_X    , OEN_0, OEN_0, ALU_X     , WB_X ,REN_0, MEN_0, M_X  , MT_X, MWD_X , csr_x, N), // implemented as a NOP

                  FENCE_I-> List(Y, BR_N  , OP1_X   , OP2_X    , OEN_0, OEN_0, ALU_X     , WB_X ,REN_0, MEN_0, M_X  , MT_X, MWD_X , csr_x, Y),
                  // kill pipeline and refetch instructions since the pipeline will be holding stall instructions.
                  FENCE  -> List(Y, BR_N  , OP1_X   , OP2_X    , OEN_0, OEN_0, ALU_X     , WB_X ,REN_0, MEN_1, M_X  , MT_X, MWD_X , csr_x, N)
                  ))
                  
  val (cs_val_inst: Bool) :: cs_br_type :: cs_op1_sel :: cs_op2_sel :: (cs_rs1_oen: Bool) :: (cs_rs2_oen: Bool) :: cs0 = csignals
  val cs_alu_fun :: cs_wb_sel :: (cs_rf_wen: Bool) :: (cs_mem_en: Bool) :: cs_mem_fcn :: cs_msk_sel :: cs_mem_wid :: cs_csr_cmd :: (cs_fencei: Bool) :: Nil = cs0

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

  val ifkill  = (ctrl_exe_pc_sel =/= PC_4) || cs_fencei || RegNext(cs_fencei) 
  val deckill = (ctrl_exe_pc_sel =/= PC_4)

  io.ctl.pipeline_kill := io.dat.csr_eret

  val dec_exception = (!cs_val_inst)

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
  val exe_reg_exception   = RegInit(false.B)

  val exe_reg_is_csr = RegInit(false.B)

  // TODO rename stall==hazard_stall full_stall == cmiss_stall
  val full_stall = Wire(Bool())
  when (!stall && !full_stall)
  {
      when (deckill)
      {
          exe_reg_wbaddr      := 0.U
          exe_reg_ctrl_rf_wen := false.B
          exe_reg_is_csr      := false.B
          exe_reg_exception   := false.B
      }
      .otherwise
      {
          exe_reg_wbaddr      := dec_wbaddr
          exe_reg_ctrl_rf_wen := cs_rf_wen
          exe_reg_is_csr      := ((cs_csr_cmd =/= csr_x) && (cs_csr_cmd =/= csr_prv))
          exe_reg_exception   := dec_exception
      }
  }
  .elsewhen (stall && !full_stall)
  {
      // kill exe stage
      exe_reg_wbaddr      := 0.U
      exe_reg_ctrl_rf_wen := false.B
      exe_reg_is_csr      := false.B
      exe_reg_exception   := false.B
  }

  mem_reg_wbaddr      := exe_reg_wbaddr
  wb_reg_wbaddr       := mem_reg_wbaddr
  mem_reg_ctrl_rf_wen := exe_reg_ctrl_rf_wen
  wb_reg_ctrl_rf_wen  := mem_reg_ctrl_rf_wen

  val exe_inst_is_load = RegInit(false.B)
  
  when (!full_stall)
  {
    exe_inst_is_load := cs_mem_en && (cs_mem_fcn === M_XRD)
  }

  // Stall signal stalls instruction fetch & decode stages,
  // inserts NOP into execute stage,  and drains execute, memory, and writeback stages
  // stalls on I$ misses and on hazards

  stall := ((exe_inst_is_load) && (exe_reg_wbaddr === dec_rs1_addr) && (exe_reg_wbaddr =/= 0.U) && dec_rs1_oen) ||
           ((exe_inst_is_load) && (exe_reg_wbaddr === dec_rs2_addr) && (exe_reg_wbaddr =/= 0.U) && dec_rs2_oen) ||
           (exe_reg_is_csr)

  full_stall := false.B

  // Set the data-path control signals
  io.ctl.dec_stall  := stall
  io.ctl.full_stall := full_stall
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
  io.ctl.mem_wid    := cs_mem_wid
  
  io.ctl.fencei     := cs_fencei || RegNext(cs_fencei)

  val rs1_addr = io.dat.dec_inst(RS1_MSB, RS1_LSB)
  val csr_ren = ((cs_csr_cmd =/= csr_x) && (cs_csr_cmd =/= csr_prv))
  io.ctl.csr_cmd := Mux(csr_ren, csr_r, cs_csr_cmd)

  printf("CTRL : inst = %x, ifkill = %d, deckill = %d, stall = %d\n",io.dat.dec_inst, ifkill, deckill, stall)
}
