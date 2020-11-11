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
    VL_OUT8(io_coreIO_inst_readIO_en,0,0);
    VL_OUT8(io_coreIO_data_readIO_en,0,0);
    VL_OUT8(io_coreIO_data_writeIO_en,0,0);
    VL_OUT8(io_coreIO_data_writeIO_mask,7,0);
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
    VL_OUT64(io_coreIO_inst_readIO_addr,63,0);
    VL_IN64(io_coreIO_inst_readIO_data,63,0);
    VL_OUT64(io_coreIO_data_readIO_addr,63,0);
    VL_IN64(io_coreIO_data_readIO_data,63,0);
    VL_OUT64(io_coreIO_data_writeIO_addr,63,0);
    VL_OUT64(io_coreIO_data_writeIO_data,63,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*1:0*/ simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath_io_ctl_if_kill;
        CData/*1:0*/ simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu;
        CData/*3:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_264;
        CData/*3:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_279;
        CData/*3:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_294;
        CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_319;
        CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_334;
        CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_349;
        CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_364;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_412;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_427;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_442;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_470;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_471;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_477;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_494;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_511;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_568;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_585;
        CData/*4:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_615;
        CData/*4:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_630;
        CData/*4:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_645;
        CData/*4:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_660;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_689;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_704;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_719;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_734;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_784;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_801;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_833;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_850;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_867;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_884;
        CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_963;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1129;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1144;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1159;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1174;
        CData/*2:0*/ simTop__DOT__mycore__DOT__cpath__DOT__cs0_7;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1204;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1221;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1238;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1255;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT__cs0_8;
        CData/*1:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1285;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1288;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1289;
        CData/*4:0*/ simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1311;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT__stall;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1295;
        CData/*0:0*/ simTop__DOT__mycore__DOT__cpath__DOT___T_1313;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid;
        CData/*4:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr;
    };
    struct {
        CData/*3:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type;
        CData/*4:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun;
        CData/*2:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen;
        CData/*1:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn;
        CData/*7:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ;
        CData/*2:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid;
        CData/*2:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_csr_cmd;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid;
        CData/*4:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen;
        CData/*2:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel;
        CData/*2:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid;
        CData/*2:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
        CData/*4:0*/ simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_4;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_22;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_79;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_83;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_87;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_103;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_105;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_109;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_111;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_115;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_117;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_140;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_161;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_20;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu;
        CData/*4:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult;
        CData/*6:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt;
        CData/*6:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_stall_req;
        CData/*6:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_186;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_289;
        CData/*6:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_194;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_261;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_mtip;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_msip;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_mtip;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_msip;
        CData/*1:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie;
        CData/*2:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__write_illegal;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_174;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_189;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_204;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_219;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_234;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_249;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_legal;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_256;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__read_illegal;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable;
    };
    struct {
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_92;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt;
        CData/*1:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now;
        CData/*0:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_244;
        SData/*14:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_237;
        WData/*127:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[4];
        IData/*31:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_36;
        IData/*31:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_106;
        IData/*31:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_divsw;
        IData/*31:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_remsw;
        WData/*64:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[3];
        WData/*127:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[4];
        WData/*127:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[4];
        WData/*127:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[4];
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath_io_data_writeIO_data;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data;
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
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__imm_itype_sext;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__imm_stype_sext;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__imm_sbtype_sext;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__imm_utype_sext;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__imm_ujtype_sext;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__dec_alu_op2;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_176;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_186;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_196;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_153;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__dec_op1_data;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__dec_op2_data;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT___T_212;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_71;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_a;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_b;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_15;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_90;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_268;
    };
    struct {
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_405;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtvec;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mscratch;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg0;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg1;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_0;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_1;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_2;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_3;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_4;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_5;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_6;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_7;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_8;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_9;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_10;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_11;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_12;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_13;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_14;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_15;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcycle;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_minstret;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_0;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_1;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_2;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_3;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_4;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_5;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_6;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_7;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_8;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_9;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_10;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_11;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_12;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_13;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_14;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_15;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_16;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_17;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_18;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_19;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_20;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_21;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_22;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_23;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_24;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_25;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_26;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_27;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_28;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcounterinhibit;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_0;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_1;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_2;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_3;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_4;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_5;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_6;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_7;
    };
    struct {
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_8;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_9;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_10;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_11;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_12;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_13;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_14;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_15;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_16;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_17;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_18;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_19;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_20;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_21;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_22;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_23;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_24;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_25;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_26;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_27;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_28;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9395;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9405;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9415;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9425;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9435;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9445;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9455;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9465;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9475;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9479;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9482;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_99;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_17729;
        QData/*63:0*/ simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[32];
    };
    
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
