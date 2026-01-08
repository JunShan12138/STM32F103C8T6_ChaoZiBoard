#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include <stdint.h>

#define USE_UART1_REMAP     (1)  /* 重映射前是PA9、PA10重映射后是PB6、PB7 */ 
#define USE_UART2_REMAP     (0)  /* 重映射前是PA2、PA3重映射后是~（待补充） */ 
#define USE_UART3_REMAP     (0)  /* 重映射前是PB10、PB11重映射后是~（待补充） */ 

extern UART_HandleTypeDef uart1;
extern UART_HandleTypeDef uart2;
extern UART_HandleTypeDef uart3;

void uart1_init(uint32_t baud);
void uart2_init(uint32_t baud);
void uart3_init(uint32_t baud);

#endif
