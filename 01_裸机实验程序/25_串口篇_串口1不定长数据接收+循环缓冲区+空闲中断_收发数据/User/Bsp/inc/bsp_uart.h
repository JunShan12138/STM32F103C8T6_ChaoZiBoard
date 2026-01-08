#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include <stdint.h>

#define USE_UART1_REMAP     (0)  /* 重映射前是PA9、PA10重映射后是PB6、PB7 */ 
#define USE_UART2_REMAP     (0)  /* 重映射前是PA2、PA3重映射后是~（待补充） */ 
#define USE_UART3_REMAP     (0)  /* 重映射前是PB10、PB11重映射后是~（待补充） */ 

#define UART1_TX_BUFF_SIZE     1024
#define UART1_RX_BUFF_SIZE     1024
#define UART1_RX_MAX           256

#define UART_PRT_ARR_SIZE      6

typedef struct 
{
    uint8_t *start;
    uint8_t *end;
}uart_ptr_t;

typedef struct
{
    uint32_t tx_count;
    uint32_t rx_count;

    uint32_t tx_state;

    uart_ptr_t tx_ptr_arr[UART_PRT_ARR_SIZE];
    uart_ptr_t rx_ptr_arr[UART_PRT_ARR_SIZE];

    uart_ptr_t *rx_in;
    uart_ptr_t *rx_out;
    uart_ptr_t *rx_end;

    uart_ptr_t *tx_in;
    uart_ptr_t *tx_out;
    uart_ptr_t *tx_end;

    UART_HandleTypeDef uart;
}uart_ctrl_t;

extern uart_ctrl_t uart1;
extern UART_HandleTypeDef uart2;
extern UART_HandleTypeDef uart3;


void uart1_init(uint32_t baud);
void uart2_init(uint32_t baud);
void uart3_init(uint32_t baud);

void uart1_tx_data(uint8_t *data, uint32_t len);
void uart1_tx_process(void);

uint8_t uart1_rx_data(uint8_t **data, uint32_t *len);

#endif
