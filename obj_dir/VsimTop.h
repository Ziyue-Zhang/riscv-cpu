// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSIMTOP_H_
#define _VSIMTOP_H_  // guard

#include "verilated_heavy.h"

//==========

class VsimTop__Syms;
class VsimTop_VerilatedVcd;


//----------

VL_MODULE(VsimTop) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT8(io_diffTestIO_valid,0,0);
    VL_OUT8(io_coreIO_inst_read_io_en,0,0);
    VL_OUT8(io_coreIO_data_read_io_en,0,0);
    VL_OUT8(io_coreIO_data_write_io_en,0,0);
    VL_OUT64(io_diffTestIO_regfile_0,63,0);
    VL_OUT64(io_diffTestIO_regfile_1,63,0);
    VL_OUT64(io_diffTestIO_regfile_2,63,0);
    VL_OUT64(io_diffTestIO_regfile_3,63,0);
    VL_OUT64(io_diffTestIO_regfile_4,63,0);
    VL_OUT64(io_diffTestIO_regfile_5,63,0);
    VL_OUT64(io_diffTestIO_regfile_6,63,0);
    VL_OUT64(io_diffTestIO_regfile_7,63,0);
    VL_OUT64(io_diffTestIO_regfile_8,63,0);
    VL_OUT64(io_diffTestIO_regfile_9,63,0);
    VL_OUT64(io_diffTestIO_regfile_10,63,0);
    VL_OUT64(io_diffTestIO_regfile_11,63,0);
    VL_OUT64(io_diffTestIO_regfile_12,63,0);
    VL_OUT64(io_diffTestIO_regfile_13,63,0);
    VL_OUT64(io_diffTestIO_regfile_14,63,0);
    VL_OUT64(io_diffTestIO_regfile_15,63,0);
    VL_OUT64(io_diffTestIO_regfile_16,63,0);
    VL_OUT64(io_diffTestIO_regfile_17,63,0);
    VL_OUT64(io_diffTestIO_regfile_18,63,0);
    VL_OUT64(io_diffTestIO_regfile_19,63,0);
    VL_OUT64(io_diffTestIO_regfile_20,63,0);
    VL_OUT64(io_diffTestIO_regfile_21,63,0);
    VL_OUT64(io_diffTestIO_regfile_22,63,0);
    VL_OUT64(io_diffTestIO_regfile_23,63,0);
    VL_OUT64(io_diffTestIO_regfile_24,63,0);
    VL_OUT64(io_diffTestIO_regfile_25,63,0);
    VL_OUT64(io_diffTestIO_regfile_26,63,0);
    VL_OUT64(io_diffTestIO_regfile_27,63,0);
    VL_OUT64(io_diffTestIO_regfile_28,63,0);
    VL_OUT64(io_diffTestIO_regfile_29,63,0);
    VL_OUT64(io_diffTestIO_regfile_30,63,0);
    VL_OUT64(io_diffTestIO_regfile_31,63,0);
    VL_OUT64(io_diffTestIO_pc,63,0);
    VL_OUT64(io_coreIO_inst_read_io_addr,63,0);
    VL_IN64(io_coreIO_inst_read_io_data,63,0);
    VL_OUT64(io_coreIO_data_read_io_addr,63,0);
    VL_IN64(io_coreIO_data_read_io_data,63,0);
    VL_OUT64(io_coreIO_data_write_io_addr,63,0);
    VL_OUT64(io_coreIO_data_write_io_data,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel;
    CData/*2:0*/ simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu;
    CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_79;
    CData/*3:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_124;
    CData/*3:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_139;
    CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_196;
    CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_211;
    CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_240;
    CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_276;
    CData/*3:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_312;
    CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_346;
    CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_361;
    CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_385;
    CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_429;
    CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_603;
    CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel;
    CData/*4:0*/ simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr;
    CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load;
    CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_612;
    CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_617;
    CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT__stall;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid;
    CData/*4:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr;
    CData/*3:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type;
    CData/*3:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun;
    CData/*1:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid;
    CData/*4:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen;
    CData/*1:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    CData/*4:0*/ simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_79;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_85;
    CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_91;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_data;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__if_reg_inst;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_133;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_134;
    QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[32];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__clock;
    CData/*0:0*/ __Vm_traceActivity[2];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VsimTop__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VsimTop);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VsimTop(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VsimTop();
    /// Trace signals in the model; called by application code
    void trace(VerilatedVcdC* tfp, int levels, int options = 0);
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval() { eval_step(); }
    /// Evaluate when calling multiple units/models per time step.
    void eval_step();
    /// Evaluate at end of a timestep for tracing, when using eval_step().
    /// Application must call after all eval() and before time changes.
    void eval_end_step() {}
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VsimTop__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VsimTop__Syms* symsp, bool first);
  private:
    static QData _change_request(VsimTop__Syms* __restrict vlSymsp);
    static QData _change_request_1(VsimTop__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VsimTop__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VsimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VsimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VsimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VsimTop__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VsimTop__Syms* __restrict vlSymsp) VL_ATTR_COLD;
  private:
    static void traceChgSub0(void* userp, VerilatedVcd* tracep);
    static void traceChgTop0(void* userp, VerilatedVcd* tracep);
    static void traceCleanup(void* userp, VerilatedVcd* /*unused*/);
    static void traceFullSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceFullTop0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitSub0(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInitTop(void* userp, VerilatedVcd* tracep) VL_ATTR_COLD;
    void traceRegister(VerilatedVcd* tracep) VL_ATTR_COLD;
    static void traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
