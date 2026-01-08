
#include "bsp.h"

UART_HandleTypeDef uart1;

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
        /* 打开GPIOA、USART1的时钟 */
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_USART1_CLK_ENABLE();

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
    }
}


