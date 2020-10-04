#ifndef __COMMON_H__
#define __COMMON_H__

//#define DEBUG
#define __RV64__
#define NUM_REG 32
#define ADDR_START 0x80000000

typedef unsigned int uint32_t;
typedef unsigned long int uint64_t;

#ifdef __RV32__
typedef uint32_t reg_t;
#define XLEN 32

#elif defined __RV64__
typedef uint64_t reg_t;
#define XLEN 64

#endif

typedef uint32_t inst_t;
typedef uint32_t mask_t;

#define RAMSIZE (128 * 1024 * 1024)

#endif