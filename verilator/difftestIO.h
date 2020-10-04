#ifndef __DIFFTESTIO_H__
#define __DIFFTESTIO_H__

#include "common.h"

typedef struct diffTestIO_t
{
  reg_t regfile[NUM_REG];
  reg_t PC;  //PC must follow regFile continuously in address space
  reg_t empty[6];
} diffTestIO;

#endif