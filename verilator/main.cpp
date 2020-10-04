#include "ram.h"
#include "difftest.h"
#include "difftestIO.h"
#include <iostream>
using namespace std;


int main(int argc, char** argv){
    Ram* new_ram = new Ram(argv[1]);
    init_difftest(0, NULL,new_ram);
    //CEmulator* emulator = new CEmulator(ram);
    //difftest_step();

    //difftest_step();
    //difftest_step();
    // reg_t reg[DIFFTEST_NR_REG];
    // emulator->read_emu_regs(reg);
    /// emulator->step(20);


    return 0;
}
