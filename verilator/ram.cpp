#include "ram.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

Ram::Ram(char* imgPath)
{
//#ifdef DEBUG
  ram_size = RAMSIZE / sizeof(inst_t);
  memset(ram, 0, ram_size);
  /*img_size = 3;
  ram[0] = 0x800002b7;  // lui t0,0x80000
  ram[2] = 0x0002a023;  // sw  zero,0(t0)
  ram[3] = 0x0002a503;  // lw  a0,0(t0)*/

//#else
  assert(imgPath && "No image file.");
  FILE *fp = fopen(imgPath, "rb");
  assert(fp && "Can not open image file.");

  fseek(fp, 0, SEEK_END);
  img_size = ftell(fp);

  fseek(fp, 0, SEEK_SET);
  int ret = fread(ram, img_size, 1, fp);
  assert(ret == 1 && "Can not read image file.");
  fclose(fp);

//#ifdef DEBUG
  printf("RAM: %x\n", (unsigned int)ram[0]);
//#endif

//#endif
}

void* Ram::get_img_start()
{
  return &ram[0];;
}

int Ram::get_img_size()
{
  return img_size;
}


inst_t Ram::InstRead(inst_t addr, bool en)
{
  printf("inst read addr = 0x%016lx \n", addr);
  assert(ADDR_START <= addr &&
        addr <= ADDR_START + ram_size &&
        "read addr out of range");
  return en ? ram[(addr - ADDR_START) / sizeof(inst_t)] : 0;
}

reg_t Ram::DataRead(reg_t addr, bool en)
{
  printf("data addr = 0x%016lx \n", addr);
    assert(ADDR_START <= addr &&
        addr <= ADDR_START + ram_size &&
        "read data addr out of range");
    return en ? ram[(addr - ADDR_START) / sizeof(reg_t)] : 0; // 读data_ram
}

void Ram::DataWrite(reg_t addr, reg_t data, bool en, mask_t mask)
{
  assert(ADDR_START <= addr &&
        addr <= ADDR_START + ram_size &&
        "write data addr out of range");
    if (en) {
    ram[(addr - ADDR_START) / sizeof(reg_t)] = data;
  }
}