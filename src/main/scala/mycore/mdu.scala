package njucore

import scala.language.reflectiveCalls

import chisel3._
import chisel3.util._

//reference to https://github.com/phantom-v/phvntom


trait mduParams{
    val xlen        = 64

    val aluXXX      =  0.U(5.W)
    val aluADD      =  1.U(5.W)
    val aluSUB      =  2.U(5.W)
    val aluSLL      =  3.U(5.W)
    val aluSLT      =  4.U(5.W)
    val aluSLTU     =  5.U(5.W)
    val aluXOR      =  6.U(5.W)
    val aluSRL      =  7.U(5.W)
    val aluSRA      =  8.U(5.W)
    val aluOR       =  9.U(5.W)
    val aluAND      = 10.U(5.W)
    val aluCPA      = 11.U(5.W)
    val aluCPB      = 12.U(5.W)
    val aluADDW     = 13.U(5.W)
    val aluSUBW     = 14.U(5.W)
    val aluSLLW     = 15.U(5.W)
    val aluSRLW     = 16.U(5.W)
    val aluSRAW     = 17.U(5.W)
    val aluMUL      = 18.U(5.W)
    val aluMULH     = 19.U(5.W)
    val aluMULHSU   = 20.U(5.W)
    val aluMULHU    = 21.U(5.W)
    val aluDIV      = 22.U(5.W)
    val aluDIVU     = 23.U(5.W)
    val aluREM      = 24.U(5.W)
    val aluREMU     = 25.U(5.W)
    val aluMULW     = 26.U(5.W)
    val aluDIVW     = 27.U(5.W)
    val aluDIVUW    = 28.U(5.W)
    val aluREMW     = 29.U(5.W)
    val aluREMUW    = 30.U(5.W)
    val aluBits = aluXXX.getWidth
}

class mduIO extends Bundle with mduParams{
    val start = Input(Bool())
    val src1 = Input(UInt(xlen.W))
    val src2 = Input(UInt(xlen.W))
    val op = Input(UInt(aluBits.W))
    val stall_req = Output(Bool())
    val mdu_out = Output(UInt(xlen.W))
}

class mdu extends Module with mduParams{
    val io = IO(new mduIO())

    def resemble_op(op: UInt, op_history: UInt): Bool = {
    (((op_history === aluMULHU || op_history === aluMULH || op_history === aluMULHSU) && op === aluMUL) ||
      (op_history === aluDIV && op === aluREM) ||
      (op_history === aluDIVU && op === aluREMU) ||
      (op_history === aluDIVUW && op === aluREMUW) ||
      (op_history === aluDIVW && op === aluREMW) ||
      (op === aluDIV && op_history === aluREM) ||
      (op === aluDIVU && op_history === aluREMU) ||
      (op === aluDIVUW && op_history === aluREMUW) ||
      (op === aluDIVW && op_history === aluREMW))
  }

  def check_history_same(src1: UInt, src2: UInt, op: UInt, hsrc1: UInt, hsrc2: UInt, hop: UInt): Bool = {
    src1 === hsrc1 && src2 === hsrc2 && resemble_op(op, hop)
  }

  val last_src1 = RegInit(UInt(xlen.W), 0.U)
  val last_src2 = RegInit(UInt(xlen.W), 0.U)
  val last_op = RegInit(UInt(aluBits.W), aluXXX)

  when(io.start) {
    last_src1 := io.src1
    last_src2 := io.src2
    last_op := io.op
  }

