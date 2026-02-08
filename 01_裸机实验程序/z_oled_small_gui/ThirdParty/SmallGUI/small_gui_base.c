
#include "small_gui.h"
#include "bsp.h"


/***************************************************************************************************
 * @fn      gui_init
 *
 * @brief   底层接口，屏幕的初始化
 *
 * @param   无
 *
 * @return  无 
 */
void gui_init(void)
{
    OLED_Init();
}

/***************************************************************************************************
 * @fn      gui_set_point
 *
 * @brief   底层接口，设置一个点
 *
 * @param   x 画点的横坐标地址
 * @param   y 画点的纵坐标地址
 * @param   type 为GUI_NORMAL则是正常，为GUI_SPECIAL是反选显示
 *
 * @return  无 
 */
void gui_set_point(GUI_INT32 x, GUI_INT32 y, GUI_MODE type)
{
    if (type)
    {
        OLED_DrawPoint(x, y);
    }
    else
    {
        OLED_ClearPoint(x, y);
    }
}

/***************************************************************************************************
 * @fn      gui_clear_point
 *
 * @brief   底层接口，清除一个点
 *
 * @param   x 清除点横的坐标地址
 * @param   y 清除点纵的坐标地址
 * @param   type 为GUI_NORMAL则是正常，为GUI_SPECIAL是反选显示
 *
 * @return  无 
 */
void gui_clear_point(GUI_INT32 x, GUI_INT32 y, GUI_MODE type)
{
    if (type)
    {
        OLED_ClearPoint(x, y);
    }
    else
    {
        OLED_DrawPoint(x, y);
    }
}

/***************************************************************************************************
 * @fn      gui_read_point
 *
 * @brief   底层接口，读取一个点的状态
 *
 * @param   x 读取固定点的横坐标地址
 * @param   y 读取固定点的纵坐标地址
 * @param   type 为GUI_NORMAL则是读正常显示的状态，为GUI_SPECIAL是反选显示的状态
 *
 * @return  GUI_TRUE 这个点是亮的， GUI_FALSE 这个点是灭的
 */
GUI_BOOL gui_read_point(GUI_INT32 x, GUI_INT32 y, GUI_MODE type)
{
    if (type)
    {
        if (OLED_GetPoint(x, y)) 
        {
            return GUI_TRUE;    
        }
        else
        {
            return GUI_FALSE;
        }
    }
    else
    {
        if (OLED_GetPoint(x, y)) 
        {
            return GUI_FALSE;    
        }
        else
        {
            return GUI_TRUE;
        }
    }
}

/***************************************************************************************************
 * @fn      gui_refresh
 *
 * @brief   底层接口，刷新屏幕
 *
 * @param   无
 *
 * @return  无
 */
void gui_refresh(void)
{
    OLED_Update();
}

/***************************************************************************************************
 * @fn      gui_clear_all
 *
 * @brief   底层接口，清屏
 *
 * @param   无
 *
 * @return  无
 */
void gui_clear_all(GUI_MODE type)
{
    if (type)
    {
        OLED_Clear();
    }
    else
    {
        OLED_Set();
    }
}

/***************************************************************************************************
 * @fn      gui_clear_area
 *
 * @brief   底层接口，清除一个区域
 *
 * @param   x 清除区域起始地址的横坐标地址
 * @param   y 清除区域起始地址的纵坐标地址
 * @param   width 此区域的宽度
 * @param   height 此区域的高度
 * @param   type 为GUI_NORMAL则是读正常显示的状态，为GUI_SPECIAL是反选显示的状态
 *
 * @return  无
 */
void gui_clear_area(GUI_INT32 x, GUI_INT32 y, GUI_INT32 width, GUI_INT32 height, GUI_MODE type)
{
    if (type)
    {
        OLED_ClearArea(x, y, width, height);
    }
    else
    {
        OLED_SetArea(x, y, width, height);
    }    
}
