/*
 * pwmTIMER.c
 * Created by Team Spider Roomba
 * Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
 */

#include "pwmTIMER.h"
#include "stdlib.h"
#include "stdio.h"

void config_pwm_timerA0(void) {
  TIMER_A0->CTL |= TIMER_A_CTL_CLR;            //
  TIMER_A0->CTL |= TIMER_A_CTL_SSEL__SMCLK;    //Select the clock source, 50mHZ
  TIMER_A0->CTL |= TIMER_A_CTL_ID__4;          //Input Divider = 4 -> Clock divided by 2^4
  TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7; // Set to transition state
  TIMER_A0->CCTL[1] &= TIMER_A_CCTLN_OUTMOD_4; //Set output mod 4
  TIMER_A0 -> CCR[0] |= TICKS;                 //Set tick value for ID calculations
}

void stop_pwmA0(void) {
  // use the CTL reg's MC mask to clear all bits in the portion of the register
  TIMER_A0->CTL &= ~(TIMER_A_CTL_MC__STOP); //Stop timer so it can be configured without potential issues
}

void start_pwmA0(void) {
  TIMER_A0->CTL |= TIMER_A_CTL_MC__UP;    // up mode - R counts to TAxCCR0, starts timer
}

