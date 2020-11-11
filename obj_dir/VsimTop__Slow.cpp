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
    vlTOPp->io_coreIO_inst_readIO_en = 1U;
}

void VsimTop::_settle__TOP__3(VsimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_settle__TOP__3\n"); );
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    WData/*127:0*/ __Vtemp39[4];
    WData/*127:0*/ __Vtemp40[4];
    WData/*127:0*/ __Vtemp42[4];
    WData/*127:0*/ __Vtemp43[4];
    WData/*127:0*/ __Vtemp44[4];
    WData/*127:0*/ __Vtemp47[4];
    WData/*127:0*/ __Vtemp48[4];
    WData/*127:0*/ __Vtemp49[4];
    WData/*95:0*/ __Vtemp52[3];
    WData/*95:0*/ __Vtemp53[3];
    WData/*95:0*/ __Vtemp54[3];
    WData/*95:0*/ __Vtemp55[3];
    // Body
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
    vlTOPp->io_diffTestIO_pc = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
    vlTOPp->io_diffTestIO_valid = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    vlTOPp->io_coreIO_data_readIO_en = (1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn));
    vlTOPp->io_coreIO_data_writeIO_en = (2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_186 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_17729 
        = (1ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcycle);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_268 
        = (((QData)((IData)(((0x80000000U & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])
                              ? 0xffffffffU : 0U))) 
            << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_194 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult 
        = (((((0xdU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)) 
              | (0x12U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
             | (0x13U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
            | (0x14U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
           | (0x19U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_256 
        = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd)) 
           & (5U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_20 
        = (((((((((((0xdU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)) 
                    | (0xeU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
                   | (0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
                  | (0x10U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
                 | (0x11U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
                | (0x12U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
               | (0x13U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
              | (0x14U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
             | (0x15U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
            | (0x16U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
           | (0x17U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)));
    vlTOPp->io_coreIO_data_writeIO_data = ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
                                            ? (((QData)((IData)(
                                                                ((0xff000000U 
                                                                  & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                                     << 0x18U)) 
                                                                 | ((0xff0000U 
                                                                     & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                                        << 0x10U)) 
                                                                    | ((0xff00U 
                                                                        & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                                           << 8U)) 
                                                                       | (0xffU 
                                                                          & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data))))))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 ((0xff000000U 
                                                                   & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                                      << 0x18U)) 
                                                                  | ((0xff0000U 
                                                                      & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                                         << 0x10U)) 
                                                                     | ((0xff00U 
                                                                         & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                                            << 8U)) 
                                                                        | (0xffU 
                                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data))))))))
                                            : ((3U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
                                                ? (
                                                   ((QData)((IData)(
                                                                    ((0xffff0000U 
                                                                      & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                                         << 0x10U)) 
                                                                     | (0xffffU 
                                                                        & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data))))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     ((0xffff0000U 
                                                                       & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                                          << 0x10U)) 
                                                                      | (0xffffU 
                                                                         & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data))))))
                                                : (
                                                   (0xfU 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
                                                    ? 
                                                   (((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)))
                                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret 
        = ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd)) 
           & (0x302U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                           >> 0x14U)))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall 
        = ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd)) 
           & (0U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                       >> 0x14U)))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak 
        = ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd)) 
           & (1U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                       >> 0x14U)))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_15 
        = ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                          >> 0x3fU))) ? (1ULL + (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1))
            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_36 
        = ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                          >> 0x1fU))) ? ((IData)(1U) 
                                         + (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1)))
            : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1));
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
           == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data);
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt 
        = VL_LTS_IQQ(1,64,64, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data);
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
           < vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op 
        = ((((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd)) 
             | (4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))) 
            & (0U == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                       >> 0xfU)))))
            ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_90 
        = ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                          >> 0x3fU))) ? (1ULL + (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_106 
        = ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                          >> 0x1fU))) ? ((IData)(1U) 
                                         + (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
            : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_261 
        = (1U & ((~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_stall_req)) 
                 & (~ (((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                         == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_a) 
                        & (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                           == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_b)) 
                       & ((((((((((((0x14U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op)) 
                                    | (0x12U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op))) 
                                   | (0x13U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op))) 
                                  & (0xdU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
                                 | ((0xeU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op)) 
                                    & (0x17U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)))) 
                                | ((0x15U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op)) 
                                   & (0x18U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)))) 
                               | ((0x11U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op)) 
                                  & (0x10U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)))) 
                              | ((0x16U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op)) 
                                 & (0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)))) 
                             | ((0xeU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)) 
                                & (0x17U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op)))) 
                            | ((0x15U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)) 
                               & (0x18U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op)))) 
                           | ((0x11U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)) 
                              & (0x10U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op)))) 
                          | ((0x16U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)) 
                             & (0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_remsw 
        = ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                          >> 0x3fU))) ? ((IData)(1U) 
                                         + (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))
            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_divsw 
        = (((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                           >> 0x1fU))) == (1U & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                                                         >> 0x1fU))))
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]
            : ((IData)(1U) + (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153 
        = ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                          >> 0x3fU))) == (1U & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                                                        >> 0x3fU))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9395 
        = (((((((((0x300U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                >> 0x14U))))
                   ? (((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp)) 
                       << 0xbU) | (QData)((IData)((
                                                   ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie) 
                                                    << 7U) 
                                                   | ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie) 
                                                      << 3U)))))
                   : 0ULL) | ((0x301U == (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                               ? 0x8000000000001100ULL
                               : 0ULL)) | ((0x304U 
                                            == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                            ? (QData)((IData)(
                                                              (((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_mtip) 
                                                                << 7U) 
                                                               | ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_msip) 
                                                                  << 3U))))
                                            : 0ULL)) 
               | ((0x344U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                >> 0x14U))))
                   ? (QData)((IData)((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_mtip) 
                                       << 7U) | ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_msip) 
                                                 << 3U))))
                   : 0ULL)) | ((0x305U == (0xfffU & (IData)(
                                                            (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                             >> 0x14U))))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtvec
                                : 0ULL)) | ((0x340U 
                                             == (0xfffU 
                                                 & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                                             ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mscratch
                                             : 0ULL)) 
            | ((0x341U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                             >> 0x14U))))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc
                : 0ULL)) | ((0x342U == (0xfffU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                          >> 0x14U))))
                             ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause
                             : 0ULL));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_174 
        = (((((((((((((((0xf11U == (0xfffU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                      >> 0x14U)))) 
                        | (0xf12U == (0xfffU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))) 
                       | (0xf13U == (0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U))))) 
                      | (0xf14U == (0xfffU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                      >> 0x14U))))) 
                     | (0x300U == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))) 
                    | (0x301U == (0xfffU & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                    >> 0x14U))))) 
                   | (0x302U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                   >> 0x14U))))) 
                  | (0x303U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))) 
                 | (0x304U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                 >> 0x14U))))) 
                | (0x344U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                >> 0x14U))))) 
               | (0x305U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))) 
              | (0x306U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) 
             | (0x340U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                             >> 0x14U))))) 
            | (0x341U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))) 
           | (0x342U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                           >> 0x14U)))));
    vlTOPp->io_coreIO_inst_readIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4 
        = (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174 
        = ((((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data 
                            >> 7U))) ? 0xffffffffffffffULL
              : 0ULL) << 8U) | (QData)((IData)((0xffU 
                                                & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data)))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_184 
        = ((((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data 
                            >> 0xfU))) ? 0xffffffffffffULL
              : 0ULL) << 0x10U) | (QData)((IData)((0xffffU 
                                                   & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data)))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_194 
        = (((QData)((IData)(((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data 
                                            >> 0x1fU)))
                              ? 0xffffffffU : 0U))) 
            << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_963 
        = ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x6003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((3ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 1U : ((0x4003ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 1U : ((0x1003ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 1U
                                                : (
                                                   (0x5003ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 1U
                                                    : 
                                                   ((0x3023ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 2U
                                                     : 
                                                    ((0x2023ULL 
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
                                                       : 
                                                      ((0x1023ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 2U
                                                        : 0U))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data 
        = ((0U != (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                    >> 0x14U)))) ? 
           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
           [(0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                              >> 0x14U)))] : 0ULL);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_103 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0x14U)))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                              >> 0x14U))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_109 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0x14U)))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                              >> 0x14U))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_115 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0x14U)))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                              >> 0x14U))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_264 
        = ((0x501bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x4000501bULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x3bULL == (0xfe00707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x4000003bULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x103bULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x4000503bULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x503bULL 
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data 
        = ((0U != (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                    >> 0xfU)))) ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
           [(0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                              >> 0xfU)))] : 0ULL);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_79 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0xfU)))) & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (IData)(
                                                            (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                             >> 0xfU))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_83 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0xfU)))) & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (IData)(
                                                            (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                             >> 0xfU))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_87 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0xfU)))) & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (IData)(
                                                            (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                             >> 0xfU))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_412 
        = ((0x501bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x4000501bULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((0x3bULL == (0xfe00707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x4000003bULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x103bULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x4000503bULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x503bULL 
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
    if ((0x2003033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))) {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_615 = 0x14U;
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_689 = 0U;
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_615 
            = ((0x2004033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0xeU : ((0x200503bULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                           ? 0x11U : ((0x2005033ULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0x15U : ((0x200403bULL 
                                                   == 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                   ? 0x16U
                                                   : 
                                                  ((0x200603bULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0xfU
                                                    : 
                                                   ((0x200703bULL 
                                                     == 
                                                     (0xfe00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0x10U
                                                     : 
                                                    ((0x2006033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0x17U
                                                      : 
                                                     ((0x2007033ULL 
                                                       == 
                                                       (0xfe00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0x18U
                                                       : 
                                                      ((0x5073ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0xaU
                                                        : 
                                                       ((0x6073ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0xaU
                                                         : 
                                                        ((0x1073ULL 
                                                          == 
                                                          (0x707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0xaU
                                                          : 
                                                         ((0x2073ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0xaU
                                                           : 
                                                          ((0x3073ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0xaU
                                                            : 
                                                           ((0x7073ULL 
                                                             == 
                                                             (0x707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0xaU
                                                             : 0U))))))))))))));
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_689 
            = ((0x2004033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0U : ((0x200503bULL == (0xfe00707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 0U : ((0x2005033ULL == (0xfe00707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x200403bULL 
                                           == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0U : (
                                                   (0x200603bULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x200703bULL 
                                                     == 
                                                     (0xfe00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x2006033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x2007033ULL 
                                                       == 
                                                       (0xfe00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x5073ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 3U
                                                        : 
                                                       ((0x6073ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 3U
                                                         : 
                                                        ((0x1073ULL 
                                                          == 
                                                          (0x707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 3U
                                                          : 
                                                         ((0x2073ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 3U
                                                           : 
                                                          ((0x3073ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 3U
                                                            : 
                                                           ((0x7073ULL 
                                                             == 
                                                             (0x707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 3U
                                                             : 0U))))))))))))));
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_833 
        = ((0x200403bULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x200603bULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x200703bULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x2006033ULL != (0xfe00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x2007033ULL != (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x5073ULL != (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x6073ULL != (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x1073ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x2073ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x3073ULL != 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x7073ULL 
                                          != (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x73ULL 
                                             != (0xffffffffULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x30200073ULL 
                                                != 
                                                (0xffffffffULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x10200073ULL 
                                                   != 
                                                   (0xffffffffULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x100073ULL 
                                                      != 
                                                      (0xffffffffULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x10500073ULL 
                                                         != 
                                                         (0xffffffffULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x100fULL 
                                                            != 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (0xfULL 
                                                              == 
                                                              (0x707fULL 
                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_319 
        = ((0x2003033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x2004033ULL == (0xfe00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x200503bULL == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x2005033ULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x200403bULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x200603bULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x200703bULL 
                                                     == 
                                                     (0xfe00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x2006033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x2007033ULL 
                                                       == 
                                                       (0xfe00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x5073ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 2U
                                                        : 
                                                       ((0x6073ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 2U
                                                         : 
                                                        ((0x1073ULL 
                                                          == 
                                                          (0x707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x2073ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x3073ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x7073ULL 
                                                             == 
                                                             (0x707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 2U
                                                             : 0U)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1129 
        = ((0x200403bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x200603bULL == (0xfe00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x200703bULL == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x2006033ULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x2007033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x5073ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 2U
                                                    : 
                                                   ((0x6073ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 4U
                                                     : 
                                                    ((0x1073ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 2U
                                                      : 
                                                     ((0x2073ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 4U
                                                       : 
                                                      ((0x3073ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 3U
                                                        : 
                                                       ((0x7073ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 3U
                                                         : 
                                                        ((0x73ULL 
                                                          == 
                                                          (0xffffffffULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 5U
                                                          : 
                                                         ((0x30200073ULL 
                                                           == 
                                                           (0xffffffffULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 5U
                                                           : 
                                                          ((0x10200073ULL 
                                                            == 
                                                            (0xffffffffULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 5U
                                                            : 
                                                           ((0x100073ULL 
                                                             == 
                                                             (0xffffffffULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 5U
                                                             : 0U)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1204 
        = ((0x2005033ULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x200403bULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x200603bULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x200703bULL != (0xfe00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x2006033ULL != (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x2007033ULL != (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x5073ULL != (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x6073ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x1073ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x2073ULL != 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x3073ULL 
                                          != (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x7073ULL 
                                             != (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x73ULL 
                                                != 
                                                (0xffffffffULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x30200073ULL 
                                                   != 
                                                   (0xffffffffULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x10200073ULL 
                                                      != 
                                                      (0xffffffffULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x100073ULL 
                                                         != 
                                                         (0xffffffffULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x10500073ULL 
                                                            != 
                                                            (0xffffffffULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (0x100fULL 
                                                              == 
                                                              (0x707fULL 
                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_470 
        = ((0x200003bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x2001033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x2002033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x2003033ULL == (0xfe00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x2004033ULL == (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x200503bULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x2005033ULL == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x200403bULL == (0xfe00707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x200603bULL == 
                                    (0xfe00707fULL 
                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x200703bULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x2006033ULL 
                                          == (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x2007033ULL 
                                             == (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | ((0x5073ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               | ((0x6073ULL 
                                                   == 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  | ((0x1073ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     | ((0x2073ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        | ((0x3073ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           | (0x7073ULL 
                                                              == 
                                                              (0x707fULL 
                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_20) 
           | (0x18U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a 
        = ((0x10U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
            ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1))
            : ((0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_36))
                : ((0x18U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1
                    : ((0x17U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_15
                        : ((0x11U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                            ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1))
                            : ((0x16U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_36))
                                : ((0x15U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1
                                    : ((0xeU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_15
                                        : ((0x19U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                            ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1))
                                            : ((0x14U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1
                                                : (
                                                   (0x13U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_15
                                                    : 
                                                   ((0x12U 
                                                     == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_15
                                                     : 
                                                    ((0xdU 
                                                      == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1
                                                      : (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1285 
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__write_illegal 
        = ((((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op)) 
             | (3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op))) 
            | (4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op))) 
           & (3U == (3U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                   >> 0x1eU)))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b 
        = ((0x10U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
            ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
            : ((0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_106))
                : ((0x18U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset
                    : ((0x17U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_90
                        : ((0x11U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                            ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
                            : ((0x16U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_106))
                                : ((0x15U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset
                                    : ((0xeU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_90
                                        : ((0x19U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                            ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
                                            : ((0x14U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset
                                                : (
                                                   (0x13U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset
                                                    : 
                                                   ((0x12U 
                                                     == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_90
                                                     : 
                                                    ((0xdU 
                                                      == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset
                                                      : (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_405 
        = ((0x18U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
            ? ((0U != vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                ? (((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                    << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U])))
                : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1)
            : ((0x17U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                ? ((0U != vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                    ? ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                      >> 0x3fU))) ? 
                       (1ULL + (~ (((QData)((IData)(
                                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U])))))
                        : (((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))))
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1)
                : ((0x11U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                    ? ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_268
                        : 0xffffffffffffffffULL) : 
                   ((0x16U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                     ? ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
                         ? (((QData)((IData)(((0x80000000U 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_divsw)
                                               ? 0xffffffffU
                                               : 0U))) 
                             << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_divsw)))
                         : 0xffffffffffffffffULL) : 
                    ((0x15U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                      ? ((0U != vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                          ? (((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                              << 0x20U) | (QData)((IData)(
                                                          vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])))
                          : 0xffffffffffffffffULL) : 
                     ((0xeU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                       ? ((0U != vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                           ? ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153)
                               ? (((QData)((IData)(
                                                   vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])))
                               : (1ULL + (~ (((QData)((IData)(
                                                              vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]))))))
                           : 0xffffffffffffffffULL)
                       : 0ULL))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9405 
        = ((((((((((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9395 
                    | ((0x343U == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval
                        : 0ULL)) | ((0x3a0U == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg0
                                     : 0ULL)) | ((0x3a1U 
                                                  == 
                                                  (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg1
                                                  : 0ULL)) 
                 | ((0xb00U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))
                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcycle
                     : 0ULL)) | ((0xb02U == (0xfffU 
                                             & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))
                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_minstret
                                  : 0ULL)) | ((0x320U 
                                               == (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcounterinhibit
                                               : 0ULL)) 
              | ((0x3b0U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))
                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_0
                  : 0ULL)) | ((0x3b1U == (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_1
                               : 0ULL)) | ((0x3b2U 
                                            == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_2
                                            : 0ULL)) 
           | ((0x3b3U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))
               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_3
               : 0ULL));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_189 
        = ((((((((((((((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_174) 
                         | (0x343U == (0xfffU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                         >> 0x14U))))) 
                        | (0x3a0U == (0xfffU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))) 
                       | (0x3a1U == (0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U))))) 
                      | (0xb00U == (0xfffU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                      >> 0x14U))))) 
                     | (0xb02U == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))) 
                    | (0x320U == (0xfffU & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                    >> 0x14U))))) 
                   | (0x3b0U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                   >> 0x14U))))) 
                  | (0x3b1U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))) 
                 | (0x3b2U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                 >> 0x14U))))) 
                | (0x3b3U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                >> 0x14U))))) 
               | (0x3b4U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))) 
              | (0x3b5U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) 
             | (0x3b6U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                             >> 0x14U))))) 
            | (0x3b7U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))) 
           | (0x3b8U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                           >> 0x14U)))));
    if ((0x1013ULL == (0xfc00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))) {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_279 = 0U;
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_427 = 1U;
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_279 
            = ((0x40005013ULL == (0xfc00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0U : ((0x5013ULL == (0xfc00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 0U : ((0x1033ULL == (0xfe00707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x33ULL 
                                           == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0U : (
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
                                                          ((0x1bULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x101bULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_264)))))))))))))));
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_427 
            = ((0x40005013ULL == (0xfc00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 1U : ((0x5013ULL == (0xfc00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 1U : ((0x1033ULL == (0xfe00707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x33ULL 
                                           == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0U : (
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
                                                          ((0x1bULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 1U
                                                            : 
                                                           ((0x101bULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 1U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_412)))))))))))))));
    }
    if ((0x103bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))) {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_630 = 2U;
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_704 = 4U;
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_630 
            = ((0x4000503bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0xcU : ((0x503bULL == (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                           ? 3U : ((0x6fULL == (0x7fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                    ? 0U : ((0x67ULL 
                                             == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                             ? 0U : 
                                            ((0x63ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                              ? 0U : 
                                             ((0x1063ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                               ? 0U
                                               : ((0x5063ULL 
                                                   == 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                   ? 0U
                                                   : 
                                                  ((0x7063ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x4063ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x6063ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x2000033ULL 
                                                       == 
                                                       (0xfe00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0xdU
                                                       : 
                                                      ((0x200003bULL 
                                                        == 
                                                        (0xfe00707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0xdU
                                                        : 
                                                       ((0x2001033ULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0x12U
                                                         : 
                                                        ((0x2002033ULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0x13U
                                                          : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_615)))))))))))))));
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_704 
            = ((0x4000503bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 4U : ((0x503bULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 4U : ((0x6fULL == (0x7fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 2U : ((0x67ULL 
                                           == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 2U : (
                                                   (0x63ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x1063ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x5063ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x7063ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x4063ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x6063ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x2000033ULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x200003bULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 4U
                                                           : 
                                                          ((0x2001033ULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x2002033ULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_689)))))))))))))));
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_850 
        = ((0x503bULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x6fULL != (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x67ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x63ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x1063ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x5063ULL != (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x7063ULL != (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x4063ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x6063ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x2000033ULL 
                                       != (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x200003bULL 
                                          != (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x2001033ULL 
                                             != (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x2002033ULL 
                                                != 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x2003033ULL 
                                                   != 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x2004033ULL 
                                                      != 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x200503bULL 
                                                         != 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x2005033ULL 
                                                            != 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_833))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_334 
        = ((0x103bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 3U : ((0x4000503bULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 3U : ((0x503bULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 3U : ((0x6fULL == (0x7fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x67ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x63ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x1063ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x5063ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x7063ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x4063ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x6063ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x2000033ULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x200003bULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x2001033ULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x2002033ULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_319))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1144 
        = ((0x67ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x63ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x1063ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x5063ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x7063ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x4063ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x6063ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x2000033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x200003bULL 
                                                       == 
                                                       (0xfe00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x2001033ULL 
                                                        == 
                                                        (0xfe00707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x2002033ULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x2003033ULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x2004033ULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x200503bULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x2005033ULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1129))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1221 
        = ((0x4000503bULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x503bULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x6fULL != (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x67ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x63ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x1063ULL != (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x5063ULL != (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x7063ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x4063ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x6063ULL != 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x2000033ULL 
                                          != (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x200003bULL 
                                             != (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x2001033ULL 
                                                != 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x2002033ULL 
                                                   != 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x2003033ULL 
                                                      != 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x2004033ULL 
                                                         != 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x200503bULL 
                                                            != 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1204))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_471 
        = ((0x2000033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_470));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
            ? ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu) 
               & ((0x41U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt)) 
                  | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_261)))
            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu) 
               & ((0x41U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt)) 
                  | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_261))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel 
        = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
            ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1285));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_289 
        = ((((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
             << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))) 
           >= vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b);
    VL_EXTEND_WQ(127,64, __Vtemp39, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1);
    VL_SHIFTL_WWI(127,127,6, __Vtemp40, __Vtemp39, 
                  (0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)));
    __Vtemp42[0U] = 1U;
    __Vtemp42[1U] = 0U;
    __Vtemp42[2U] = 0U;
    __Vtemp42[3U] = 0U;
    __Vtemp43[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
    __Vtemp43[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
    __Vtemp43[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
    __Vtemp43[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
    VL_ADD_W(4, __Vtemp44, __Vtemp42, __Vtemp43);
    __Vtemp47[0U] = 1U;
    __Vtemp47[1U] = 0U;
    __Vtemp47[2U] = 0U;
    __Vtemp47[3U] = 0U;
    __Vtemp48[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
    __Vtemp48[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
    __Vtemp48[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
    __Vtemp48[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
    VL_ADD_W(4, __Vtemp49, __Vtemp47, __Vtemp48);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_71 
        = ((6U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
            ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
               | vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
            : ((7U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                   ^ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                : ((8U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                    ? (QData)((IData)(VL_LTS_IQQ(1,64,64, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                    : ((9U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                        ? (QData)((IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                           < vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                        : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                            ? (((QData)((IData)(__Vtemp40[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            __Vtemp40[0U])))
                            : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                ? VL_SHIFTRS_QQI(64,64,6, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, 
                                                 (0x3fU 
                                                  & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                                : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                    ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                       >> (0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                                    : ((0xaU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1
                                        : ((0xbU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset
                                            : ((0xcU 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                ? (
                                                   ((QData)((IData)(
                                                                    ((1U 
                                                                      & (IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                                                >> 0x1fU)))
                                                                      ? 0xffffffffU
                                                                      : 0U))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     ((0x1fU 
                                                                       >= 
                                                                       (0x3fU 
                                                                        & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                                                                       ? 
                                                                      VL_SHIFTRS_III(32,32,6, (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1), 
                                                                                (0x3fU 
                                                                                & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                                                                       : 
                                                                      (- 
                                                                       ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1) 
                                                                        >> 0x1fU))))))
                                                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu)
                                                    ? 
                                                   ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
                                                     ? 
                                                    ((0x19U 
                                                      == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_268
                                                      : 
                                                     ((0x14U 
                                                       == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U])))
                                                       : 
                                                      ((0x13U 
                                                        == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         ((1U 
                                                                           & (IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                                                >> 0x3fU)))
                                                                           ? 
                                                                          __Vtemp44[3U]
                                                                           : 
                                                                          vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((1U 
                                                                            & (IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                                                >> 0x3fU)))
                                                                            ? 
                                                                           __Vtemp44[2U]
                                                                            : 
                                                                           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))))
                                                        : 
                                                       ((0x12U 
                                                         == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                         ? 
                                                        (((QData)((IData)(
                                                                          ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153)
                                                                            ? 
                                                                           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]
                                                                            : 
                                                                           __Vtemp49[3U]))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153)
                                                                             ? 
                                                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]
                                                                             : 
                                                                            __Vtemp49[2U]))))
                                                         : 
                                                        ((0xdU 
                                                          == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                          ? 
                                                         (((QData)((IData)(
                                                                           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                                           << 0x20U) 
                                                          | (QData)((IData)(
                                                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])))
                                                          : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_268)))))
                                                     : 
                                                    ((0x10U 
                                                      == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                      ? 
                                                     ((0U 
                                                       != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
                                                       ? 
                                                      (((QData)((IData)(
                                                                        ((0x80000000U 
                                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U])
                                                                          ? 0xffffffffU
                                                                          : 0U))) 
                                                        << 0x20U) 
                                                       | (QData)((IData)(
                                                                         vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U])))
                                                       : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1)
                                                      : 
                                                     ((0xfU 
                                                       == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                       ? 
                                                      ((0U 
                                                        != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         ((0x80000000U 
                                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_remsw)
                                                                           ? 0xffffffffU
                                                                           : 0U))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_remsw)))
                                                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1)
                                                       : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_405)))
                                                    : 0ULL)))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9415 
        = ((((((((((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9405 
                    | ((0x3b4U == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_4
                        : 0ULL)) | ((0x3b5U == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_5
                                     : 0ULL)) | ((0x3b6U 
                                                  == 
                                                  (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_6
                                                  : 0ULL)) 
                 | ((0x3b7U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))
                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_7
                     : 0ULL)) | ((0x3b8U == (0xfffU 
                                             & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))
                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_8
                                  : 0ULL)) | ((0x3b9U 
                                               == (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_9
                                               : 0ULL)) 
              | ((0x3baU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))
                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_10
                  : 0ULL)) | ((0x3bbU == (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_11
                               : 0ULL)) | ((0x3bcU 
                                            == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_12
                                            : 0ULL)) 
           | ((0x3bdU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))
               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_13
               : 0ULL));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_204 
        = ((((((((((((((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_189) 
                         | (0x3b9U == (0xfffU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                         >> 0x14U))))) 
                        | (0x3baU == (0xfffU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))) 
                       | (0x3bbU == (0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U))))) 
                      | (0x3bcU == (0xfffU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                      >> 0x14U))))) 
                     | (0x3bdU == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))) 
                    | (0x3beU == (0xfffU & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                    >> 0x14U))))) 
                   | (0x3bfU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                   >> 0x14U))))) 
                  | (0xb03U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))) 
                 | (0xb04U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                 >> 0x14U))))) 
                | (0xb05U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                >> 0x14U))))) 
               | (0xb06U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))) 
              | (0xb07U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) 
             | (0xb08U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                             >> 0x14U))))) 
            | (0xb09U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))) 
           | (0xb0aU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                           >> 0x14U)))));
    if ((0x4003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))) {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_294 = 0U;
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_442 = 1U;
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_294 
            = ((0x1003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0U : ((0x5003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 0U : ((0x3023ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x2023ULL 
                                           == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0U : (
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_279)))))))))))))));
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_442 
            = ((0x1003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 1U : ((0x5003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 1U : ((0x3023ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 2U : ((0x2023ULL 
                                           == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 2U : (
                                                   (0x23ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 2U
                                                    : 
                                                   ((0x1023ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 2U
                                                     : 
                                                    ((0x17ULL 
                                                      == 
                                                      (0x7fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 4U
                                                      : 
                                                     ((0x37ULL 
                                                       == 
                                                       (0x7fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 4U
                                                       : 
                                                      ((0x13ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 1U
                                                        : 
                                                       ((0x7013ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 1U
                                                         : 
                                                        ((0x6013ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_427)))))))))))))));
    }
    if ((0x33ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))) {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_645 = 0U;
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_719 = 0U;
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_645 
            = ((0x40000033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 1U : ((0x2033ULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 8U : ((0x3033ULL == (0xfe00707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 9U : ((0x7033ULL 
                                           == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 5U : (
                                                   (0x6033ULL 
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
                                                       : 
                                                      ((0x1bULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x101bULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 2U
                                                         : 
                                                        ((0x501bULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 3U
                                                          : 
                                                         ((0x4000501bULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0xcU
                                                           : 
                                                          ((0x3bULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x4000003bULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 1U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_630)))))))))))))));
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_719 
            = ((0x40000033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0U : ((0x2033ULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 0U : ((0x3033ULL == (0xfe00707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x7033ULL 
                                           == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0U : (
                                                   (0x6033ULL 
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
                                                      ((0x1bULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 4U
                                                        : 
                                                       ((0x101bULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 4U
                                                         : 
                                                        ((0x501bULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 4U
                                                          : 
                                                         ((0x4000501bULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 4U
                                                           : 
                                                          ((0x3bULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 4U
                                                            : 
                                                           ((0x4000003bULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 4U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_704)))))))))))))));
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_867 
        = ((0x33ULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x40000033ULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x2033ULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x3033ULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x7033ULL != (0xfe00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x6033ULL != (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x4033ULL != (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x40005033ULL != (0xfe00707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x5033ULL != (0xfe00707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x1bULL != (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x101bULL 
                                          != (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x501bULL 
                                             != (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x4000501bULL 
                                                != 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x3bULL 
                                                   != 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x4000003bULL 
                                                      != 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x103bULL 
                                                         != 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x4000503bULL 
                                                            != 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_850))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_349 
        = ((0x33ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x40000033ULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x2033ULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x3033ULL == 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x7033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x6033ULL 
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
                                                      ((0x1bULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x101bULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 3U
                                                         : 
                                                        ((0x501bULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 3U
                                                          : 
                                                         ((0x4000501bULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 3U
                                                           : 
                                                          ((0x3bULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x4000003bULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_334))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1159 
        = ((0x7033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x6033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x4033ULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x40005033ULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x5033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x1bULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x101bULL 
                                                     == 
                                                     (0xfe00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x501bULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x4000501bULL 
                                                       == 
                                                       (0xfe00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x3bULL 
                                                        == 
                                                        (0xfe00707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x4000003bULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0U
                                                         : 
                                                        ((0x103bULL 
                                                          == 
                                                          (0xfe00707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0U
                                                          : 
                                                         ((0x4000503bULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 0U
                                                           : 
                                                          ((0x503bULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 0U
                                                            : 
                                                           ((0x6fULL 
                                                             == 
                                                             (0x7fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1144))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1238 
        = ((0x1033ULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x33ULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x40000033ULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x2033ULL != (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x3033ULL != (0xfe00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x7033ULL != (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x6033ULL != (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x4033ULL != (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x40005033ULL != 
                                    (0xfe00707fULL 
                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x5033ULL != 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x1bULL != 
                                          (0x707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x101bULL 
                                             != (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x501bULL 
                                                != 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x4000501bULL 
                                                   != 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x3bULL 
                                                      != 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x4000003bULL 
                                                         != 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x103bULL 
                                                            != 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1221))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_784 
        = ((0x1bULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x101bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x501bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x4000501bULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x3bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x4000003bULL == (0xfe00707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x103bULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x4000503bULL == (0xfe00707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x503bULL == (0xfe00707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x6fULL == (0x7fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x67ULL == 
                                          (0x707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x63ULL 
                                             != (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x1063ULL 
                                                != 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x5063ULL 
                                                   != 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x7063ULL 
                                                      != 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x4063ULL 
                                                         != 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x6063ULL 
                                                            != 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_471))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_477 
        = ((0x63ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x1063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x5063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x7063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x4063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x6063ULL == (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_471)))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req));
    VL_EXTEND_WQ(65,64, __Vtemp52, ((1U & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a
                                     : 0ULL));
    VL_EXTEND_WQ(65,64, __Vtemp53, (((QData)((IData)(
                                                     vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))));
    VL_ADD_W(3, __Vtemp54, __Vtemp52, __Vtemp53);
    VL_EXTEND_WQ(65,64, __Vtemp55, ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_289)
                                     ? ((((QData)((IData)(
                                                          vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))) 
                                        - vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b)
                                     : (((QData)((IData)(
                                                         vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U])))));
    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[0U] 
            = __Vtemp54[0U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U] 
            = __Vtemp54[1U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[2U] 
            = (1U & __Vtemp54[2U]);
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[0U] 
            = __Vtemp55[0U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U] 
            = __Vtemp55[1U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[2U] 
            = (1U & __Vtemp55[2U]);
    }
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
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_71)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9425 
        = ((((((((((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9415 
                    | ((0x3beU == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_14
                        : 0ULL)) | ((0x3bfU == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_15
                                     : 0ULL)) | ((0xb03U 
                                                  == 
                                                  (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_0
                                                  : 0ULL)) 
                 | ((0xb04U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))
                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_1
                     : 0ULL)) | ((0xb05U == (0xfffU 
                                             & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))
                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_2
                                  : 0ULL)) | ((0xb06U 
                                               == (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_3
                                               : 0ULL)) 
              | ((0xb07U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))
                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_4
                  : 0ULL)) | ((0xb08U == (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_5
                               : 0ULL)) | ((0xb09U 
                                            == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_6
                                            : 0ULL)) 
           | ((0xb0aU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))
               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_7
               : 0ULL));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_219 
        = ((((((((((((((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_204) 
                         | (0xb0bU == (0xfffU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                         >> 0x14U))))) 
                        | (0xb0cU == (0xfffU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))) 
                       | (0xb0dU == (0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U))))) 
                      | (0xb0eU == (0xfffU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                      >> 0x14U))))) 
                     | (0xb0fU == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))) 
                    | (0xb10U == (0xfffU & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                    >> 0x14U))))) 
                   | (0xb11U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                   >> 0x14U))))) 
                  | (0xb12U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))) 
                 | (0xb13U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                 >> 0x14U))))) 
                | (0xb14U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                >> 0x14U))))) 
               | (0xb15U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))) 
              | (0xb16U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) 
             | (0xb17U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                             >> 0x14U))))) 
            | (0xb18U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))) 
           | (0xb19U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                           >> 0x14U)))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel 
        = ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((0x6003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 1U : ((3ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_442)))));
    if ((0x2023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))) {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_660 = 0U;
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_734 = 0U;
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_660 
            = ((0x23ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0U : ((0x1023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 0U : ((0x17ULL == (0x7fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x37ULL 
                                           == (0x7fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0xbU : 
                                          ((0x13ULL 
                                            == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                            ? 0U : 
                                           ((0x7013ULL 
                                             == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                             ? 5U : 
                                            ((0x6013ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                              ? 6U : 
                                             ((0x4013ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                               ? 7U
                                               : ((0x2013ULL 
                                                   == 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                   ? 8U
                                                   : 
                                                  ((0x3013ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 9U
                                                    : 
                                                   ((0x1013ULL 
                                                     == 
                                                     (0xfc00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 2U
                                                     : 
                                                    ((0x40005013ULL 
                                                      == 
                                                      (0xfc00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 4U
                                                      : 
                                                     ((0x5013ULL 
                                                       == 
                                                       (0xfc00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 3U
                                                       : 
                                                      ((0x1033ULL 
                                                        == 
                                                        (0xfe00707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 2U
                                                        : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_645)))))))))))))));
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_734 
            = ((0x23ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0U : ((0x1023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 0U : ((0x17ULL == (0x7fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x37ULL 
                                           == (0x7fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0U : (
                                                   (0x13ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_719)))))))))))))));
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_884 
        = ((0x5003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x3023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x2023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x23ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x1023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x17ULL != (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x37ULL != (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x13ULL != (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x7013ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x6013ULL != 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x4013ULL 
                                          != (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x2013ULL 
                                             != (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x3013ULL 
                                                != 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x1013ULL 
                                                   != 
                                                   (0xfc00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x40005013ULL 
                                                      != 
                                                      (0xfc00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x5013ULL 
                                                         != 
                                                         (0xfc00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x1033ULL 
                                                            != 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_867))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_364 
        = ((0x2023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x23ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x1023ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x17ULL == (0x7fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 1U : ((0x37ULL 
                                                == 
                                                (0x7fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x13ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_349))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1174 
        = ((0x37ULL == (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x13ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x7013ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x6013ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x4013ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x2013ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1159))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1255 
        = ((0x1003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x5003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x3023ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x2023ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x23ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x1023ULL != (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x17ULL != (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x37ULL != (0x7fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x13ULL != (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x7013ULL != 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x6013ULL 
                                          != (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x4013ULL 
                                             != (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x2013ULL 
                                                != 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x3013ULL 
                                                   != 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x1013ULL 
                                                      != 
                                                      (0xfc00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x40005013ULL 
                                                         != 
                                                         (0xfc00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x5013ULL 
                                                            != 
                                                            (0xfc00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1238))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_801 
        = ((0x6013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x4013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x2013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x3013ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x1013ULL == (0xfc00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x40005013ULL == (0xfc00707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x5013ULL == (0xfc00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x1033ULL == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x33ULL == (0xfe00707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x40000033ULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x2033ULL 
                                          == (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x3033ULL 
                                             == (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | ((0x7033ULL 
                                                == 
                                                (0xfe00707fULL 
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
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_784))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_494 
        = ((0x3033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x7033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x6033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x4033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x40005033ULL == (0xfe00707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x5033ULL == (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x1bULL == (0x707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x101bULL == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x501bULL == (0xfe00707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x4000501bULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x3bULL == 
                                          (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x4000003bULL 
                                             == (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | ((0x103bULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               | ((0x4000503bULL 
                                                   == 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  | ((0x503bULL 
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
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_477))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_568 
        = ((0x3033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x7033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x6033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x4033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x40005033ULL == (0xfe00707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x5033ULL == (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x1bULL != (0x707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x101bULL != (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x501bULL != (0xfe00707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x4000501bULL 
                                       != (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x3bULL == 
                                          (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x4000003bULL 
                                             == (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | ((0x103bULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               | ((0x4000503bULL 
                                                   == 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  | ((0x503bULL 
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
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_477))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt 
        = (((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_mtip) 
              & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_mtip)) 
             & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie)) 
            & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall))) 
           & (0ULL != vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[0U] 
        = (IData)((((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                    << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[1U] 
        = (IData)(((((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                     << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]))) 
                   >> 0x20U));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[2U] 
        = (IData)((((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U])) 
                    << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[0U]))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[3U] 
        = (IData)(((((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U])) 
                     << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[0U]))) 
                   >> 0x20U));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[0U] 
        = ((0xfffffffeU & ((IData)((((QData)((IData)(
                                                     vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])))) 
                           << 1U)) | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_289));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[1U] 
        = ((1U & ((IData)((((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])))) 
                  >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                       ((((QData)((IData)(
                                                                          vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]))) 
                                                        >> 0x20U)) 
                                               << 1U)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[2U] 
        = ((0xfffffffeU & ((IData)((0x7fffffffffffffffULL 
                                    & (((QData)((IData)(
                                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[0U]))))) 
                           << 1U)) | (1U & ((IData)(
                                                    ((((QData)((IData)(
                                                                       vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]))) 
                                                     >> 0x20U)) 
                                            >> 0x1fU)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[3U] 
        = ((1U & ((IData)((0x7fffffffffffffffULL & 
                           (((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U])) 
                             << 0x20U) | (QData)((IData)(
                                                         vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[0U]))))) 
                  >> 0x1fU)) | (0xfffffffeU & ((IData)(
                                                       ((0x7fffffffffffffffULL 
                                                         & (((QData)((IData)(
                                                                             vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U])) 
                                                             << 0x20U) 
                                                            | (QData)((IData)(
                                                                              vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[0U])))) 
                                                        >> 0x20U)) 
                                               << 1U)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151 
        = (((QData)((IData)(((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res 
                                            >> 0x1fU)))
                              ? 0xffffffffU : 0U))) 
            << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9435 
        = ((((((((((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9425 
                    | ((0xb0bU == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_8
                        : 0ULL)) | ((0xb0cU == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_9
                                     : 0ULL)) | ((0xb0dU 
                                                  == 
                                                  (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_10
                                                  : 0ULL)) 
                 | ((0xb0eU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))
                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_11
                     : 0ULL)) | ((0xb0fU == (0xfffU 
                                             & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))
                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_12
                                  : 0ULL)) | ((0xb10U 
                                               == (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_13
                                               : 0ULL)) 
              | ((0xb11U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))
                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_14
                  : 0ULL)) | ((0xb12U == (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_15
                               : 0ULL)) | ((0xb13U 
                                            == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_16
                                            : 0ULL)) 
           | ((0xb14U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))
               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_17
               : 0ULL));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_234 
        = ((((((((((((((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_219) 
                         | (0xb1aU == (0xfffU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                         >> 0x14U))))) 
                        | (0xb1bU == (0xfffU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))) 
                       | (0xb1cU == (0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U))))) 
                      | (0xb1dU == (0xfffU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                      >> 0x14U))))) 
                     | (0xb1eU == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))) 
                    | (0xb1fU == (0xfffU & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                    >> 0x14U))))) 
                   | (0x323U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                   >> 0x14U))))) 
                  | (0x324U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))) 
                 | (0x325U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                 >> 0x14U))))) 
                | (0x326U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                >> 0x14U))))) 
               | (0x327U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))) 
              | (0x328U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) 
             | (0x329U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                             >> 0x14U))))) 
            | (0x32aU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))) 
           | (0x32bU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                           >> 0x14U)))));
    if ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))) {
        vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel = 0U;
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7 = 0U;
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel 
            = ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0U : ((0x6003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 0U : ((3ULL == (0x707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x4003ULL 
                                           == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0U : (
                                                   (0x1003ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x5003ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x3023ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_364))))))));
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7 
            = ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0U : ((0x6003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 0U : ((3ULL == (0x707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x4003ULL 
                                           == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0U : (
                                                   (0x1003ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x5003ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0U
                                                     : 
                                                    ((0x3023ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : 
                                                     ((0x2023ULL 
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
                                                          ? 0U
                                                          : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1174))))))))))));
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8 
        = ((0x3003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x2003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x6003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((3ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x4003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1255))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_511 
        = ((0x23ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x1023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x17ULL != (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x37ULL != (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x13ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x7013ULL == (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x6013ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x4013ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x2013ULL == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x3013ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x1013ULL 
                                          == (0xfc00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x40005013ULL 
                                             == (0xfc00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | ((0x5013ULL 
                                                == 
                                                (0xfc00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               | ((0x1033ULL 
                                                   == 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  | ((0x33ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     | ((0x40000033ULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        | ((0x2033ULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_494))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_585 
        = ((0x23ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x1023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x17ULL != (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x37ULL != (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x13ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x7013ULL != (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x6013ULL != (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x4013ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x2013ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x3013ULL != 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x1013ULL 
                                          != (0xfc00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x40005013ULL 
                                             != (0xfc00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x5013ULL 
                                                != 
                                                (0xfc00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x1033ULL 
                                                   == 
                                                   (0xfe00707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  | ((0x33ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     | ((0x40000033ULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        | ((0x2033ULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_568))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall)
            ? 3U : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt)
                     ? 3U : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret)
                              ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp)
                              : 3U)));
    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[0U] 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[0U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[1U] 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[1U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[2U] 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[2U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[3U] 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[3U];
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[0U] 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[0U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[1U] 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[1U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[2U] 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[2U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[3U] 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[3U];
    }
    if ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))) {
        vlTOPp->io_coreIO_data_readIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151;
        vlTOPp->io_coreIO_data_writeIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151;
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151;
    } else {
        vlTOPp->io_coreIO_data_readIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res;
        vlTOPp->io_coreIO_data_writeIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res;
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res;
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9445 
        = ((((((((((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9435 
                    | ((0xb15U == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_18
                        : 0ULL)) | ((0xb16U == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_19
                                     : 0ULL)) | ((0xb17U 
                                                  == 
                                                  (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_20
                                                  : 0ULL)) 
                 | ((0xb18U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))
                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_21
                     : 0ULL)) | ((0xb19U == (0xfffU 
                                             & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))
                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_22
                                  : 0ULL)) | ((0xb1aU 
                                               == (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_23
                                               : 0ULL)) 
              | ((0xb1bU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))
                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_24
                  : 0ULL)) | ((0xb1cU == (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_25
                               : 0ULL)) | ((0xb1dU 
                                            == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_26
                                            : 0ULL)) 
           | ((0xb1eU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))
               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_27
               : 0ULL));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_249 
        = ((((((((((((((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_234) 
                         | (0x32cU == (0xfffU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                         >> 0x14U))))) 
                        | (0x32dU == (0xfffU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))) 
                       | (0x32eU == (0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U))))) 
                      | (0x32fU == (0xfffU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                      >> 0x14U))))) 
                     | (0x330U == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))) 
                    | (0x331U == (0xfffU & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                    >> 0x14U))))) 
                   | (0x332U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                   >> 0x14U))))) 
                  | (0x333U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))) 
                 | (0x334U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                 >> 0x14U))))) 
                | (0x335U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                >> 0x14U))))) 
               | (0x336U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))) 
              | (0x337U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) 
             | (0x338U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                             >> 0x14U))))) 
            | (0x339U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))) 
           | (0x33aU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                           >> 0x14U)))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1295 
        = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7)) 
           & (5U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_if_kill 
        = (((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
            | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8)) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1289));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1311 
        = (((((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load) 
              & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr) 
                 == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                      >> 0xfU))))) 
             & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr))) 
            & ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
               & ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                  | ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                     | ((0x6003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                        | ((3ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                           | ((0x4003ULL == (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                              | ((0x1003ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                 | ((0x5003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                    | ((0x3023ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                       | ((0x2023ULL 
                                           == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                          | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_511)))))))))))) 
           | ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load) 
                & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr) 
                   == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                        >> 0x14U))))) 
               & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr))) 
              & ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                 & ((0x3003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x2003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x6003ULL != (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((3ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x4003ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x1003ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x5003ULL != 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x3023ULL 
                                          == (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x2023ULL 
                                             == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_585)))))))))))));
    vlTOPp->io_coreIO_data_writeIO_mask = (0xffU & 
                                           ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ) 
                                            << (7U 
                                                & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_79)
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out
            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_83)
                ? ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                    ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                        : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                            ? (QData)((IData)((0xffU 
                                               & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                            : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_184
                                : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                    ? (QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                    : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_194
                                        : ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                            ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)
                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_87)
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9455 
        = ((((((((((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9445 
                    | ((0xb1fU == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_28
                        : 0ULL)) | ((0x323U == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_0
                                     : 0ULL)) | ((0x324U 
                                                  == 
                                                  (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_1
                                                  : 0ULL)) 
                 | ((0x325U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))
                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_2
                     : 0ULL)) | ((0x326U == (0xfffU 
                                             & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))
                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_3
                                  : 0ULL)) | ((0x327U 
                                               == (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_4
                                               : 0ULL)) 
              | ((0x328U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))
                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_5
                  : 0ULL)) | ((0x329U == (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_6
                               : 0ULL)) | ((0x32aU 
                                            == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_7
                                            : 0ULL)) 
           | ((0x32bU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))
               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_8
               : 0ULL));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_legal 
        = ((((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_249) 
               | (0x33bU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))) 
              | (0x33cU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) 
             | (0x33dU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                             >> 0x14U))))) 
            | (0x33eU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))) 
           | (0x33fU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                           >> 0x14U)))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1311) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9465 
        = ((((((((((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9455 
                    | ((0x32cU == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_9
                        : 0ULL)) | ((0x32dU == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_10
                                     : 0ULL)) | ((0x32eU 
                                                  == 
                                                  (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_11
                                                  : 0ULL)) 
                 | ((0x32fU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))
                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_12
                     : 0ULL)) | ((0x330U == (0xfffU 
                                             & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))
                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_13
                                  : 0ULL)) | ((0x331U 
                                               == (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_14
                                               : 0ULL)) 
              | ((0x332U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))
                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_15
                  : 0ULL)) | ((0x333U == (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_16
                               : 0ULL)) | ((0x334U 
                                            == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_17
                                            : 0ULL)) 
           | ((0x335U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))
               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_18
               : 0ULL));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen 
        = ((((~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__write_illegal)) 
             & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_legal)) 
            & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall))) 
           & (((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op)) 
               & (5U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op))) 
              & (1U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__read_illegal 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_256) 
           & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_legal)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4 
        = (1U & ((~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)) 
                 & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9475 
        = ((((((((((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9465 
                    | ((0x336U == (0xfffU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                     >> 0x14U))))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_19
                        : 0ULL)) | ((0x337U == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_20
                                     : 0ULL)) | ((0x338U 
                                                  == 
                                                  (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_21
                                                  : 0ULL)) 
                 | ((0x339U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))
                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_22
                     : 0ULL)) | ((0x33aU == (0xfffU 
                                             & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x14U))))
                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_23
                                  : 0ULL)) | ((0x33bU 
                                               == (0xfffU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                              >> 0x14U))))
                                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_24
                                               : 0ULL)) 
              | ((0x33cU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                               >> 0x14U))))
                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_25
                  : 0ULL)) | ((0x33dU == (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))
                               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_26
                               : 0ULL)) | ((0x33eU 
                                            == (0xfffU 
                                                & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x14U))))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_27
                                            : 0ULL)) 
           | ((0x33fU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                            >> 0x14U))))
               ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_28
               : 0ULL));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__read_illegal) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__write_illegal));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_256) 
           & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__read_illegal)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_244 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr)
            ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie)
            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall)
                ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie)
                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak)
                    ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie)
                    : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception 
        = (((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) 
            | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall)) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable)
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9475
            : 0ULL);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir 
        = (((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception) 
            | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt)) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9479 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data 
           | vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9482 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data 
           & (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140 
        = (((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) 
            & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall))) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
        = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
            : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9479
                : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9482
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data)));
    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_92 
            = (1U & ((0x300U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                   >> 0x14U))))
                      ? (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
                                 >> 7U)) : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie)));
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_99 
            = ((0x341U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                             >> 0x14U))))
                ? (0xfffffffffffffffcULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data)
                : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc);
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_92 
            = (1U & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie));
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_99 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc;
    }
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
    io_coreIO_inst_readIO_addr = VL_RAND_RESET_Q(64);
    io_coreIO_inst_readIO_data = VL_RAND_RESET_Q(64);
    io_coreIO_inst_readIO_en = VL_RAND_RESET_I(1);
    io_coreIO_data_readIO_addr = VL_RAND_RESET_Q(64);
    io_coreIO_data_readIO_data = VL_RAND_RESET_Q(64);
    io_coreIO_data_readIO_en = VL_RAND_RESET_I(1);
    io_coreIO_data_writeIO_addr = VL_RAND_RESET_Q(64);
    io_coreIO_data_writeIO_data = VL_RAND_RESET_Q(64);
    io_coreIO_data_writeIO_en = VL_RAND_RESET_I(1);
    io_coreIO_data_writeIO_mask = VL_RAND_RESET_I(8);
    simTop__DOT__mycore__DOT__cpath_io_ctl_if_kill = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_264 = VL_RAND_RESET_I(4);
    simTop__DOT__mycore__DOT__cpath__DOT___T_279 = VL_RAND_RESET_I(4);
    simTop__DOT__mycore__DOT__cpath__DOT___T_294 = VL_RAND_RESET_I(4);
    simTop__DOT__mycore__DOT__cpath__DOT___T_319 = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT___T_334 = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT___T_349 = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT___T_364 = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT___T_412 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_427 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_442 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_470 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_471 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_477 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_494 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_511 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_568 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_585 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_615 = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__cpath__DOT___T_630 = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__cpath__DOT___T_645 = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__cpath__DOT___T_660 = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__cpath__DOT___T_689 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_704 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_719 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_734 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_784 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_801 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_833 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_850 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_867 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_884 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_963 = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1129 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1144 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1159 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1174 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT__cs0_7 = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1204 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1221 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1238 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1255 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT__cs0_8 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1285 = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1289 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1311 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT__stall = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1295 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__cpath__DOT___T_1313 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir = VL_RAND_RESET_I(1);
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
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ = VL_RAND_RESET_I(8);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_csr_cmd = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_4 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT___T_79 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_83 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_87 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_174 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT___T_184 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT___T_194 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT___T_151 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT___T_103 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_109 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_115 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_140 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT___T_159 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<32; ++__Vi0) {
            simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[__Vi0] = VL_RAND_RESET_Q(64);
    }}
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_20 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_71 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_a = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_b = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op = VL_RAND_RESET_I(5);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt = VL_RAND_RESET_I(7);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt = VL_RAND_RESET_I(7);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_15 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_36 = VL_RAND_RESET_I(32);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_90 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_106 = VL_RAND_RESET_I(32);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_divsw = VL_RAND_RESET_I(32);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_remsw = VL_RAND_RESET_I(32);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_stall_req = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_186 = VL_RAND_RESET_I(7);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_289 = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(65, simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val);
    VL_RAND_RESET_W(128, simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214);
    VL_RAND_RESET_W(128, simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300);
    VL_RAND_RESET_W(128, simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_194 = VL_RAND_RESET_I(7);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_261 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_268 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_405 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtvec = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_mtip = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_msip = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_mtip = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_msip = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mscratch = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg0 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg1 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_0 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_1 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_2 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_3 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_4 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_5 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_6 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_7 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_8 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_9 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_10 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_11 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_12 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_13 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_14 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_15 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcycle = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_minstret = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_0 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_1 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_2 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_3 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_4 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_5 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_6 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_7 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_8 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_9 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_10 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_11 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_12 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_13 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_14 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_15 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_16 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_17 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_18 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_19 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_20 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_21 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_22 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_23 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_24 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_25 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_26 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_27 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_28 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcounterinhibit = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_0 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_1 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_2 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_3 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_4 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_5 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_6 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_7 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_8 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_9 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_10 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_11 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_12 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_13 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_14 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_15 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_16 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_17 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_18 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_19 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_20 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_21 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_22 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_23 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_24 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_25 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_26 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_27 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_28 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op = VL_RAND_RESET_I(3);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__write_illegal = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_174 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_189 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_204 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_219 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_234 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_249 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_legal = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_256 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__read_illegal = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9395 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9405 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9415 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9425 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9435 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9445 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9455 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9465 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9475 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9479 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9482 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_92 = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_99 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_17729 = VL_RAND_RESET_Q(64);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt = VL_RAND_RESET_I(1);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now = VL_RAND_RESET_I(2);
    simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_244 = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
