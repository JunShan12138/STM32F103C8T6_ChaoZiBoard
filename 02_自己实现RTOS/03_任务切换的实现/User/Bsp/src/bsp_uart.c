
#include "bsp.h"


#if USE_UART1_DRIVER
uart_ctrl_t uart1;
static uint8_t g_uart1_tx_buff[UART1_TX_BUFF_SIZE];
static uint8_t g_uart1_rx_buff[UART1_RX_BUFF_SIZE];
#endif

#if USE_UART2_DRIVER
uart_ctrl_t uart2;
static uint8_t g_uart2_tx_buff[UART2_TX_BUFF_SIZE];
static uint8_t g_uart2_rx_buff[UART2_RX_BUFF_SIZE];
#endif

#if USE_UART3_DRIVER
uart_ctrl_t uart3;
static uint8_t g_uart3_tx_buff[UART3_TX_BUFF_SIZE];
static uint8_t g_uart3_rx_buff[UART3_RX_BUFF_SIZE];
#endif


#if USE_UART1_DRIVER
/***************************************************************************************************
 * @fn      uart1_var_init
 *
 * @brief   初始化串口1相关的变量
 *
 * @param   无
 *
 * @return  无 
 */
static void uart1_var_init(void)
{
    uart1.rx_in    = &uart1.rx_ptr_arr[0];
    uart1.rx_out   = &uart1.rx_ptr_arr[0];
    uart1.rx_end   = &uart1.rx_ptr_arr[UART_PRT_ARR_SIZE - 1];
    uart1.rx_count = 0;
    uart1.rx_in->start = &g_uart1_rx_buff[0];

    uart1.tx_in    = &uart1.tx_ptr_arr[0];
    uart1.tx_out   = &uart1.tx_ptr_arr[0];
    uart1.tx_end   = &uart1.tx_ptr_arr[UART_PRT_ARR_SIZE - 1];
    uart1.tx_count = 0;
    uart1.tx_in->start = &g_uart1_tx_buff[0];
}
#endif

#if USE_UART2_DRIVER
/***************************************************************************************************
 * @fn      uart2_var_init
 *
 * @brief   初始化串口2相关的变量
 *
 * @param   无
 *
 * @return  无 
 */
static void uart2_var_init(void)
{
    uart2.rx_in    = &uart2.rx_ptr_arr[0];
    uart2.rx_out   = &uart2.rx_ptr_arr[0];
    uart2.rx_end   = &uart2.rx_ptr_arr[UART_PRT_ARR_SIZE - 1];
    uart2.rx_count = 0;
    uart2.rx_in->start = &g_uart2_rx_buff[0];

    uart2.tx_in    = &uart2.tx_ptr_arr[0];
    uart2.tx_out   = &uart2.tx_ptr_arr[0];
    uart2.tx_end   = &uart2.tx_ptr_arr[UART_PRT_ARR_SIZE - 1];
    uart2.tx_count = 0;
    uart2.tx_in->start = &g_uart2_tx_buff[0];
}
#endif

#if USE_UART3_DRIVER
/***************************************************************************************************
 * @fn      uart3_var_init
 *
 * @brief   初始化串口3相关的变量
 *
 * @param   无
 *
 * @return  无 
 */
static void uart3_var_init(void)
{
    uart3.rx_in    = &uart3.rx_ptr_arr[0];
    uart3.rx_out   = &uart3.rx_ptr_arr[0];
    uart3.rx_end   = &uart3.rx_ptr_arr[UART_PRT_ARR_SIZE - 1];
    uart3.rx_count = 0;
    uart3.rx_in->start = &g_uart3_rx_buff[0];

    uart3.tx_in    = &uart3.tx_ptr_arr[0];
    uart3.tx_out   = &uart3.tx_ptr_arr[0];
    uart3.tx_end   = &uart3.tx_ptr_arr[UART_PRT_ARR_SIZE - 1];
    uart3.tx_count = 0;
    uart3.tx_in->start = &g_uart3_rx_buff[0];
}
#endif

#if USE_UART1_DRIVER
/***************************************************************************************************
 * @fn      uart1_tx_data
 *
 * @brief   准备串口1要发送的数据
 *
 * @param   data 要发送的数据
 * @param   len 要发送的数据长度
 *
 * @return  无 
 */
void uart1_tx_data(uint8_t *data, uint32_t len)
{
    if ((UART1_TX_BUFF_SIZE - uart1.tx_count) >= len)
    {
        uart1.tx_in->start = &g_uart1_tx_buff[uart1.tx_count];
    }
    else
    {
        uart1.tx_count = 0;
        uart1.tx_in->start = &g_uart1_tx_buff[0];
    }

    uart1.tx_count += len;
    uart1.tx_in->end = &g_uart1_tx_buff[uart1.tx_count - 1];
    memcpy(uart1.tx_in->start, data, len);
    
    uart1.tx_in++;
    if (uart1.tx_in == uart1.tx_end)
    {
        uart1.tx_in = &uart1.tx_ptr_arr[0];
    }
}
#endif

