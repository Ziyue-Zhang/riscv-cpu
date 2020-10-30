// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VsimTop__Syms.h"


void VsimTop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    VsimTop__Syms* __restrict vlSymsp = static_cast<VsimTop__Syms*>(userp);
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void VsimTop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    VsimTop__Syms* __restrict vlSymsp = static_cast<VsimTop__Syms*>(userp);
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc),64);
            tracep->chgQData(oldp+2,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res),64);
            tracep->chgBit(oldp+4,((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn))));
            tracep->chgQData(oldp+5,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_data),64);
            tracep->chgBit(oldp+7,((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn))));
            tracep->chgCData(oldp+8,((0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_157))),8);
            tracep->chgBit(oldp+9,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid));
            tracep->chgQData(oldp+10,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0U]),64);
            tracep->chgQData(oldp+12,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [1U]),64);
            tracep->chgQData(oldp+14,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [2U]),64);
            tracep->chgQData(oldp+16,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [3U]),64);
            tracep->chgQData(oldp+18,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [4U]),64);
            tracep->chgQData(oldp+20,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [5U]),64);
            tracep->chgQData(oldp+22,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [6U]),64);
            tracep->chgQData(oldp+24,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [7U]),64);
            tracep->chgQData(oldp+26,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [8U]),64);
            tracep->chgQData(oldp+28,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [9U]),64);
            tracep->chgQData(oldp+30,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xaU]),64);
            tracep->chgQData(oldp+32,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xbU]),64);
            tracep->chgQData(oldp+34,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xcU]),64);
            tracep->chgQData(oldp+36,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xdU]),64);
            tracep->chgQData(oldp+38,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xeU]),64);
            tracep->chgQData(oldp+40,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xfU]),64);
            tracep->chgQData(oldp+42,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x10U]),64);
            tracep->chgQData(oldp+44,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x11U]),64);
            tracep->chgQData(oldp+46,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x12U]),64);
            tracep->chgQData(oldp+48,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x13U]),64);
            tracep->chgQData(oldp+50,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x14U]),64);
            tracep->chgQData(oldp+52,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x15U]),64);
            tracep->chgQData(oldp+54,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x16U]),64);
            tracep->chgQData(oldp+56,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x17U]),64);
            tracep->chgQData(oldp+58,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x18U]),64);
            tracep->chgQData(oldp+60,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x19U]),64);
            tracep->chgQData(oldp+62,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1aU]),64);
            tracep->chgQData(oldp+64,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1bU]),64);
            tracep->chgQData(oldp+66,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1cU]),64);
            tracep->chgQData(oldp+68,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1dU]),64);
            tracep->chgQData(oldp+70,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1eU]),64);
            tracep->chgQData(oldp+72,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1fU]),64);
            tracep->chgQData(oldp+74,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc),64);
            tracep->chgQData(oldp+76,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst),64);
            tracep->chgBit(oldp+78,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq));
            tracep->chgBit(oldp+79,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt));
            tracep->chgBit(oldp+80,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu));
            tracep->chgCData(oldp+81,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type),4);
            tracep->chgBit(oldp+82,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall));
            tracep->chgCData(oldp+83,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel),2);
            tracep->chgCData(oldp+84,(((0x2003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 0U : ((3ULL 
                                                 == 
                                                 (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                 ? 0U
                                                 : 
                                                ((0x4003ULL 
                                                  == 
                                                  (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                  ? 0U
                                                  : 
                                                 ((0x1003ULL 
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
                                                      : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_139))))))))),4);
            tracep->chgBit(oldp+85,((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))));
            tracep->chgCData(oldp+86,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel),2);
            tracep->chgCData(oldp+87,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel),3);
            tracep->chgCData(oldp+88,(((0x2003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 0U : ((3ULL 
                                                 == 
                                                 (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                 ? 0U
                                                 : 
                                                ((0x4003ULL 
                                                  == 
                                                  (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                  ? 0U
                                                  : 
                                                 ((0x1003ULL 
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
                                                             : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_312)))))))))))))))),4);
            tracep->chgCData(oldp+89,(((0x2003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_361))),2);
            tracep->chgBit(oldp+90,(((0x2003ULL == 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((3ULL == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        | ((0x4003ULL 
                                            == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           | ((0x1003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                              | ((0x5003ULL 
                                                  == 
                                                  (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                 | ((0x2023ULL 
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
                                                                      | ((0x6013ULL 
                                                                          == 
                                                                          (0x707fULL 
                                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                         | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_385))))))))))))))));
            tracep->chgCData(oldp+91,(((0x2003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_469))),2);
            tracep->chgCData(oldp+92,(((0x2003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 3U : ((3ULL 
                                                 == 
                                                 (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                 ? 1U
                                                 : 
                                                ((0x4003ULL 
                                                  == 
                                                  (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                  ? 5U
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
                                                    ? 6U
                                                    : 
                                                   ((0x2023ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                     ? 3U
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
                                                       ? 2U
                                                       : 0U))))))))),3);
            tracep->chgBit(oldp+93,(((0x2003ULL == 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((3ULL == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        | ((0x4003ULL 
                                            == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           | ((0x1003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                              | ((0x5003ULL 
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
                                                       | ((0x1023ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                          | ((0x17ULL 
                                                              != 
                                                              (0x7fULL 
                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                             & ((0x37ULL 
                                                                 != 
                                                                 (0x7fULL 
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
            tracep->chgBit(oldp+94,(((0x2003ULL != 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     & ((3ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        & ((0x4003ULL 
                                            != (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           & ((0x1003ULL 
                                               != (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                              & ((0x5003ULL 
                                                  != 
                                                  (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                 & ((0x2023ULL 
                                                     == 
                                                     (0x707fULL 
                                                      & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                    | ((0x23ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                       | ((0x1023ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                          | ((0x17ULL 
                                                              != 
                                                              (0x7fULL 
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
                                                                            & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_276)))))))))))))))));
            tracep->chgBit(oldp+95,(((0x2003ULL == 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((3ULL == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        | ((0x4003ULL 
                                            == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           | ((0x1003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                              | ((0x5003ULL 
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
                                                           & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)))))))))));
            tracep->chgCData(oldp+96,((0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0xfU)))),5);
            tracep->chgCData(oldp+97,((0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0x14U)))),5);
            tracep->chgCData(oldp+98,((0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 7U)))),5);
            tracep->chgBit(oldp+99,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
                                     & ((0x2003ULL 
                                         == (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        | ((3ULL == 
                                            (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           | ((0x4003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                              | ((0x1003ULL 
                                                  == 
                                                  (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                 | ((0x5003ULL 
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
                                                          | ((0x1023ULL 
                                                              == 
                                                              (0x707fULL 
                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                             | ((0x17ULL 
                                                                 != 
                                                                 (0x7fULL 
                                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                & ((0x37ULL 
                                                                    != 
                                                                    (0x7fULL 
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
                                                                               | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_240))))))))))))))))));
            tracep->chgBit(oldp+100,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
                                      & ((0x2003ULL 
                                          != (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((3ULL != 
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
                                                     & ((0x2023ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        | ((0x23ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           | ((0x1023ULL 
                                                               == 
                                                               (0x707fULL 
                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                              | ((0x17ULL 
                                                                  != 
                                                                  (0x7fULL 
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
                                                                                & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_276))))))))))))))))));
            tracep->chgCData(oldp+101,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr),5);
            tracep->chgBit(oldp+102,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load));
            tracep->chgQData(oldp+103,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data),64);
            tracep->chgQData(oldp+105,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data),64);
            tracep->chgCData(oldp+107,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr),5);
            tracep->chgQData(oldp+108,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata),64);
            tracep->chgBit(oldp+110,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
            tracep->chgQData(oldp+111,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1),64);
            tracep->chgQData(oldp+113,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset),64);
            tracep->chgCData(oldp+115,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun),4);
            tracep->chgBit(oldp+116,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid));
            tracep->chgQData(oldp+117,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc),64);
            tracep->chgBit(oldp+119,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid));
            tracep->chgQData(oldp+120,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst),64);
            tracep->chgQData(oldp+122,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc),64);
            tracep->chgCData(oldp+124,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr),5);
            tracep->chgCData(oldp+125,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs1_addr),5);
            tracep->chgCData(oldp+126,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_addr),5);
            tracep->chgQData(oldp+127,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data),64);
            tracep->chgCData(oldp+129,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel),2);
            tracep->chgBit(oldp+130,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
            tracep->chgCData(oldp+131,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn),2);
            tracep->chgCData(oldp+132,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ),3);
            tracep->chgBit(oldp+133,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid));
            tracep->chgQData(oldp+134,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc),64);
            tracep->chgQData(oldp+136,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst),64);
            tracep->chgQData(oldp+138,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out),64);
            tracep->chgCData(oldp+140,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr),5);
            tracep->chgCData(oldp+141,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs1_addr),5);
            tracep->chgCData(oldp+142,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_addr),5);
            tracep->chgQData(oldp+143,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_op1_data),64);
            tracep->chgQData(oldp+145,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_op2_data),64);
            tracep->chgBit(oldp+147,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
            tracep->chgCData(oldp+148,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel),2);
            tracep->chgQData(oldp+149,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data),64);
            tracep->chgQData(oldp+151,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_inst),64);
            tracep->chgQData(oldp+153,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)),64);
            tracep->chgQData(oldp+155,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target),64);
            tracep->chgQData(oldp+157,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out),64);
            tracep->chgQData(oldp+159,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                                         ? (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)
                                         : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                                             ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target
                                             : ((2U 
                                                 == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                                                 ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out
                                                 : 0x4033ULL)))),64);
            tracep->chgSData(oldp+161,((0xfffU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0x14U)))),12);
            tracep->chgSData(oldp+162,(((0xfe0U & ((IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0x19U)) 
                                                   << 5U)) 
                                        | (0x1fU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 7U))))),12);
            tracep->chgSData(oldp+163,(((0x800U & ((IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0x1fU)) 
                                                   << 0xbU)) 
                                        | ((0x400U 
                                            & ((IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 7U)) 
                                               << 0xaU)) 
                                           | ((0x3f0U 
                                               & ((IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                           >> 0x19U)) 
                                                  << 4U)) 
                                              | (0xfU 
                                                 & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 8U))))))),12);
            tracep->chgIData(oldp+164,((0xfffffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0xcU)))),20);
            tracep->chgIData(oldp+165,(((0x80000U & 
                                         ((IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                   >> 0x1fU)) 
                                          << 0x13U)) 
                                        | ((0x7f800U 
                                            & ((IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0xcU)) 
                                               << 0xbU)) 
                                           | ((0x400U 
                                               & ((IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                           >> 0x14U)) 
                                                  << 0xaU)) 
                                              | (0x3ffU 
                                                 & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0x15U))))))),20);
            tracep->chgIData(oldp+166,((0x1fU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0xfU)))),32);
            tracep->chgQData(oldp+167,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_itype_sext),64);
            tracep->chgQData(oldp+169,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_stype_sext),64);
            tracep->chgQData(oldp+171,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_sbtype_sext),64);
            tracep->chgQData(oldp+173,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_utype_sext),64);
            tracep->chgQData(oldp+175,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_ujtype_sext),64);
            tracep->chgQData(oldp+177,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_alu_op2),64);
            tracep->chgQData(oldp+179,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata),64);
            tracep->chgQData(oldp+181,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_60)
                                         ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res
                                         : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_64)
                                             ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata
                                             : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_68)
                                                 ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                                                 : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data)))),64);
            tracep->chgQData(oldp+183,(((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                                         ? (QData)((IData)(
                                                           (0x1fU 
                                                            & (IData)(
                                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                       >> 0xfU)))))
                                         : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                                             ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc
                                             : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_60)
                                                 ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res
                                                 : 
                                                ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_64)
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata
                                                  : 
                                                 ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_68)
                                                   ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                                                   : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data)))))),64);
            tracep->chgQData(oldp+185,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_81)
                                         ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res
                                         : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_87)
                                             ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata
                                             : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_93)
                                                 ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                                                 : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_alu_op2)))),64);
            tracep->chgQData(oldp+187,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)),64);
            tracep->chgQData(oldp+189,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[0]),64);
            tracep->chgQData(oldp+191,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[1]),64);
            tracep->chgQData(oldp+193,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[2]),64);
            tracep->chgQData(oldp+195,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[3]),64);
            tracep->chgQData(oldp+197,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[4]),64);
            tracep->chgQData(oldp+199,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[5]),64);
            tracep->chgQData(oldp+201,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[6]),64);
            tracep->chgQData(oldp+203,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[7]),64);
            tracep->chgQData(oldp+205,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[8]),64);
            tracep->chgQData(oldp+207,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[9]),64);
            tracep->chgQData(oldp+209,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[10]),64);
            tracep->chgQData(oldp+211,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[11]),64);
            tracep->chgQData(oldp+213,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[12]),64);
            tracep->chgQData(oldp+215,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[13]),64);
            tracep->chgQData(oldp+217,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[14]),64);
            tracep->chgQData(oldp+219,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[15]),64);
            tracep->chgQData(oldp+221,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[16]),64);
            tracep->chgQData(oldp+223,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[17]),64);
            tracep->chgQData(oldp+225,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[18]),64);
            tracep->chgQData(oldp+227,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[19]),64);
            tracep->chgQData(oldp+229,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[20]),64);
            tracep->chgQData(oldp+231,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[21]),64);
            tracep->chgQData(oldp+233,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[22]),64);
            tracep->chgQData(oldp+235,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[23]),64);
            tracep->chgQData(oldp+237,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[24]),64);
            tracep->chgQData(oldp+239,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[25]),64);
            tracep->chgQData(oldp+241,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[26]),64);
            tracep->chgQData(oldp+243,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[27]),64);
            tracep->chgQData(oldp+245,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[28]),64);
            tracep->chgQData(oldp+247,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[29]),64);
            tracep->chgQData(oldp+249,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[30]),64);
            tracep->chgQData(oldp+251,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[31]),64);
            tracep->chgQData(oldp+253,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                       [(0x1fU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0xfU)))]),64);
            tracep->chgQData(oldp+255,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                       [(0x1fU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0x14U)))]),64);
            tracep->chgBit(oldp+257,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen) 
                                      & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr)))));
            tracep->chgCData(oldp+258,((0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))),6);
        }
        tracep->chgBit(oldp+259,(vlTOPp->clock));
        tracep->chgBit(oldp+260,(vlTOPp->reset));
        tracep->chgQData(oldp+261,(vlTOPp->io_diffTestIO_regfile_0),64);
        tracep->chgQData(oldp+263,(vlTOPp->io_diffTestIO_regfile_1),64);
        tracep->chgQData(oldp+265,(vlTOPp->io_diffTestIO_regfile_2),64);
        tracep->chgQData(oldp+267,(vlTOPp->io_diffTestIO_regfile_3),64);
        tracep->chgQData(oldp+269,(vlTOPp->io_diffTestIO_regfile_4),64);
        tracep->chgQData(oldp+271,(vlTOPp->io_diffTestIO_regfile_5),64);
        tracep->chgQData(oldp+273,(vlTOPp->io_diffTestIO_regfile_6),64);
        tracep->chgQData(oldp+275,(vlTOPp->io_diffTestIO_regfile_7),64);
        tracep->chgQData(oldp+277,(vlTOPp->io_diffTestIO_regfile_8),64);
        tracep->chgQData(oldp+279,(vlTOPp->io_diffTestIO_regfile_9),64);
        tracep->chgQData(oldp+281,(vlTOPp->io_diffTestIO_regfile_10),64);
        tracep->chgQData(oldp+283,(vlTOPp->io_diffTestIO_regfile_11),64);
        tracep->chgQData(oldp+285,(vlTOPp->io_diffTestIO_regfile_12),64);
        tracep->chgQData(oldp+287,(vlTOPp->io_diffTestIO_regfile_13),64);
        tracep->chgQData(oldp+289,(vlTOPp->io_diffTestIO_regfile_14),64);
        tracep->chgQData(oldp+291,(vlTOPp->io_diffTestIO_regfile_15),64);
        tracep->chgQData(oldp+293,(vlTOPp->io_diffTestIO_regfile_16),64);
        tracep->chgQData(oldp+295,(vlTOPp->io_diffTestIO_regfile_17),64);
        tracep->chgQData(oldp+297,(vlTOPp->io_diffTestIO_regfile_18),64);
        tracep->chgQData(oldp+299,(vlTOPp->io_diffTestIO_regfile_19),64);
        tracep->chgQData(oldp+301,(vlTOPp->io_diffTestIO_regfile_20),64);
        tracep->chgQData(oldp+303,(vlTOPp->io_diffTestIO_regfile_21),64);
        tracep->chgQData(oldp+305,(vlTOPp->io_diffTestIO_regfile_22),64);
        tracep->chgQData(oldp+307,(vlTOPp->io_diffTestIO_regfile_23),64);
        tracep->chgQData(oldp+309,(vlTOPp->io_diffTestIO_regfile_24),64);
        tracep->chgQData(oldp+311,(vlTOPp->io_diffTestIO_regfile_25),64);
        tracep->chgQData(oldp+313,(vlTOPp->io_diffTestIO_regfile_26),64);
        tracep->chgQData(oldp+315,(vlTOPp->io_diffTestIO_regfile_27),64);
        tracep->chgQData(oldp+317,(vlTOPp->io_diffTestIO_regfile_28),64);
        tracep->chgQData(oldp+319,(vlTOPp->io_diffTestIO_regfile_29),64);
        tracep->chgQData(oldp+321,(vlTOPp->io_diffTestIO_regfile_30),64);
        tracep->chgQData(oldp+323,(vlTOPp->io_diffTestIO_regfile_31),64);
        tracep->chgQData(oldp+325,(vlTOPp->io_diffTestIO_pc),64);
        tracep->chgBit(oldp+327,(vlTOPp->io_diffTestIO_valid));
        tracep->chgQData(oldp+328,(vlTOPp->io_coreIO_inst_readIO_addr),64);
        tracep->chgQData(oldp+330,(vlTOPp->io_coreIO_inst_readIO_data),64);
        tracep->chgBit(oldp+332,(vlTOPp->io_coreIO_inst_readIO_en));
        tracep->chgQData(oldp+333,(vlTOPp->io_coreIO_data_readIO_addr),64);
        tracep->chgQData(oldp+335,(vlTOPp->io_coreIO_data_readIO_data),64);
        tracep->chgBit(oldp+337,(vlTOPp->io_coreIO_data_readIO_en));
        tracep->chgQData(oldp+338,(vlTOPp->io_coreIO_data_writeIO_addr),64);
        tracep->chgQData(oldp+340,(vlTOPp->io_coreIO_data_writeIO_data),64);
        tracep->chgBit(oldp+342,(vlTOPp->io_coreIO_data_writeIO_en));
        tracep->chgCData(oldp+343,(vlTOPp->io_coreIO_data_writeIO_mask),8);
    }
}

void VsimTop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    VsimTop__Syms* __restrict vlSymsp = static_cast<VsimTop__Syms*>(userp);
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
