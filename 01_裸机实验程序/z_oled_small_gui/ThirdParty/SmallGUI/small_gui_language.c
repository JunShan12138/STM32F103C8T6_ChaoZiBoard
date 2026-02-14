
#include "small_gui.h"
 


void gui_show_img(GUI_INT32 x, GUI_INT32 y, 
                  GUI_INT32 hang, GUI_INT32 lie, 
                  const GUI_UINT8 *p, GUI_MODE type)
{
    // 计算每行所需的字节数（向上取整）
    GUI_INT32 bytes_per_row = (lie + 7) / 8;

    for (GUI_INT32 row = 0; row < hang; row++) 
    {
        for (GUI_INT32 col = 0; col < lie; col++) 
        {
            // 计算当前像素在字节数组中的位置
            GUI_INT32 byte_index = row * bytes_per_row + col / 8;
            GUI_UINT8 current_byte = p[byte_index];
            
            // 提取像素位（高位在前）
            GUI_UINT8 bit_mask = 0x80 >> (col % 8);  // 0x80 = 1000 0000
            
            if (current_byte & bit_mask) {
                // 阴码：1 表示点亮像素
                gui_set_point(x + col, y + row, type);
            } else {
                // 阴码：0 表示熄灭像素
                gui_clear_point(x + col, y + row, type);
            }
        }
    }
}


/***************************************************************************************************
 * @fn      gui_show_font_string
 *
 * @brief   显示一个英文字符
 *
 * @param   x 英文字符的横坐标地址
 * @param   y 英文字符的纵坐标地址
 * @param   c 英文字符
 * @param   font_size 字符的大小
 * @param   type 为GUI_NORMAL则是正常显示，为GUI_SPECIAL是反选显示
 *
 * @return  无
 */
void gui_show_font_string(GUI_INT32 x, GUI_INT32 y, 
                          GUI_CHAR *p, GUI_FONT_SIZE font_size,
                          GUI_MODE type)
{
    GUI_INT8 point;
//    GUI_INT8 not_find;
    GUI_INT32 i;
    GUI_INT32 j;
//    GUI_INT32 k;
    GUI_INT32 x_t = x;
    GUI_INT32 y_t = y;
    
    /* 字符串以'\0'结尾-->显示完字符串退出循环 */
    while (*p != '\0')
    {
        if ((*p >= 0x2) && (*p <= 0x7E))  /* 是ascii字符 */
        {
            if (GUI_FONT_8x16 == font_size)
            {
                /* 做换行操作 */
                if (x_t + 8 >= MAX_X_POS)
                {
                    y_t += 16;
                    x_t = 0;
                }
                
                /* 显示英文字符 */
                for (i = 0; i < 16; i++)
                {
                    for (j = 0; j < 8; j++)
                    {
                        point = ((g_gui_font_8x16_en[*p - ' '][i] >> ((7 - j) % 8)) & 0x01);

                        if (point)
                        {
                            gui_set_point((x_t + j), (y_t + i), type);
                        }
                        else
                        {
                            gui_clear_point((x_t + j), (y_t + i), type);
                        }
                    }
                }

                p++;
                x_t += 8;
            }
        }
        else if (*p > 0x80)  /* 是中文字符 */
        {
//            /* 做换行操作 */
//            if (x_t + 16 >= 160)
//            {
//                y_t -= 16;
//                x_t = 0;
//            }
//            
//            /* 遍历字库 */
//            not_find = 1;
//            for (k = 0; k < FONT_ARR_SIZE(g_Font_GB16); k++)
//            {
//                if ((g_Font_GB16[k].index[0] == p[0]) && (g_Font_GB16[k].index[1] == p[1]))
//                {
//                    not_find = 0;
//                    
//                    /* 显示中文字符 */
//                    for (i = 0; i < 16; i++)
//                    {
//                        for (j = 0; j < 16; j++)
//                        {
//                            gui_set_point((x_t + j), (y_t - i), ((g_Font_GB16[k].data[i * 2 + j / 8] >> (j % 8)) & 0x01), type);
//                        }
//                    }
//                }
//            }
//            
//            /* 没找到对应的字符 */
//            if (not_find)
//            {
//                /* 显示错误字符 */
//                for (i = 0; i < 16; i++)
//                {
//                    for (j = 0; j < 16; j++)
//                    {
//                        gui_set_point((x_t + j), (y_t - i), ((g_Font_GB16[0].data[i * 2 + j / 8] >> (j % 8)) & 0x01), color);
//                    }
//                }
//            }
//            
//            p += 2;
//            x_t += 16;
       }
    }
}
