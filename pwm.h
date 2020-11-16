/*
 * pwm.h
 *
 *  Created on: Sep 13, 2020
 *      Author: arielle blum
 */

#ifndef PWM_H_
#define PWM_H_

#include "msp.h"

/*   D E F I N E S  */
/* (f_src/(2^ID))*(1/(0.5*f_desired) */
/* ((3MHz)/(2^4)*(1/30Hz)) = 6250 in decimal */
#define TICKS ((uint16_t)0x186A)


/* Configure TIMER_A0 to produce a PWM waveform */
void config_pwm_timer(void);

/* Start counting by making MC>{0} by 19.2.2 Starting the Timer*/
void start_pwm(void);

/* Clear all Mode Control bits in TAxCTL register to put into stop mode
 * 19.2.2 Starting the Timer: If Timer is in UP mode, write a ZERO to TAxCCR0 to stop timer
 */
void stop_pwm(void);

/* configure P2.4 to output the waveform produced by TAO.1 */
void config_pwm_gpio(void);

#endif /* PWM_H_ */
