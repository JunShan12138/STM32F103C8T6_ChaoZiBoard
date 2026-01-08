
#include "bsp.h"

#define RX_SIZE   200

uint8_t buffer[256];

int main(void)
{
    HAL_StatusTypeDef status;
    
    bsp_init();

    while (1)
    {
        status = HAL_UART_Receive(&uart1, buffer, RX_SIZE, 200);

        if (status == HAL_OK)
        {
            HAL_UART_Transmit(&uart1, buffer, RX_SIZE, 200);
        }
        else if (status == HAL_TIMEOUT)
        {
            if (uart1.RxXferCount != (RX_SIZE - 1))
            {
                HAL_UART_Transmit(&uart1, buffer, (RX_SIZE - 1 - uart1.RxXferCount), 200);
            }
        }
    }
}


