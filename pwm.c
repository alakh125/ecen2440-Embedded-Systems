/*
 * @author: arielle
 *
 *  pwm.c
 */


#include "pwm.h"



/* Configure TIMER_A0 to produce a PWM waveform */
void config_pwm_timer(void) {
    TIMER_A0->CTL |= TIMER_A_CTL_CLR;               // Clear
    TIMER_A0->CTL |= TIMER_A_CTL_SSEL__SMCLK;       // 3MHz Clock
    TIMER_A0->CTL |= TIMER_A_CTL_ID__2;             // Divide by 2^4
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7;    // Output Mode switched to transition mode 111
    TIMER_A0->CCTL[1] &= TIMER_A_CCTLN_OUTMOD_2;    // select Toggle Output Mode 100 ----->100
    TIMER_A0->CCR[0]  = TICKS;                      // load CCR0 with the calculated
}

/* start the timer by making MC > 0 */
void start_pwm(void) {
    TIMER_A0->CTL |= TIMER_A_CTL_MC__UP;    // up mode - R counts to TAxCCR0, starts timer
}

/* clear all Mode Control bits in TAxCTL register to put into stop mode */
void stop_pwm(void) {
    // use the CTL reg's MC mask to clear all bits in the portion of the register
    TIMER_A0->CTL &= ~(TIMER_A_CTL_MC__STOP);
}

/* configure P2.4 to output the waveform produced by TAO.1 */
void config_pwm_gpio(void) {
    // Initialize the output pin for Timer A0, P2.4 and then set the pin to Primary Mode
    P2->DIR |= BIT4;   // Set P2.4 as an output by setting the DIR bit for the pin to 1
    P2->OUT |= BIT4;   // Set P2.4 to HIGH by setting the OUT bit for the pin to 1
    // Select Alternate Function 1 to use Primary Mode - Timer A0 pin 1
    P2->SEL0 |= BIT4;  // SEL0 = 0b01
    P2->SEL1 &= ~BIT4; // SEL1 = 0b00
}

