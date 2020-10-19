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
            tracep->chgQData(oldp+0,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out),64);
            tracep->chgQData(oldp+2,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_data),64);
            tracep->chgBit(oldp+4,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid));
            tracep->chgQData(oldp+5,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                     [0U]),64);
            tracep->chgQData(oldp+7,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                     [1U]),64);
            tracep->chgQData(oldp+9,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                     [2U]),64);
            tracep->chgQData(oldp+11,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [3U]),64);
            tracep->chgQData(oldp+13,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [4U]),64);
            tracep->chgQData(oldp+15,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [5U]),64);
            tracep->chgQData(oldp+17,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [6U]),64);
            tracep->chgQData(oldp+19,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [7U]),64);
            tracep->chgQData(oldp+21,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [8U]),64);
            tracep->chgQData(oldp+23,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [9U]),64);
            tracep->chgQData(oldp+25,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xaU]),64);
            tracep->chgQData(oldp+27,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xbU]),64);
            tracep->chgQData(oldp+29,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xcU]),64);
            tracep->chgQData(oldp+31,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xdU]),64);
            tracep->chgQData(oldp+33,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xeU]),64);
            tracep->chgQData(oldp+35,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0xfU]),64);
            tracep->chgQData(oldp+37,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x10U]),64);
            tracep->chgQData(oldp+39,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x11U]),64);
            tracep->chgQData(oldp+41,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x12U]),64);
            tracep->chgQData(oldp+43,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x13U]),64);
            tracep->chgQData(oldp+45,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x14U]),64);
            tracep->chgQData(oldp+47,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x15U]),64);
            tracep->chgQData(oldp+49,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x16U]),64);
            tracep->chgQData(oldp+51,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x17U]),64);
            tracep->chgQData(oldp+53,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x18U]),64);
            tracep->chgQData(oldp+55,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x19U]),64);
            tracep->chgQData(oldp+57,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1aU]),64);
            tracep->chgQData(oldp+59,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1bU]),64);
            tracep->chgQData(oldp+61,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1cU]),64);
            tracep->chgQData(oldp+63,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1dU]),64);
            tracep->chgQData(oldp+65,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1eU]),64);
            tracep->chgQData(oldp+67,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                      [0x1fU]),64);
            tracep->chgQData(oldp+69,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst),64);
            tracep->chgBit(oldp+71,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq));
            tracep->chgBit(oldp+72,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt));
            tracep->chgBit(oldp+73,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu));
            tracep->chgCData(oldp+74,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type),4);
            tracep->chgBit(oldp+75,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall));
            tracep->chgCData(oldp+76,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel),2);
            tracep->chgCData(oldp+77,(((0x2003ULL == 
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
            tracep->chgBit(oldp+78,((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))));
            tracep->chgCData(oldp+79,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel),2);
            tracep->chgCData(oldp+80,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel),3);
            tracep->chgCData(oldp+81,(((0x2003ULL == 
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
            tracep->chgCData(oldp+82,(((0x2003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_361))),2);
            tracep->chgBit(oldp+83,(((0x2003ULL == 
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
            tracep->chgBit(oldp+84,(((0x2003ULL == 
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
            tracep->chgBit(oldp+85,(((0x2003ULL != 
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
            tracep->chgBit(oldp+86,(((0x2003ULL == 
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
                                                 | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_429))))))));
            tracep->chgBit(oldp+87,(((0x2003ULL != 
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
                                                 & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_429))))))));
            tracep->chgCData(oldp+88,((0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0xfU)))),5);
            tracep->chgCData(oldp+89,((0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0x14U)))),5);
            tracep->chgCData(oldp+90,((0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 7U)))),5);
            tracep->chgBit(oldp+91,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
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
            tracep->chgBit(oldp+92,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                                     & ((0x2003ULL 
                                         != (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        & ((3ULL != 
                                            (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           & ((0x4003ULL 
                                               != (0x707fULL 
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
            tracep->chgCData(oldp+93,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr),5);
            tracep->chgBit(oldp+94,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load));
            tracep->chgQData(oldp+95,(((0U != (0x1fU 
                                               & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0xfU))))
                                        ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                       [(0x1fU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0xfU)))]
                                        : 0ULL)),64);
            tracep->chgQData(oldp+97,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data),64);
            tracep->chgCData(oldp+99,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr),5);
            tracep->chgQData(oldp+100,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata),64);
            tracep->chgBit(oldp+102,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
            tracep->chgQData(oldp+103,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1),64);
            tracep->chgQData(oldp+105,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset),64);
            tracep->chgCData(oldp+107,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun),4);
            tracep->chgQData(oldp+108,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res),64);
            tracep->chgQData(oldp+110,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc),64);
            tracep->chgBit(oldp+112,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid));
            tracep->chgQData(oldp+113,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc),64);
            tracep->chgBit(oldp+115,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid));
            tracep->chgQData(oldp+116,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst),64);
            tracep->chgQData(oldp+118,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc),64);
            tracep->chgCData(oldp+120,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr),5);
            tracep->chgQData(oldp+121,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data),64);
            tracep->chgCData(oldp+123,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel),2);
            tracep->chgBit(oldp+124,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
            tracep->chgBit(oldp+125,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid));
            tracep->chgQData(oldp+126,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc),64);
            tracep->chgQData(oldp+128,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst),64);
            tracep->chgCData(oldp+130,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr),5);
            tracep->chgBit(oldp+131,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
            tracep->chgCData(oldp+132,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel),2);
            tracep->chgQData(oldp+133,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)),64);
            tracep->chgQData(oldp+135,((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
                                        + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)),64);
            tracep->chgQData(oldp+137,((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                        + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)),64);
            tracep->chgQData(oldp+139,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_inst),64);
            tracep->chgSData(oldp+141,((0xfffU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0x14U)))),12);
            tracep->chgSData(oldp+142,(((0xfe0U & ((IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0x19U)) 
                                                   << 5U)) 
                                        | (0x1fU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 7U))))),12);
            tracep->chgSData(oldp+143,(((0x800U & ((IData)(
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
            tracep->chgIData(oldp+144,((0xfffffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0xcU)))),20);
            tracep->chgIData(oldp+145,(((0x80000U & 
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
            tracep->chgIData(oldp+146,((0x1fU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0xfU)))),32);
            tracep->chgQData(oldp+147,(((((1U & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0x1fU)))
                                           ? 0xfffffffffffffULL
                                           : 0ULL) 
                                         << 0xcU) | (QData)((IData)(
                                                                    (0xfffU 
                                                                     & (IData)(
                                                                               (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 0x14U))))))),64);
            tracep->chgQData(oldp+149,(((((1U & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0x1fU)))
                                           ? 0xfffffffffffffULL
                                           : 0ULL) 
                                         << 0xcU) | (QData)((IData)(
                                                                    ((0xfe0U 
                                                                      & ((IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 0x19U)) 
                                                                         << 5U)) 
                                                                     | (0x1fU 
                                                                        & (IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 7U)))))))),64);
            tracep->chgQData(oldp+151,(((((1U & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0x1fU)))
                                           ? 0x7ffffffffffffULL
                                           : 0ULL) 
                                         << 0xdU) | (QData)((IData)(
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
                                                                                << 1U))))))))),64);
            tracep->chgQData(oldp+153,((((QData)((IData)(
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
                                                              << 0xcU)))))),64);
            tracep->chgQData(oldp+155,(((((1U & (IData)(
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
                                                                       << 1U))))))))),64);
            tracep->chgQData(oldp+157,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)),64);
            tracep->chgQData(oldp+159,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[0]),64);
            tracep->chgQData(oldp+161,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[1]),64);
            tracep->chgQData(oldp+163,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[2]),64);
            tracep->chgQData(oldp+165,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[3]),64);
            tracep->chgQData(oldp+167,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[4]),64);
            tracep->chgQData(oldp+169,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[5]),64);
            tracep->chgQData(oldp+171,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[6]),64);
            tracep->chgQData(oldp+173,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[7]),64);
            tracep->chgQData(oldp+175,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[8]),64);
            tracep->chgQData(oldp+177,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[9]),64);
            tracep->chgQData(oldp+179,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[10]),64);
            tracep->chgQData(oldp+181,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[11]),64);
            tracep->chgQData(oldp+183,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[12]),64);
            tracep->chgQData(oldp+185,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[13]),64);
            tracep->chgQData(oldp+187,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[14]),64);
            tracep->chgQData(oldp+189,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[15]),64);
            tracep->chgQData(oldp+191,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[16]),64);
            tracep->chgQData(oldp+193,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[17]),64);
            tracep->chgQData(oldp+195,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[18]),64);
            tracep->chgQData(oldp+197,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[19]),64);
            tracep->chgQData(oldp+199,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[20]),64);
            tracep->chgQData(oldp+201,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[21]),64);
            tracep->chgQData(oldp+203,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[22]),64);
            tracep->chgQData(oldp+205,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[23]),64);
            tracep->chgQData(oldp+207,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[24]),64);
            tracep->chgQData(oldp+209,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[25]),64);
            tracep->chgQData(oldp+211,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[26]),64);
            tracep->chgQData(oldp+213,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[27]),64);
            tracep->chgQData(oldp+215,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[28]),64);
            tracep->chgQData(oldp+217,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[29]),64);
            tracep->chgQData(oldp+219,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[30]),64);
            tracep->chgQData(oldp+221,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[31]),64);
            tracep->chgQData(oldp+223,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                       [(0x1fU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0xfU)))]),64);
            tracep->chgQData(oldp+225,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                       [(0x1fU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0x14U)))]),64);
            tracep->chgBit(oldp+227,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen) 
                                      & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr)))));
            tracep->chgCData(oldp+228,((0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))),6);
        }
        tracep->chgBit(oldp+229,(vlTOPp->clock));
        tracep->chgBit(oldp+230,(vlTOPp->reset));
        tracep->chgQData(oldp+231,(vlTOPp->io_diffTestIO_regfile_0),64);
        tracep->chgQData(oldp+233,(vlTOPp->io_diffTestIO_regfile_1),64);
        tracep->chgQData(oldp+235,(vlTOPp->io_diffTestIO_regfile_2),64);
        tracep->chgQData(oldp+237,(vlTOPp->io_diffTestIO_regfile_3),64);
        tracep->chgQData(oldp+239,(vlTOPp->io_diffTestIO_regfile_4),64);
        tracep->chgQData(oldp+241,(vlTOPp->io_diffTestIO_regfile_5),64);
        tracep->chgQData(oldp+243,(vlTOPp->io_diffTestIO_regfile_6),64);
        tracep->chgQData(oldp+245,(vlTOPp->io_diffTestIO_regfile_7),64);
        tracep->chgQData(oldp+247,(vlTOPp->io_diffTestIO_regfile_8),64);
        tracep->chgQData(oldp+249,(vlTOPp->io_diffTestIO_regfile_9),64);
        tracep->chgQData(oldp+251,(vlTOPp->io_diffTestIO_regfile_10),64);
        tracep->chgQData(oldp+253,(vlTOPp->io_diffTestIO_regfile_11),64);
        tracep->chgQData(oldp+255,(vlTOPp->io_diffTestIO_regfile_12),64);
        tracep->chgQData(oldp+257,(vlTOPp->io_diffTestIO_regfile_13),64);
        tracep->chgQData(oldp+259,(vlTOPp->io_diffTestIO_regfile_14),64);
        tracep->chgQData(oldp+261,(vlTOPp->io_diffTestIO_regfile_15),64);
        tracep->chgQData(oldp+263,(vlTOPp->io_diffTestIO_regfile_16),64);
        tracep->chgQData(oldp+265,(vlTOPp->io_diffTestIO_regfile_17),64);
        tracep->chgQData(oldp+267,(vlTOPp->io_diffTestIO_regfile_18),64);
        tracep->chgQData(oldp+269,(vlTOPp->io_diffTestIO_regfile_19),64);
        tracep->chgQData(oldp+271,(vlTOPp->io_diffTestIO_regfile_20),64);
        tracep->chgQData(oldp+273,(vlTOPp->io_diffTestIO_regfile_21),64);
        tracep->chgQData(oldp+275,(vlTOPp->io_diffTestIO_regfile_22),64);
        tracep->chgQData(oldp+277,(vlTOPp->io_diffTestIO_regfile_23),64);
        tracep->chgQData(oldp+279,(vlTOPp->io_diffTestIO_regfile_24),64);
        tracep->chgQData(oldp+281,(vlTOPp->io_diffTestIO_regfile_25),64);
        tracep->chgQData(oldp+283,(vlTOPp->io_diffTestIO_regfile_26),64);
        tracep->chgQData(oldp+285,(vlTOPp->io_diffTestIO_regfile_27),64);
        tracep->chgQData(oldp+287,(vlTOPp->io_diffTestIO_regfile_28),64);
        tracep->chgQData(oldp+289,(vlTOPp->io_diffTestIO_regfile_29),64);
        tracep->chgQData(oldp+291,(vlTOPp->io_diffTestIO_regfile_30),64);
        tracep->chgQData(oldp+293,(vlTOPp->io_diffTestIO_regfile_31),64);
        tracep->chgQData(oldp+295,(vlTOPp->io_diffTestIO_pc),64);
        tracep->chgBit(oldp+297,(vlTOPp->io_diffTestIO_valid));
        tracep->chgQData(oldp+298,(vlTOPp->io_coreIO_inst_read_io_addr),64);
        tracep->chgQData(oldp+300,(vlTOPp->io_coreIO_inst_read_io_data),64);
        tracep->chgBit(oldp+302,(vlTOPp->io_coreIO_inst_read_io_en));
        tracep->chgQData(oldp+303,(vlTOPp->io_coreIO_data_read_io_addr),64);
        tracep->chgQData(oldp+305,(vlTOPp->io_coreIO_data_read_io_data),64);
        tracep->chgBit(oldp+307,(vlTOPp->io_coreIO_data_read_io_en));
        tracep->chgQData(oldp+308,(vlTOPp->io_coreIO_data_write_io_addr),64);
        tracep->chgQData(oldp+310,(vlTOPp->io_coreIO_data_write_io_data),64);
        tracep->chgBit(oldp+312,(vlTOPp->io_coreIO_data_write_io_en));
        tracep->chgQData(oldp+313,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                     ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                                     : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                         ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                                         : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                             ? vlTOPp->io_coreIO_data_read_io_data
                                             : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)))),64);
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
