/* RT-Thread config file */

#ifndef __RTTHREAD_CFG_H__
#define __RTTHREAD_CFG_H__

// <<< Use Configuration Wizard in Context Menu >>>

// <h> 基本配置
// <o> 线程优先级的最大级别 8-256
//  <i>Default: 32
#define RT_THREAD_PRIORITY_MAX  8   
// <o> 操作系统每秒滴答数
//  <i>Default: 1000   (1ms)
#define RT_TICK_PER_SECOND  1000
// <o> CPU架构数据访问的对齐大小
//  <i>Default: 4
#define RT_ALIGN_SIZE   4
// <o> 对象名称的最大程度 2-16 
//  <i>Default: 8
#define RT_NAME_MAX    16
// <c1> 使用RT-Thread组件初始化
//  <i>Using RT-Thread components initialization
//#define RT_USING_COMPONENTS_INIT
// </c>

#define RT_USING_USER_MAIN

// <o> 主线程的堆栈大小 1-4086
//  <i>Default: 512
#define RT_MAIN_THREAD_STACK_SIZE     512

// </h>

// <h> 调试配置
// <c1> 启用内核调试配置
//  <i>Default: enable kernel debug configuration
//#define RT_DEBUG
// </c>
// <o> 启用组件初始化调试配置 0-1 
//  <i>Default: 0
#define RT_DEBUG_INIT 0
// <c1> 线程堆栈溢出检测
//  <i> Diable Thread stack over flow detect
//#define RT_USING_OVERFLOW_CHECK
// </c>
// </h>

// <h> 钩子函数(hook)配置
// <c1> 使用钩子函数(hook)
//  <i>using hook
//#define RT_USING_HOOK
// </c>
// <c1> 使用空闲钩子函数(idle hook)
//  <i>using idle hook
//#define RT_USING_IDLE_HOOK
// </c>
// </h>

// <e> 软件定时器配置
// <i> Enables user timers
#define RT_USING_TIMER_SOFT         1
#if RT_USING_TIMER_SOFT == 0
    #undef RT_USING_TIMER_SOFT
#endif
// <o> 定时器线程的优先级 0-31
//  <i>Default: 4
#define RT_TIMER_THREAD_PRIO        4
// <o> 定时器线程的堆栈大小 0-8192 
//  <i>Default: 512
#define RT_TIMER_THREAD_STACK_SIZE  512
// </e>

// <h>IPC(线程间通信)配置
// <c1> 使用信号量 Semaphore 
//  <i>Using Semaphore
#define RT_USING_SEMAPHORE
// </c>
// <c1> 使用互斥量 Mutex
//  <i>Using Mutex
#define RT_USING_MUTEX
// </c>
// <c1> 使用事件 Event
//  <i>Using Event
#define RT_USING_EVENT
// </c>
// <c1> 使用邮箱 MailBox
//  <i>Using MailBox
#define RT_USING_MAILBOX
// </c>
// <c1> 使用消息队列 Message Queue
//  <i>Using Message Queue
#define RT_USING_MESSAGEQUEUE
// </c>
// </h>

// <h> 内存管理配置
// <c1> 使用动态内存堆 Dynamic Heap Management
//  <i>Please modify RT_HEAP_SIZE if RT_USING_HEAP is enabled 
#define RT_USING_HEAP
// </c>
// <c1> 使用小内存 small memory
//  <i>using small memory
#define RT_USING_SMALL_MEM
// </c>
// <c1> 使用极小内存 tiny size of memory
//  <i>using tiny size of memory
//#define RT_USING_TINY_SIZE
// </c>
// </h>

// <h> 控制台配置 console
// <c1> 使用控制台 console
//  <i>Using console
#define RT_USING_CONSOLE
// </c>

// <o> 控制台缓冲区大小 1-1024
//  <i>the buffer size of console
//  <i>Default: 128  (128Byte)
#define RT_CONSOLEBUF_SIZE          256
// </h>

// <h>FinSH 组件配置
// <c1> 使用Fnish组件
//  <i>Select this choice if you using FinSH 
//#include "finsh_config.h"
// </c>
// </h>

// <h>Device 设备驱动配置
// <c1> 使用 device 设备驱动
//  <i>using device framework
//#define RT_USING_DEVICE
// </c>
// </h>


// <<< end of configuration section >>>

#endif
