
#include "small_gui.h"


/***************************************************************************************************
 * @fn      gui_draw_line
 *
 * @brief   绘制线段
 *
 * @param   s_x 起始的横坐标地址
 * @param   s_y 起始的纵坐标地址
 * @param   e_x 结束的横坐标地址
 * @param   e_y 结束的纵坐标地址
 * @param   type 为GUI_NORMAL则是正常显示，为GUI_SPECIAL是反选显示
 *
 * @return  无
 */
void gui_draw_line(GUI_INT32 s_x, GUI_INT32 s_y, GUI_INT32 e_x, GUI_INT32 e_y, GUI_MODE type)
{
    GUI_INT32 x, y, dx, dy, d, incr_e, incr_ne, temp;
    GUI_INT32 x0 = s_x, y0 = s_y, x1 = e_x, y1 = e_y;
    GUI_UINT8 yflag = 0, xyflag = 0;
    
    if (y0 == y1)  /* 横线单独处理 */
    {
        /* 0号点X坐标大于1号点X坐标，则交换两点X坐标 */
        if (x0 > x1) 
        {   
            temp = x0; 
            x0 = x1; 
            x1 = temp;
        }
        
        /* 遍历X坐标 */
        for (x = x0; x <= x1; x ++)
        {
            gui_set_point(x, y0, type);  /* 依次画点 */
        }
    }
    else if (x0 == x1)  /* 竖线单独处理 */
    {
        /* 0号点Y坐标大于1号点Y坐标，则交换两点Y坐标 */
        if (y0 > y1) 
        {
            temp = y0; 
            y0 = y1; 
            y1 = temp;
        }
        
        /*遍历Y坐标*/
        for (y = y0; y <= y1; y ++)
        {
            gui_set_point(x0, y, type);  /* 依次画点 */
        }
    }
    else  /* 斜线 */
    {
        /* 使用Bresenham算法画直线，可以避免耗时的浮点运算，效率更高 */
        /* 参考文档：https://www.cs.montana.edu/courses/spring2009/425/dslectures/Bresenham.pdf */
        /* 参考教程：https://www.bilibili.com/video/BV1364y1d7Lo */

        if (x0 > x1)  /* 0号点X坐标大于1号点X坐标 */
        {
            /* 交换两点坐标 */
            /* 交换后不影响画线，但是画线方向由第一、二、三、四象限变为第一、四象限 */
            temp = x0; 
            x0 = x1; 
            x1 = temp;

            temp = y0; 
            y0 = y1; 
            y1 = temp;
        }
        
        if (y0 > y1)  /* 0号点Y坐标大于1号点Y坐标 */
        {
            /* 将Y坐标取负 */
            /* 取负后影响画线，但是画线方向由第一、四象限变为第一象限 */
            y0 = -y0;
            y1 = -y1;
            
            /* 置标志位yflag，记住当前变换，在后续实际画线时，再将坐标换回来 */
            yflag = 1;
        }
        
        if (y1 - y0 > x1 - x0)  /* 画线斜率大于1 */
        {
            /* 将X坐标与Y坐标互换 */
            /* 互换后影响画线，但是画线方向由第一象限0~90度范围变为第一象限0~45度范围 */
            temp = x0; 
            x0 = y0; 
            y0 = temp;

            temp = x1; 
            x1 = y1; 
            y1 = temp;
            
            /* 置标志位xyflag，记住当前变换，在后续实际画线时，再将坐标换回来 */
            xyflag = 1;
        }
        
        /* 以下为Bresenham算法画直线 */
        /* 算法要求，画线方向必须为第一象限0~45度范围 */
        dx = x1 - x0;
        dy = y1 - y0;
        incr_e = 2 * dy;
        incr_ne = 2 * (dy - dx);
        d = 2 * dy - dx;
        x = x0;
        y = y0;
        
        /* 画起始点，同时判断标志位，将坐标换回来 */
        if (yflag && xyflag)
        {
            gui_set_point(y, -x, type);
        }
        else if (yflag)
        {
            gui_set_point(x, -y, type);
        }
        else if (xyflag)
        {
            gui_set_point(y, x, type);
        }
        else
        {
            gui_set_point(x, y, type);
        }
        
        while (x < x1)  /* 遍历X轴的每个点 */
        {
            x ++;
            if (d < 0)  /* 下一个点在当前点东方 */
            {
                d += incr_e;
            }
            else  /* 下一个点在当前点东北方 */
            {
                y ++;
                d += incr_ne;
            }
            
            /* 画每一个点，同时判断标志位，将坐标换回来 */
            if (yflag && xyflag)
            {
                gui_set_point(y, -x, type);
            } 
            else if (yflag)		
            {
                gui_set_point(x, -y, type);
            }
            else if (xyflag)	
            {
                gui_set_point(y, x, type);
            }
            else				
            {
                gui_set_point(x, y, type);
            }
        }
    }
}

