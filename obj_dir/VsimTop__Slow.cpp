// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsimTop.h for the primary calling header

#include "VsimTop.h"
#include "VsimTop__Syms.h"

//==========

VL_CTOR_IMP(VsimTop) {
    VsimTop__Syms* __restrict vlSymsp = __VlSymsp = new VsimTop__Syms(this, name());
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VsimTop::__Vconfigure(VsimTop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

VsimTop::~VsimTop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void VsimTop::_initial__TOP__1(VsimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_initial__TOP__1\n"); );
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->io_coreIO_inst_read_io_en = 1U;
    vlTOPp->io_coreIO_data_read_io_en = 1U;
    vlTOPp->io_coreIO_data_write_io_en = 1U;
}

void VsimTop::_settle__TOP__3(VsimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_settle__TOP__3\n"); );
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp6[4];
    WData/*127:0*/ __Vtemp7[4];
    // Body
    vlTOPp->io_diffTestIO_valid = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    vlTOPp->io_coreIO_data_write_io_data = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_data;
    vlTOPp->io_diffTestIO_regfile_0 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0U];
    vlTOPp->io_diffTestIO_regfile_1 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [1U];
    vlTOPp->io_diffTestIO_regfile_2 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [2U];
    vlTOPp->io_diffTestIO_regfile_3 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [3U];
    vlTOPp->io_diffTestIO_regfile_4 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [4U];
    vlTOPp->io_diffTestIO_regfile_5 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [5U];
    vlTOPp->io_diffTestIO_regfile_6 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [6U];
    vlTOPp->io_diffTestIO_regfile_7 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [7U];
    vlTOPp->io_diffTestIO_regfile_8 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [8U];
    vlTOPp->io_diffTestIO_regfile_9 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [9U];
    vlTOPp->io_diffTestIO_regfile_10 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0xaU];
    vlTOPp->io_diffTestIO_regfile_11 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0xbU];
    vlTOPp->io_diffTestIO_regfile_12 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0xcU];
    vlTOPp->io_diffTestIO_regfile_13 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0xdU];
    vlTOPp->io_diffTestIO_regfile_14 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0xeU];
    vlTOPp->io_diffTestIO_regfile_15 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0xfU];
    vlTOPp->io_diffTestIO_regfile_16 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x10U];
    vlTOPp->io_diffTestIO_regfile_17 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x11U];
    vlTOPp->io_diffTestIO_regfile_18 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x12U];
    vlTOPp->io_diffTestIO_regfile_19 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x13U];
    vlTOPp->io_diffTestIO_regfile_20 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x14U];
    vlTOPp->io_diffTestIO_regfile_21 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x15U];
    vlTOPp->io_diffTestIO_regfile_22 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x16U];
    vlTOPp->io_diffTestIO_regfile_23 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x17U];
    vlTOPp->io_diffTestIO_regfile_24 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x18U];
    vlTOPp->io_diffTestIO_regfile_25 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x19U];
    vlTOPp->io_diffTestIO_regfile_26 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x1aU];
    vlTOPp->io_diffTestIO_regfile_27 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x1bU];
    vlTOPp->io_diffTestIO_regfile_28 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x1cU];
    vlTOPp->io_diffTestIO_regfile_29 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x1dU];
    vlTOPp->io_diffTestIO_regfile_30 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x1eU];
    vlTOPp->io_diffTestIO_regfile_31 = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
        [0x1fU];
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
           == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data);
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt 
        = VL_LTS_IQQ(1,64,64, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data);
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
           < vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data);
    vlTOPp->io_diffTestIO_pc = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
    vlTOPp->io_coreIO_inst_read_io_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4 
        = (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc);
    vlTOPp->io_coreIO_data_read_io_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out;
    vlTOPp->io_coreIO_data_write_io_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out;
    VL_EXTEND_WQ(127,64, __Vtemp6, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1);
    VL_SHIFTL_WWI(127,127,6, __Vtemp7, __Vtemp6, (0x3fU 
                                                  & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res 
        = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
            ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
               + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
            : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                   - vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                : ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                    ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                    : ((6U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                        ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                           | vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                        : ((7U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                            ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                               ^ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                            : ((8U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                ? (QData)((IData)(VL_LTS_IQQ(1,64,64, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                                : ((9U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                    ? (QData)((IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                       < vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                        ? (((QData)((IData)(
                                                            __Vtemp7[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             __Vtemp7[0U])))
                                        : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                            ? VL_SHIFTRS_QQI(64,64,6, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, 
                                                             (0x3fU 
                                                              & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                                            : ((3U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                   >> 
                                                   (0x3fU 
                                                    & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                                                : (
                                                   (0xaU 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1
                                                    : 0ULL)))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_312 
        = ((0x2013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 8U : ((0x3013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 9U : ((0x1013ULL == (0xfc00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 2U : ((0x40005013ULL 
                                       == (0xfc00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 4U : ((0x5013ULL 
                                                == 
                                                (0xfc00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 3U
                                                : (
                                                   (0x1033ULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 2U
                                                    : 
                                                   ((0x33ULL 
                                                     == 
                                                     (0xfe00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x40000033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 1U
                                                      : 
                                                     ((0x2033ULL 
                                                       == 
                                                       (0xfe00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 8U
                                                       : 
                                                      ((0x3033ULL 
                                                        == 
                                                        (0xfe00707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 9U
                                                        : 
                                                       ((0x7033ULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 5U
                                                         : 
                                                        ((0x6033ULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 6U
                                                          : 
                                                         ((0x4033ULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 7U
                                                           : 
                                                          ((0x40005033ULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 4U
                                                            : 
                                                           ((0x5033ULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 3U
                                                             : 0U)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_385 
        = ((0x4013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x2013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x3013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x1013ULL == (0xfc00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x40005013ULL == (0xfc00707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x5013ULL == (0xfc00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x1033ULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x33ULL == (0xfe00707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x40000033ULL == 
                                    (0xfe00707fULL 
                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x2033ULL == 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x3033ULL 
                                          == (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x7033ULL 
                                             == (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | ((0x6033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               | ((0x4033ULL 
                                                   == 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  | ((0x40005033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     | ((0x5033ULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        | ((0x6fULL 
                                                            == 
                                                            (0x7fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           | (0x67ULL 
                                                              == 
                                                              (0x707fULL 
                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_429 
        = ((0x2023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x23ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | (0x1023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel 
        = ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((3ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x4003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x1003ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x5003ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x2023ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x23ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x1023ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x17ULL 
                                                       == 
                                                       (0x7fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 1U
                                                       : 0U)))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data 
        = ((0U != (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                    >> 0x14U)))) ? 
           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
           [(0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                              >> 0x14U)))] : 0ULL);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_79 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0x14U)))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                              >> 0x14U))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_85 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0x14U)))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                              >> 0x14U))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_91 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0x14U)))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                              >> 0x14U))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_124 
        = ((0x2033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x3033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x7033ULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x6033ULL == 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x4033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x40005033ULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x5033ULL 
                                                     == 
                                                     (0xfe00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x6fULL 
                                                      == 
                                                      (0x7fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 7U
                                                      : 
                                                     ((0x67ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 8U
                                                       : 
                                                      ((0x63ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 2U
                                                        : 
                                                       ((0x1063ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 1U
                                                         : 
                                                        ((0x5063ULL 
                                                          == 
                                                          (0x707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 3U
                                                          : 
                                                         ((0x7063ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 4U
                                                           : 
                                                          ((0x4063ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 5U
                                                            : 
                                                           ((0x6063ULL 
                                                             == 
                                                             (0x707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 6U
                                                             : 0U)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_346 
        = ((0x1013ULL == (0xfc00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x40005013ULL == (0xfc00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x5013ULL == (0xfc00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x1033ULL == 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x33ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x40000033ULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x2033ULL 
                                                     == 
                                                     (0xfe00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x3033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x7033ULL 
                                                       == 
                                                       (0xfe00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x6033ULL 
                                                        == 
                                                        (0xfe00707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x4033ULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x40005033ULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x5033ULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x6fULL 
                                                            == 
                                                            (0x7fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 2U
                                                            : 
                                                           ((0x67ULL 
                                                             == 
                                                             (0x707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 2U
                                                             : 0U)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_196 
        = ((0x2033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x3033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x7033ULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x6033ULL == 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x4033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x40005033ULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x5033ULL 
                                                     == 
                                                     (0xfe00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x6fULL 
                                                      == 
                                                      (0x7fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 5U
                                                      : 
                                                     ((0x67ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 1U
                                                       : 
                                                      ((0x63ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 3U
                                                        : 
                                                       ((0x1063ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 3U
                                                         : 
                                                        ((0x5063ULL 
                                                          == 
                                                          (0x707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 3U
                                                          : 
                                                         ((0x7063ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 3U
                                                           : 
                                                          ((0x4063ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 3U
                                                            : 
                                                           ((0x6063ULL 
                                                             == 
                                                             (0x707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 3U
                                                             : 0U)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_79 
        = ((0x63ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x1063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x5063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x7063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x4063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | (0x6063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_603 
        = ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
            ? ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq)
                ? 0U : 1U) : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
                               ? ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq)
                                   ? 1U : 0U) : ((3U 
                                                  == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
                                                  ? 
                                                 ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt)
                                                   ? 0U
                                                   : 1U)
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
                                                   ? 
                                                  ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu)
                                                    ? 0U
                                                    : 1U)
                                                   : 
                                                  ((5U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
                                                    ? 
                                                   ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt)
                                                     ? 1U
                                                     : 0U)
                                                    : 
                                                   ((6U 
                                                     == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
                                                     ? 
                                                    ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    ((7U 
                                                      == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
                                                      ? 1U
                                                      : 
                                                     ((8U 
                                                       == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
                                                       ? 2U
                                                       : 0U))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_139 
        = ((0x1023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x17ULL == (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x37ULL == (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x13ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x7013ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x6013ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x4013ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x2013ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x3013ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x1013ULL 
                                                        == 
                                                        (0xfc00707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x40005013ULL 
                                                         == 
                                                         (0xfc00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x5013ULL 
                                                          == 
                                                          (0xfc00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x1033ULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x33ULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x40000033ULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_124))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_361 
        = ((3ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x4003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((0x1003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 1U : ((0x5003ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 1U : ((0x2023ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x23ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x1023ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x17ULL 
                                                      == 
                                                      (0x7fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x37ULL 
                                                       == 
                                                       (0x7fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x13ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x7013ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x6013ULL 
                                                          == 
                                                          (0x707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x4013ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x2013ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x3013ULL 
                                                             == 
                                                             (0x707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_346))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_211 
        = ((0x1023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 2U : ((0x17ULL == (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 4U : ((0x37ULL == (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 4U : ((0x13ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 1U : ((0x7013ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 1U
                                                : (
                                                   (0x6013ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 1U
                                                    : 
                                                   ((0x4013ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 1U
                                                     : 
                                                    ((0x2013ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 1U
                                                      : 
                                                     ((0x3013ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 1U
                                                       : 
                                                      ((0x1013ULL 
                                                        == 
                                                        (0xfc00707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 1U
                                                        : 
                                                       ((0x40005013ULL 
                                                         == 
                                                         (0xfc00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 1U
                                                         : 
                                                        ((0x5013ULL 
                                                          == 
                                                          (0xfc00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 1U
                                                          : 
                                                         ((0x1033ULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x33ULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x40000033ULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_196))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_240 
        = ((0x2013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x3013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x1013ULL == (0xfc00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x40005013ULL == (0xfc00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x5013ULL == (0xfc00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x1033ULL == (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x33ULL == (0xfe00707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x40000033ULL == (0xfe00707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x2033ULL == (0xfe00707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x3033ULL == 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x7033ULL 
                                          == (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x6033ULL 
                                             == (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | ((0x4033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               | ((0x40005033ULL 
                                                   == 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  | ((0x5033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     | ((0x6fULL 
                                                         != 
                                                         (0x7fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x67ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_79))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_276 
        = ((0x2013ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x3013ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x1013ULL != (0xfc00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x40005013ULL != (0xfc00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x5013ULL != (0xfc00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x1033ULL == (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x33ULL == (0xfe00707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x40000033ULL == (0xfe00707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x2033ULL == (0xfe00707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x3033ULL == 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x7033ULL 
                                          == (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x6033ULL 
                                             == (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | ((0x4033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               | ((0x40005033ULL 
                                                   == 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  | ((0x5033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     | ((0x6fULL 
                                                         != 
                                                         (0x7fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x67ULL 
                                                            != 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_79))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel 
        = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
            ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_603));
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel 
        = ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((3ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((0x4003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 1U : ((0x1003ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 1U : ((0x5003ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 1U
                                                : (
                                                   (0x2023ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 2U
                                                    : 
                                                   ((0x23ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 2U
                                                     : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_211))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_612 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load) 
             & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr) 
                == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                     >> 0xfU))))) & 
            (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr))) 
           & ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
              & ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((3ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x4003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x1003ULL == (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x5003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x2023ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x23ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x1023ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x17ULL != 
                                          (0x7fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x37ULL 
                                             != (0x7fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x13ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               | ((0x7013ULL 
                                                   == 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  | ((0x6013ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     | ((0x4013ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_240)))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_617 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load) 
             & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr) 
                == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                     >> 0x14U))))) 
            & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr))) 
           & ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
              & ((0x2003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((3ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x4003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x1003ULL != (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x5003ULL != (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x2023ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x23ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x1023ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x17ULL != 
                                          (0x7fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x37ULL 
                                             != (0x7fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x13ULL 
                                                != 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x7013ULL 
                                                   != 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x6013ULL 
                                                      != 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x4013ULL 
                                                         != 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_276)))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_612) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_617));
}

void VsimTop::_eval_initial(VsimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_eval_initial\n"); );
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void VsimTop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::final\n"); );
    // Variables
    VsimTop__Syms* __restrict vlSymsp = this->__VlSymsp;
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VsimTop::_eval_settle(VsimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_eval_settle\n"); );
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void VsimTop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_ctor_var_reset\n"); );
    // Body
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    io_diffTestIO_regfile_0 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_1 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_2 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_3 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_4 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_5 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_6 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_7 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_8 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_9 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_10 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_11 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_12 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_13 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_14 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_15 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_16 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_17 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_18 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_19 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_20 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_21 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_22 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_23 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_24 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_25 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_26 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_27 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_28 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_29 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_30 = VL_RAND_RESET_Q(64);
    io_diffTestIO_regfile_31 = VL_RAND_RESET_Q(64);
    io_diffTestIO_pc = VL_RAND_RESET_Q(64);
    io_diffTestIO_valid = VL_RAND_RESET_I(1);
    io_coreIO_inst_read_io_addr = VL_RAND_RESET_Q(64);
    io_coreIO_inst_read_io_data = VL_RAND_RESET_Q(64);
    io_coreIO_inst_read_io_en = VL_RAND_RESET_I(1);
    io_coreIO_data_read_io_addr = VL_RAND_RESET_Q(64);
    io_coreIO_data_read_io_data = VL_RAND_RESET_Q(64);
    io_coreIO_data_read_io_en = VL_RAND_RESET_I(1);
    io_coreIO_data_write_io_addr = VL_RAND_RESET_Q(64);
    io_coreIO_data_write_io_data = VL_RAND_RESET_Q(64);
    io_coreIO_data_write_io_en = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_79 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_124 = VL_RAND_RESET_I(4);
    simTop__DOT__mycore__DOT__cpath__DOT___T_139 = VL_RAND_RESET_I(4);
    simTop__DOT__mycore__DOT__cpath__DOT___T_196 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_211 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_240 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_276 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_312 = VL_RAND_RESET_I(4);
    simTop__DOT__mycore__DOT__cpath__DOT___T_346 = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT___T_361 = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT___T_385 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_429 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_603 = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_612 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_617 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT__stall = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type = VL_RAND_RESET_I(4);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun = VL_RAND_RESET_I(4);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_data = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__if_reg_inst = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT___T_79 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_85 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_91 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_133 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT___T_134 = VL_RAND_RESET_Q(64);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
