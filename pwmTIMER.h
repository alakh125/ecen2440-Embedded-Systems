#ifndef pwmTIMER_H_
#define pwmTIMER_H_
// Created by Team Spider Roomba
 // Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
#include "msp.h"

#define TICKS ((uint16_t)0x01E0) //Set ticks to 480 with input divider of 2^4

void config_pwm_timerA0(void);


void stop_pwmA0(void);

void start_pwmA0(void);

void pause_pwmA0(void);

#endif
