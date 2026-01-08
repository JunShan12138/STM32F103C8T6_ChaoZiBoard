
#include "bsp.h"


int main(void)
{
    // uint8_t *buff;
    // uint32_t len;

    bsp_init();

   DEBUG_LOG("Hard init over\r\n");

   DEBUG_LOG("uart print test %d, %02X\r\n", 200, 0x8D);

    while (1)
    {
//        if (uart1_rx_data(&buff, &len))
//        {
//            uart1_tx_data(buff, len);
//        }

//        if (uart2_rx_data(&buff, &len))
//        {
//            uart2_tx_data(buff, len);
//        }

//        if (uart3_rx_data(&buff, &len))
//        {
//            uart3_tx_data(buff, len);
//        }

//        /* 处理要发送的数据 */
////        uart1_tx_process();
//        uart2_tx_process();
//        uart3_tx_process();
    }
}


