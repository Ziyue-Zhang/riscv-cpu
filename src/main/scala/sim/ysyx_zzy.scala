package sim

import scala.language.reflectiveCalls

import chisel3._
import chisel3.util.experimental.BoringUtils

import common.constant._
import njucore._

class ysyx_zzy extends Module {
  val io = IO(new Bundle{
    val mem  = Flipped(new AXI_Interface)
    val mmio = Flipped(new AXI_lite_interface)
    
    val mtip = Input(Bool())
    val meip = Input(Bool())
  })

  val cpath = Module(new Cpath)
  val dpath = Module(new Dpath)

  cpath.io.ctl <> dpath.io.ctl
  cpath.io.dat <> dpath.io.dat
  
  val CPU_Bridge = Module(new AXI_Bridge)

  // Connecting core to AXI bridge
  CPU_Bridge.io.clock     := clock
  CPU_Bridge.io.reset     := reset

  CPU_Bridge.io.inst_req   := dpath.io.imem.req.valid && !dpath.io.inst_mmio
  CPU_Bridge.io.inst_wr    := 0.U
  CPU_Bridge.io.inst_size  := 2.U
  CPU_Bridge.io.inst_addr  := dpath.io.imem.req.bits.addr
  CPU_Bridge.io.inst_wdata := 0.U
  
  CPU_Bridge.io.data_req   := dpath.io.dmem.req.valid
  CPU_Bridge.io.data_wr    := dpath.io.dmem.req.bits.wr
  CPU_Bridge.io.data_size  := dpath.io.dmem.req.bits.msk
  CPU_Bridge.io.data_addr  := dpath.io.dmem.req.bits.addr
  CPU_Bridge.io.data_wdata := dpath.io.dmem.req.bits.data

  val MMIO_Bridge = Module(new AXI_Bridge)
    
  MMIO_Bridge.io.clock := clock
  MMIO_Bridge.io.reset := reset
   
  MMIO_Bridge.io.inst_req   := dpath.io.imem.req.valid && dpath.io.inst_mmio
  MMIO_Bridge.io.inst_wr    := 0.U
  MMIO_Bridge.io.inst_size  := 2.U
  MMIO_Bridge.io.inst_addr  := dpath.io.imem.req.bits.addr
  MMIO_Bridge.io.inst_wdata := 0.U

  MMIO_Bridge.io.data_req   := dpath.io.dmem.req.valid
  MMIO_Bridge.io.data_wr    := dpath.io.dmem.req.bits.wr
  MMIO_Bridge.io.data_size  := dpath.io.dmem.req.bits.msk
  MMIO_Bridge.io.data_addr  := dpath.io.dmem.req.bits.addr
  MMIO_Bridge.io.data_wdata := dpath.io.dmem.req.bits.data
    
  when (dpath.io.inst_mmio === 1.U) {
      dpath.io.imem.req.ready      := MMIO_Bridge.io.inst_addr_ok
      dpath.io.imem.resp.valid     := MMIO_Bridge.io.inst_data_ok
      cpath.io.inst_resp_valid     := MMIO_Bridge.io.inst_data_ok
      dpath.io.imem.resp.bits.data := MMIO_Bridge.io.inst_rdata
  } .otherwise {
      dpath.io.imem.req.ready      := CPU_Bridge.io.inst_addr_ok
      dpath.io.imem.resp.valid     := CPU_Bridge.io.inst_data_ok
      cpath.io.inst_resp_valid     := CPU_Bridge.io.inst_data_ok
      dpath.io.imem.resp.bits.data := CPU_Bridge.io.inst_rdata
  }
    
  when (dpath.io.data_mmio === 1.U) {
      dpath.io.dmem.req.ready      := MMIO_Bridge.io.data_addr_ok
      dpath.io.dmem.resp.valid     := MMIO_Bridge.io.data_data_ok
      cpath.io.data_resp_valid     := MMIO_Bridge.io.data_data_ok
      dpath.io.dmem.resp.bits.data := MMIO_Bridge.io.data_rdata
  } .otherwise {
      dpath.io.dmem.req.ready      := CPU_Bridge.io.data_addr_ok
      dpath.io.dmem.resp.valid     := CPU_Bridge.io.data_data_ok
      cpath.io.data_resp_valid     := CPU_Bridge.io.data_data_ok
      dpath.io.dmem.resp.bits.data := CPU_Bridge.io.data_rdata
  }
       
