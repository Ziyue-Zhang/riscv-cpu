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
        tracep->declBit(c+514,"clock", false,-1);
        tracep->declBit(c+515,"reset", false,-1);
        tracep->declQuad(c+516,"io_diffTestIO_regfile_0", false,-1, 63,0);
        tracep->declQuad(c+518,"io_diffTestIO_regfile_1", false,-1, 63,0);
        tracep->declQuad(c+520,"io_diffTestIO_regfile_2", false,-1, 63,0);
        tracep->declQuad(c+522,"io_diffTestIO_regfile_3", false,-1, 63,0);
        tracep->declQuad(c+524,"io_diffTestIO_regfile_4", false,-1, 63,0);
        tracep->declQuad(c+526,"io_diffTestIO_regfile_5", false,-1, 63,0);
        tracep->declQuad(c+528,"io_diffTestIO_regfile_6", false,-1, 63,0);
        tracep->declQuad(c+530,"io_diffTestIO_regfile_7", false,-1, 63,0);
        tracep->declQuad(c+532,"io_diffTestIO_regfile_8", false,-1, 63,0);
        tracep->declQuad(c+534,"io_diffTestIO_regfile_9", false,-1, 63,0);
        tracep->declQuad(c+536,"io_diffTestIO_regfile_10", false,-1, 63,0);
        tracep->declQuad(c+538,"io_diffTestIO_regfile_11", false,-1, 63,0);
        tracep->declQuad(c+540,"io_diffTestIO_regfile_12", false,-1, 63,0);
        tracep->declQuad(c+542,"io_diffTestIO_regfile_13", false,-1, 63,0);
        tracep->declQuad(c+544,"io_diffTestIO_regfile_14", false,-1, 63,0);
        tracep->declQuad(c+546,"io_diffTestIO_regfile_15", false,-1, 63,0);
        tracep->declQuad(c+548,"io_diffTestIO_regfile_16", false,-1, 63,0);
        tracep->declQuad(c+550,"io_diffTestIO_regfile_17", false,-1, 63,0);
        tracep->declQuad(c+552,"io_diffTestIO_regfile_18", false,-1, 63,0);
        tracep->declQuad(c+554,"io_diffTestIO_regfile_19", false,-1, 63,0);
        tracep->declQuad(c+556,"io_diffTestIO_regfile_20", false,-1, 63,0);
        tracep->declQuad(c+558,"io_diffTestIO_regfile_21", false,-1, 63,0);
        tracep->declQuad(c+560,"io_diffTestIO_regfile_22", false,-1, 63,0);
        tracep->declQuad(c+562,"io_diffTestIO_regfile_23", false,-1, 63,0);
        tracep->declQuad(c+564,"io_diffTestIO_regfile_24", false,-1, 63,0);
        tracep->declQuad(c+566,"io_diffTestIO_regfile_25", false,-1, 63,0);
        tracep->declQuad(c+568,"io_diffTestIO_regfile_26", false,-1, 63,0);
        tracep->declQuad(c+570,"io_diffTestIO_regfile_27", false,-1, 63,0);
        tracep->declQuad(c+572,"io_diffTestIO_regfile_28", false,-1, 63,0);
        tracep->declQuad(c+574,"io_diffTestIO_regfile_29", false,-1, 63,0);
        tracep->declQuad(c+576,"io_diffTestIO_regfile_30", false,-1, 63,0);
        tracep->declQuad(c+578,"io_diffTestIO_regfile_31", false,-1, 63,0);
        tracep->declQuad(c+580,"io_diffTestIO_pc", false,-1, 63,0);
        tracep->declBit(c+582,"io_diffTestIO_valid", false,-1);
        tracep->declQuad(c+583,"io_coreIO_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+585,"io_coreIO_inst_readIO_data", false,-1, 63,0);
        tracep->declBit(c+587,"io_coreIO_inst_readIO_en", false,-1);
        tracep->declQuad(c+588,"io_coreIO_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+590,"io_coreIO_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+592,"io_coreIO_data_readIO_en", false,-1);
        tracep->declQuad(c+593,"io_coreIO_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+595,"io_coreIO_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+597,"io_coreIO_data_writeIO_en", false,-1);
        tracep->declBus(c+598,"io_coreIO_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+514,"simTop clock", false,-1);
        tracep->declBit(c+515,"simTop reset", false,-1);
        tracep->declQuad(c+516,"simTop io_diffTestIO_regfile_0", false,-1, 63,0);
        tracep->declQuad(c+518,"simTop io_diffTestIO_regfile_1", false,-1, 63,0);
        tracep->declQuad(c+520,"simTop io_diffTestIO_regfile_2", false,-1, 63,0);
        tracep->declQuad(c+522,"simTop io_diffTestIO_regfile_3", false,-1, 63,0);
        tracep->declQuad(c+524,"simTop io_diffTestIO_regfile_4", false,-1, 63,0);
        tracep->declQuad(c+526,"simTop io_diffTestIO_regfile_5", false,-1, 63,0);
        tracep->declQuad(c+528,"simTop io_diffTestIO_regfile_6", false,-1, 63,0);
        tracep->declQuad(c+530,"simTop io_diffTestIO_regfile_7", false,-1, 63,0);
        tracep->declQuad(c+532,"simTop io_diffTestIO_regfile_8", false,-1, 63,0);
        tracep->declQuad(c+534,"simTop io_diffTestIO_regfile_9", false,-1, 63,0);
        tracep->declQuad(c+536,"simTop io_diffTestIO_regfile_10", false,-1, 63,0);
        tracep->declQuad(c+538,"simTop io_diffTestIO_regfile_11", false,-1, 63,0);
        tracep->declQuad(c+540,"simTop io_diffTestIO_regfile_12", false,-1, 63,0);
        tracep->declQuad(c+542,"simTop io_diffTestIO_regfile_13", false,-1, 63,0);
        tracep->declQuad(c+544,"simTop io_diffTestIO_regfile_14", false,-1, 63,0);
        tracep->declQuad(c+546,"simTop io_diffTestIO_regfile_15", false,-1, 63,0);
        tracep->declQuad(c+548,"simTop io_diffTestIO_regfile_16", false,-1, 63,0);
        tracep->declQuad(c+550,"simTop io_diffTestIO_regfile_17", false,-1, 63,0);
        tracep->declQuad(c+552,"simTop io_diffTestIO_regfile_18", false,-1, 63,0);
        tracep->declQuad(c+554,"simTop io_diffTestIO_regfile_19", false,-1, 63,0);
        tracep->declQuad(c+556,"simTop io_diffTestIO_regfile_20", false,-1, 63,0);
        tracep->declQuad(c+558,"simTop io_diffTestIO_regfile_21", false,-1, 63,0);
        tracep->declQuad(c+560,"simTop io_diffTestIO_regfile_22", false,-1, 63,0);
        tracep->declQuad(c+562,"simTop io_diffTestIO_regfile_23", false,-1, 63,0);
        tracep->declQuad(c+564,"simTop io_diffTestIO_regfile_24", false,-1, 63,0);
        tracep->declQuad(c+566,"simTop io_diffTestIO_regfile_25", false,-1, 63,0);
        tracep->declQuad(c+568,"simTop io_diffTestIO_regfile_26", false,-1, 63,0);
        tracep->declQuad(c+570,"simTop io_diffTestIO_regfile_27", false,-1, 63,0);
        tracep->declQuad(c+572,"simTop io_diffTestIO_regfile_28", false,-1, 63,0);
        tracep->declQuad(c+574,"simTop io_diffTestIO_regfile_29", false,-1, 63,0);
        tracep->declQuad(c+576,"simTop io_diffTestIO_regfile_30", false,-1, 63,0);
        tracep->declQuad(c+578,"simTop io_diffTestIO_regfile_31", false,-1, 63,0);
        tracep->declQuad(c+580,"simTop io_diffTestIO_pc", false,-1, 63,0);
        tracep->declBit(c+582,"simTop io_diffTestIO_valid", false,-1);
        tracep->declQuad(c+583,"simTop io_coreIO_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+585,"simTop io_coreIO_inst_readIO_data", false,-1, 63,0);
        tracep->declBit(c+587,"simTop io_coreIO_inst_readIO_en", false,-1);
        tracep->declQuad(c+588,"simTop io_coreIO_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+590,"simTop io_coreIO_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+592,"simTop io_coreIO_data_readIO_en", false,-1);
        tracep->declQuad(c+593,"simTop io_coreIO_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+595,"simTop io_coreIO_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+597,"simTop io_coreIO_data_writeIO_en", false,-1);
        tracep->declBus(c+598,"simTop io_coreIO_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+514,"simTop mycore_clock", false,-1);
        tracep->declBit(c+515,"simTop mycore_reset", false,-1);
        tracep->declQuad(c+1,"simTop mycore_io_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+585,"simTop mycore_io_inst_readIO_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore_io_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+590,"simTop mycore_io_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+5,"simTop mycore_io_data_readIO_en", false,-1);
        tracep->declQuad(c+6,"simTop mycore_io_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+8,"simTop mycore_io_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+10,"simTop mycore_io_data_writeIO_en", false,-1);
        tracep->declBus(c+11,"simTop mycore_io_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+12,"simTop mycore_wb_reg_valid", false,-1);
        tracep->declQuad(c+13,"simTop mycore__T_42_0", false,-1, 63,0);
        tracep->declQuad(c+15,"simTop mycore__T_42_1", false,-1, 63,0);
        tracep->declQuad(c+17,"simTop mycore__T_42_2", false,-1, 63,0);
        tracep->declQuad(c+19,"simTop mycore__T_42_3", false,-1, 63,0);
        tracep->declQuad(c+21,"simTop mycore__T_42_4", false,-1, 63,0);
        tracep->declQuad(c+23,"simTop mycore__T_42_5", false,-1, 63,0);
        tracep->declQuad(c+25,"simTop mycore__T_42_6", false,-1, 63,0);
        tracep->declQuad(c+27,"simTop mycore__T_42_7", false,-1, 63,0);
        tracep->declQuad(c+29,"simTop mycore__T_42_8", false,-1, 63,0);
        tracep->declQuad(c+31,"simTop mycore__T_42_9", false,-1, 63,0);
        tracep->declQuad(c+33,"simTop mycore__T_42_10", false,-1, 63,0);
        tracep->declQuad(c+35,"simTop mycore__T_42_11", false,-1, 63,0);
        tracep->declQuad(c+37,"simTop mycore__T_42_12", false,-1, 63,0);
        tracep->declQuad(c+39,"simTop mycore__T_42_13", false,-1, 63,0);
        tracep->declQuad(c+41,"simTop mycore__T_42_14", false,-1, 63,0);
        tracep->declQuad(c+43,"simTop mycore__T_42_15", false,-1, 63,0);
        tracep->declQuad(c+45,"simTop mycore__T_42_16", false,-1, 63,0);
        tracep->declQuad(c+47,"simTop mycore__T_42_17", false,-1, 63,0);
        tracep->declQuad(c+49,"simTop mycore__T_42_18", false,-1, 63,0);
        tracep->declQuad(c+51,"simTop mycore__T_42_19", false,-1, 63,0);
        tracep->declQuad(c+53,"simTop mycore__T_42_20", false,-1, 63,0);
        tracep->declQuad(c+55,"simTop mycore__T_42_21", false,-1, 63,0);
        tracep->declQuad(c+57,"simTop mycore__T_42_22", false,-1, 63,0);
        tracep->declQuad(c+59,"simTop mycore__T_42_23", false,-1, 63,0);
        tracep->declQuad(c+61,"simTop mycore__T_42_24", false,-1, 63,0);
        tracep->declQuad(c+63,"simTop mycore__T_42_25", false,-1, 63,0);
        tracep->declQuad(c+65,"simTop mycore__T_42_26", false,-1, 63,0);
        tracep->declQuad(c+67,"simTop mycore__T_42_27", false,-1, 63,0);
        tracep->declQuad(c+69,"simTop mycore__T_42_28", false,-1, 63,0);
        tracep->declQuad(c+71,"simTop mycore__T_42_29", false,-1, 63,0);
        tracep->declQuad(c+73,"simTop mycore__T_42_30", false,-1, 63,0);
        tracep->declQuad(c+75,"simTop mycore__T_42_31", false,-1, 63,0);
        tracep->declQuad(c+77,"simTop mycore_wb_reg_pc", false,-1, 63,0);
        tracep->declBit(c+514,"simTop mycore clock", false,-1);
        tracep->declBit(c+515,"simTop mycore reset", false,-1);
        tracep->declQuad(c+1,"simTop mycore io_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+585,"simTop mycore io_inst_readIO_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore io_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+590,"simTop mycore io_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+5,"simTop mycore io_data_readIO_en", false,-1);
        tracep->declQuad(c+6,"simTop mycore io_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+8,"simTop mycore io_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+10,"simTop mycore io_data_writeIO_en", false,-1);
        tracep->declBus(c+11,"simTop mycore io_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+12,"simTop mycore wb_reg_valid", false,-1);
        tracep->declQuad(c+77,"simTop mycore wb_reg_pc", false,-1, 63,0);
        tracep->declBit(c+514,"simTop mycore cpath_clock", false,-1);
        tracep->declBit(c+515,"simTop mycore cpath_reset", false,-1);
        tracep->declQuad(c+79,"simTop mycore cpath_io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+81,"simTop mycore cpath_io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+82,"simTop mycore cpath_io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+83,"simTop mycore cpath_io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+84,"simTop mycore cpath_io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+85,"simTop mycore cpath_io_dat_csr_eret", false,-1);
        tracep->declBit(c+86,"simTop mycore cpath_io_ctl_dec_stall", false,-1);
        tracep->declBus(c+87,"simTop mycore cpath_io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+88,"simTop mycore cpath_io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+89,"simTop mycore cpath_io_ctl_if_kill", false,-1);
        tracep->declBit(c+90,"simTop mycore cpath_io_ctl_dec_kill", false,-1);
        tracep->declBus(c+91,"simTop mycore cpath_io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+92,"simTop mycore cpath_io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+93,"simTop mycore cpath_io_ctl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+94,"simTop mycore cpath_io_ctl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+95,"simTop mycore cpath_io_ctl_rf_wen", false,-1);
        tracep->declBus(c+96,"simTop mycore cpath_io_ctl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+97,"simTop mycore cpath_io_ctl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+98,"simTop mycore cpath_io_ctl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+99,"simTop mycore cpath_io_ctl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+100,"simTop mycore cpath_io_ctl_fencei", false,-1);
        tracep->declBit(c+85,"simTop mycore cpath_io_ctl_pipeline_kill", false,-1);
        tracep->declBit(c+514,"simTop mycore dpath_clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath_reset", false,-1);
        tracep->declBit(c+86,"simTop mycore dpath_io_ctl_dec_stall", false,-1);
        tracep->declBus(c+87,"simTop mycore dpath_io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+88,"simTop mycore dpath_io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+89,"simTop mycore dpath_io_ctl_if_kill", false,-1);
        tracep->declBit(c+90,"simTop mycore dpath_io_ctl_dec_kill", false,-1);
        tracep->declBus(c+91,"simTop mycore dpath_io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+92,"simTop mycore dpath_io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+93,"simTop mycore dpath_io_ctl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+94,"simTop mycore dpath_io_ctl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+95,"simTop mycore dpath_io_ctl_rf_wen", false,-1);
        tracep->declBus(c+96,"simTop mycore dpath_io_ctl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+97,"simTop mycore dpath_io_ctl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+98,"simTop mycore dpath_io_ctl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+99,"simTop mycore dpath_io_ctl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+100,"simTop mycore dpath_io_ctl_fencei", false,-1);
        tracep->declBit(c+85,"simTop mycore dpath_io_ctl_pipeline_kill", false,-1);
        tracep->declQuad(c+79,"simTop mycore dpath_io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+81,"simTop mycore dpath_io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+82,"simTop mycore dpath_io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+83,"simTop mycore dpath_io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+84,"simTop mycore dpath_io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+85,"simTop mycore dpath_io_dat_csr_eret", false,-1);
        tracep->declQuad(c+1,"simTop mycore dpath_io_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+585,"simTop mycore dpath_io_inst_readIO_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore dpath_io_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+590,"simTop mycore dpath_io_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+5,"simTop mycore dpath_io_data_readIO_en", false,-1);
        tracep->declQuad(c+6,"simTop mycore dpath_io_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+8,"simTop mycore dpath_io_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+10,"simTop mycore dpath_io_data_writeIO_en", false,-1);
        tracep->declBus(c+11,"simTop mycore dpath_io_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+12,"simTop mycore dpath_wb_reg_valid_0", false,-1);
        tracep->declQuad(c+13,"simTop mycore dpath__T_42_0_0", false,-1, 63,0);
        tracep->declQuad(c+15,"simTop mycore dpath__T_42_0_1", false,-1, 63,0);
        tracep->declQuad(c+17,"simTop mycore dpath__T_42_0_2", false,-1, 63,0);
        tracep->declQuad(c+19,"simTop mycore dpath__T_42_0_3", false,-1, 63,0);
        tracep->declQuad(c+21,"simTop mycore dpath__T_42_0_4", false,-1, 63,0);
        tracep->declQuad(c+23,"simTop mycore dpath__T_42_0_5", false,-1, 63,0);
        tracep->declQuad(c+25,"simTop mycore dpath__T_42_0_6", false,-1, 63,0);
        tracep->declQuad(c+27,"simTop mycore dpath__T_42_0_7", false,-1, 63,0);
        tracep->declQuad(c+29,"simTop mycore dpath__T_42_0_8", false,-1, 63,0);
        tracep->declQuad(c+31,"simTop mycore dpath__T_42_0_9", false,-1, 63,0);
        tracep->declQuad(c+33,"simTop mycore dpath__T_42_0_10", false,-1, 63,0);
        tracep->declQuad(c+35,"simTop mycore dpath__T_42_0_11", false,-1, 63,0);
        tracep->declQuad(c+37,"simTop mycore dpath__T_42_0_12", false,-1, 63,0);
        tracep->declQuad(c+39,"simTop mycore dpath__T_42_0_13", false,-1, 63,0);
        tracep->declQuad(c+41,"simTop mycore dpath__T_42_0_14", false,-1, 63,0);
        tracep->declQuad(c+43,"simTop mycore dpath__T_42_0_15", false,-1, 63,0);
        tracep->declQuad(c+45,"simTop mycore dpath__T_42_0_16", false,-1, 63,0);
        tracep->declQuad(c+47,"simTop mycore dpath__T_42_0_17", false,-1, 63,0);
        tracep->declQuad(c+49,"simTop mycore dpath__T_42_0_18", false,-1, 63,0);
        tracep->declQuad(c+51,"simTop mycore dpath__T_42_0_19", false,-1, 63,0);
        tracep->declQuad(c+53,"simTop mycore dpath__T_42_0_20", false,-1, 63,0);
        tracep->declQuad(c+55,"simTop mycore dpath__T_42_0_21", false,-1, 63,0);
        tracep->declQuad(c+57,"simTop mycore dpath__T_42_0_22", false,-1, 63,0);
        tracep->declQuad(c+59,"simTop mycore dpath__T_42_0_23", false,-1, 63,0);
        tracep->declQuad(c+61,"simTop mycore dpath__T_42_0_24", false,-1, 63,0);
        tracep->declQuad(c+63,"simTop mycore dpath__T_42_0_25", false,-1, 63,0);
        tracep->declQuad(c+65,"simTop mycore dpath__T_42_0_26", false,-1, 63,0);
        tracep->declQuad(c+67,"simTop mycore dpath__T_42_0_27", false,-1, 63,0);
        tracep->declQuad(c+69,"simTop mycore dpath__T_42_0_28", false,-1, 63,0);
        tracep->declQuad(c+71,"simTop mycore dpath__T_42_0_29", false,-1, 63,0);
        tracep->declQuad(c+73,"simTop mycore dpath__T_42_0_30", false,-1, 63,0);
        tracep->declQuad(c+75,"simTop mycore dpath__T_42_0_31", false,-1, 63,0);
        tracep->declQuad(c+77,"simTop mycore dpath_wb_reg_pc_0", false,-1, 63,0);
        tracep->declBit(c+514,"simTop mycore cpath clock", false,-1);
        tracep->declBit(c+515,"simTop mycore cpath reset", false,-1);
        tracep->declQuad(c+79,"simTop mycore cpath io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+81,"simTop mycore cpath io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+82,"simTop mycore cpath io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+83,"simTop mycore cpath io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+84,"simTop mycore cpath io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+85,"simTop mycore cpath io_dat_csr_eret", false,-1);
        tracep->declBit(c+86,"simTop mycore cpath io_ctl_dec_stall", false,-1);
        tracep->declBus(c+87,"simTop mycore cpath io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+88,"simTop mycore cpath io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+89,"simTop mycore cpath io_ctl_if_kill", false,-1);
        tracep->declBit(c+90,"simTop mycore cpath io_ctl_dec_kill", false,-1);
        tracep->declBus(c+91,"simTop mycore cpath io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+92,"simTop mycore cpath io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+93,"simTop mycore cpath io_ctl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+94,"simTop mycore cpath io_ctl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+95,"simTop mycore cpath io_ctl_rf_wen", false,-1);
        tracep->declBus(c+96,"simTop mycore cpath io_ctl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+97,"simTop mycore cpath io_ctl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+98,"simTop mycore cpath io_ctl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+99,"simTop mycore cpath io_ctl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+100,"simTop mycore cpath io_ctl_fencei", false,-1);
        tracep->declBit(c+85,"simTop mycore cpath io_ctl_pipeline_kill", false,-1);
        tracep->declBit(c+101,"simTop mycore cpath cs_rs1_oen", false,-1);
        tracep->declBit(c+102,"simTop mycore cpath cs_rs2_oen", false,-1);
        tracep->declBus(c+93,"simTop mycore cpath cs0_0", false,-1, 4,0);
        tracep->declBit(c+103,"simTop mycore cpath cs0_3", false,-1);
        tracep->declBus(c+96,"simTop mycore cpath cs0_4", false,-1, 1,0);
        tracep->declBus(c+104,"simTop mycore cpath cs0_7", false,-1, 2,0);
        tracep->declBit(c+105,"simTop mycore cpath cs0_8", false,-1);
        tracep->declBus(c+87,"simTop mycore cpath ctrl_exe_pc_sel", false,-1, 1,0);
        tracep->declBit(c+106,"simTop mycore cpath ifkill", false,-1);
        tracep->declBus(c+107,"simTop mycore cpath dec_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+108,"simTop mycore cpath dec_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+109,"simTop mycore cpath dec_wbaddr", false,-1, 4,0);
        tracep->declBit(c+110,"simTop mycore cpath dec_rs1_oen", false,-1);
        tracep->declBit(c+111,"simTop mycore cpath dec_rs2_oen", false,-1);
        tracep->declBus(c+112,"simTop mycore cpath exe_reg_wbaddr", false,-1, 4,0);
        tracep->declBit(c+113,"simTop mycore cpath exe_reg_is_csr", false,-1);
        tracep->declBit(c+114,"simTop mycore cpath exe_inst_is_load", false,-1);
        tracep->declBit(c+86,"simTop mycore cpath stall", false,-1);
        tracep->declBit(c+514,"simTop mycore dpath clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath reset", false,-1);
        tracep->declBit(c+86,"simTop mycore dpath io_ctl_dec_stall", false,-1);
        tracep->declBus(c+87,"simTop mycore dpath io_ctl_exe_pc_sel", false,-1, 1,0);
        tracep->declBus(c+88,"simTop mycore dpath io_ctl_br_type", false,-1, 3,0);
        tracep->declBit(c+89,"simTop mycore dpath io_ctl_if_kill", false,-1);
        tracep->declBit(c+90,"simTop mycore dpath io_ctl_dec_kill", false,-1);
        tracep->declBus(c+91,"simTop mycore dpath io_ctl_op1_sel", false,-1, 1,0);
        tracep->declBus(c+92,"simTop mycore dpath io_ctl_op2_sel", false,-1, 2,0);
        tracep->declBus(c+93,"simTop mycore dpath io_ctl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+94,"simTop mycore dpath io_ctl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+95,"simTop mycore dpath io_ctl_rf_wen", false,-1);
        tracep->declBus(c+96,"simTop mycore dpath io_ctl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+97,"simTop mycore dpath io_ctl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+98,"simTop mycore dpath io_ctl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+99,"simTop mycore dpath io_ctl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+100,"simTop mycore dpath io_ctl_fencei", false,-1);
        tracep->declBit(c+85,"simTop mycore dpath io_ctl_pipeline_kill", false,-1);
        tracep->declQuad(c+79,"simTop mycore dpath io_dat_dec_inst", false,-1, 63,0);
        tracep->declBit(c+81,"simTop mycore dpath io_dat_exe_br_eq", false,-1);
        tracep->declBit(c+82,"simTop mycore dpath io_dat_exe_br_lt", false,-1);
        tracep->declBit(c+83,"simTop mycore dpath io_dat_exe_br_ltu", false,-1);
        tracep->declBus(c+84,"simTop mycore dpath io_dat_exe_br_type", false,-1, 3,0);
        tracep->declBit(c+85,"simTop mycore dpath io_dat_csr_eret", false,-1);
        tracep->declQuad(c+1,"simTop mycore dpath io_inst_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+585,"simTop mycore dpath io_inst_readIO_data", false,-1, 63,0);
        tracep->declQuad(c+3,"simTop mycore dpath io_data_readIO_addr", false,-1, 63,0);
        tracep->declQuad(c+590,"simTop mycore dpath io_data_readIO_data", false,-1, 63,0);
        tracep->declBit(c+5,"simTop mycore dpath io_data_readIO_en", false,-1);
        tracep->declQuad(c+6,"simTop mycore dpath io_data_writeIO_addr", false,-1, 63,0);
        tracep->declQuad(c+8,"simTop mycore dpath io_data_writeIO_data", false,-1, 63,0);
        tracep->declBit(c+10,"simTop mycore dpath io_data_writeIO_en", false,-1);
        tracep->declBus(c+11,"simTop mycore dpath io_data_writeIO_mask", false,-1, 7,0);
        tracep->declBit(c+12,"simTop mycore dpath wb_reg_valid_0", false,-1);
        tracep->declQuad(c+77,"simTop mycore dpath wb_reg_pc_0", false,-1, 63,0);
        tracep->declBit(c+514,"simTop mycore dpath regfile_clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath regfile_reset", false,-1);
        tracep->declBus(c+107,"simTop mycore dpath regfile_io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+115,"simTop mycore dpath regfile_io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+108,"simTop mycore dpath regfile_io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+117,"simTop mycore dpath regfile_io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+119,"simTop mycore dpath regfile_io_waddr", false,-1, 4,0);
        tracep->declQuad(c+120,"simTop mycore dpath regfile_io_wdata", false,-1, 63,0);
        tracep->declBit(c+122,"simTop mycore dpath regfile_io_wen", false,-1);
        tracep->declQuad(c+13,"simTop mycore dpath regfile__T_42_0_0", false,-1, 63,0);
        tracep->declQuad(c+15,"simTop mycore dpath regfile__T_42_0_1", false,-1, 63,0);
        tracep->declQuad(c+17,"simTop mycore dpath regfile__T_42_0_2", false,-1, 63,0);
        tracep->declQuad(c+19,"simTop mycore dpath regfile__T_42_0_3", false,-1, 63,0);
        tracep->declQuad(c+21,"simTop mycore dpath regfile__T_42_0_4", false,-1, 63,0);
        tracep->declQuad(c+23,"simTop mycore dpath regfile__T_42_0_5", false,-1, 63,0);
        tracep->declQuad(c+25,"simTop mycore dpath regfile__T_42_0_6", false,-1, 63,0);
        tracep->declQuad(c+27,"simTop mycore dpath regfile__T_42_0_7", false,-1, 63,0);
        tracep->declQuad(c+29,"simTop mycore dpath regfile__T_42_0_8", false,-1, 63,0);
        tracep->declQuad(c+31,"simTop mycore dpath regfile__T_42_0_9", false,-1, 63,0);
        tracep->declQuad(c+33,"simTop mycore dpath regfile__T_42_0_10", false,-1, 63,0);
        tracep->declQuad(c+35,"simTop mycore dpath regfile__T_42_0_11", false,-1, 63,0);
        tracep->declQuad(c+37,"simTop mycore dpath regfile__T_42_0_12", false,-1, 63,0);
        tracep->declQuad(c+39,"simTop mycore dpath regfile__T_42_0_13", false,-1, 63,0);
        tracep->declQuad(c+41,"simTop mycore dpath regfile__T_42_0_14", false,-1, 63,0);
        tracep->declQuad(c+43,"simTop mycore dpath regfile__T_42_0_15", false,-1, 63,0);
        tracep->declQuad(c+45,"simTop mycore dpath regfile__T_42_0_16", false,-1, 63,0);
        tracep->declQuad(c+47,"simTop mycore dpath regfile__T_42_0_17", false,-1, 63,0);
        tracep->declQuad(c+49,"simTop mycore dpath regfile__T_42_0_18", false,-1, 63,0);
        tracep->declQuad(c+51,"simTop mycore dpath regfile__T_42_0_19", false,-1, 63,0);
        tracep->declQuad(c+53,"simTop mycore dpath regfile__T_42_0_20", false,-1, 63,0);
        tracep->declQuad(c+55,"simTop mycore dpath regfile__T_42_0_21", false,-1, 63,0);
        tracep->declQuad(c+57,"simTop mycore dpath regfile__T_42_0_22", false,-1, 63,0);
        tracep->declQuad(c+59,"simTop mycore dpath regfile__T_42_0_23", false,-1, 63,0);
        tracep->declQuad(c+61,"simTop mycore dpath regfile__T_42_0_24", false,-1, 63,0);
        tracep->declQuad(c+63,"simTop mycore dpath regfile__T_42_0_25", false,-1, 63,0);
        tracep->declQuad(c+65,"simTop mycore dpath regfile__T_42_0_26", false,-1, 63,0);
        tracep->declQuad(c+67,"simTop mycore dpath regfile__T_42_0_27", false,-1, 63,0);
        tracep->declQuad(c+69,"simTop mycore dpath regfile__T_42_0_28", false,-1, 63,0);
        tracep->declQuad(c+71,"simTop mycore dpath regfile__T_42_0_29", false,-1, 63,0);
        tracep->declQuad(c+73,"simTop mycore dpath regfile__T_42_0_30", false,-1, 63,0);
        tracep->declQuad(c+75,"simTop mycore dpath regfile__T_42_0_31", false,-1, 63,0);
        tracep->declBit(c+514,"simTop mycore dpath alu_clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath alu_reset", false,-1);
        tracep->declQuad(c+123,"simTop mycore dpath alu_io_src1", false,-1, 63,0);
        tracep->declQuad(c+125,"simTop mycore dpath alu_io_src2", false,-1, 63,0);
        tracep->declBus(c+127,"simTop mycore dpath alu_io_op", false,-1, 4,0);
        tracep->declQuad(c+128,"simTop mycore dpath alu_io_res", false,-1, 63,0);
        tracep->declBit(c+130,"simTop mycore dpath alu_io_stall", false,-1);
        tracep->declBit(c+514,"simTop mycore dpath csr_clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath csr_reset", false,-1);
        tracep->declBus(c+131,"simTop mycore dpath csr_io_inst", false,-1, 31,0);
        tracep->declBus(c+132,"simTop mycore dpath csr_io_csr_op", false,-1, 2,0);
        tracep->declQuad(c+133,"simTop mycore dpath csr_io_data_in", false,-1, 63,0);
        tracep->declBit(c+130,"simTop mycore dpath csr_io_has_stall", false,-1);
        tracep->declQuad(c+135,"simTop mycore dpath csr_io_in_mem_pc", false,-1, 63,0);
        tracep->declQuad(c+137,"simTop mycore dpath csr_io_in_exe_pc", false,-1, 63,0);
        tracep->declQuad(c+139,"simTop mycore dpath csr_io_in_dec_pc", false,-1, 63,0);
        tracep->declQuad(c+1,"simTop mycore dpath csr_io_in_if_pc", false,-1, 63,0);
        tracep->declBit(c+85,"simTop mycore dpath csr_io_is_redir", false,-1);
        tracep->declQuad(c+1,"simTop mycore dpath if_reg_pc", false,-1, 63,0);
        tracep->declBit(c+141,"simTop mycore dpath dec_reg_valid", false,-1);
        tracep->declQuad(c+79,"simTop mycore dpath dec_reg_inst", false,-1, 63,0);
        tracep->declQuad(c+139,"simTop mycore dpath dec_reg_pc", false,-1, 63,0);
        tracep->declBit(c+142,"simTop mycore dpath exe_reg_valid", false,-1);
        tracep->declQuad(c+143,"simTop mycore dpath exe_reg_inst", false,-1, 63,0);
        tracep->declQuad(c+137,"simTop mycore dpath exe_reg_pc", false,-1, 63,0);
        tracep->declBus(c+145,"simTop mycore dpath exe_reg_wbaddr", false,-1, 4,0);
        tracep->declQuad(c+123,"simTop mycore dpath exe_alu_op1", false,-1, 63,0);
        tracep->declQuad(c+125,"simTop mycore dpath brjmp_offset", false,-1, 63,0);
        tracep->declQuad(c+146,"simTop mycore dpath exe_reg_rs2_data", false,-1, 63,0);
        tracep->declBus(c+84,"simTop mycore dpath exe_reg_ctrl_br_type", false,-1, 3,0);
        tracep->declBus(c+127,"simTop mycore dpath exe_reg_ctrl_alu_fun", false,-1, 4,0);
        tracep->declBus(c+148,"simTop mycore dpath exe_reg_ctrl_wb_sel", false,-1, 2,0);
        tracep->declBit(c+149,"simTop mycore dpath exe_reg_ctrl_rf_wen", false,-1);
        tracep->declBus(c+150,"simTop mycore dpath exe_reg_ctrl_mem_fcn", false,-1, 1,0);
        tracep->declBus(c+151,"simTop mycore dpath exe_reg_ctrl_mem_typ", false,-1, 7,0);
        tracep->declBus(c+152,"simTop mycore dpath exe_reg_ctrl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+153,"simTop mycore dpath exe_reg_ctrl_csr_cmd", false,-1, 2,0);
        tracep->declBit(c+154,"simTop mycore dpath mem_reg_valid", false,-1);
        tracep->declQuad(c+135,"simTop mycore dpath mem_reg_pc", false,-1, 63,0);
        tracep->declQuad(c+155,"simTop mycore dpath mem_reg_inst", false,-1, 63,0);
        tracep->declQuad(c+133,"simTop mycore dpath mem_reg_alu_out", false,-1, 63,0);
        tracep->declBus(c+157,"simTop mycore dpath mem_reg_wbaddr", false,-1, 4,0);
        tracep->declBit(c+158,"simTop mycore dpath mem_reg_ctrl_rf_wen", false,-1);
        tracep->declBus(c+159,"simTop mycore dpath mem_reg_ctrl_wb_sel", false,-1, 2,0);
        tracep->declBus(c+160,"simTop mycore dpath mem_reg_ctrl_mem_wid", false,-1, 2,0);
        tracep->declBus(c+132,"simTop mycore dpath mem_reg_ctrl_csr_cmd", false,-1, 2,0);
        tracep->declQuad(c+161,"simTop mycore dpath mem_reg_dram_data", false,-1, 63,0);
        tracep->declBit(c+12,"simTop mycore dpath wb_reg_valid", false,-1);
        tracep->declQuad(c+77,"simTop mycore dpath wb_reg_pc", false,-1, 63,0);
        tracep->declBus(c+119,"simTop mycore dpath wb_reg_wbaddr", false,-1, 4,0);
        tracep->declQuad(c+120,"simTop mycore dpath wb_reg_wbdata", false,-1, 63,0);
        tracep->declBit(c+122,"simTop mycore dpath wb_reg_ctrl_rf_wen", false,-1);
        tracep->declBit(c+130,"simTop mycore dpath alu_stall", false,-1);
        tracep->declQuad(c+163,"simTop mycore dpath if_pc_plus4", false,-1, 63,0);
        tracep->declQuad(c+165,"simTop mycore dpath exe_brjmp_target", false,-1, 63,0);
        tracep->declQuad(c+167,"simTop mycore dpath exe_adder_out", false,-1, 63,0);
        tracep->declQuad(c+169,"simTop mycore dpath if_pc_next", false,-1, 63,0);
        tracep->declBus(c+107,"simTop mycore dpath dec_rs1_addr", false,-1, 4,0);
        tracep->declBus(c+108,"simTop mycore dpath dec_rs2_addr", false,-1, 4,0);
        tracep->declBus(c+109,"simTop mycore dpath dec_wbaddr", false,-1, 4,0);
        tracep->declBus(c+171,"simTop mycore dpath imm_itype", false,-1, 11,0);
        tracep->declBus(c+172,"simTop mycore dpath imm_stype", false,-1, 11,0);
        tracep->declBus(c+173,"simTop mycore dpath imm_sbtype", false,-1, 11,0);
        tracep->declBus(c+174,"simTop mycore dpath imm_utype", false,-1, 19,0);
        tracep->declBus(c+175,"simTop mycore dpath imm_ujtype", false,-1, 19,0);
        tracep->declBus(c+176,"simTop mycore dpath imm_z", false,-1, 31,0);
        tracep->declQuad(c+177,"simTop mycore dpath imm_itype_sext", false,-1, 63,0);
        tracep->declQuad(c+179,"simTop mycore dpath imm_stype_sext", false,-1, 63,0);
        tracep->declQuad(c+181,"simTop mycore dpath imm_sbtype_sext", false,-1, 63,0);
        tracep->declQuad(c+183,"simTop mycore dpath imm_utype_sext", false,-1, 63,0);
        tracep->declQuad(c+185,"simTop mycore dpath imm_ujtype_sext", false,-1, 63,0);
        tracep->declQuad(c+187,"simTop mycore dpath dec_alu_op2", false,-1, 63,0);
        tracep->declQuad(c+189,"simTop mycore dpath mem_data", false,-1, 63,0);
        tracep->declQuad(c+191,"simTop mycore dpath mem_wbdata", false,-1, 63,0);
        tracep->declQuad(c+193,"simTop mycore dpath exe_alu_out", false,-1, 63,0);
        tracep->declQuad(c+195,"simTop mycore dpath dec_rs1_data", false,-1, 63,0);
        tracep->declQuad(c+197,"simTop mycore dpath dec_op1_data", false,-1, 63,0);
        tracep->declQuad(c+199,"simTop mycore dpath dec_op2_data", false,-1, 63,0);
        tracep->declQuad(c+201,"simTop mycore dpath exe_pc_plus4", false,-1, 63,0);
        tracep->declBit(c+514,"simTop mycore dpath regfile clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath regfile reset", false,-1);
        tracep->declBus(c+107,"simTop mycore dpath regfile io_rs1_addr", false,-1, 4,0);
        tracep->declQuad(c+115,"simTop mycore dpath regfile io_rs1_data", false,-1, 63,0);
        tracep->declBus(c+108,"simTop mycore dpath regfile io_rs2_addr", false,-1, 4,0);
        tracep->declQuad(c+117,"simTop mycore dpath regfile io_rs2_data", false,-1, 63,0);
        tracep->declBus(c+119,"simTop mycore dpath regfile io_waddr", false,-1, 4,0);
        tracep->declQuad(c+120,"simTop mycore dpath regfile io_wdata", false,-1, 63,0);
        tracep->declBit(c+122,"simTop mycore dpath regfile io_wen", false,-1);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+203+i*2,"simTop mycore dpath regfile regfile", true,(i+0), 63,0);}}
        tracep->declQuad(c+267,"simTop mycore dpath regfile regfile__T_1_data", false,-1, 63,0);
        tracep->declBus(c+107,"simTop mycore dpath regfile regfile__T_1_addr", false,-1, 4,0);
        tracep->declQuad(c+269,"simTop mycore dpath regfile regfile__T_4_data", false,-1, 63,0);
        tracep->declBus(c+108,"simTop mycore dpath regfile regfile__T_4_addr", false,-1, 4,0);
        tracep->declQuad(c+13,"simTop mycore dpath regfile regfile__T_10_data", false,-1, 63,0);
        tracep->declBus(c+599,"simTop mycore dpath regfile regfile__T_10_addr", false,-1, 4,0);
        tracep->declQuad(c+15,"simTop mycore dpath regfile regfile__T_11_data", false,-1, 63,0);
        tracep->declBus(c+600,"simTop mycore dpath regfile regfile__T_11_addr", false,-1, 4,0);
        tracep->declQuad(c+17,"simTop mycore dpath regfile regfile__T_12_data", false,-1, 63,0);
        tracep->declBus(c+601,"simTop mycore dpath regfile regfile__T_12_addr", false,-1, 4,0);
        tracep->declQuad(c+19,"simTop mycore dpath regfile regfile__T_13_data", false,-1, 63,0);
        tracep->declBus(c+602,"simTop mycore dpath regfile regfile__T_13_addr", false,-1, 4,0);
        tracep->declQuad(c+21,"simTop mycore dpath regfile regfile__T_14_data", false,-1, 63,0);
        tracep->declBus(c+603,"simTop mycore dpath regfile regfile__T_14_addr", false,-1, 4,0);
        tracep->declQuad(c+23,"simTop mycore dpath regfile regfile__T_15_data", false,-1, 63,0);
        tracep->declBus(c+604,"simTop mycore dpath regfile regfile__T_15_addr", false,-1, 4,0);
        tracep->declQuad(c+25,"simTop mycore dpath regfile regfile__T_16_data", false,-1, 63,0);
        tracep->declBus(c+605,"simTop mycore dpath regfile regfile__T_16_addr", false,-1, 4,0);
        tracep->declQuad(c+27,"simTop mycore dpath regfile regfile__T_17_data", false,-1, 63,0);
        tracep->declBus(c+606,"simTop mycore dpath regfile regfile__T_17_addr", false,-1, 4,0);
        tracep->declQuad(c+29,"simTop mycore dpath regfile regfile__T_18_data", false,-1, 63,0);
        tracep->declBus(c+607,"simTop mycore dpath regfile regfile__T_18_addr", false,-1, 4,0);
        tracep->declQuad(c+31,"simTop mycore dpath regfile regfile__T_19_data", false,-1, 63,0);
        tracep->declBus(c+608,"simTop mycore dpath regfile regfile__T_19_addr", false,-1, 4,0);
        tracep->declQuad(c+33,"simTop mycore dpath regfile regfile__T_20_data", false,-1, 63,0);
        tracep->declBus(c+609,"simTop mycore dpath regfile regfile__T_20_addr", false,-1, 4,0);
        tracep->declQuad(c+35,"simTop mycore dpath regfile regfile__T_21_data", false,-1, 63,0);
        tracep->declBus(c+610,"simTop mycore dpath regfile regfile__T_21_addr", false,-1, 4,0);
        tracep->declQuad(c+37,"simTop mycore dpath regfile regfile__T_22_data", false,-1, 63,0);
        tracep->declBus(c+611,"simTop mycore dpath regfile regfile__T_22_addr", false,-1, 4,0);
        tracep->declQuad(c+39,"simTop mycore dpath regfile regfile__T_23_data", false,-1, 63,0);
        tracep->declBus(c+612,"simTop mycore dpath regfile regfile__T_23_addr", false,-1, 4,0);
        tracep->declQuad(c+41,"simTop mycore dpath regfile regfile__T_24_data", false,-1, 63,0);
        tracep->declBus(c+613,"simTop mycore dpath regfile regfile__T_24_addr", false,-1, 4,0);
        tracep->declQuad(c+43,"simTop mycore dpath regfile regfile__T_25_data", false,-1, 63,0);
        tracep->declBus(c+614,"simTop mycore dpath regfile regfile__T_25_addr", false,-1, 4,0);
        tracep->declQuad(c+45,"simTop mycore dpath regfile regfile__T_26_data", false,-1, 63,0);
        tracep->declBus(c+615,"simTop mycore dpath regfile regfile__T_26_addr", false,-1, 4,0);
        tracep->declQuad(c+47,"simTop mycore dpath regfile regfile__T_27_data", false,-1, 63,0);
        tracep->declBus(c+616,"simTop mycore dpath regfile regfile__T_27_addr", false,-1, 4,0);
        tracep->declQuad(c+49,"simTop mycore dpath regfile regfile__T_28_data", false,-1, 63,0);
        tracep->declBus(c+617,"simTop mycore dpath regfile regfile__T_28_addr", false,-1, 4,0);
        tracep->declQuad(c+51,"simTop mycore dpath regfile regfile__T_29_data", false,-1, 63,0);
        tracep->declBus(c+618,"simTop mycore dpath regfile regfile__T_29_addr", false,-1, 4,0);
        tracep->declQuad(c+53,"simTop mycore dpath regfile regfile__T_30_data", false,-1, 63,0);
        tracep->declBus(c+619,"simTop mycore dpath regfile regfile__T_30_addr", false,-1, 4,0);
        tracep->declQuad(c+55,"simTop mycore dpath regfile regfile__T_31_data", false,-1, 63,0);
        tracep->declBus(c+620,"simTop mycore dpath regfile regfile__T_31_addr", false,-1, 4,0);
        tracep->declQuad(c+57,"simTop mycore dpath regfile regfile__T_32_data", false,-1, 63,0);
        tracep->declBus(c+621,"simTop mycore dpath regfile regfile__T_32_addr", false,-1, 4,0);
        tracep->declQuad(c+59,"simTop mycore dpath regfile regfile__T_33_data", false,-1, 63,0);
        tracep->declBus(c+622,"simTop mycore dpath regfile regfile__T_33_addr", false,-1, 4,0);
        tracep->declQuad(c+61,"simTop mycore dpath regfile regfile__T_34_data", false,-1, 63,0);
        tracep->declBus(c+623,"simTop mycore dpath regfile regfile__T_34_addr", false,-1, 4,0);
        tracep->declQuad(c+63,"simTop mycore dpath regfile regfile__T_35_data", false,-1, 63,0);
        tracep->declBus(c+624,"simTop mycore dpath regfile regfile__T_35_addr", false,-1, 4,0);
        tracep->declQuad(c+65,"simTop mycore dpath regfile regfile__T_36_data", false,-1, 63,0);
        tracep->declBus(c+625,"simTop mycore dpath regfile regfile__T_36_addr", false,-1, 4,0);
        tracep->declQuad(c+67,"simTop mycore dpath regfile regfile__T_37_data", false,-1, 63,0);
        tracep->declBus(c+626,"simTop mycore dpath regfile regfile__T_37_addr", false,-1, 4,0);
        tracep->declQuad(c+69,"simTop mycore dpath regfile regfile__T_38_data", false,-1, 63,0);
        tracep->declBus(c+627,"simTop mycore dpath regfile regfile__T_38_addr", false,-1, 4,0);
        tracep->declQuad(c+71,"simTop mycore dpath regfile regfile__T_39_data", false,-1, 63,0);
        tracep->declBus(c+628,"simTop mycore dpath regfile regfile__T_39_addr", false,-1, 4,0);
        tracep->declQuad(c+73,"simTop mycore dpath regfile regfile__T_40_data", false,-1, 63,0);
        tracep->declBus(c+629,"simTop mycore dpath regfile regfile__T_40_addr", false,-1, 4,0);
        tracep->declQuad(c+75,"simTop mycore dpath regfile regfile__T_41_data", false,-1, 63,0);
        tracep->declBus(c+630,"simTop mycore dpath regfile regfile__T_41_addr", false,-1, 4,0);
        tracep->declQuad(c+120,"simTop mycore dpath regfile regfile__T_9_data", false,-1, 63,0);
        tracep->declBus(c+119,"simTop mycore dpath regfile regfile__T_9_addr", false,-1, 4,0);
        tracep->declBit(c+631,"simTop mycore dpath regfile regfile__T_9_mask", false,-1);
        tracep->declBit(c+271,"simTop mycore dpath regfile regfile__T_9_en", false,-1);
        tracep->declBit(c+514,"simTop mycore dpath alu clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath alu reset", false,-1);
        tracep->declQuad(c+123,"simTop mycore dpath alu io_src1", false,-1, 63,0);
        tracep->declQuad(c+125,"simTop mycore dpath alu io_src2", false,-1, 63,0);
        tracep->declBus(c+127,"simTop mycore dpath alu io_op", false,-1, 4,0);
        tracep->declQuad(c+128,"simTop mycore dpath alu io_res", false,-1, 63,0);
        tracep->declBit(c+130,"simTop mycore dpath alu io_stall", false,-1);
        tracep->declBit(c+514,"simTop mycore dpath alu mdu_clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath alu mdu_reset", false,-1);
        tracep->declBit(c+272,"simTop mycore dpath alu mdu_io_start", false,-1);
        tracep->declQuad(c+123,"simTop mycore dpath alu mdu_io_a", false,-1, 63,0);
        tracep->declQuad(c+125,"simTop mycore dpath alu mdu_io_b", false,-1, 63,0);
        tracep->declBus(c+127,"simTop mycore dpath alu mdu_io_op", false,-1, 4,0);
        tracep->declBit(c+273,"simTop mycore dpath alu mdu_io_stall_req", false,-1);
        tracep->declQuad(c+274,"simTop mycore dpath alu mdu_io_mult_out", false,-1, 63,0);
        tracep->declBus(c+276,"simTop mycore dpath alu shamt", false,-1, 5,0);
        tracep->declBit(c+277,"simTop mycore dpath alu use_mdu", false,-1);
        tracep->declBit(c+514,"simTop mycore dpath alu mdu clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath alu mdu reset", false,-1);
        tracep->declBit(c+272,"simTop mycore dpath alu mdu io_start", false,-1);
        tracep->declQuad(c+123,"simTop mycore dpath alu mdu io_a", false,-1, 63,0);
        tracep->declQuad(c+125,"simTop mycore dpath alu mdu io_b", false,-1, 63,0);
        tracep->declBus(c+127,"simTop mycore dpath alu mdu io_op", false,-1, 4,0);
        tracep->declBit(c+273,"simTop mycore dpath alu mdu io_stall_req", false,-1);
        tracep->declQuad(c+274,"simTop mycore dpath alu mdu io_mult_out", false,-1, 63,0);
        tracep->declQuad(c+278,"simTop mycore dpath alu mdu last_a", false,-1, 63,0);
        tracep->declQuad(c+280,"simTop mycore dpath alu mdu last_b", false,-1, 63,0);
        tracep->declBus(c+282,"simTop mycore dpath alu mdu last_op", false,-1, 4,0);
        tracep->declBit(c+283,"simTop mycore dpath alu mdu is_mult", false,-1);
        tracep->declArray(c+284,"simTop mycore dpath alu mdu res", false,-1, 127,0);
        tracep->declBus(c+288,"simTop mycore dpath alu mdu mult_cnt", false,-1, 6,0);
        tracep->declBus(c+289,"simTop mycore dpath alu mdu div_cnt", false,-1, 6,0);
        tracep->declBit(c+290,"simTop mycore dpath alu mdu sign_a", false,-1);
        tracep->declBit(c+291,"simTop mycore dpath alu mdu sign_wa", false,-1);
        tracep->declQuad(c+292,"simTop mycore dpath alu mdu abs_a", false,-1, 63,0);
        tracep->declBit(c+294,"simTop mycore dpath alu mdu sign_b", false,-1);
        tracep->declBit(c+295,"simTop mycore dpath alu mdu sign_wb", false,-1);
        tracep->declQuad(c+296,"simTop mycore dpath alu mdu abs_b", false,-1, 63,0);
        tracep->declArray(c+298,"simTop mycore dpath alu mdu res_ss", false,-1, 127,0);
        tracep->declArray(c+302,"simTop mycore dpath alu mdu res_su", false,-1, 127,0);
        tracep->declQuad(c+306,"simTop mycore dpath alu mdu res_divs", false,-1, 63,0);
        tracep->declQuad(c+308,"simTop mycore dpath alu mdu res_rems", false,-1, 63,0);
        tracep->declBus(c+310,"simTop mycore dpath alu mdu res_divsw", false,-1, 31,0);
        tracep->declBus(c+311,"simTop mycore dpath alu mdu res_remsw", false,-1, 31,0);
        tracep->declBit(c+312,"simTop mycore dpath alu mdu last_stall_req", false,-1);
        tracep->declArray(c+313,"simTop mycore dpath alu mdu front_val", false,-1, 64,0);
        tracep->declArray(c+316,"simTop mycore dpath alu mdu step_result", false,-1, 127,0);
        tracep->declBit(c+514,"simTop mycore dpath csr clock", false,-1);
        tracep->declBit(c+515,"simTop mycore dpath csr reset", false,-1);
        tracep->declBus(c+131,"simTop mycore dpath csr io_inst", false,-1, 31,0);
        tracep->declBus(c+132,"simTop mycore dpath csr io_csr_op", false,-1, 2,0);
        tracep->declQuad(c+133,"simTop mycore dpath csr io_data_in", false,-1, 63,0);
        tracep->declBit(c+130,"simTop mycore dpath csr io_has_stall", false,-1);
        tracep->declQuad(c+135,"simTop mycore dpath csr io_in_mem_pc", false,-1, 63,0);
        tracep->declQuad(c+137,"simTop mycore dpath csr io_in_exe_pc", false,-1, 63,0);
        tracep->declQuad(c+139,"simTop mycore dpath csr io_in_dec_pc", false,-1, 63,0);
        tracep->declQuad(c+1,"simTop mycore dpath csr io_in_if_pc", false,-1, 63,0);
        tracep->declBit(c+85,"simTop mycore dpath csr io_is_redir", false,-1);
        tracep->declQuad(c+320,"simTop mycore dpath csr reg_mtvec", false,-1, 63,0);
        tracep->declQuad(c+322,"simTop mycore dpath csr reg_mepc", false,-1, 63,0);
        tracep->declQuad(c+324,"simTop mycore dpath csr reg_mcause", false,-1, 63,0);
        tracep->declBit(c+326,"simTop mycore dpath csr reg_mie_mtip", false,-1);
        tracep->declBit(c+327,"simTop mycore dpath csr reg_mie_msip", false,-1);
        tracep->declBit(c+328,"simTop mycore dpath csr reg_mip_mtip", false,-1);
        tracep->declBit(c+329,"simTop mycore dpath csr reg_mip_msip", false,-1);
        tracep->declQuad(c+330,"simTop mycore dpath csr reg_mtval", false,-1, 63,0);
        tracep->declQuad(c+332,"simTop mycore dpath csr reg_mscratch", false,-1, 63,0);
        tracep->declBus(c+334,"simTop mycore dpath csr reg_mstatus_mpp", false,-1, 1,0);
        tracep->declBit(c+335,"simTop mycore dpath csr reg_mstatus_mpie", false,-1);
        tracep->declBit(c+336,"simTop mycore dpath csr reg_mstatus_mie", false,-1);
        tracep->declQuad(c+337,"simTop mycore dpath csr reg_pmpcfg0", false,-1, 63,0);
        tracep->declQuad(c+339,"simTop mycore dpath csr reg_pmpcfg1", false,-1, 63,0);
        tracep->declQuad(c+341,"simTop mycore dpath csr regs_pmpaddr_0", false,-1, 63,0);
        tracep->declQuad(c+343,"simTop mycore dpath csr regs_pmpaddr_1", false,-1, 63,0);
        tracep->declQuad(c+345,"simTop mycore dpath csr regs_pmpaddr_2", false,-1, 63,0);
        tracep->declQuad(c+347,"simTop mycore dpath csr regs_pmpaddr_3", false,-1, 63,0);
        tracep->declQuad(c+349,"simTop mycore dpath csr regs_pmpaddr_4", false,-1, 63,0);
        tracep->declQuad(c+351,"simTop mycore dpath csr regs_pmpaddr_5", false,-1, 63,0);
        tracep->declQuad(c+353,"simTop mycore dpath csr regs_pmpaddr_6", false,-1, 63,0);
        tracep->declQuad(c+355,"simTop mycore dpath csr regs_pmpaddr_7", false,-1, 63,0);
        tracep->declQuad(c+357,"simTop mycore dpath csr regs_pmpaddr_8", false,-1, 63,0);
        tracep->declQuad(c+359,"simTop mycore dpath csr regs_pmpaddr_9", false,-1, 63,0);
        tracep->declQuad(c+361,"simTop mycore dpath csr regs_pmpaddr_10", false,-1, 63,0);
        tracep->declQuad(c+363,"simTop mycore dpath csr regs_pmpaddr_11", false,-1, 63,0);
        tracep->declQuad(c+365,"simTop mycore dpath csr regs_pmpaddr_12", false,-1, 63,0);
        tracep->declQuad(c+367,"simTop mycore dpath csr regs_pmpaddr_13", false,-1, 63,0);
        tracep->declQuad(c+369,"simTop mycore dpath csr regs_pmpaddr_14", false,-1, 63,0);
        tracep->declQuad(c+371,"simTop mycore dpath csr regs_pmpaddr_15", false,-1, 63,0);
        tracep->declQuad(c+373,"simTop mycore dpath csr reg_mcycle", false,-1, 63,0);
        tracep->declQuad(c+375,"simTop mycore dpath csr reg_minstret", false,-1, 63,0);
        tracep->declQuad(c+377,"simTop mycore dpath csr regs_mhpmcounter_0", false,-1, 63,0);
        tracep->declQuad(c+379,"simTop mycore dpath csr regs_mhpmcounter_1", false,-1, 63,0);
        tracep->declQuad(c+381,"simTop mycore dpath csr regs_mhpmcounter_2", false,-1, 63,0);
        tracep->declQuad(c+383,"simTop mycore dpath csr regs_mhpmcounter_3", false,-1, 63,0);
        tracep->declQuad(c+385,"simTop mycore dpath csr regs_mhpmcounter_4", false,-1, 63,0);
        tracep->declQuad(c+387,"simTop mycore dpath csr regs_mhpmcounter_5", false,-1, 63,0);
        tracep->declQuad(c+389,"simTop mycore dpath csr regs_mhpmcounter_6", false,-1, 63,0);
        tracep->declQuad(c+391,"simTop mycore dpath csr regs_mhpmcounter_7", false,-1, 63,0);
        tracep->declQuad(c+393,"simTop mycore dpath csr regs_mhpmcounter_8", false,-1, 63,0);
        tracep->declQuad(c+395,"simTop mycore dpath csr regs_mhpmcounter_9", false,-1, 63,0);
        tracep->declQuad(c+397,"simTop mycore dpath csr regs_mhpmcounter_10", false,-1, 63,0);
        tracep->declQuad(c+399,"simTop mycore dpath csr regs_mhpmcounter_11", false,-1, 63,0);
        tracep->declQuad(c+401,"simTop mycore dpath csr regs_mhpmcounter_12", false,-1, 63,0);
        tracep->declQuad(c+403,"simTop mycore dpath csr regs_mhpmcounter_13", false,-1, 63,0);
        tracep->declQuad(c+405,"simTop mycore dpath csr regs_mhpmcounter_14", false,-1, 63,0);
        tracep->declQuad(c+407,"simTop mycore dpath csr regs_mhpmcounter_15", false,-1, 63,0);
        tracep->declQuad(c+409,"simTop mycore dpath csr regs_mhpmcounter_16", false,-1, 63,0);
        tracep->declQuad(c+411,"simTop mycore dpath csr regs_mhpmcounter_17", false,-1, 63,0);
        tracep->declQuad(c+413,"simTop mycore dpath csr regs_mhpmcounter_18", false,-1, 63,0);
        tracep->declQuad(c+415,"simTop mycore dpath csr regs_mhpmcounter_19", false,-1, 63,0);
        tracep->declQuad(c+417,"simTop mycore dpath csr regs_mhpmcounter_20", false,-1, 63,0);
        tracep->declQuad(c+419,"simTop mycore dpath csr regs_mhpmcounter_21", false,-1, 63,0);
        tracep->declQuad(c+421,"simTop mycore dpath csr regs_mhpmcounter_22", false,-1, 63,0);
        tracep->declQuad(c+423,"simTop mycore dpath csr regs_mhpmcounter_23", false,-1, 63,0);
        tracep->declQuad(c+425,"simTop mycore dpath csr regs_mhpmcounter_24", false,-1, 63,0);
        tracep->declQuad(c+427,"simTop mycore dpath csr regs_mhpmcounter_25", false,-1, 63,0);
        tracep->declQuad(c+429,"simTop mycore dpath csr regs_mhpmcounter_26", false,-1, 63,0);
        tracep->declQuad(c+431,"simTop mycore dpath csr regs_mhpmcounter_27", false,-1, 63,0);
        tracep->declQuad(c+433,"simTop mycore dpath csr regs_mhpmcounter_28", false,-1, 63,0);
        tracep->declQuad(c+435,"simTop mycore dpath csr reg_mcounterinhibit", false,-1, 63,0);
        tracep->declQuad(c+437,"simTop mycore dpath csr regs_mhpmevet_0", false,-1, 63,0);
        tracep->declQuad(c+439,"simTop mycore dpath csr regs_mhpmevet_1", false,-1, 63,0);
        tracep->declQuad(c+441,"simTop mycore dpath csr regs_mhpmevet_2", false,-1, 63,0);
        tracep->declQuad(c+443,"simTop mycore dpath csr regs_mhpmevet_3", false,-1, 63,0);
        tracep->declQuad(c+445,"simTop mycore dpath csr regs_mhpmevet_4", false,-1, 63,0);
        tracep->declQuad(c+447,"simTop mycore dpath csr regs_mhpmevet_5", false,-1, 63,0);
        tracep->declQuad(c+449,"simTop mycore dpath csr regs_mhpmevet_6", false,-1, 63,0);
        tracep->declQuad(c+451,"simTop mycore dpath csr regs_mhpmevet_7", false,-1, 63,0);
        tracep->declQuad(c+453,"simTop mycore dpath csr regs_mhpmevet_8", false,-1, 63,0);
        tracep->declQuad(c+455,"simTop mycore dpath csr regs_mhpmevet_9", false,-1, 63,0);
        tracep->declQuad(c+457,"simTop mycore dpath csr regs_mhpmevet_10", false,-1, 63,0);
        tracep->declQuad(c+459,"simTop mycore dpath csr regs_mhpmevet_11", false,-1, 63,0);
        tracep->declQuad(c+461,"simTop mycore dpath csr regs_mhpmevet_12", false,-1, 63,0);
        tracep->declQuad(c+463,"simTop mycore dpath csr regs_mhpmevet_13", false,-1, 63,0);
        tracep->declQuad(c+465,"simTop mycore dpath csr regs_mhpmevet_14", false,-1, 63,0);
        tracep->declQuad(c+467,"simTop mycore dpath csr regs_mhpmevet_15", false,-1, 63,0);
        tracep->declQuad(c+469,"simTop mycore dpath csr regs_mhpmevet_16", false,-1, 63,0);
        tracep->declQuad(c+471,"simTop mycore dpath csr regs_mhpmevet_17", false,-1, 63,0);
        tracep->declQuad(c+473,"simTop mycore dpath csr regs_mhpmevet_18", false,-1, 63,0);
        tracep->declQuad(c+475,"simTop mycore dpath csr regs_mhpmevet_19", false,-1, 63,0);
        tracep->declQuad(c+477,"simTop mycore dpath csr regs_mhpmevet_20", false,-1, 63,0);
        tracep->declQuad(c+479,"simTop mycore dpath csr regs_mhpmevet_21", false,-1, 63,0);
        tracep->declQuad(c+481,"simTop mycore dpath csr regs_mhpmevet_22", false,-1, 63,0);
        tracep->declQuad(c+483,"simTop mycore dpath csr regs_mhpmevet_23", false,-1, 63,0);
        tracep->declQuad(c+485,"simTop mycore dpath csr regs_mhpmevet_24", false,-1, 63,0);
        tracep->declQuad(c+487,"simTop mycore dpath csr regs_mhpmevet_25", false,-1, 63,0);
        tracep->declQuad(c+489,"simTop mycore dpath csr regs_mhpmevet_26", false,-1, 63,0);
        tracep->declQuad(c+491,"simTop mycore dpath csr regs_mhpmevet_27", false,-1, 63,0);
        tracep->declQuad(c+493,"simTop mycore dpath csr regs_mhpmevet_28", false,-1, 63,0);
        tracep->declBus(c+495,"simTop mycore dpath csr wire_csr_index", false,-1, 11,0);
        tracep->declBus(c+496,"simTop mycore dpath csr wire_csr_op", false,-1, 2,0);
        tracep->declBit(c+497,"simTop mycore dpath csr csr_read_only", false,-1);
        tracep->declBit(c+498,"simTop mycore dpath csr write_illegal", false,-1);
        tracep->declBit(c+499,"simTop mycore dpath csr csr_legal", false,-1);
        tracep->declBit(c+500,"simTop mycore dpath csr read_illegal", false,-1);
        tracep->declBit(c+501,"simTop mycore dpath csr exception_in_csr", false,-1);
        tracep->declBit(c+502,"simTop mycore dpath csr csr_read_enable", false,-1);
        tracep->declQuad(c+503,"simTop mycore dpath csr csr_read_data", false,-1, 63,0);
        tracep->declQuad(c+505,"simTop mycore dpath csr csr_write_data", false,-1, 63,0);
        tracep->declBit(c+507,"simTop mycore dpath csr csr_wen", false,-1);
        tracep->declBit(c+508,"simTop mycore dpath csr csr_isecall", false,-1);
        tracep->declBit(c+509,"simTop mycore dpath csr csr_isebreak", false,-1);
        tracep->declBit(c+510,"simTop mycore dpath csr csr_ismret", false,-1);
        tracep->declBit(c+511,"simTop mycore dpath csr csr_has_exception", false,-1);
        tracep->declBit(c+512,"simTop mycore dpath csr csr_has_interrupt", false,-1);
        tracep->declBus(c+513,"simTop mycore dpath csr prv_now", false,-1, 1,0);
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
        tracep->fullQData(oldp+6,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_addr),64);
        tracep->fullQData(oldp+8,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_data_writeIO_data),64);
        tracep->fullBit(oldp+10,((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn))));
        tracep->fullCData(oldp+11,((0xffU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_235))),8);
        tracep->fullBit(oldp+12,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_valid));
        tracep->fullQData(oldp+13,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0U]),64);
        tracep->fullQData(oldp+15,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [1U]),64);
        tracep->fullQData(oldp+17,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [2U]),64);
        tracep->fullQData(oldp+19,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [3U]),64);
        tracep->fullQData(oldp+21,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [4U]),64);
        tracep->fullQData(oldp+23,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [5U]),64);
        tracep->fullQData(oldp+25,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [6U]),64);
        tracep->fullQData(oldp+27,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [7U]),64);
        tracep->fullQData(oldp+29,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [8U]),64);
        tracep->fullQData(oldp+31,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [9U]),64);
        tracep->fullQData(oldp+33,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xaU]),64);
        tracep->fullQData(oldp+35,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xbU]),64);
        tracep->fullQData(oldp+37,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xcU]),64);
        tracep->fullQData(oldp+39,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xdU]),64);
        tracep->fullQData(oldp+41,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xeU]),64);
        tracep->fullQData(oldp+43,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0xfU]),64);
        tracep->fullQData(oldp+45,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x10U]),64);
        tracep->fullQData(oldp+47,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x11U]),64);
        tracep->fullQData(oldp+49,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x12U]),64);
        tracep->fullQData(oldp+51,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x13U]),64);
        tracep->fullQData(oldp+53,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x14U]),64);
        tracep->fullQData(oldp+55,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x15U]),64);
        tracep->fullQData(oldp+57,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x16U]),64);
        tracep->fullQData(oldp+59,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x17U]),64);
        tracep->fullQData(oldp+61,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x18U]),64);
        tracep->fullQData(oldp+63,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x19U]),64);
        tracep->fullQData(oldp+65,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1aU]),64);
        tracep->fullQData(oldp+67,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1bU]),64);
        tracep->fullQData(oldp+69,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1cU]),64);
        tracep->fullQData(oldp+71,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1dU]),64);
        tracep->fullQData(oldp+73,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1eU]),64);
        tracep->fullQData(oldp+75,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                   [0x1fU]),64);
        tracep->fullQData(oldp+77,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_pc),64);
        tracep->fullQData(oldp+79,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst),64);
        tracep->fullBit(oldp+81,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_eq));
        tracep->fullBit(oldp+82,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_lt));
        tracep->fullBit(oldp+83,(vlTOPp->simTop__DOT__mycore__DOT__dpath_io_dat_exe_br_ltu));
        tracep->fullCData(oldp+84,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_br_type),4);
        tracep->fullBit(oldp+85,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr_io_is_redir));
        tracep->fullBit(oldp+86,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__stall));
        tracep->fullCData(oldp+87,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel),2);
        tracep->fullCData(oldp+88,(((0x3003ULL == (0x707fULL 
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
        tracep->fullBit(oldp+89,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_if_kill));
        tracep->fullBit(oldp+90,((0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))));
        tracep->fullCData(oldp+91,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel),2);
        tracep->fullCData(oldp+92,(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op2_sel),3);
        tracep->fullCData(oldp+93,(((0x3003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 0U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_667))),5);
        tracep->fullCData(oldp+94,(((0x3003ULL == (0x707fULL 
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
        tracep->fullBit(oldp+95,(((0x3003ULL == (0x707fULL 
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
        tracep->fullCData(oldp+96,(((0x3003ULL == (0x707fULL 
                                                   & vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst))
                                     ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_963))),2);
        tracep->fullCData(oldp+97,(((0x3003ULL == (0x707fULL 
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
        tracep->fullCData(oldp+98,(((0x3003ULL == (0x707fULL 
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
        tracep->fullCData(oldp+99,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1295)
                                     ? 1U : (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7))),3);
        tracep->fullBit(oldp+100,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8) 
                                   | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1313))));
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
        tracep->fullBit(oldp+102,(((0x3003ULL != (0x707fULL 
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
        tracep->fullBit(oldp+103,(((0x3003ULL == (0x707fULL 
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
        tracep->fullCData(oldp+104,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_7),3);
        tracep->fullBit(oldp+105,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__cs0_8));
        tracep->fullBit(oldp+106,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1288) 
                                   | (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT___T_1289))));
        tracep->fullCData(oldp+107,((0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0xfU)))),5);
        tracep->fullCData(oldp+108,((0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0x14U)))),5);
        tracep->fullCData(oldp+109,((0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 7U)))),5);
        tracep->fullBit(oldp+110,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
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
        tracep->fullBit(oldp+111,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel)) 
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
        tracep->fullCData(oldp+112,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_wbaddr),5);
        tracep->fullBit(oldp+113,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_reg_is_csr));
        tracep->fullBit(oldp+114,(vlTOPp->simTop__DOT__mycore__DOT__cpath__DOT__exe_inst_is_load));
        tracep->fullQData(oldp+115,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs1_data),64);
        tracep->fullQData(oldp+117,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile_io_rs2_data),64);
        tracep->fullCData(oldp+119,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr),5);
        tracep->fullQData(oldp+120,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata),64);
        tracep->fullBit(oldp+122,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen));
        tracep->fullQData(oldp+123,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1),64);
        tracep->fullQData(oldp+125,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset),64);
        tracep->fullCData(oldp+127,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_alu_fun),5);
        tracep->fullQData(oldp+128,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_res),64);
        tracep->fullBit(oldp+130,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu_io_stall));
        tracep->fullIData(oldp+131,((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst)),32);
        tracep->fullCData(oldp+132,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_csr_cmd),3);
        tracep->fullQData(oldp+133,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_alu_out),64);
        tracep->fullQData(oldp+135,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_pc),64);
        tracep->fullQData(oldp+137,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc),64);
        tracep->fullQData(oldp+139,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc),64);
        tracep->fullBit(oldp+141,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_valid));
        tracep->fullBit(oldp+142,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_valid));
        tracep->fullQData(oldp+143,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_inst),64);
        tracep->fullCData(oldp+145,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_wbaddr),5);
        tracep->fullQData(oldp+146,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_rs2_data),64);
        tracep->fullCData(oldp+148,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_wb_sel),3);
        tracep->fullBit(oldp+149,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_rf_wen));
        tracep->fullCData(oldp+150,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_fcn),2);
        tracep->fullCData(oldp+151,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_typ),8);
        tracep->fullCData(oldp+152,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_mem_wid),3);
        tracep->fullCData(oldp+153,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_ctrl_csr_cmd),3);
        tracep->fullBit(oldp+154,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_valid));
        tracep->fullQData(oldp+155,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst),64);
        tracep->fullCData(oldp+157,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_wbaddr),5);
        tracep->fullBit(oldp+158,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_rf_wen));
        tracep->fullCData(oldp+159,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_wb_sel),3);
        tracep->fullCData(oldp+160,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid),3);
        tracep->fullQData(oldp+161,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_dram_data),64);
        tracep->fullQData(oldp+163,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)),64);
        tracep->fullQData(oldp+165,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target),64);
        tracep->fullQData(oldp+167,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out),64);
        tracep->fullQData(oldp+169,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_22)
                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc
                                      : ((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                                          ? (4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__if_reg_pc)
                                          : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                                              ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_brjmp_target
                                              : ((2U 
                                                  == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_exe_pc_sel))
                                                  ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_adder_out
                                                  : 0x4033ULL))))),64);
        tracep->fullSData(oldp+171,((0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0x14U)))),12);
        tracep->fullSData(oldp+172,(((0xfe0U & ((IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0x19U)) 
                                                << 5U)) 
                                     | (0x1fU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 7U))))),12);
        tracep->fullSData(oldp+173,(((0x800U & ((IData)(
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
        tracep->fullIData(oldp+174,((0xfffffU & (IData)(
                                                        (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                         >> 0xcU)))),20);
        tracep->fullIData(oldp+175,(((0x80000U & ((IData)(
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
        tracep->fullIData(oldp+176,((0x1fU & (IData)(
                                                     (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                      >> 0xfU)))),32);
        tracep->fullQData(oldp+177,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_itype_sext),64);
        tracep->fullQData(oldp+179,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_stype_sext),64);
        tracep->fullQData(oldp+181,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_sbtype_sext),64);
        tracep->fullQData(oldp+183,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_utype_sext),64);
        tracep->fullQData(oldp+185,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__imm_ujtype_sext),64);
        tracep->fullQData(oldp+187,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_alu_op2),64);
        tracep->fullQData(oldp+189,(((0U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_ctrl_mem_wid))
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
        tracep->fullQData(oldp+191,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata),64);
        tracep->fullQData(oldp+193,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out),64);
        tracep->fullQData(oldp+195,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data),64);
        tracep->fullQData(oldp+197,(((2U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                                      ? (QData)((IData)(
                                                        (0x1fU 
                                                         & (IData)(
                                                                   (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                                    >> 0xfU)))))
                                      : ((1U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                                          ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_pc
                                          : ((3U == (IData)(vlTOPp->simTop__DOT__mycore__DOT__cpath_io_ctl_op1_sel))
                                              ? (QData)((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data))
                                              : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_rs1_data)))),64);
        tracep->fullQData(oldp+199,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_105)
                                      ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_out
                                      : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_111)
                                          ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_wbdata
                                          : ((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT___T_117)
                                              ? vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbdata
                                              : vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_alu_op2)))),64);
        tracep->fullQData(oldp+201,((4ULL + vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_reg_pc)),64);
        tracep->fullQData(oldp+203,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[0]),64);
        tracep->fullQData(oldp+205,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[1]),64);
        tracep->fullQData(oldp+207,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[2]),64);
        tracep->fullQData(oldp+209,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[3]),64);
        tracep->fullQData(oldp+211,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[4]),64);
        tracep->fullQData(oldp+213,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[5]),64);
        tracep->fullQData(oldp+215,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[6]),64);
        tracep->fullQData(oldp+217,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[7]),64);
        tracep->fullQData(oldp+219,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[8]),64);
        tracep->fullQData(oldp+221,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[9]),64);
        tracep->fullQData(oldp+223,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[10]),64);
        tracep->fullQData(oldp+225,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[11]),64);
        tracep->fullQData(oldp+227,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[12]),64);
        tracep->fullQData(oldp+229,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[13]),64);
        tracep->fullQData(oldp+231,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[14]),64);
        tracep->fullQData(oldp+233,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[15]),64);
        tracep->fullQData(oldp+235,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[16]),64);
        tracep->fullQData(oldp+237,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[17]),64);
        tracep->fullQData(oldp+239,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[18]),64);
        tracep->fullQData(oldp+241,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[19]),64);
        tracep->fullQData(oldp+243,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[20]),64);
        tracep->fullQData(oldp+245,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[21]),64);
        tracep->fullQData(oldp+247,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[22]),64);
        tracep->fullQData(oldp+249,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[23]),64);
        tracep->fullQData(oldp+251,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[24]),64);
        tracep->fullQData(oldp+253,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[25]),64);
        tracep->fullQData(oldp+255,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[26]),64);
        tracep->fullQData(oldp+257,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[27]),64);
        tracep->fullQData(oldp+259,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[28]),64);
        tracep->fullQData(oldp+261,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[29]),64);
        tracep->fullQData(oldp+263,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[30]),64);
        tracep->fullQData(oldp+265,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile[31]),64);
        tracep->fullQData(oldp+267,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                    [(0x1fU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0xfU)))]),64);
        tracep->fullQData(oldp+269,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__regfile__DOT__regfile
                                    [(0x1fU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__dec_reg_inst 
                                                       >> 0x14U)))]),64);
        tracep->fullBit(oldp+271,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_ctrl_rf_wen) 
                                   & (0U != (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__wb_reg_wbaddr)))));
        tracep->fullBit(oldp+272,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_start));
        tracep->fullBit(oldp+273,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu_io_stall_req));
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
        tracep->fullQData(oldp+274,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult)
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
        tracep->fullCData(oldp+276,((0x3fU & (IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset))),6);
        tracep->fullBit(oldp+277,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__use_mdu));
        tracep->fullQData(oldp+278,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_a),64);
        tracep->fullQData(oldp+280,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_b),64);
        tracep->fullCData(oldp+282,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_op),5);
        tracep->fullBit(oldp+283,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__is_mult));
        tracep->fullWData(oldp+284,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res),128);
        tracep->fullCData(oldp+288,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__mult_cnt),7);
        tracep->fullCData(oldp+289,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__div_cnt),7);
        tracep->fullBit(oldp+290,((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                 >> 0x3fU)))));
        tracep->fullBit(oldp+291,((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__exe_alu_op1 
                                                 >> 0x1fU)))));
        tracep->fullQData(oldp+292,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_a),64);
        tracep->fullBit(oldp+294,((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                                                 >> 0x3fU)))));
        tracep->fullBit(oldp+295,((1U & (IData)((vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__brjmp_offset 
                                                 >> 0x1fU)))));
        tracep->fullQData(oldp+296,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__abs_b),64);
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
        tracep->fullWData(oldp+298,(__Vtemp74),128);
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
        tracep->fullWData(oldp+302,(__Vtemp79),128);
        tracep->fullQData(oldp+306,(((IData)(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT___T_153)
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
        tracep->fullQData(oldp+308,(((1U & (IData)(
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
        tracep->fullIData(oldp+310,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_divsw),32);
        tracep->fullIData(oldp+311,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__res_remsw),32);
        tracep->fullBit(oldp+312,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__last_stall_req));
        tracep->fullWData(oldp+313,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__front_val),65);
        tracep->fullWData(oldp+316,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__alu__DOT__mdu__DOT__step_result),128);
        tracep->fullQData(oldp+320,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtvec),64);
        tracep->fullQData(oldp+322,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mepc),64);
        tracep->fullQData(oldp+324,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcause),64);
        tracep->fullBit(oldp+326,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_mtip));
        tracep->fullBit(oldp+327,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mie_msip));
        tracep->fullBit(oldp+328,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_mtip));
        tracep->fullBit(oldp+329,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mip_msip));
        tracep->fullQData(oldp+330,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mtval),64);
        tracep->fullQData(oldp+332,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mscratch),64);
        tracep->fullCData(oldp+334,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpp),2);
        tracep->fullBit(oldp+335,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mpie));
        tracep->fullBit(oldp+336,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mstatus_mie));
        tracep->fullQData(oldp+337,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg0),64);
        tracep->fullQData(oldp+339,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_pmpcfg1),64);
        tracep->fullQData(oldp+341,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_0),64);
        tracep->fullQData(oldp+343,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_1),64);
        tracep->fullQData(oldp+345,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_2),64);
        tracep->fullQData(oldp+347,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_3),64);
        tracep->fullQData(oldp+349,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_4),64);
        tracep->fullQData(oldp+351,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_5),64);
        tracep->fullQData(oldp+353,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_6),64);
        tracep->fullQData(oldp+355,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_7),64);
        tracep->fullQData(oldp+357,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_8),64);
        tracep->fullQData(oldp+359,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_9),64);
        tracep->fullQData(oldp+361,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_10),64);
        tracep->fullQData(oldp+363,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_11),64);
        tracep->fullQData(oldp+365,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_12),64);
        tracep->fullQData(oldp+367,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_13),64);
        tracep->fullQData(oldp+369,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_14),64);
        tracep->fullQData(oldp+371,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_pmpaddr_15),64);
        tracep->fullQData(oldp+373,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcycle),64);
        tracep->fullQData(oldp+375,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_minstret),64);
        tracep->fullQData(oldp+377,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_0),64);
        tracep->fullQData(oldp+379,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_1),64);
        tracep->fullQData(oldp+381,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_2),64);
        tracep->fullQData(oldp+383,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_3),64);
        tracep->fullQData(oldp+385,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_4),64);
        tracep->fullQData(oldp+387,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_5),64);
        tracep->fullQData(oldp+389,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_6),64);
        tracep->fullQData(oldp+391,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_7),64);
        tracep->fullQData(oldp+393,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_8),64);
        tracep->fullQData(oldp+395,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_9),64);
        tracep->fullQData(oldp+397,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_10),64);
        tracep->fullQData(oldp+399,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_11),64);
        tracep->fullQData(oldp+401,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_12),64);
        tracep->fullQData(oldp+403,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_13),64);
        tracep->fullQData(oldp+405,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_14),64);
        tracep->fullQData(oldp+407,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_15),64);
        tracep->fullQData(oldp+409,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_16),64);
        tracep->fullQData(oldp+411,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_17),64);
        tracep->fullQData(oldp+413,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_18),64);
        tracep->fullQData(oldp+415,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_19),64);
        tracep->fullQData(oldp+417,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_20),64);
        tracep->fullQData(oldp+419,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_21),64);
        tracep->fullQData(oldp+421,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_22),64);
        tracep->fullQData(oldp+423,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_23),64);
        tracep->fullQData(oldp+425,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_24),64);
        tracep->fullQData(oldp+427,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_25),64);
        tracep->fullQData(oldp+429,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_26),64);
        tracep->fullQData(oldp+431,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_27),64);
        tracep->fullQData(oldp+433,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmcounter_28),64);
        tracep->fullQData(oldp+435,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__reg_mcounterinhibit),64);
        tracep->fullQData(oldp+437,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_0),64);
        tracep->fullQData(oldp+439,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_1),64);
        tracep->fullQData(oldp+441,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_2),64);
        tracep->fullQData(oldp+443,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_3),64);
        tracep->fullQData(oldp+445,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_4),64);
        tracep->fullQData(oldp+447,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_5),64);
        tracep->fullQData(oldp+449,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_6),64);
        tracep->fullQData(oldp+451,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_7),64);
        tracep->fullQData(oldp+453,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_8),64);
        tracep->fullQData(oldp+455,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_9),64);
        tracep->fullQData(oldp+457,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_10),64);
        tracep->fullQData(oldp+459,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_11),64);
        tracep->fullQData(oldp+461,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_12),64);
        tracep->fullQData(oldp+463,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_13),64);
        tracep->fullQData(oldp+465,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_14),64);
        tracep->fullQData(oldp+467,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_15),64);
        tracep->fullQData(oldp+469,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_16),64);
        tracep->fullQData(oldp+471,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_17),64);
        tracep->fullQData(oldp+473,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_18),64);
        tracep->fullQData(oldp+475,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_19),64);
        tracep->fullQData(oldp+477,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_20),64);
        tracep->fullQData(oldp+479,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_21),64);
        tracep->fullQData(oldp+481,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_22),64);
        tracep->fullQData(oldp+483,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_23),64);
        tracep->fullQData(oldp+485,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_24),64);
        tracep->fullQData(oldp+487,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_25),64);
        tracep->fullQData(oldp+489,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_26),64);
        tracep->fullQData(oldp+491,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_27),64);
        tracep->fullQData(oldp+493,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__regs_mhpmevet_28),64);
        tracep->fullSData(oldp+495,((0xfffU & (IData)(
                                                      (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                       >> 0x14U)))),12);
        tracep->fullCData(oldp+496,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__wire_csr_op),3);
        tracep->fullBit(oldp+497,((3U == (3U & (IData)(
                                                       (vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__mem_reg_inst 
                                                        >> 0x1eU))))));
        tracep->fullBit(oldp+498,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__write_illegal));
        tracep->fullBit(oldp+499,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_legal));
        tracep->fullBit(oldp+500,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__read_illegal));
        tracep->fullBit(oldp+501,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__exception_in_csr));
        tracep->fullBit(oldp+502,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_enable));
        tracep->fullQData(oldp+503,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_read_data),64);
        tracep->fullQData(oldp+505,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_write_data),64);
        tracep->fullBit(oldp+507,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_wen));
        tracep->fullBit(oldp+508,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isecall));
        tracep->fullBit(oldp+509,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_isebreak));
        tracep->fullBit(oldp+510,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_ismret));
        tracep->fullBit(oldp+511,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_exception));
        tracep->fullBit(oldp+512,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__csr_has_interrupt));
        tracep->fullCData(oldp+513,(vlTOPp->simTop__DOT__mycore__DOT__dpath__DOT__csr__DOT__prv_now),2);
        tracep->fullBit(oldp+514,(vlTOPp->clock));
        tracep->fullBit(oldp+515,(vlTOPp->reset));
        tracep->fullQData(oldp+516,(vlTOPp->io_diffTestIO_regfile_0),64);
        tracep->fullQData(oldp+518,(vlTOPp->io_diffTestIO_regfile_1),64);
        tracep->fullQData(oldp+520,(vlTOPp->io_diffTestIO_regfile_2),64);
        tracep->fullQData(oldp+522,(vlTOPp->io_diffTestIO_regfile_3),64);
        tracep->fullQData(oldp+524,(vlTOPp->io_diffTestIO_regfile_4),64);
        tracep->fullQData(oldp+526,(vlTOPp->io_diffTestIO_regfile_5),64);
        tracep->fullQData(oldp+528,(vlTOPp->io_diffTestIO_regfile_6),64);
        tracep->fullQData(oldp+530,(vlTOPp->io_diffTestIO_regfile_7),64);
        tracep->fullQData(oldp+532,(vlTOPp->io_diffTestIO_regfile_8),64);
        tracep->fullQData(oldp+534,(vlTOPp->io_diffTestIO_regfile_9),64);
        tracep->fullQData(oldp+536,(vlTOPp->io_diffTestIO_regfile_10),64);
        tracep->fullQData(oldp+538,(vlTOPp->io_diffTestIO_regfile_11),64);
        tracep->fullQData(oldp+540,(vlTOPp->io_diffTestIO_regfile_12),64);
        tracep->fullQData(oldp+542,(vlTOPp->io_diffTestIO_regfile_13),64);
        tracep->fullQData(oldp+544,(vlTOPp->io_diffTestIO_regfile_14),64);
        tracep->fullQData(oldp+546,(vlTOPp->io_diffTestIO_regfile_15),64);
        tracep->fullQData(oldp+548,(vlTOPp->io_diffTestIO_regfile_16),64);
        tracep->fullQData(oldp+550,(vlTOPp->io_diffTestIO_regfile_17),64);
        tracep->fullQData(oldp+552,(vlTOPp->io_diffTestIO_regfile_18),64);
        tracep->fullQData(oldp+554,(vlTOPp->io_diffTestIO_regfile_19),64);
        tracep->fullQData(oldp+556,(vlTOPp->io_diffTestIO_regfile_20),64);
        tracep->fullQData(oldp+558,(vlTOPp->io_diffTestIO_regfile_21),64);
        tracep->fullQData(oldp+560,(vlTOPp->io_diffTestIO_regfile_22),64);
        tracep->fullQData(oldp+562,(vlTOPp->io_diffTestIO_regfile_23),64);
        tracep->fullQData(oldp+564,(vlTOPp->io_diffTestIO_regfile_24),64);
        tracep->fullQData(oldp+566,(vlTOPp->io_diffTestIO_regfile_25),64);
        tracep->fullQData(oldp+568,(vlTOPp->io_diffTestIO_regfile_26),64);
        tracep->fullQData(oldp+570,(vlTOPp->io_diffTestIO_regfile_27),64);
        tracep->fullQData(oldp+572,(vlTOPp->io_diffTestIO_regfile_28),64);
        tracep->fullQData(oldp+574,(vlTOPp->io_diffTestIO_regfile_29),64);
        tracep->fullQData(oldp+576,(vlTOPp->io_diffTestIO_regfile_30),64);
        tracep->fullQData(oldp+578,(vlTOPp->io_diffTestIO_regfile_31),64);
        tracep->fullQData(oldp+580,(vlTOPp->io_diffTestIO_pc),64);
        tracep->fullBit(oldp+582,(vlTOPp->io_diffTestIO_valid));
        tracep->fullQData(oldp+583,(vlTOPp->io_coreIO_inst_readIO_addr),64);
        tracep->fullQData(oldp+585,(vlTOPp->io_coreIO_inst_readIO_data),64);
        tracep->fullBit(oldp+587,(vlTOPp->io_coreIO_inst_readIO_en));
        tracep->fullQData(oldp+588,(vlTOPp->io_coreIO_data_readIO_addr),64);
        tracep->fullQData(oldp+590,(vlTOPp->io_coreIO_data_readIO_data),64);
        tracep->fullBit(oldp+592,(vlTOPp->io_coreIO_data_readIO_en));
        tracep->fullQData(oldp+593,(vlTOPp->io_coreIO_data_writeIO_addr),64);
        tracep->fullQData(oldp+595,(vlTOPp->io_coreIO_data_writeIO_data),64);
        tracep->fullBit(oldp+597,(vlTOPp->io_coreIO_data_writeIO_en));
        tracep->fullCData(oldp+598,(vlTOPp->io_coreIO_data_writeIO_mask),8);
        tracep->fullCData(oldp+599,(0U),5);
        tracep->fullCData(oldp+600,(1U),5);
        tracep->fullCData(oldp+601,(2U),5);
        tracep->fullCData(oldp+602,(3U),5);
        tracep->fullCData(oldp+603,(4U),5);
        tracep->fullCData(oldp+604,(5U),5);
        tracep->fullCData(oldp+605,(6U),5);
        tracep->fullCData(oldp+606,(7U),5);
        tracep->fullCData(oldp+607,(8U),5);
        tracep->fullCData(oldp+608,(9U),5);
        tracep->fullCData(oldp+609,(0xaU),5);
        tracep->fullCData(oldp+610,(0xbU),5);
        tracep->fullCData(oldp+611,(0xcU),5);
        tracep->fullCData(oldp+612,(0xdU),5);
        tracep->fullCData(oldp+613,(0xeU),5);
        tracep->fullCData(oldp+614,(0xfU),5);
        tracep->fullCData(oldp+615,(0x10U),5);
        tracep->fullCData(oldp+616,(0x11U),5);
        tracep->fullCData(oldp+617,(0x12U),5);
        tracep->fullCData(oldp+618,(0x13U),5);
        tracep->fullCData(oldp+619,(0x14U),5);
        tracep->fullCData(oldp+620,(0x15U),5);
        tracep->fullCData(oldp+621,(0x16U),5);
        tracep->fullCData(oldp+622,(0x17U),5);
        tracep->fullCData(oldp+623,(0x18U),5);
        tracep->fullCData(oldp+624,(0x19U),5);
        tracep->fullCData(oldp+625,(0x1aU),5);
        tracep->fullCData(oldp+626,(0x1bU),5);
        tracep->fullCData(oldp+627,(0x1cU),5);
        tracep->fullCData(oldp+628,(0x1dU),5);
        tracep->fullCData(oldp+629,(0x1eU),5);
        tracep->fullCData(oldp+630,(0x1fU),5);
        tracep->fullBit(oldp+631,(1U));
    }
}
