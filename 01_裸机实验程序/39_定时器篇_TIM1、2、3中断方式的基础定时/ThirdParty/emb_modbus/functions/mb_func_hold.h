#ifndef __MB_FUNC_HOLD_H__
#define __MB_FUNC_HOLD_H__

#include <stdint.h>

#include "mb_base.h"
#include "mb_config.h"

#ifdef MB_FUNC_READ_HOLD

extern uint16_t g_mb_hold_reg[MB_HOLD_REG_SUM];

mb_resp_e mb_read_hold_reg(uint8_t *buf, uint8_t buf_len);

#endif  /* end of MB_FUNC_READ_HOLD */

#endif /* __MB_FUNC_HOLD_H__ */ 
