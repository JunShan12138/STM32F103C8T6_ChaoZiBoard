#include "mb_base.h"
#include "mb_crc.h"


/* modbus发送数据缓冲区 */
uint8_t g_mb_send_buf[MB_SEND_BUF_LEN];

/* modbus发送数据回调函数指针 */
mb_send_cb_t _mb_send_cb = NULL;


/***************************************************************************************************
 * @fn      big_endian_to_uint16
 *
 * @brief   把数据转换成16进制
 *
 * @param   send_cb 数据发送回调函数
 *
 * @return  转换得到的16进制的数据 
 */
uint16_t big_endian_to_uint16(uint8_t *buf)
{
    return (((uint16_t)buf[0] << 8) | buf[1]);
}

/***************************************************************************************************
 * @fn      mb_reg_send_cb
 *
 * @brief   注册发送回调函数
 *
 * @param   send_cb 数据发送回调函数
 *
 * @return  无
 */
void mb_reg_send_cb(mb_send_cb_t send_cb)
{
    _mb_send_cb = send_cb;
}

/***************************************************************************************************
 * @fn      mb_send_with_crc
 *
 * @brief   计算CRC，并发送数据
 *
 * @param   tx_buf 要发送的数据
 * @param   tx_len 数据长度（单位：字节）
 *
 * @return  返回MB_RESP_OK则发送成功
 */
mb_resp_e mb_send_with_crc(uint8_t *tx_buf, uint16_t tx_len)
{
    uint16_t crc;
    mb_resp_e resp = MB_RESP_OK;
    
    /* 要发送的数据长度没有超过缓冲区大小 */
    if (tx_len < (MB_SEND_BUF_LEN - 2))
    {
        /* 计算校验码 */
        crc = mb_crc16(tx_buf, tx_len);
        tx_buf[tx_len++] = (crc << 8);
        tx_buf[tx_len++] = (crc & 0xFF);

        /* 发送回调函数已经注册 */
        if (_mb_send_cb != NULL)
        {
            resp = _mb_send_cb(tx_buf, tx_len);  /* 发送数据 */
        }
        else
        {
            resp = MB_RESP_ERR_VALUE;  /* 未注册发送函数，则错 */
        }
    }
    else
    {
        resp = MB_RESP_ERR_VALUE;  /* 超出发送缓冲区的范围 */
    }

    return resp;
}

/***************************************************************************************************
 * @fn      mb_response_error
 *
 * @brief   错误响应
 *
 * @param   recv 接收到的数据
 * @param   err_code 错误码
 *
 * @return  返回MB_RESP_OK则发送成功
 */
mb_resp_e mb_response_error(uint8_t *recv, uint8_t err_code)
{
    uint8_t  *tx_buf = &g_mb_send_buf[0];
    uint16_t tx_cnt = 0;
    
    /* 准备发送数据 */
    tx_buf[tx_cnt++] = recv[MB_LOCAL_ADDR_INDEX];  /* 本机地址 */
    tx_buf[tx_cnt++] = recv[MB_FUNC_CODE_INDEX] | 0x80;  /* 功能码|0x80，就是功能码报错*/
    tx_buf[tx_cnt++] = err_code;
    
    return mb_send_with_crc(tx_buf, tx_cnt);
}
