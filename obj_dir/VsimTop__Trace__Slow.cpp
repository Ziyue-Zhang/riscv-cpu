// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VsimTop__Syms.h"


//======================

void VsimTop::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void VsimTop::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VsimTop__Syms* __restrict vlSymsp = static_cast<VsimTop__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    VsimTop::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void VsimTop::traceInitTop(void* userp, VerilatedVcd* tracep) {
    VsimTop__Syms* __restrict vlSymsp = static_cast<VsimTop__Syms*>(userp);
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void VsimTop::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    VsimTop__Syms* __restrict vlSymsp = static_cast<VsimTop__Syms*>(userp);
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+232,"clock", false,-1);
        tracep->declBit(c+233,"reset", false,-1);
        tracep->declQuad(c+234,"io_diffTestIO_regfile_0", false,-1, 63,0);
        tracep->declQuad(c+236,"io_diffTestIO_regfile_1", false,-1, 63,0);
        tracep->declQuad(c+238,"io_diffTestIO_regfile_2", false,-1, 63,0);
        tracep->declQuad(c+240,"io_diffTestIO_regfile_3", false,-1, 63,0);
        tracep->declQuad(c+242,"io_diffTestIO_regfile_4", false,-1, 63,0);
        tracep->declQuad(c+244,"io_diffTestIO_regfile_5", false,-1, 63,0);
        tracep->declQuad(c+246,"io_diffTestIO_regfile_6", false,-1, 63,0);
        tracep->declQuad(c+248,"io_diffTestIO_regfile_7", false,-1, 63,0);
        tracep->declQuad(c+250,"io_diffTestIO_regfile_8", false,-1, 63,0);
        tracep->declQuad(c+252,"io_diffTestIO_regfile_9", false,-1, 63,0);
        tracep->declQuad(c+254,"io_diffTestIO_regfile_10", false,-1, 63,0);
        tracep->declQuad(c+256,"io_diffTestIO_regfile_11", false,-1, 63,0);
        tracep->declQuad(c+258,"io_diffTestIO_regfile_12", false,-1, 63,0);
        tracep->declQuad(c+260,"io_diffTestIO_regfile_13", false,-1, 63,0);
        tracep->declQuad(c+262,"io_diffTestIO_regfile_14", false,-1, 63,0);
        tracep->declQuad(c+264,"io_diffTestIO_regfile_15", false,-1, 63,0);
        tracep->declQuad(c+266,"io_diffTestIO_regfile_16", false,-1, 63,0);
        tracep->declQuad(c+268,"io_diffTestIO_regfile_17", false,-1, 63,0);
        tracep->declQuad(c+270,"io_diffTestIO_regfile_18", false,-1, 63,0);
        tracep->declQuad(c+272,"io_diffTestIO_regfile_19", false,-1, 63,0);
        tracep->declQuad(c+274,"io_diffTestIO_regfile_20", false,-1, 63,0);
        tracep->declQuad(c+276,"io_diffTestIO_regfile_21", false,-1, 63,0);
        tracep->declQuad(c+278,"io_diffTestIO_regfile_22", false,-1, 63,0);
        tracep->declQuad(c+280,"io_diffTestIO_regfile_23", false,-1, 63,0);
        tracep->declQuad(c+282,"io_diffTestIO_regfile_24", false,-1, 63,0);
        tracep->declQuad(c+284,"io_diffTestIO_regfile_25", false,-1, 63,0);
        tracep->declQuad(c+286,"io_diffTestIO_regfile_26", false,-1, 63,0);
        tracep->declQuad(c+288,"io_diffTestIO_regfile_27", false,-1, 63,0);
        tracep->declQuad(c+290,"io_diffTestIO_regfile_28", false,-1, 63,0);
        tracep->declQuad(c+292,"io_diffTestIO_regfile_29", false,-1, 63,0);
        tracep->declQuad(c+294,"io_diffTestIO_regfile_30", false,-1, 63,0);
        tracep->declQuad(c+296,"io_diffTestIO_regfile_31", false,-1, 63,0);
        tracep->declQuad(c+298,"io_diffTestIO_pc", false,-1, 63,0);
        tracep->declBit(c+300,"io_diffTestIO_valid", false,-1);
        tracep->declQuad(c+301,"io_coreIO_inst_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+303,"io_coreIO_inst_read_io_data", false,-1, 63,0);
        tracep->declBit(c+305,"io_coreIO_inst_read_io_en", false,-1);
        tracep->declQuad(c+306,"io_coreIO_data_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+308,"io_coreIO_data_read_io_data", false,-1, 63,0);
        tracep->declBit(c+310,"io_coreIO_data_read_io_en", false,-1);
        tracep->declQuad(c+311,"io_coreIO_data_write_io_addr", false,-1, 63,0);
        tracep->declQuad(c+313,"io_coreIO_data_write_io_data", false,-1, 63,0);
        tracep->declBit(c+315,"io_coreIO_data_write_io_en", false,-1);
        tracep->declBit(c+232,"simTop clock", false,-1);
        tracep->declBit(c+233,"simTop reset", false,-1);
        tracep->declQuad(c+234,"simTop io_diffTestIO_regfile_0", false,-1, 63,0);
        tracep->declQuad(c+236,"simTop io_diffTestIO_regfile_1", false,-1, 63,0);
        tracep->declQuad(c+238,"simTop io_diffTestIO_regfile_2", false,-1, 63,0);
        tracep->declQuad(c+240,"simTop io_diffTestIO_regfile_3", false,-1, 63,0);
        tracep->declQuad(c+242,"simTop io_diffTestIO_regfile_4", false,-1, 63,0);
        tracep->declQuad(c+244,"simTop io_diffTestIO_regfile_5", false,-1, 63,0);
        tracep->declQuad(c+246,"simTop io_diffTestIO_regfile_6", false,-1, 63,0);
        tracep->declQuad(c+248,"simTop io_diffTestIO_regfile_7", false,-1, 63,0);
        tracep->declQuad(c+250,"simTop io_diffTestIO_regfile_8", false,-1, 63,0);
        tracep->declQuad(c+252,"simTop io_diffTestIO_regfile_9", false,-1, 63,0);
        tracep->declQuad(c+254,"simTop io_diffTestIO_regfile_10", false,-1, 63,0);
        tracep->declQuad(c+256,"simTop io_diffTestIO_regfile_11", false,-1, 63,0);
        tracep->declQuad(c+258,"simTop io_diffTestIO_regfile_12", false,-1, 63,0);
        tracep->declQuad(c+260,"simTop io_diffTestIO_regfile_13", false,-1, 63,0);
        tracep->declQuad(c+262,"simTop io_diffTestIO_regfile_14", false,-1, 63,0);
        tracep->declQuad(c+264,"simTop io_diffTestIO_regfile_15", false,-1, 63,0);
        tracep->declQuad(c+266,"simTop io_diffTestIO_regfile_16", false,-1, 63,0);
        tracep->declQuad(c+268,"simTop io_diffTestIO_regfile_17", false,-1, 63,0);
        tracep->declQuad(c+270,"simTop io_diffTestIO_regfile_18", false,-1, 63,0);
        tracep->declQuad(c+272,"simTop io_diffTestIO_regfile_19", false,-1, 63,0);
        tracep->declQuad(c+274,"simTop io_diffTestIO_regfile_20", false,-1, 63,0);
        tracep->declQuad(c+276,"simTop io_diffTestIO_regfile_21", false,-1, 63,0);
        tracep->declQuad(c+278,"simTop io_diffTestIO_regfile_22", false,-1, 63,0);
        tracep->declQuad(c+280,"simTop io_diffTestIO_regfile_23", false,-1, 63,0);
        tracep->declQuad(c+282,"simTop io_diffTestIO_regfile_24", false,-1, 63,0);
        tracep->declQuad(c+284,"simTop io_diffTestIO_regfile_25", false,-1, 63,0);
        tracep->declQuad(c+286,"simTop io_diffTestIO_regfile_26", false,-1, 63,0);
        tracep->declQuad(c+288,"simTop io_diffTestIO_regfile_27", false,-1, 63,0);
        tracep->declQuad(c+290,"simTop io_diffTestIO_regfile_28", false,-1, 63,0);
        tracep->declQuad(c+292,"simTop io_diffTestIO_regfile_29", false,-1, 63,0);
        tracep->declQuad(c+294,"simTop io_diffTestIO_regfile_30", false,-1, 63,0);
        tracep->declQuad(c+296,"simTop io_diffTestIO_regfile_31", false,-1, 63,0);
        tracep->declQuad(c+298,"simTop io_diffTestIO_pc", false,-1, 63,0);
        tracep->declBit(c+300,"simTop io_diffTestIO_valid", false,-1);
        tracep->declQuad(c+301,"simTop io_coreIO_inst_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+303,"simTop io_coreIO_inst_read_io_data", false,-1, 63,0);
        tracep->declBit(c+305,"simTop io_coreIO_inst_read_io_en", false,-1);
        tracep->declQuad(c+306,"simTop io_coreIO_data_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+308,"simTop io_coreIO_data_read_io_data", false,-1, 63,0);
        tracep->declBit(c+310,"simTop io_coreIO_data_read_io_en", false,-1);
        tracep->declQuad(c+311,"simTop io_coreIO_data_write_io_addr", false,-1, 63,0);
        tracep->declQuad(c+313,"simTop io_coreIO_data_write_io_data", false,-1, 63,0);
        tracep->declBit(c+315,"simTop io_coreIO_data_write_io_en", false,-1);
        tracep->declBit(c+232,"simTop mycore_clock", false,-1);
        tracep->declBit(c+233,"simTop mycore_reset", false,-1);
        tracep->declQuad(c+1,"simTop mycore_io_inst_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+303,"simTop mycore_io_inst_read_io_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore_io_data_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+308,"simTop mycore_io_data_read_io_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore_io_data_write_io_addr", false,-1, 63,0);
        tracep->declQuad(c+5,"simTop mycore_io_data_write_io_data", false,-1, 63,0);
        tracep->declBit(c+7,"simTop mycore_wb_reg_valid", false,-1);
        tracep->declQuad(c+8,"simTop mycore__T_42_0", false,-1, 63,0);
        tracep->declQuad(c+10,"simTop mycore__T_42_1", false,-1, 63,0);
        tracep->declQuad(c+12,"simTop mycore__T_42_2", false,-1, 63,0);
        tracep->declQuad(c+14,"simTop mycore__T_42_3", false,-1, 63,0);
        tracep->declQuad(c+16,"simTop mycore__T_42_4", false,-1, 63,0);
        tracep->declQuad(c+18,"simTop mycore__T_42_5", false,-1, 63,0);
        tracep->declQuad(c+20,"simTop mycore__T_42_6", false,-1, 63,0);
        tracep->declQuad(c+22,"simTop mycore__T_42_7", false,-1, 63,0);
        tracep->declQuad(c+24,"simTop mycore__T_42_8", false,-1, 63,0);
        tracep->declQuad(c+26,"simTop mycore__T_42_9", false,-1, 63,0);
        tracep->declQuad(c+28,"simTop mycore__T_42_10", false,-1, 63,0);
        tracep->declQuad(c+30,"simTop mycore__T_42_11", false,-1, 63,0);
        tracep->declQuad(c+32,"simTop mycore__T_42_12", false,-1, 63,0);
        tracep->declQuad(c+34,"simTop mycore__T_42_13", false,-1, 63,0);
        tracep->declQuad(c+36,"simTop mycore__T_42_14", false,-1, 63,0);
        tracep->declQuad(c+38,"simTop mycore__T_42_15", false,-1, 63,0);
        tracep->declQuad(c+40,"simTop mycore__T_42_16", false,-1, 63,0);
        tracep->declQuad(c+42,"simTop mycore__T_42_17", false,-1, 63,0);
        tracep->declQuad(c+44,"simTop mycore__T_42_18", false,-1, 63,0);
        tracep->declQuad(c+46,"simTop mycore__T_42_19", false,-1, 63,0);
        tracep->declQuad(c+48,"simTop mycore__T_42_20", false,-1, 63,0);
        tracep->declQuad(c+50,"simTop mycore__T_42_21", false,-1, 63,0);
        tracep->declQuad(c+52,"simTop mycore__T_42_22", false,-1, 63,0);
        tracep->declQuad(c+54,"simTop mycore__T_42_23", false,-1, 63,0);
        tracep->declQuad(c+56,"simTop mycore__T_42_24", false,-1, 63,0);
        tracep->declQuad(c+58,"simTop mycore__T_42_25", false,-1, 63,0);
        tracep->declQuad(c+60,"simTop mycore__T_42_26", false,-1, 63,0);
        tracep->declQuad(c+62,"simTop mycore__T_42_27", false,-1, 63,0);
        tracep->declQuad(c+64,"simTop mycore__T_42_28", false,-1, 63,0);
        tracep->declQuad(c+66,"simTop mycore__T_42_29", false,-1, 63,0);
        tracep->declQuad(c+68,"simTop mycore__T_42_30", false,-1, 63,0);
        tracep->declQuad(c+70,"simTop mycore__T_42_31", false,-1, 63,0);
        tracep->declQuad(c+72,"simTop mycore_wb_reg_pc", false,-1, 63,0);
        tracep->declBit(c+232,"simTop mycore clock", false,-1);
        tracep->declBit(c+233,"simTop mycore reset", false,-1);
        tracep->declQuad(c+1,"simTop mycore io_inst_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+303,"simTop mycore io_inst_read_io_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore io_data_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+308,"simTop mycore io_data_read_io_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore io_data_write_io_addr", false,-1, 63,0);
        tracep->declQuad(c+5,"simTop mycore io_data_write_io_data", false,-1, 63,0);
        tracep->declBit(c+7,"simTop mycore wb_reg_valid", false,-1);
        tracep->declQuad(c+72,"simTop mycore wb_reg_pc", false,-1, 63,0);
        tracep->declBit(c+232,"simTop mycore cpath_clock", false,-1);
        tracep->declBit(c+233,"simTop mycore cpath_reset", false,-1);
        tracep->declQuad(c+74,"simTop mycore cpath_io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+76,"simTop mycore cpath_io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+77,"simTop mycore cpath_io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+78,"simTop mycore cpath_io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+79,"simTop mycore cpath_io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+80,"simTop mycore cpath_io_ctl_dec_stall", false,-1);
        tracep->declBus(c+81,"simTop mycore cpath_io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+82,"simTop mycore cpath_io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+83,"simTop mycore cpath_io_ctl_if_kill", false,-1);
        tracep->declBit(c+83,"simTop mycore cpath_io_ctl_dec_kill", false,-1);
        tracep->declBus(c+84,"simTop mycore cpath_io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+85,"simTop mycore cpath_io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+86,"simTop mycore cpath_io_ctl_alu_fun", false,-1, 3,0);
        tracep->declBus(c+87,"simTop mycore cpath_io_ctl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+88,"simTop mycore cpath_io_ctl_rf_wen", false,-1);
        tracep->declBit(c+232,"simTop mycore dpath_clock", false,-1);
        tracep->declBit(c+233,"simTop mycore dpath_reset", false,-1);
        tracep->declQuad(c+1,"simTop mycore dpath_io_inst_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+303,"simTop mycore dpath_io_inst_read_io_data", false,-1, 63,0);
        tracep->declBit(c+318,"simTop mycore dpath_io_inst_read_io_en", false,-1);
        tracep->declQuad(c+3,"simTop mycore dpath_io_data_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+308,"simTop mycore dpath_io_data_read_io_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore dpath_io_data_write_io_addr", false,-1, 63,0);
        tracep->declQuad(c+5,"simTop mycore dpath_io_data_write_io_data", false,-1, 63,0);
        tracep->declBit(c+80,"simTop mycore dpath_io_ctl_dec_stall", false,-1);
        tracep->declBus(c+81,"simTop mycore dpath_io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+82,"simTop mycore dpath_io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+83,"simTop mycore dpath_io_ctl_if_kill", false,-1);
        tracep->declBit(c+83,"simTop mycore dpath_io_ctl_dec_kill", false,-1);
        tracep->declBus(c+84,"simTop mycore dpath_io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+85,"simTop mycore dpath_io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+86,"simTop mycore dpath_io_ctl_alu_fun", false,-1, 3,0);
        tracep->declBus(c+87,"simTop mycore dpath_io_ctl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+88,"simTop mycore dpath_io_ctl_rf_wen", false,-1);
        tracep->declQuad(c+74,"simTop mycore dpath_io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+76,"simTop mycore dpath_io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+77,"simTop mycore dpath_io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+78,"simTop mycore dpath_io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+79,"simTop mycore dpath_io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+7,"simTop mycore dpath_wb_reg_valid_0", false,-1);
        tracep->declQuad(c+8,"simTop mycore dpath__T_42_0_0", false,-1, 63,0);
        tracep->declQuad(c+10,"simTop mycore dpath__T_42_0_1", false,-1, 63,0);
        tracep->declQuad(c+12,"simTop mycore dpath__T_42_0_2", false,-1, 63,0);
        tracep->declQuad(c+14,"simTop mycore dpath__T_42_0_3", false,-1, 63,0);
        tracep->declQuad(c+16,"simTop mycore dpath__T_42_0_4", false,-1, 63,0);
        tracep->declQuad(c+18,"simTop mycore dpath__T_42_0_5", false,-1, 63,0);
        tracep->declQuad(c+20,"simTop mycore dpath__T_42_0_6", false,-1, 63,0);
        tracep->declQuad(c+22,"simTop mycore dpath__T_42_0_7", false,-1, 63,0);
        tracep->declQuad(c+24,"simTop mycore dpath__T_42_0_8", false,-1, 63,0);
        tracep->declQuad(c+26,"simTop mycore dpath__T_42_0_9", false,-1, 63,0);
        tracep->declQuad(c+28,"simTop mycore dpath__T_42_0_10", false,-1, 63,0);
        tracep->declQuad(c+30,"simTop mycore dpath__T_42_0_11", false,-1, 63,0);
        tracep->declQuad(c+32,"simTop mycore dpath__T_42_0_12", false,-1, 63,0);
        tracep->declQuad(c+34,"simTop mycore dpath__T_42_0_13", false,-1, 63,0);
        tracep->declQuad(c+36,"simTop mycore dpath__T_42_0_14", false,-1, 63,0);
        tracep->declQuad(c+38,"simTop mycore dpath__T_42_0_15", false,-1, 63,0);
        tracep->declQuad(c+40,"simTop mycore dpath__T_42_0_16", false,-1, 63,0);
        tracep->declQuad(c+42,"simTop mycore dpath__T_42_0_17", false,-1, 63,0);
        tracep->declQuad(c+44,"simTop mycore dpath__T_42_0_18", false,-1, 63,0);
        tracep->declQuad(c+46,"simTop mycore dpath__T_42_0_19", false,-1, 63,0);
        tracep->declQuad(c+48,"simTop mycore dpath__T_42_0_20", false,-1, 63,0);
        tracep->declQuad(c+50,"simTop mycore dpath__T_42_0_21", false,-1, 63,0);
        tracep->declQuad(c+52,"simTop mycore dpath__T_42_0_22", false,-1, 63,0);
        tracep->declQuad(c+54,"simTop mycore dpath__T_42_0_23", false,-1, 63,0);
        tracep->declQuad(c+56,"simTop mycore dpath__T_42_0_24", false,-1, 63,0);
        tracep->declQuad(c+58,"simTop mycore dpath__T_42_0_25", false,-1, 63,0);
        tracep->declQuad(c+60,"simTop mycore dpath__T_42_0_26", false,-1, 63,0);
        tracep->declQuad(c+62,"simTop mycore dpath__T_42_0_27", false,-1, 63,0);
        tracep->declQuad(c+64,"simTop mycore dpath__T_42_0_28", false,-1, 63,0);
        tracep->declQuad(c+66,"simTop mycore dpath__T_42_0_29", false,-1, 63,0);
        tracep->declQuad(c+68,"simTop mycore dpath__T_42_0_30", false,-1, 63,0);
        tracep->declQuad(c+70,"simTop mycore dpath__T_42_0_31", false,-1, 63,0);
        tracep->declQuad(c+72,"simTop mycore dpath_wb_reg_pc_0", false,-1, 63,0);
        tracep->declBit(c+232,"simTop mycore cpath clock", false,-1);
        tracep->declBit(c+233,"simTop mycore cpath reset", false,-1);
        tracep->declQuad(c+74,"simTop mycore cpath io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+76,"simTop mycore cpath io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+77,"simTop mycore cpath io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+78,"simTop mycore cpath io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+79,"simTop mycore cpath io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+80,"simTop mycore cpath io_ctl_dec_stall", false,-1);
        tracep->declBus(c+81,"simTop mycore cpath io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+82,"simTop mycore cpath io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+83,"simTop mycore cpath io_ctl_if_kill", false,-1);
        tracep->declBit(c+83,"simTop mycore cpath io_ctl_dec_kill", false,-1);
        tracep->declBus(c+84,"simTop mycore cpath io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+85,"simTop mycore cpath io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+86,"simTop mycore cpath io_ctl_alu_fun", false,-1, 3,0);
        tracep->declBus(c+87,"simTop mycore cpath io_ctl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+88,"simTop mycore cpath io_ctl_rf_wen", false,-1);
        tracep->declBit(c+89,"simTop mycore cpath cs_rs1_oen", false,-1);
        tracep->declBit(c+90,"simTop mycore cpath cs_rs2_oen", false,-1);
        tracep->declBit(c+91,"simTop mycore cpath cs0_3", false,-1);
        tracep->declBit(c+92,"simTop mycore cpath cs0_4", false,-1);
        tracep->declBus(c+81,"simTop mycore cpath ctrl_exe_pc_sel", false,-1, 1,0);
        tracep->declBit(c+83,"simTop mycore cpath ifkill", false,-1);
        tracep->declBus(c+93,"simTop mycore cpath dec_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+94,"simTop mycore cpath dec_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+95,"simTop mycore cpath dec_wbaddr", false,-1, 4,0);
        tracep->declBit(c+96,"simTop mycore cpath dec_rs1_oen", false,-1);
        tracep->declBit(c+97,"simTop mycore cpath dec_rs2_oen", false,-1);
        tracep->declBus(c+98,"simTop mycore cpath exe_reg_wbaddr", false,-1, 4,0);
        tracep->declBit(c+99,"simTop mycore cpath exe_inst_is_load", false,-1);
        tracep->declBit(c+80,"simTop mycore cpath stall", false,-1);
        tracep->declBit(c+232,"simTop mycore dpath clock", false,-1);
        tracep->declBit(c+233,"simTop mycore dpath reset", false,-1);
        tracep->declQuad(c+1,"simTop mycore dpath io_inst_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+303,"simTop mycore dpath io_inst_read_io_data", false,-1, 63,0);
        tracep->declBit(c+318,"simTop mycore dpath io_inst_read_io_en", false,-1);
        tracep->declQuad(c+3,"simTop mycore dpath io_data_read_io_addr", false,-1, 63,0);
        tracep->declQuad(c+308,"simTop mycore dpath io_data_read_io_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore dpath io_data_write_io_addr", false,-1, 63,0);
        tracep->declQuad(c+5,"simTop mycore dpath io_data_write_io_data", false,-1, 63,0);
        tracep->declBit(c+80,"simTop mycore dpath io_ctl_dec_stall", false,-1);
        tracep->declBus(c+81,"simTop mycore dpath io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+82,"simTop mycore dpath io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+83,"simTop mycore dpath io_ctl_if_kill", false,-1);
        tracep->declBit(c+83,"simTop mycore dpath io_ctl_dec_kill", false,-1);
        tracep->declBus(c+84,"simTop mycore dpath io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+85,"simTop mycore dpath io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+86,"simTop mycore dpath io_ctl_alu_fun", false,-1, 3,0);
        tracep->declBus(c+87,"simTop mycore dpath io_ctl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+88,"simTop mycore dpath io_ctl_rf_wen", false,-1);
        tracep->declQuad(c+74,"simTop mycore dpath io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+76,"simTop mycore dpath io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+77,"simTop mycore dpath io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+78,"simTop mycore dpath io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+79,"simTop mycore dpath io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+7,"simTop mycore dpath wb_reg_valid_0", false,-1);
        tracep->declQuad(c+72,"simTop mycore dpath wb_reg_pc_0", false,-1, 63,0);
        tracep->declBit(c+232,"simTop mycore dpath regfile_clock", false,-1);
        tracep->declBus(c+93,"simTop mycore dpath regfile_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+100,"simTop mycore dpath regfile_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+94,"simTop mycore dpath regfile_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+102,"simTop mycore dpath regfile_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+104,"simTop mycore dpath regfile_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+105,"simTop mycore dpath regfile_io_wdata", false,-1, 63,0);
        tracep->declBit(c+107,"simTop mycore dpath regfile_io_wen", false,-1);
        tracep->declQuad(c+8,"simTop mycore dpath regfile__T_42_0_0", false,-1, 63,0);
        tracep->declQuad(c+10,"simTop mycore dpath regfile__T_42_0_1", false,-1, 63,0);
        tracep->declQuad(c+12,"simTop mycore dpath regfile__T_42_0_2", false,-1, 63,0);
        tracep->declQuad(c+14,"simTop mycore dpath regfile__T_42_0_3", false,-1, 63,0);
        tracep->declQuad(c+16,"simTop mycore dpath regfile__T_42_0_4", false,-1, 63,0);
        tracep->declQuad(c+18,"simTop mycore dpath regfile__T_42_0_5", false,-1, 63,0);
        tracep->declQuad(c+20,"simTop mycore dpath regfile__T_42_0_6", false,-1, 63,0);
        tracep->declQuad(c+22,"simTop mycore dpath regfile__T_42_0_7", false,-1, 63,0);
        tracep->declQuad(c+24,"simTop mycore dpath regfile__T_42_0_8", false,-1, 63,0);
        tracep->declQuad(c+26,"simTop mycore dpath regfile__T_42_0_9", false,-1, 63,0);
        tracep->declQuad(c+28,"simTop mycore dpath regfile__T_42_0_10", false,-1, 63,0);
        tracep->declQuad(c+30,"simTop mycore dpath regfile__T_42_0_11", false,-1, 63,0);
        tracep->declQuad(c+32,"simTop mycore dpath regfile__T_42_0_12", false,-1, 63,0);
        tracep->declQuad(c+34,"simTop mycore dpath regfile__T_42_0_13", false,-1, 63,0);
        tracep->declQuad(c+36,"simTop mycore dpath regfile__T_42_0_14", false,-1, 63,0);
        tracep->declQuad(c+38,"simTop mycore dpath regfile__T_42_0_15", false,-1, 63,0);
        tracep->declQuad(c+40,"simTop mycore dpath regfile__T_42_0_16", false,-1, 63,0);
        tracep->declQuad(c+42,"simTop mycore dpath regfile__T_42_0_17", false,-1, 63,0);
        tracep->declQuad(c+44,"simTop mycore dpath regfile__T_42_0_18", false,-1, 63,0);
        tracep->declQuad(c+46,"simTop mycore dpath regfile__T_42_0_19", false,-1, 63,0);
        tracep->declQuad(c+48,"simTop mycore dpath regfile__T_42_0_20", false,-1, 63,0);
        tracep->declQuad(c+50,"simTop mycore dpath regfile__T_42_0_21", false,-1, 63,0);
        tracep->declQuad(c+52,"simTop mycore dpath regfile__T_42_0_22", false,-1, 63,0);
        tracep->declQuad(c+54,"simTop mycore dpath regfile__T_42_0_23", false,-1, 63,0);
        tracep->declQuad(c+56,"simTop mycore dpath regfile__T_42_0_24", false,-1, 63,0);
        tracep->declQuad(c+58,"simTop mycore dpath regfile__T_42_0_25", false,-1, 63,0);
        tracep->declQuad(c+60,"simTop mycore dpath regfile__T_42_0_26", false,-1, 63,0);
        tracep->declQuad(c+62,"simTop mycore dpath regfile__T_42_0_27", false,-1, 63,0);
        tracep->declQuad(c+64,"simTop mycore dpath regfile__T_42_0_28", false,-1, 63,0);
        tracep->declQuad(c+66,"simTop mycore dpath regfile__T_42_0_29", false,-1, 63,0);
        tracep->declQuad(c+68,"simTop mycore dpath regfile__T_42_0_30", false,-1, 63,0);
        tracep->declQuad(c+70,"simTop mycore dpath regfile__T_42_0_31", false,-1, 63,0);
        tracep->declQuad(c+108,"simTop mycore dpath alu_io_src1", false,-1, 63,0);
        tracep->declQuad(c+110,"simTop mycore dpath alu_io_src2", false,-1, 63,0);
        tracep->declBus(c+112,"simTop mycore dpath alu_io_op", false,-1, 3,0);
        tracep->declQuad(c+113,"simTop mycore dpath alu_io_res", false,-1, 63,0);
        tracep->declQuad(c+1,"simTop mycore dpath if_reg_pc", false,-1, 63,0);
        tracep->declBit(c+115,"simTop mycore dpath dec_reg_valid", false,-1);
        tracep->declQuad(c+74,"simTop mycore dpath dec_reg_inst", false,-1, 63,0);
        tracep->declQuad(c+116,"simTop mycore dpath dec_reg_pc", false,-1, 63,0);
        tracep->declBit(c+118,"simTop mycore dpath exe_reg_valid", false,-1);
        tracep->declQuad(c+119,"simTop mycore dpath exe_reg_inst", false,-1, 63,0);
        tracep->declQuad(c+121,"simTop mycore dpath exe_reg_pc", false,-1, 63,0);
        tracep->declBus(c+123,"simTop mycore dpath exe_reg_wbaddr", false,-1, 4,0);
        tracep->declQuad(c+108,"simTop mycore dpath exe_alu_op1", false,-1, 63,0);
        tracep->declQuad(c+110,"simTop mycore dpath brjmp_offset", false,-1, 63,0);
        tracep->declQuad(c+124,"simTop mycore dpath exe_reg_rs2_data", false,-1, 63,0);
        tracep->declBus(c+79,"simTop mycore dpath exe_reg_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+112,"simTop mycore dpath exe_reg_ctrl_alu_fun", false,-1, 3,0);
        tracep->declBus(c+126,"simTop mycore dpath exe_reg_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+127,"simTop mycore dpath exe_reg_ctrl_rf_wen", false,-1);
        tracep->declBit(c+128,"simTop mycore dpath mem_reg_valid", false,-1);
        tracep->declQuad(c+129,"simTop mycore dpath mem_reg_pc", false,-1, 63,0);
        tracep->declQuad(c+131,"simTop mycore dpath mem_reg_inst", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore dpath mem_reg_alu_out", false,-1, 63,0);
        tracep->declBus(c+133,"simTop mycore dpath mem_reg_wbaddr", false,-1, 4,0);
        tracep->declQuad(c+5,"simTop mycore dpath mem_reg_rs2_data", false,-1, 63,0);
        tracep->declBit(c+134,"simTop mycore dpath mem_reg_ctrl_rf_wen", false,-1);
        tracep->declBus(c+135,"simTop mycore dpath mem_reg_ctrl_wb_sel", false,-1, 1,0);
        tracep->declBit(c+7,"simTop mycore dpath wb_reg_valid", false,-1);
        tracep->declQuad(c+72,"simTop mycore dpath wb_reg_pc", false,-1, 63,0);
        tracep->declBus(c+104,"simTop mycore dpath wb_reg_wbaddr", false,-1, 4,0);
        tracep->declQuad(c+105,"simTop mycore dpath wb_reg_wbdata", false,-1, 63,0);
        tracep->declBit(c+107,"simTop mycore dpath wb_reg_ctrl_rf_wen", false,-1);
        tracep->declQuad(c+136,"simTop mycore dpath if_pc_plus4", false,-1, 63,0);
        tracep->declQuad(c+138,"simTop mycore dpath exe_adder_out", false,-1, 63,0);
        tracep->declQuad(c+140,"simTop mycore dpath exe_brjmp_target", false,-1, 63,0);
        tracep->declQuad(c+142,"simTop mycore dpath if_reg_inst", false,-1, 63,0);
        tracep->declBus(c+93,"simTop mycore dpath dec_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+94,"simTop mycore dpath dec_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+95,"simTop mycore dpath dec_wbaddr", false,-1, 4,0);
        tracep->declBus(c+144,"simTop mycore dpath imm_itype", false,-1, 11,0);
        tracep->declBus(c+145,"simTop mycore dpath imm_stype", false,-1, 11,0);
        tracep->declBus(c+146,"simTop mycore dpath imm_sbtype", false,-1, 11,0);
        tracep->declBus(c+147,"simTop mycore dpath imm_utype", false,-1, 19,0);
        tracep->declBus(c+148,"simTop mycore dpath imm_ujtype", false,-1, 19,0);
        tracep->declBus(c+149,"simTop mycore dpath imm_z", false,-1, 31,0);
        tracep->declQuad(c+150,"simTop mycore dpath imm_itype_sext", false,-1, 63,0);
        tracep->declQuad(c+152,"simTop mycore dpath imm_stype_sext", false,-1, 63,0);
        tracep->declQuad(c+154,"simTop mycore dpath imm_sbtype_sext", false,-1, 63,0);
        tracep->declQuad(c+156,"simTop mycore dpath imm_utype_sext", false,-1, 63,0);
        tracep->declQuad(c+158,"simTop mycore dpath imm_ujtype_sext", false,-1, 63,0);
        tracep->declQuad(c+316,"simTop mycore dpath mem_wbdata", false,-1, 63,0);
        tracep->declQuad(c+113,"simTop mycore dpath exe_alu_out", false,-1, 63,0);
        tracep->declQuad(c+160,"simTop mycore dpath exe_pc_plus4", false,-1, 63,0);
        tracep->declBit(c+232,"simTop mycore dpath regfile clock", false,-1);
        tracep->declBus(c+93,"simTop mycore dpath regfile io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+100,"simTop mycore dpath regfile io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+94,"simTop mycore dpath regfile io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+102,"simTop mycore dpath regfile io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+104,"simTop mycore dpath regfile io_waddr", false,-1, 4,0);
        tracep->declQuad(c+105,"simTop mycore dpath regfile io_wdata", false,-1, 63,0);
        tracep->declBit(c+107,"simTop mycore dpath regfile io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+162+i*2,"simTop mycore dpath regfile regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+226,"simTop mycore dpath regfile regfile__T_1_data", false,-1, 63,0);
        tracep->declBus(c+93,"simTop mycore dpath regfile regfile__T_1_addr", false,-1, 4,0);
        tracep->declQuad(c+228,"simTop mycore dpath regfile regfile__T_4_data", false,-1, 63,0);
        tracep->declBus(c+94,"simTop mycore dpath regfile regfile__T_4_addr", false,-1, 4,0);
        tracep->declQuad(c+8,"simTop mycore dpath regfile regfile__T_10_data", false,-1, 63,0);
        tracep->declBus(c+319,"simTop mycore dpath regfile regfile__T_10_addr", false,-1, 4,0);
        tracep->declQuad(c+10,"simTop mycore dpath regfile regfile__T_11_data", false,-1, 63,0);
        tracep->declBus(c+320,"simTop mycore dpath regfile regfile__T_11_addr", false,-1, 4,0);
        tracep->declQuad(c+12,"simTop mycore dpath regfile regfile__T_12_data", false,-1, 63,0);
        tracep->declBus(c+321,"simTop mycore dpath regfile regfile__T_12_addr", false,-1, 4,0);
        tracep->declQuad(c+14,"simTop mycore dpath regfile regfile__T_13_data", false,-1, 63,0);
        tracep->declBus(c+322,"simTop mycore dpath regfile regfile__T_13_addr", false,-1, 4,0);
        tracep->declQuad(c+16,"simTop mycore dpath regfile regfile__T_14_data", false,-1, 63,0);
        tracep->declBus(c+323,"simTop mycore dpath regfile regfile__T_14_addr", false,-1, 4,0);
        tracep->declQuad(c+18,"simTop mycore dpath regfile regfile__T_15_data", false,-1, 63,0);
        tracep->declBus(c+324,"simTop mycore dpath regfile regfile__T_15_addr", false,-1, 4,0);
        tracep->declQuad(c+20,"simTop mycore dpath regfile regfile__T_16_data", false,-1, 63,0);
        tracep->declBus(c+325,"simTop mycore dpath regfile regfile__T_16_addr", false,-1, 4,0);
        tracep->declQuad(c+22,"simTop mycore dpath regfile regfile__T_17_data", false,-1, 63,0);
        tracep->declBus(c+326,"simTop mycore dpath regfile regfile__T_17_addr", false,-1, 4,0);
        tracep->declQuad(c+24,"simTop mycore dpath regfile regfile__T_18_data", false,-1, 63,0);
        tracep->declBus(c+327,"simTop mycore dpath regfile regfile__T_18_addr", false,-1, 4,0);
        tracep->declQuad(c+26,"simTop mycore dpath regfile regfile__T_19_data", false,-1, 63,0);
        tracep->declBus(c+328,"simTop mycore dpath regfile regfile__T_19_addr", false,-1, 4,0);
        tracep->declQuad(c+28,"simTop mycore dpath regfile regfile__T_20_data", false,-1, 63,0);
        tracep->declBus(c+329,"simTop mycore dpath regfile regfile__T_20_addr", false,-1, 4,0);
        tracep->declQuad(c+30,"simTop mycore dpath regfile regfile__T_21_data", false,-1, 63,0);
        tracep->declBus(c+330,"simTop mycore dpath regfile regfile__T_21_addr", false,-1, 4,0);
        tracep->declQuad(c+32,"simTop mycore dpath regfile regfile__T_22_data", false,-1, 63,0);
        tracep->declBus(c+331,"simTop mycore dpath regfile regfile__T_22_addr", false,-1, 4,0);
        tracep->declQuad(c+34,"simTop mycore dpath regfile regfile__T_23_data", false,-1, 63,0);
        tracep->declBus(c+332,"simTop mycore dpath regfile regfile__T_23_addr", false,-1, 4,0);
        tracep->declQuad(c+36,"simTop mycore dpath regfile regfile__T_24_data", false,-1, 63,0);
        tracep->declBus(c+333,"simTop mycore dpath regfile regfile__T_24_addr", false,-1, 4,0);
        tracep->declQuad(c+38,"simTop mycore dpath regfile regfile__T_25_data", false,-1, 63,0);
        tracep->declBus(c+334,"simTop mycore dpath regfile regfile__T_25_addr", false,-1, 4,0);
        tracep->declQuad(c+40,"simTop mycore dpath regfile regfile__T_26_data", false,-1, 63,0);
        tracep->declBus(c+335,"simTop mycore dpath regfile regfile__T_26_addr", false,-1, 4,0);
        tracep->declQuad(c+42,"simTop mycore dpath regfile regfile__T_27_data", false,-1, 63,0);
        tracep->declBus(c+336,"simTop mycore dpath regfile regfile__T_27_addr", false,-1, 4,0);
        tracep->declQuad(c+44,"simTop mycore dpath regfile regfile__T_28_data", false,-1, 63,0);
        tracep->declBus(c+337,"simTop mycore dpath regfile regfile__T_28_addr", false,-1, 4,0);
        tracep->declQuad(c+46,"simTop mycore dpath regfile regfile__T_29_data", false,-1, 63,0);
        tracep->declBus(c+338,"simTop mycore dpath regfile regfile__T_29_addr", false,-1, 4,0);
        tracep->declQuad(c+48,"simTop mycore dpath regfile regfile__T_30_data", false,-1, 63,0);
        tracep->declBus(c+339,"simTop mycore dpath regfile regfile__T_30_addr", false,-1, 4,0);
        tracep->declQuad(c+50,"simTop mycore dpath regfile regfile__T_31_data", false,-1, 63,0);
        tracep->declBus(c+340,"simTop mycore dpath regfile regfile__T_31_addr", false,-1, 4,0);
        tracep->declQuad(c+52,"simTop mycore dpath regfile regfile__T_32_data", false,-1, 63,0);
        tracep->declBus(c+341,"simTop mycore dpath regfile regfile__T_32_addr", false,-1, 4,0);
        tracep->declQuad(c+54,"simTop mycore dpath regfile regfile__T_33_data", false,-1, 63,0);
        tracep->declBus(c+342,"simTop mycore dpath regfile regfile__T_33_addr", false,-1, 4,0);
        tracep->declQuad(c+56,"simTop mycore dpath regfile regfile__T_34_data", false,-1, 63,0);
        tracep->declBus(c+343,"simTop mycore dpath regfile regfile__T_34_addr", false,-1, 4,0);
        tracep->declQuad(c+58,"simTop mycore dpath regfile regfile__T_35_data", false,-1, 63,0);
        tracep->declBus(c+344,"simTop mycore dpath regfile regfile__T_35_addr", false,-1, 4,0);
        tracep->declQuad(c+60,"simTop mycore dpath regfile regfile__T_36_data", false,-1, 63,0);
        tracep->declBus(c+345,"simTop mycore dpath regfile regfile__T_36_addr", false,-1, 4,0);
        tracep->declQuad(c+62,"simTop mycore dpath regfile regfile__T_37_data", false,-1, 63,0);
        tracep->declBus(c+346,"simTop mycore dpath regfile regfile__T_37_addr", false,-1, 4,0);
        tracep->declQuad(c+64,"simTop mycore dpath regfile regfile__T_38_data", false,-1, 63,0);
        tracep->declBus(c+347,"simTop mycore dpath regfile regfile__T_38_addr", false,-1, 4,0);
        tracep->declQuad(c+66,"simTop mycore dpath regfile regfile__T_39_data", false,-1, 63,0);
        tracep->declBus(c+348,"simTop mycore dpath regfile regfile__T_39_addr", false,-1, 4,0);
        tracep->declQuad(c+68,"simTop mycore dpath regfile regfile__T_40_data", false,-1, 63,0);
        tracep->declBus(c+349,"simTop mycore dpath regfile regfile__T_40_addr", false,-1, 4,0);
        tracep->declQuad(c+70,"simTop mycore dpath regfile regfile__T_41_data", false,-1, 63,0);
        tracep->declBus(c+350,"simTop mycore dpath regfile regfile__T_41_addr", false,-1, 4,0);
        tracep->declQuad(c+105,"simTop mycore dpath regfile regfile__T_9_data", false,-1, 63,0);
        tracep->declBus(c+104,"simTop mycore dpath regfile regfile__T_9_addr", false,-1, 4,0);
        tracep->declBit(c+318,"simTop mycore dpath regfile regfile__T_9_mask", false,-1);
        tracep->declBit(c+230,"simTop mycore dpath regfile regfile__T_9_en", false,-1);
        tracep->declQuad(c+108,"simTop mycore dpath alu io_src1", false,-1, 63,0);
        tracep->declQuad(c+110,"simTop mycore dpath alu io_src2", false,-1, 63,0);
        tracep->declBus(c+112,"simTop mycore dpath alu io_op", false,-1, 3,0);
        tracep->declQuad(c+113,"simTop mycore dpath alu io_res", false,-1, 63,0);
        tracep->declBus(c+231,"simTop mycore dpath alu shamt", false,-1, 5,0);
    }
}

void VsimTop::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void VsimTop::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    VsimTop__Syms* __restrict vlSymsp = static_cast<VsimTop__Syms*>(userp);
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void VsimTop::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    VsimTop__Syms* __restrict vlSymsp = static_cast<VsimTop__Syms*>(userp);
    VsimTop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc),64);
        tracep->fullQData(oldp+3,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out),64);
        tracep->fullQData(oldp+5,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_rs2_data),64);
        tracep->fullBit(oldp+7,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid));
        tracep->fullQData(oldp+8,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                  [0U]),64);
        tracep->fullQData(oldp+10,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [1U]),64);
        tracep->fullQData(oldp+12,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [2U]),64);
        tracep->fullQData(oldp+14,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [3U]),64);
        tracep->fullQData(oldp+16,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [4U]),64);
        tracep->fullQData(oldp+18,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [5U]),64);
        tracep->fullQData(oldp+20,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [6U]),64);
        tracep->fullQData(oldp+22,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [7U]),64);
        tracep->fullQData(oldp+24,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [8U]),64);
        tracep->fullQData(oldp+26,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [9U]),64);
        tracep->fullQData(oldp+28,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xaU]),64);
        tracep->fullQData(oldp+30,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xbU]),64);
        tracep->fullQData(oldp+32,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xcU]),64);
        tracep->fullQData(oldp+34,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xdU]),64);
        tracep->fullQData(oldp+36,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xeU]),64);
        tracep->fullQData(oldp+38,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xfU]),64);
        tracep->fullQData(oldp+40,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x10U]),64);
        tracep->fullQData(oldp+42,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x11U]),64);
        tracep->fullQData(oldp+44,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x12U]),64);
        tracep->fullQData(oldp+46,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x13U]),64);
        tracep->fullQData(oldp+48,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x14U]),64);
        tracep->fullQData(oldp+50,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x15U]),64);
        tracep->fullQData(oldp+52,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x16U]),64);
        tracep->fullQData(oldp+54,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x17U]),64);
        tracep->fullQData(oldp+56,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x18U]),64);
        tracep->fullQData(oldp+58,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x19U]),64);
        tracep->fullQData(oldp+60,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1aU]),64);
        tracep->fullQData(oldp+62,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1bU]),64);
        tracep->fullQData(oldp+64,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1cU]),64);
        tracep->fullQData(oldp+66,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1dU]),64);
        tracep->fullQData(oldp+68,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1eU]),64);
        tracep->fullQData(oldp+70,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1fU]),64);
        tracep->fullQData(oldp+72,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc),64);
        tracep->fullQData(oldp+74,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst),64);
        tracep->fullBit(oldp+76,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq));
        tracep->fullBit(oldp+77,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt));
        tracep->fullBit(oldp+78,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu));
        tracep->fullCData(oldp+79,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type),4);
        tracep->fullBit(oldp+80,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall));
        tracep->fullCData(oldp+81,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel),2);
        tracep->fullCData(oldp+82,(((0x2003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 0U : ((3ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                              ? 0U : 
                                             ((0x4003ULL 
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
                                                      : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_139))))))))),4);
        tracep->fullBit(oldp+83,((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))));
        tracep->fullCData(oldp+84,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel),2);
        tracep->fullCData(oldp+85,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel),3);
        tracep->fullCData(oldp+86,(((0x2003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 0U : ((3ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                              ? 0U : 
                                             ((0x4003ULL 
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
        tracep->fullCData(oldp+87,(((0x2003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_361))),2);
        tracep->fullBit(oldp+88,(((0x2003ULL == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                  | ((3ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((0x4003ULL 
                                         == (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        | ((0x1003ULL 
                                            == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           | ((0x5003ULL 
                                               == (0x707fULL 
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
        tracep->fullBit(oldp+89,(((0x2003ULL == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                  | ((3ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((0x4003ULL 
                                         == (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        | ((0x1003ULL 
                                            == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           | ((0x5003ULL 
                                               == (0x707fULL 
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
        tracep->fullBit(oldp+90,(((0x2003ULL != (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                  & ((3ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     & ((0x4003ULL 
                                         != (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        & ((0x1003ULL 
                                            != (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           & ((0x5003ULL 
                                               != (0x707fULL 
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
        tracep->fullBit(oldp+91,(((0x2003ULL == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                  | ((3ULL == (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((0x4003ULL 
                                         == (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        | ((0x1003ULL 
                                            == (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           | ((0x5003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                              | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_429))))))));
        tracep->fullBit(oldp+92,(((0x2003ULL != (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                  & ((3ULL != (0x707fULL 
                                               & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     & ((0x4003ULL 
                                         != (0x707fULL 
                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                        & ((0x1003ULL 
                                            != (0x707fULL 
                                                & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                           & ((0x5003ULL 
                                               != (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                              & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_429))))))));
        tracep->fullCData(oldp+93,((0x1fU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                     >> 0xfU)))),5);
        tracep->fullCData(oldp+94,((0x1fU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                     >> 0x14U)))),5);
        tracep->fullCData(oldp+95,((0x1fU & (IData)(
                                                    (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                     >> 7U)))),5);
        tracep->fullBit(oldp+96,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                                  & ((0x2003ULL == 
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
                                                                            | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_240))))))))))))))))));
        tracep->fullBit(oldp+97,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                                  & ((0x2003ULL != 
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
                                                                            & (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_276))))))))))))))))));
        tracep->fullCData(oldp+98,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr),5);
        tracep->fullBit(oldp+99,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load));
        tracep->fullQData(oldp+100,(((0U != (0x1fU 
                                             & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0xfU))))
                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                     [(0x1fU & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                        >> 0xfU)))]
                                      : 0ULL)),64);
        tracep->fullQData(oldp+102,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data),64);
        tracep->fullCData(oldp+104,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr),5);
        tracep->fullQData(oldp+105,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata),64);
        tracep->fullBit(oldp+107,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
        tracep->fullQData(oldp+108,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1),64);
        tracep->fullQData(oldp+110,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset),64);
        tracep->fullCData(oldp+112,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun),4);
        tracep->fullQData(oldp+113,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res),64);
        tracep->fullBit(oldp+115,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid));
        tracep->fullQData(oldp+116,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc),64);
        tracep->fullBit(oldp+118,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid));
        tracep->fullQData(oldp+119,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst),64);
        tracep->fullQData(oldp+121,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc),64);
        tracep->fullCData(oldp+123,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr),5);
        tracep->fullQData(oldp+124,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data),64);
        tracep->fullCData(oldp+126,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel),2);
        tracep->fullBit(oldp+127,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
        tracep->fullBit(oldp+128,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid));
        tracep->fullQData(oldp+129,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc),64);
        tracep->fullQData(oldp+131,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst),64);
        tracep->fullCData(oldp+133,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr),5);
        tracep->fullBit(oldp+134,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
        tracep->fullCData(oldp+135,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel),2);
        tracep->fullQData(oldp+136,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)),64);
        tracep->fullQData(oldp+138,((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                     + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)),64);
        tracep->fullQData(oldp+140,((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
                                     + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)),64);
        tracep->fullQData(oldp+142,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_inst),64);
        tracep->fullSData(oldp+144,((0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0x14U)))),12);
        tracep->fullSData(oldp+145,(((0xfe0U & ((IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0x19U)) 
                                                << 5U)) 
                                     | (0x1fU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 7U))))),12);
        tracep->fullSData(oldp+146,(((0x800U & ((IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0x1fU)) 
                                                << 0xbU)) 
                                     | ((0x400U & ((IData)(
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
        tracep->fullIData(oldp+147,((0xfffffU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0xcU)))),20);
        tracep->fullIData(oldp+148,(((0x80000U & ((IData)(
                                                          (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                           >> 0x1fU)) 
                                                  << 0x13U)) 
                                     | ((0x7f800U & 
                                         ((IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
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
        tracep->fullIData(oldp+149,((0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0xfU)))),32);
        tracep->fullQData(oldp+150,(((((1U & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0x1fU)))
                                        ? 0xfffffffffffffULL
                                        : 0ULL) << 0xcU) 
                                     | (QData)((IData)(
                                                       (0xfffU 
                                                        & (IData)(
                                                                  (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                   >> 0x14U))))))),64);
        tracep->fullQData(oldp+152,(((((1U & (IData)(
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
                                                                      >> 7U)))))))),64);
        tracep->fullQData(oldp+154,(((((1U & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0x1fU)))
                                        ? 0x7ffffffffffffULL
                                        : 0ULL) << 0xdU) 
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
                                                                    << 1U))))))))),64);
        tracep->fullQData(oldp+156,((((QData)((IData)(
                                                      ((1U 
                                                        & (IData)(
                                                                  (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                   >> 0x1fU)))
                                                        ? 0xffffffffU
                                                        : 0U))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (0xfffff000U 
                                                                   & ((IData)(
                                                                              (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                               >> 0xcU)) 
                                                                      << 0xcU)))))),64);
        tracep->fullQData(oldp+158,(((((1U & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0x1fU)))
                                        ? 0x7ffffffffffULL
                                        : 0ULL) << 0x15U) 
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
        tracep->fullQData(oldp+160,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)),64);
        tracep->fullQData(oldp+162,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[0]),64);
        tracep->fullQData(oldp+164,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[1]),64);
        tracep->fullQData(oldp+166,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[2]),64);
        tracep->fullQData(oldp+168,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[3]),64);
        tracep->fullQData(oldp+170,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[4]),64);
        tracep->fullQData(oldp+172,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[5]),64);
        tracep->fullQData(oldp+174,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[6]),64);
        tracep->fullQData(oldp+176,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[7]),64);
        tracep->fullQData(oldp+178,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[8]),64);
        tracep->fullQData(oldp+180,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[9]),64);
        tracep->fullQData(oldp+182,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[10]),64);
        tracep->fullQData(oldp+184,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[11]),64);
        tracep->fullQData(oldp+186,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[12]),64);
        tracep->fullQData(oldp+188,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[13]),64);
        tracep->fullQData(oldp+190,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[14]),64);
        tracep->fullQData(oldp+192,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[15]),64);
        tracep->fullQData(oldp+194,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[16]),64);
        tracep->fullQData(oldp+196,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[17]),64);
        tracep->fullQData(oldp+198,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[18]),64);
        tracep->fullQData(oldp+200,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[19]),64);
        tracep->fullQData(oldp+202,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[20]),64);
        tracep->fullQData(oldp+204,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[21]),64);
        tracep->fullQData(oldp+206,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[22]),64);
        tracep->fullQData(oldp+208,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[23]),64);
        tracep->fullQData(oldp+210,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[24]),64);
        tracep->fullQData(oldp+212,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[25]),64);
        tracep->fullQData(oldp+214,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[26]),64);
        tracep->fullQData(oldp+216,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[27]),64);
        tracep->fullQData(oldp+218,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[28]),64);
        tracep->fullQData(oldp+220,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[29]),64);
        tracep->fullQData(oldp+222,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[30]),64);
        tracep->fullQData(oldp+224,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[31]),64);
        tracep->fullQData(oldp+226,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                    [(0x1fU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0xfU)))]),64);
        tracep->fullQData(oldp+228,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                    [(0x1fU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0x14U)))]),64);
        tracep->fullBit(oldp+230,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen) 
                                   & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr)))));
        tracep->fullCData(oldp+231,((0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))),6);
        tracep->fullBit(oldp+232,(vlTOPp->clock));
        tracep->fullBit(oldp+233,(vlTOPp->reset));
        tracep->fullQData(oldp+234,(vlTOPp->io_diffTestIO_regfile_0),64);
        tracep->fullQData(oldp+236,(vlTOPp->io_diffTestIO_regfile_1),64);
        tracep->fullQData(oldp+238,(vlTOPp->io_diffTestIO_regfile_2),64);
        tracep->fullQData(oldp+240,(vlTOPp->io_diffTestIO_regfile_3),64);
        tracep->fullQData(oldp+242,(vlTOPp->io_diffTestIO_regfile_4),64);
        tracep->fullQData(oldp+244,(vlTOPp->io_diffTestIO_regfile_5),64);
        tracep->fullQData(oldp+246,(vlTOPp->io_diffTestIO_regfile_6),64);
        tracep->fullQData(oldp+248,(vlTOPp->io_diffTestIO_regfile_7),64);
        tracep->fullQData(oldp+250,(vlTOPp->io_diffTestIO_regfile_8),64);
        tracep->fullQData(oldp+252,(vlTOPp->io_diffTestIO_regfile_9),64);
        tracep->fullQData(oldp+254,(vlTOPp->io_diffTestIO_regfile_10),64);
        tracep->fullQData(oldp+256,(vlTOPp->io_diffTestIO_regfile_11),64);
        tracep->fullQData(oldp+258,(vlTOPp->io_diffTestIO_regfile_12),64);
        tracep->fullQData(oldp+260,(vlTOPp->io_diffTestIO_regfile_13),64);
        tracep->fullQData(oldp+262,(vlTOPp->io_diffTestIO_regfile_14),64);
        tracep->fullQData(oldp+264,(vlTOPp->io_diffTestIO_regfile_15),64);
        tracep->fullQData(oldp+266,(vlTOPp->io_diffTestIO_regfile_16),64);
        tracep->fullQData(oldp+268,(vlTOPp->io_diffTestIO_regfile_17),64);
        tracep->fullQData(oldp+270,(vlTOPp->io_diffTestIO_regfile_18),64);
        tracep->fullQData(oldp+272,(vlTOPp->io_diffTestIO_regfile_19),64);
        tracep->fullQData(oldp+274,(vlTOPp->io_diffTestIO_regfile_20),64);
        tracep->fullQData(oldp+276,(vlTOPp->io_diffTestIO_regfile_21),64);
        tracep->fullQData(oldp+278,(vlTOPp->io_diffTestIO_regfile_22),64);
        tracep->fullQData(oldp+280,(vlTOPp->io_diffTestIO_regfile_23),64);
        tracep->fullQData(oldp+282,(vlTOPp->io_diffTestIO_regfile_24),64);
        tracep->fullQData(oldp+284,(vlTOPp->io_diffTestIO_regfile_25),64);
        tracep->fullQData(oldp+286,(vlTOPp->io_diffTestIO_regfile_26),64);
        tracep->fullQData(oldp+288,(vlTOPp->io_diffTestIO_regfile_27),64);
        tracep->fullQData(oldp+290,(vlTOPp->io_diffTestIO_regfile_28),64);
        tracep->fullQData(oldp+292,(vlTOPp->io_diffTestIO_regfile_29),64);
        tracep->fullQData(oldp+294,(vlTOPp->io_diffTestIO_regfile_30),64);
        tracep->fullQData(oldp+296,(vlTOPp->io_diffTestIO_regfile_31),64);
        tracep->fullQData(oldp+298,(vlTOPp->io_diffTestIO_pc),64);
        tracep->fullBit(oldp+300,(vlTOPp->io_diffTestIO_valid));
        tracep->fullQData(oldp+301,(vlTOPp->io_coreIO_inst_read_io_addr),64);
        tracep->fullQData(oldp+303,(vlTOPp->io_coreIO_inst_read_io_data),64);
        tracep->fullBit(oldp+305,(vlTOPp->io_coreIO_inst_read_io_en));
        tracep->fullQData(oldp+306,(vlTOPp->io_coreIO_data_read_io_addr),64);
        tracep->fullQData(oldp+308,(vlTOPp->io_coreIO_data_read_io_data),64);
        tracep->fullBit(oldp+310,(vlTOPp->io_coreIO_data_read_io_en));
        tracep->fullQData(oldp+311,(vlTOPp->io_coreIO_data_write_io_addr),64);
        tracep->fullQData(oldp+313,(vlTOPp->io_coreIO_data_write_io_data),64);
        tracep->fullBit(oldp+315,(vlTOPp->io_coreIO_data_write_io_en));
        tracep->fullQData(oldp+316,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                                      : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                          ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out
                                          : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                              ? vlTOPp->io_coreIO_data_read_io_data
                                              : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)))),64);
        tracep->fullBit(oldp+318,(1U));
        tracep->fullCData(oldp+319,(0U),5);
        tracep->fullCData(oldp+320,(1U),5);
        tracep->fullCData(oldp+321,(2U),5);
        tracep->fullCData(oldp+322,(3U),5);
        tracep->fullCData(oldp+323,(4U),5);
        tracep->fullCData(oldp+324,(5U),5);
        tracep->fullCData(oldp+325,(6U),5);
        tracep->fullCData(oldp+326,(7U),5);
        tracep->fullCData(oldp+327,(8U),5);
        tracep->fullCData(oldp+328,(9U),5);
        tracep->fullCData(oldp+329,(0xaU),5);
        tracep->fullCData(oldp+330,(0xbU),5);
        tracep->fullCData(oldp+331,(0xcU),5);
        tracep->fullCData(oldp+332,(0xdU),5);
        tracep->fullCData(oldp+333,(0xeU),5);
        tracep->fullCData(oldp+334,(0xfU),5);
        tracep->fullCData(oldp+335,(0x10U),5);
        tracep->fullCData(oldp+336,(0x11U),5);
        tracep->fullCData(oldp+337,(0x12U),5);
        tracep->fullCData(oldp+338,(0x13U),5);
        tracep->fullCData(oldp+339,(0x14U),5);
        tracep->fullCData(oldp+340,(0x15U),5);
        tracep->fullCData(oldp+341,(0x16U),5);
        tracep->fullCData(oldp+342,(0x17U),5);
        tracep->fullCData(oldp+343,(0x18U),5);
        tracep->fullCData(oldp+344,(0x19U),5);
        tracep->fullCData(oldp+345,(0x1aU),5);
        tracep->fullCData(oldp+346,(0x1bU),5);
        tracep->fullCData(oldp+347,(0x1cU),5);
        tracep->fullCData(oldp+348,(0x1dU),5);
        tracep->fullCData(oldp+349,(0x1eU),5);
        tracep->fullCData(oldp+350,(0x1fU),5);
    }
}
