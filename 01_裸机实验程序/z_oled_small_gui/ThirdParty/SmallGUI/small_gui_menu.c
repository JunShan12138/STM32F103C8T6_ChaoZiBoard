
#include "small_gui.h"
#include "bsp.h" 

menu_item_t _draw_point_menu_items[] = 
{
    {draw_point, NULL, "慢速", "", 0},
};

gui_menu_t _draw_point_menu = 
{
    (menu_item_t *)_draw_point_menu_items,
    GUI_ARR_SIZE(_draw_point_menu_items),
    NULL,
    0
};

menu_item_t _top_menu_items[] = 
{
    {NULL, &_draw_point_menu, "画点", "", 0},
};

menu_engine_t g_menu_engine;


fsm_rt_e draw_point(menu_item_t *item)
{

    return FSM_RT_ON_GOING;
}

void gui_refresh_menu(void)
{
    uint32_t i;
    uint32_t start_index = g_menu_engine.current_menu->current_item_index / 4;

    // 清空显存
    for (i = 0; i < 4; i++)
    {   
        /* 存在这个节点 */
        if ((start_index * 4 + i) < g_menu_engine.current_menu->count)
        {
            
        }
    }
}

