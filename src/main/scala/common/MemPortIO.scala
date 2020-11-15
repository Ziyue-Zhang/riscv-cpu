package common

import chisel3._

import common.constant._
import chisel3.util._

class MemReq(val data_width: Int) extends Bundle {
    val addr = Output(UInt(XLEN.W))
    val data = Output(UInt(data_width.W))
    val wr   = Output(Bool())
    val msk  = Output(UInt(8.W))
}

class MemResp(val data_width: Int) extends Bundle {
    val data = Output(UInt(data_width.W))
}

class MemPortIO(val data_width: Int) extends Bundle {
    val req     = new DecoupledIO(new MemReq(data_width)) //add ready & valid
    val resp    = Flipped(new ValidIO(new MemResp(data_width))) //add valid
}