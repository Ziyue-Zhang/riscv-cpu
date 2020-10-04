package common

import chisel3._
import chisel3.util.log2Ceil

object constant extends RiscvConstants
                with MemoryOpConstants 
{
}

trait RiscvConstants
{
  val XLEN    = 32
  val WIDE    = log2Ceil(XLEN)
  val NUM_REG = 32

  val RD_MSB = 11
  val RD_LSB = 7
  val RS1_MSB = 19
  val RS1_LSB = 15
  val RS2_MSB = 24
  val RS2_LSB = 20

  val CSR_ADDR_MSB = 31
  val CSR_ADDR_LSB = 20

  val x0 = 0.U

  val BUBBLE = 0X4033.U(64.W)

  val ALU_ADD    = 0.asUInt(4.W)
  val ALU_SUB    = 1.asUInt(4.W)
  val ALU_AND    = 2.asUInt(4.W)
  val ALU_OR     = 3.asUInt(4.W)
  val ALU_XOR    = 4.asUInt(4.W)
  val ALU_SLT    = 5.asUInt(4.W)
  val ALU_SLTU   = 6.asUInt(4.W)
  val ALU_SLL    = 7.asUInt(4.W)
  val ALU_SRA    = 8.asUInt(4.W)
  val ALU_SRL    = 9.asUInt(4.W)
  val ALU_COPY_1 = 10.asUInt(4.W)
  val ALU_COPY_2 = 11.asUInt(4.W)
  val ALU_X      = 0.asUInt(4.W)

  //定义Y为true的布尔量，N为false的布尔量
  val Y      = true.B
  val N      = false.B

  val START_ADDR = "h80000000".U

  //PC的选择信号
  //PC_4  		---  	PC+4 			--- 位宽为3bits的信号，0值
  //PC_BR 		---  分支目标 			--- 位宽为3bits的信号，1值
  //PC_J  		---  跳转目标 			--- 位宽为3bits的信号，2值
  //PC_JR 		---  跳转寄存器目标 		--- 位宽为3bits的信号，3值
  //PC_EXC 	---  异常 				--- 位宽为3bits的信号，4值
  // PC Select Signal
  val PC_4   = 0.asUInt(3.W)  // PC + 4
  val PC_BR  = 1.asUInt(3.W)  // branch_target
  val PC_J   = 2.asUInt(3.W)  // jump_target
  val PC_JR  = 3.asUInt(3.W)  // jump_reg_target
  val PC_EXC = 4.asUInt(3.W)  // exception
  
  //分支类型
  //BR_N	---	下一个PC				---	位宽为4bits的信号，0值
  //BR_NE	---	不等于				---	位宽为4bits的信号，1值
  //BR_EQ	---	等于				---	位宽为4bits的信号，2值
  //BR_GE	---	大于等于				---	位宽为4bits的信号，3值
  //BR_GEU	---	大于等于(无符号数)	---	位宽为4bits的信号，4值
  //BR_LT	---	小于				---	位宽为4bits的信号，5值
  //BR_LTU	---	小于(无符号数)		---	位宽为4bits的信号，6值
  //BR_J	---	跳转				---	位宽为4bits的信号，7值
  //BR_JR	---	寄存器跳转			---	位宽为4bits的信号，8值
  // Branch Type
  val BR_N   = 0.asUInt(4.W)  // Next
  val BR_NE  = 1.asUInt(4.W)  // Branch on NotEqual
  val BR_EQ  = 2.asUInt(4.W)  // Branch on Equal
  val BR_GE  = 3.asUInt(4.W)  // Branch on Greater/Equal
  val BR_GEU = 4.asUInt(4.W)  // Branch on Greater/Equal Unsigned
  val BR_LT  = 5.asUInt(4.W)  // Branch on Less Than
  val BR_LTU = 6.asUInt(4.W)  // Branch on Less Than Unsigned
  val BR_J   = 7.asUInt(4.W)  // Jump
  val BR_JR  = 8.asUInt(4.W)  // Jump Register

  //rs1寄存器操作选择信号
  //OP1_RS1	---	rs1寄存器						---	位宽为2bits的信号，0值
  //OP1_IMU	---	立即数，U-type					---	位宽为2bits的信号，1值
  //OP1_IMZ	---	rs1的零扩展字段，用于CSRI指令		---	位宽为2bits的信号，2值
  //OP1_X		---	rs1寄存器						---	位宽为2bits的信号，0值
  // RS1 Operand Select Signal
  val OP1_RS1 = 0.asUInt(2.W) // Register Source #1
  val OP1_IMU = 1.asUInt(2.W) // immediate, U-type
  val OP1_IMZ = 2.asUInt(2.W) // Zero-extended rs1 field of inst, for CSRI instructions
  val OP1_X   = 0.asUInt(2.W)
  
  //rs2寄存器操作选择信号
  //OP2_RS2	---	rs2寄存器						---	位宽为2bits的信号，0值
  //OP2_IMI	---	立即数，I-type					---	位宽为2bits的信号，1值
  //OP2_IMS	---	立即数，S-type					---	位宽为2bits的信号，2值
  //OP2_PC		---	PC								---	位宽为2bits的信号，3值
  //OP2_X		---	rs2寄存器						---	位宽为2bits的信号，0值
  // RS2 Operand Select Signal
  val OP2_RS2 = 0.asUInt(2.W) // Register Source #2
  val OP2_IMI = 1.asUInt(2.W) // immediate, I-type
  val OP2_IMS = 2.asUInt(2.W) // immediate, S-type
  val OP2_PC  = 3.asUInt(2.W) // PC
  val OP2_X   = 0.asUInt(2.W)
  
