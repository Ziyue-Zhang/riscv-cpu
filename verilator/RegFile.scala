package mycore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

import common.constant._

class regfile extends Module{
    val io = IO(new Bundle {
        val rd1_addr = Input(UInt(WIDE.W))
        val rd2_addr = Input(UInt(WIDE.W))
        val rd1_data = Output(UInt(XLEN.W))
        val rd2_data = Output(UInt(XLEN.W))
        val wr_en = Input(UInt(1.W))
        val wr_addr = Input(UInt(WIDE.W))
        val wr_data = Output(UInt(XLEN.W))
    })

    val regs = Mem(NUM_REG, UInt(XLEN.W))

    io.rd1_data := Mux(io.rd1_addr =/= 0.U, regs(io.rd1_addr), 0.U(XLEN.W))
    io.rd2_data := Mux(io.rd2_addr =/= 0.U, regs(io.rd2_addr), 0.U(XLEN.W))

    when(io.wr_en.asBool() && io.wr_addr =/= 0.U) {
        regs(io.wr_addr) := io.wr_data
    }
}