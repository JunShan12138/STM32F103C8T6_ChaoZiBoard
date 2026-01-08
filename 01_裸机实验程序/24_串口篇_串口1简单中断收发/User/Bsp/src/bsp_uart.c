
#include "bsp.h"

UART_HandleTypeDef uart1;
UART_HandleTypeDef uart2;
UART_HandleTypeDef uart3;


uint8_t g_uart1_tx_buff[UART1_BUFF_SIZE];
uint8_t g_uart1_rx_buff[UART1_BUFF_SIZE];

volatile uint8_t g_uart1_rx_state;

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
    uart1.Instance          = USART1;  /* 串口编号 */
    uart1.Init.BaudRate     = baud;    /* 波特率 */
    uart1.Init.WordLength   = USART_WORDLENGTH_8B;  /* 数据宽度 */
    uart1.Init.StopBits     = USART_STOPBITS_1;     /* 停止位 */
    uart1.Init.Parity       = USART_PARITY_NONE;    /* 校验 */
    uart1.Init.Mode         = USART_MODE_TX_RX;     /* 工作模式 */
    uart1.Init.HwFlowCtl    = UART_HWCONTROL_NONE;  /* 硬件流控 */
    HAL_UART_Init(&uart1);

    HAL_UART_Receive_IT(&uart1, g_uart1_rx_buff, UART1_BUFF_SIZE);
}

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
    uart2.Instance          = USART2;  /* 串口编号 */
    uart2.Init.BaudRate     = baud;    /* 波特率 */
    uart2.Init.WordLength   = USART_WORDLENGTH_8B;  /* 数据宽度 */
    uart2.Init.StopBits     = USART_STOPBITS_1;     /* 停止位 */
    uart2.Init.Parity       = USART_PARITY_NONE;    /* 校验 */
    uart2.Init.Mode         = USART_MODE_TX_RX;     /* 工作模式 */
    uart2.Init.HwFlowCtl    = UART_HWCONTROL_NONE;  /* 硬件流控 */
    HAL_UART_Init(&uart2);
}

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
    uart3.Instance          = USART3;  /* 串口编号 */
    uart3.Init.BaudRate     = baud;    /* 波特率 */
    uart3.Init.WordLength   = USART_WORDLENGTH_8B;  /* 数据宽度 */
    uart3.Init.StopBits     = USART_STOPBITS_1;     /* 停止位 */
    uart3.Init.Parity       = USART_PARITY_NONE;    /* 校验 */
    uart3.Init.Mode         = USART_MODE_TX_RX;     /* 工作模式 */
    uart3.Init.HwFlowCtl    = UART_HWCONTROL_NONE;  /* 硬件流控 */
    HAL_UART_Init(&uart3);
}


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
    GPIO_InitTypeDef GPIO_Init;

    if (huart->Instance == USART1)
    {
        /* 开时钟 */
    #if USE_UART1_REMAP
        __HAL_RCC_AFIO_CLK_ENABLE();
        __HAL_AFIO_REMAP_USART1_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
    #else
        __HAL_RCC_GPIOA_CLK_ENABLE();
    #endif
        __HAL_RCC_USART1_CLK_ENABLE();

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


    }
    else if (huart->Instance == USART2)
    {
        /* 开的时钟 */
    #if USE_UART2_REMAP
    #else
        __HAL_RCC_GPIOA_CLK_ENABLE();
    #endif
        __HAL_RCC_USART2_CLK_ENABLE();

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
    }
    else if (huart->Instance == USART3)
    {
        /* 打开GPIOB、USART3的时钟 */
        __HAL_RCC_GPIOB_CLK_ENABLE();
        __HAL_RCC_USART3_CLK_ENABLE();

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
        memcpy(g_uart1_tx_buff, g_uart1_rx_buff, UART1_BUFF_SIZE);
        g_uart1_rx_state = 1;
        HAL_UART_Receive_IT(&uart1, g_uart1_rx_buff, UART1_BUFF_SIZE);
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
        memcpy(g_uart1_tx_buff, g_uart1_rx_buff, UART1_BUFF_SIZE);
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
    HAL_UART_IRQHandler(&uart1);
}

