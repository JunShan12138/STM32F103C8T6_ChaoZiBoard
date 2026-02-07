#include "mb_func_hold.h"

#ifdef MB_FUNC_READ_HOLD

/* 输入寄存器 */
uint16_t g_mb_hold_reg[MB_HOLD_REG_SUM];

/***************************************************************************************************
 * @fn      mb_read_hold_reg
 *
 * @brief   功能码03H 读保持寄存器
 *
 * @param   recv 接收到的数据
 * @param   buf_len 收到的字节个数
 *
 * @return  无
 */
mb_resp_e mb_read_hold_reg(uint8_t *recv, uint8_t buf_len)
{
    uint16_t i, reg_index;
    uint16_t reg_start;
    uint16_t reg_sum;
    uint16_t tx_cnt = 0;
    uint8_t  *tx_buf = &g_mb_send_buf[0];

    /* 收到的数据必须是8字节 */
    if (8 != buf_len)
    {
        return MB_RESP_ERR_VALUE;
    }

    reg_start = big_endian_to_uint16(&recv[2]);  /* 寄存器编号 */
    reg_sum   = big_endian_to_uint16(&recv[4]);  /* 寄存器个数 */
    
    /* 寄存器个数 + 报头 + CRC不能超过发送缓冲区大小 */
    if (((reg_sum * 2) + 5) > MB_SEND_BUF_LEN)
    {
        return MB_RESP_ERR_VALUE;
    }

#if MB_HOLD_REG_START == 0
    if ((reg_start + reg_sum) > (MB_HOLD_REG_START + MB_HOLD_REG_SUM))
#else
    if ((reg_start < MB_HOLD_REG_START) || 
        ((reg_start + reg_sum) > (MB_HOLD_REG_START + MB_HOLD_REG_SUM)))
#endif
    {
        return MB_RESP_ERR_REG_ADDR;
    }

    /* 准备发送数据 */
    tx_buf[tx_cnt++] = recv[MB_LOCAL_ADDR_INDEX];  /* 本机地址 */
    tx_buf[tx_cnt++] = recv[MB_FUNC_CODE_INDEX];  /* 功能码 */

    /* 数据个数 */
    tx_buf[tx_cnt++] = reg_sum * 2;

    /* 数据域 */
    reg_index = reg_start;
    for (i = 0; i < reg_sum; i++)
    {
        tx_buf[tx_cnt++] = (uint8_t)(g_mb_hold_reg[reg_index] >> 8);
        tx_buf[tx_cnt++] = (uint8_t)(g_mb_hold_reg[reg_index] & 0xFF);
        reg_index++;
    }

    /* 计算校验并发送数据 */
    return mb_send_with_crc(tx_buf, tx_cnt);
}

#endif  /* MB_FUNC_READ_HOLD */