#if USE_UART2_DRIVER
/***************************************************************************************************
 * @fn      uart2_tx_data
 *
 * @brief   准备串口2要发送的数据
 *
 * @param   data 要发送的数据
 * @param   len 要发送的数据长度
 *
 * @return  无 
 */
void uart2_tx_data(uint8_t *data, uint32_t len)
{
    if ((UART2_TX_BUFF_SIZE - uart2.tx_count) >= len)
    {
        uart2.tx_in->start = &g_uart2_tx_buff[uart2.tx_count];
    }
    else
    {
        uart2.tx_count = 0;
        uart2.tx_in->start = &g_uart2_tx_buff[0];
    }

    uart2.tx_count += len;
    uart2.tx_in->end = &g_uart2_tx_buff[uart2.tx_count - 1];
    memcpy(uart2.tx_in->start, data, len);
    
    uart2.tx_in++;
    if (uart2.tx_in == uart2.tx_end)
    {
        uart2.tx_in = &uart2.tx_ptr_arr[0];
    }
}
#endif

#if USE_UART3_DRIVER
/***************************************************************************************************
 * @fn      uart3_tx_data
 *
 * @brief   准备串口3要发送的数据
 *
 * @param   data 要发送的数据
 * @param   len 要发送的数据长度
 *
 * @return  无 
 */
void uart3_tx_data(uint8_t *data, uint32_t len)
{
    if ((UART3_TX_BUFF_SIZE - uart3.tx_count) >= len)
    {
        uart3.tx_in->start = &g_uart3_tx_buff[uart3.tx_count];
    }
    else
    {
        uart3.tx_count = 0;
        uart3.tx_in->start = &g_uart3_tx_buff[0];
    }

    uart3.tx_count += len;
    uart3.tx_in->end = &g_uart3_tx_buff[uart3.tx_count - 1];
    memcpy(uart3.tx_in->start, data, len);
    
    uart3.tx_in++;
    if (uart3.tx_in == uart3.tx_end)
    {
        uart3.tx_in = &uart3.tx_ptr_arr[0];
    }
}
#endif

#if USE_UART1_DRIVER
/***************************************************************************************************
 * @fn      uart1_tx_process
 *
 * @brief   处理要发送的数据
 *
 * @param   data 要发送的数据
 * @param   len 要发送的数据长度
 *
 * @return  0 没有数据，1有数据 
 */
void uart1_tx_process(void)
{
    uint16_t len;

    /* 发送缓冲区中有数据 */
    if ((uart1.tx_in != uart1.tx_out) && (uart1.tx_state == 0))
    {
        uart1.tx_state = 1;  /* 1表示发送忙碌 */

        len = uart1.tx_out->end - uart1.tx_out->start + 1;
        HAL_UART_Transmit_DMA(&uart1.uart, uart1.tx_out->start, len);
        
        uart1.tx_out++;
        if (uart1.tx_out == uart1.tx_end)
        {
            uart1.tx_out = &uart1.tx_ptr_arr[0];
        }
    }
}
#endif

#if USE_UART2_DRIVER
/***************************************************************************************************
 * @fn      uart2_tx_process
 *
 * @brief   处理要发送的数据
 *
 * @param   data 要发送的数据
 * @param   len 要发送的数据长度
 *
 * @return  0 没有数据，1有数据 
 */
void uart2_tx_process(void)
{
    uint16_t len;

    /* 发送缓冲区中有数据 */
    if ((uart2.tx_in != uart2.tx_out) && (uart2.tx_state == 0))
    {
        uart2.tx_state = 1;  /* 1表示发送忙碌 */

        len = uart2.tx_out->end - uart2.tx_out->start + 1;
        HAL_UART_Transmit_DMA(&uart2.uart, uart2.tx_out->start, len);
        
        uart2.tx_out++;
        if (uart2.tx_out == uart2.tx_end)
        {
            uart2.tx_out = &uart2.tx_ptr_arr[0];
        }
    }
}
#endif

#if USE_UART3_DRIVER
/***************************************************************************************************
 * @fn      uart3_tx_process
 *
 * @brief   处理要发送的数据
 *
 * @param   data 要发送的数据
 * @param   len 要发送的数据长度
 *
 * @return  0 没有数据，1有数据 
 */
