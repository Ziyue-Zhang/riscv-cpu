package mycore

import chisel3._
import common._

class coreIO extends Bundle{
  val inst_read_io = new InstReadIO()
  val data_read_io = new DataReadIO()
  val data_write_io = new DataWriteIO()
}

class core extends Module{
  val io = IO(new coreIO)
  val cpath = Module(new cpath)
  val dpath = Module(new dpath)

  // 和外部连接
  io.inst_read_io <> dpath.io.inst_read_io
  io.data_read_io <> dpath.io.data_read_io
  io.data_write_io <> dpath.io.data_write_io

  // 两个模块连接
  cpath.io.ctl <> dpath.io.ctl
  cpath.io.dat <> dpath.io.dat
}