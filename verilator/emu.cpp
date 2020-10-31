#include "emu.h"
#include "VsimTop.h"
#include "verilated_vcd_c.h"
#include "difftest.h"
#include <iostream>
using namespace std;
#include "difftestIO.h"

Emu::Emu(Ram* input_ram, long* input_time)
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
    emu_simtop->reset = 1;
    for (size_t i = 0; i < 10; i++)
    {
        emu_simtop->clock = 0;
        emu_simtop->eval();
        emu_simtop->clock = 1;
        emu_simtop->eval();       
    }
    emu_simtop->reset = 0;
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
    for(int i = 100; i > 0; i--){
        printf("cycle = %d \n", emu_cycles);
        emu_simtop->clock = 0;
        emu_simtop->eval();

        emu_eval();      

        emu_simtop->clock = 1;
        emu_simtop->eval();
        if(vcdTrace) 
            emu_vcd->dump(emu_cycles);
        emu_cycles++;

        // difftest
        if(emu_simtop->io_diffTestIO_valid){
            extern int difftest_step(Emu* emu);
            int temp = difftest_step(this);
            assert(temp==0);
            printf("***************************************\n");
            return;
        }
    }
}

void Emu::emu_difftest_getregs(reg_t* r)
{
#define emu_reg(x) r[x] = emu_simtop->io_diffTestIO_regfile_##x
    emu_reg(0); emu_reg(1); emu_reg(2); emu_reg(3); emu_reg(4); emu_reg(5); emu_reg(6); emu_reg(7);
    emu_reg(8); emu_reg(9); emu_reg(10); emu_reg(11); emu_reg(12); emu_reg(13); emu_reg(14); emu_reg(15);
    emu_reg(16); emu_reg(17); emu_reg(18); emu_reg(19); emu_reg(20); emu_reg(21); emu_reg(22); emu_reg(23);
    emu_reg(24); emu_reg(25); emu_reg(26); emu_reg(27); emu_reg(28); emu_reg(29); emu_reg(30); emu_reg(31);
    r[32] = emu_simtop->io_diffTestIO_pc;

}

double Emu::get_time() {       
    return emu_cycles;           
}

void Emu::emu_eval(){
    emu_simtop->io_coreIO_inst_readIO_data = 
        emu_ram->InstRead(emu_simtop->io_coreIO_inst_readIO_addr, emu_simtop->io_coreIO_inst_readIO_en);
    emu_simtop->io_coreIO_data_readIO_data =
        emu_ram->DataRead(emu_simtop->io_coreIO_data_readIO_addr, emu_simtop->io_coreIO_data_readIO_en);
    emu_ram->DataWrite( emu_simtop->io_coreIO_data_writeIO_addr,
        emu_simtop->io_coreIO_data_writeIO_data,
        emu_simtop->io_coreIO_data_writeIO_en,
        emu_simtop->io_coreIO_data_writeIO_mask);
}