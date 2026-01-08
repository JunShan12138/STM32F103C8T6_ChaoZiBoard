#ifndef __MB_CONFIG_H__
#define __MB_CONFIG_H__

#include <stdint.h>

// <<< Use Configuration Wizard in Context Menu >>>

// <h> 发送/接收缓冲区大小配置
// <o> 发送缓冲区大小 
#define MB_SEND_BUF_LEN             150  
// <o> 接收缓冲区大小 
#define MB_RECV_BUF_LEN             150   
// </h>

// <h> 功能码配置
// <c1> 启用，读保持寄存器功能 03H
//  <i>using read hold reg 03H
 #define MB_FUNC_READ_HOLD 
// </c>
// <c1> 启用，读输入寄存器功能 04H
//  <i>using read input reg 04H
 #define MB_FUNC_READ_INPUT      
// </c>
// </h>

// <h> 寄存器个数配置

#ifdef MB_FUNC_READ_HOLD
    // <o>  保持寄存器（03H）起始位置
    #define MB_HOLD_REG_START   0
    // <o>  保持寄存器（03H）总数量
    #define MB_HOLD_REG_SUM     32
#endif

#ifdef MB_FUNC_READ_INPUT
    // <o>  输入寄存器（04H）起始位置
    #define MB_INPUT_REG_START   0
    // <o>  输入寄存器（04H）总数量
    #define MB_INPUT_REG_SUM     32
#endif

// </h>

// <<< end of configuration section >>>

#endif /* __MB_CONFIG_H__ */ 
