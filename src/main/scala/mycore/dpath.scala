package mycore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

import common.constant._
import common._

//定义cpath到dpath的一些控制信号
//inst:从memory中读取的instruction
//br_eq:分支判断条件，当判断为相等时
//br_lt:分支判断条件，当有符号数，判断为小于时
//br_ltu:分支判断条件，当无符号数，判断为小于时
//csr_eret:当当前的执行指令为csr的call/break/ret时，该位置1
class DatToCtlIo extends Bundle()
{
  val inst   = Output(UInt(XLEN.W))
  val br_eq  = Output(Bool())
  val br_lt  = Output(Bool())
  val br_ltu = Output(Bool())
  val csr_eret = Output(Bool())
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

  //定义几个32位、wire类型的信号
  //pc_next:下一个pc的值
  //pc_plus4:当前pc+4
  //br_target:分支判断的目标
  //jmp_target:直接跳转的目标
  //jump_reg_target:以寄存器的值为地址的跳转
  // exception_target:异常的跳转
  // Instruction Fetch
  val pc_next          = Wire(UInt(XLEN.W))
  val pc_plus4         = Wire(UInt(XLEN.W))
  val br_target        = Wire(UInt(32.W))
  val jmp_target       = Wire(UInt(32.W))
  val jump_reg_target  = Wire(UInt(32.W))
  
  //val exception_target = Wire(UInt(32.W))
  //pc_next的变化情况，根据io.ctl.pc_sel的值来选择
  // PC Register
  pc_next := MuxCase(pc_plus4, Array(
                  (io.ctl.pc_sel === PC_4)   -> pc_plus4,
                  (io.ctl.pc_sel === PC_BR)  -> br_target,
                  (io.ctl.pc_sel === PC_J )  -> jmp_target,
                  (io.ctl.pc_sel === PC_JR)  -> jump_reg_target
                  //(io.ctl.pc_sel === PC_EXC) -> exception_target
                  ))
   
  //定义一个pc register，初始值为START_ADDR
  val pc_reg = RegInit(UInt(XLEN.W), START_ADDR) 

  //当流水线不暂停时，每个clk上升沿来时，将pc_next的值赋给pc_reg
  when (!io.ctl.stall) 
  {
     pc_reg := pc_next
  }
  
  //pc_plus4的值为pc_reg+4，即当前pc+4，在不支持压缩指令的情况下，pc的运行以word对齐
  pc_plus4 := (pc_reg + 4.asUInt(XLEN.W))


  //请求memory中instruction的数据，请求地址为pc的值，请求信号为true，当io.imem.resp.valid为假//时，inst输出BUBBLE，当然这里永远都是真的
  //io.imem.req.bits.addr := pc_reg
  //io.imem.req.valid := true.B 
  //val inst = Mux(io.imem.resp.valid, io.imem.resp.bits.data, BUBBLE) 
  io.instReadIO.addr := pc_reg
  io.instReadIO.en := true.B
  val inst = Wire(UInt(32.W))
  inst := io.instReadIO.data

  //提前指令中rs1，rs2，wb的地址，提前rs1，rs2，wb通用寄存器的编号，这里需要对RISCV指令比较熟悉
  // Decode
  val rs1_addr = inst(RS1_MSB, RS1_LSB)
  val rs2_addr = inst(RS2_MSB, RS2_LSB)
  val wb_addr  = inst(RD_MSB,  RD_LSB)

  //声明wb_data信号，位宽为conf.xprlen的长度
  val wb_data = Wire(UInt(XLEN.W))
  val wb_wen = io.ctl.rf_wen //&& !io.ctl.exception
 
  //声明通用寄存器，32个通用寄存器，通用寄存器的位宽为conf.xprlen
  // Register File
  val regfile = Mem(32, UInt(XLEN.W))

  //当写寄存器使能了，且写的寄存器编号不为0，同时没有异常生成时，将wb_data赋给相应的寄存器
  //这步操作是在时钟上升沿来时完成，类似于always @(posedge clk)
  when (wb_wen && (wb_addr =/= 0.U))
  {
     regfile(wb_addr) := wb_data
  }

