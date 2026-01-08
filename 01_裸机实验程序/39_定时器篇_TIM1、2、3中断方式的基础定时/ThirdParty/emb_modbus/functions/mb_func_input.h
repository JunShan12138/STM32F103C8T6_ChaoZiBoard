#ifndef __MB_FUNC_INPUT_H__
#define __MB_FUNC_INPUT_H__

#include <stdint.h>

#include "mb_base.h"
#include "mb_config.h"

#ifdef MB_FUNC_READ_INPUT

extern uint16_t g_mb_input_reg[MB_INPUT_REG_SUM];

mb_resp_e mb_read_input_reg(uint8_t *buf, uint8_t buf_len);

#endif  /* end of MB_FUNC_READ_INPUT */

#endif /* __MB_FUNC_INPUT_H__ */ 
