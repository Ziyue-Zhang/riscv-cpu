#include <iostream>
#include <dlfcn.h>
#include <assert.h>
using namespace std;
#include "difftest.h"
#include "emu.h"

const char* dllPath = "/home/zzy/Desktop/riscv/verilator/nemu_so/riscv64-nemu-interpreter-so";
// 等待获取的6个函数指针
void (*ref_difftest_memcpy_from_dut)(reg_t dest, void *src, size_t n);
void (*ref_difftest_getregs)(void *c);
void (*ref_difftest_setregs)(const void *c);
void (*ref_difftest_exec)(uint64_t n);
void (*ref_difftest_raise_intr)(uint64_t NO);
void (*ref_isa_reg_display)(void);

void init_difftest(reg_t *reg, char* imgPath, Ram* ram){
    void *handle;
    handle = dlopen(dllPath, RTLD_LAZY | RTLD_DEEPBIND);
    assert(handle);
    // 获取6个函数
    ref_difftest_memcpy_from_dut = (void (*)(reg_t dest, void *src, size_t n))dlsym(handle, "difftest_memcpy_from_dut");
    assert(ref_difftest_memcpy_from_dut);

    ref_difftest_getregs = (void (*)(void *))dlsym(handle, "difftest_getregs");
    assert(ref_difftest_getregs);
  
    ref_difftest_setregs = (void (*)(const void *))dlsym(handle, "difftest_setregs");
    assert(ref_difftest_setregs);
  
    ref_difftest_exec = (void (*)(uint64_t))dlsym(handle, "difftest_exec");
    assert(ref_difftest_exec);
  
    ref_difftest_raise_intr = (void (*)(uint64_t))dlsym(handle, "difftest_raise_intr");
    assert(ref_difftest_raise_intr);
  
    ref_isa_reg_display = (void (*)(void))dlsym(handle, "isa_reg_display");
    assert(ref_isa_reg_display);
  
    void (*ref_difftest_init)(void) = (void (*)(void))dlsym(handle, "difftest_init");
    assert(ref_difftest_init);

    ref_difftest_init();
    ref_isa_reg_display();

    ref_difftest_memcpy_from_dut(ADDR_START, ram->get_img_start(), ram->get_img_size());

    /*ref_difftest_exec(1);               // test exec
    //ref_isa_reg_display();
    reg_t reg_ref[NUM_REG+7];
    ref_difftest_getregs(&reg_ref);
    reg_t temp=reg_ref[32];

    int i=2000;
    while(i--){
        ref_difftest_exec(1);               // test exec
        //ref_isa_reg_display();
        ref_difftest_getregs(&reg_ref);
        if(temp==reg_ref[32]){
            return;
        }
        else{
            temp=reg_ref[32];
        }
    }*/
}

void difftest_step(Emu* emu) {
    reg_t reg_dut[DIFFTEST_NR_REG];
    reg_t reg_ref[DIFFTEST_NR_REG];
    reg_t temp=0;
    for(; i>0; i--) {
        emu->step(1);
        emu->emu_difftest_getregs(reg_dut);
        ref_difftest_exec(1);
        ref_difftest_getregs(&reg_ref);
        if(temp==reg_ref[32]){
            return;
        }
        else{
            temp=reg_ref[32];
        }
        //ref_isa_reg_display();
        bool flag = false;
        for (int i = 0; i < 32; i++) {
            if (reg_dut[i] != reg_ref[i]) {
                printf("reg %d %s different at pc = [0x%16lx], nemu=[0x%16lx], mycore=[0x%16lx]\n",
                i, reg_name[i], reg_dut[32], reg_ref[i], reg_dut[i]);
                flag=true;
            }
        }
        if(reg_dut[32] != reg_ref[32]) {
            printf("right pc = [0x%16x], wrong pc = [0x%16x] \n", reg_ref[32], reg_dut[32]);
            flag=true;
        }
        if(flag){
            return;
        }
    }
}
