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
            VL_FATAL_MT("simTop.v", 5201, "",
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
            VL_FATAL_MT("simTop.v", 5201, "",
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
    CData/*0:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie;
    WData/*127:0*/ __Vtemp5[4];
    WData/*127:0*/ __Vtemp11[4];
    WData/*127:0*/ __Vtemp15[4];
    WData/*127:0*/ __Vtemp16[4];
    WData/*127:0*/ __Vtemp18[4];
    WData/*127:0*/ __Vtemp19[4];
    WData/*127:0*/ __Vtemp20[4];
    WData/*127:0*/ __Vtemp23[4];
    WData/*127:0*/ __Vtemp24[4];
    WData/*127:0*/ __Vtemp25[4];
    WData/*95:0*/ __Vtemp28[3];
    WData/*95:0*/ __Vtemp29[3];
    WData/*95:0*/ __Vtemp30[3];
    WData/*95:0*/ __Vtemp31[3];
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
    QData/*63:0*/ __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_210;
    QData/*63:0*/ __Vdlyvval__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    // Body
    __Vdlyvset__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0 = 0U;
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
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"CTRL : inst = %x, cs_alu_fun = %2#, ifkill = %1#, deckill = %1#, stall = %1#\n",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst,
                   5,((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                       ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_667)),
                   1,((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1288) 
                      | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1289)),
                   1,(0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)),
                   1,(IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall));
    }
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_210 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_210;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"ALU: op = %2#, src1=[%x] src2=[%x] shamt=[%x] result=[%x]\n",
                   5,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset,
                   6,(0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)),
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res);
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
            if (vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) {
                vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr = 0U;
            }
        } else {
            vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr 
                = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
                   & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1295));
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt 
                    = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req)
                        ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_186)
                        : 0U);
            }
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1313 
        = ((0x3003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x2003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x6003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((3ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x4003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x1003ULL != (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x5003ULL != (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x3023ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x2023ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x23ULL != (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x1023ULL 
                                          != (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x17ULL 
                                             != (0x7fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x37ULL 
                                                != 
                                                (0x7fULL 
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
                                                                          & ((0x1033ULL 
                                                                              != 
                                                                              (0xfe00707fULL 
                                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                             & ((0x33ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x40000033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x2033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x3033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x7033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x6033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x4033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x40005033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x5033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x1bULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x101bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
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
                                                                                & ((0x4000503bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x503bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x6fULL 
                                                                                != 
                                                                                (0x7fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x67ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x63ULL 
                                                                                != 
                                                                                (0x707fULL 
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
                                                                                & ((0x2000033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x200003bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
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
                                                                                & ((0x2005033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x200403bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x200603bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x200703bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x2006033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x2007033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x5073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x6073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x1073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x2073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x3073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x7073ULL 
                                                                                != 
                                                                                (0x707fULL 
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
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
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
                                                         | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_884))))))) 
                                         & (1U == (
                                                   (0x3003ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 1U
                                                    : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_963)))));
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ = 0xffU;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140)))) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
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
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type = 0U;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
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
                                                    : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_294))))));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U] = 0U;
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U] = 0U;
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U] = 0U;
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U] = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult) {
                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req) {
                    VL_EXTEND_WQ(128,64, __Vtemp5, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b);
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_stall_req) {
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U] 
                            = ((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[1U] 
                                << 0x1fU) | (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[0U] 
                                             >> 1U));
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U] 
                            = ((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[2U] 
                                << 0x1fU) | (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[1U] 
                                             >> 1U));
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U] 
                            = ((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[3U] 
                                << 0x1fU) | (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[2U] 
                                             >> 1U));
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U] 
                            = ((0x80000000U & (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[2U] 
                                               << 0x1fU)) 
                               | (0x7fffffffU & (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[3U] 
                                                 >> 1U)));
                    } else {
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U] 
                            = __Vtemp5[0U];
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U] 
                            = __Vtemp5[1U];
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U] 
                            = __Vtemp5[2U];
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U] 
                            = __Vtemp5[3U];
                    }
                }
            } else {
                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req) {
                    VL_EXTEND_WQ(127,64, __Vtemp11, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a);
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_stall_req) {
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U] 
                            = ((0x40U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt))
                                ? (IData)((((QData)((IData)(
                                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[0U]))))
                                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[0U]
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[0U]));
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U] 
                            = ((0x40U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt))
                                ? (IData)(((((QData)((IData)(
                                                             vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[0U]))) 
                                           >> 0x20U))
                                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[1U]
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[1U]));
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U] 
                            = ((0x40U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt))
                                ? (IData)((((QData)((IData)(
                                                            (1U 
                                                             & (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U] 
                                                                >> 0x1fU)))) 
                                            << 0x3fU) 
                                           | (0x7fffffffffffffffULL 
                                              & (((QData)((IData)(
                                                                  vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[3U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[2U])) 
                                                    >> 1U)))))
                                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[2U]
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[2U]));
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U] 
                            = ((0x40U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt))
                                ? (IData)(((((QData)((IData)(
                                                             (1U 
                                                              & (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U] 
                                                                 >> 0x1fU)))) 
                                             << 0x3fU) 
                                            | (0x7fffffffffffffffULL 
                                               & (((QData)((IData)(
                                                                   vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[3U])) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result[2U])) 
                                                     >> 1U)))) 
                                           >> 0x20U))
                                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_214[3U]
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_300[3U]));
                    } else {
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U] 
                            = (0xfffffffeU & (__Vtemp11[0U] 
                                              << 1U));
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U] 
                            = ((1U & (__Vtemp11[0U] 
                                      >> 0x1fU)) | 
                               (0xfffffffeU & (__Vtemp11[1U] 
                                               << 1U)));
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U] 
                            = ((1U & (__Vtemp11[1U] 
                                      >> 0x1fU)) | 
                               (0xfffffffeU & (__Vtemp11[2U] 
                                               << 1U)));
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U] 
                            = ((1U & (__Vtemp11[2U] 
                                      >> 0x1fU)) | 
                               (0xfffffffeU & (__Vtemp11[3U] 
                                               << 1U)));
                    }
                }
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
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op 
                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun;
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcycle 
        = ((IData)(vlTOPp->reset) ? 0ULL : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_17729);
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall)))) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt) {
                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall) {
                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                } else {
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt) {
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                    } else {
                        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret)))) {
                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                        }
                    }
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret)))) {
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception) {
                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall) {
                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                                } else {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt) {
                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                                    } else {
                                        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret)))) {
                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                                        }
                                    }
                                }
                            } else {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall) {
                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                                    } else {
                                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt) {
                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                                        } else {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret)))) {
                                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                                            }
                                        }
                                    }
                                } else {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall) {
                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                                        } else {
                                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt) {
                                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                                            } else {
                                                if (
                                                    (1U 
                                                     & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret)))) {
                                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp = 3U;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp 
                                        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now;
                                } else {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp 
                                            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now;
                                    } else {
                                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp 
                                                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now;
                                        }
                                    }
                                }
                            } else {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp 
                                            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now;
                                    } else {
                                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp 
                                                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now;
                                        } else {
                                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp 
                                                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_26 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x33dU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_26 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_24 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x33bU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_24 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_28 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x33fU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_28 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_27 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x33eU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_27 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_23 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x33aU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_23 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_19 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x336U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_19 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_20 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x337U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_20 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_21 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x338U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_21 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_22 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x339U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_22 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_25 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x33cU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_25 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_14 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x331U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_14 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_13 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x330U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_13 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_12 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x32fU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_12 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_11 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x32eU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_11 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_9 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x32cU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_9 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_18 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x335U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_18 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_16 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x333U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_16 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_15 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x332U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_15 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_10 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x32dU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_10 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_17 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x334U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_17 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_8 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x32bU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_8 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_6 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x329U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_6 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_5 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x328U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_5 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_4 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x327U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_4 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_3 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x326U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_3 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_2 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x325U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_2 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_1 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x324U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_1 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_0 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x323U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_0 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_28 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb1fU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_28 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_7 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x32aU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_7 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_27 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb1eU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_27 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_26 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb1dU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_26 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_20 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb17U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_20 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_18 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb15U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_18 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_24 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb1bU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_24 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_25 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb1cU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_25 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_23 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb1aU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_23 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_19 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb16U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_19 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_21 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb18U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_21 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_22 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb19U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_22 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_15 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb12U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_15 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_13 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb10U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_13 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_8 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb0bU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_8 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_9 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb0cU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_9 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_10 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb0dU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_10 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_11 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb0eU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_11 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_12 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb0fU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_12 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_14 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb11U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_14 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_16 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb13U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_16 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_17 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb14U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_17 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_0 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb03U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_0 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_1 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb04U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_1 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_3 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb06U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_3 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_4 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb07U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_4 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_5 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb08U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_5 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_6 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb09U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_6 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_14 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3beU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_14 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_15 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3bfU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_15 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_2 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb05U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_2 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_7 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb0aU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_7 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_11 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3bbU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_11 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_8 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b8U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_8 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_5 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b5U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_5 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_6 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b6U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_6 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_4 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b4U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_4 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_7 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b7U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_7 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_9 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b9U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_9 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_10 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3baU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_10 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_12 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3bcU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_12 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_13 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3bdU == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_13 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcounterinhibit = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x320U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcounterinhibit 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_2 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b2U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_2 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_1 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b1U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_1 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_0 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b0U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_0 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg1 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3a1U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg1 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg0 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3a0U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg0 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_3 = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x3b3U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_3 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_minstret = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0xb02U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_minstret 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval = 0ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall)))) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
            } else {
                if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret)))) {
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception) {
                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval 
                                = (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst));
                        } else {
                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval 
                                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
                            } else {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval 
                                        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_msip = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x304U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_msip 
                    = (1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
                                     >> 3U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_msip = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x344U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_msip 
                    = (1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
                                     >> 3U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mscratch = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x340U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mscratch 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_mtip = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x304U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_mtip 
                    = (1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
                                     >> 7U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_mtip = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x344U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_mtip 
                    = (1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
                                     >> 7U)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_99;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt) {
                if (((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret) 
                     | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception))) {
                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
                } else {
                    if ((0ULL != vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)) {
                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
                    } else {
                        if ((0ULL != vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc)) {
                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc;
                        } else {
                            if ((0ULL != vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)) {
                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
                            } else {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                                    if ((0x341U == 
                                         (0xfffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))) {
                                        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                                            = (0xfffffffffffffffcULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data);
                                    }
                                }
                            }
                        }
                    }
                }
            } else {
                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret) {
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                        if ((0x341U == (0xfffU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                          >> 0x14U))))) {
                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                                = (0xfffffffffffffffcULL 
                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data);
                        }
                    }
                } else {
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception) {
                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
                        } else {
                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
                            } else {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                                        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
                                } else {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                                        if ((0x341U 
                                             == (0xfffU 
                                                 & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))) {
                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                                                = (0xfffffffffffffffcULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data);
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                            if ((0x341U == (0xfffU 
                                            & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U))))) {
                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc 
                                    = (0xfffffffffffffffcULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data);
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtvec = 0x8000c09cULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
            if ((0x305U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                              >> 0x14U))))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtvec 
                    = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                        : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9479
                            : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9482
                                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable)
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9475
                                    : 0ULL))));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                if ((0x342U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))) {
                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause 
                        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data;
                }
            }
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause = 0x8000000000000007ULL;
            } else {
                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret) {
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                        if ((0x342U == (0xfffU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                          >> 0x14U))))) {
                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause 
                                = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                                    : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9479
                                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9482
                                            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable)
                                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9475
                                                : 0ULL))));
                        }
                    }
                } else {
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception) {
                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause = 2ULL;
                        } else {
                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause = 0xbULL;
                            } else {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause = 3ULL;
                                } else {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                                        if ((0x342U 
                                             == (0xfffU 
                                                 & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))) {
                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause 
                                                = (
                                                   (2U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                                                    : 
                                                   ((4U 
                                                     == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9479
                                                     : 
                                                    ((3U 
                                                      == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9482
                                                      : 
                                                     ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable)
                                                       ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9475
                                                       : 0ULL))));
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                            if ((0x342U == (0xfffU 
                                            & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U))))) {
                                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause 
                                    = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                                        : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9479
                                            : ((3U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9482
                                                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable)
                                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9475
                                                    : 0ULL))));
                            }
                        }
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_b = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_b 
                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset;
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_a = 0ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_a 
                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1;
        }
    }
    if (vlTOPp->reset) {
        __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                if ((0x300U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))) {
                    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie 
                        = (1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
                                         >> 3U)));
                }
            }
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt) {
                __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
            } else {
                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret) {
                    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie 
                        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie;
                } else {
                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception) {
                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                                __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
                            } else {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
                                } else {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                        __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
                                    }
                                }
                            }
                        } else {
                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                                    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
                                } else {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                        __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
                                    } else {
                                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                            __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
                                        }
                                    }
                                }
                            } else {
                                if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr) {
                                        __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
                                    } else {
                                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall) {
                                            __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
                                        } else {
                                            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak) {
                                                __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie = 0U;
                                            }
                                        }
                                    }
                                } else {
                                    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                                        if ((0x300U 
                                             == (0xfffU 
                                                 & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                            >> 0x14U))))) {
                                            __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie 
                                                = (1U 
                                                   & (IData)(
                                                             (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
                                                              >> 3U)));
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                            if ((0x300U == (0xfffU 
                                            & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U))))) {
                                __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie 
                                    = (1U & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
                                                     >> 3U)));
                            }
                        }
                    }
                }
            }
        }
    }
    if (__Vdlyvset__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[__Vdlyvdim0__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0] 
            = __Vdlyvval__simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile__v0;
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1289 
        = ((0x3003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x2003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x6003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((3ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x4003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & ((0x1003ULL != (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                          & ((0x5003ULL != (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                             & ((0x3023ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                & ((0x2023ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x23ULL != (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x1023ULL 
                                          != (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x17ULL 
                                             != (0x7fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x37ULL 
                                                != 
                                                (0x7fULL 
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
                                                                          & ((0x1033ULL 
                                                                              != 
                                                                              (0xfe00707fULL 
                                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                             & ((0x33ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x40000033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x2033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x3033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x7033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x6033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x4033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x40005033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x5033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x1bULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x101bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
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
                                                                                & ((0x4000503bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x503bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x6fULL 
                                                                                != 
                                                                                (0x7fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x67ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x63ULL 
                                                                                != 
                                                                                (0x707fULL 
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
                                                                                & ((0x2000033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x200003bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
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
                                                                                & ((0x2005033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x200403bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x200603bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x200703bULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x2006033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x2007033ULL 
                                                                                != 
                                                                                (0xfe00707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x5073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x6073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x1073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x2073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x3073ULL 
                                                                                != 
                                                                                (0x707fULL 
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                                & ((0x7073ULL 
                                                                                != 
                                                                                (0x707fULL 
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
                                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_186 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_stall_req 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req));
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start) {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)))) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt 
                    = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req)
                        ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_194)
                        : 0U);
            }
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_268 
        = (((QData)((IData)(((0x80000000U & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])
                              ? 0xffffffffU : 0U))) 
            << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])));
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140)))) {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun 
                = ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                    ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_667));
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_17729 
        = (1ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcycle);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd 
        = ((IData)(vlTOPp->reset) ? 0U : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159)
                                           ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_csr_cmd)));
    if (vlTOPp->reset) {
        __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc = 0ULL;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140)))) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
                __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc;
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140)))) {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                    ? (QData)((IData)((0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0xfU)))))
                    : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc
                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                            ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data))
                            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_79)
                                ? ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)
                                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_83)
                                    ? ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                        ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                                            : ((1U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                ? (QData)((IData)(
                                                                  (0xffU 
                                                                   & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                                : (
                                                   (2U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_184
                                                    : 
                                                   ((3U 
                                                     == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                     ? (QData)((IData)(
                                                                       (0xffffU 
                                                                        & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                                     : 
                                                    ((4U 
                                                      == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_194
                                                      : 
                                                     ((5U 
                                                       == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                       ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                                       : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
                                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)
                                    : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_87)
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data))))));
        }
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140)))) {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_105)
                    ? ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151
                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)
                    : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_111)
                        ? ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                            ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                    ? (QData)((IData)(
                                                      (0xffU 
                                                       & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_184
                                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                            ? (QData)((IData)(
                                                              (0xffffU 
                                                               & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                            : ((4U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_194
                                                : (
                                                   (5U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
                            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)
                        : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_117)
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
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140)))) {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data 
                = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_103)
                    ? ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151
                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)
                    : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_109)
                        ? ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                            ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                    ? (QData)((IData)(
                                                      (0xffU 
                                                       & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_184
                                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                            ? (QData)((IData)(
                                                              (0xffffU 
                                                               & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                            : ((4U 
                                                == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_194
                                                : (
                                                   (5U 
                                                    == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
                            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)
                        : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_115)
                            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data)));
        }
    }
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & ((~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159)) 
                                         & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid)));
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159)))) {
        __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    }
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159)
            ? 0x4033ULL : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst);
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid 
        = ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid));
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_210 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"IF : pc=[%x] inst=[%x] if_pc_next=[%x] pc_sel=[%1#] e_bj_pc=[%x]\n",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc,
                   64,vlTOPp->io_coreIO_inst_readIO_data,
                   64,((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_22)
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc
                        : ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                            ? (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)
                            : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target
                                : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out
                                    : 0x4033ULL)))),
                   2,(IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel),
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
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir)))) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc 
                    = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc;
            }
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
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid = 0U;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid 
                    = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
                       & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst = 0x4033ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst = 0x4033ULL;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
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
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_210,
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata,
                   5,(IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"store:addr = [%x] en=%1# data = [%x] mask = %b\n ",
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_addr,
                   1,(2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn)),
                   64,vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_data,
                   8,(0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_235)));
    }
    if (VL_UNLIKELY((1U & (~ (IData)(vlTOPp->reset))))) {
        VL_FWRITEF(0x80000002U,"pc=[%x]\n",64,vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc);
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata 
        = ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
            ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                    ? (QData)((IData)((0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_184
                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                            ? (QData)((IData)((0xffffU 
                                               & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                            : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_194
                                : ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out);
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall) {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen) {
                if ((0x300U == (0xfffU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                  >> 0x14U))))) {
                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie 
                        = (1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
                                         >> 7U)));
                }
            }
        } else {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie 
                = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt)
                    ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie)
                    : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret) 
                       | ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception)
                           ? ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr)
                               ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_244)
                               : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall)
                                   ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_244)
                                   : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak)
                                       ? (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_244)
                                       : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_92))))
                           : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___GEN_92))));
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_210 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT___T_210;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_194 
        = (0x7fU & ((IData)(1U) + (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen 
        = ((~ (IData)(vlTOPp->reset)) & ((~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159)) 
                                         & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult 
        = (((((0xdU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)) 
              | (0x12U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
             | (0x13U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
            | (0x14U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) 
           | (0x19U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)));
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
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_csr_cmd = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_csr_cmd = 0U;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_csr_cmd 
                    = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                        ? 0U : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1295)
                                 ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7)));
            }
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_256 
        = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd)) 
           & (5U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd)));
    vlTOPp->io_diffTestIO_valid = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid;
    vlTOPp->io_diffTestIO_pc = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc;
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid = 0U;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid 
                    = (1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_if_kill)));
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc = 0x80000000ULL;
    } else {
        if (((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) 
             | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir))) {
            if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_22)))) {
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
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data 
        = ((IData)(vlTOPp->reset) ? 0ULL : vlTOPp->io_coreIO_data_readIO_data);
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_90 
        = ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                          >> 0x3fU))) ? (1ULL + (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_106 
        = ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                          >> 0x1fU))) ? ((IData)(1U) 
                                         + (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
            : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset));
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
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn = 0U;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn 
                    = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                        ? 0U : ((0x3003ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                 ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_963)));
            }
        }
    }
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159)))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel;
    }
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid = 0U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159)))) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid 
                = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid;
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr 
        = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr;
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159)))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out 
            = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                ? (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)
                : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res));
    }
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op 
        = ((((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd)) 
             | (4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))) 
            & (0U == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                       >> 0xfU)))))
            ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd));
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_20) 
           | (0x18U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_20) 
           | (0x18U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
           + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset);
    vlTOPp->io_coreIO_data_writeIO_data = vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_data;
    if ((0x10U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b 
            = (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset));
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a 
            = (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1));
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b 
            = ((0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
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
                                                      : (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))))))))))))));
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a 
            = ((0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
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
                                                      : (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1))))))))))))));
    }
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
        = __Vdly__simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__write_illegal 
        = ((((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op)) 
             | (3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op))) 
            | (4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op))) 
           & (3U == (3U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                   >> 0x1eU)))));
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
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen = 0U;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
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
                                                                    | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_801)))))))))))))))));
            }
        }
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
            ? ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start) 
               & ((0x41U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt)) 
                  | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_261)))
            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start) 
               & ((0x41U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt)) 
                  | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_261))));
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_289 
        = ((((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
             << 0x20U) | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))) 
           >= vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b);
    VL_EXTEND_WQ(127,64, __Vtemp15, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1);
    VL_SHIFTL_WWI(127,127,6, __Vtemp16, __Vtemp15, 
                  (0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)));
    __Vtemp18[0U] = 1U;
    __Vtemp18[1U] = 0U;
    __Vtemp18[2U] = 0U;
    __Vtemp18[3U] = 0U;
    __Vtemp19[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
    __Vtemp19[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
    __Vtemp19[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
    __Vtemp19[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
    VL_ADD_W(4, __Vtemp20, __Vtemp18, __Vtemp19);
    __Vtemp23[0U] = 1U;
    __Vtemp23[1U] = 0U;
    __Vtemp23[2U] = 0U;
    __Vtemp23[3U] = 0U;
    __Vtemp24[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
    __Vtemp24[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
    __Vtemp24[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
    __Vtemp24[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
    VL_ADD_W(4, __Vtemp25, __Vtemp23, __Vtemp24);
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_74 
        = ((7U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
            ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
               ^ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
            : ((8U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                ? (QData)((IData)(VL_LTS_IQQ(1,64,64, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                : ((9U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                    ? (QData)((IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                       < vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                        ? (((QData)((IData)(__Vtemp16[1U])) 
                            << 0x20U) | (QData)((IData)(
                                                        __Vtemp16[0U])))
                        : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                            ? VL_SHIFTRS_QQI(64,64,6, vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1, 
                                             (0x3fU 
                                              & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                            : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                   >> (0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
                                : ((0x1aU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                    ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                       >> (0x1fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)))
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
                                                                          __Vtemp20[3U]
                                                                           : 
                                                                          vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]))) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          ((1U 
                                                                            & (IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                                                >> 0x3fU)))
                                                                            ? 
                                                                           __Vtemp20[2U]
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
                                                                           __Vtemp25[3U]))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153)
                                                                             ? 
                                                                            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]
                                                                             : 
                                                                            __Vtemp25[2U]))))
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
    vlTOPp->io_coreIO_data_readIO_en = (1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn));
    vlTOPp->io_coreIO_data_writeIO_en = (2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn));
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid = 0U;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
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
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159)))) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr;
    }
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target 
        = (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
           + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset);
    if ((1U & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140)))) {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
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
                                                    : 
                                                   ((0x5003ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 1U
                                                     : 
                                                    ((0x3023ULL 
                                                      == 
                                                      (0x707fULL 
                                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                      ? 0U
                                                      : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_734)))))))));
        }
    }
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu) 
           & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata 
        = ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
            ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                    ? (QData)((IData)((0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                    : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_184
                        : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                            ? (QData)((IData)((0xffffU 
                                               & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                            : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_194
                                : ((5U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out);
    VL_EXTEND_WQ(65,64, __Vtemp28, ((1U & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a
                                     : 0ULL));
    VL_EXTEND_WQ(65,64, __Vtemp29, (((QData)((IData)(
                                                     vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))));
    VL_ADD_W(3, __Vtemp30, __Vtemp28, __Vtemp29);
    VL_EXTEND_WQ(65,64, __Vtemp31, ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_289)
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
            = __Vtemp30[0U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U] 
            = __Vtemp30[1U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[2U] 
            = (1U & __Vtemp30[2U]);
    } else {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[0U] 
            = __Vtemp31[0U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[1U] 
            = __Vtemp31[1U];
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val[2U] 
            = (1U & __Vtemp31[2U]);
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
                    : ((6U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                        ? (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                           | vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)
                        : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT___T_74))));
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
    if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr = 0U;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr 
                = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                    ? 0U : (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                             >> 7U))));
        }
    }
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
        vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_addr 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151;
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151;
    } else {
        vlTOPp->io_coreIO_data_readIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res;
        vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_addr 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res;
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out 
            = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res;
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel 
        = ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type))
            ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1285));
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
    vlTOPp->io_coreIO_data_writeIO_addr = vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_addr;
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_235 
        = (0x7fffU & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ) 
                      << (7U & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out))));
    if (vlTOPp->reset) {
        vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst = 0x4033ULL;
    } else {
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir) {
            vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst = 0x4033ULL;
        } else {
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4) {
                vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                    = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_if_kill)
                        ? 0x4033ULL : vlTOPp->io_coreIO_inst_readIO_data);
            }
        }
    }
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
    vlTOPp->io_coreIO_data_writeIO_mask = (0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_235));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_689 
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
                                                             : 0U)))))))))))))));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_615 
        = ((0x2003033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0x14U : ((0x2004033ULL == (0xfe00707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                        ? 0xeU : ((0x200503bULL == 
                                   (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                   ? 0x11U : ((0x2005033ULL 
                                               == (0xfe00707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                               ? 0x15U
                                               : ((0x200403bULL 
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_279 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_264))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_79)
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out
            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_83)
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata
                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_87)
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_704 
        = ((0x103bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 4U : ((0x4000503bULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 4U : ((0x503bULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 4U : ((0x6fULL == (0x7fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 2U : ((0x67ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 2U
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_689))))))))))))))));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_630 
        = ((0x103bULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 2U : ((0x4000503bULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0xcU : ((0x503bULL == (0xfe00707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                ? 0x1aU : ((0x6fULL 
                                            == (0x7fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                            ? 0U : 
                                           ((0x67ULL 
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
                                                          : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_615))))))))))))))));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_427 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_412))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_471 
        = ((0x2000033ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_470));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_294 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_279))))))))))))))));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_719 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_704))))))))))))))));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_645 
        = ((0x33ULL == (0xfe00707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x40000033ULL == (0xfe00707fULL 
                                       & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((0x2033ULL == (0xfe00707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 8U : ((0x3033ULL == 
                                       (0xfe00707fULL 
                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 9U : ((0x7033ULL 
                                                == 
                                                (0xfe00707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 5U
                                                : (
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_630))))))))))))))));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_442 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_427))))))))))))))));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_734 
        = ((0x2023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x23ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x1023ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x17ULL == (0x7fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x37ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_719))))))))))))))));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_660 
        = ((0x2023ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x23ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((0x1023ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x17ULL == (0x7fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x37ULL 
                                                == 
                                                (0x7fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0xbU
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
                                                       : 
                                                      ((0x2013ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_645))))))))))))))));
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel 
        = ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 1U : ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 1U : ((0x6003ULL == (0x707fULL 
                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 1U : ((3ULL == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_442)))));
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
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_159 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data 
        = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
            : ((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9479
                : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd))
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT___T_9482
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_667 
        = ((0x2003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
            ? 0U : ((0x6003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                     ? 0U : ((3ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                              ? 0U : ((0x4003ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                       ? 0U : ((0x1003ULL 
                                                == 
                                                (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                ? 0U
                                                : (
                                                   (0x5003ULL 
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
                                                     : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_660))))))));
    if ((0x3003ULL == (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))) {
        vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7 = 0U;
        vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel = 0U;
    } else {
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
    }
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8 
        = ((0x3003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
           & ((0x2003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
              & ((0x6003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                 & ((3ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                    & ((0x4003ULL != (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                       & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1255))))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_105 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_103) 
           & (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_111 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_109) 
           & (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_117 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_115) 
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1295 
        = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7)) 
           & (5U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7)));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_op1_data 
        = ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
            ? (QData)((IData)((0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                >> 0xfU)))))
            : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc
                : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                    ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data))
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1288 
        = ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_op2_data 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_105)
            ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out
            : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_111)
                ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata
                : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_117)
                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_alu_op2)));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1311 
        = (((((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load) 
              & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr) 
                 == (0x1fU & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                      >> 0xfU))))) 
             & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr))) 
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
              & ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
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
    vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_if_kill 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1288) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1289));
    vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall 
        = ((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1311) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_4 
        = (1U & ((~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall)) 
                 & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall))));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_140 
        = (((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall) 
            & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall))) 
           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir));
    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_22 
        = ((((((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8) 
               | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1313)) 
              & (0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))) 
             & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall))) 
            & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall))) 
           & (~ (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir)));
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
