#ifndef BUTTON_H_
#define BUTTON_H_

#include "msp.h"

//#define TICKS ((uint16_t)0x0003)
#define TICKS ((uint16_t)0xFFFF)

#define TICKS2 ((uint16_t)0x00FF)
/* Configure the S1 Button */
void config_button(void);

/* Configure NVIC for Interrupt Source */
void config_nvic_button(void);

void config_LEDs(void);

void random_LEDs(void);

void disable_LEDs(void);

void autonomous_LEDs(void);

void autonomous_mode(void);

void dance_mode(void);

void random_buzzer(void);

void config_pwm_timerA0(void);

void config_pwm_timerA1(void);

void start_pwmA0(void);

void start_pwmA1(void);

void stop_pwmA0(void);

void stop_pwmA1(void);

void NVIC_enableA0(void);

void NVIC_enableA1(void);

void TA0_N_IRQHandler(void);

void TA1_N_IRQHandler(void);

void config_speaker(void);




#endif /* BUTTON_H_ */