  //寄存器文件写使能信号
  //REN_0	---	flase，不使能						---	位宽为1bit的信号，false值
  //REN_1	---	true，使能							---	位宽为1bit的信号，true值
  //REN_X	---	flase，不使能						---	位宽为1bit的信号，false值
  // Register File Write Enable Signal
  val REN_0   = false.B
  val REN_1   = true.B
  val REN_X   = false.B
  
  //回写选择信号
  //WB_ALU	---	回写ALU						---	位宽为2bits的信号，0值
  //WB_MEM	---	回写memory					---	位宽为2bits的信号，1值
  //WB_PC4	---	回写PC						---	位宽为2bits的信号，2值
  //WB_CSR	---	回写CSR寄存器				---	位宽为2bits的信号，3值
  //WB_X	---	不操作						---	位宽为2bits的信号，0值
  // Writeback Select Signal
  val WB_ALU  = 0.asUInt(2.W)
  val WB_MEM  = 1.asUInt(2.W)
  val WB_PC4  = 2.asUInt(2.W)
  val WB_CSR  = 3.asUInt(2.W)
  val WB_X    = 0.asUInt(2.W)

  // Memory Write Signal
  val MWR_0   = false.B
  val MWR_1   = true.B
  val MWR_X   = false.B
  
  //memory写使能信号
  //MEN_0	---	flase，不使能						---	位宽为1bit的信号，false值
  //MEN_1	---	true，使能							---	位宽为1bit的信号，true值
  //MEN_X	---	flase，不使能						---	位宽为1bit的信号，false值
  // Memory Enable Signal
  val MEN_0   = false.B
  val MEN_1   = true.B
  val MEN_X   = false.B
  
  //memory掩蔽类型信号
  //MSK_B	---	1字节						---	位宽为3bits的信号，0值
  //MSK_BU	---	1字节(无符号)			    ---	位宽为3bits的信号，1值
  //MSK_H	---	half-word(半字)				---	位宽为3bits的信号，2值
  //MSK_HU	---	half-word(半字)				---	位宽为3bits的信号，3值
  //MSK_W	---	word(4字节)					---	位宽为3bits的信号，4值
  //MSK_X	---	word(4字节)					---	位宽为3bits的信号，4值
  // Memory Mask Type Signal
  val MSK_B   = 0.asUInt(3.W)
  val MSK_BU  = 1.asUInt(3.W)
  val MSK_H   = 2.asUInt(3.W)
  val MSK_HU  = 3.asUInt(3.W)
  val MSK_W   = 4.asUInt(3.W)
  val MSK_X   = 4.asUInt(3.W)

  //cache flush操作，同步
  //M_N		---	不操作						---	位宽为3bits的信号，0值
  //M_SI		---	指令流同步					---	位宽为3bits的信号，1值
  //M_SD	    ---	数据流同步					---	位宽为3bits的信号，2值
  //M_FA		---	刷新全部cache				---	位宽为3bits的信号，3值
  //M_FD	    ---	刷新dcache					---	位宽为3bits的信号，4值
  // Cache Flushes & Sync Primitives
  val M_N      = 0.asUInt(3.W)
  val M_SI     = 1.asUInt(3.W)   // synch instruction stream
  val M_SD     = 2.asUInt(3.W)   // synch data stream
  val M_FA     = 3.asUInt(3.W)   // flush all caches
  val M_FD     = 4.asUInt(3.W)   // flush data cache

  //内存函数的类型
  //MT_READ	---	读					    ---	位宽为2bits的信号，0值
  //MT_WRITE	---	写						---	位宽为2bits的信号，1值
  //MT_FENCE	---	FENCE					---	位宽为2bits的信号，2值
  // Memory Functions (read, write, fence)
  val MT_READ  = 0.asUInt(2.W)
  val MT_WRITE = 1.asUInt(2.W)
  val MT_FENCE = 2.asUInt(2.W)
}

trait MemoryOpConstants
{
   val MT_X  = 0.asUInt(3.W)
   val MT_B  = 1.asUInt(3.W)
   val MT_H  = 2.asUInt(3.W)
   val MT_W  = 3.asUInt(3.W)
   val MT_D  = 4.asUInt(3.W)
   val MT_BU = 5.asUInt(3.W)
   val MT_HU = 6.asUInt(3.W)
   val MT_WU = 7.asUInt(3.W)

   val M_X   = "b0".asUInt(1.W)
   val M_XRD = "b0".asUInt(1.W) // int load
   val M_XWR = "b1".asUInt(1.W) // int store

   val DPORT = 0
   val IPORT = 1
}

object CSR
{
  // commands
  val SZ = 3.W
  val X = 0.asUInt(SZ)
  val N = 0.asUInt(SZ)
  val W = 1.asUInt(SZ)
  val S = 2.asUInt(SZ)
  val C = 3.asUInt(SZ)
  val I = 4.asUInt(SZ)
  val R = 5.asUInt(SZ)

  val ADDRSZ = 12
}