  //根据inst中提取rs1，rs2的寄存器编号，利用这个编号提取寄存器中的值，若rs1和rs2为0时，则
  //rs1_data，rs2_data输出0值
  val rs1_data = Mux((rs1_addr =/= 0.U), regfile(rs1_addr), 0.asUInt(XLEN.W))
  val rs2_data = Mux((rs2_addr =/= 0.U), regfile(rs2_addr), 0.asUInt(XLEN.W))
   
  //如果inst中包含的不是寄存器的编号，即不是rs1，rs2和wb的编号，而是立即数的话，则通过下面
  //的步骤将立即数重组，不同指令有不同立即数类型，这点需要看RISCV指令的用户使用册2.2
  // immediates
  val imm_i = inst(31, 20) 
  val imm_s = Cat(inst(31, 25), inst(11,7))
  val imm_b = Cat(inst(31), inst(7), inst(30,25), inst(11,8))
  val imm_u = inst(31, 12)
  val imm_j = Cat(inst(31), inst(19,12), inst(20), inst(30,21))
  val imm_z = Cat(Fill(27,0.U), inst(19,15))

  //下面是对符号位进行扩展，将符号位进行高位填充
  // sign-extend immediates
  val imm_i_sext = Cat(Fill(20,imm_i(11)), imm_i)
  val imm_s_sext = Cat(Fill(20,imm_s(11)), imm_s)
  val imm_b_sext = Cat(Fill(19,imm_b(11)), imm_b, 0.U)
  val imm_u_sext = Cat(imm_u, Fill(12,0.U))
  val imm_j_sext = Cat(Fill(11,imm_j(19)), imm_j, 0.U)


  //根据ctl.op1_sel信号来选择alu_op1是rs1_data(寄存器的值)，还是U类立即数imm_u_sext，
  //还是Z类的立即数imm_z，或者是0
  val alu_op1 = MuxCase(0.U, Array(
               (io.ctl.op1_sel === OP1_RS1) -> rs1_data,
               (io.ctl.op1_sel === OP1_IMU) -> imm_u_sext,
               (io.ctl.op1_sel === OP1_IMZ) -> imm_z
               )).asUInt()

  //根据ctl.op2_sel信号来选择alu_op2是rs2_data(寄存器的值)，还是pc寄存器的值，还是I类立即数
  //imm_u_sext，还是S类的立即数imm_z，或者是0
  val alu_op2 = MuxCase(0.U, Array(
               (io.ctl.op2_sel === OP2_RS2) -> rs2_data,
               (io.ctl.op2_sel === OP2_PC)  -> pc_reg,
               (io.ctl.op2_sel === OP2_IMI) -> imm_i_sext,
               (io.ctl.op2_sel === OP2_IMS) -> imm_s_sext
               )).asUInt()



  // ALU
  val alu_out   = Wire(UInt(XLEN.W))

  //定义一个alu_shamt信号，取alu_op2数据的低5位
  val alu_shamt = alu_op2(4,0).asUInt()

  //进行ALU运算，根据ctl.alu_fun信号来确定运算的类型，->为运算的逻辑，最后将运算值赋给alu_out
  alu_out := MuxCase(0.U, Array(
                  (io.ctl.alu_fun === ALU_ADD)  -> (alu_op1 + alu_op2).asUInt(),
                  (io.ctl.alu_fun === ALU_SUB)  -> (alu_op1 - alu_op2).asUInt(),
                  (io.ctl.alu_fun === ALU_AND)  -> (alu_op1 & alu_op2).asUInt(),
                  (io.ctl.alu_fun === ALU_OR)   -> (alu_op1 | alu_op2).asUInt(),
                  (io.ctl.alu_fun === ALU_XOR)  -> (alu_op1 ^ alu_op2).asUInt(),
                  (io.ctl.alu_fun === ALU_SLT)  -> (alu_op1.asSInt() < alu_op2.asSInt()).asUInt(),
                  (io.ctl.alu_fun === ALU_SLTU) -> (alu_op1 < alu_op2).asUInt(),
                  (io.ctl.alu_fun === ALU_SLL)  -> ((alu_op1 << alu_shamt)(XLEN, 0)).asUInt(),
                  (io.ctl.alu_fun === ALU_SRA)  -> (alu_op1.asSInt() >> alu_shamt).asUInt(),
                  (io.ctl.alu_fun === ALU_SRL)  -> (alu_op1 >> alu_shamt).asUInt(),
                  (io.ctl.alu_fun === ALU_COPY_1)-> alu_op1
                  ))
   
