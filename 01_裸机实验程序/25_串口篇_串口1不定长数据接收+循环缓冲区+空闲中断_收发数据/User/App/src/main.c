
#include "bsp.h"


int main(void)
{
    uint8_t *buff;
    uint32_t len;

    bsp_init();

    while (1)
    {
        if (uart1_rx_data(&buff, &len))
        {
            uart1_tx_data(buff, len);
        }

        /* 处理要发送的数据 */
        uart1_tx_process();
    }
}


