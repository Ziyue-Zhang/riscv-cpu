#ifndef __RAM_H__
#define __RAM_H__

#include "common.h"
#include "uart.h"

class Ram {
public:
  Ram(char* imgPath);
  void* get_img_start();
  int get_img_size();

  inst_t InstRead(reg_t addr, bool en);
  reg_t DataRead(reg_t addr, bool en);
  void DataWrite(reg_t addr, reg_t data, bool en, mask_t mask);

private:
  reg_t ram[RAMSIZE / sizeof(reg_t)];
  Uart* uart;
  int img_size;
  int ram_size; 
};

#endif