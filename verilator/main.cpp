#include "ram.h"
#include "difftest.h"
#include "difftestIO.h"
#include "emu.h"
#include <iostream>
using namespace std;

long emu_time = 0;
double emu_time_stamp(){
    return emu_time;
}

int main(int argc, char** argv){
    Ram* new_ram = new Ram(argv[1]);
    init_difftest(0, NULL,new_ram);
    Emu* emu = new Emu(new_ram, &emu_time);
    difftest_step(emu);

    return 0;
}
