package njucore

import scala.language.reflectiveCalls

import chisel3._
import chisel3.util._
import common.constant._

//reference to https://github.com/phantom-v/phvntom

trait phvntomParams {
  val xlen          = 64
  val bitWidth      = log2Ceil(xlen)

  val aluXXX        = 0.U(5.W)
  val aluBits       = aluXXX.getWidth  
}

class zzy_MultiplierIO extends Bundle with phvntomParams {
  val start = Input(Bool())
  val a = Input(UInt(xlen.W))
  val b = Input(UInt(xlen.W))
  val op = Input(UInt(aluBits.W))
  val stall_req = Output(Bool())
  val mult_out = Output(UInt(xlen.W))
}

class zzy_Multiplier extends Module with phvntomParams {
  val io = IO(new Bundle{
    val start = Input(Bool())
    val a = Input(UInt(xlen.W))
    val b = Input(UInt(xlen.W))
    val op = Input(UInt(aluBits.W))
    val stall_req = Output(Bool())
    val mult_out = Output(UInt(xlen.W))
    
  })

  def resemble_op(op: UInt, op_history: UInt): Bool = {
    (((op_history === ALU_MULHU || op_history === ALU_MULH || op_history === ALU_MULHSU) && op === ALU_MUL) ||
      (op_history === ALU_DIV && op === ALU_REM) ||
      (op_history === ALU_DIVU && op === ALU_REMU) ||
      (op_history === ALU_DIVUW && op === ALU_REMUW) ||
      (op_history === ALU_DIVW && op === ALU_REMW) ||
      (op === ALU_DIV && op_history === ALU_REM) ||
      (op === ALU_DIVU && op_history === ALU_REMU) ||
      (op === ALU_DIVUW && op_history === ALU_REMUW) ||
      (op === ALU_DIVW && op_history === ALU_REMW))
  }

  def check_history_same(a: UInt, b: UInt, op: UInt, ha: UInt, hb: UInt, hop: UInt): Bool = {
    a === ha && b === hb && resemble_op(op, hop)
  }

  val last_a = RegInit(UInt(xlen.W), 0.U)
  val last_b = RegInit(UInt(xlen.W), 0.U)
  val last_op = RegInit(UInt(aluBits.W), aluXXX)

  when(io.start) {
    last_a := io.a
    last_b := io.b
    last_op := io.op
  }

  val is_mult = io.op === ALU_MUL || io.op === ALU_MULH || io.op === ALU_MULHSU || io.op === ALU_MULHU || io.op === ALU_MULW
  val res = RegInit(UInt(128.W), 0.U)
  val mult_cnt = RegInit(UInt(log2Ceil(xlen + 1).W), 0.U)
  val div_cnt = RegInit(UInt(log2Ceil(xlen + 1).W), 0.U)
  val sign_a = io.a(xlen - 1)
  val sign_wa = io.a(31)
  val abs_a = MuxLookup(io.op, Cat(Fill(32, 0.U), io.a(31, 0)),
    Seq(
      ALU_MUL -> io.a,
      ALU_MULH -> Mux(io.a(xlen - 1), ((~io.a) + 1.U), io.a),
      ALU_MULHSU -> Mux(io.a(xlen - 1), ((~io.a) + 1.U), io.a),
      ALU_MULHU -> io.a,
      ALU_MULW -> Cat(Fill(32, 0.U), io.a(31, 0)),
      ALU_DIV -> Mux(io.a(xlen - 1), ((~io.a) + 1.U), io.a),
      ALU_DIVU -> io.a,
      ALU_DIVW -> Cat(Fill(32, 0.U), Mux(io.a(31), ((~io.a) + 1.U)(31, 0), io.a(31, 0))),
      ALU_DIVUW -> Cat(Fill(32, 0.U), io.a(31, 0)),
      ALU_REM -> Mux(io.a(xlen - 1), ((~io.a) + 1.U), io.a),
      ALU_REMU -> io.a,
      ALU_REMW -> Cat(Fill(32, 0.U), Mux(io.a(31), ((~io.a) + 1.U)(31, 0), io.a(31, 0))),
      ALU_REMUW -> Cat(Fill(32, 0.U), io.a(31, 0))
    )
  )