void uart3_tx_process(void)
{
    uint16_t len;

    /* 发送缓冲区中有数据 */
    if ((uart3.tx_in != uart3.tx_out) && (uart3.tx_state == 0))
    {
        uart3.tx_state = 1;  /* 1表示发送忙碌 */

        len = uart3.tx_out->end - uart3.tx_out->start + 1;
        HAL_UART_Transmit_DMA(&uart3.uart, uart3.tx_out->start, len);
        
        uart3.tx_out++;
        if (uart3.tx_out == uart3.tx_end)
        {
            uart3.tx_out = &uart3.tx_ptr_arr[0];
        }
    }
}
#endif

#if USE_UART1_DRIVER
/***************************************************************************************************
 * @fn      uart1_rx_data
 *
 * @brief   串口接收数据
 *
 * @param   data 要发送的数据
 * @param   len 要发送的数据长度
 *
 * @return  0 没有数据，1有数据 
 */
uint8_t uart1_rx_data(uint8_t **data, uint32_t *len)
{ 
    if (uart1.rx_in != uart1.rx_out)
    {
        *data = uart1.rx_out->start;
        *len  = uart1.rx_out->end - uart1.rx_out->start + 1;

        uart1.rx_out++;

        /* 防止越界 */
        if (uart1.rx_out == uart1.rx_end)
        {
            uart1.rx_out = &uart1.rx_ptr_arr[0];
        }

        return 1;
    }
    else
    {
        return 0;
    }
}
#endif

#if USE_UART2_DRIVER
/***************************************************************************************************
 * @fn      uart2_rx_data
 *
 * @brief   串口接收数据
 *
 * @param   data 要发送的数据
 * @param   len 要发送的数据长度
 *
 * @return  0 没有数据，1有数据 
 */
uint8_t uart2_rx_data(uint8_t **data, uint32_t *len)
{ 
    if (uart2.rx_in != uart2.rx_out)
    {
        *data = uart2.rx_out->start;
        *len  = uart2.rx_out->end - uart2.rx_out->start + 1;

        uart2.rx_out++;

        /* 防止越界 */
        if (uart2.rx_out == uart2.rx_end)
        {
            uart2.rx_out = &uart2.rx_ptr_arr[0];
        }

        return 1;
    }
    else
    {
        return 0;
    }
}
#endif

#if USE_UART3_DRIVER
/***************************************************************************************************
 * @fn      uart3_rx_data
 *
 * @brief   串口接收数据
 *
 * @param   data 要发送的数据
 * @param   len 要发送的数据长度
 *
 * @return  0 没有数据，1有数据 
 */
uint8_t uart3_rx_data(uint8_t **data, uint32_t *len)
{ 
    if (uart3.rx_in != uart3.rx_out)
    {
        *data = uart3.rx_out->start;
        *len  = uart3.rx_out->end - uart3.rx_out->start + 1;

        uart3.rx_out++;

        /* 防止越界 */
        if (uart3.rx_out == uart3.rx_end)
        {
            uart3.rx_out = &uart3.rx_ptr_arr[0];
        }

        return 1;
    }
    else
    {
        return 0;
    }
}
#endif

#if USE_UART1_DRIVER
/***************************************************************************************************
 * @fn      uart1_init
 *
 * @brief   串口1初始化
 *
 * @param   无
 *
 * @return  无 
 */
void uart1_init(uint32_t baud)
{
    uart1.uart.Instance          = USART1;  /* 串口编号 */
    uart1.uart.Init.BaudRate     = baud;    /* 波特率 */
    uart1.uart.Init.WordLength   = USART_WORDLENGTH_8B;  /* 数据宽度 */
    uart1.uart.Init.StopBits     = USART_STOPBITS_1;     /* 停止位 */
    uart1.uart.Init.Parity       = USART_PARITY_NONE;    /* 校验 */
    uart1.uart.Init.Mode         = USART_MODE_TX_RX;     /* 工作模式 */
    uart1.uart.Init.HwFlowCtl    = UART_HWCONTROL_NONE;  /* 硬件流控 */
    HAL_UART_Init(&uart1.uart);

    uart1_var_init();

    /* 开启空闲中断 */
    __HAL_UART_ENABLE_IT(&uart1.uart, UART_IT_IDLE);

    HAL_UART_Receive_DMA(&uart1.uart, uart1.rx_in->start, UART1_RX_MAX);
}
#endif

#if USE_UART2_DRIVER
/***************************************************************************************************
 * @fn      uart2_init
 *
 * @brief   串口2初始化
 *
 * @param   无
 *
 * @return  无 
 */
