#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include <stdint.h>

extern UART_HandleTypeDef uart1;

void uart1_init(uint32_t baud);

#endif
