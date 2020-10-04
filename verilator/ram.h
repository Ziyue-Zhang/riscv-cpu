#ifndef __RAM_H__
#define __RAM_H__

#include "common.h"

class Ram {
public:
  Ram(char* imgPath);
  void* get_img_start();
  int get_img_size();

  inst_t InstRead(inst_t addr, bool en);
  reg_t DataRead(reg_t addr, bool en);
  void DataWrite(reg_t addr, reg_t data, bool en, mask_t mask);

private:
  inst_t ram[RAMSIZE / sizeof(inst_t)];
  int img_size;
  int ram_size; 
};

#endif