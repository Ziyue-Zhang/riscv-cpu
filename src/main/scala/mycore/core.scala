package njucore

import chisel3._
import common._

class njucoreIO extends Bundle{
  val inst_readIO  = new InstReadIO
  val data_readIO  = new DataReadIO
  val data_writeIO = new DataWriteIO
}

class njucore extends Module{
  val io = IO(new njucoreIO)
  val cpath = Module(new Cpath)
  val dpath = Module(new Dpath)

  io.inst_readIO  <> dpath.io.inst_readIO
  io.data_readIO  <> dpath.io.data_readIO
  io.data_writeIO <> dpath.io.data_writeIO

  cpath.io.ctl <> dpath.io.ctl
  cpath.io.dat <> dpath.io.dat
}