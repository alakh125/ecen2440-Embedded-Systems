#include "pwmTIMER.h"
#include "stdlib.h"
#include "stdio.h"


void config_pwm_timerA0(void) {
    TIMER_A0->CTL |= TIMER_A_CTL_CLR;
    TIMER_A0->CTL |= TIMER_A_CTL_SSEL__SMCLK;
    TIMER_A0->CTL |= TIMER_A_CTL_ID__1;
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7;
    TIMER_A0->CCTL[1] &= TIMER_A_CCTLN_OUTMOD_4;
    TIMER_A0 -> CCR[0] |= TICKS;
}

void stop_pwmA0(void) {
    // use the CTL reg's MC mask to clear all bits in the portion of the register
    TIMER_A0->CTL &= ~(TIMER_A_CTL_MC__STOP);
}

void start_pwmA0(void) {
    TIMER_A0->CTL |= TIMER_A_CTL_MC__UP;    // up mode - R counts to TAxCCR0, starts timer
}
