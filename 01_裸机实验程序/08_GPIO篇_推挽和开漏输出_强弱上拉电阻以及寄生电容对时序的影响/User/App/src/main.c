
#include "bsp.h"



int main(void)
{
    bsp_init();

    while (1)
    {
        bsp_led_toggle();

        bsp_delay_ms(500);
    }
}