  io.mem.awid           := CPU_Bridge.io.awid
  io.mem.awaddr         := CPU_Bridge.io.awaddr
  io.mem.awlen          := CPU_Bridge.io.awlen
  io.mem.awsize         := CPU_Bridge.io.awsize
  io.mem.awburst        := CPU_Bridge.io.awburst
  io.mem.awlock         := CPU_Bridge.io.awlock
  io.mem.awcache        := CPU_Bridge.io.awcache
  io.mem.awprot         := CPU_Bridge.io.awprot
  io.mem.awvalid        := CPU_Bridge.io.awvalid
  CPU_Bridge.io.awready := io.mem.awready
  io.mem.wid            := CPU_Bridge.io.wid
  io.mem.wdata          := CPU_Bridge.io.wdata
  io.mem.wstrb          := CPU_Bridge.io.wstrb
  io.mem.wlast          := CPU_Bridge.io.wlast
  io.mem.wvalid         := CPU_Bridge.io.wvalid
  CPU_Bridge.io.wready  := io.mem.wready
  CPU_Bridge.io.bid     := io.mem.bid
  CPU_Bridge.io.bresp   := io.mem.bresp
  CPU_Bridge.io.bvalid  := io.mem.bvalid
  io.mem.bready         := CPU_Bridge.io.bready
  io.mem.arid           := CPU_Bridge.io.arid
  io.mem.araddr         := CPU_Bridge.io.araddr
  io.mem.arlen          := CPU_Bridge.io.arlen
  io.mem.arsize         := CPU_Bridge.io.arsize
  io.mem.arburst        := CPU_Bridge.io.arburst
  io.mem.arlock         := CPU_Bridge.io.arlock
  io.mem.arcache        := CPU_Bridge.io.arcache
  io.mem.arprot         := CPU_Bridge.io.arcache
  io.mem.arvalid        := CPU_Bridge.io.arvalid
  CPU_Bridge.io.arready := io.mem.arready
  CPU_Bridge.io.rid     := io.mem.rid
  CPU_Bridge.io.rdata   := io.mem.rdata
  CPU_Bridge.io.rresp   := io.mem.rresp
  CPU_Bridge.io.rlast   := io.mem.rlast
  CPU_Bridge.io.rvalid  := io.mem.rvalid
  io.mem.rready         := CPU_Bridge.io.rready
    
  io.mmio.awaddr         := MMIO_Bridge.io.awaddr
  io.mmio.awprot         := MMIO_Bridge.io.awprot
  io.mmio.awvalid        := MMIO_Bridge.io.awvalid
  MMIO_Bridge.io.awready := io.mmio.awready
  io.mmio.wdata          := MMIO_Bridge.io.wdata
  io.mmio.wstrb          := MMIO_Bridge.io.wstrb
  io.mmio.wvalid         := MMIO_Bridge.io.wvalid
  MMIO_Bridge.io.wready  := io.mmio.wready
  MMIO_Bridge.io.bresp   := io.mmio.bresp
  MMIO_Bridge.io.bvalid  := io.mmio.bvalid
  io.mmio.bready         := MMIO_Bridge.io.bready
  io.mmio.araddr         := MMIO_Bridge.io.araddr
  io.mmio.arprot         := MMIO_Bridge.io.arcache
  io.mmio.arvalid        := MMIO_Bridge.io.arvalid
  MMIO_Bridge.io.arready := io.mmio.arready
  MMIO_Bridge.io.rdata   := io.mmio.rdata
  MMIO_Bridge.io.rresp   := io.mmio.rresp
  MMIO_Bridge.io.rvalid  := io.mmio.rvalid
  io.mmio.rready         := MMIO_Bridge.io.rready

  
  val diffTestRegfile = Wire(Vec(NUM_REG, UInt(XLEN.W)))
  val diffTestPC      = Wire(UInt(XLEN.W))
  val diffTestValid   = Wire(Bool())
  diffTestRegfile := DontCare
  diffTestPC      := DontCare
  diffTestValid   := DontCare
  BoringUtils.addSink(diffTestRegfile, "diffTestRegfile")
  BoringUtils.addSink(diffTestPC, "diffTestPC")
  BoringUtils.addSink(diffTestValid, "diffTestValid")
}

object elaborateysyx_zzy extends App {
  (new stage.ChiselStage).execute(args, Seq(stage.ChiselGeneratorAnnotation(() => new ysyx_zzy)))
}