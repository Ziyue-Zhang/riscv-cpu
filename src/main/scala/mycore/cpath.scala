package mycore


import chisel3._
import chisel3.util._


import common.constant._
import common.instructions._
import common.CSR
import common.MemPortIo

//这个是定义cpath到dpath的一些控制信号。
//pc_sel:用于告诉dpath模块pc下一步怎么变化
//op1_sel:操作数1，指定一些特定操作，可以看consts.scala，后面会对consts.scala进行说明
//op2_sel:c操作数2，指定一些特定操作，可以看consts.scala，后面会对consts.scala进行说明
//alu_fun:alu对应的操作类型
//wb_sel:是否进行回写操作
//rf_wen:写寄存器文件使能
//csr_cmd:该指令的操作是否为csr相关指令
//exception:该指令是否为异常/非法指令
class CtlToDatIo extends Bundle() 
{
   val stall     = Output(Bool())
   val pc_sel    = Output(UInt(PC_4.getWidth.W)) 
   val op1_sel   = Output(UInt(OP1_X.getWidth.W)) 
   val op2_sel   = Output(UInt(OP2_X.getWidth.W)) 
   val alu_fun   = Output(UInt(ALU_X.getWidth.W)) 
   val wb_sel    = Output(UInt(WB_X.getWidth.W)) 
   val rf_wen    = Output(Bool()) 
   //val csr_cmd   = Output(UInt(CSR.SZ)) 
   //val exception = Output(Bool())
}