  //跳转目标的处理
  //br_target:当前pc加br的立即数
  //jmp_target:当前pc+跳转的立即数
  // jump_reg_target:rs1寄存器值+立即数的跳转
  // Branch/Jump Target Calculation
  br_target       := pc_reg + imm_b_sext
  jmp_target      := pc_reg + imm_j_sext
  jump_reg_target := (rs1_data.asUInt() + imm_i_sext.asUInt())

  /*
  // Control Status Registers
  //什么一个csr的模块，调用CSRFile()
  val csr = Module(new CSRFile())
  csr.io := DontCare
  //根据inst数据中的(CSR_ADDR_MSB,CSR_ADDR_LSB)来确定是哪个csr寄存器需要被操作
  csr.io.decode.csr := inst(CSR_ADDR_MSB,CSR_ADDR_LSB)
  //根据ctl.csr_cmd的信号来说明csr的具体操作是什么，如写/读/清除/置位
  csr.io.rw.cmd   := io.ctl.csr_cmd 
  //操作csr寄存器的数据
  csr.io.rw.wdata := alu_out

  //csr寄存器中有一个特别的csr寄存器为instret，用于记录某时刻开始后系统执行了多少条指令
  //这里csr模块中的retire就是用于记录执行了多少条指令，当流水线不暂停时，每个
  //时钟来临，retiret都会为1，然后instret就自动+1
  csr.io.retire    := !(io.ctl.stall || io.ctl.exception)
  //csr寄存器记录系统是否有异常
  csr.io.exception := io.ctl.exception
  //csr模块中的pc信号记录当前pc寄存器的值 
  csr.io.pc        := pc_reg
  //若发生异常时，异常跳转的目标由csr模块中的csr.io.evec(这是一个csr寄存器)给出
  exception_target := csr.io.evec
  //将csr的eret信号传输给cpath模块，用于下一个pc的选择
  io.dat.csr_eret := csr.io.eret

  // Add your own uarch counters here!
  //增加自定义的计数器，非指令集规定的计数器
  csr.io.counters.foreach(_.inc := false.B)*/

  //writeback数据的选择，通过cpath模块传过来WB_ALU信号进行选择，是ALU的运算结果alu_out
  //还是mem数据的读取，还是当前pc+4后的值，还是csr寄存器读取的值
  // WB Mux
  io.dataReadIO.en := true.B
  io.dataReadIO.addr := alu_out
  wb_data := MuxCase(alu_out, Array(
                  (io.ctl.wb_sel === WB_ALU) -> alu_out,
                  (io.ctl.wb_sel === WB_MEM) -> io.dataReadIO.data, 
                  (io.ctl.wb_sel === WB_PC4) -> pc_plus4,
                  //(io.ctl.wb_sel === WB_CSR) -> csr.io.rw.rdata
                  ))



  //dpath模块给cpath模块的数据
  //inst为指令的数据，若(rs1_data === rs2_data)，则br_eq为1，若有符号数(rs1_data.asSInt() < rs2_data.asSInt())
  //则br_lt为1，若无符号数(rs1_data.asUInt() < rs2_data.asUInt())，则br_ltu为1
  // datapath to controlpath outputs
  io.dat.inst   := inst
  io.dat.br_eq  := (rs1_data === rs2_data)
  io.dat.br_lt  := (rs1_data.asSInt() < rs2_data.asSInt()) 
  io.dat.br_ltu := (rs1_data.asUInt() < rs2_data.asUInt())

  //dpath模块请求写data到memory中，请求地址为alu_out，写的数据为无符号的rs2_data
  // datapath to data memory outputs
  io.dataWriteIO.en := true.B
  io.dataWriteIO.addr := alu_out
  io.dataWriteIO.data := rs2_data.asUInt()

  BoringUtils.addSource(VecInit((0 to NUM_REG-1).map(i => regfile(i.U))), "diffTestRegfile") 
  BoringUtils.addSource(pc_reg, "diffTestPC")
}

 
