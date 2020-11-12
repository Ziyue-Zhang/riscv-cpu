package njucore

import chisel3._
import chisel3.util._
import common.constant._

class alu extends Module{
  val io = IO(new Bundle {
      val src1 = Input(UInt(XLEN.W))
      val src2 = Input(UInt(XLEN.W))
      val op = Input(UInt(5.W))
      val res =  Output(UInt(XLEN.W))

      val stall = Output(Bool())
  })


  val op = io.op
  val (src1, src2) = (io.src1, io.src2)
  val shamt = io.src2(5,0).asUInt()  

  // Multiplier

  val use_mdu = io.op === ALU_MUL    || io.op === ALU_DIV   || io.op === ALU_REMW ||
                io.op === ALU_REMUW  || io.op === ALU_DIVUW || io.op === ALU_MULH ||
                io.op === ALU_MULHSU || io.op === ALU_MULHU || io.op === ALU_DIVU ||
                io.op === ALU_DIVW   || io.op === ALU_REM   || io.op === ALU_REMU
  val mdu = Module(new Multiplier)
  
  mdu.io.start := use_mdu
  mdu.io.a  := io.src1
  mdu.io.b  := io.src2
  mdu.io.op    := io.op
  io.stall     := use_mdu && mdu.io.stall_req

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
    (op === ALU_SRL)    -> (src1.asUInt() >> shamt).asUInt(),
    (op === ALU_SRLW)   -> (src1.asUInt() >> io.src2(4,0).asUInt()).asUInt(),
    (op === ALU_COPY_1) -> src1,
    (op === ALU_COPY_2) -> src2,
    (op === ALU_SRAW)   -> Cat(Fill(32, src1(31)), (src1(31,0).asSInt() >> shamt).asUInt()),
    /*(op === ALU_MUL)-> (src1 * src2)(63,0).asUInt(),
    //(op === ALU_DIV)-> Mux(src2 === 0.U,0.U,(src1.asSInt() / src2.asSInt()).asUInt()),
    (op === ALU_DIV)-> Mux(src2 === 0.U,0.U,(src1 / src2).asUInt()),
    (op === ALU_REMW)-> Mux(src2 === 0.U,0.U,(src1(31,0).asSInt() % src2(31,0).asSInt()).asUInt()),
    (op === ALU_REMUW)-> Mux(src2 === 0.U,0.U,(src1(31,0) % src2(31,0)).asUInt()),
    (op === ALU_DIVUW)-> Mux(src2 === 0.U,0.U,(src1(31,0) / src2(31,0)).asUInt()),
    (op === ALU_MULH) -> (src1.asSInt() * src2.asSInt())(127,64).asUInt(),
    (op === ALU_MULHSU) -> (src1.asSInt() * src2)(127,64).asUInt(),
    (op === ALU_MULHU) -> (src1 * src2)(127,64).asUInt(),
    (op === ALU_DIVU) -> Mux(src2 === 0.U,0.U,(src1 / src2).asUInt()),
    //(op === ALU_DIVW) -> Mux(src2 === 0.U,0.U,(src1(31,0).asSInt() / src2(31,0).asSInt()).asUInt()),
    (op === ALU_DIVW) -> Mux(src2 === 0.U,0.U,(src1(31,0) / src2(31,0)).asUInt()),
    (op === ALU_REM) -> Mux(src2 === 0.U,0.U,(src1.asSInt() % src2.asSInt()).asUInt()),
    (op === ALU_REMU) -> Mux(src2 === 0.U,0.U,(src1 % src2).asUInt())*/
    (use_mdu)           -> mdu.io.mult_out
  ))
  when(DEBUG){
    printf("ALU: op = %d, src1=[%x] src2=[%x] shamt=[%x] result=[%x]\n", op, src1, src2, shamt,io.res)
  }
}
