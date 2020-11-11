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
        tracep->declBit(c+502,"clock", false,-1);
        tracep->declBit(c+503,"reset", false,-1);
        tracep->declQuad(c+504,"io_diffTestIO_regfile_0", false,-1, 63,0);
        tracep->declQuad(c+506,"io_diffTestIO_regfile_1", false,-1, 63,0);
        tracep->declQuad(c+508,"io_diffTestIO_regfile_2", false,-1, 63,0);
        tracep->declQuad(c+510,"io_diffTestIO_regfile_3", false,-1, 63,0);
        tracep->declQuad(c+512,"io_diffTestIO_regfile_4", false,-1, 63,0);
        tracep->declQuad(c+514,"io_diffTestIO_regfile_5", false,-1, 63,0);
        tracep->declQuad(c+516,"io_diffTestIO_regfile_6", false,-1, 63,0);
        tracep->declQuad(c+518,"io_diffTestIO_regfile_7", false,-1, 63,0);
        tracep->declQuad(c+520,"io_diffTestIO_regfile_8", false,-1, 63,0);
        tracep->declQuad(c+522,"io_diffTestIO_regfile_9", false,-1, 63,0);
        tracep->declQuad(c+524,"io_diffTestIO_regfile_10", false,-1, 63,0);
        tracep->declQuad(c+526,"io_diffTestIO_regfile_11", false,-1, 63,0);
        tracep->declQuad(c+528,"io_diffTestIO_regfile_12", false,-1, 63,0);
        tracep->declQuad(c+530,"io_diffTestIO_regfile_13", false,-1, 63,0);
        tracep->declQuad(c+532,"io_diffTestIO_regfile_14", false,-1, 63,0);
        tracep->declQuad(c+534,"io_diffTestIO_regfile_15", false,-1, 63,0);
        tracep->declQuad(c+536,"io_diffTestIO_regfile_16", false,-1, 63,0);
        tracep->declQuad(c+538,"io_diffTestIO_regfile_17", false,-1, 63,0);
        tracep->declQuad(c+540,"io_diffTestIO_regfile_18", false,-1, 63,0);
        tracep->declQuad(c+542,"io_diffTestIO_regfile_19", false,-1, 63,0);
        tracep->declQuad(c+544,"io_diffTestIO_regfile_20", false,-1, 63,0);
        tracep->declQuad(c+546,"io_diffTestIO_regfile_21", false,-1, 63,0);
        tracep->declQuad(c+548,"io_diffTestIO_regfile_22", false,-1, 63,0);
        tracep->declQuad(c+550,"io_diffTestIO_regfile_23", false,-1, 63,0);
        tracep->declQuad(c+552,"io_diffTestIO_regfile_24", false,-1, 63,0);
        tracep->declQuad(c+554,"io_diffTestIO_regfile_25", false,-1, 63,0);
        tracep->declQuad(c+556,"io_diffTestIO_regfile_26", false,-1, 63,0);
        tracep->declQuad(c+558,"io_diffTestIO_regfile_27", false,-1, 63,0);
        tracep->declQuad(c+560,"io_diffTestIO_regfile_28", false,-1, 63,0);
        tracep->declQuad(c+562,"io_diffTestIO_regfile_29", false,-1, 63,0);
        tracep->declQuad(c+564,"io_diffTestIO_regfile_30", false,-1, 63,0);
        tracep->declQuad(c+566,"io_diffTestIO_regfile_31", false,-1, 63,0);
        tracep->declQuad(c+568,"io_diffTestIO_pc", false,-1, 63,0);
        tracep->declBit(c+570,"io_diffTestIO_valid", false,-1);
        tracep->declQuad(c+571,"io_coreIO_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+573,"io_coreIO_inst_readIO_data", false,-1, 63,0);
        tracep->declBit(c+575,"io_coreIO_inst_readIO_en", false,-1);
        tracep->declQuad(c+576,"io_coreIO_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+578,"io_coreIO_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+580,"io_coreIO_data_readIO_en", false,-1);
        tracep->declQuad(c+581,"io_coreIO_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+583,"io_coreIO_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+585,"io_coreIO_data_writeIO_en", false,-1);
        tracep->declBus(c+586,"io_coreIO_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+502,"simTop clock", false,-1);
        tracep->declBit(c+503,"simTop reset", false,-1);
        tracep->declQuad(c+504,"simTop io_diffTestIO_regfile_0", false,-1, 63,0);
        tracep->declQuad(c+506,"simTop io_diffTestIO_regfile_1", false,-1, 63,0);
        tracep->declQuad(c+508,"simTop io_diffTestIO_regfile_2", false,-1, 63,0);
        tracep->declQuad(c+510,"simTop io_diffTestIO_regfile_3", false,-1, 63,0);
        tracep->declQuad(c+512,"simTop io_diffTestIO_regfile_4", false,-1, 63,0);
        tracep->declQuad(c+514,"simTop io_diffTestIO_regfile_5", false,-1, 63,0);
        tracep->declQuad(c+516,"simTop io_diffTestIO_regfile_6", false,-1, 63,0);
        tracep->declQuad(c+518,"simTop io_diffTestIO_regfile_7", false,-1, 63,0);
        tracep->declQuad(c+520,"simTop io_diffTestIO_regfile_8", false,-1, 63,0);
        tracep->declQuad(c+522,"simTop io_diffTestIO_regfile_9", false,-1, 63,0);
        tracep->declQuad(c+524,"simTop io_diffTestIO_regfile_10", false,-1, 63,0);
        tracep->declQuad(c+526,"simTop io_diffTestIO_regfile_11", false,-1, 63,0);
        tracep->declQuad(c+528,"simTop io_diffTestIO_regfile_12", false,-1, 63,0);
        tracep->declQuad(c+530,"simTop io_diffTestIO_regfile_13", false,-1, 63,0);
        tracep->declQuad(c+532,"simTop io_diffTestIO_regfile_14", false,-1, 63,0);
        tracep->declQuad(c+534,"simTop io_diffTestIO_regfile_15", false,-1, 63,0);
        tracep->declQuad(c+536,"simTop io_diffTestIO_regfile_16", false,-1, 63,0);
        tracep->declQuad(c+538,"simTop io_diffTestIO_regfile_17", false,-1, 63,0);
        tracep->declQuad(c+540,"simTop io_diffTestIO_regfile_18", false,-1, 63,0);
        tracep->declQuad(c+542,"simTop io_diffTestIO_regfile_19", false,-1, 63,0);
        tracep->declQuad(c+544,"simTop io_diffTestIO_regfile_20", false,-1, 63,0);
        tracep->declQuad(c+546,"simTop io_diffTestIO_regfile_21", false,-1, 63,0);
        tracep->declQuad(c+548,"simTop io_diffTestIO_regfile_22", false,-1, 63,0);
        tracep->declQuad(c+550,"simTop io_diffTestIO_regfile_23", false,-1, 63,0);
        tracep->declQuad(c+552,"simTop io_diffTestIO_regfile_24", false,-1, 63,0);
        tracep->declQuad(c+554,"simTop io_diffTestIO_regfile_25", false,-1, 63,0);
        tracep->declQuad(c+556,"simTop io_diffTestIO_regfile_26", false,-1, 63,0);
        tracep->declQuad(c+558,"simTop io_diffTestIO_regfile_27", false,-1, 63,0);
        tracep->declQuad(c+560,"simTop io_diffTestIO_regfile_28", false,-1, 63,0);
        tracep->declQuad(c+562,"simTop io_diffTestIO_regfile_29", false,-1, 63,0);
        tracep->declQuad(c+564,"simTop io_diffTestIO_regfile_30", false,-1, 63,0);
        tracep->declQuad(c+566,"simTop io_diffTestIO_regfile_31", false,-1, 63,0);
        tracep->declQuad(c+568,"simTop io_diffTestIO_pc", false,-1, 63,0);
        tracep->declBit(c+570,"simTop io_diffTestIO_valid", false,-1);
        tracep->declQuad(c+571,"simTop io_coreIO_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+573,"simTop io_coreIO_inst_readIO_data", false,-1, 63,0);
        tracep->declBit(c+575,"simTop io_coreIO_inst_readIO_en", false,-1);
        tracep->declQuad(c+576,"simTop io_coreIO_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+578,"simTop io_coreIO_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+580,"simTop io_coreIO_data_readIO_en", false,-1);
        tracep->declQuad(c+581,"simTop io_coreIO_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+583,"simTop io_coreIO_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+585,"simTop io_coreIO_data_writeIO_en", false,-1);
        tracep->declBus(c+586,"simTop io_coreIO_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+502,"simTop mycore_clock", false,-1);
        tracep->declBit(c+503,"simTop mycore_reset", false,-1);
        tracep->declQuad(c+1,"simTop mycore_io_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+573,"simTop mycore_io_inst_readIO_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore_io_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+578,"simTop mycore_io_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+5,"simTop mycore_io_data_readIO_en", false,-1);
        tracep->declQuad(c+3,"simTop mycore_io_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+6,"simTop mycore_io_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+8,"simTop mycore_io_data_writeIO_en", false,-1);
        tracep->declBus(c+9,"simTop mycore_io_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+10,"simTop mycore_wb_reg_valid", false,-1);
        tracep->declQuad(c+11,"simTop mycore__T_42_0", false,-1, 63,0);
        tracep->declQuad(c+13,"simTop mycore__T_42_1", false,-1, 63,0);
        tracep->declQuad(c+15,"simTop mycore__T_42_2", false,-1, 63,0);
        tracep->declQuad(c+17,"simTop mycore__T_42_3", false,-1, 63,0);
        tracep->declQuad(c+19,"simTop mycore__T_42_4", false,-1, 63,0);
        tracep->declQuad(c+21,"simTop mycore__T_42_5", false,-1, 63,0);
        tracep->declQuad(c+23,"simTop mycore__T_42_6", false,-1, 63,0);
        tracep->declQuad(c+25,"simTop mycore__T_42_7", false,-1, 63,0);
        tracep->declQuad(c+27,"simTop mycore__T_42_8", false,-1, 63,0);
        tracep->declQuad(c+29,"simTop mycore__T_42_9", false,-1, 63,0);
        tracep->declQuad(c+31,"simTop mycore__T_42_10", false,-1, 63,0);
        tracep->declQuad(c+33,"simTop mycore__T_42_11", false,-1, 63,0);
        tracep->declQuad(c+35,"simTop mycore__T_42_12", false,-1, 63,0);
        tracep->declQuad(c+37,"simTop mycore__T_42_13", false,-1, 63,0);
        tracep->declQuad(c+39,"simTop mycore__T_42_14", false,-1, 63,0);
        tracep->declQuad(c+41,"simTop mycore__T_42_15", false,-1, 63,0);
        tracep->declQuad(c+43,"simTop mycore__T_42_16", false,-1, 63,0);
        tracep->declQuad(c+45,"simTop mycore__T_42_17", false,-1, 63,0);
        tracep->declQuad(c+47,"simTop mycore__T_42_18", false,-1, 63,0);
        tracep->declQuad(c+49,"simTop mycore__T_42_19", false,-1, 63,0);
        tracep->declQuad(c+51,"simTop mycore__T_42_20", false,-1, 63,0);
        tracep->declQuad(c+53,"simTop mycore__T_42_21", false,-1, 63,0);
        tracep->declQuad(c+55,"simTop mycore__T_42_22", false,-1, 63,0);
        tracep->declQuad(c+57,"simTop mycore__T_42_23", false,-1, 63,0);
        tracep->declQuad(c+59,"simTop mycore__T_42_24", false,-1, 63,0);
        tracep->declQuad(c+61,"simTop mycore__T_42_25", false,-1, 63,0);
        tracep->declQuad(c+63,"simTop mycore__T_42_26", false,-1, 63,0);
        tracep->declQuad(c+65,"simTop mycore__T_42_27", false,-1, 63,0);
        tracep->declQuad(c+67,"simTop mycore__T_42_28", false,-1, 63,0);
        tracep->declQuad(c+69,"simTop mycore__T_42_29", false,-1, 63,0);
        tracep->declQuad(c+71,"simTop mycore__T_42_30", false,-1, 63,0);
        tracep->declQuad(c+73,"simTop mycore__T_42_31", false,-1, 63,0);
        tracep->declQuad(c+75,"simTop mycore_wb_reg_pc", false,-1, 63,0);
        tracep->declBit(c+502,"simTop mycore clock", false,-1);
        tracep->declBit(c+503,"simTop mycore reset", false,-1);
        tracep->declQuad(c+1,"simTop mycore io_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+573,"simTop mycore io_inst_readIO_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore io_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+578,"simTop mycore io_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+5,"simTop mycore io_data_readIO_en", false,-1);
        tracep->declQuad(c+3,"simTop mycore io_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+6,"simTop mycore io_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+8,"simTop mycore io_data_writeIO_en", false,-1);
        tracep->declBus(c+9,"simTop mycore io_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+10,"simTop mycore wb_reg_valid", false,-1);
        tracep->declQuad(c+75,"simTop mycore wb_reg_pc", false,-1, 63,0);
        tracep->declBit(c+502,"simTop mycore cpath_clock", false,-1);
        tracep->declBit(c+503,"simTop mycore cpath_reset", false,-1);
        tracep->declQuad(c+77,"simTop mycore cpath_io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+79,"simTop mycore cpath_io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+80,"simTop mycore cpath_io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+81,"simTop mycore cpath_io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+82,"simTop mycore cpath_io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+83,"simTop mycore cpath_io_dat_csr_eret", false,-1);
        tracep->declBit(c+84,"simTop mycore cpath_io_ctl_dec_stall", false,-1);
        tracep->declBus(c+85,"simTop mycore cpath_io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+86,"simTop mycore cpath_io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+87,"simTop mycore cpath_io_ctl_if_kill", false,-1);
        tracep->declBit(c+88,"simTop mycore cpath_io_ctl_dec_kill", false,-1);
        tracep->declBus(c+89,"simTop mycore cpath_io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+90,"simTop mycore cpath_io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+91,"simTop mycore cpath_io_ctl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+92,"simTop mycore cpath_io_ctl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+93,"simTop mycore cpath_io_ctl_rf_wen", false,-1);
        tracep->declBus(c+94,"simTop mycore cpath_io_ctl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+95,"simTop mycore cpath_io_ctl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+96,"simTop mycore cpath_io_ctl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+97,"simTop mycore cpath_io_ctl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+98,"simTop mycore cpath_io_ctl_fencei", false,-1);
        tracep->declBit(c+83,"simTop mycore cpath_io_ctl_pipeline_kill", false,-1);
        tracep->declBit(c+502,"simTop mycore dpath_clock", false,-1);
        tracep->declBit(c+503,"simTop mycore dpath_reset", false,-1);
        tracep->declBit(c+84,"simTop mycore dpath_io_ctl_dec_stall", false,-1);
        tracep->declBus(c+85,"simTop mycore dpath_io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+86,"simTop mycore dpath_io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+87,"simTop mycore dpath_io_ctl_if_kill", false,-1);
        tracep->declBit(c+88,"simTop mycore dpath_io_ctl_dec_kill", false,-1);
        tracep->declBus(c+89,"simTop mycore dpath_io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+90,"simTop mycore dpath_io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+91,"simTop mycore dpath_io_ctl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+92,"simTop mycore dpath_io_ctl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+93,"simTop mycore dpath_io_ctl_rf_wen", false,-1);
        tracep->declBus(c+94,"simTop mycore dpath_io_ctl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+95,"simTop mycore dpath_io_ctl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+96,"simTop mycore dpath_io_ctl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+97,"simTop mycore dpath_io_ctl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+98,"simTop mycore dpath_io_ctl_fencei", false,-1);
        tracep->declBit(c+83,"simTop mycore dpath_io_ctl_pipeline_kill", false,-1);
        tracep->declQuad(c+77,"simTop mycore dpath_io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+79,"simTop mycore dpath_io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+80,"simTop mycore dpath_io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+81,"simTop mycore dpath_io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+82,"simTop mycore dpath_io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+83,"simTop mycore dpath_io_dat_csr_eret", false,-1);
        tracep->declQuad(c+1,"simTop mycore dpath_io_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+573,"simTop mycore dpath_io_inst_readIO_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore dpath_io_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+578,"simTop mycore dpath_io_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+5,"simTop mycore dpath_io_data_readIO_en", false,-1);
        tracep->declQuad(c+3,"simTop mycore dpath_io_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+6,"simTop mycore dpath_io_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+8,"simTop mycore dpath_io_data_writeIO_en", false,-1);
        tracep->declBus(c+9,"simTop mycore dpath_io_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+10,"simTop mycore dpath_wb_reg_valid_0", false,-1);
        tracep->declQuad(c+11,"simTop mycore dpath__T_42_0_0", false,-1, 63,0);
        tracep->declQuad(c+13,"simTop mycore dpath__T_42_0_1", false,-1, 63,0);
        tracep->declQuad(c+15,"simTop mycore dpath__T_42_0_2", false,-1, 63,0);
        tracep->declQuad(c+17,"simTop mycore dpath__T_42_0_3", false,-1, 63,0);
        tracep->declQuad(c+19,"simTop mycore dpath__T_42_0_4", false,-1, 63,0);
        tracep->declQuad(c+21,"simTop mycore dpath__T_42_0_5", false,-1, 63,0);
        tracep->declQuad(c+23,"simTop mycore dpath__T_42_0_6", false,-1, 63,0);
        tracep->declQuad(c+25,"simTop mycore dpath__T_42_0_7", false,-1, 63,0);
        tracep->declQuad(c+27,"simTop mycore dpath__T_42_0_8", false,-1, 63,0);
        tracep->declQuad(c+29,"simTop mycore dpath__T_42_0_9", false,-1, 63,0);
        tracep->declQuad(c+31,"simTop mycore dpath__T_42_0_10", false,-1, 63,0);
        tracep->declQuad(c+33,"simTop mycore dpath__T_42_0_11", false,-1, 63,0);
        tracep->declQuad(c+35,"simTop mycore dpath__T_42_0_12", false,-1, 63,0);
        tracep->declQuad(c+37,"simTop mycore dpath__T_42_0_13", false,-1, 63,0);
        tracep->declQuad(c+39,"simTop mycore dpath__T_42_0_14", false,-1, 63,0);
        tracep->declQuad(c+41,"simTop mycore dpath__T_42_0_15", false,-1, 63,0);
        tracep->declQuad(c+43,"simTop mycore dpath__T_42_0_16", false,-1, 63,0);
        tracep->declQuad(c+45,"simTop mycore dpath__T_42_0_17", false,-1, 63,0);
        tracep->declQuad(c+47,"simTop mycore dpath__T_42_0_18", false,-1, 63,0);
        tracep->declQuad(c+49,"simTop mycore dpath__T_42_0_19", false,-1, 63,0);
        tracep->declQuad(c+51,"simTop mycore dpath__T_42_0_20", false,-1, 63,0);
        tracep->declQuad(c+53,"simTop mycore dpath__T_42_0_21", false,-1, 63,0);
        tracep->declQuad(c+55,"simTop mycore dpath__T_42_0_22", false,-1, 63,0);
        tracep->declQuad(c+57,"simTop mycore dpath__T_42_0_23", false,-1, 63,0);
        tracep->declQuad(c+59,"simTop mycore dpath__T_42_0_24", false,-1, 63,0);
        tracep->declQuad(c+61,"simTop mycore dpath__T_42_0_25", false,-1, 63,0);
        tracep->declQuad(c+63,"simTop mycore dpath__T_42_0_26", false,-1, 63,0);
        tracep->declQuad(c+65,"simTop mycore dpath__T_42_0_27", false,-1, 63,0);
        tracep->declQuad(c+67,"simTop mycore dpath__T_42_0_28", false,-1, 63,0);
        tracep->declQuad(c+69,"simTop mycore dpath__T_42_0_29", false,-1, 63,0);
        tracep->declQuad(c+71,"simTop mycore dpath__T_42_0_30", false,-1, 63,0);
        tracep->declQuad(c+73,"simTop mycore dpath__T_42_0_31", false,-1, 63,0);
        tracep->declQuad(c+75,"simTop mycore dpath_wb_reg_pc_0", false,-1, 63,0);
        tracep->declBit(c+502,"simTop mycore cpath clock", false,-1);
        tracep->declBit(c+503,"simTop mycore cpath reset", false,-1);
        tracep->declQuad(c+77,"simTop mycore cpath io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+79,"simTop mycore cpath io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+80,"simTop mycore cpath io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+81,"simTop mycore cpath io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+82,"simTop mycore cpath io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+83,"simTop mycore cpath io_dat_csr_eret", false,-1);
        tracep->declBit(c+84,"simTop mycore cpath io_ctl_dec_stall", false,-1);
        tracep->declBus(c+85,"simTop mycore cpath io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+86,"simTop mycore cpath io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+87,"simTop mycore cpath io_ctl_if_kill", false,-1);
        tracep->declBit(c+88,"simTop mycore cpath io_ctl_dec_kill", false,-1);
        tracep->declBus(c+89,"simTop mycore cpath io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+90,"simTop mycore cpath io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+91,"simTop mycore cpath io_ctl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+92,"simTop mycore cpath io_ctl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+93,"simTop mycore cpath io_ctl_rf_wen", false,-1);
        tracep->declBus(c+94,"simTop mycore cpath io_ctl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+95,"simTop mycore cpath io_ctl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+96,"simTop mycore cpath io_ctl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+97,"simTop mycore cpath io_ctl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+98,"simTop mycore cpath io_ctl_fencei", false,-1);
        tracep->declBit(c+83,"simTop mycore cpath io_ctl_pipeline_kill", false,-1);
        tracep->declBit(c+99,"simTop mycore cpath cs_rs1_oen", false,-1);
        tracep->declBit(c+100,"simTop mycore cpath cs_rs2_oen", false,-1);
        tracep->declBit(c+101,"simTop mycore cpath cs0_3", false,-1);
        tracep->declBus(c+94,"simTop mycore cpath cs0_4", false,-1, 1,0);
        tracep->declBus(c+102,"simTop mycore cpath cs0_7", false,-1, 2,0);
        tracep->declBit(c+103,"simTop mycore cpath cs0_8", false,-1);
        tracep->declBus(c+85,"simTop mycore cpath ctrl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+104,"simTop mycore cpath dec_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+105,"simTop mycore cpath dec_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+106,"simTop mycore cpath dec_wbaddr", false,-1, 4,0);
        tracep->declBit(c+107,"simTop mycore cpath dec_rs1_oen", false,-1);
        tracep->declBit(c+108,"simTop mycore cpath dec_rs2_oen", false,-1);
        tracep->declBus(c+109,"simTop mycore cpath exe_reg_wbaddr", false,-1, 4,0);
        tracep->declBit(c+110,"simTop mycore cpath exe_reg_is_csr", false,-1);
        tracep->declBit(c+111,"simTop mycore cpath exe_inst_is_load", false,-1);
        tracep->declBit(c+84,"simTop mycore cpath stall", false,-1);
        tracep->declBit(c+502,"simTop mycore dpath clock", false,-1);
        tracep->declBit(c+503,"simTop mycore dpath reset", false,-1);
        tracep->declBit(c+84,"simTop mycore dpath io_ctl_dec_stall", false,-1);
        tracep->declBus(c+85,"simTop mycore dpath io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+86,"simTop mycore dpath io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+87,"simTop mycore dpath io_ctl_if_kill", false,-1);
        tracep->declBit(c+88,"simTop mycore dpath io_ctl_dec_kill", false,-1);
        tracep->declBus(c+89,"simTop mycore dpath io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+90,"simTop mycore dpath io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+91,"simTop mycore dpath io_ctl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+92,"simTop mycore dpath io_ctl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+93,"simTop mycore dpath io_ctl_rf_wen", false,-1);
        tracep->declBus(c+94,"simTop mycore dpath io_ctl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+95,"simTop mycore dpath io_ctl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+96,"simTop mycore dpath io_ctl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+97,"simTop mycore dpath io_ctl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+98,"simTop mycore dpath io_ctl_fencei", false,-1);
        tracep->declBit(c+83,"simTop mycore dpath io_ctl_pipeline_kill", false,-1);
        tracep->declQuad(c+77,"simTop mycore dpath io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+79,"simTop mycore dpath io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+80,"simTop mycore dpath io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+81,"simTop mycore dpath io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+82,"simTop mycore dpath io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+83,"simTop mycore dpath io_dat_csr_eret", false,-1);
        tracep->declQuad(c+1,"simTop mycore dpath io_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+573,"simTop mycore dpath io_inst_readIO_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore dpath io_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+578,"simTop mycore dpath io_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+5,"simTop mycore dpath io_data_readIO_en", false,-1);
        tracep->declQuad(c+3,"simTop mycore dpath io_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+6,"simTop mycore dpath io_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+8,"simTop mycore dpath io_data_writeIO_en", false,-1);
        tracep->declBus(c+9,"simTop mycore dpath io_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+10,"simTop mycore dpath wb_reg_valid_0", false,-1);
        tracep->declQuad(c+75,"simTop mycore dpath wb_reg_pc_0", false,-1, 63,0);
        tracep->declBit(c+502,"simTop mycore dpath regfile_clock", false,-1);
        tracep->declBus(c+104,"simTop mycore dpath regfile_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+112,"simTop mycore dpath regfile_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+105,"simTop mycore dpath regfile_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"simTop mycore dpath regfile_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+116,"simTop mycore dpath regfile_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+117,"simTop mycore dpath regfile_io_wdata", false,-1, 63,0);
        tracep->declBit(c+119,"simTop mycore dpath regfile_io_wen", false,-1);
        tracep->declQuad(c+11,"simTop mycore dpath regfile__T_42_0_0", false,-1, 63,0);
        tracep->declQuad(c+13,"simTop mycore dpath regfile__T_42_0_1", false,-1, 63,0);
        tracep->declQuad(c+15,"simTop mycore dpath regfile__T_42_0_2", false,-1, 63,0);
        tracep->declQuad(c+17,"simTop mycore dpath regfile__T_42_0_3", false,-1, 63,0);
        tracep->declQuad(c+19,"simTop mycore dpath regfile__T_42_0_4", false,-1, 63,0);
        tracep->declQuad(c+21,"simTop mycore dpath regfile__T_42_0_5", false,-1, 63,0);
        tracep->declQuad(c+23,"simTop mycore dpath regfile__T_42_0_6", false,-1, 63,0);
        tracep->declQuad(c+25,"simTop mycore dpath regfile__T_42_0_7", false,-1, 63,0);
        tracep->declQuad(c+27,"simTop mycore dpath regfile__T_42_0_8", false,-1, 63,0);
        tracep->declQuad(c+29,"simTop mycore dpath regfile__T_42_0_9", false,-1, 63,0);
        tracep->declQuad(c+31,"simTop mycore dpath regfile__T_42_0_10", false,-1, 63,0);
        tracep->declQuad(c+33,"simTop mycore dpath regfile__T_42_0_11", false,-1, 63,0);
        tracep->declQuad(c+35,"simTop mycore dpath regfile__T_42_0_12", false,-1, 63,0);
        tracep->declQuad(c+37,"simTop mycore dpath regfile__T_42_0_13", false,-1, 63,0);
        tracep->declQuad(c+39,"simTop mycore dpath regfile__T_42_0_14", false,-1, 63,0);
        tracep->declQuad(c+41,"simTop mycore dpath regfile__T_42_0_15", false,-1, 63,0);
        tracep->declQuad(c+43,"simTop mycore dpath regfile__T_42_0_16", false,-1, 63,0);
        tracep->declQuad(c+45,"simTop mycore dpath regfile__T_42_0_17", false,-1, 63,0);
        tracep->declQuad(c+47,"simTop mycore dpath regfile__T_42_0_18", false,-1, 63,0);
        tracep->declQuad(c+49,"simTop mycore dpath regfile__T_42_0_19", false,-1, 63,0);
        tracep->declQuad(c+51,"simTop mycore dpath regfile__T_42_0_20", false,-1, 63,0);
        tracep->declQuad(c+53,"simTop mycore dpath regfile__T_42_0_21", false,-1, 63,0);
        tracep->declQuad(c+55,"simTop mycore dpath regfile__T_42_0_22", false,-1, 63,0);
        tracep->declQuad(c+57,"simTop mycore dpath regfile__T_42_0_23", false,-1, 63,0);
        tracep->declQuad(c+59,"simTop mycore dpath regfile__T_42_0_24", false,-1, 63,0);
        tracep->declQuad(c+61,"simTop mycore dpath regfile__T_42_0_25", false,-1, 63,0);
        tracep->declQuad(c+63,"simTop mycore dpath regfile__T_42_0_26", false,-1, 63,0);
        tracep->declQuad(c+65,"simTop mycore dpath regfile__T_42_0_27", false,-1, 63,0);
        tracep->declQuad(c+67,"simTop mycore dpath regfile__T_42_0_28", false,-1, 63,0);
        tracep->declQuad(c+69,"simTop mycore dpath regfile__T_42_0_29", false,-1, 63,0);
        tracep->declQuad(c+71,"simTop mycore dpath regfile__T_42_0_30", false,-1, 63,0);
        tracep->declQuad(c+73,"simTop mycore dpath regfile__T_42_0_31", false,-1, 63,0);
        tracep->declBit(c+502,"simTop mycore dpath alu_clock", false,-1);
        tracep->declBit(c+503,"simTop mycore dpath alu_reset", false,-1);
        tracep->declQuad(c+120,"simTop mycore dpath alu_io_src1", false,-1, 63,0);
        tracep->declQuad(c+122,"simTop mycore dpath alu_io_src2", false,-1, 63,0);
        tracep->declBus(c+124,"simTop mycore dpath alu_io_op", false,-1, 4,0);
        tracep->declQuad(c+125,"simTop mycore dpath alu_io_res", false,-1, 63,0);
        tracep->declBit(c+127,"simTop mycore dpath alu_io_stall", false,-1);
        tracep->declBit(c+502,"simTop mycore dpath csr_clock", false,-1);
        tracep->declBit(c+503,"simTop mycore dpath csr_reset", false,-1);
        tracep->declBus(c+128,"simTop mycore dpath csr_io_inst", false,-1, 31,0);
        tracep->declBus(c+129,"simTop mycore dpath csr_io_csr_op", false,-1, 2,0);
        tracep->declQuad(c+130,"simTop mycore dpath csr_io_data_in", false,-1, 63,0);
        tracep->declBit(c+127,"simTop mycore dpath csr_io_has_stall", false,-1);
        tracep->declQuad(c+132,"simTop mycore dpath csr_io_in_mem_pc", false,-1, 63,0);
        tracep->declQuad(c+134,"simTop mycore dpath csr_io_in_exe_pc", false,-1, 63,0);
        tracep->declQuad(c+136,"simTop mycore dpath csr_io_in_dec_pc", false,-1, 63,0);
        tracep->declQuad(c+1,"simTop mycore dpath csr_io_in_if_pc", false,-1, 63,0);
        tracep->declBit(c+83,"simTop mycore dpath csr_io_is_redir", false,-1);
        tracep->declQuad(c+1,"simTop mycore dpath if_reg_pc", false,-1, 63,0);
        tracep->declBit(c+138,"simTop mycore dpath dec_reg_valid", false,-1);
        tracep->declQuad(c+77,"simTop mycore dpath dec_reg_inst", false,-1, 63,0);
        tracep->declQuad(c+136,"simTop mycore dpath dec_reg_pc", false,-1, 63,0);
        tracep->declBit(c+139,"simTop mycore dpath exe_reg_valid", false,-1);
        tracep->declQuad(c+140,"simTop mycore dpath exe_reg_inst", false,-1, 63,0);
        tracep->declQuad(c+134,"simTop mycore dpath exe_reg_pc", false,-1, 63,0);
        tracep->declBus(c+142,"simTop mycore dpath exe_reg_wbaddr", false,-1, 4,0);
        tracep->declQuad(c+120,"simTop mycore dpath exe_alu_op1", false,-1, 63,0);
        tracep->declQuad(c+122,"simTop mycore dpath brjmp_offset", false,-1, 63,0);
        tracep->declQuad(c+143,"simTop mycore dpath exe_reg_rs2_data", false,-1, 63,0);
        tracep->declBus(c+82,"simTop mycore dpath exe_reg_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+124,"simTop mycore dpath exe_reg_ctrl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+145,"simTop mycore dpath exe_reg_ctrl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+146,"simTop mycore dpath exe_reg_ctrl_rf_wen", false,-1);
        tracep->declBus(c+147,"simTop mycore dpath exe_reg_ctrl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+148,"simTop mycore dpath exe_reg_ctrl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+149,"simTop mycore dpath exe_reg_ctrl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+150,"simTop mycore dpath exe_reg_ctrl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+151,"simTop mycore dpath mem_reg_valid", false,-1);
        tracep->declQuad(c+132,"simTop mycore dpath mem_reg_pc", false,-1, 63,0);
        tracep->declQuad(c+152,"simTop mycore dpath mem_reg_inst", false,-1, 63,0);
        tracep->declQuad(c+130,"simTop mycore dpath mem_reg_alu_out", false,-1, 63,0);
        tracep->declBus(c+154,"simTop mycore dpath mem_reg_wbaddr", false,-1, 4,0);
        tracep->declBit(c+155,"simTop mycore dpath mem_reg_ctrl_rf_wen", false,-1);
        tracep->declBus(c+156,"simTop mycore dpath mem_reg_ctrl_wb_sel", false,-1, 2,0);
        tracep->declBus(c+157,"simTop mycore dpath mem_reg_ctrl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+129,"simTop mycore dpath mem_reg_ctrl_csr_cmd", false,-1, 2,0);
        tracep->declQuad(c+158,"simTop mycore dpath mem_reg_dram_data", false,-1, 63,0);
        tracep->declBit(c+10,"simTop mycore dpath wb_reg_valid", false,-1);
        tracep->declQuad(c+75,"simTop mycore dpath wb_reg_pc", false,-1, 63,0);
        tracep->declBus(c+116,"simTop mycore dpath wb_reg_wbaddr", false,-1, 4,0);
        tracep->declQuad(c+117,"simTop mycore dpath wb_reg_wbdata", false,-1, 63,0);
        tracep->declBit(c+119,"simTop mycore dpath wb_reg_ctrl_rf_wen", false,-1);
        tracep->declBit(c+127,"simTop mycore dpath alu_stall", false,-1);
        tracep->declQuad(c+160,"simTop mycore dpath if_pc_plus4", false,-1, 63,0);
        tracep->declQuad(c+162,"simTop mycore dpath exe_brjmp_target", false,-1, 63,0);
        tracep->declQuad(c+164,"simTop mycore dpath exe_adder_out", false,-1, 63,0);
        tracep->declBus(c+104,"simTop mycore dpath dec_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+105,"simTop mycore dpath dec_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+106,"simTop mycore dpath dec_wbaddr", false,-1, 4,0);
        tracep->declBus(c+166,"simTop mycore dpath imm_itype", false,-1, 11,0);
        tracep->declBus(c+167,"simTop mycore dpath imm_stype", false,-1, 11,0);
        tracep->declBus(c+168,"simTop mycore dpath imm_sbtype", false,-1, 11,0);
        tracep->declBus(c+169,"simTop mycore dpath imm_utype", false,-1, 19,0);
        tracep->declBus(c+170,"simTop mycore dpath imm_ujtype", false,-1, 19,0);
        tracep->declBus(c+171,"simTop mycore dpath imm_z", false,-1, 31,0);
        tracep->declQuad(c+172,"simTop mycore dpath imm_itype_sext", false,-1, 63,0);
        tracep->declQuad(c+174,"simTop mycore dpath imm_stype_sext", false,-1, 63,0);
        tracep->declQuad(c+176,"simTop mycore dpath imm_sbtype_sext", false,-1, 63,0);
        tracep->declQuad(c+178,"simTop mycore dpath imm_utype_sext", false,-1, 63,0);
        tracep->declQuad(c+180,"simTop mycore dpath imm_ujtype_sext", false,-1, 63,0);
        tracep->declQuad(c+182,"simTop mycore dpath mem_data", false,-1, 63,0);
        tracep->declQuad(c+184,"simTop mycore dpath mem_wbdata", false,-1, 63,0);
        tracep->declQuad(c+186,"simTop mycore dpath exe_alu_out", false,-1, 63,0);
        tracep->declQuad(c+188,"simTop mycore dpath dec_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+190,"simTop mycore dpath exe_pc_plus4", false,-1, 63,0);
        tracep->declBit(c+502,"simTop mycore dpath regfile clock", false,-1);
        tracep->declBus(c+104,"simTop mycore dpath regfile io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+112,"simTop mycore dpath regfile io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+105,"simTop mycore dpath regfile io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+114,"simTop mycore dpath regfile io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+116,"simTop mycore dpath regfile io_waddr", false,-1, 4,0);
        tracep->declQuad(c+117,"simTop mycore dpath regfile io_wdata", false,-1, 63,0);
        tracep->declBit(c+119,"simTop mycore dpath regfile io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+192+i*2,"simTop mycore dpath regfile regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+256,"simTop mycore dpath regfile regfile__T_1_data", false,-1, 63,0);
        tracep->declBus(c+104,"simTop mycore dpath regfile regfile__T_1_addr", false,-1, 4,0);
        tracep->declQuad(c+258,"simTop mycore dpath regfile regfile__T_4_data", false,-1, 63,0);
        tracep->declBus(c+105,"simTop mycore dpath regfile regfile__T_4_addr", false,-1, 4,0);
        tracep->declQuad(c+11,"simTop mycore dpath regfile regfile__T_10_data", false,-1, 63,0);
        tracep->declBus(c+587,"simTop mycore dpath regfile regfile__T_10_addr", false,-1, 4,0);
        tracep->declQuad(c+13,"simTop mycore dpath regfile regfile__T_11_data", false,-1, 63,0);
        tracep->declBus(c+588,"simTop mycore dpath regfile regfile__T_11_addr", false,-1, 4,0);
        tracep->declQuad(c+15,"simTop mycore dpath regfile regfile__T_12_data", false,-1, 63,0);
        tracep->declBus(c+589,"simTop mycore dpath regfile regfile__T_12_addr", false,-1, 4,0);
        tracep->declQuad(c+17,"simTop mycore dpath regfile regfile__T_13_data", false,-1, 63,0);
        tracep->declBus(c+590,"simTop mycore dpath regfile regfile__T_13_addr", false,-1, 4,0);
        tracep->declQuad(c+19,"simTop mycore dpath regfile regfile__T_14_data", false,-1, 63,0);
        tracep->declBus(c+591,"simTop mycore dpath regfile regfile__T_14_addr", false,-1, 4,0);
        tracep->declQuad(c+21,"simTop mycore dpath regfile regfile__T_15_data", false,-1, 63,0);
        tracep->declBus(c+592,"simTop mycore dpath regfile regfile__T_15_addr", false,-1, 4,0);
        tracep->declQuad(c+23,"simTop mycore dpath regfile regfile__T_16_data", false,-1, 63,0);
        tracep->declBus(c+593,"simTop mycore dpath regfile regfile__T_16_addr", false,-1, 4,0);
        tracep->declQuad(c+25,"simTop mycore dpath regfile regfile__T_17_data", false,-1, 63,0);
        tracep->declBus(c+594,"simTop mycore dpath regfile regfile__T_17_addr", false,-1, 4,0);
        tracep->declQuad(c+27,"simTop mycore dpath regfile regfile__T_18_data", false,-1, 63,0);
        tracep->declBus(c+595,"simTop mycore dpath regfile regfile__T_18_addr", false,-1, 4,0);
        tracep->declQuad(c+29,"simTop mycore dpath regfile regfile__T_19_data", false,-1, 63,0);
        tracep->declBus(c+596,"simTop mycore dpath regfile regfile__T_19_addr", false,-1, 4,0);
        tracep->declQuad(c+31,"simTop mycore dpath regfile regfile__T_20_data", false,-1, 63,0);
        tracep->declBus(c+597,"simTop mycore dpath regfile regfile__T_20_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"simTop mycore dpath regfile regfile__T_21_data", false,-1, 63,0);
        tracep->declBus(c+598,"simTop mycore dpath regfile regfile__T_21_addr", false,-1, 4,0);
        tracep->declQuad(c+35,"simTop mycore dpath regfile regfile__T_22_data", false,-1, 63,0);
        tracep->declBus(c+599,"simTop mycore dpath regfile regfile__T_22_addr", false,-1, 4,0);
        tracep->declQuad(c+37,"simTop mycore dpath regfile regfile__T_23_data", false,-1, 63,0);
        tracep->declBus(c+600,"simTop mycore dpath regfile regfile__T_23_addr", false,-1, 4,0);
        tracep->declQuad(c+39,"simTop mycore dpath regfile regfile__T_24_data", false,-1, 63,0);
        tracep->declBus(c+601,"simTop mycore dpath regfile regfile__T_24_addr", false,-1, 4,0);
        tracep->declQuad(c+41,"simTop mycore dpath regfile regfile__T_25_data", false,-1, 63,0);
        tracep->declBus(c+602,"simTop mycore dpath regfile regfile__T_25_addr", false,-1, 4,0);
        tracep->declQuad(c+43,"simTop mycore dpath regfile regfile__T_26_data", false,-1, 63,0);
        tracep->declBus(c+603,"simTop mycore dpath regfile regfile__T_26_addr", false,-1, 4,0);
        tracep->declQuad(c+45,"simTop mycore dpath regfile regfile__T_27_data", false,-1, 63,0);
        tracep->declBus(c+604,"simTop mycore dpath regfile regfile__T_27_addr", false,-1, 4,0);
        tracep->declQuad(c+47,"simTop mycore dpath regfile regfile__T_28_data", false,-1, 63,0);
        tracep->declBus(c+605,"simTop mycore dpath regfile regfile__T_28_addr", false,-1, 4,0);
        tracep->declQuad(c+49,"simTop mycore dpath regfile regfile__T_29_data", false,-1, 63,0);
        tracep->declBus(c+606,"simTop mycore dpath regfile regfile__T_29_addr", false,-1, 4,0);
        tracep->declQuad(c+51,"simTop mycore dpath regfile regfile__T_30_data", false,-1, 63,0);
        tracep->declBus(c+607,"simTop mycore dpath regfile regfile__T_30_addr", false,-1, 4,0);
        tracep->declQuad(c+53,"simTop mycore dpath regfile regfile__T_31_data", false,-1, 63,0);
        tracep->declBus(c+608,"simTop mycore dpath regfile regfile__T_31_addr", false,-1, 4,0);
        tracep->declQuad(c+55,"simTop mycore dpath regfile regfile__T_32_data", false,-1, 63,0);
        tracep->declBus(c+609,"simTop mycore dpath regfile regfile__T_32_addr", false,-1, 4,0);
        tracep->declQuad(c+57,"simTop mycore dpath regfile regfile__T_33_data", false,-1, 63,0);
        tracep->declBus(c+610,"simTop mycore dpath regfile regfile__T_33_addr", false,-1, 4,0);
        tracep->declQuad(c+59,"simTop mycore dpath regfile regfile__T_34_data", false,-1, 63,0);
        tracep->declBus(c+611,"simTop mycore dpath regfile regfile__T_34_addr", false,-1, 4,0);
        tracep->declQuad(c+61,"simTop mycore dpath regfile regfile__T_35_data", false,-1, 63,0);
        tracep->declBus(c+612,"simTop mycore dpath regfile regfile__T_35_addr", false,-1, 4,0);
        tracep->declQuad(c+63,"simTop mycore dpath regfile regfile__T_36_data", false,-1, 63,0);
        tracep->declBus(c+613,"simTop mycore dpath regfile regfile__T_36_addr", false,-1, 4,0);
        tracep->declQuad(c+65,"simTop mycore dpath regfile regfile__T_37_data", false,-1, 63,0);
        tracep->declBus(c+614,"simTop mycore dpath regfile regfile__T_37_addr", false,-1, 4,0);
        tracep->declQuad(c+67,"simTop mycore dpath regfile regfile__T_38_data", false,-1, 63,0);
        tracep->declBus(c+615,"simTop mycore dpath regfile regfile__T_38_addr", false,-1, 4,0);
        tracep->declQuad(c+69,"simTop mycore dpath regfile regfile__T_39_data", false,-1, 63,0);
        tracep->declBus(c+616,"simTop mycore dpath regfile regfile__T_39_addr", false,-1, 4,0);
        tracep->declQuad(c+71,"simTop mycore dpath regfile regfile__T_40_data", false,-1, 63,0);
        tracep->declBus(c+617,"simTop mycore dpath regfile regfile__T_40_addr", false,-1, 4,0);
        tracep->declQuad(c+73,"simTop mycore dpath regfile regfile__T_41_data", false,-1, 63,0);
        tracep->declBus(c+618,"simTop mycore dpath regfile regfile__T_41_addr", false,-1, 4,0);
        tracep->declQuad(c+117,"simTop mycore dpath regfile regfile__T_9_data", false,-1, 63,0);
        tracep->declBus(c+116,"simTop mycore dpath regfile regfile__T_9_addr", false,-1, 4,0);
        tracep->declBit(c+619,"simTop mycore dpath regfile regfile__T_9_mask", false,-1);
        tracep->declBit(c+260,"simTop mycore dpath regfile regfile__T_9_en", false,-1);
        tracep->declBit(c+502,"simTop mycore dpath alu clock", false,-1);
        tracep->declBit(c+503,"simTop mycore dpath alu reset", false,-1);
        tracep->declQuad(c+120,"simTop mycore dpath alu io_src1", false,-1, 63,0);
        tracep->declQuad(c+122,"simTop mycore dpath alu io_src2", false,-1, 63,0);
        tracep->declBus(c+124,"simTop mycore dpath alu io_op", false,-1, 4,0);
        tracep->declQuad(c+125,"simTop mycore dpath alu io_res", false,-1, 63,0);
        tracep->declBit(c+127,"simTop mycore dpath alu io_stall", false,-1);
        tracep->declBit(c+502,"simTop mycore dpath alu mdu_clock", false,-1);
        tracep->declBit(c+503,"simTop mycore dpath alu mdu_reset", false,-1);
        tracep->declBit(c+261,"simTop mycore dpath alu mdu_io_start", false,-1);
        tracep->declQuad(c+120,"simTop mycore dpath alu mdu_io_a", false,-1, 63,0);
        tracep->declQuad(c+122,"simTop mycore dpath alu mdu_io_b", false,-1, 63,0);
        tracep->declBus(c+124,"simTop mycore dpath alu mdu_io_op", false,-1, 4,0);
        tracep->declBit(c+262,"simTop mycore dpath alu mdu_io_stall_req", false,-1);
        tracep->declQuad(c+263,"simTop mycore dpath alu mdu_io_mult_out", false,-1, 63,0);
        tracep->declBus(c+265,"simTop mycore dpath alu shamt", false,-1, 5,0);
        tracep->declBit(c+261,"simTop mycore dpath alu use_mdu", false,-1);
        tracep->declBit(c+502,"simTop mycore dpath alu mdu clock", false,-1);
        tracep->declBit(c+503,"simTop mycore dpath alu mdu reset", false,-1);
        tracep->declBit(c+261,"simTop mycore dpath alu mdu io_start", false,-1);
        tracep->declQuad(c+120,"simTop mycore dpath alu mdu io_a", false,-1, 63,0);
        tracep->declQuad(c+122,"simTop mycore dpath alu mdu io_b", false,-1, 63,0);
        tracep->declBus(c+124,"simTop mycore dpath alu mdu io_op", false,-1, 4,0);
        tracep->declBit(c+262,"simTop mycore dpath alu mdu io_stall_req", false,-1);
        tracep->declQuad(c+263,"simTop mycore dpath alu mdu io_mult_out", false,-1, 63,0);
        tracep->declQuad(c+266,"simTop mycore dpath alu mdu last_a", false,-1, 63,0);
        tracep->declQuad(c+268,"simTop mycore dpath alu mdu last_b", false,-1, 63,0);
        tracep->declBus(c+270,"simTop mycore dpath alu mdu last_op", false,-1, 4,0);
        tracep->declBit(c+271,"simTop mycore dpath alu mdu is_mult", false,-1);
        tracep->declArray(c+272,"simTop mycore dpath alu mdu res", false,-1, 127,0);
        tracep->declBus(c+276,"simTop mycore dpath alu mdu mult_cnt", false,-1, 6,0);
        tracep->declBus(c+277,"simTop mycore dpath alu mdu div_cnt", false,-1, 6,0);
        tracep->declBit(c+278,"simTop mycore dpath alu mdu sign_a", false,-1);
        tracep->declBit(c+279,"simTop mycore dpath alu mdu sign_wa", false,-1);
        tracep->declQuad(c+280,"simTop mycore dpath alu mdu abs_a", false,-1, 63,0);
        tracep->declBit(c+282,"simTop mycore dpath alu mdu sign_b", false,-1);
        tracep->declBit(c+283,"simTop mycore dpath alu mdu sign_wb", false,-1);
        tracep->declQuad(c+284,"simTop mycore dpath alu mdu abs_b", false,-1, 63,0);
        tracep->declArray(c+286,"simTop mycore dpath alu mdu res_ss", false,-1, 127,0);
        tracep->declArray(c+290,"simTop mycore dpath alu mdu res_su", false,-1, 127,0);
        tracep->declQuad(c+294,"simTop mycore dpath alu mdu res_divs", false,-1, 63,0);
        tracep->declQuad(c+296,"simTop mycore dpath alu mdu res_rems", false,-1, 63,0);
        tracep->declBus(c+298,"simTop mycore dpath alu mdu res_divsw", false,-1, 31,0);
        tracep->declBus(c+299,"simTop mycore dpath alu mdu res_remsw", false,-1, 31,0);
        tracep->declBit(c+300,"simTop mycore dpath alu mdu last_stall_req", false,-1);
        tracep->declArray(c+301,"simTop mycore dpath alu mdu front_val", false,-1, 64,0);
        tracep->declArray(c+304,"simTop mycore dpath alu mdu step_result", false,-1, 127,0);
        tracep->declBit(c+502,"simTop mycore dpath csr clock", false,-1);
        tracep->declBit(c+503,"simTop mycore dpath csr reset", false,-1);
        tracep->declBus(c+128,"simTop mycore dpath csr io_inst", false,-1, 31,0);
        tracep->declBus(c+129,"simTop mycore dpath csr io_csr_op", false,-1, 2,0);
        tracep->declQuad(c+130,"simTop mycore dpath csr io_data_in", false,-1, 63,0);
        tracep->declBit(c+127,"simTop mycore dpath csr io_has_stall", false,-1);
        tracep->declQuad(c+132,"simTop mycore dpath csr io_in_mem_pc", false,-1, 63,0);
        tracep->declQuad(c+134,"simTop mycore dpath csr io_in_exe_pc", false,-1, 63,0);
        tracep->declQuad(c+136,"simTop mycore dpath csr io_in_dec_pc", false,-1, 63,0);
        tracep->declQuad(c+1,"simTop mycore dpath csr io_in_if_pc", false,-1, 63,0);
        tracep->declBit(c+83,"simTop mycore dpath csr io_is_redir", false,-1);
        tracep->declQuad(c+308,"simTop mycore dpath csr reg_mtvec", false,-1, 63,0);
        tracep->declQuad(c+310,"simTop mycore dpath csr reg_mepc", false,-1, 63,0);
        tracep->declQuad(c+312,"simTop mycore dpath csr reg_mcause", false,-1, 63,0);
        tracep->declBit(c+314,"simTop mycore dpath csr reg_mie_mtip", false,-1);
        tracep->declBit(c+315,"simTop mycore dpath csr reg_mie_msip", false,-1);
        tracep->declBit(c+316,"simTop mycore dpath csr reg_mip_mtip", false,-1);
        tracep->declBit(c+317,"simTop mycore dpath csr reg_mip_msip", false,-1);
        tracep->declQuad(c+318,"simTop mycore dpath csr reg_mtval", false,-1, 63,0);
        tracep->declQuad(c+320,"simTop mycore dpath csr reg_mscratch", false,-1, 63,0);
        tracep->declBus(c+322,"simTop mycore dpath csr reg_mstatus_mpp", false,-1, 1,0);
        tracep->declBit(c+323,"simTop mycore dpath csr reg_mstatus_mpie", false,-1);
        tracep->declBit(c+324,"simTop mycore dpath csr reg_mstatus_mie", false,-1);
        tracep->declQuad(c+325,"simTop mycore dpath csr reg_pmpcfg0", false,-1, 63,0);
        tracep->declQuad(c+327,"simTop mycore dpath csr reg_pmpcfg1", false,-1, 63,0);
        tracep->declQuad(c+329,"simTop mycore dpath csr regs_pmpaddr_0", false,-1, 63,0);
        tracep->declQuad(c+331,"simTop mycore dpath csr regs_pmpaddr_1", false,-1, 63,0);
        tracep->declQuad(c+333,"simTop mycore dpath csr regs_pmpaddr_2", false,-1, 63,0);
        tracep->declQuad(c+335,"simTop mycore dpath csr regs_pmpaddr_3", false,-1, 63,0);
        tracep->declQuad(c+337,"simTop mycore dpath csr regs_pmpaddr_4", false,-1, 63,0);
        tracep->declQuad(c+339,"simTop mycore dpath csr regs_pmpaddr_5", false,-1, 63,0);
        tracep->declQuad(c+341,"simTop mycore dpath csr regs_pmpaddr_6", false,-1, 63,0);
        tracep->declQuad(c+343,"simTop mycore dpath csr regs_pmpaddr_7", false,-1, 63,0);
        tracep->declQuad(c+345,"simTop mycore dpath csr regs_pmpaddr_8", false,-1, 63,0);
        tracep->declQuad(c+347,"simTop mycore dpath csr regs_pmpaddr_9", false,-1, 63,0);
        tracep->declQuad(c+349,"simTop mycore dpath csr regs_pmpaddr_10", false,-1, 63,0);
        tracep->declQuad(c+351,"simTop mycore dpath csr regs_pmpaddr_11", false,-1, 63,0);
        tracep->declQuad(c+353,"simTop mycore dpath csr regs_pmpaddr_12", false,-1, 63,0);
        tracep->declQuad(c+355,"simTop mycore dpath csr regs_pmpaddr_13", false,-1, 63,0);
        tracep->declQuad(c+357,"simTop mycore dpath csr regs_pmpaddr_14", false,-1, 63,0);
        tracep->declQuad(c+359,"simTop mycore dpath csr regs_pmpaddr_15", false,-1, 63,0);
        tracep->declQuad(c+361,"simTop mycore dpath csr reg_mcycle", false,-1, 63,0);
        tracep->declQuad(c+363,"simTop mycore dpath csr reg_minstret", false,-1, 63,0);
        tracep->declQuad(c+365,"simTop mycore dpath csr regs_mhpmcounter_0", false,-1, 63,0);
        tracep->declQuad(c+367,"simTop mycore dpath csr regs_mhpmcounter_1", false,-1, 63,0);
        tracep->declQuad(c+369,"simTop mycore dpath csr regs_mhpmcounter_2", false,-1, 63,0);
        tracep->declQuad(c+371,"simTop mycore dpath csr regs_mhpmcounter_3", false,-1, 63,0);
        tracep->declQuad(c+373,"simTop mycore dpath csr regs_mhpmcounter_4", false,-1, 63,0);
        tracep->declQuad(c+375,"simTop mycore dpath csr regs_mhpmcounter_5", false,-1, 63,0);
        tracep->declQuad(c+377,"simTop mycore dpath csr regs_mhpmcounter_6", false,-1, 63,0);
        tracep->declQuad(c+379,"simTop mycore dpath csr regs_mhpmcounter_7", false,-1, 63,0);
        tracep->declQuad(c+381,"simTop mycore dpath csr regs_mhpmcounter_8", false,-1, 63,0);
        tracep->declQuad(c+383,"simTop mycore dpath csr regs_mhpmcounter_9", false,-1, 63,0);
        tracep->declQuad(c+385,"simTop mycore dpath csr regs_mhpmcounter_10", false,-1, 63,0);
        tracep->declQuad(c+387,"simTop mycore dpath csr regs_mhpmcounter_11", false,-1, 63,0);
        tracep->declQuad(c+389,"simTop mycore dpath csr regs_mhpmcounter_12", false,-1, 63,0);
        tracep->declQuad(c+391,"simTop mycore dpath csr regs_mhpmcounter_13", false,-1, 63,0);
        tracep->declQuad(c+393,"simTop mycore dpath csr regs_mhpmcounter_14", false,-1, 63,0);
        tracep->declQuad(c+395,"simTop mycore dpath csr regs_mhpmcounter_15", false,-1, 63,0);
        tracep->declQuad(c+397,"simTop mycore dpath csr regs_mhpmcounter_16", false,-1, 63,0);
        tracep->declQuad(c+399,"simTop mycore dpath csr regs_mhpmcounter_17", false,-1, 63,0);
        tracep->declQuad(c+401,"simTop mycore dpath csr regs_mhpmcounter_18", false,-1, 63,0);
        tracep->declQuad(c+403,"simTop mycore dpath csr regs_mhpmcounter_19", false,-1, 63,0);
        tracep->declQuad(c+405,"simTop mycore dpath csr regs_mhpmcounter_20", false,-1, 63,0);
        tracep->declQuad(c+407,"simTop mycore dpath csr regs_mhpmcounter_21", false,-1, 63,0);
        tracep->declQuad(c+409,"simTop mycore dpath csr regs_mhpmcounter_22", false,-1, 63,0);
        tracep->declQuad(c+411,"simTop mycore dpath csr regs_mhpmcounter_23", false,-1, 63,0);
        tracep->declQuad(c+413,"simTop mycore dpath csr regs_mhpmcounter_24", false,-1, 63,0);
        tracep->declQuad(c+415,"simTop mycore dpath csr regs_mhpmcounter_25", false,-1, 63,0);
        tracep->declQuad(c+417,"simTop mycore dpath csr regs_mhpmcounter_26", false,-1, 63,0);
        tracep->declQuad(c+419,"simTop mycore dpath csr regs_mhpmcounter_27", false,-1, 63,0);
        tracep->declQuad(c+421,"simTop mycore dpath csr regs_mhpmcounter_28", false,-1, 63,0);
        tracep->declQuad(c+423,"simTop mycore dpath csr reg_mcounterinhibit", false,-1, 63,0);
        tracep->declQuad(c+425,"simTop mycore dpath csr regs_mhpmevet_0", false,-1, 63,0);
        tracep->declQuad(c+427,"simTop mycore dpath csr regs_mhpmevet_1", false,-1, 63,0);
        tracep->declQuad(c+429,"simTop mycore dpath csr regs_mhpmevet_2", false,-1, 63,0);
        tracep->declQuad(c+431,"simTop mycore dpath csr regs_mhpmevet_3", false,-1, 63,0);
        tracep->declQuad(c+433,"simTop mycore dpath csr regs_mhpmevet_4", false,-1, 63,0);
        tracep->declQuad(c+435,"simTop mycore dpath csr regs_mhpmevet_5", false,-1, 63,0);
        tracep->declQuad(c+437,"simTop mycore dpath csr regs_mhpmevet_6", false,-1, 63,0);
        tracep->declQuad(c+439,"simTop mycore dpath csr regs_mhpmevet_7", false,-1, 63,0);
        tracep->declQuad(c+441,"simTop mycore dpath csr regs_mhpmevet_8", false,-1, 63,0);
        tracep->declQuad(c+443,"simTop mycore dpath csr regs_mhpmevet_9", false,-1, 63,0);
        tracep->declQuad(c+445,"simTop mycore dpath csr regs_mhpmevet_10", false,-1, 63,0);
        tracep->declQuad(c+447,"simTop mycore dpath csr regs_mhpmevet_11", false,-1, 63,0);
        tracep->declQuad(c+449,"simTop mycore dpath csr regs_mhpmevet_12", false,-1, 63,0);
        tracep->declQuad(c+451,"simTop mycore dpath csr regs_mhpmevet_13", false,-1, 63,0);
        tracep->declQuad(c+453,"simTop mycore dpath csr regs_mhpmevet_14", false,-1, 63,0);
        tracep->declQuad(c+455,"simTop mycore dpath csr regs_mhpmevet_15", false,-1, 63,0);
        tracep->declQuad(c+457,"simTop mycore dpath csr regs_mhpmevet_16", false,-1, 63,0);
        tracep->declQuad(c+459,"simTop mycore dpath csr regs_mhpmevet_17", false,-1, 63,0);
        tracep->declQuad(c+461,"simTop mycore dpath csr regs_mhpmevet_18", false,-1, 63,0);
        tracep->declQuad(c+463,"simTop mycore dpath csr regs_mhpmevet_19", false,-1, 63,0);
        tracep->declQuad(c+465,"simTop mycore dpath csr regs_mhpmevet_20", false,-1, 63,0);
        tracep->declQuad(c+467,"simTop mycore dpath csr regs_mhpmevet_21", false,-1, 63,0);
        tracep->declQuad(c+469,"simTop mycore dpath csr regs_mhpmevet_22", false,-1, 63,0);
        tracep->declQuad(c+471,"simTop mycore dpath csr regs_mhpmevet_23", false,-1, 63,0);
        tracep->declQuad(c+473,"simTop mycore dpath csr regs_mhpmevet_24", false,-1, 63,0);
        tracep->declQuad(c+475,"simTop mycore dpath csr regs_mhpmevet_25", false,-1, 63,0);
        tracep->declQuad(c+477,"simTop mycore dpath csr regs_mhpmevet_26", false,-1, 63,0);
        tracep->declQuad(c+479,"simTop mycore dpath csr regs_mhpmevet_27", false,-1, 63,0);
        tracep->declQuad(c+481,"simTop mycore dpath csr regs_mhpmevet_28", false,-1, 63,0);
        tracep->declBus(c+483,"simTop mycore dpath csr wire_csr_index", false,-1, 11,0);
        tracep->declBus(c+484,"simTop mycore dpath csr wire_csr_op", false,-1, 2,0);
        tracep->declBit(c+485,"simTop mycore dpath csr csr_read_only", false,-1);
        tracep->declBit(c+486,"simTop mycore dpath csr write_illegal", false,-1);
        tracep->declBit(c+487,"simTop mycore dpath csr csr_legal", false,-1);
        tracep->declBit(c+488,"simTop mycore dpath csr read_illegal", false,-1);
        tracep->declBit(c+489,"simTop mycore dpath csr exception_in_csr", false,-1);
        tracep->declBit(c+490,"simTop mycore dpath csr csr_read_enable", false,-1);
        tracep->declQuad(c+491,"simTop mycore dpath csr csr_read_data", false,-1, 63,0);
        tracep->declQuad(c+493,"simTop mycore dpath csr csr_write_data", false,-1, 63,0);
        tracep->declBit(c+495,"simTop mycore dpath csr csr_wen", false,-1);
        tracep->declBit(c+496,"simTop mycore dpath csr csr_isecall", false,-1);
        tracep->declBit(c+497,"simTop mycore dpath csr csr_isebreak", false,-1);
        tracep->declBit(c+498,"simTop mycore dpath csr csr_ismret", false,-1);
        tracep->declBit(c+499,"simTop mycore dpath csr csr_has_exception", false,-1);
        tracep->declBit(c+500,"simTop mycore dpath csr csr_has_interrupt", false,-1);
        tracep->declBus(c+501,"simTop mycore dpath csr prv_now", false,-1, 1,0);
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
    // Variables
    WData/*127:0*/ __Vtemp62[4];
    WData/*127:0*/ __Vtemp63[4];
    WData/*127:0*/ __Vtemp64[4];
    WData/*127:0*/ __Vtemp67[4];
    WData/*127:0*/ __Vtemp68[4];
    WData/*127:0*/ __Vtemp69[4];
    WData/*127:0*/ __Vtemp71[4];
    WData/*127:0*/ __Vtemp72[4];
    WData/*127:0*/ __Vtemp73[4];
    WData/*127:0*/ __Vtemp74[4];
    WData/*127:0*/ __Vtemp75[4];
    WData/*127:0*/ __Vtemp76[4];
    WData/*127:0*/ __Vtemp77[4];
    WData/*127:0*/ __Vtemp79[4];
    // Body
    {
        tracep->fullQData(oldp+1,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc),64);
        tracep->fullQData(oldp+3,(((4U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel))
                                    ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_151
                                    : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res)),64);
        tracep->fullBit(oldp+5,((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn))));
        tracep->fullQData(oldp+6,(((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
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
                                        << 0x20U) | (QData)((IData)(
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
                                        : ((0xfU == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ))
                                            ? (((QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)))
                                            : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data)))),64);
        tracep->fullBit(oldp+8,((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn))));
        tracep->fullCData(oldp+9,((0xffU & ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ) 
                                            << (7U 
                                                & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out))))),8);
        tracep->fullBit(oldp+10,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid));
        tracep->fullQData(oldp+11,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0U]),64);
        tracep->fullQData(oldp+13,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [1U]),64);
        tracep->fullQData(oldp+15,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [2U]),64);
        tracep->fullQData(oldp+17,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [3U]),64);
        tracep->fullQData(oldp+19,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [4U]),64);
        tracep->fullQData(oldp+21,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [5U]),64);
        tracep->fullQData(oldp+23,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [6U]),64);
        tracep->fullQData(oldp+25,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [7U]),64);
        tracep->fullQData(oldp+27,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [8U]),64);
        tracep->fullQData(oldp+29,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [9U]),64);
        tracep->fullQData(oldp+31,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xaU]),64);
        tracep->fullQData(oldp+33,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xbU]),64);
        tracep->fullQData(oldp+35,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xcU]),64);
        tracep->fullQData(oldp+37,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xdU]),64);
        tracep->fullQData(oldp+39,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xeU]),64);
        tracep->fullQData(oldp+41,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xfU]),64);
        tracep->fullQData(oldp+43,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x10U]),64);
        tracep->fullQData(oldp+45,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x11U]),64);
        tracep->fullQData(oldp+47,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x12U]),64);
        tracep->fullQData(oldp+49,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x13U]),64);
        tracep->fullQData(oldp+51,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x14U]),64);
        tracep->fullQData(oldp+53,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x15U]),64);
        tracep->fullQData(oldp+55,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x16U]),64);
        tracep->fullQData(oldp+57,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x17U]),64);
        tracep->fullQData(oldp+59,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x18U]),64);
        tracep->fullQData(oldp+61,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x19U]),64);
        tracep->fullQData(oldp+63,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1aU]),64);
        tracep->fullQData(oldp+65,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1bU]),64);
        tracep->fullQData(oldp+67,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1cU]),64);
        tracep->fullQData(oldp+69,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1dU]),64);
        tracep->fullQData(oldp+71,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1eU]),64);
        tracep->fullQData(oldp+73,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1fU]),64);
        tracep->fullQData(oldp+75,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc),64);
        tracep->fullQData(oldp+77,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst),64);
        tracep->fullBit(oldp+79,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq));
        tracep->fullBit(oldp+80,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt));
        tracep->fullBit(oldp+81,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu));
        tracep->fullCData(oldp+82,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type),4);
        tracep->fullBit(oldp+83,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir));
        tracep->fullBit(oldp+84,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall));
        tracep->fullCData(oldp+85,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel),2);
        tracep->fullCData(oldp+86,(((0x3003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 0U : ((0x2003ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                              ? 0U : 
                                             ((0x6003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                               ? 0U
                                               : ((3ULL 
                                                   == 
                                                   (0x707fULL 
                                                    & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                                   ? 0U
                                                   : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_294)))))),4);
        tracep->fullBit(oldp+87,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_if_kill));
        tracep->fullBit(oldp+88,((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel))));
        tracep->fullCData(oldp+89,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel),2);
        tracep->fullCData(oldp+90,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel),3);
        tracep->fullCData(oldp+91,(((0x3003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 0U : ((0x2003ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                              ? 0U : 
                                             ((0x6003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                               ? 0U
                                               : ((3ULL 
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
        tracep->fullCData(oldp+92,(((0x3003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 1U : ((0x2003ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                              ? 1U : 
                                             ((0x6003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                               ? 1U
                                               : ((3ULL 
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
        tracep->fullBit(oldp+93,(((0x3003ULL == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                  | ((0x2003ULL == 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((0x6003ULL 
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
        tracep->fullCData(oldp+94,(((0x3003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_963))),2);
        tracep->fullCData(oldp+95,(((0x3003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 0xffU : ((0x2003ULL 
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
        tracep->fullCData(oldp+96,(((0x3003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 6U : ((0x2003ULL 
                                              == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                              ? 4U : 
                                             ((0x6003ULL 
                                               == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                               ? 5U
                                               : ((3ULL 
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
        tracep->fullCData(oldp+97,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1295)
                                     ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7))),3);
        tracep->fullBit(oldp+98,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8) 
                                  | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1313))));
        tracep->fullBit(oldp+99,(((0x3003ULL == (0x707fULL 
                                                 & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                  | ((0x2003ULL == 
                                      (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                     | ((0x6003ULL 
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
                                                    | ((0x3023ULL 
                                                        == 
                                                        (0x707fULL 
                                                         & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                       | ((0x2023ULL 
                                                           == 
                                                           (0x707fULL 
                                                            & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                          | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_511))))))))))));
        tracep->fullBit(oldp+100,(((0x3003ULL != (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   & ((0x2003ULL != 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x6003ULL 
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
                                                     & ((0x3023ULL 
                                                         == 
                                                         (0x707fULL 
                                                          & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                        | ((0x2023ULL 
                                                            == 
                                                            (0x707fULL 
                                                             & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                                           | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_585))))))))))));
        tracep->fullBit(oldp+101,(((0x3003ULL == (0x707fULL 
                                                  & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                   | ((0x2003ULL == 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      | ((0x6003ULL 
                                          == (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         | ((3ULL == 
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
        tracep->fullCData(oldp+102,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7),3);
        tracep->fullBit(oldp+103,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8));
        tracep->fullCData(oldp+104,((0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0xfU)))),5);
        tracep->fullCData(oldp+105,((0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0x14U)))),5);
        tracep->fullCData(oldp+106,((0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 7U)))),5);
        tracep->fullBit(oldp+107,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                                   & ((0x3003ULL == 
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
        tracep->fullBit(oldp+108,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__ctrl_exe_pc_sel)) 
                                   & ((0x3003ULL != 
                                       (0x707fULL & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                      & ((0x2003ULL 
                                          != (0x707fULL 
                                              & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst)) 
                                         & ((0x6003ULL 
                                             != (0x707fULL 
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
        tracep->fullCData(oldp+109,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr),5);
        tracep->fullBit(oldp+110,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr));
        tracep->fullBit(oldp+111,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load));
        tracep->fullQData(oldp+112,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data),64);
        tracep->fullQData(oldp+114,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data),64);
        tracep->fullCData(oldp+116,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr),5);
        tracep->fullQData(oldp+117,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata),64);
        tracep->fullBit(oldp+119,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
        tracep->fullQData(oldp+120,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1),64);
        tracep->fullQData(oldp+122,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset),64);
        tracep->fullCData(oldp+124,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun),5);
        tracep->fullQData(oldp+125,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res),64);
        tracep->fullBit(oldp+127,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall));
        tracep->fullIData(oldp+128,((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst)),32);
        tracep->fullCData(oldp+129,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd),3);
        tracep->fullQData(oldp+130,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out),64);
        tracep->fullQData(oldp+132,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc),64);
        tracep->fullQData(oldp+134,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc),64);
        tracep->fullQData(oldp+136,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc),64);
        tracep->fullBit(oldp+138,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid));
        tracep->fullBit(oldp+139,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid));
        tracep->fullQData(oldp+140,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst),64);
        tracep->fullCData(oldp+142,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr),5);
        tracep->fullQData(oldp+143,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data),64);
        tracep->fullCData(oldp+145,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel),3);
        tracep->fullBit(oldp+146,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
        tracep->fullCData(oldp+147,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn),2);
        tracep->fullCData(oldp+148,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ),8);
        tracep->fullCData(oldp+149,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid),3);
        tracep->fullCData(oldp+150,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_csr_cmd),3);
        tracep->fullBit(oldp+151,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid));
        tracep->fullQData(oldp+152,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst),64);
        tracep->fullCData(oldp+154,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr),5);
        tracep->fullBit(oldp+155,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
        tracep->fullCData(oldp+156,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel),3);
        tracep->fullCData(oldp+157,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid),3);
        tracep->fullQData(oldp+158,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data),64);
        tracep->fullQData(oldp+160,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)),64);
        tracep->fullQData(oldp+162,((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc 
                                     + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)),64);
        tracep->fullQData(oldp+164,((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                     + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset)),64);
        tracep->fullSData(oldp+166,((0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0x14U)))),12);
        tracep->fullSData(oldp+167,(((0xfe0U & ((IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0x19U)) 
                                                << 5U)) 
                                     | (0x1fU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 7U))))),12);
        tracep->fullSData(oldp+168,(((0x800U & ((IData)(
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
        tracep->fullIData(oldp+169,((0xfffffU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0xcU)))),20);
        tracep->fullIData(oldp+170,(((0x80000U & ((IData)(
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
        tracep->fullIData(oldp+171,((0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0xfU)))),32);
        tracep->fullQData(oldp+172,(((((1U & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0x1fU)))
                                        ? 0xfffffffffffffULL
                                        : 0ULL) << 0xcU) 
                                     | (QData)((IData)(
                                                       (0xfffU 
                                                        & (IData)(
                                                                  (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                   >> 0x14U))))))),64);
        tracep->fullQData(oldp+174,(((((1U & (IData)(
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
        tracep->fullQData(oldp+176,(((((1U & (IData)(
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
        tracep->fullQData(oldp+178,((((QData)((IData)(
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
        tracep->fullQData(oldp+180,(((((1U & (IData)(
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
        tracep->fullQData(oldp+182,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_174
                                      : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                          ? (QData)((IData)(
                                                            (0xffU 
                                                             & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))
                                          : ((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
                                              ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_184
                                              : ((3U 
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
        tracep->fullQData(oldp+184,(((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                      ? ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
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
                                                     : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data))))))
                                      : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out)),64);
        tracep->fullQData(oldp+186,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out),64);
        tracep->fullQData(oldp+188,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_79)
                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out
                                      : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_83)
                                          ? ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel))
                                              ? ((0U 
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
        tracep->fullQData(oldp+190,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)),64);
        tracep->fullQData(oldp+192,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[0]),64);
        tracep->fullQData(oldp+194,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[1]),64);
        tracep->fullQData(oldp+196,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[2]),64);
        tracep->fullQData(oldp+198,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[3]),64);
        tracep->fullQData(oldp+200,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[4]),64);
        tracep->fullQData(oldp+202,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[5]),64);
        tracep->fullQData(oldp+204,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[6]),64);
        tracep->fullQData(oldp+206,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[7]),64);
        tracep->fullQData(oldp+208,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[8]),64);
        tracep->fullQData(oldp+210,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[9]),64);
        tracep->fullQData(oldp+212,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[10]),64);
        tracep->fullQData(oldp+214,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[11]),64);
        tracep->fullQData(oldp+216,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[12]),64);
        tracep->fullQData(oldp+218,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[13]),64);
        tracep->fullQData(oldp+220,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[14]),64);
        tracep->fullQData(oldp+222,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[15]),64);
        tracep->fullQData(oldp+224,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[16]),64);
        tracep->fullQData(oldp+226,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[17]),64);
        tracep->fullQData(oldp+228,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[18]),64);
        tracep->fullQData(oldp+230,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[19]),64);
        tracep->fullQData(oldp+232,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[20]),64);
        tracep->fullQData(oldp+234,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[21]),64);
        tracep->fullQData(oldp+236,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[22]),64);
        tracep->fullQData(oldp+238,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[23]),64);
        tracep->fullQData(oldp+240,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[24]),64);
        tracep->fullQData(oldp+242,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[25]),64);
        tracep->fullQData(oldp+244,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[26]),64);
        tracep->fullQData(oldp+246,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[27]),64);
        tracep->fullQData(oldp+248,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[28]),64);
        tracep->fullQData(oldp+250,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[29]),64);
        tracep->fullQData(oldp+252,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[30]),64);
        tracep->fullQData(oldp+254,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[31]),64);
        tracep->fullQData(oldp+256,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                    [(0x1fU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0xfU)))]),64);
        tracep->fullQData(oldp+258,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                    [(0x1fU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0x14U)))]),64);
        tracep->fullBit(oldp+260,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen) 
                                   & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr)))));
        tracep->fullBit(oldp+261,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu));
        tracep->fullBit(oldp+262,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req));
        __Vtemp62[0U] = 1U;
        __Vtemp62[1U] = 0U;
        __Vtemp62[2U] = 0U;
        __Vtemp62[3U] = 0U;
        __Vtemp63[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
        __Vtemp63[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
        __Vtemp63[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
        __Vtemp63[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
        VL_ADD_W(4, __Vtemp64, __Vtemp62, __Vtemp63);
        __Vtemp67[0U] = 1U;
        __Vtemp67[1U] = 0U;
        __Vtemp67[2U] = 0U;
        __Vtemp67[3U] = 0U;
        __Vtemp68[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
        __Vtemp68[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
        __Vtemp68[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
        __Vtemp68[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
        VL_ADD_W(4, __Vtemp69, __Vtemp67, __Vtemp68);
        tracep->fullQData(oldp+263,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
                                      ? ((0x19U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                          ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_268
                                          : ((0x14U 
                                              == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                              ? (((QData)((IData)(
                                                                  vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U])))
                                              : ((0x13U 
                                                  == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                                  ? 
                                                 (((QData)((IData)(
                                                                   ((1U 
                                                                     & (IData)(
                                                                               (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                                                >> 0x3fU)))
                                                                     ? 
                                                                    __Vtemp64[3U]
                                                                     : 
                                                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    ((1U 
                                                                      & (IData)(
                                                                                (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                                                >> 0x3fU)))
                                                                      ? 
                                                                     __Vtemp64[2U]
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
                                                                     __Vtemp69[3U]))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153)
                                                                       ? 
                                                                      vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]
                                                                       : 
                                                                      __Vtemp69[2U]))))
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
                                      : ((0x10U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun))
                                          ? ((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))
                                              ? (((QData)((IData)(
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
                                              ? ((0U 
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
        tracep->fullCData(oldp+265,((0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))),6);
        tracep->fullQData(oldp+266,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_a),64);
        tracep->fullQData(oldp+268,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_b),64);
        tracep->fullCData(oldp+270,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op),5);
        tracep->fullBit(oldp+271,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult));
        tracep->fullWData(oldp+272,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res),128);
        tracep->fullCData(oldp+276,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt),7);
        tracep->fullCData(oldp+277,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt),7);
        tracep->fullBit(oldp+278,((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                 >> 0x3fU)))));
        tracep->fullBit(oldp+279,((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                 >> 0x1fU)))));
        tracep->fullQData(oldp+280,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a),64);
        tracep->fullBit(oldp+282,((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                                                 >> 0x3fU)))));
        tracep->fullBit(oldp+283,((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                                                 >> 0x1fU)))));
        tracep->fullQData(oldp+284,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b),64);
        __Vtemp71[0U] = 1U;
        __Vtemp71[1U] = 0U;
        __Vtemp71[2U] = 0U;
        __Vtemp71[3U] = 0U;
        __Vtemp72[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
        __Vtemp72[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
        __Vtemp72[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
        __Vtemp72[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
        VL_ADD_W(4, __Vtemp73, __Vtemp71, __Vtemp72);
        if (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153) {
            __Vtemp74[0U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U];
            __Vtemp74[1U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U];
            __Vtemp74[2U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U];
            __Vtemp74[3U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U];
        } else {
            __Vtemp74[0U] = __Vtemp73[0U];
            __Vtemp74[1U] = __Vtemp73[1U];
            __Vtemp74[2U] = __Vtemp73[2U];
            __Vtemp74[3U] = __Vtemp73[3U];
        }
        tracep->fullWData(oldp+286,(__Vtemp74),128);
        __Vtemp75[0U] = 1U;
        __Vtemp75[1U] = 0U;
        __Vtemp75[2U] = 0U;
        __Vtemp75[3U] = 0U;
        __Vtemp76[0U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]);
        __Vtemp76[1U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U]);
        __Vtemp76[2U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]);
        __Vtemp76[3U] = (~ vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U]);
        VL_ADD_W(4, __Vtemp77, __Vtemp75, __Vtemp76);
        if ((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                           >> 0x3fU)))) {
            __Vtemp79[0U] = __Vtemp77[0U];
            __Vtemp79[1U] = __Vtemp77[1U];
            __Vtemp79[2U] = __Vtemp77[2U];
            __Vtemp79[3U] = __Vtemp77[3U];
        } else {
            __Vtemp79[0U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U];
            __Vtemp79[1U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U];
            __Vtemp79[2U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U];
            __Vtemp79[3U] = vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U];
        }
        tracep->fullWData(oldp+290,(__Vtemp79),128);
        tracep->fullQData(oldp+294,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153)
                                      ? (((QData)((IData)(
                                                          vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U])))
                                      : (1ULL + (~ 
                                                 (((QData)((IData)(
                                                                   vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[0U]))))))),64);
        tracep->fullQData(oldp+296,(((1U & (IData)(
                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                    >> 0x3fU)))
                                      ? (1ULL + (~ 
                                                 (((QData)((IData)(
                                                                   vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U])))))
                                      : (((QData)((IData)(
                                                          vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[3U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res[2U]))))),64);
        tracep->fullIData(oldp+298,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_divsw),32);
        tracep->fullIData(oldp+299,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_remsw),32);
        tracep->fullBit(oldp+300,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_stall_req));
        tracep->fullWData(oldp+301,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val),65);
        tracep->fullWData(oldp+304,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result),128);
        tracep->fullQData(oldp+308,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtvec),64);
        tracep->fullQData(oldp+310,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc),64);
        tracep->fullQData(oldp+312,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause),64);
        tracep->fullBit(oldp+314,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_mtip));
        tracep->fullBit(oldp+315,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_msip));
        tracep->fullBit(oldp+316,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_mtip));
        tracep->fullBit(oldp+317,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_msip));
        tracep->fullQData(oldp+318,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval),64);
        tracep->fullQData(oldp+320,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mscratch),64);
        tracep->fullCData(oldp+322,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp),2);
        tracep->fullBit(oldp+323,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie));
        tracep->fullBit(oldp+324,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie));
        tracep->fullQData(oldp+325,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg0),64);
        tracep->fullQData(oldp+327,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg1),64);
        tracep->fullQData(oldp+329,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_0),64);
        tracep->fullQData(oldp+331,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_1),64);
        tracep->fullQData(oldp+333,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_2),64);
        tracep->fullQData(oldp+335,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_3),64);
        tracep->fullQData(oldp+337,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_4),64);
        tracep->fullQData(oldp+339,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_5),64);
        tracep->fullQData(oldp+341,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_6),64);
        tracep->fullQData(oldp+343,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_7),64);
        tracep->fullQData(oldp+345,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_8),64);
        tracep->fullQData(oldp+347,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_9),64);
        tracep->fullQData(oldp+349,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_10),64);
        tracep->fullQData(oldp+351,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_11),64);
        tracep->fullQData(oldp+353,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_12),64);
        tracep->fullQData(oldp+355,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_13),64);
        tracep->fullQData(oldp+357,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_14),64);
        tracep->fullQData(oldp+359,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_15),64);
        tracep->fullQData(oldp+361,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcycle),64);
        tracep->fullQData(oldp+363,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_minstret),64);
        tracep->fullQData(oldp+365,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_0),64);
        tracep->fullQData(oldp+367,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_1),64);
        tracep->fullQData(oldp+369,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_2),64);
        tracep->fullQData(oldp+371,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_3),64);
        tracep->fullQData(oldp+373,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_4),64);
        tracep->fullQData(oldp+375,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_5),64);
        tracep->fullQData(oldp+377,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_6),64);
        tracep->fullQData(oldp+379,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_7),64);
        tracep->fullQData(oldp+381,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_8),64);
        tracep->fullQData(oldp+383,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_9),64);
        tracep->fullQData(oldp+385,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_10),64);
        tracep->fullQData(oldp+387,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_11),64);
        tracep->fullQData(oldp+389,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_12),64);
        tracep->fullQData(oldp+391,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_13),64);
        tracep->fullQData(oldp+393,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_14),64);
        tracep->fullQData(oldp+395,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_15),64);
        tracep->fullQData(oldp+397,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_16),64);
        tracep->fullQData(oldp+399,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_17),64);
        tracep->fullQData(oldp+401,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_18),64);
        tracep->fullQData(oldp+403,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_19),64);
        tracep->fullQData(oldp+405,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_20),64);
        tracep->fullQData(oldp+407,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_21),64);
        tracep->fullQData(oldp+409,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_22),64);
        tracep->fullQData(oldp+411,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_23),64);
        tracep->fullQData(oldp+413,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_24),64);
        tracep->fullQData(oldp+415,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_25),64);
        tracep->fullQData(oldp+417,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_26),64);
        tracep->fullQData(oldp+419,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_27),64);
        tracep->fullQData(oldp+421,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_28),64);
        tracep->fullQData(oldp+423,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcounterinhibit),64);
        tracep->fullQData(oldp+425,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_0),64);
        tracep->fullQData(oldp+427,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_1),64);
        tracep->fullQData(oldp+429,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_2),64);
        tracep->fullQData(oldp+431,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_3),64);
        tracep->fullQData(oldp+433,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_4),64);
        tracep->fullQData(oldp+435,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_5),64);
        tracep->fullQData(oldp+437,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_6),64);
        tracep->fullQData(oldp+439,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_7),64);
        tracep->fullQData(oldp+441,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_8),64);
        tracep->fullQData(oldp+443,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_9),64);
        tracep->fullQData(oldp+445,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_10),64);
        tracep->fullQData(oldp+447,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_11),64);
        tracep->fullQData(oldp+449,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_12),64);
        tracep->fullQData(oldp+451,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_13),64);
        tracep->fullQData(oldp+453,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_14),64);
        tracep->fullQData(oldp+455,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_15),64);
        tracep->fullQData(oldp+457,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_16),64);
        tracep->fullQData(oldp+459,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_17),64);
        tracep->fullQData(oldp+461,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_18),64);
        tracep->fullQData(oldp+463,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_19),64);
        tracep->fullQData(oldp+465,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_20),64);
        tracep->fullQData(oldp+467,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_21),64);
        tracep->fullQData(oldp+469,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_22),64);
        tracep->fullQData(oldp+471,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_23),64);
        tracep->fullQData(oldp+473,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_24),64);
        tracep->fullQData(oldp+475,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_25),64);
        tracep->fullQData(oldp+477,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_26),64);
        tracep->fullQData(oldp+479,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_27),64);
        tracep->fullQData(oldp+481,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_28),64);
        tracep->fullSData(oldp+483,((0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U)))),12);
        tracep->fullCData(oldp+484,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op),3);
        tracep->fullBit(oldp+485,((3U == (3U & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x1eU))))));
        tracep->fullBit(oldp+486,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__write_illegal));
        tracep->fullBit(oldp+487,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_legal));
        tracep->fullBit(oldp+488,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__read_illegal));
        tracep->fullBit(oldp+489,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr));
        tracep->fullBit(oldp+490,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable));
        tracep->fullQData(oldp+491,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data),64);
        tracep->fullQData(oldp+493,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data),64);
        tracep->fullBit(oldp+495,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen));
        tracep->fullBit(oldp+496,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall));
        tracep->fullBit(oldp+497,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak));
        tracep->fullBit(oldp+498,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret));
        tracep->fullBit(oldp+499,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception));
        tracep->fullBit(oldp+500,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt));
        tracep->fullCData(oldp+501,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now),2);
        tracep->fullBit(oldp+502,(vlTOPp->clock));
        tracep->fullBit(oldp+503,(vlTOPp->reset));
        tracep->fullQData(oldp+504,(vlTOPp->io_diffTestIO_regfile_0),64);
        tracep->fullQData(oldp+506,(vlTOPp->io_diffTestIO_regfile_1),64);
        tracep->fullQData(oldp+508,(vlTOPp->io_diffTestIO_regfile_2),64);
        tracep->fullQData(oldp+510,(vlTOPp->io_diffTestIO_regfile_3),64);
        tracep->fullQData(oldp+512,(vlTOPp->io_diffTestIO_regfile_4),64);
        tracep->fullQData(oldp+514,(vlTOPp->io_diffTestIO_regfile_5),64);
        tracep->fullQData(oldp+516,(vlTOPp->io_diffTestIO_regfile_6),64);
        tracep->fullQData(oldp+518,(vlTOPp->io_diffTestIO_regfile_7),64);
        tracep->fullQData(oldp+520,(vlTOPp->io_diffTestIO_regfile_8),64);
        tracep->fullQData(oldp+522,(vlTOPp->io_diffTestIO_regfile_9),64);
        tracep->fullQData(oldp+524,(vlTOPp->io_diffTestIO_regfile_10),64);
        tracep->fullQData(oldp+526,(vlTOPp->io_diffTestIO_regfile_11),64);
        tracep->fullQData(oldp+528,(vlTOPp->io_diffTestIO_regfile_12),64);
        tracep->fullQData(oldp+530,(vlTOPp->io_diffTestIO_regfile_13),64);
        tracep->fullQData(oldp+532,(vlTOPp->io_diffTestIO_regfile_14),64);
        tracep->fullQData(oldp+534,(vlTOPp->io_diffTestIO_regfile_15),64);
        tracep->fullQData(oldp+536,(vlTOPp->io_diffTestIO_regfile_16),64);
        tracep->fullQData(oldp+538,(vlTOPp->io_diffTestIO_regfile_17),64);
        tracep->fullQData(oldp+540,(vlTOPp->io_diffTestIO_regfile_18),64);
        tracep->fullQData(oldp+542,(vlTOPp->io_diffTestIO_regfile_19),64);
        tracep->fullQData(oldp+544,(vlTOPp->io_diffTestIO_regfile_20),64);
        tracep->fullQData(oldp+546,(vlTOPp->io_diffTestIO_regfile_21),64);
        tracep->fullQData(oldp+548,(vlTOPp->io_diffTestIO_regfile_22),64);
        tracep->fullQData(oldp+550,(vlTOPp->io_diffTestIO_regfile_23),64);
        tracep->fullQData(oldp+552,(vlTOPp->io_diffTestIO_regfile_24),64);
        tracep->fullQData(oldp+554,(vlTOPp->io_diffTestIO_regfile_25),64);
        tracep->fullQData(oldp+556,(vlTOPp->io_diffTestIO_regfile_26),64);
        tracep->fullQData(oldp+558,(vlTOPp->io_diffTestIO_regfile_27),64);
        tracep->fullQData(oldp+560,(vlTOPp->io_diffTestIO_regfile_28),64);
        tracep->fullQData(oldp+562,(vlTOPp->io_diffTestIO_regfile_29),64);
        tracep->fullQData(oldp+564,(vlTOPp->io_diffTestIO_regfile_30),64);
        tracep->fullQData(oldp+566,(vlTOPp->io_diffTestIO_regfile_31),64);
        tracep->fullQData(oldp+568,(vlTOPp->io_diffTestIO_pc),64);
        tracep->fullBit(oldp+570,(vlTOPp->io_diffTestIO_valid));
        tracep->fullQData(oldp+571,(vlTOPp->io_coreIO_inst_readIO_addr),64);
        tracep->fullQData(oldp+573,(vlTOPp->io_coreIO_inst_readIO_data),64);
        tracep->fullBit(oldp+575,(vlTOPp->io_coreIO_inst_readIO_en));
        tracep->fullQData(oldp+576,(vlTOPp->io_coreIO_data_readIO_addr),64);
        tracep->fullQData(oldp+578,(vlTOPp->io_coreIO_data_readIO_data),64);
        tracep->fullBit(oldp+580,(vlTOPp->io_coreIO_data_readIO_en));
        tracep->fullQData(oldp+581,(vlTOPp->io_coreIO_data_writeIO_addr),64);
        tracep->fullQData(oldp+583,(vlTOPp->io_coreIO_data_writeIO_data),64);
        tracep->fullBit(oldp+585,(vlTOPp->io_coreIO_data_writeIO_en));
        tracep->fullCData(oldp+586,(vlTOPp->io_coreIO_data_writeIO_mask),8);
        tracep->fullCData(oldp+587,(0U),5);
        tracep->fullCData(oldp+588,(1U),5);
        tracep->fullCData(oldp+589,(2U),5);
        tracep->fullCData(oldp+590,(3U),5);
        tracep->fullCData(oldp+591,(4U),5);
        tracep->fullCData(oldp+592,(5U),5);
        tracep->fullCData(oldp+593,(6U),5);
        tracep->fullCData(oldp+594,(7U),5);
        tracep->fullCData(oldp+595,(8U),5);
        tracep->fullCData(oldp+596,(9U),5);
        tracep->fullCData(oldp+597,(0xaU),5);
        tracep->fullCData(oldp+598,(0xbU),5);
        tracep->fullCData(oldp+599,(0xcU),5);
        tracep->fullCData(oldp+600,(0xdU),5);
        tracep->fullCData(oldp+601,(0xeU),5);
        tracep->fullCData(oldp+602,(0xfU),5);
        tracep->fullCData(oldp+603,(0x10U),5);
        tracep->fullCData(oldp+604,(0x11U),5);
        tracep->fullCData(oldp+605,(0x12U),5);
        tracep->fullCData(oldp+606,(0x13U),5);
        tracep->fullCData(oldp+607,(0x14U),5);
        tracep->fullCData(oldp+608,(0x15U),5);
        tracep->fullCData(oldp+609,(0x16U),5);
        tracep->fullCData(oldp+610,(0x17U),5);
        tracep->fullCData(oldp+611,(0x18U),5);
        tracep->fullCData(oldp+612,(0x19U),5);
        tracep->fullCData(oldp+613,(0x1aU),5);
        tracep->fullCData(oldp+614,(0x1bU),5);
        tracep->fullCData(oldp+615,(0x1cU),5);
        tracep->fullCData(oldp+616,(0x1dU),5);
        tracep->fullCData(oldp+617,(0x1eU),5);
        tracep->fullCData(oldp+618,(0x1fU),5);
        tracep->fullBit(oldp+619,(1U));
    }
}
