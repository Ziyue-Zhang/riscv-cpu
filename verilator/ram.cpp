#include "ram.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

Ram::Ram(char* imgPath) {
  ram_size = RAMSIZE / sizeof(reg_t);
  memset(ram, 0, ram_size);

  assert(imgPath && "No image file.");
  FILE *fp = fopen(imgPath, "rb");
  assert(fp && "Can not open image file.");

  fseek(fp, 0, SEEK_END);
  img_size = ftell(fp);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(ram, img_size, 1, fp);
  assert(ret == 1 && "Can not read image file.");
  fclose(fp);

  uart = new Uart();
}

void* Ram::get_img_start()
{
  return &ram[0];;
}

int Ram::get_img_size()
{
  return img_size;
}


inst_t Ram::InstRead(reg_t addr, bool en){
  if(!en){
    return 0;
  }
  //printf("inst read addr = 0x%016lx \n", addr);
  assert(ADDR_START <= addr &&
      addr <= ADDR_START + ram_size &&
      "read addr out of range");
  return ram[(addr - ADDR_START) / sizeof(reg_t)] >> ((addr % sizeof(reg_t)) * 8);
}

reg_t Ram::DataRead(reg_t addr, bool en){
  if(!en){
    return 0;
  }
  /*printf("data read addr = 0x%016lx data = 0x%016lx\n", addr,
    ram[(addr - ADDR_START) / sizeof(reg_t)] >> ((addr % sizeof(reg_t)) * 8));*/
  if((ADDR_START <= addr) && (addr < ADDR_START + ram_size)){
    return ram[(addr - ADDR_START) / sizeof(reg_t)] >> ((addr % sizeof(reg_t)) * 8);
  }
  else if((UART0_CTRL_ADDR <= addr) && (addr < UART0_CTRL_ADDR + UART0_CTRL_SIZE)) {
    return uart->read(addr);
  }
  else{
    assert(ADDR_START <= addr &&
      addr <= ADDR_START + ram_size &&
      "read data addr out of range");
  }
}

void Ram::DataWrite(reg_t addr, reg_t data, bool en, mask_t mask)
{
  if(!en){
    return;
  }
  /*assert(ADDR_START <= addr &&
      addr <= ADDR_START + ram_size &&
      "write data addr out of range");*/
    
  reg_t data_mask = data;
  reg_t full_mask = 0;
  reg_t tmp = 0xff;     
  for (size_t i = 0; i < 8; i++) {
      if ((mask >> i) & 0x1) {
          full_mask = full_mask | (tmp << (i*8));
      }
  }
  data_mask = (full_mask & data) | (~full_mask & ram[(addr - ADDR_START) / sizeof(reg_t)]);
  if((ADDR_START <= addr) && (addr < ADDR_START + ram_size)){
    ram[(addr - ADDR_START) / sizeof(reg_t)] = data_mask;
  }
  else if((UART0_CTRL_ADDR <= addr) && (addr < UART0_CTRL_ADDR + UART0_CTRL_SIZE)) {
     uart->write(addr, data);
  }
  else{
    assert(ADDR_START <= addr &&
      addr <= ADDR_START + ram_size &&
      "read data addr out of range");
  }
  //printf("data write addr = 0x%016lx \n", addr);
  //printf("mask = %x, fullMask= 0x%016lx, data = 0x%016lx, data_mask = 0x%016lx\n", mask, full_mask, data, data_mask);
}