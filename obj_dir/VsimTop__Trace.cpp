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
    // Variables
    WData/*127:0*/ __Vtemp80[4];
    WData/*127:0*/ __Vtemp81[4];
    WData/*127:0*/ __Vtemp82[4];
    WData/*127:0*/ __Vtemp85[4];
    WData/*127:0*/ __Vtemp86[4];
    WData/*127:0*/ __Vtemp87[4];
    WData/*127:0*/ __Vtemp89[4];
    WData/*127:0*/ __Vtemp90[4];
    WData/*127:0*/ __Vtemp91[4];
    WData/*127:0*/ __Vtemp92[4];
    WData/*127:0*/ __Vtemp93[4];
    WData/*127:0*/ __Vtemp94[4];
    WData/*127:0*/ __Vtemp95[4];
    WData/*127:0*/ __Vtemp97[4];
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc),64);
            tracep->chgQData(oldp+2,(((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                                       ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151
                                       : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)),64);
            tracep->chgBit(oldp+4,((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn))));
            tracep->chgQData(oldp+5,(((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
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
                                       : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
                                           ? (((QData)((IData)(
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
                                           : ((0xfU 
                                               == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
                                               ? (((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)))
                                               : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)))),64);
            tracep->chgBit(oldp+7,((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn))));
            tracep->chgCData(oldp+8,((0xffU & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ) 
                                               << (7U 
                                                   & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out))))),8);
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
            tracep->chgBit(oldp+82,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir));
            tracep->chgBit(oldp+83,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall));
            tracep->chgCData(oldp+84,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel),2);
            tracep->chgCData(oldp+85,(((0x3003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 0U : ((0x2003ULL 
                                                 == 
                                                 (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                 ? 0U
                                                 : 
                                                ((0x6003ULL 
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
                                                   : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_294)))))),4);
            tracep->chgBit(oldp+86,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_if_kill));
            tracep->chgBit(oldp+87,((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))));
            tracep->chgCData(oldp+88,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel),2);
            tracep->chgCData(oldp+89,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel),3);
            tracep->chgCData(oldp+90,(((0x3003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 0U : ((0x2003ULL 
                                                 == 
                                                 (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                 ? 0U
                                                 : 
                                                ((0x6003ULL 
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
                                                     ((0x3023ULL 
                                                       == 
                                                       (0x707fULL 
                                                        & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                       ? 0U
                                                       : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_660)))))))))),5);
            tracep->chgCData(oldp+91,(((0x3003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 1U : ((0x2003ULL 
                                                 == 
                                                 (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                 ? 1U
                                                 : 
                                                ((0x6003ULL 
                                                  == 
                                                  (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                  ? 1U
                                                  : 
                                                 ((3ULL 
                                                   == 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                   ? 1U
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
                                                       : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_734)))))))))),3);
            tracep->chgBit(oldp+92,(((0x3003ULL == 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((0x2003ULL 
                                         == (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        | ((0x6003ULL 
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
                                                                               | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_801))))))))))))))))));
            tracep->chgCData(oldp+93,(((0x3003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_963))),2);
            tracep->chgCData(oldp+94,(((0x3003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 0xffU : (
                                                   (0x2003ULL 
                                                    == 
                                                    (0x707fULL 
                                                     & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                    ? 0xffU
                                                    : 
                                                   ((0x6003ULL 
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
                                                             : 0xffU)))))))))))),8);
            tracep->chgCData(oldp+95,(((0x3003ULL == 
                                        (0x707fULL 
                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                        ? 6U : ((0x2003ULL 
                                                 == 
                                                 (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                 ? 4U
                                                 : 
                                                ((0x6003ULL 
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
                                                      : 0U)))))))),3);
            tracep->chgCData(oldp+96,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1295)
                                        ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7))),3);
            tracep->chgBit(oldp+97,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8) 
                                     | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1313))));
            tracep->chgBit(oldp+98,(((0x3003ULL == 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((0x2003ULL 
                                         == (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        | ((0x6003ULL 
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
                                                       | ((0x3023ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                          | ((0x2023ULL 
                                                              == 
                                                              (0x707fULL 
                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                             | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_511))))))))))));
            tracep->chgBit(oldp+99,(((0x3003ULL != 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     & ((0x2003ULL 
                                         != (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        & ((0x6003ULL 
                                            != (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           & ((3ULL 
                                               != (0x707fULL 
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
                                                       & ((0x3023ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                          | ((0x2023ULL 
                                                              == 
                                                              (0x707fULL 
                                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                             | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_585))))))))))));
            tracep->chgBit(oldp+100,(((0x3003ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x2003ULL 
                                          == (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((0x6003ULL 
                                             == (0x707fULL 
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
                                                     | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_884)))))))));
            tracep->chgCData(oldp+101,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7),3);
            tracep->chgBit(oldp+102,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8));
            tracep->chgCData(oldp+103,((0x1fU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0xfU)))),5);
            tracep->chgCData(oldp+104,((0x1fU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0x14U)))),5);
            tracep->chgCData(oldp+105,((0x1fU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 7U)))),5);
            tracep->chgBit(oldp+106,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                                      & ((0x3003ULL 
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
                                                                 | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_511)))))))))))));
            tracep->chgBit(oldp+107,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                                      & ((0x3003ULL 
                                          != (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x2003ULL 
                                             != (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                            & ((0x6003ULL 
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
                                                           & ((0x3023ULL 
                                                               == 
                                                               (0x707fULL 
                                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                              | ((0x2023ULL 
                                                                  == 
                                                                  (0x707fULL 
                                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                                 | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_585)))))))))))));
            tracep->chgCData(oldp+108,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr),5);
            tracep->chgBit(oldp+109,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr));
            tracep->chgBit(oldp+110,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load));
            tracep->chgQData(oldp+111,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data),64);
            tracep->chgQData(oldp+113,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data),64);
            tracep->chgCData(oldp+115,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr),5);
            tracep->chgQData(oldp+116,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata),64);
            tracep->chgBit(oldp+118,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
            tracep->chgQData(oldp+119,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1),64);
            tracep->chgQData(oldp+121,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset),64);
            tracep->chgCData(oldp+123,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun),5);
            tracep->chgQData(oldp+124,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res),64);
            tracep->chgBit(oldp+126,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall));
            tracep->chgIData(oldp+127,((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst)),32);
            tracep->chgCData(oldp+128,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd),3);
            tracep->chgQData(oldp+129,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out),64);
            tracep->chgQData(oldp+131,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc),64);
            tracep->chgQData(oldp+133,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc),64);
            tracep->chgQData(oldp+135,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc),64);
            tracep->chgBit(oldp+137,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid));
            tracep->chgBit(oldp+138,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid));
            tracep->chgQData(oldp+139,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst),64);
            tracep->chgCData(oldp+141,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr),5);
            tracep->chgQData(oldp+142,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data),64);
            tracep->chgCData(oldp+144,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel),3);
            tracep->chgBit(oldp+145,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
            tracep->chgCData(oldp+146,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn),2);
            tracep->chgCData(oldp+147,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ),8);
            tracep->chgCData(oldp+148,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid),3);
            tracep->chgCData(oldp+149,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_csr_cmd),3);
            tracep->chgBit(oldp+150,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid));
            tracep->chgQData(oldp+151,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst),64);
            tracep->chgCData(oldp+153,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr),5);
            tracep->chgBit(oldp+154,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
            tracep->chgCData(oldp+155,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel),3);
            tracep->chgCData(oldp+156,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid),3);
            tracep->chgQData(oldp+157,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data),64);
            tracep->chgQData(oldp+159,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)),64);
            tracep->chgQData(oldp+161,((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
                                        + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)),64);
            tracep->chgQData(oldp+163,((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                        + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)),64);
            tracep->chgSData(oldp+165,((0xfffU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0x14U)))),12);
            tracep->chgSData(oldp+166,(((0xfe0U & ((IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0x19U)) 
                                                   << 5U)) 
                                        | (0x1fU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 7U))))),12);
            tracep->chgSData(oldp+167,(((0x800U & ((IData)(
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
            tracep->chgIData(oldp+168,((0xfffffU & (IData)(
                                                           (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                            >> 0xcU)))),20);
            tracep->chgIData(oldp+169,(((0x80000U & 
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
            tracep->chgIData(oldp+170,((0x1fU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0xfU)))),32);
            tracep->chgQData(oldp+171,(((((1U & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0x1fU)))
                                           ? 0xfffffffffffffULL
                                           : 0ULL) 
                                         << 0xcU) | (QData)((IData)(
                                                                    (0xfffU 
                                                                     & (IData)(
                                                                               (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                                >> 0x14U))))))),64);
            tracep->chgQData(oldp+173,(((((1U & (IData)(
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
            tracep->chgQData(oldp+175,(((((1U & (IData)(
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
            tracep->chgQData(oldp+177,((((QData)((IData)(
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
            tracep->chgQData(oldp+179,(((((1U & (IData)(
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
            tracep->chgQData(oldp+181,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                         ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                                         : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                             ? (QData)((IData)(
                                                               (0xffU 
                                                                & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                             : ((2U 
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
                                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))),64);
            tracep->chgQData(oldp+183,(((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                         ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                             ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                                             : ((1U 
                                                 == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                 ? (QData)((IData)(
                                                                   (0xffU 
                                                                    & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                                 : 
                                                ((2U 
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
                                         : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)),64);
            tracep->chgQData(oldp+185,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out),64);
            tracep->chgQData(oldp+187,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_79)
                                         ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out
                                         : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_83)
                                             ? ((1U 
                                                 == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                                 ? 
                                                ((0U 
                                                  == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                                                  : 
                                                 ((1U 
                                                   == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                                   ? (QData)((IData)(
                                                                     (0xffU 
                                                                      & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                                   : 
                                                  ((2U 
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
                                                 : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data)))),64);
            tracep->chgQData(oldp+189,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)),64);
            tracep->chgQData(oldp+191,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[0]),64);
            tracep->chgQData(oldp+193,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[1]),64);
            tracep->chgQData(oldp+195,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[2]),64);
            tracep->chgQData(oldp+197,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[3]),64);
            tracep->chgQData(oldp+199,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[4]),64);
            tracep->chgQData(oldp+201,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[5]),64);
            tracep->chgQData(oldp+203,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[6]),64);
            tracep->chgQData(oldp+205,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[7]),64);
            tracep->chgQData(oldp+207,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[8]),64);
            tracep->chgQData(oldp+209,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[9]),64);
            tracep->chgQData(oldp+211,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[10]),64);
            tracep->chgQData(oldp+213,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[11]),64);
            tracep->chgQData(oldp+215,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[12]),64);
            tracep->chgQData(oldp+217,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[13]),64);
            tracep->chgQData(oldp+219,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[14]),64);
            tracep->chgQData(oldp+221,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[15]),64);
            tracep->chgQData(oldp+223,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[16]),64);
            tracep->chgQData(oldp+225,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[17]),64);
            tracep->chgQData(oldp+227,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[18]),64);
            tracep->chgQData(oldp+229,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[19]),64);
            tracep->chgQData(oldp+231,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[20]),64);
            tracep->chgQData(oldp+233,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[21]),64);
            tracep->chgQData(oldp+235,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[22]),64);
            tracep->chgQData(oldp+237,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[23]),64);
            tracep->chgQData(oldp+239,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[24]),64);
            tracep->chgQData(oldp+241,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[25]),64);
            tracep->chgQData(oldp+243,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[26]),64);
            tracep->chgQData(oldp+245,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[27]),64);
            tracep->chgQData(oldp+247,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[28]),64);
            tracep->chgQData(oldp+249,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[29]),64);
            tracep->chgQData(oldp+251,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[30]),64);
            tracep->chgQData(oldp+253,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[31]),64);
            tracep->chgQData(oldp+255,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                       [(0x1fU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0xfU)))]),64);
            tracep->chgQData(oldp+257,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                       [(0x1fU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                          >> 0x14U)))]),64);
            tracep->chgBit(oldp+259,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen) 
                                      & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr)))));
            tracep->chgBit(oldp+260,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu));
            tracep->chgBit(oldp+261,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req));
            __Vtemp80[0U] = 1U;
            __Vtemp80[1U] = 0U;
            __Vtemp80[2U] = 0U;
            __Vtemp80[3U] = 0U;
            __Vtemp81[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
            __Vtemp81[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
            __Vtemp81[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
            __Vtemp81[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
            VL_ADD_W(4, __Vtemp82, __Vtemp80, __Vtemp81);
            __Vtemp85[0U] = 1U;
            __Vtemp85[1U] = 0U;
            __Vtemp85[2U] = 0U;
            __Vtemp85[3U] = 0U;
            __Vtemp86[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
            __Vtemp86[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
            __Vtemp86[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
            __Vtemp86[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
            VL_ADD_W(4, __Vtemp87, __Vtemp85, __Vtemp86);
            tracep->chgQData(oldp+262,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
                                         ? ((0x19U 
                                             == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                             ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_268
                                             : ((0x14U 
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
                                                                    __Vtemp82[3U]
                                                                     : 
                                                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    ((1U 
                                                                      & (IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                                                >> 0x3fU)))
                                                                      ? 
                                                                     __Vtemp82[2U]
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
                                                                     __Vtemp87[3U]))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153)
                                                                       ? 
                                                                      vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]
                                                                       : 
                                                                      __Vtemp87[2U]))))
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
                                         : ((0x10U 
                                             == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                             ? ((0U 
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
                                             : ((0xfU 
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
                                                 : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_405)))),64);
            tracep->chgCData(oldp+264,((0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))),6);
            tracep->chgQData(oldp+265,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_a),64);
            tracep->chgQData(oldp+267,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_b),64);
            tracep->chgCData(oldp+269,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op),5);
            tracep->chgBit(oldp+270,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult));
            tracep->chgWData(oldp+271,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res),128);
            tracep->chgCData(oldp+275,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt),7);
            tracep->chgCData(oldp+276,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt),7);
            tracep->chgBit(oldp+277,((1U & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                    >> 0x3fU)))));
            tracep->chgBit(oldp+278,((1U & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                    >> 0x1fU)))));
            tracep->chgQData(oldp+279,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a),64);
            tracep->chgBit(oldp+281,((1U & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                                                    >> 0x3fU)))));
            tracep->chgBit(oldp+282,((1U & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                                                    >> 0x1fU)))));
            tracep->chgQData(oldp+283,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b),64);
            __Vtemp89[0U] = 1U;
            __Vtemp89[1U] = 0U;
            __Vtemp89[2U] = 0U;
            __Vtemp89[3U] = 0U;
            __Vtemp90[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
            __Vtemp90[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
            __Vtemp90[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
            __Vtemp90[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
            VL_ADD_W(4, __Vtemp91, __Vtemp89, __Vtemp90);
            if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153) {
                __Vtemp92[0U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U];
                __Vtemp92[1U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U];
                __Vtemp92[2U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U];
                __Vtemp92[3U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U];
            } else {
                __Vtemp92[0U] = __Vtemp91[0U];
                __Vtemp92[1U] = __Vtemp91[1U];
                __Vtemp92[2U] = __Vtemp91[2U];
                __Vtemp92[3U] = __Vtemp91[3U];
            }
            tracep->chgWData(oldp+285,(__Vtemp92),128);
            __Vtemp93[0U] = 1U;
            __Vtemp93[1U] = 0U;
            __Vtemp93[2U] = 0U;
            __Vtemp93[3U] = 0U;
            __Vtemp94[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
            __Vtemp94[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
            __Vtemp94[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
            __Vtemp94[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
            VL_ADD_W(4, __Vtemp95, __Vtemp93, __Vtemp94);
            if ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                               >> 0x3fU)))) {
                __Vtemp97[0U] = __Vtemp95[0U];
                __Vtemp97[1U] = __Vtemp95[1U];
                __Vtemp97[2U] = __Vtemp95[2U];
                __Vtemp97[3U] = __Vtemp95[3U];
            } else {
                __Vtemp97[0U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U];
                __Vtemp97[1U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U];
                __Vtemp97[2U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U];
                __Vtemp97[3U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U];
            }
            tracep->chgWData(oldp+289,(__Vtemp97),128);
            tracep->chgQData(oldp+293,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153)
                                         ? (((QData)((IData)(
                                                             vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])))
                                         : (1ULL + 
                                            (~ (((QData)((IData)(
                                                                 vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]))))))),64);
            tracep->chgQData(oldp+295,(((1U & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                       >> 0x3fU)))
                                         ? (1ULL + 
                                            (~ (((QData)((IData)(
                                                                 vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U])))))
                                         : (((QData)((IData)(
                                                             vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))))),64);
            tracep->chgIData(oldp+297,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_divsw),32);
            tracep->chgIData(oldp+298,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_remsw),32);
            tracep->chgBit(oldp+299,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_stall_req));
            tracep->chgWData(oldp+300,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val),65);
            tracep->chgWData(oldp+303,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result),128);
            tracep->chgQData(oldp+307,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtvec),64);
            tracep->chgQData(oldp+309,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc),64);
            tracep->chgQData(oldp+311,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause),64);
            tracep->chgBit(oldp+313,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_mtip));
            tracep->chgBit(oldp+314,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_msip));
            tracep->chgBit(oldp+315,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_mtip));
            tracep->chgBit(oldp+316,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_msip));
            tracep->chgQData(oldp+317,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval),64);
            tracep->chgQData(oldp+319,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mscratch),64);
            tracep->chgCData(oldp+321,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp),2);
            tracep->chgBit(oldp+322,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie));
            tracep->chgBit(oldp+323,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie));
            tracep->chgQData(oldp+324,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg0),64);
            tracep->chgQData(oldp+326,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg1),64);
            tracep->chgQData(oldp+328,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_0),64);
            tracep->chgQData(oldp+330,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_1),64);
            tracep->chgQData(oldp+332,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_2),64);
            tracep->chgQData(oldp+334,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_3),64);
            tracep->chgQData(oldp+336,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_4),64);
            tracep->chgQData(oldp+338,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_5),64);
            tracep->chgQData(oldp+340,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_6),64);
            tracep->chgQData(oldp+342,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_7),64);
            tracep->chgQData(oldp+344,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_8),64);
            tracep->chgQData(oldp+346,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_9),64);
            tracep->chgQData(oldp+348,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_10),64);
            tracep->chgQData(oldp+350,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_11),64);
            tracep->chgQData(oldp+352,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_12),64);
            tracep->chgQData(oldp+354,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_13),64);
            tracep->chgQData(oldp+356,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_14),64);
            tracep->chgQData(oldp+358,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_15),64);
            tracep->chgQData(oldp+360,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcycle),64);
            tracep->chgQData(oldp+362,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_minstret),64);
            tracep->chgQData(oldp+364,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_0),64);
            tracep->chgQData(oldp+366,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_1),64);
            tracep->chgQData(oldp+368,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_2),64);
            tracep->chgQData(oldp+370,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_3),64);
            tracep->chgQData(oldp+372,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_4),64);
            tracep->chgQData(oldp+374,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_5),64);
            tracep->chgQData(oldp+376,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_6),64);
            tracep->chgQData(oldp+378,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_7),64);
            tracep->chgQData(oldp+380,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_8),64);
            tracep->chgQData(oldp+382,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_9),64);
            tracep->chgQData(oldp+384,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_10),64);
            tracep->chgQData(oldp+386,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_11),64);
            tracep->chgQData(oldp+388,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_12),64);
            tracep->chgQData(oldp+390,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_13),64);
            tracep->chgQData(oldp+392,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_14),64);
            tracep->chgQData(oldp+394,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_15),64);
            tracep->chgQData(oldp+396,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_16),64);
            tracep->chgQData(oldp+398,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_17),64);
            tracep->chgQData(oldp+400,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_18),64);
            tracep->chgQData(oldp+402,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_19),64);
            tracep->chgQData(oldp+404,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_20),64);
            tracep->chgQData(oldp+406,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_21),64);
            tracep->chgQData(oldp+408,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_22),64);
            tracep->chgQData(oldp+410,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_23),64);
            tracep->chgQData(oldp+412,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_24),64);
            tracep->chgQData(oldp+414,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_25),64);
            tracep->chgQData(oldp+416,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_26),64);
            tracep->chgQData(oldp+418,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_27),64);
            tracep->chgQData(oldp+420,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_28),64);
            tracep->chgQData(oldp+422,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcounterinhibit),64);
            tracep->chgQData(oldp+424,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_0),64);
            tracep->chgQData(oldp+426,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_1),64);
            tracep->chgQData(oldp+428,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_2),64);
            tracep->chgQData(oldp+430,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_3),64);
            tracep->chgQData(oldp+432,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_4),64);
            tracep->chgQData(oldp+434,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_5),64);
            tracep->chgQData(oldp+436,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_6),64);
            tracep->chgQData(oldp+438,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_7),64);
            tracep->chgQData(oldp+440,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_8),64);
            tracep->chgQData(oldp+442,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_9),64);
            tracep->chgQData(oldp+444,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_10),64);
            tracep->chgQData(oldp+446,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_11),64);
            tracep->chgQData(oldp+448,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_12),64);
            tracep->chgQData(oldp+450,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_13),64);
            tracep->chgQData(oldp+452,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_14),64);
            tracep->chgQData(oldp+454,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_15),64);
            tracep->chgQData(oldp+456,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_16),64);
            tracep->chgQData(oldp+458,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_17),64);
            tracep->chgQData(oldp+460,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_18),64);
            tracep->chgQData(oldp+462,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_19),64);
            tracep->chgQData(oldp+464,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_20),64);
            tracep->chgQData(oldp+466,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_21),64);
            tracep->chgQData(oldp+468,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_22),64);
            tracep->chgQData(oldp+470,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_23),64);
            tracep->chgQData(oldp+472,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_24),64);
            tracep->chgQData(oldp+474,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_25),64);
            tracep->chgQData(oldp+476,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_26),64);
            tracep->chgQData(oldp+478,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_27),64);
            tracep->chgQData(oldp+480,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_28),64);
            tracep->chgSData(oldp+482,((0xfffU & (IData)(
                                                         (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                          >> 0x14U)))),12);
            tracep->chgCData(oldp+483,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op),3);
            tracep->chgBit(oldp+484,((3U == (3U & (IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                           >> 0x1eU))))));
            tracep->chgBit(oldp+485,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__write_illegal));
            tracep->chgBit(oldp+486,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_legal));
            tracep->chgBit(oldp+487,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__read_illegal));
            tracep->chgBit(oldp+488,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr));
            tracep->chgBit(oldp+489,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable));
            tracep->chgQData(oldp+490,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data),64);
            tracep->chgQData(oldp+492,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data),64);
            tracep->chgBit(oldp+494,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen));
            tracep->chgBit(oldp+495,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall));
            tracep->chgBit(oldp+496,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak));
            tracep->chgBit(oldp+497,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret));
            tracep->chgBit(oldp+498,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception));
            tracep->chgBit(oldp+499,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt));
            tracep->chgCData(oldp+500,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now),2);
        }
        tracep->chgBit(oldp+501,(vlTOPp->clock));
        tracep->chgBit(oldp+502,(vlTOPp->reset));
        tracep->chgQData(oldp+503,(vlTOPp->io_diffTestIO_regfile_0),64);
        tracep->chgQData(oldp+505,(vlTOPp->io_diffTestIO_regfile_1),64);
        tracep->chgQData(oldp+507,(vlTOPp->io_diffTestIO_regfile_2),64);
        tracep->chgQData(oldp+509,(vlTOPp->io_diffTestIO_regfile_3),64);
        tracep->chgQData(oldp+511,(vlTOPp->io_diffTestIO_regfile_4),64);
        tracep->chgQData(oldp+513,(vlTOPp->io_diffTestIO_regfile_5),64);
        tracep->chgQData(oldp+515,(vlTOPp->io_diffTestIO_regfile_6),64);
        tracep->chgQData(oldp+517,(vlTOPp->io_diffTestIO_regfile_7),64);
        tracep->chgQData(oldp+519,(vlTOPp->io_diffTestIO_regfile_8),64);
        tracep->chgQData(oldp+521,(vlTOPp->io_diffTestIO_regfile_9),64);
        tracep->chgQData(oldp+523,(vlTOPp->io_diffTestIO_regfile_10),64);
        tracep->chgQData(oldp+525,(vlTOPp->io_diffTestIO_regfile_11),64);
        tracep->chgQData(oldp+527,(vlTOPp->io_diffTestIO_regfile_12),64);
        tracep->chgQData(oldp+529,(vlTOPp->io_diffTestIO_regfile_13),64);
        tracep->chgQData(oldp+531,(vlTOPp->io_diffTestIO_regfile_14),64);
        tracep->chgQData(oldp+533,(vlTOPp->io_diffTestIO_regfile_15),64);
        tracep->chgQData(oldp+535,(vlTOPp->io_diffTestIO_regfile_16),64);
        tracep->chgQData(oldp+537,(vlTOPp->io_diffTestIO_regfile_17),64);
        tracep->chgQData(oldp+539,(vlTOPp->io_diffTestIO_regfile_18),64);
        tracep->chgQData(oldp+541,(vlTOPp->io_diffTestIO_regfile_19),64);
        tracep->chgQData(oldp+543,(vlTOPp->io_diffTestIO_regfile_20),64);
        tracep->chgQData(oldp+545,(vlTOPp->io_diffTestIO_regfile_21),64);
        tracep->chgQData(oldp+547,(vlTOPp->io_diffTestIO_regfile_22),64);
        tracep->chgQData(oldp+549,(vlTOPp->io_diffTestIO_regfile_23),64);
        tracep->chgQData(oldp+551,(vlTOPp->io_diffTestIO_regfile_24),64);
        tracep->chgQData(oldp+553,(vlTOPp->io_diffTestIO_regfile_25),64);
        tracep->chgQData(oldp+555,(vlTOPp->io_diffTestIO_regfile_26),64);
        tracep->chgQData(oldp+557,(vlTOPp->io_diffTestIO_regfile_27),64);
        tracep->chgQData(oldp+559,(vlTOPp->io_diffTestIO_regfile_28),64);
        tracep->chgQData(oldp+561,(vlTOPp->io_diffTestIO_regfile_29),64);
        tracep->chgQData(oldp+563,(vlTOPp->io_diffTestIO_regfile_30),64);
        tracep->chgQData(oldp+565,(vlTOPp->io_diffTestIO_regfile_31),64);
        tracep->chgQData(oldp+567,(vlTOPp->io_diffTestIO_pc),64);
        tracep->chgBit(oldp+569,(vlTOPp->io_diffTestIO_valid));
        tracep->chgQData(oldp+570,(vlTOPp->io_coreIO_inst_readIO_addr),64);
        tracep->chgQData(oldp+572,(vlTOPp->io_coreIO_inst_readIO_data),64);
        tracep->chgBit(oldp+574,(vlTOPp->io_coreIO_inst_readIO_en));
        tracep->chgQData(oldp+575,(vlTOPp->io_coreIO_data_readIO_addr),64);
        tracep->chgQData(oldp+577,(vlTOPp->io_coreIO_data_readIO_data),64);
        tracep->chgBit(oldp+579,(vlTOPp->io_coreIO_data_readIO_en));
        tracep->chgQData(oldp+580,(vlTOPp->io_coreIO_data_writeIO_addr),64);
        tracep->chgQData(oldp+582,(vlTOPp->io_coreIO_data_writeIO_data),64);
        tracep->chgBit(oldp+584,(vlTOPp->io_coreIO_data_writeIO_en));
        tracep->chgCData(oldp+585,(vlTOPp->io_coreIO_data_writeIO_mask),8);
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
