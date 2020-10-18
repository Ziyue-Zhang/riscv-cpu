#include "emu.h"
#include "VsimTop.h"
#include "verilated_vcd_c.h"
#include <iostream>
using namespace std;
#include "difftestIO.h"

Emu::Emu(CRam* input_ram, long* input_time)
{
    emu_ram = input_ram;
    emu_time = input_time;
    emu_simtop = new VsimTop("emu_simtop");

    if(vcdTrace){   
        Verilated::traceEverOn(true);
        emu_vcd = new VerilatedVcdC;
        emu_simtop->trace(emu_vcd, 99);  
        emu_vcd->open("build/trace/myVCD.vcd");
    }
    
    reset_cycles(10);
}

Emu::~Emu()
{
    emu_simtop->final();
    emu_vcd->close();
    delete emu_simtop;
    delete emu_vcd;
}

void Emu::step(int num)
{
    for(int i = num; i > 0; i--){
        int max_step = 10;      
        while(!emu_simtop->io_diffTestIO_PC_valid && max_step-- > 0){      
            cout << "clock = " << emu_cycles << endl;
            emu_cycles++;
            emu_simtop->clock = 1;
            emu_eval();      
            emu_simtop->eval();
            (*emu_time)++;
            if(vcdTrace) {
                emu_vcd->dump((double)*emu_time);
            }
            emu_simtop->clock = 0;
            emu_simtop->eval();
            (*emu_time)++;
            if(vcdTrace) {
                emu_vcd->dump((double)*emu_time);
            }        
        }
        //now valid
        cout << "clock = " << emu_cycles << endl;
        emu_cycles++;
        emu_simtop->clock = 1;
        emu_eval();     
        emu_simtop->eval();
        (*emu_time)++;
        if(vcdTrace) {
            emu_vcd->dump((double)*emu_time);
        }
        emu_simtop->clock = 0;
        emu_simtop->eval();
        (*emu_time)++;
        if(vcdTrace) {
            emu_vcd->dump((double)*emu_time);
        }
        cout <<"****************************"<< endl;
    }
}

void Emu::emu_difftest_getregs(reg_t* r)
{
#define emu_reg(x) r[x] = emu_simtop->io_diffTestIO_regfile_##x
    emu_reg(0); emu_reg(1); emu_reg(2); emu_reg(3); emu_reg(4); emu_reg(5); emu_reg(6); emu_reg(7);
    emu_reg(8); emu_reg(9); emu_reg(10); emu_reg(11); emu_reg(12); emu_reg(13); emu_reg(14); emu_reg(15);
    emu_reg(16); emu_reg(17); emu_reg(18); emu_reg(19); emu_reg(20); emu_reg(21); emu_reg(22); emu_reg(23);
    emu_reg(24); emu_reg(25); emu_reg(26); emu_reg(27); emu_reg(28); emu_reg(29); emu_reg(30); emu_reg(31);
    r[DIFFTEST_THIS_PC] = emu_simtop->io_diffTestIO_PC;

}

double Emu::get_time() {       
    return emu_cycles;           
}

void Emu::emu_eval(){
    emu_simtop->inst_readio_data = emu_ram->InstRead(emu_simtop->inst_readio__addr, emu_simtop->inst_readio__en);
}