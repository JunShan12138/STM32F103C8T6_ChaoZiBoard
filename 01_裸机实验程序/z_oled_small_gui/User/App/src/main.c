
#include "bsp.h"
#include "small_gui.h"

// static uint8_t _number1;



int main(void)
{
    // GUI_BOOL ret;
    
    bsp_init();
    
    gui_init();

//    gui_draw_line(0, 0, MAX_X_POS, MAX_Y_POS, GUI_NORMAL);

    // gui_draw_rectangle(5, 5, 100, 50, GUI_FALSE, GUI_NORMAL);
    
    // gui_draw_triangle(5, 5, 30, 5, 10, 60, GUI_TRUE, GUI_NORMAL);

//    gui_draw_circle(30, 30, 20, GUI_TRUE, GUI_NORMAL);

//    gui_draw_ellipse(30, 30, 20, 10, GUI_TRUE, GUI_NORMAL);
    
    // gui_draw_arc(30, 30, 10, 60, 180, GUI_TRUE, GUI_NORMAL);

    // gui_show_font_string(20, 20, "english", GUI_FONT_8x16, GUI_NORMAL);

    gui_show_img(10, 10, 19, 15, &g_gui_img_15x19[0], GUI_NORMAL);

    gui_refresh();
    
    

    while (1)
    {
//        gui_refresh_menu();
    }
}


