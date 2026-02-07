#ifndef __SMALL_GUI_MENU_H__
#define __SMALL_GUI_MENU_H__

#include "small_gui_type.h"

#define MENU_ARR_SIZE(__ARRAY)    ((sizeof(__ARRAY)) / (sizeof(__ARRAY[0])))

/* 有限状态机的各种状态 */
typedef enum
{
    FSM_RT_ERR          = -1,  /* 出错状态 */ 
    FSM_RT_COMPLETE     = 0,   /* 完成状态 */ 
    FSM_RT_ON_GOING     = 1,   /* 正在执行 */ 
    FSM_RT_WAIT_FOT_OBJ = 2,   /* 等待对象构建->暂停状态 */ 
    FSM_RT_ASYNC        = 3    /* 异步完成 */ 
}fsm_rt_e;

typedef struct __menu_item  menu_item_t;  /* 菜单节点类型 */ 
typedef struct __gui_menu   gui_menu_t;   /* GUI菜单总控制类型 */ 

/* 菜单节点函数指针类型 */ 
typedef fsm_rt_e (menu_item_handler_t)(menu_item_t *);


struct __menu_item
{
    menu_item_handler_t *item_handler;  /* 菜单节点执行函数 */ 

    gui_menu_t *child;  /* 下一个菜单 */ 

    GUI_INT8 *tile;  /* 菜单标题 */ 

    GUI_INT8 *description;  /* 菜单描述 */ 
    GUI_INT8 short_cut_key; /* 当前菜单节点的快捷键值 */ 
};

/* 菜单引擎回调函数 */
typedef struct __menu_engine    menu_engine_t;

/* 菜单引擎回调函数 */
typedef fsm_rt_e (menu_engine_handler_t)(menu_engine_t *);

struct __gui_menu
{
    menu_item_t *items;   /* 菜单节点列表 */
    GUI_UINT32  count;    /* 同一级菜单下的菜单量 */
    gui_menu_t  *parent;  /* 父级菜单 */

    /* 菜单引擎指定的处理函数 */
    menu_engine_handler_t *engine_handler;

    GUI_UINT32 current_item_index;  /* 当前菜单的当前指示是哪个数 */
};

struct __menu_engine
{
    GUI_UINT32 state;  /* 之前或者当前节点函数运行后的状态 */

    gui_menu_t *current_menu;  /* 当前菜单 */
};

extern menu_engine_t g_menu_engine;

fsm_rt_e draw_point(menu_item_t *item);

void gui_refresh_menu(void);

#endif


