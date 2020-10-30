package common

import chisel3._
import chisel3.util.log2Ceil

object constant extends 
    RiscvConstants with 
    MemoryOpConstants {
}

trait RiscvConstants {
  val XLEN    = 64
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

  //定义Y为true的布尔量，N为false的布尔量
  val Y      = true.B
  val N      = false.B

  val START_ADDR = "h80000000".U


  val PC_4   = 0.asUInt(2.W)  // PC + 4
  val PC_BRJMP  = 1.asUInt(2.W)  // brjmp_target
  val PC_JALR  = 2.asUInt(2.W)  // jump_reg_target
  val PC_EXC = 3.asUInt(2.W)  // exception
  
  //分支类型
  //BR_N	---	下一个PC		
  //BR_NE	---	不等于			
  //BR_EQ	---	等于			
  //BR_GE	---	大于等于			
  //BR_GEU	---	大于等于(无符号数)	
  //BR_LT	---	小于				
  //BR_LTU	---	小于(无符号数)	
  //BR_J	---	跳转			
  //BR_JR	---	寄存器跳转		
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

  // RS1 Operand Select Signal
   val OP1_RS1   = 0.asUInt(2.W) // Register Source #1
   val OP1_PC    = 1.asUInt(2.W) // PC
   val OP1_IMZ   = 2.asUInt(2.W) // Zero-extended Immediate from RS1 field, for use by CSRI instructions
   val OP1_X     = 0.asUInt(2.W)

   // RS2 Operand Select Signal
   val OP2_RS2    = 0.asUInt(3.W) // Register Source #2
   val OP2_ITYPE  = 1.asUInt(3.W) // immediate, I-type
   val OP2_STYPE  = 2.asUInt(3.W) // immediate, S-type
   val OP2_SBTYPE = 3.asUInt(3.W) // immediate, B
   val OP2_UTYPE  = 4.asUInt(3.W) // immediate, U-type
   val OP2_UJTYPE = 5.asUInt(3.W) // immediate, J-type
   val OP2_X      = 0.asUInt(3.W)

   // Register Operand Output Enable Signal
   val OEN_0   = false.B
   val OEN_1   = true.B

   // Register File Write Enable Signal
   val REN_0   = false.B
   val REN_1   = true.B

   // ALU Operation Signal
   val ALU_ADD    = 0.asUInt(4.W)
   val ALU_SUB    = 1.asUInt(4.W)
   val ALU_SLL    = 2.asUInt(4.W)
   val ALU_SRL    = 3.asUInt(4.W)
   val ALU_SRA    = 4.asUInt(4.W)
   val ALU_AND    = 5.asUInt(4.W)
   val ALU_OR     = 6.asUInt(4.W)
   val ALU_XOR    = 7.asUInt(4.W)
   val ALU_SLT    = 8.asUInt(4.W)
   val ALU_SLTU   = 9.asUInt(4.W)
   val ALU_COPY_1 = 10.asUInt(4.W)
   val ALU_COPY_2 = 11.asUInt(4.W)
   val ALU_X      = 0.asUInt(4.W)

   // Writeback Select Signal
   val WB_ALU  = 0.asUInt(2.W)
   val WB_MEM  = 1.asUInt(2.W)
   val WB_PC4  = 2.asUInt(2.W)
   val WB_CSR  = 3.asUInt(2.W)
   val WB_X    = 0.asUInt(2.W)

   // Memory Enable Signal
   val MEN_0   = false.B
   val MEN_1   = true.B
   val MEN_X   = false.B
}

trait MemoryOpConstants {
   val MT_X  = 0.asUInt(3.W)
   val MT_B  = 1.asUInt(3.W)
   val MT_H  = 2.asUInt(3.W)
   val MT_W  = 3.asUInt(3.W)
   val MT_D  = 4.asUInt(3.W)
   val MT_BU = 5.asUInt(3.W)
   val MT_HU = 6.asUInt(3.W)
   val MT_WU = 7.asUInt(3.W)

   val M_X   = 0.asUInt(2.W)
   val M_XRD = 1.asUInt(2.W) // int load
   val M_XWR = 2.asUInt(2.W) // int store
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