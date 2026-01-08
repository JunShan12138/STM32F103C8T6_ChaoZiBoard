#ifndef __BSP_UART_H__
#define __BSP_UART_H__

#include <stdint.h>

/* 是否使用该驱动 */
#define USE_UART1_DRIVER    (1)
#define USE_UART2_DRIVER    (1)
#define USE_UART3_DRIVER    (1)

/* 串口重定向配置 */
#define USE_UART1_REMAP     (0)  /* 重映射前是PA9、PA10重映射后是PB6、PB7 */ 
#define USE_UART2_REMAP     (0)  /* 重映射前是PA2、PA3重映射后是~（待补充） */ 
#define USE_UART3_REMAP     (0)  /* 重映射前是PB10、PB11重映射后是~（待补充） */ 

/* 串口1缓冲区配置 */
#define UART1_TX_BUFF_SIZE     1024  /* 串口1发送缓冲区大小 */
#define UART1_RX_BUFF_SIZE     1024  /* 串口1接收缓冲区大小 */
#define UART1_RX_MAX           256   /* 串口1一次能接收的数据大小 */

/* 串口2缓冲区配置 */
#define UART2_TX_BUFF_SIZE     1024  /* 串口2发送缓冲区大小 */  
#define UART2_RX_BUFF_SIZE     1024  /* 串口2接收缓冲区大小 */   
#define UART2_RX_MAX           256   /* 串口2一次能接收的数据大小 */  

/* 串口3缓冲区配置 */
#define UART3_TX_BUFF_SIZE     1024  /* 串口3发送缓冲区大小 */ 
#define UART3_RX_BUFF_SIZE     1024  /* 串口3接收缓冲区大小 */ 
#define UART3_RX_MAX           256   /* 串口3一次能接收的数据大小 */ 

/* 环形缓冲指针数组大小 */
#define UART_PRT_ARR_SIZE      6

typedef struct 
{
    uint8_t *start;
    uint8_t *end;
}uart_ptr_t;

typedef struct
{
    /* 一次接收的数据个数 */
    uint32_t tx_count;
    uint32_t rx_count;

    /* 发送状态：0空闲，1忙 */
    uint32_t tx_state;

    /* 环形缓冲指针数组 */
    uart_ptr_t tx_ptr_arr[UART_PRT_ARR_SIZE];
    uart_ptr_t rx_ptr_arr[UART_PRT_ARR_SIZE];

    uart_ptr_t *rx_in;
    uart_ptr_t *rx_out;
    uart_ptr_t *rx_end;

    uart_ptr_t *tx_in;
    uart_ptr_t *tx_out;
    uart_ptr_t *tx_end;

    UART_HandleTypeDef uart;
    
    DMA_HandleTypeDef dma_tx;
    DMA_HandleTypeDef dma_rx;
}uart_ctrl_t;

extern uart_ctrl_t uart1;
extern uart_ctrl_t uart2;
extern uart_ctrl_t uart3;

/* 初始化 */
void uart1_init(uint32_t baud);
void uart2_init(uint32_t baud);
void uart3_init(uint32_t baud);

/* 发送数据 */
void uart1_tx_data(uint8_t *data, uint32_t len);
void uart2_tx_data(uint8_t *data, uint32_t len);
void uart3_tx_data(uint8_t *data, uint32_t len);

/* 发送处理函数 */
void uart1_tx_process(void);
void uart2_tx_process(void);
void uart3_tx_process(void);

/* 接收数据 */
uint8_t uart1_rx_data(uint8_t **data, uint32_t *len);
uint8_t uart2_rx_data(uint8_t **data, uint32_t *len);
uint8_t uart3_rx_data(uint8_t **data, uint32_t *len);

#endif
