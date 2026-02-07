
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
 * @param   无
 *
 * @return  无 
 */
void gui_set_point(GUI_INT32 x, GUI_INT32 y)
{
    // 这里要加上底层实现点亮一个点位
    OLED_DrawPoint(x, y);
}

/***************************************************************************************************
 * @fn      gui_clear_point
 *
 * @brief   底层接口，清除一个点
 *
 * @param   无
 *
 * @return  无 
 */
void gui_clear_point(GUI_INT32 x, GUI_INT32 y)
{
    // 这里要加上底层读点位
    OLED_ClearPoint(x, y);
}

/***************************************************************************************************
 * @fn      gui_read_point
 *
 * @brief   底层接口，读取一个点的状态
 *
 * @param   无
 *
 * @return  GUI_TRUE 这个点是亮的， GUI_FALSE 这个点是灭的
 */
GUI_BOOL gui_read_point(GUI_INT32 x, GUI_INT32 y)
{
    // 这里要加上底层实现
    if (OLED_GetPoint(x, y)) 
    {
        return GUI_TRUE;    
    }

    return GUI_FALSE;
}

/***************************************************************************************************
 * @fn      gui_refresh
 *
 * @brief   刷新屏幕
 *
 * @param   无
 *
 * @return  无
 */
void gui_refresh(void)
{
    OLED_Update();
}
