// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsimTop.h for the primary calling header

#include "VsimTop.h"
#include "VsimTop__Syms.h"

//==========

void VsimTop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VsimTop::eval\n"); );
    VsimTop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("simTop.v", 1715, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VsimTop::_eval_initial_loop(VsimTop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("simTop.v", 1715, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VsimTop::_sequent__TOP__2(VsimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_sequent__TOP__2\n"); );
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdlyvdim0__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    CData/*0:0*/ __Vdlyvset__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    WData/*127:0*/ __Vtemp2[4];
    WData/*127:0*/ __Vtemp3[4];
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_133;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_134;
    QData/*63:0*/ __Vdlyvval__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    // Body
    __Vdlyvset__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0 = 0U;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_134 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_134;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_133 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_133;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load 
        = ((~ (IData)(vlTOPp->reset)) & (((0x2003ULL 
                                           == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                          | ((3ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                             | ((0x4003ULL 
                                                 == 
                                                 (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                | ((0x1003ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                   | ((0x5003ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                      | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_429)))))) 
                                         & (~ ((0x2003ULL 
                                                != 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((3ULL 
                                                   != 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x4003ULL 
                                                      != 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x1003ULL 
                                                         != 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x5003ULL 
                                                            != 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_429)))))))));
    if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
        if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
            vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr = 0U;
        }
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr 
            = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))
                ? 0U : (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                         >> 7U))));
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type 
                = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))
                    ? 0U : ((0x2003ULL == (0x707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                             ? 0U : ((3ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                      ? 0U : ((0x4003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                               ? 0U
                                               : ((0x1003ULL 
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
                                                      : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_139)))))))));
        }
    }
    if (((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen) 
         & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr)))) {
        __Vdlyvval__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata;
        __Vdlyvset__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0 = 1U;
        __Vdlyvdim0__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr;
    }
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_133 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_134 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"EXE: alu_op=[%x] alu_out=[%x] \n",
                   4,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"EXE: pc=[%x] inst=[%x] \n",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"MEM: pc=[%x] inst=[%x] wb_sel=[%1#] wbdata=[%x]\n",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst,
                   2,(IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel),
                   64,((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                        : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                            : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                ? vlTOPp->io_coreIO_data_read_io_data
                                : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out))));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"WB : pc=[%x] inst=[%x]\n",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_133,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_134);
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_data 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data;
    if (vlTOPp->reset) {
        __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc = 0x7ffffffcULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc 
                = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4
                    : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))
                        ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
                           + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                        : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))
                            ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                               + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                            : 0x4033ULL)));
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_133 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_133;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_134 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_134;
    vlTOPp->io_diffTestIO_valid = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid));
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun 
            = ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 0U : ((3ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                         ? 0U : ((0x4003ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                  ? 0U : ((0x1003ULL 
                                           == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                           ? 0U : (
                                                   (0x5003ULL 
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
                                                        : 
                                                       ((0x37ULL 
                                                         == 
                                                         (0x7fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0xbU
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
                                                           ? 5U
                                                           : 
                                                          ((0x6013ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 6U
                                                            : 
                                                           ((0x4013ULL 
                                                             == 
                                                             (0x707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 7U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_312)))))))))))))));
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst = 0x4033ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst 
                = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))
                    ? 0x4033ULL : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst);
        }
    }
    vlTOPp->io_coreIO_data_write_io_data = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_data;
    if (vlTOPp->reset) {
        __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc = 0ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc;
        }
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
            = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                ? (QData)((IData)((0x1fU & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                    >> 0xfU)))))
                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc
                    : (((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr) 
                          == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                               >> 0xfU)))) 
                         & (0U != (0x1fU & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                    >> 0xfU))))) 
                        & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res
                        : (((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr) 
                              == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                   >> 0xfU)))) 
                             & (0U != (0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0xfU))))) 
                            & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen))
                            ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                                : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                                    : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                        ? vlTOPp->io_coreIO_data_read_io_data
                                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)))
                            : (((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr) 
                                  == (0x1fU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0xfU)))) 
                                 & (0U != (0x1fU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0xfU))))) 
                                & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                                : ((0U != (0x1fU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0xfU))))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [(0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0xfU)))]
                                    : 0ULL))))));
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
            = (((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_79) 
                & (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel)))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res
                : (((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_85) 
                    & (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel)))
                    ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                        : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                            : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                ? vlTOPp->io_coreIO_data_read_io_data
                                : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)))
                    : (((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_91) 
                        & (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel)))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                        : ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data
                            : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                ? ((((1U & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                    >> 0x1fU)))
                                      ? 0xfffffffffffffULL
                                      : 0ULL) << 0xcU) 
                                   | (QData)((IData)(
                                                     (0xfffU 
                                                      & (IData)(
                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                 >> 0x14U))))))
                                : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                    ? ((((1U & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0x1fU)))
                                          ? 0xfffffffffffffULL
                                          : 0ULL) << 0xcU) 
                                       | (QData)((IData)(
                                                         ((0xfe0U 
                                                           & ((IData)(
                                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                       >> 0x19U)) 
                                                              << 5U)) 
                                                          | (0x1fU 
                                                             & (IData)(
                                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                        >> 7U)))))))
                                    : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                        ? ((((1U & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0x1fU)))
                                              ? 0x7ffffffffffffULL
                                              : 0ULL) 
                                            << 0xdU) 
                                           | (QData)((IData)(
                                                             ((0x1000U 
                                                               & ((IData)(
                                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                           >> 0x1fU)) 
                                                                  << 0xcU)) 
                                                              | ((0x800U 
                                                                  & ((IData)(
                                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                              >> 7U)) 
                                                                     << 0xbU)) 
                                                                 | ((0x7e0U 
                                                                     & ((IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 0x19U)) 
                                                                        << 5U)) 
                                                                    | (0x1eU 
                                                                       & ((IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 8U)) 
                                                                          << 1U))))))))
                                        : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                            ? (((QData)((IData)(
                                                                ((1U 
                                                                  & (IData)(
                                                                            (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                             >> 0x1fU)))
                                                                  ? 0xffffffffU
                                                                  : 0U))) 
                                                << 0x20U) 
                                               | (QData)((IData)(
                                                                 (0xfffff000U 
                                                                  & ((IData)(
                                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                              >> 0xcU)) 
                                                                     << 0xcU)))))
                                            : ((5U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                                ? (
                                                   (((1U 
                                                      & (IData)(
                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                 >> 0x1fU)))
                                                      ? 0x7ffffffffffULL
                                                      : 0ULL) 
                                                    << 0x15U) 
                                                   | (QData)((IData)(
                                                                     ((0x100000U 
                                                                       & ((IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 0x1fU)) 
                                                                          << 0x14U)) 
                                                                      | ((0xff000U 
                                                                          & ((IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 0xcU)) 
                                                                             << 0xcU)) 
                                                                         | ((0x800U 
                                                                             & ((IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 0x14U)) 
                                                                                << 0xbU)) 
                                                                            | (0x7feU 
                                                                               & ((IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 0x15U)) 
                                                                                << 1U))))))))
                                                : 0ULL)))))))));
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data 
            = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_79)
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res
                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_85)
                    ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                        : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                            : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                ? vlTOPp->io_coreIO_data_read_io_data
                                : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)))
                    : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_91)
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data)));
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata 
        = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
            : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                    ? vlTOPp->io_coreIO_data_read_io_data
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)));
    if (__Vdlyvset__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[__Vdlyvdim0__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0] 
            = __Vdlyvval__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid 
                = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                   & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc = 0ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc 
                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
        }
    }
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out 
        = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
            ? (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)
            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    VL_EXTEND_WQ(127,64, __Vtemp2, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1);
    VL_SHIFTL_WWI(127,127,6, __Vtemp3, __Vtemp2, (0x3fU 
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
                                                            __Vtemp3[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             __Vtemp3[0U])))
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
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid 
                = (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel));
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4 
        = (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc);
    vlTOPp->io_coreIO_data_read_io_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out;
    vlTOPp->io_coreIO_data_write_io_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out;
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel 
            = ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_361));
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr 
            = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))
                ? 0U : (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                         >> 7U))));
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen 
                = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                   & ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                      | ((3ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                         | ((0x4003ULL == (0x707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                            | ((0x1003ULL == (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                               | ((0x5003ULL == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                  | ((0x2023ULL != 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     & ((0x23ULL != 
                                         (0x707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        & ((0x1023ULL 
                                            != (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           & ((0x17ULL 
                                               == (0x7fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                              | ((0x37ULL 
                                                  == 
                                                  (0x7fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                 | ((0x13ULL 
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
                                                          | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_385)))))))))))))));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst = 0x4033ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))
                    ? 0x4033ULL : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_inst);
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel 
        = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
            ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_603));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_inst 
        = vlTOPp->io_coreIO_inst_read_io_data;
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

void VsimTop::_eval(VsimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_eval\n"); );
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

VL_INLINE_OPT QData VsimTop::_change_request(VsimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_change_request\n"); );
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData VsimTop::_change_request_1(VsimTop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_change_request_1\n"); );
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VsimTop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsimTop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
