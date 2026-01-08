
#include "bsp.h"



int main(void)
{
    
    bsp_init();

    while (1)
    {
        if (g_uart1_rx_state == 1)
        {
            g_uart1_rx_state = 0;

            HAL_UART_Transmit_IT(&uart1, g_uart1_tx_buff, UART1_BUFF_SIZE);
        }
    }
}


