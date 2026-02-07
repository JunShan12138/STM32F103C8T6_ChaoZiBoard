#ifndef __MB_BASE_H__
#define __MB_BASE_H__

#include <stdint.h>
#include <stddef.h>

#include "mb_config.h"

#define MB_LOCAL_ADDR_INDEX    0   /* 本机地址字节位置索引 */
#define MB_FUNC_CODE_INDEX     1  /* 功能码位置索引 */

typedef enum
{
    MB_RESP_OK            = 0,     /* 成功*/
    MB_RESP_ERR_CMD       = 0x01,  /* 不支持的功能码 */
    MB_RESP_ERR_REG_ADDR  = 0x02,  /* 寄存器地址错误 */
    MB_RESP_ERR_VALUE     = 0x03,  /* 数据错误 */
    MB_RESP_ERR_WITE      = 0x04,  /* 写入失败 */
}mb_resp_e;


typedef mb_resp_e (*mb_send_cb_t)(uint8_t *buf, uint8_t buf_len);

extern uint8_t g_mb_send_buf[MB_SEND_BUF_LEN];

uint16_t big_endian_to_uint16(uint8_t *buf);

void mb_reg_send_cb(mb_send_cb_t send_cb);

mb_resp_e mb_send_with_crc(uint8_t *tx_buf, uint16_t tx_len);

mb_resp_e mb_response_error(uint8_t *recv, uint8_t err_code);

#endif