  val is_mult = io.op === aluMUL || io.op === aluMULH || io.op === aluMULHSU || io.op === aluMULHU || io.op === aluMULW
  val res = RegInit(UInt((2 * xlen).W), 0.U)
  val mult_cnt = RegInit(UInt(log2Ceil(xlen + 1).W), 0.U)
  val div_cnt = RegInit(UInt(log2Ceil(xlen + 1).W), 0.U)
  val sign_src1 = io.src1(xlen - 1)
  val sign_wsrc1 = io.src1(31)
  val abs_src1 = MuxLookup(io.op, Cat(Fill(32, 0.U), io.src1(31, 0)),
    Seq(
      aluMUL -> io.src1,
      aluMULH -> Mux(io.src1(xlen - 1), ((~io.src1) + 1.U), io.src1),
      aluMULHSU -> Mux(io.src1(xlen - 1), ((~io.src1) + 1.U), io.src1),
      aluMULHU -> io.src1,
      aluMULW -> Cat(Fill(32, 0.U), io.src1(31, 0)),
      aluDIV -> Mux(io.src1(xlen - 1), ((~io.src1) + 1.U), io.src1),
      aluDIVU -> io.src1,
      aluDIVW -> Cat(Fill(32, 0.U), Mux(io.src1(31), ((~io.src1) + 1.U)(31, 0), io.src1(31, 0))),
      aluDIVUW -> Cat(Fill(32, 0.U), io.src1(31, 0)),
      aluREM -> Mux(io.src1(xlen - 1), ((~io.src1) + 1.U), io.src1),
      aluREMU -> io.src1,
      aluREMW -> Cat(Fill(32, 0.U), Mux(io.src1(31), ((~io.src1) + 1.U)(31, 0), io.src1(31, 0))),
      aluREMUW -> Cat(Fill(32, 0.U), io.src1(31, 0))
    )
  )

//  printf("MUL a:%x, b:%x, out:%x, op:%x, start:%x, stall_req:%x, cnt:%x\n", io.src1, io.src2, io.mdu_out, io.op, io.start, io.stall_req, mult_cnt)

  val sign_src2 = io.src2(xlen - 1)
  val sign_wsrc2 = io.src2(31)
  val abs_src2 = MuxLookup(io.op, Cat(Fill(32, 0.U), io.src2(31, 0)),
    Seq(
      aluMUL -> io.src2,
      aluMULH -> Mux(io.src2(xlen - 1), ((~io.src2) + 1.U), io.src2),
      aluMULHSU -> io.src2,
      aluMULHU -> io.src2,
      aluMULW -> Cat(Fill(32, 0.U), io.src2(31, 0)),
      aluDIV -> Mux(io.src2(xlen - 1), ((~io.src2) + 1.U), io.src2),
      aluDIVU -> io.src2,
      aluDIVW -> Cat(Fill(32, 0.U), Mux(io.src2(31), ((~io.src2) + 1.U)(31, 0), io.src2(31, 0))),
      aluDIVUW -> Cat(Fill(32, 0.U), io.src2(31, 0)),
      aluREM -> Mux(io.src2(xlen - 1), ((~io.src2) + 1.U), io.src2),
      aluREMU -> io.src2,
      aluREMW -> Cat(Fill(32, 0.U), Mux(io.src2(31), ((~io.src2) + 1.U)(31, 0), io.src2(31, 0))),
      aluREMUW -> Cat(Fill(32, 0.U), io.src2(31, 0))
    )
  )
  val res_ss = Mux(sign_src1 === sign_src2, res, ((~res) + 1.U))
  val res_su = Mux(sign_src1 === 0.U, res, ((~res) + 1.U))
  val res_divs = Mux(sign_src1 === sign_src2, res(xlen - 1, 0), ((~res(xlen - 1, 0)) + 1.U))
  val res_rems = Mux(sign_src1 === 0.U, res(2 * xlen - 1, xlen), ((~res(2 * xlen - 1, xlen)) + 1.U))
  val res_divsw = Mux(sign_wsrc1 === sign_wsrc2, res(31, 0), ((~res(31, 0)) + 1.U))
  val res_remsw = Mux(sign_src1 === 0.U, res(xlen + 31, xlen), ((~res(xlen + 31, xlen)) + 1.U))
  val last_stall_req = RegInit(Bool(), false.B)
  val step_result = WireInit(UInt((2 * xlen).W), 0.U)
  val front_val = WireInit(UInt((xlen + 1).W), 0.U)