void uart2_init(uint32_t baud)
{
    uart2.uart.Instance          = USART2;  /* 串口编号 */
    uart2.uart.Init.BaudRate     = baud;    /* 波特率 */
    uart2.uart.Init.WordLength   = USART_WORDLENGTH_8B;  /* 数据宽度 */
    uart2.uart.Init.StopBits     = USART_STOPBITS_1;     /* 停止位 */
    uart2.uart.Init.Parity       = USART_PARITY_NONE;    /* 校验 */
    uart2.uart.Init.Mode         = USART_MODE_TX_RX;     /* 工作模式 */
    uart2.uart.Init.HwFlowCtl    = UART_HWCONTROL_NONE;  /* 硬件流控 */
    HAL_UART_Init(&uart2.uart);

    uart2_var_init();

    /* 开启空闲中断 */
    __HAL_UART_ENABLE_IT(&uart2.uart, UART_IT_IDLE);

    HAL_UART_Receive_DMA(&uart2.uart, uart2.rx_in->start, UART2_RX_MAX);
}
#endif

#if USE_UART3_DRIVER
/***************************************************************************************************
 * @fn      uart3_init
 *
 * @brief   串口3初始化
 *
 * @param   无
 *
 * @return  无 
 */
void uart3_init(uint32_t baud)
{
    uart3.uart.Instance          = USART3;  /* 串口编号 */
    uart3.uart.Init.BaudRate     = baud;    /* 波特率 */
    uart3.uart.Init.WordLength   = USART_WORDLENGTH_8B;  /* 数据宽度 */
    uart3.uart.Init.StopBits     = USART_STOPBITS_1;     /* 停止位 */
    uart3.uart.Init.Parity       = USART_PARITY_NONE;    /* 校验 */
    uart3.uart.Init.Mode         = USART_MODE_TX_RX;     /* 工作模式 */
    uart3.uart.Init.HwFlowCtl    = UART_HWCONTROL_NONE;  /* 硬件流控 */
    HAL_UART_Init(&uart3.uart);

    uart3_var_init();

    /* 开启空闲中断 */
    __HAL_UART_ENABLE_IT(&uart3.uart, UART_IT_IDLE);

    HAL_UART_Receive_DMA(&uart3.uart, uart3.rx_in->start, UART3_RX_MAX);
}
#endif


/***************************************************************************************************
 * @fn      HAL_UART_MspInit
 *
 * @brief   UART的回调函数
 *
 * @param   无
 *
 * @return  无 
 */
void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
#if (USE_UART1_DRIVER | USE_UART2_DRIVER | USE_UART3_DRIVER)
    GPIO_InitTypeDef GPIO_Init;
#endif

    if (huart->Instance == USART1)
    {
#if USE_UART1_DRIVER
        /* 开时钟 */
    #if USE_UART1_REMAP
        __HAL_RCC_AFIO_CLK_ENABLE();
        __HAL_AFIO_REMAP_USART1_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
    #else
        __HAL_RCC_GPIOA_CLK_ENABLE();
    #endif
        __HAL_RCC_USART1_CLK_ENABLE();
        __HAL_RCC_DMA1_CLK_ENABLE();

    #if USE_UART1_REMAP
        /* 配置引脚PB6 */
        GPIO_Init.Pin   = GPIO_PIN_6;
        GPIO_Init.Mode  = GPIO_MODE_AF_PP;
        GPIO_Init.Pull  = GPIO_NOPULL;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOB, &GPIO_Init);

        /* 配置引脚PB7 */
        GPIO_Init.Pin   = GPIO_PIN_7;
        GPIO_Init.Mode  = GPIO_MODE_AF_INPUT;
        GPIO_Init.Pull  = GPIO_NOPULL;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOB, &GPIO_Init);
    #else
        /* 配置引脚PA9 */
        GPIO_Init.Pin   = GPIO_PIN_9;
        GPIO_Init.Mode  = GPIO_MODE_AF_PP;
        GPIO_Init.Pull  = GPIO_NOPULL;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_Init);

        /* 配置引脚PA10 */
        GPIO_Init.Pin   = GPIO_PIN_10;
        GPIO_Init.Mode  = GPIO_MODE_AF_INPUT;
        GPIO_Init.Pull  = GPIO_NOPULL;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_Init);
    #endif

        /* 配置中断优先级 */
        HAL_NVIC_SetPriority(USART1_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(USART1_IRQn);

        /* DMA发送配置 */
        uart1.dma_tx.Instance       = DMA1_Channel4;  /* DMA通道选择 */
        uart1.dma_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;  /* DMA传输方向 */
        uart1.dma_tx.Init.PeriphInc = DMA_PINC_DISABLE;  /* 外设地址不递增 */
        uart1.dma_tx.Init.MemInc    = DMA_MINC_ENABLE;  /* 缓冲区地址递增 */

        /* 外设数据宽度：一个字节  */
        uart1.dma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;

        /* 内存数据宽度：一个字节 */
        uart1.dma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;

        uart1.dma_tx.Init.Mode     = DMA_NORMAL;  /* 正常的单次发送 */
        uart1.dma_tx.Init.Priority = DMA_PRIORITY_MEDIUM;  /* 优先级 */
        __HAL_LINKDMA(huart, hdmatx, uart1.dma_tx);
        HAL_DMA_Init(&uart1.dma_tx);

        /* 设置DMA发送中断优先级 */
        HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);

        /* DMA接收配置 */
        uart1.dma_rx.Instance       = DMA1_Channel5;  /* DMA通道选择 */
        uart1.dma_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;  /* DMA传输方向 */
        uart1.dma_rx.Init.PeriphInc = DMA_PINC_DISABLE;  /* 外设地址不递增 */
        uart1.dma_rx.Init.MemInc    = DMA_MINC_ENABLE;  /* 缓冲区地址递增 */

        /* 外设数据宽度：一个字节  */
        uart1.dma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;

        /* 内存数据宽度：一个字节 */
        uart1.dma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;

        uart1.dma_rx.Init.Mode     = DMA_NORMAL;  /* 正常的单次发送 */
        uart1.dma_rx.Init.Priority = DMA_PRIORITY_MEDIUM;  /* 优先级 */
        __HAL_LINKDMA(huart, hdmarx, uart1.dma_rx);
        HAL_DMA_Init(&uart1.dma_rx);

        /* 设置DMA接收中断优先级 */
        HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);