/***************************************************************************************************
 * @fn      gui_draw_rectangle
 *
 * @brief   绘制矩形
 *
 * @param   x 矩形起始的横坐标地址
 * @param   y 矩形起始的纵坐标地址
 * @param   width 矩形的宽
 * @param   heigth 矩形的高
 * @param   is_fill 需要填充则GUI_TRUE，不需要填充则GUI_FALSE
 * @param   type 为GUI_NORMAL则是正常显示，为GUI_SPECIAL是反选显示
 *
 * @return  无
 */
void gui_draw_rectangle(GUI_INT32 x, GUI_INT32 y, 
                        GUI_INT32 width, GUI_INT32 heigth, 
                        GUI_BOOL is_fill, GUI_MODE type)
{
    GUI_INT32 i, j;
    
    if (is_fill == GUI_FALSE)  /* 指定矩形不填充 */
    {
        /* 遍历上下X坐标，画矩形上下两条线 */
        for (i = x; i < x + width; i ++)
        {
            gui_set_point(i, y, type);
            gui_set_point(i, (y + heigth - 1), type);
        }
        /*遍历左右Y坐标，画矩形左右两条线*/
        for (i = y; i < y + heigth; i ++)
        {
            gui_set_point(x, i, type);
            gui_set_point((x + width - 1), i, type);
        }
    }
    else  /* 指定矩形填充 */
    {
        /* 遍历X坐标 */
        for (i = x; i < x + width; i ++)
        {
            /* 遍历Y坐标 */
            for (j = y; j < y + heigth; j ++)
            {
                /* 在指定区域画点，填充满矩形 */
                gui_set_point(i, j, type);
            }
        }
    }
}

/**
 * 函    数：判断指定点是否在指定多边形内部
 * 参    数：nvert 多边形的顶点数
 * 参    数：vertx verty 包含多边形顶点的x和y坐标的数组
 * 参    数：testx testy 测试点的X和y坐标
 * 返 回 值：指定点是否在指定多边形内部，1：在内部，0：不在内部
 */
uint8_t gui_pnpoly(uint8_t nvert, GUI_INT32 *vertx, GUI_INT32 *verty, GUI_INT32 testx, GUI_INT32 testy)
{
    GUI_INT32 i, j, c = 0;
    
    /*此算法由W. Randolph Franklin提出*/
    /*参考链接：https://wrfranklin.org/Research/Short_Notes/pnpoly.html*/
    for (i = 0, j = nvert - 1; i < nvert; j = i++)
    {
        if (((verty[i] > testy) != (verty[j] > testy)) &&
            (testx < (vertx[j] - vertx[i]) * (testy - verty[i]) / (verty[j] - verty[i]) + vertx[i]))
        {
            c = !c;
        }
    }
    return c;
}

/***************************************************************************************************
 * @fn      gui_draw_triangle
 *
 * @brief   绘制三角形
 *
 * @param   x0 三角形形第一个端点的横坐标地址
 * @param   y0 三角形形第一个端点的纵坐标地址
 * @param   x1 三角形形第二个端点的横坐标地址
 * @param   y1 三角形形第二个端点的纵坐标地址
 * @param   x2 三角形形第三个端点的横坐标地址
 * @param   y2 三角形形第三个端点的纵坐标地址
 * @param   is_fill 需要填充则GUI_TRUE，不需要填充则GUI_FALSE
 * @param   type 为GUI_NORMAL则是正常显示，为GUI_SPECIAL是反选显示
 *
 * @return  无
 */