  last_stall_req := io.stall_req

  when(io.start) {
    when(is_mult) {
      when (io.stall_req) {
        mult_cnt := mult_cnt + 1.U
      }.otherwise {
        mult_cnt := 0.U
      }
      when(io.stall_req) {
        when(!last_stall_req) {
          res := Cat(Fill(xlen, 0.U), abs_src2)
        }.otherwise {
          res := Cat(front_val(xlen), step_result(2 * xlen - 1, 1))
        }
      }
    }.otherwise {
      when (io.stall_req) {
        div_cnt := div_cnt + 1.U
      }.otherwise {
        div_cnt := 0.U
      }
      when(io.stall_req) {
        when(!last_stall_req) {
          res := Cat(Fill(xlen - 1, 0.U), abs_src1, Fill(1, 0.U))
        }.elsewhen(div_cnt === xlen.U) {
          res := Cat(front_val(xlen - 1), step_result(2 * xlen - 1, xlen + 1), step_result(xlen - 1, 0))
        }.otherwise {
          res := step_result
        }
      }

    }
  }

  when(is_mult) {
    front_val := Cat(Fill(1, 0.U), Mux(res(0), abs_src1, 0.U(xlen.W))) + Cat(Fill(1, 0.U), res(2 * xlen - 1, xlen))
    step_result := Cat(front_val(xlen - 1, 0), res(xlen - 1, 0))
    io.stall_req := io.start && (mult_cnt =/= (xlen + 1).U || (!last_stall_req && !check_history_same(io.src1, io.src2, io.op, last_src1, last_src2, last_op)))
    io.mdu_out := MuxLookup(io.op, Cat(Fill(32, res(31)), res(31, 0)),
      Seq(
        aluMUL -> res(xlen - 1, 0),
        aluMULH -> res_ss(2 * xlen - 1, xlen),
        aluMULHSU -> res_su(2 * xlen - 1, xlen),
        aluMULHU -> res(2 * xlen - 1, xlen),
        aluMULW -> Cat(Fill(32, res(31)), res(31, 0))
      )
    )
  }.otherwise {
    front_val := Mux(res(2 * xlen - 1, xlen) >= abs_src2, res(2 * xlen - 1, xlen) - abs_src2, res(2 * xlen - 1, xlen))
    step_result := Cat(front_val(xlen - 2, 0), res(xlen - 1, 0), (res(2 * xlen - 1, xlen) >= abs_src2).asUInt)
    io.stall_req := io.start && (div_cnt =/= (xlen + 1).U || (!last_stall_req && !check_history_same(io.src1, io.src2, io.op, last_src1, last_src2, last_op)))
    io.mdu_out := MuxLookup(io.op, 0.U,
      Seq(
        aluDIV -> Mux(io.src2.orR, res_divs, Fill(xlen, 1.U)),
        aluDIVU -> Mux(io.src2.orR, res(xlen - 1, 0), Fill(xlen, 1.U)),
        aluDIVW -> Mux(io.src2(31, 0).orR, Cat(Fill(32, res_divsw(31)), res_divsw), Fill(xlen, 1.U)),
        aluDIVUW -> Mux(io.src2(31, 0).orR, Cat(Fill(32, res(31)), res(31, 0)), Fill(xlen, 1.U)),
        aluREM -> Mux(io.src2.orR, res_rems, io.src1),
        aluREMU -> Mux(io.src2.orR, res(2 * xlen - 1, xlen), io.src1),
        aluREMW -> Mux(io.src2(31, 0).orR, Cat(Fill(32, res_remsw(31)), res_remsw), io.src1),
        aluREMUW -> Mux(io.src2(31, 0).orR, Cat(Fill(32, res(xlen + 31)), res(xlen + 31, xlen)), io.src1)
      )
    )
  }

}