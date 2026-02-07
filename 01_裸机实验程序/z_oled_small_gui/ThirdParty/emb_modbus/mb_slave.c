#include "mb_slave.h"


#define MB_TIMEOUT_MAX   200

static uint8_t _mb_recv_buf[MB_RECV_BUF_LEN];
static uint8_t _mb_recv_len;
static uint8_t _mb_address;
static uint8_t _mb_recv_timeout;

/***************************************************************************************************
 * @fn      mb_send_cb
 *
 * @brief   modbus发送数据回调函数
 *
 * @param   buf 发送的数据
 * @param   buf_len 发送的数据长度 
 *
 * @return  发送成功返回MB_RESP_OK，不成功返回其它
 */
static mb_resp_e mb_send_cb(uint8_t *buf, uint8_t buf_len)
{

    return MB_RESP_OK;
}

/***************************************************************************************************
 * @fn      mb_slave_poll
 *
 * @brief   处理Modbus数据
 *
 * @param   无 
 *
 * @return  无
 */
void mb_slave_poll(void)
{
    uint16_t addr;
    uint16_t crc;
    mb_resp_e resp = MB_RESP_OK;

    /* 超过4ms没有新数据，说明一帧数据收完 */
    if (_mb_recv_timeout == 4)
    {
        if (_mb_recv_len > 1)
        {
            /* 检查发来的地址 */
            addr = _mb_recv_buf[MB_LOCAL_ADDR_INDEX];
            if (addr != _mb_address)
            {
                /* 地址不对直接退出 */
                _mb_recv_len = 0;
                return;
            }

            /* 计算校验值 */
            crc = mb_crc16(_mb_recv_buf, _mb_recv_len);
            if (0 != crc)
            {
                /* 校验码不对，直接退出 */
                _mb_recv_len = 0;
                return;
            }
            
            /* 功能码 */
            switch (_mb_recv_buf[MB_FUNC_CODE_INDEX])
            {
                case 0x03:  /* 读保持寄存器 */
                {
                #ifdef MB_FUNC_READ_HOLD
                    resp = mb_read_hold_reg(_mb_recv_buf, _mb_recv_len);
                #else
                    resp = MB_RESP_ERR_CMD;
                #endif
                    if (resp != MB_RESP_OK)
                    {
                        mb_response_error(_mb_recv_buf, resp);
                    }
                    break;
                }
                
                case 0x04:  /* 读输入寄存器 */
                {
                #ifdef MB_FUNC_READ_INPUT
                    resp = mb_read_input_reg(_mb_recv_buf, _mb_recv_len);
                #else
                    resp = MB_RESP_ERR_CMD;
                #endif
                    if (resp != MB_RESP_OK)
                    {
                        mb_response_error(_mb_recv_buf, resp);
                    }
                    break;
                }
                
                default:  /* 不支持的功能码 */
                {
                    mb_response_error(_mb_recv_buf, MB_RESP_ERR_CMD);
                    break;
                }
            }
        }

        _mb_recv_len = 0;
    }  
}

/***************************************************************************************************
 * @fn      mb_slave_init
 *
 * @brief   Modbus初始化
 *
 * @param   无 
 *
 * @return  无
 */
void mb_slave_init(void)
{
    /* 初始化一些参数 */
    _mb_recv_timeout = MB_TIMEOUT_MAX;  /* 超时计数 */
    _mb_address = 0x01;  /* 本机地址 */
    
    /* 注册数据发送回调函数 */
    mb_reg_send_cb(mb_send_cb);
}

/***************************************************************************************************
 * @fn      mb_recv_timeout_cnt
 *
 * @brief   接收超时计数
 *
 * @param   无 
 *
 * @return  无
 */
void mb_recv_timeout_cnt(void)
{
    if (_mb_recv_timeout < MB_TIMEOUT_MAX)
    {
        _mb_recv_timeout++;
    }
}

/***************************************************************************************************
 * @fn      mb_receive_byte
 *
 * @brief   数据接收->这个可以放在中断中
 *
 * @param   data 接收到的一个字节数据 
 *
 * @return  无
 */
void mb_receive_byte(uint8_t data)
{
    /* 接收一次数据就清零一次 */
    _mb_recv_timeout = 0;

    /* 接收的数据长度不能超过缓冲区大小 */
    if (_mb_recv_len < MB_RECV_BUF_LEN)
    {
        _mb_recv_buf[_mb_recv_len] = data;
        _mb_recv_len++;
    }
}
