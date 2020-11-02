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
            VL_FATAL_MT("simTop.v", 2385, "",
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
            VL_FATAL_MT("simTop.v", 2385, "",
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
    CData/*0:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid;
    CData/*0:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    CData/*4:0*/ __Vdlyvdim0__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    CData/*0:0*/ __Vdlyvset__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    WData/*127:0*/ __Vtemp1[4];
    WData/*127:0*/ __Vtemp2[4];
    WData/*127:0*/ __Vtemp3[4];
    WData/*127:0*/ __Vtemp4[4];
    WData/*127:0*/ __Vtemp5[4];
    WData/*127:0*/ __Vtemp6[4];
    WData/*95:0*/ __Vtemp9[3];
    WData/*159:0*/ __Vtemp10[5];
    WData/*159:0*/ __Vtemp11[5];
    WData/*95:0*/ __Vtemp13[3];
    WData/*159:0*/ __Vtemp14[5];
    WData/*159:0*/ __Vtemp15[5];
    WData/*159:0*/ __Vtemp16[5];
    WData/*127:0*/ __Vtemp19[4];
    WData/*127:0*/ __Vtemp20[4];
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_inst;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_181;
    QData/*63:0*/ __Vdlyvval__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    // Body
    __Vdlyvset__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0 = 0U;
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"CTRL : inst = %x, ifkill = %1#, deckill = %1#, stall = %1#\n",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst,
                   1,(0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)),
                   1,(0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)),
                   1,(IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"ALU: op = %2#, src1=[%x] src2=[%x] result=[%x]\n",
                   5,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"RF: rdata1(%2#)=[%x] rdata2(%2#)=[%x] wdata(%2#)=[%x] wen=%1#\n",
                   5,(0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                       >> 0xfU))),64,
                   vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data,
                   5,(0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                       >> 0xfU))),64,
                   vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data,
                   5,(IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr),
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata,
                   1,(IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
    }
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_181 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_181;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_inst 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_inst;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1;
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load 
        = ((~ (IData)(vlTOPp->reset)) & (((0x3003ULL 
                                           == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                          | ((0x2003ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                             | ((0x6003ULL 
                                                 == 
                                                 (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                | ((3ULL 
                                                    == 
                                                    (0x707fULL 
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
                                                            | ((0x3023ULL 
                                                                == 
                                                                (0x707fULL 
                                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                               | ((0x2023ULL 
                                                                   == 
                                                                   (0x707fULL 
                                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                  | ((0x23ULL 
                                                                      == 
                                                                      (0x707fULL 
                                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                     | (0x1023ULL 
                                                                        == 
                                                                        (0x707fULL 
                                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)))))))))))) 
                                         & (1U == (
                                                   (0x3003ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 1U
                                                    : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_794)))));
    if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
        if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
            vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr = 0U;
        }
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr 
            = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                ? 0U : (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                         >> 7U))));
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type 
                    = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                        ? 0U : ((0x3003ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                 ? 0U : ((0x2003ULL 
                                          == (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                          ? 0U : ((0x6003ULL 
                                                   == 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                   ? 0U
                                                   : 
                                                  ((3ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_242))))));
            }
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
    if (vlTOPp->reset) {
        __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc = 0ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
                __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc;
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                    ? (QData)((IData)((0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0xfU)))))
                    : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc
                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                            ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data))
                            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_60)
                                ? ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_125
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)
                                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_64)
                                    ? ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                        ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_145
                                            : ((1U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                ? (QData)((IData)(
                                                                  (0xffU 
                                                                   & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                                : (
                                                   (2U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_155
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                     ? (QData)((IData)(
                                                                       (0xffffU 
                                                                        & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_165
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                       ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                                       : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
                                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)
                                    : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_68)
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data))))));
        }
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_86)
                    ? ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_125
                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)
                    : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_92)
                        ? ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                            ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_145
                                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                    ? (QData)((IData)(
                                                      (0xffU 
                                                       & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_155
                                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                            ? (QData)((IData)(
                                                              (0xffffU 
                                                               & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                            : ((4U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_165
                                                : (
                                                   (5U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
                            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)
                        : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_98)
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                            : ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data
                                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_itype_sext
                                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_stype_sext
                                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_sbtype_sext
                                            : ((4U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_utype_sext
                                                : (
                                                   (5U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_ujtype_sext
                                                    : 0ULL)))))))));
        }
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data 
                = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_84)
                    ? ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_125
                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)
                    : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_90)
                        ? ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                            ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_145
                                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                    ? (QData)((IData)(
                                                      (0xffU 
                                                       & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_155
                                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                            ? (QData)((IData)(
                                                              (0xffffU 
                                                               & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                            : ((4U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_165
                                                : (
                                                   (5U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
                            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)
                        : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_96)
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data)));
        }
    }
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid));
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid));
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_inst 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_181 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"IF : pc=[%x] inst=[%x] if_pc_next=[%x] pc_sel=[%1#] e_bj_pc=[%x]\n",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc,
                   64,vlTOPp->io_coreIO_inst_readIO_data,
                   64,((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                        ? (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)
                        : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target
                            : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out
                                : 0x4033ULL))),2,(IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel),
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"DEC: valid = %1# pc=[%x] inst=[%x] op1=[%x] alu2=[%x] op2=[%x]\n",
                   1,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_op1_data,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_alu_op2,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_op2_data);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"EXE: valid = %1# pc=[%x] inst=[%x] bj_target = [%x]\n",
                   1,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target);
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"MEM read data = [%x]\n",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data);
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc = 0ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc 
                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
        }
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"MEM: valid = %1# pc=[%x] inst=[%x] wb_sel=[%1#] wbdata=[%x]\n",
                   1,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst,
                   3,(IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel),
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata);
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid 
                    = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
                       & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst = 0x4033ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst = 0x4033ULL;
        } else {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst 
                    = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                        ? 0x4033ULL : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst);
            }
        }
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"WB : valid = %1# pc=[%x] inst=[%x], mem_wbdata=[%x], mem_reg_wbaddr=[%2#]\n",
                   1,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_181,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata,
                   5,(IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"store: mem_typ=[%x] offset=[%x]\n",
                   8,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ,
                   3,(7U & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out)));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"store:addr = [%x] en=%1# data = [%x] mask = %b\n ",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out,
                   1,(2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn)),
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_data,
                   8,(0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_206)));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"pc=[%x] W[r%2#=%x][%1#] Op1=[r%2#][%x] Op2=[r%2#][%x] inst=[%x]\n\n",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc,
                   5,(IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr),
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata,
                   1,(IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen),
                   5,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_214,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_215,
                   5,(IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_216),
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_217,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_inst);
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata 
        = ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
            ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_145
                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                    ? (QData)((IData)((0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_155
                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                            ? (QData)((IData)((0xffffU 
                                               & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                            : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_165
                                : ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out);
    if (__Vdlyvset__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[__Vdlyvdim0__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0] 
            = __Vdlyvval__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun 
                = ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                    ? 0U : ((0x2003ULL == (0x707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                             ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_549)));
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_inst 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_inst;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_181 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_181;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
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
    vlTOPp->io_diffTestIO_valid = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    vlTOPp->io_diffTestIO_pc = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid 
                = (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc = 0x80000000ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc 
                = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4
                    : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target
                        : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out
                            : 0x4033ULL)));
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data 
        = ((IData)(vlTOPp->reset) ? 0ULL : vlTOPp->io_coreIO_data_readIO_data);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_214 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs1_addr;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_216 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_addr;
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn 
                    = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                        ? 0U : ((0x3003ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                 ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_794)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ = 0xffU;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
                if ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))) {
                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ 
                        = ((0x3003ULL == (0x707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                            ? 0xffU : ((0x2003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 0xffU : (
                                                   (0x6003ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0xffU
                                                    : 
                                                   ((3ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0xffU
                                                     : 
                                                    ((0x4003ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0xffU
                                                      : 
                                                     ((0x1003ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0xffU
                                                       : 
                                                      ((0x5003ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0xffU
                                                        : 
                                                       ((0x3023ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0xffU
                                                         : 
                                                        ((0x2023ULL 
                                                          == 
                                                          (0x707fULL 
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                          ? 0xfU
                                                          : 
                                                         ((0x23ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 1U
                                                           : 
                                                          ((0x1023ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 3U
                                                            : 0xffU)))))))))));
                }
            }
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid 
        = ((IData)(vlTOPp->reset) ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out 
        = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
            ? (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)
            : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_125
                : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_217 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_op2_data;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_215 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_op1_data;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    vlTOPp->io_coreIO_inst_readIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_pc_plus4 
        = (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_145 
        = ((((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data 
                            >> 7U))) ? 0xffffffffffffffULL
              : 0ULL) << 8U) | (QData)((IData)((0xffU 
                                                & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data)))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_155 
        = ((((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data 
                            >> 0xfU))) ? 0xffffffffffffULL
              : 0ULL) << 0x10U) | (QData)((IData)((0xffffU 
                                                   & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data)))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_165 
        = (((QData)((IData)(((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data 
                                            >> 0x1fU)))
                              ? 0xffffffffU : 0U))) 
            << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs1_addr 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs1_addr;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_addr 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_addr;
    vlTOPp->io_coreIO_data_readIO_en = (1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn));
    vlTOPp->io_coreIO_data_writeIO_en = (2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn));
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_data 
        = ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
            ? (((QData)((IData)(((0xff000000U & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                 << 0x18U)) 
                                 | ((0xff0000U & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                  << 0x10U)) 
                                    | ((0xff00U & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                   << 8U)) 
                                       | (0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data))))))) 
                << 0x20U) | (QData)((IData)(((0xff000000U 
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
            : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
                ? (((QData)((IData)(((0xffff0000U & 
                                      ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                       << 0x10U)) | 
                                     (0xffffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data))))) 
                    << 0x20U) | (QData)((IData)(((0xffff0000U 
                                                  & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data) 
                                                     << 0x10U)) 
                                                 | (0xffffU 
                                                    & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data))))))
                : ((0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
                    ? (((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)) 
                        << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)))
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)));
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid 
                    = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                        ? 0U : ((0x3003ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                 ? 6U : ((0x2003ULL 
                                          == (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                          ? 4U : ((0x6003ULL 
                                                   == 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                   ? 5U
                                                   : 
                                                  ((3ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0U
                                                    : 
                                                   ((0x4003ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 1U
                                                     : 
                                                    ((0x1003ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 2U
                                                      : 
                                                     ((0x5003ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 3U
                                                       : 0U))))))));
            }
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel 
                = ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                    ? 1U : ((0x2003ULL == (0x707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                             ? 1U : ((0x6003ULL == 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                      ? 1U : ((3ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                               ? 1U
                                               : ((0x4003ULL 
                                                   == 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                   ? 1U
                                                   : 
                                                  ((0x1003ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 1U
                                                    : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_606)))))));
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_op2_data 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_op1_data 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata 
        = ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
            ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_145
                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                    ? (QData)((IData)((0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_155
                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                            ? (QData)((IData)((0xffffU 
                                               & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                            : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_165
                                : ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out);
    vlTOPp->io_coreIO_data_writeIO_data = vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_data;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1;
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs1_addr 
                = (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                    >> 0xfU)));
        }
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_addr 
                = (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                    >> 0x14U)));
        }
    }
    if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr 
                = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                    ? 0U : (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                             >> 7U))));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen = 0U;
        } else {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen 
                    = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
                       & ((0x3003ULL == (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x2003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x6003ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((3ULL == (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x4003ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x1003ULL 
                                          == (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x5003ULL 
                                             == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | ((0x3023ULL 
                                                != 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                               & ((0x2023ULL 
                                                   != 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                  & ((0x23ULL 
                                                      != 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                     & ((0x1023ULL 
                                                         != 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        & ((0x17ULL 
                                                            == 
                                                            (0x7fULL 
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
                                                                    | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_658)))))))))))))))));
            }
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
           + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
           + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset);
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
           == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data);
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt 
        = VL_LTS_IQQ(1,64,64, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data);
    vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
           < vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_65 
        = ((0ULL == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
            ? 0U : VL_DIV_III(32, (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1), (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)));
    VL_EXTEND_WQ(128,64, __Vtemp1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1);
    VL_EXTEND_WQ(128,64, __Vtemp2, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset);
    VL_MUL_W(4, __Vtemp3, __Vtemp1, __Vtemp2);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_39[0U] 
        = __Vtemp3[0U];
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_39[1U] 
        = __Vtemp3[1U];
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_39[2U] 
        = __Vtemp3[2U];
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_39[3U] 
        = __Vtemp3[3U];
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_44 
        = ((0ULL == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
            ? 0ULL : VL_DIV_QQQ(64, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1064 
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
    VL_EXTENDS_WQ(128,64, __Vtemp4, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1);
    VL_EXTENDS_WQ(128,64, __Vtemp5, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset);
    VL_MULS_WWW(128,128,128, __Vtemp6, __Vtemp4, __Vtemp5);
    __Vtemp9[0U] = (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1);
    __Vtemp9[1U] = (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                            >> 0x20U));
    __Vtemp9[2U] = (1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                  >> 0x3fU)));
    VL_EXTENDS_WW(129,65, __Vtemp10, __Vtemp9);
    __Vtemp11[0U] = __Vtemp10[0U];
    __Vtemp11[1U] = __Vtemp10[1U];
    __Vtemp11[2U] = __Vtemp10[2U];
    __Vtemp11[3U] = __Vtemp10[3U];
    __Vtemp11[4U] = (1U & __Vtemp10[4U]);
    VL_EXTEND_WQ(65,64, __Vtemp13, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset);
    VL_EXTENDS_WW(129,65, __Vtemp14, __Vtemp13);
    __Vtemp15[0U] = __Vtemp14[0U];
    __Vtemp15[1U] = __Vtemp14[1U];
    __Vtemp15[2U] = __Vtemp14[2U];
    __Vtemp15[3U] = __Vtemp14[3U];
    __Vtemp15[4U] = (1U & __Vtemp14[4U]);
    VL_MULS_WWW(129,129,129, __Vtemp16, __Vtemp11, __Vtemp15);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_111 
        = ((0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
            ? (QData)((IData)(((0ULL == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                                ? 0U : VL_MODDIVS_III(32, (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1), (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))))
            : ((0x10U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                ? (QData)((IData)(((0ULL == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                                    ? 0U : VL_MODDIV_III(32, (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1), (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))))
                : ((0x11U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_65))
                    : ((0x12U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                        ? (((QData)((IData)(__Vtemp6[3U])) 
                            << 0x20U) | (QData)((IData)(
                                                        __Vtemp6[2U])))
                        : ((0x13U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                            ? (((QData)((IData)(__Vtemp16[3U])) 
                                << 0x20U) | (QData)((IData)(
                                                            __Vtemp16[2U])))
                            : ((0x14U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                ? (((QData)((IData)(
                                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_39[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_39[2U])))
                                : ((0x15U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_44
                                    : ((0x16U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                        ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_65))
                                        : ((0x17U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                            ? ((0ULL 
                                                == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                                                ? 0ULL
                                                : VL_MODDIVS_QQQ(64, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
                                            : ((0x18U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                ? (
                                                   (0ULL 
                                                    == vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                                                    ? 0ULL
                                                    : 
                                                   VL_MODDIV_QQQ(64, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
                                                : 0ULL))))))))));
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst = 0x4033ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                    ? 0x4033ULL : vlTOPp->io_coreIO_inst_readIO_data);
        }
    }
    VL_EXTEND_WQ(127,64, __Vtemp19, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1);
    VL_SHIFTL_WWI(127,127,6, __Vtemp20, __Vtemp19, 
                  (0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_123 
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
                            ? (((QData)((IData)(__Vtemp20[1U])) 
                                << 0x20U) | (QData)((IData)(
                                                            __Vtemp20[0U])))
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
                                                : (
                                                   (0xdU 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                    ? 
                                                   (((QData)((IData)(
                                                                     vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_39[1U])) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_39[0U])))
                                                    : 
                                                   ((0xeU 
                                                     == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_44
                                                     : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_111))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel 
        = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
            ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1064));
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
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_123)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_794 
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_212 
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_576 
        = ((0x3bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 4U : ((0x4000003bULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 4U : ((0x103bULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 4U : ((0x4000503bULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 4U : ((0x503bULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 4U
                                                : (
                                                   (0x6fULL 
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
                                                     : 
                                                    ((0x63ULL 
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
                                                             : 0U)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data 
        = ((0U != (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                    >> 0xfU)))) ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
           [(0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                              >> 0xfU)))] : 0ULL);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_60 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0xfU)))) & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (IData)(
                                                            (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                             >> 0xfU))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_64 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0xfU)))) & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (IData)(
                                                            (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                             >> 0xfU))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_68 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0xfU)))) & (0U 
                                                 != 
                                                 (0x1fU 
                                                  & (IData)(
                                                            (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                             >> 0xfU))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_84 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0x14U)))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                              >> 0x14U))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_90 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0x14U)))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                              >> 0x14U))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_96 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr) 
             == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                  >> 0x14U)))) & (0U 
                                                  != 
                                                  (0x1fU 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                              >> 0x14U))))) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_itype_sext 
        = ((((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                            >> 0x1fU))) ? 0xfffffffffffffULL
              : 0ULL) << 0xcU) | (QData)((IData)((0xfffU 
                                                  & (IData)(
                                                            (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                             >> 0x14U))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_stype_sext 
        = ((((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                            >> 0x1fU))) ? 0xfffffffffffffULL
              : 0ULL) << 0xcU) | (QData)((IData)(((0xfe0U 
                                                   & ((IData)(
                                                              (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                               >> 0x19U)) 
                                                      << 5U)) 
                                                  | (0x1fU 
                                                     & (IData)(
                                                               (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                >> 7U)))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_sbtype_sext 
        = ((((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                            >> 0x1fU))) ? 0x7ffffffffffffULL
              : 0ULL) << 0xdU) | (QData)((IData)(((0x1000U 
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
                                                              << 1U))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_utype_sext 
        = (((QData)((IData)(((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                            >> 0x1fU)))
                              ? 0xffffffffU : 0U))) 
            << 0x20U) | (QData)((IData)((0xfffff000U 
                                         & ((IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                     >> 0xcU)) 
                                            << 0xcU)))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_ujtype_sext 
        = ((((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                            >> 0x1fU))) ? 0x7ffffffffffULL
              : 0ULL) << 0x15U) | (QData)((IData)((
                                                   (0x100000U 
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
                                                               << 1U))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data 
        = ((0U != (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                    >> 0x14U)))) ? 
           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
           [(0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                              >> 0x14U)))] : 0ULL);
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_504 
        = ((0x4063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x6063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x2000033ULL == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0xdU : ((0x200003bULL 
                                         == (0xfe00707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                         ? 0xdU : (
                                                   (0x2001033ULL 
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
                                                     : 
                                                    ((0x2003033ULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0x14U
                                                      : 
                                                     ((0x2004033ULL 
                                                       == 
                                                       (0xfe00707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0xeU
                                                       : 
                                                      ((0x200503bULL 
                                                        == 
                                                        (0xfe00707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0x11U
                                                        : 
                                                       ((0x2005033ULL 
                                                         == 
                                                         (0xfe00707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                         ? 0x15U
                                                         : 
                                                        ((0x200403bULL 
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
                                                              : 0U)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_281 
        = ((0x3033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x7033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x6033ULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x4033ULL == 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x40005033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x5033ULL 
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
                                                          : 
                                                         ((0x103bULL 
                                                           == 
                                                           (0xfe00707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                           ? 3U
                                                           : 
                                                          ((0x4000503bULL 
                                                            == 
                                                            (0xfe00707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                            ? 3U
                                                            : 
                                                           ((0x503bULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 3U
                                                             : 0U)))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_136 
        = ((0x2000033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x200003bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x2001033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x2002033ULL == (0xfe00707fULL 
                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x2003033ULL == (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x2004033ULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | ((0x200503bULL == (0xfe00707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             | ((0x2005033ULL == (0xfe00707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                | ((0x200403bULL == 
                                    (0xfe00707fULL 
                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x200603bULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x200703bULL 
                                          == (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x2006033ULL 
                                             == (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            | (0x2007033ULL 
                                               == (0xfe00707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_334 
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_125 
        = (((QData)((IData)(((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res 
                                            >> 0x1fU)))
                              ? 0xffffffffU : 0U))) 
            << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_227 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_212))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_591 
        = ((0x5013ULL == (0xfc00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x1033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x33ULL == (0xfe00707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x40000033ULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x2033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x3033ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_576))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_519 
        = ((0x1bULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x101bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 2U : ((0x501bULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 3U : ((0x4000501bULL 
                                       == (0xfe00707fULL 
                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0xcU : ((0x3bULL 
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
                                                   : 
                                                  ((0x103bULL 
                                                    == 
                                                    (0xfe00707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 2U
                                                    : 
                                                   ((0x4000503bULL 
                                                     == 
                                                     (0xfe00707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 0xcU
                                                     : 
                                                    ((0x503bULL 
                                                      == 
                                                      (0xfe00707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 3U
                                                      : 
                                                     ((0x6fULL 
                                                       == 
                                                       (0x7fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : 
                                                      ((0x67ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                        ? 0U
                                                        : 
                                                       ((0x63ULL 
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
                                                            : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_504))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_296 
        = ((0x17ULL == (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x37ULL == (0x7fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x13ULL == (0x707fULL 
                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x7013ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x6013ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x4013ULL 
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
                                                            : 
                                                           ((0x2033ULL 
                                                             == 
                                                             (0xfe00707fULL 
                                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                             ? 0U
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_281))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_641 
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
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_136))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_142 
        = ((0x63ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | ((0x1063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              | ((0x5063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 | ((0x7063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    | ((0x4063ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       | ((0x6063ULL == (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_136)))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_349 
        = ((0x1013ULL == (0xfc00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x40005013ULL == (0xfc00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((0x5013ULL == (0xfc00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 1U : ((0x1033ULL == 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_334))))))))))))))));
    if ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))) {
        vlTOPp->io_coreIO_data_readIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_125;
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_125;
    } else {
        vlTOPp->io_coreIO_data_readIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res;
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res;
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_242 
        = ((0x4003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x1003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x5003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x3023ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x2023ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_227))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_606 
        = ((0x5003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x3023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x2023ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x23ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x1023ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x17ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_591))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_534 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_519))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel 
        = ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x6003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((3ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x4003ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
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
                                                         : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_296))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_658 
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
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_641))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_403 
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
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_142))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_464 
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
                                                           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_142))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_364 
        = ((0x4003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x1003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((0x5003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 1U : ((0x3023ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 2U : ((0x2023ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 2U
                                                : (
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_349))))))))))))))));
    vlTOPp->io_coreIO_data_writeIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_206 
        = (0x7fffU & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ) 
                      << (7U & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_60)
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out
            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_64)
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata
                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_68)
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_549 
        = ((0x6003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
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
                                                   (0x3023ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_534))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_420 
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
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_403))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_481 
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
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_464))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel 
        = ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((0x6003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 1U : ((3ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_364)))));
    vlTOPp->io_coreIO_data_writeIO_mask = (0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_206));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_op1_data 
        = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
            ? (QData)((IData)((0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                >> 0xfU)))))
            : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc
                : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data))
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1073 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load) 
             & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr) 
                == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                     >> 0xfU))))) & 
            (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr))) 
           & ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
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
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x2023ULL 
                                          == (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_420))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1078 
        = ((((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load) 
             & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr) 
                == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                     >> 0x14U))))) 
            & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr))) 
           & ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
              & ((0x3003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((0x2003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x6003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((3ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x4003ULL != (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x1003ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x5003ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x3023ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x2023ULL 
                                          == (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_481))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_86 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_84) 
           & (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_92 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_90) 
           & (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_98 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_96) 
           & (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_alu_op2 
        = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data
            : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_itype_sext
                : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_stype_sext
                    : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_sbtype_sext
                        : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_utype_sext
                            : ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_ujtype_sext
                                : 0ULL))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1073) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1078));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_op2_data 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_86)
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out
            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_92)
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata
                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_98)
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_alu_op2)));
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
