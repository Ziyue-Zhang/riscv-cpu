#include "uart.h"

#include <stdio.h>
#include <assert.h>

Uart::Uart()
{
}

reg_t Uart::read(reg_t addr)
{
  uartreg = UARTLITE_RX_VALID;
  
  if (addr == UART0_CTRL_ADDR) {
    char temp;
    scanf("%c", &temp);
    return (reg_t)temp;
  }
  else if (addr == UART0_CTRL_ADDR + 8) {
    return (reg_t)uartreg;
  }
  else {
    printf("Warning: Uart Read Addr out of range!!!\n");
  }
}

void Uart::write(reg_t addr, reg_t data)
{
  if (addr == UART0_CTRL_ADDR) {
    printf("%c", (char)(data >> 32));
    uartreg = (char)(data >> 32);
  }
  else {
    printf("Warning: Uart Write Addr out of range!!!\n");
  }
}