  val sign_b = io.b(xlen - 1)
  val sign_wb = io.b(31)
  val abs_b = MuxLookup(io.op, Cat(Fill(32, 0.U), io.b(31, 0)),
    Seq(
      ALU_MUL -> io.b,
      ALU_MULH -> Mux(io.b(xlen - 1), ((~io.b) + 1.U), io.b),
      ALU_MULHSU -> io.b,
      ALU_MULHU -> io.b,
      ALU_MULW -> Cat(Fill(32, 0.U), io.b(31, 0)),
      ALU_DIV -> Mux(io.b(xlen - 1), ((~io.b) + 1.U), io.b),
      ALU_DIVU -> io.b,
      ALU_DIVW -> Cat(Fill(32, 0.U), Mux(io.b(31), ((~io.b) + 1.U)(31, 0), io.b(31, 0))),
      ALU_DIVUW -> Cat(Fill(32, 0.U), io.b(31, 0)),
      ALU_REM -> Mux(io.b(xlen - 1), ((~io.b) + 1.U), io.b),
      ALU_REMU -> io.b,
      ALU_REMW -> Cat(Fill(32, 0.U), Mux(io.b(31), ((~io.b) + 1.U)(31, 0), io.b(31, 0))),
      ALU_REMUW -> Cat(Fill(32, 0.U), io.b(31, 0))
    )
  )
  val res_ss = Mux(sign_a === sign_b, res, ((~res) + 1.U))
  val res_su = Mux(sign_a === 0.U, res, ((~res) + 1.U))
  val res_divs = Mux(sign_a === sign_b, res(xlen - 1, 0), ((~res(xlen - 1, 0)) + 1.U))
  val res_rems = Mux(sign_a === 0.U, res(2 * xlen - 1, xlen), ((~res(2 * xlen - 1, xlen)) + 1.U))
  val res_divsw = Mux(sign_wa === sign_wb, res(31, 0), ((~res(31, 0)) + 1.U))
  val res_remsw = Mux(sign_a === 0.U, res(xlen + 31, xlen), ((~res(xlen + 31, xlen)) + 1.U))
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
          res := Cat(Fill(xlen, 0.U), abs_b)
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
          res := Cat(Fill(xlen - 1, 0.U), abs_a, Fill(1, 0.U))
        }.elsewhen(div_cnt === xlen.U) {
          res := Cat(front_val(xlen - 1), step_result(2 * xlen - 1, xlen + 1), step_result(xlen - 1, 0))
        }.otherwise {
          res := step_result
        }
      }

    }
  }


  when(is_mult) {
    front_val := Cat(Fill(1, 0.U), Mux(res(0), abs_a, 0.U(xlen.W))) + Cat(Fill(1, 0.U), res(2 * xlen - 1, xlen))
    step_result := Cat(front_val(xlen - 1, 0), res(xlen - 1, 0))
    io.stall_req := io.start && (mult_cnt =/= (xlen + 1).U || (!last_stall_req && !check_history_same(io.a, io.b, io.op, last_a, last_b, last_op)))
    io.mult_out := MuxLookup(io.op, Cat(Fill(32, res(31)), res(31, 0)),
      Seq(
        ALU_MUL -> res(xlen - 1, 0),
        ALU_MULH -> res_ss(2 * xlen - 1, xlen),
        ALU_MULHSU -> res_su(2 * xlen - 1, xlen),
        ALU_MULHU -> res(2 * xlen - 1, xlen),
        ALU_MULW -> Cat(Fill(32, res(31)), res(31, 0))
      )
    )
  }.otherwise {
    front_val := Mux(res(2 * xlen - 1, xlen) >= abs_b, res(2 * xlen - 1, xlen) - abs_b, res(2 * xlen - 1, xlen))
    step_result := Cat(front_val(xlen - 2, 0), res(xlen - 1, 0), (res(2 * xlen - 1, xlen) >= abs_b).asUInt)
    io.stall_req := io.start && (div_cnt =/= (xlen + 1).U || (!last_stall_req && !check_history_same(io.a, io.b, io.op, last_a, last_b, last_op)))
    io.mult_out := MuxLookup(io.op, 0.U,
      Seq(
        ALU_DIV -> Mux(io.b.orR, res_divs, Fill(xlen, 1.U)),
        ALU_DIVU -> Mux(io.b.orR, res(xlen - 1, 0), Fill(xlen, 1.U)),
        ALU_DIVW -> Mux(io.b(31, 0).orR, Cat(Fill(32, res_divsw(31)), res_divsw), Fill(xlen, 1.U)),
        ALU_DIVUW -> Mux(io.b(31, 0).orR, Cat(Fill(32, res(31)), res(31, 0)), Fill(xlen, 1.U)),
        ALU_REM -> Mux(io.b.orR, res_rems, io.a),
        ALU_REMU -> Mux(io.b.orR, res(2 * xlen - 1, xlen), io.a),
        ALU_REMW -> Mux(io.b(31, 0).orR, Cat(Fill(32, res_remsw(31)), res_remsw), io.a),
        ALU_REMUW -> Mux(io.b(31, 0).orR, Cat(Fill(32, res(xlen + 31)), res(xlen + 31, xlen)), io.a)
      )
    )
  }

}