void gui_draw_triangle(GUI_INT32 x0, GUI_INT32 y0, 
                    GUI_INT32 x1, GUI_INT32 y1, 
                    GUI_INT32 x2, GUI_INT32 y2, 
                    GUI_BOOL is_fill, GUI_MODE type)
{
    GUI_INT32 minx = x0, miny = y0, maxx = x0, maxy = y0;
    GUI_INT32 i, j;
    GUI_INT32 vx[] = {x0, x1, x2};
    GUI_INT32 vy[] = {y0, y1, y2};
    
    if (is_fill == GUI_FALSE)  /* 指定三角形不填充 */
    {
        /*调用画线函数，将三个点用直线连接*/
        gui_draw_line(x0, y0, x1, y1, type);
        gui_draw_line(x0, y0, x2, y2, type);
        gui_draw_line(x1, y1, x2, y2, type);
    }
    else  /* 指定三角形填充 */
    {
        /*找到三个点最小的X、Y坐标*/
        if (x1 < minx) { minx = x1; }
        if (x2 < minx) { minx = x2; }
        if (y1 < miny) { miny = y1; }
        if (y2 < miny) { miny = y2; }
        
        /*找到三个点最大的X、Y坐标*/
        if (x1 > maxx) { maxx = x1; }
        if (x2 > maxx) { maxx = x2; }
        if (y1 > maxy) { maxy = y1; }
        if (y2 > maxy) { maxy = y2; }
        
        /* 最小最大坐标之间的矩形为可能需要填充的区域 */
        /* 遍历此区域中所有的点 */
        /* 遍历X坐标 */		
        for (i = minx; i <= maxx; i ++)
        {
            /*遍历Y坐标*/	
            for (j = miny; j <= maxy; j ++)
            {
                /* 调用gui_pnpoly，判断指定点是否在指定三角形之中 */
                /* 如果在，则画点，如果不在，则不做处理 */
                if (gui_pnpoly(3, vx, vy, i, j)) 
                {
                    gui_set_point(i, j, type);
                }
            }
        }
    }
}

/***************************************************************************************************
 * @fn      gui_draw_circle
 *
 * @brief   绘制圆形
 *
 * @param   x 圆心的横坐标地址
 * @param   y 圆心的纵坐标地址
 * @param   radius 圆的半径
 * @param   is_fill 需要填充则GUI_TRUE，不需要填充则GUI_FALSE
 * @param   type 为GUI_NORMAL则是正常显示，为GUI_SPECIAL是反选显示
 *
 * @return  无
 */
void gui_draw_circle(GUI_INT32 x, GUI_INT32 y, 
                    GUI_INT32 radius, GUI_BOOL is_fill, GUI_MODE type)
{
    GUI_INT32 x_t, y_t, d, j;
    
    /* 使用Bresenham算法画圆，可以避免耗时的浮点运算，效率更高 */
    /* 参考文档：https://www.cs.montana.edu/courses/spring2009/425/dslectures/Bresenham.pdf */
    /* 参考教程：https://www.bilibili.com/video/BV1VM4y1u7wJ */
    d = 1 - radius;
    x_t = 0;
    y_t = radius;
    
    /* 画每个八分之一圆弧的起始点 */
    gui_set_point((x + x_t), (y + y_t), type);
    gui_set_point((x - x_t), (y - y_t), type);
    gui_set_point((x + y_t), (y + x_t), type);
    gui_set_point((x - y_t), (y - x_t), type);
    
    if (is_fill == GUI_TRUE)  /* 指定圆填充 */
    {
        /* 遍历起始点Y坐标 */
        for (j = -y_t; j < y_t; j ++)
        {
            /* 在指定区域画点，填充部分圆 */
            gui_set_point(x, (y + j), type);
        }
    }
    
    while (x_t < y_t)  /* 遍历X轴的每个点 */
    {
        x_t ++;
        if (d < 0)  /* 下一个点在当前点东方 */
        {
            d += 2 * x_t + 1;
        }
        else  /* 下一个点在当前点东南方 */
        {
            y_t --;
            d += 2 * (x_t - y_t) + 1;
        }
        
        /* 画每个八分之一圆弧的点 */
        gui_set_point((x + x_t), (y + y_t), type);
        gui_set_point((x + y_t), (y + x_t), type);
        gui_set_point((x - x_t), (y - y_t), type);
        gui_set_point((x - y_t), (y - x_t), type);
        gui_set_point((x + x_t), (y - y_t), type);
        gui_set_point((x + y_t), (y - x_t), type);
        gui_set_point((x - x_t), (y + y_t), type);
        gui_set_point((x - y_t), (y + x_t), type);
        
        if (is_fill == GUI_TRUE)  /* 指定圆填充 */
        {
            /* 遍历中间部分 */
            for (j = -y_t; j < y_t; j ++)
            {
                /* 在指定区域画点，填充部分圆 */
                gui_set_point((x + x_t), (y + j), type);
                gui_set_point((x - x_t), (y + j), type);
            }
            
            /* 遍历两侧部分 */
            for (j = -x_t; j < x_t; j ++)
            {
                /* 在指定区域画点，填充部分圆 */
                gui_set_point((x - y_t), (y + j), type);
                gui_set_point((x + y_t), (y + j), type);
            }
        }
    }
}