#endif
    }
    else if (huart->Instance == USART2)
    {
#if USE_UART2_DRIVER
        /* 开的时钟 */
    #if USE_UART2_REMAP
    #else
        __HAL_RCC_GPIOA_CLK_ENABLE();
    #endif
        __HAL_RCC_USART2_CLK_ENABLE();
        __HAL_RCC_DMA1_CLK_ENABLE();

        /* 配置引脚PA2 */
        GPIO_Init.Pin   = GPIO_PIN_2;
        GPIO_Init.Mode  = GPIO_MODE_AF_PP;
        GPIO_Init.Pull  = GPIO_NOPULL;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_Init);

        /* 配置引脚PA3 */
        GPIO_Init.Pin   = GPIO_PIN_3;
        GPIO_Init.Mode  = GPIO_MODE_AF_INPUT;
        GPIO_Init.Pull  = GPIO_NOPULL;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOA, &GPIO_Init);

        /* 配置中断优先级 */
        HAL_NVIC_SetPriority(USART2_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(USART2_IRQn);

        /* DMA发送配置 */
        uart2.dma_tx.Instance       = DMA1_Channel7;  /* DMA通道选择 */
        uart2.dma_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;  /* DMA传输方向 */
        uart2.dma_tx.Init.PeriphInc = DMA_PINC_DISABLE;  /* 外设地址不递增 */
        uart2.dma_tx.Init.MemInc    = DMA_MINC_ENABLE;  /* 缓冲区地址递增 */

        /* 外设数据宽度：一个字节  */
        uart2.dma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;

        /* 内存数据宽度：一个字节 */
        uart2.dma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;

        uart2.dma_tx.Init.Mode     = DMA_NORMAL;  /* 正常的单次发送 */
        uart2.dma_tx.Init.Priority = DMA_PRIORITY_MEDIUM;  /* 优先级 */
        __HAL_LINKDMA(huart, hdmatx, uart2.dma_tx);
        HAL_DMA_Init(&uart2.dma_tx);

        /* 设置DMA发送中断优先级 */
        HAL_NVIC_SetPriority(DMA1_Channel7_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(DMA1_Channel7_IRQn);

        /* DMA接收配置 */
        uart2.dma_rx.Instance       = DMA1_Channel6;  /* DMA通道选择 */
        uart2.dma_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;  /* DMA传输方向 */
        uart2.dma_rx.Init.PeriphInc = DMA_PINC_DISABLE;  /* 外设地址不递增 */
        uart2.dma_rx.Init.MemInc    = DMA_MINC_ENABLE;  /* 缓冲区地址递增 */

        /* 外设数据宽度：一个字节  */
        uart2.dma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;

        /* 内存数据宽度：一个字节 */
        uart2.dma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;

        uart2.dma_rx.Init.Mode     = DMA_NORMAL;  /* 正常的单次发送 */
        uart2.dma_rx.Init.Priority = DMA_PRIORITY_MEDIUM;  /* 优先级 */
        __HAL_LINKDMA(huart, hdmarx, uart2.dma_rx);
        HAL_DMA_Init(&uart2.dma_rx);

        /* 设置DMA接收中断优先级 */
        HAL_NVIC_SetPriority(DMA1_Channel6_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(DMA1_Channel6_IRQn);
#endif
    }
    else if (huart->Instance == USART3)
    {
#if USE_UART3_DRIVER
        /* 打开GPIOB、USART3的时钟 */
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_USART3_CLK_ENABLE();
        __HAL_RCC_DMA1_CLK_ENABLE();

        /* 配置引脚PB10 */
        GPIO_Init.Pin   = GPIO_PIN_10;
        GPIO_Init.Mode  = GPIO_MODE_AF_PP;
        GPIO_Init.Pull  = GPIO_NOPULL;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOB, &GPIO_Init);

        /* 配置引脚PB11 */
        GPIO_Init.Pin   = GPIO_PIN_11;
        GPIO_Init.Mode  = GPIO_MODE_AF_INPUT;
        GPIO_Init.Pull  = GPIO_NOPULL;
        GPIO_Init.Speed = GPIO_SPEED_FREQ_HIGH;
        HAL_GPIO_Init(GPIOB, &GPIO_Init);

        /* 配置中断优先级 */
        HAL_NVIC_SetPriority(USART3_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(USART3_IRQn);

        /* DMA发送配置 */
        uart3.dma_tx.Instance       = DMA1_Channel2;  /* DMA通道选择 */
        uart3.dma_tx.Init.Direction = DMA_MEMORY_TO_PERIPH;  /* DMA传输方向 */
        uart3.dma_tx.Init.PeriphInc = DMA_PINC_DISABLE;  /* 外设地址不递增 */
        uart3.dma_tx.Init.MemInc    = DMA_MINC_ENABLE;  /* 缓冲区地址递增 */

        /* 外设数据宽度：一个字节  */
        uart3.dma_tx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;

        /* 内存数据宽度：一个字节 */
        uart3.dma_tx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;

        uart3.dma_tx.Init.Mode     = DMA_NORMAL;  /* 正常的单次发送 */
        uart3.dma_tx.Init.Priority = DMA_PRIORITY_MEDIUM;  /* 优先级 */
        __HAL_LINKDMA(huart, hdmatx, uart3.dma_tx);
        HAL_DMA_Init(&uart3.dma_tx);

        /* 设置DMA发送中断优先级 */
        HAL_NVIC_SetPriority(DMA1_Channel2_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(DMA1_Channel2_IRQn);

        /* DMA接收配置 */
        uart3.dma_rx.Instance       = DMA1_Channel3;  /* DMA通道选择 */
        uart3.dma_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;  /* DMA传输方向 */
        uart3.dma_rx.Init.PeriphInc = DMA_PINC_DISABLE;  /* 外设地址不递增 */
        uart3.dma_rx.Init.MemInc    = DMA_MINC_ENABLE;  /* 缓冲区地址递增 */

        /* 外设数据宽度：一个字节  */
        uart3.dma_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;

        /* 内存数据宽度：一个字节 */
        uart3.dma_rx.Init.MemDataAlignment    = DMA_MDATAALIGN_BYTE;

        uart3.dma_rx.Init.Mode     = DMA_NORMAL;  /* 正常的单次发送 */
        uart3.dma_rx.Init.Priority = DMA_PRIORITY_MEDIUM;  /* 优先级 */
        __HAL_LINKDMA(huart, hdmarx, uart3.dma_rx);
        HAL_DMA_Init(&uart3.dma_rx);

        /* 设置DMA接收中断优先级 */
        HAL_NVIC_SetPriority(DMA1_Channel3_IRQn, 3, 0);
        HAL_NVIC_EnableIRQ(DMA1_Channel3_IRQn);
#endif
    }
}

/***************************************************************************************************
 * @fn      HAL_UART_RxCpltCallback
 *
 * @brief   UART的接收中断回调函数
 *
 * @param   无
 *
 * @return  无 
 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        ;
    }
}

/***************************************************************************************************
 * @fn      HAL_UART_TxCpltCallback
 *
 * @brief   UART的发送中断回调函数
 *
 * @param   无
 *
 * @return  无 
 */
void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
    #if USE_UART1_DRIVER
        uart1.tx_state = 0;  /* 发送完成，则清忙碌状态 */
    #endif
    }
    else if (huart->Instance == USART2)
    {
    #if USE_UART2_DRIVER
        uart2.tx_state = 0;  /* 发送完成，则清忙碌状态 */
    #endif
    }
    else if (huart->Instance == USART3)
    {
    #if USE_UART3_DRIVER
        uart3.tx_state = 0;  /* 发送完成，则清忙碌状态 */
    #endif
    }
}