//定义cpath模块的端口
//Flipped是反转的作用，将DebugCPath()中定义的端口反过来，并在cpath模块中命名为dcpath，即input在这边边ouput
//imem是cpath取指令的memory，MemPortIo()在/commo/memory.scala中定义，后面再说明吧，在这里知道它是声明了一片sram就可以了
//dmem是cpath出来数据的memory，MemPortIo()在/commo/memory.scala中定义，后面再说明吧，在这里知道它是声明了一片sram就可以了
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
      ListLookup(io.dat.inst,                                                                                       
                             List(N, BR_N  , OP1_X  ,  OP2_X  , ALU_X   , WB_X   , REN_0, MEN_0, M_X  , MT_X,  CSR.N),
               Array(       /* val  |  BR  |  op1   |   op2     |  ALU    |  wb  | rf   | mem  | mem  | mask |  csr  */
                            /* inst | type |   sel  |    sel    |   fcn   |  sel | wen  |  en  |  wr  | type |  cmd  */
                  LW      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, M_XRD, MT_W,  CSR.N),
                  LB      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, M_XRD, MT_B,  CSR.N),
                  LBU     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, M_XRD, MT_BU, CSR.N),
                  LH      -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, M_XRD, MT_H,  CSR.N),
                  LHU     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_MEM, REN_1, MEN_1, M_XRD, MT_HU, CSR.N),
                  SW      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, M_XWR, MT_W,  CSR.N),
                  SB      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, M_XWR, MT_B,  CSR.N),
                  SH      -> List(Y, BR_N  , OP1_RS1, OP2_IMS , ALU_ADD ,  WB_X  , REN_0, MEN_1, M_XWR, MT_H,  CSR.N),
                  
                  AUIPC   -> List(Y, BR_N  , OP1_IMU, OP2_PC  , ALU_ADD ,  WB_ALU, REN_1, MEN_0, M_X ,  MT_X,  CSR.N),
                  LUI     -> List(Y, BR_N  , OP1_IMU, OP2_X   , ALU_COPY_1, WB_ALU, REN_1, MEN_0, M_X ,  MT_X,  CSR.N),
                 
                  ADDI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_ADD ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  ANDI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_AND ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  ORI     -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_OR  ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  XORI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_XOR ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SLTI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLT ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SLTIU   -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLTU,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SLLI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SLL ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SRAI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRA ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SRLI    -> List(Y, BR_N  , OP1_RS1, OP2_IMI , ALU_SRL ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                   
                  SLL     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLL ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  ADD     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_ADD ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SUB     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SUB ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SLT     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLT ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SLTU    -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SLTU,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  AND     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_AND ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  OR      -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_OR  ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  XOR     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_XOR ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SRA     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRA ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  SRL     -> List(Y, BR_N  , OP1_RS1, OP2_RS2 , ALU_SRL ,  WB_ALU, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  
                  JAL     -> List(Y, BR_J  , OP1_X  , OP2_X   , ALU_X   ,  WB_PC4, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  JALR    -> List(Y, BR_JR , OP1_RS1, OP2_IMI , ALU_X   ,  WB_PC4, REN_1, MEN_0, M_X  , MT_X,  CSR.N),
                  BEQ     -> List(Y, BR_EQ , OP1_X  , OP2_X   , ALU_X   ,  WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.N),
                  BNE     -> List(Y, BR_NE , OP1_X  , OP2_X   , ALU_X   ,  WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.N),
                  BGE     -> List(Y, BR_GE , OP1_X  , OP2_X   , ALU_X   ,  WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.N),
                  BGEU    -> List(Y, BR_GEU, OP1_X  , OP2_X   , ALU_X   ,  WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.N),
                  BLT     -> List(Y, BR_LT , OP1_X  , OP2_X   , ALU_X   ,  WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.N),
                  BLTU    -> List(Y, BR_LTU, OP1_X  , OP2_X   , ALU_X   ,  WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.N),
  
                  CSRRWI  -> List(Y, BR_N  , OP1_IMZ, OP2_X   , ALU_COPY_1, WB_CSR, REN_1, MEN_0, M_X ,  MT_X,  CSR.W),
                  CSRRSI  -> List(Y, BR_N  , OP1_IMZ, OP2_X   , ALU_COPY_1, WB_CSR, REN_1, MEN_0, M_X ,  MT_X,  CSR.S),
                  CSRRCI  -> List(Y, BR_N  , OP1_IMZ, OP2_X   , ALU_COPY_1, WB_CSR, REN_1, MEN_0, M_X ,  MT_X,  CSR.C),
                  CSRRW   -> List(Y, BR_N  , OP1_RS1, OP2_X   , ALU_COPY_1, WB_CSR, REN_1, MEN_0, M_X ,  MT_X,  CSR.W),
                  CSRRS   -> List(Y, BR_N  , OP1_RS1, OP2_X   , ALU_COPY_1, WB_CSR, REN_1, MEN_0, M_X ,  MT_X,  CSR.S),
                  CSRRC   -> List(Y, BR_N  , OP1_RS1, OP2_X   , ALU_COPY_1, WB_CSR, REN_1, MEN_0, M_X ,  MT_X,  CSR.C),
           
                  ECALL   -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.I),
                  MRET    -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.I),
                  DRET    -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.I),
                  EBREAK  -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.I),
                  WFI     -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.N), // implemented as a NOP

                  FENCE_I -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_0, M_X  , MT_X,  CSR.N),
                  FENCE   -> List(Y, BR_N  , OP1_X  , OP2_X  ,  ALU_X    , WB_X  , REN_0, MEN_1, M_X  , MT_X,  CSR.N)
                  // we are already sequentially consistent, so no need to honor the fence instruction
                  ))
                  
   //将csignals中的值，逐一赋给下面的变量，cs_val_ins、cs_br_type、cs_op1_sel……
   // Put these control signals into variables
   val (cs_val_inst: Bool) :: cs_br_type         :: cs_op1_sel            :: cs_op2_sel :: cs0 = csignals
   val cs_alu_fun          :: cs_wb_sel          :: (cs_rf_wen: Bool)     ::               cs1 = cs0
   val (cs_mem_en: Bool)   :: cs_mem_fcn         :: cs_msk_sel            :: cs_csr_cmd :: Nil = cs1
               
   // 利用cs_br_type的新值和io.dat.br_x中的返回值判断下一个pc是否为跳转的情况，为什么要用上io.dat.br_x? 因为某些循环会用到上次的值，例如要循环100次，判断cs_br_type知道指令为跳转指令，但不知道循环了多少次，所以需要用io.dat.br_x来记录
   // Branch Logic   
   val ctrl_pc_sel = //Mux(io.dat.csr_eret  ||
                         //io.ctl.exception     ,  PC_EXC,
                     Mux(cs_br_type === BR_N  ,  PC_4,
                     Mux(cs_br_type === BR_NE ,  Mux(!io.dat.br_eq,  PC_BR, PC_4),
                     Mux(cs_br_type === BR_EQ ,  Mux( io.dat.br_eq,  PC_BR, PC_4),
                     Mux(cs_br_type === BR_GE ,  Mux(!io.dat.br_lt,  PC_BR, PC_4),
                     Mux(cs_br_type === BR_GEU,  Mux(!io.dat.br_ltu, PC_BR, PC_4),
                     Mux(cs_br_type === BR_LT ,  Mux( io.dat.br_lt,  PC_BR, PC_4),
                     Mux(cs_br_type === BR_LTU,  Mux( io.dat.br_ltu, PC_BR, PC_4),
                     Mux(cs_br_type === BR_J  ,  PC_J,
                     Mux(cs_br_type === BR_JR ,  PC_JR,
                                                 PC_4)))))))))//)

   //流水线暂停的标志位，当imem的数据没有准备好，或者正在进行dmem数据写入，且数据还没有完成写成功是，则stall信号为1，使流水线暂停                        
   //val stall =  !io.imem.resp.valid || !((cs_mem_en && io.dmem.resp.valid) || !cs_mem_en)
   val stall = false.B 
 
   //将指令解码的控制信号分别赋给相应的端口，准备好送给dpath
   // Set the data-path control signals
   io.ctl.stall    := stall
   io.ctl.pc_sel   := ctrl_pc_sel
   io.ctl.op1_sel  := cs_op1_sel
   io.ctl.op2_sel  := cs_op2_sel
   io.ctl.alu_fun  := cs_alu_fun
   io.ctl.wb_sel   := cs_wb_sel
   io.ctl.rf_wen   := Mux(stall /*|| io.ctl.exception*/, false.B, cs_rf_wen)
  
   //如果是csr操作指令，则将指令进行解码，并将相应的数据送到dpath中
   //rs1_addr = 指令数据的[19:15]
   //csr_cmd:该指令为csr的set/clear操作
   //csr_cmd:若csr_ren为1，则输出CSR.R，若为0，则输出cs_csr_cmd
   //若stall为1，怎输出CSR.N(没有csr操作指令)，若为0，则输出csr_cmd
   // convert CSR instructions with raddr1 == 0 to read-only CSR commands
   val rs1_addr = io.dat.inst(RS1_MSB, RS1_LSB)
   val csr_ren = (cs_csr_cmd === CSR.S || cs_csr_cmd === CSR.C) && rs1_addr === 0.U
   val csr_cmd = Mux(csr_ren, CSR.R, cs_csr_cmd)

   /*io.ctl.csr_cmd  := Mux(stall, CSR.N, csr_cmd)
   
   //请求指令数据
   // Memory Requests
   io.imem.req.valid    := true.B
   io.imem.req.bits.fcn := M_XRD
   io.imem.req.bits.typ := MT_WU

   io.dmem.req.valid    := cs_mem_en
   io.dmem.req.bits.fcn := cs_mem_fcn
   io.dmem.req.bits.typ := cs_msk_sel
   
   // Exception Handling ---------------------
   // We only need to check if the instruction is illegal (or unsupported)
   // or if the CSR file wants us to be interrupted.
   // Other exceptions are detected later in the pipeline by passing the
   // instruction to the CSR File and letting it redirect the PC as it sees
   // fit.
   //若为非法指令/异常指令，则输出io.ctl.exception到dpath模块
   io.ctl.exception := (!cs_val_inst && io.imem.resp.valid) */
 
}