/***************************************************************************************************
 * @fn      gui_draw_ellipse
 *
 * @brief   绘制椭圆形
 *
 * @param   x 圆心的横坐标地址
 * @param   y 圆心的纵坐标地址
 * @param   a 椭圆的横向半轴长度
 * @param   b 椭圆的纵向半轴长度
 * @param   is_fill 需要填充则GUI_TRUE，不需要填充则GUI_FALSE
 * @param   type 为GUI_NORMAL则是正常显示，为GUI_SPECIAL是反选显示
 *
 * @return  无
 */
void gui_draw_ellipse(GUI_INT32 x, GUI_INT32 y, 
                    GUI_INT32 a, GUI_INT32 b, 
                    GUI_BOOL is_fill, GUI_MODE type)
{
    GUI_INT32 x_t, y_t, j;
    GUI_INT32 a_t = a, b_t = b;
    float d1, d2;
    
    /* 使用Bresenham算法画椭圆，可以避免部分耗时的浮点运算，效率更高 */
    /* 参考链接：https://blog.csdn.net/myf_666/article/details/128167392 */
    
    x_t = 0;
    y_t = b_t;
    d1 = b_t * b_t + a_t * a_t * (-b_t + 0.5);
    
    if (is_fill == GUI_TRUE)  /* 指定椭圆填充 */
    {
        /* 遍历起始点Y坐标 */
        for (j = -y_t; j < y_t; j ++)
        {
            /* 在指定区域画点，填充部分椭圆 */
            gui_set_point(x, y + j, type);
            gui_set_point(x, y + j, type);
        }
    }
    
    /* 画椭圆弧的起始点 */
    gui_set_point(x + x_t, y + y_t, type);
    gui_set_point(x - x_t, y - y_t, type);
    gui_set_point(x - x_t, y + y_t, type);
    gui_set_point(x + x_t, y - y_t, type);
    
    /* 画椭圆中间部分 */
    while (b_t * b_t * (x_t + 1) < a_t * a_t * (y_t - 0.5))
    {
        if (d1 <= 0)  /* 下一个点在当前点东方 */
        {
            d1 += b_t * b_t * (2 * x_t + 3);
        }
        else  /* 下一个点在当前点东南方 */
        {
            d1 += b_t * b_t * (2 * x_t + 3) + a_t * a_t * (-2 * y_t + 2);
            y_t --;
        }
        x_t ++;
        
        if (is_fill == GUI_TRUE)  /* 指定椭圆填充 */
        {
            /* 遍历中间部分 */
            for (j = -y_t; j < y_t; j ++)
            {
                /* 在指定区域画点，填充部分椭圆 */
                gui_set_point(x + x_t, y + j, type);
                gui_set_point(x - x_t, y + j, type);
            }
        }
        
        /* 画椭圆中间部分圆弧 */
        gui_set_point(x + x_t, y + y_t, type);
        gui_set_point(x - x_t, y - y_t, type);
        gui_set_point(x - x_t, y + y_t, type);
        gui_set_point(x + x_t, y - y_t, type);
    }
    
    /* 画椭圆两侧部分 */
    d2 = b_t * b_t * (x_t + 0.5) * (x_t + 0.5) + 
        a_t * a_t * (y_t - 1) * (y_t - 1) - a_t * a_t * b_t * b_t;
    
    while (y_t > 0)
    {
        if (d2 <= 0)  /* 下一个点在当前点东方 */
        {
            d2 += b_t * b_t * (2 * x_t + 2) + a_t * a_t * (-2 * y_t + 3);
            x_t ++;
        }
        else  /* 下一个点在当前点东南方 */
        {
            d2 += a_t * a_t * (-2 * y_t + 3);
        }
        y_t --;
        
        if (is_fill)  /* 指定椭圆填充 */
        {
            /* 遍历两侧部分 */
            for (j = -y_t; j < y_t; j ++)
            {
                /* 在指定区域画点，填充部分椭圆 */
                gui_set_point(x + x_t, y + j, type);
                gui_set_point(x - x_t, y + j, type);
            }
        }
        
        /* 画椭圆两侧部分圆弧 */
        gui_set_point(x + x_t, y + y_t, type);
        gui_set_point(x - x_t, y - y_t, type);
        gui_set_point(x - x_t, y + y_t, type);
        gui_set_point(x + x_t, y - y_t, type);
    }
}

