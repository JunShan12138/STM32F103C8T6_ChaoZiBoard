
#include "bsp.h"
#include "small_gui.h"

// static uint8_t _number1;

int main(void)
{
    GUI_BOOL ret;
    
    bsp_init();
    
    gui_init();
    
    ret = gui_read_point(10, 10);

    gui_set_point(10, 10);

    gui_refresh();
    
    ret = gui_read_point(10, 10);
    
    gui_clear_point(10, 10);

    gui_refresh();
    
    ret = gui_read_point(10, 10);
    
    if (ret)
    {
        gui_refresh();
    }
    
    // OLED_ShowString(0,0,"风扇控制             ",OLED_8X16);
	// OLED_ShowString(0,16,"AD                  ",OLED_8X16);
	// OLED_ShowString(0,32,"摇杆数据            ",OLED_8X16);
	// OLED_ShowString(0,48,"MPU6050             ",OLED_8X16);
	// OLED_Update();

    while (1)
    {
        gui_refresh_menu();
    }
}


