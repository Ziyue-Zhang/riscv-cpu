package njucore

import chisel3._
import chisel3.util._
import chisel3.util.experimental.BoringUtils

import common.constant._

class regfileIo() extends Bundle()
{
   val rs1_addr = Input(UInt(5.W))
   val rs1_data = Output(UInt(XLEN.W))
   val rs2_addr = Input(UInt(5.W))
   val rs2_data = Output(UInt(XLEN.W))

   val waddr    = Input(UInt(5.W))
   val wdata    = Input(UInt(XLEN.W))
   val wen      = Input(UInt(1.W))
}
class zzy_regfile extends Module{
  val io = IO(new regfileIo()) 
  val regfile = Mem(32, UInt(XLEN.W))

  io.rs1_data := Mux((io.rs1_addr =/= 0.U), regfile(io.rs1_addr), 0.U(XLEN.W))
  io.rs2_data := Mux((io.rs2_addr =/= 0.U), regfile(io.rs2_addr), 0.U(XLEN.W))

  when (io.wen.asBool() && (io.waddr =/= 0.U)) {
      regfile(io.waddr) := io.wdata
  }
   
  BoringUtils.addSource(VecInit((0 to NUM_REG-1).map(i => regfile(i.U))), "diffTestRegfile")
  
  when(DEBUG){
    printf("RF: rdata1(%d)=[%x] rdata2(%d)=[%x] wdata(%d)=[%x] wen=%d\n", io.rs1_addr, io.rs1_data, io.rs1_addr, io.rs2_data, io.waddr, io.wdata, io.wen)
  }
}