/**
 * 函    数：判断指定点是否在指定角度内部
 * 参    数：X Y 指定点的坐标
 * 参    数：start_angle end_angle 起始角度和终止角度，范围：-180~180
 *           水平向右为0度，水平向左为180度或-180度，下方为正数，上方为负数，顺时针旋转
 * 返 回 值：指定点是否在指定角度内部，1：在内部，0：不在内部
 */
GUI_BOOL gui_is_in_angle(GUI_INT32 X, GUI_INT32 Y, GUI_INT32 start_angle, GUI_INT32 end_angle)
{
    GUI_INT32 point_angle;

    /* 计算指定点的弧度，并转换为角度表示 */
    point_angle = atan2(Y, X) / 3.14 * 180;	

    if (start_angle < end_angle)  /* 起始角度小于终止角度的情况 */
    {
        /* 如果指定角度在起始终止角度之间，则判定指定点在指定角度 */
        if (point_angle >= start_angle && point_angle <= end_angle)
        {
            return GUI_TRUE;
        }
    }
    else  /* 起始角度大于于终止角度的情况 */
    {
        /* 如果指定角度大于起始角度或者小于终止角度，则判定指定点在指定角度 */
        if (point_angle >= start_angle || point_angle <= end_angle)
        {
            return GUI_TRUE;
        }
    }

    /* 不满足以上条件，则判断判定指定点不在指定角度 */
    return GUI_FALSE;  
}

/**
 * 函    数：OLED画圆弧
 * 参    数：X 指定圆弧的圆心横坐标，范围：-32768~32767，屏幕区域：0~127
 * 参    数：Y 指定圆弧的圆心纵坐标，范围：-32768~32767，屏幕区域：0~63
 * 参    数：Radius 指定圆弧的半径，范围：0~255
 * 参    数：StartAngle 指定圆弧的起始角度，范围：-180~180
 *           水平向右为0度，水平向左为180度或-180度，下方为正数，上方为负数，顺时针旋转
 * 参    数：EndAngle 指定圆弧的终止角度，范围：-180~180
 *           水平向右为0度，水平向左为180度或-180度，下方为正数，上方为负数，顺时针旋转
 * 参    数：IsFilled 指定圆弧是否填充，填充后为扇形
 *           范围：OLED_UNFILLED		不填充
 *                 OLED_FILLED			填充
 * 返 回 值：无
 * 说    明：调用此函数后，要想真正地呈现在屏幕上，还需调用更新函数
 */

/***************************************************************************************************
 * @fn      gui_draw_arc
 *
 * @brief   绘制圆弧形
 *
 * @param   x 圆弧圆心的横坐标地址
 * @param   y 圆弧圆心的纵坐标地址
 * @param   radius 圆弧的横向半轴长度
 * @param   start_angle 指定圆弧的起始角度，范围：-180~180 
 *                      水平向右为0度，水平向左为180度或-180度，下方为正数，上方为负数，顺时针旋转
 * @param   end_angle   指定圆弧的终止角度，范围：-180~180
 *                      水平向右为0度，水平向左为180度或-180度，下方为正数，上方为负数，顺时针旋转
 * @param   is_fill 需要填充则GUI_TRUE，不需要填充则GUI_FALSE
 * @param   type 为GUI_NORMAL则是正常显示，为GUI_SPECIAL是反选显示
 *
 * @return  无
 */
