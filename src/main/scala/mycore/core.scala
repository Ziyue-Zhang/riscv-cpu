/*package njucore

import chisel3._
import common._
import common.constant._

class njucoreIO extends Bundle{
  val imem = new MemPortIO(XLEN)
  val dmem = new MemPortIO(XLEN)
  val inst_mmio = Output(UInt(1.W))
  val data_mmio = Output(UInt(1.W))
}

class njucore extends Module{
  val io = IO(new njucoreIO)
  val cpath = Module(new Cpath)
  val dpath = Module(new Dpath)

  cpath.io.ctl <> dpath.io.ctl
  cpath.io.dat <> dpath.io.dat

  //io.imem  <> cpath.io.imem
  io.imem  <> dpath.io.imem

  //io.dmem  <> cpath.io.dmem
  io.dmem  <> dpath.io.dmem

  //io.inst_mmio := dpath.io.inst_mmio
  io.data_mmio := dpath.io.data_mmio
}*/