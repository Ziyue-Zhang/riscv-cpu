package sim

import chisel3._
import chisel3.util._

import common.constant._

class diffTestIO extends Bundle{
  val regfile = Output(Vec(NUM_REG, UInt(XLEN.W)))
  val pc      = Output(UInt(XLEN.W))
  val valid   = Output(Bool())
}