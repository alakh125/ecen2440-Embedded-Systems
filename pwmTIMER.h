#ifndef pwmTIMER_H_
#define pwmTIMER_H_

#include "msp.h"

#define TICKS ((uint16_t)0x001E)

void config_pwm_timerA0(void);

void stop_pwmA0(void);

void start_pwmA0(void);

#endif
