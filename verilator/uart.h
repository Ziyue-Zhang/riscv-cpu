#ifndef __UART_H__
#define __UART_H__


#include "common.h"

#define UART0_CTRL_ADDR 0x40600000
#define UART0_CTRL_SIZE 16


#define UARTLITE_RX_FIFO  0x0
#define UARTLITE_TX_FIFO  0x4
#define UARTLITE_STAT_REG 0x8

#define UARTLITE_TX_FULL  0x08
#define UARTLITE_RX_VALID 0x01

class Uart {
public:
  Uart();
  reg_t read(reg_t addr);
  void write(reg_t addr, reg_t data);



private:
  char uartreg;

};

#endif