/***************************************************************************************************
 * @fn      HAL_UART_ErrorCallback
 *
 * @brief   UART的错误中断回调函数
 *
 * @param   无
 *
 * @return  无 
 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
        ;
    }
}

/***************************************************************************************************
 * @fn      HAL_UART_AbortReceiveCpltCallback
 *
 * @brief   UART的终止接收回调函数
 *
 * @param   无
 *
 * @return  无 
 */
void HAL_UART_AbortReceiveCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1)
    {
    #if USE_UART1_DRIVER
        uart1.rx_in->end = &g_uart1_rx_buff[uart1.rx_count - 1];
        uart1.rx_in++;

        if (uart1.rx_in >= uart1.rx_end)
        {
            uart1.rx_in = &uart1.rx_ptr_arr[0];
        }

        if ((UART1_RX_BUFF_SIZE - uart1.rx_count) < UART1_RX_MAX)
        {
            uart1.rx_count = 0;
            uart1.rx_in->start = &g_uart1_rx_buff[0];
        }
        else
        {
            uart1.rx_in->start = &g_uart1_rx_buff[uart1.rx_count];
        }

        HAL_UART_Receive_DMA(&uart1.uart, uart1.rx_in->start, UART1_RX_MAX);
    #endif
    }
    else if (huart->Instance == USART2)
    {
    #if USE_UART2_DRIVER
        uart2.rx_in->end = &g_uart2_rx_buff[uart2.rx_count - 1];
        uart2.rx_in++;

        if (uart2.rx_in >= uart2.rx_end)
        {
            uart2.rx_in = &uart2.rx_ptr_arr[0];
        }

        if ((UART2_RX_BUFF_SIZE - uart2.rx_count) < UART2_RX_MAX)
        {
            uart2.rx_count = 0;
            uart2.rx_in->start = &g_uart2_rx_buff[0];
        }
        else
        {
            uart2.rx_in->start = &g_uart2_rx_buff[uart2.rx_count];
        }

        HAL_UART_Receive_DMA(&uart2.uart, uart2.rx_in->start, UART2_RX_MAX);
    #endif
    }
    else if (huart->Instance == USART3)
    {
    #if USE_UART3_DRIVER
        uart3.rx_in->end = &g_uart3_rx_buff[uart3.rx_count - 1];
        uart3.rx_in++;

        if (uart3.rx_in >= uart3.rx_end)
        {
            uart3.rx_in = &uart3.rx_ptr_arr[0];
        }

        if ((UART3_RX_BUFF_SIZE - uart3.rx_count) < UART3_RX_MAX)
        {
            uart3.rx_count = 0;
            uart3.rx_in->start = &g_uart3_rx_buff[0];
        }
        else
        {
            uart3.rx_in->start = &g_uart3_rx_buff[uart3.rx_count];
        }

        HAL_UART_Receive_DMA(&uart3.uart, uart3.rx_in->start, UART3_RX_MAX);
    #endif
    }
}