void gui_draw_arc(GUI_INT32 x, GUI_INT32 y, 
                GUI_INT32 radius, GUI_INT32 start_angle,
                GUI_INT32 end_angle,  GUI_BOOL is_fill, GUI_MODE type)
{
    int16_t x_t, y_t, d, j;
    
    /* 此函数借用Bresenham算法画圆的方法 */
    
    d = 1 - radius;
    x_t = 0;
    y_t = radius;
    
    /* 在画圆的每个点时，判断指定点是否在指定角度内，在，则画点，不在，则不做处理 */
    if (gui_is_in_angle(x_t, y_t, start_angle, end_angle))	
    {
        gui_set_point(x + x_t, y + y_t, type);
    }
    if (gui_is_in_angle(-x_t, -y_t, start_angle, end_angle)) 
    {
        gui_set_point(x - x_t, y - y_t, type);
    }
    if (gui_is_in_angle(y_t, x_t, start_angle, end_angle)) 
    {
        gui_set_point(x + y_t, y + x_t, type);
    }
    if (gui_is_in_angle(-y_t, -x_t, start_angle, end_angle)) 
    {
        gui_set_point(x - y_t, y - x_t, type);
    }
    
    if (is_fill == GUI_TRUE)  /* 指定圆弧填充 */
    {
        /* 遍历起始点Y坐标 */
        for (j = -y_t; j < y_t; j ++)
        {
            /* 在填充圆的每个点时，判断指定点是否在指定角度内，在，则画点，不在，则不做处理 */
            if (gui_is_in_angle(0, j, start_angle, end_angle)) 
            {
                gui_set_point(x, y + j, type);
            }
        }
    }
    
    while (x_t < y_t)  /* 遍历X轴的每个点 */
    {
        x_t ++;
        if (d < 0)  /* 下一个点在当前点东方 */
        {
            d += 2 * x_t + 1;
        }
        else  /* 下一个点在当前点东南方 */
        {
            y_t --;
            d += 2 * (x_t - y_t) + 1;
        }
        
        /* 在画圆的每个点时，判断指定点是否在指定角度内，在，则画点，不在，则不做处理 */
        if (gui_is_in_angle(x_t, y_t, start_angle, end_angle)) 
        {
            gui_set_point(x + x_t, y + y_t, type);
        }
        if (gui_is_in_angle(y_t, x_t, start_angle, end_angle)) 
        {
            gui_set_point(x + y_t, y + x_t, type);
        }
        if (gui_is_in_angle(-x_t, -y_t, start_angle, end_angle)) 
        {
            gui_set_point(x - x_t, y - y_t, type);
        }
        if (gui_is_in_angle(-y_t, -x_t, start_angle, end_angle)) 
        {
            gui_set_point(x - y_t, y - x_t, type);
        }
        if (gui_is_in_angle(x_t, -y_t, start_angle, end_angle)) 
        {
            gui_set_point(x + x_t, y - y_t, type);
        }
        if (gui_is_in_angle(y_t, -x_t, start_angle, end_angle)) 
        {
            gui_set_point(x + y_t, y - x_t, type);
        }
        if (gui_is_in_angle(-x_t, y_t, start_angle, end_angle)) 
        {
            gui_set_point(x - x_t, y + y_t, type);
        }
        if (gui_is_in_angle(-y_t, x_t, start_angle, end_angle)) 
        {
            gui_set_point(x - y_t, y + x_t, type);
        }
        
        if (is_fill == GUI_TRUE)  /* 指定圆弧填充 */
        {
            /* 遍历中间部分 */
            for (j = -y_t; j < y_t; j ++)
            {
                /* 在填充圆的每个点时，判断指定点是否在指定角度内，在，则画点，不在，则不做处理 */
                if (gui_is_in_angle(x_t, j, start_angle, end_angle)) 
                {
                    gui_set_point(x + x_t, y + j, type);
                }
                if (gui_is_in_angle(-x_t, j, start_angle, end_angle)) 
                {
                    gui_set_point(x - x_t, y + j, type);
                }
            }
            
            /* 遍历两侧部分 */
            for (j = -x_t; j < x_t; j ++)
            {
                /* 在填充圆的每个点时，判断指定点是否在指定角度内，在，则画点，不在，则不做处理 */
                if (gui_is_in_angle(-y_t, j, start_angle, end_angle)) 
                {
                    gui_set_point(x - y_t, y + j, type);
                }
                if (gui_is_in_angle(y_t, j, start_angle, end_angle)) 
                {
                    gui_set_point(x + y_t, y + j, type);
                }
            }
        }
    }
}
