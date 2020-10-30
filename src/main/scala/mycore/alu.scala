package njucore

import chisel3._
import chisel3.util._
import common.constant._

class alu extends Module{
  val io = IO(new Bundle {
      val src1 = Input(UInt(XLEN.W))
      val src2 = Input(UInt(XLEN.W))
      val op = Input(UInt(4.W))
      val res =  Output(UInt(XLEN.W))
  })

  val op = io.op
  val (src1, src2) = (io.src1, io.src2)
  val shamt = io.src2(5,0).asUInt()  

  io.res := MuxCase(0.U, Array(
    (op === ALU_ADD)    -> (src1 + src2).asUInt(),
    (op === ALU_SUB)    -> (src1 - src2).asUInt(),
    (op === ALU_AND)    -> (src1 & src2).asUInt(),
    (op === ALU_OR)     -> (src1 | src2).asUInt(),
    (op === ALU_XOR)    -> (src1 ^ src2).asUInt(),
    (op === ALU_SLT)    -> (src1.asSInt() < src2.asSInt()).asUInt(),
    (op === ALU_SLTU)   -> (src1 < src2).asUInt(),
    (op === ALU_SLL)    -> ((src1 << shamt)(XLEN-1, 0)).asUInt(),
    (op === ALU_SRA)    -> (src1.asSInt() >> shamt).asUInt(),
    (op === ALU_SRL)    -> (src1 >> shamt).asUInt(),
    (op === ALU_COPY_1) -> src1,
    (op === ALU_COPY_2) -> src2
  ))

  printf("ALU: op = %d, src1=[%x] src2=[%x] result=[%x]\n", op, src1, src2, io.res);
}
