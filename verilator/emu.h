#ifndef __EMU_H__
#define __EMU_H__

#include "ram.h"
#include "VsimTop.h"
#include "difftestIO.h"

class Emu
{
private:

    int emu_cycles = 0;
    long* emu_time;
    Ram *emu_ram;
    VsimTop* emu_simtop;
    VerilatedVcdC* emu_vcd;
    void emu_eval();
public:
    Emu(Ram* input_ram, long* input_time);
    ~Emu();
    void step(int i);
    void emu_difftest_getregs(reg_t* r);    
    double get_time();
};

#endif