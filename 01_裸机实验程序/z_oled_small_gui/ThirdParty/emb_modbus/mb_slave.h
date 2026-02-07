#ifndef __MB_SLAVE_H__
#define __MB_SLAVE_H__

#include <stdint.h>


#include "mb_crc.h"
#include "mb_base.h"
#include "mb_func_input.h"
#include "mb_func_hold.h"

void mb_slave_init(void);
void mb_slave_poll(void);

void mb_recv_timeout_cnt(void);

#endif  /* __MB_SLAVE_H__ */
