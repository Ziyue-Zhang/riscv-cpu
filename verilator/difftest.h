#ifndef __DIFFTESTIO_H__
#define __DIFFTESTIO_H__

#include "common.h"
#include "ram.h"
#include "emu.h"

void init_difftest(reg_t *reg, char* imgPath, Ram* ram);
void difftest_step(Emu* emu);


static const char *reg_name[NUM_REG+1] = {
  "$0", "ra", "sp", "gp", "tp", "t0", "t1", "t2",
  "s0", "s1", "a0", "a1", "a2", "a3", "a4", "a5",
  "a6", "a7", "s2", "s3", "s4", "s5", "s6", "s7",
  "s8", "s9", "s10", "s11", "t3", "t4", "t5", "t6",
  "this_pc"
};

#endif