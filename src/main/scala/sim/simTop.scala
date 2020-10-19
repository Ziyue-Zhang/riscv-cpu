package sim

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils
import mycore._

class simTop extends Module{
  val io = IO(new Bundle{
    val diffTestIO = new diffTestIO
    val coreIO = new coreIO
  })
  io := DontCare    // 不会被使用

  val mycore = Module(new core())
  BoringUtils.addSink(io.diffTestIO.regfile, "diffTestRegfile")
  BoringUtils.addSink(io.diffTestIO.pc, "diffTestPC")
  BoringUtils.addSink(io.diffTestIO.valid, "diffTestValid")
  io.coreIO <> mycore.io

}

object elaborate extends App {
  (new stage.ChiselStage).execute(args, Seq(stage.ChiselGeneratorAnnotation(() => new simTop)))
}