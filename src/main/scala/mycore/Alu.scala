package mycore

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

    val (src1, src2) = (io.src1, io.src2)
    val shamt = io.src2(5,0).asUInt()

    io.res := MuxCase(0.U, Array(
        (io.op === ALU_ADD)  -> (src1 + src2).asUInt(),
        (io.op === ALU_SUB)  -> (src1 - src2).asUInt(),
        (io.op === ALU_AND)  -> (src1 & src2).asUInt(),
        (io.op === ALU_OR)   -> (src1 | src2).asUInt(),
        (io.op === ALU_XOR)  -> (src1 ^ src2).asUInt(),
        (io.op === ALU_SLT)  -> (src1.asSInt() < src2.asSInt()).asUInt(),
        (io.op === ALU_SLTU) -> (src1 < src2).asUInt(),
        (io.op === ALU_SLL)  -> ((src1 << shamt)(XLEN-1, 0)).asUInt(),
        (io.op === ALU_SRA)  -> (src1.asSInt() >> shamt).asUInt(),
        (io.op === ALU_SRL)  -> (src1 >> shamt).asUInt(),
        (io.op === ALU_COPY_1)-> src1
    ))
}