/***************************************************************************************************
 * @fn      USART1_IRQHandler
 *
 * @brief   UART1的中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void USART1_IRQHandler(void)
{
#if USE_UART1_DRIVER
    HAL_UART_IRQHandler(&uart1.uart);

    /* 发生空闲中断 */
    if (__HAL_UART_GET_FLAG(&uart1.uart, UART_FLAG_IDLE))
    {
        __HAL_UART_CLEAR_IDLEFLAG(&uart1.uart);
        
        uart1.rx_count += (UART1_RX_MAX - __HAL_DMA_GET_COUNTER(&uart1.dma_rx));

        HAL_UART_AbortReceive_IT(&uart1.uart);
    }
#endif
}

/***************************************************************************************************
 * @fn      USART2_IRQHandler
 *
 * @brief   UART2的中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void USART2_IRQHandler(void)
{
#if USE_UART2_DRIVER
    HAL_UART_IRQHandler(&uart2.uart);

    /* 发生空闲中断 */
    if (__HAL_UART_GET_FLAG(&uart2.uart, UART_FLAG_IDLE))
    {
        __HAL_UART_CLEAR_IDLEFLAG(&uart2.uart);
        
        uart2.rx_count += (UART2_RX_MAX - __HAL_DMA_GET_COUNTER(&uart2.dma_rx));

        HAL_UART_AbortReceive_IT(&uart2.uart);
    }
#endif
}

/***************************************************************************************************
 * @fn      USART3_IRQHandler
 *
 * @brief   UART3的中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void USART3_IRQHandler(void)
{
#if USE_UART3_DRIVER
    HAL_UART_IRQHandler(&uart3.uart);

    /* 发生空闲中断 */
    if (__HAL_UART_GET_FLAG(&uart3.uart, UART_FLAG_IDLE))
    {
        __HAL_UART_CLEAR_IDLEFLAG(&uart3.uart);
        
        uart3.rx_count += (UART3_RX_MAX - __HAL_DMA_GET_COUNTER(&uart3.dma_rx));

        HAL_UART_AbortReceive_IT(&uart3.uart);
    }
#endif
}

/***************************************************************************************************
 * @fn      DMA1_Channel4_IRQHandler
 *
 * @brief   DMA1通道4的中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void DMA1_Channel4_IRQHandler(void)
{
#if USE_UART1_DRIVER
    HAL_DMA_IRQHandler(&uart1.dma_tx);
#endif
}

/***************************************************************************************************
 * @fn      DMA1_Channel5_IRQHandler
 *
 * @brief   DMA1通道5的中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void DMA1_Channel5_IRQHandler(void)
{
#if USE_UART1_DRIVER
    HAL_DMA_IRQHandler(&uart1.dma_rx);
#endif
}

/***************************************************************************************************
 * @fn      DMA1_Channel6_IRQHandler
 *
 * @brief   DMA1通道6的中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void DMA1_Channel6_IRQHandler(void)
{
#if USE_UART2_DRIVER
    HAL_DMA_IRQHandler(&uart2.dma_rx);
#endif
}

/***************************************************************************************************
 * @fn      DMA1_Channel7_IRQHandler
 *
 * @brief   DMA1通道7的中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void DMA1_Channel7_IRQHandler(void)
{
#if USE_UART2_DRIVER
    HAL_DMA_IRQHandler(&uart2.dma_tx);
#endif
}

/***************************************************************************************************
 * @fn      DMA1_Channel2_IRQHandler
 *
 * @brief   DMA1通道2的中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void DMA1_Channel2_IRQHandler(void)
{
#if USE_UART3_DRIVER
    HAL_DMA_IRQHandler(&uart3.dma_tx);
#endif
}

/***************************************************************************************************
 * @fn      DMA1_Channel3_IRQHandler
 *
 * @brief   DMA1通道3的中断服务函数
 *
 * @param   无
 *
 * @return  无 
 */
void DMA1_Channel3_IRQHandler(void)
{
#if USE_UART3_DRIVER
    HAL_DMA_IRQHandler(&uart3.dma_rx);
#endif
}

#if (USE_UART1_DRIVER | USE_UART2_DRIVER | USE_UART3_DRIVER)
static uint8_t _temp_buff[512];
#endif

#if USE_UART1_DRIVER
/***************************************************************************************************
 * @fn      uart1_printf
 *
 * @brief   串口1printf输出
 *
 * @param   无
 *
 * @return  无 
 */
void uart1_printf(char *fmt, ...)
{
    uint16_t i;
    va_list ap;

    va_start(ap, fmt);
    vsprintf((char *)_temp_buff, fmt, ap);
    va_end(ap);

    for (i = 0; i < strlen((char *)_temp_buff); i++)
    {
        while (!__HAL_UART_GET_FLAG(&uart1.uart, UART_FLAG_TXE))
        {}

        uart1.uart.Instance->DR = _temp_buff[i];
    }

    while (!__HAL_UART_GET_FLAG(&uart1.uart, UART_FLAG_TC))
    {}
}
#endif

#if USE_UART2_DRIVER
/***************************************************************************************************
 * @fn      uart2_printf
 *
 * @brief   串口2printf输出
 *
 * @param   无
 *
 * @return  无 
 */
void uart2_printf(char *fmt, ...)
{
    uint16_t i;
    va_list ap;

    va_start(ap, fmt);
    vsprintf((char *)_temp_buff, fmt, ap);
    va_end(ap);

    for (i = 0; i < strlen((char *)_temp_buff); i++)
    {
        while (!__HAL_UART_GET_FLAG(&uart2.uart, UART_FLAG_TXE))
        {}

        uart2.uart.Instance->DR = _temp_buff[i];
    }

    while (!__HAL_UART_GET_FLAG(&uart2.uart, UART_FLAG_TC))
    {}
}
#endif

#if USE_UART3_DRIVER
/***************************************************************************************************
 * @fn      uart3_printf
 *
 * @brief   串口3printf输出
 *
 * @param   无
 *
 * @return  无 
 */
void uart3_printf(char *fmt, ...)
{
    uint16_t i;
    va_list ap;

    va_start(ap, fmt);
    vsprintf((char *)_temp_buff, fmt, ap);
    va_end(ap);

    for (i = 0; i < strlen((char *)_temp_buff); i++)
    {
        while (!__HAL_UART_GET_FLAG(&uart3.uart, UART_FLAG_TXE))
        {}

        uart3.uart.Instance->DR = _temp_buff[i];
    }

    while (!__HAL_UART_GET_FLAG(&uart3.uart, UART_FLAG_TC))
    {}
}
#endif
