#include "button.h"
#include "stdlib.h"
#include "stdio.h"

/* Configure the S1 Button */
void config_pwm_timerA0(void) {
    TIMER_A0->CTL |= TIMER_A_CTL_CLR;               // Clear
    TIMER_A0->CTL |= TIMER_A_CTL_SSEL__SMCLK;       // 3MHz Clock
    TIMER_A0->CTL |= TIMER_A_CTL_ID__4;             // Divide by 2^4
    TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7;    // Output Mode switched to transition mode 111
    TIMER_A0->CCTL[1] &= TIMER_A_CCTLN_OUTMOD_2;    // select Toggle Output Mode 100 ----->100
    TIMER_A0->CCR[0]  = TICKS;
    TIMER_A0 ->CCTL[1] |= TIMER_A_CCTLN_CCIE; /*!< Capture/compare interrupt enable */
}

void config_pwm_timerA1(void) {
    TIMER_A1->CTL |= TIMER_A_CTL_CLR;
    TIMER_A1->CTL |= TIMER_A_CTL_SSEL__SMCLK;
    TIMER_A1->CTL |= TIMER_A_CTL_ID__8;
    TIMER_A1-> CCR[0] |= TICKS2;
    TIMER_A1->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7;
    TIMER_A1->CCTL[1] &= TIMER_A_CCTLN_OUTMOD_4;
    TIMER_A1 ->CCTL[1] |= TIMER_A_CCTLN_CCIE; /*!< Capture/compare interrupt enable */
}


void NVIC_enableA0(void) {
    __NVIC_EnableIRQ(TA0_N_IRQn); // enable NVIC
}
void NVIC_enableA1(void) {
    __NVIC_EnableIRQ(TA1_N_IRQn); // enable NVIC
}

void NVIC_disableA0(void) {
     __NVIC_DisableIRQ(TA0_N_IRQn); // disable NVIC
}
void NVIC_disableA1(void) {
     __NVIC_DisableIRQ(TA1_N_IRQn); // disable NVIC
}

void start_pwmA0(void) {
    TIMER_A0->CTL |= TIMER_A_CTL_MC__UP;    // up mode - R counts to TAxCCR0, starts timer
}
void start_pwmA1(void) {
    TIMER_A1->CTL |= TIMER_A_CTL_MC__UP;    // up mode - R counts to TAxCCR0, starts timer
}

void stop_pwmA0(void) {
    // use the CTL reg's MC mask to clear all bits in the portion of the register
    TIMER_A0->CTL &= ~(TIMER_A_CTL_MC__STOP);
}
void stop_pwmA1(void) {
    // use the CTL reg's MC mask to clear all bits in the portion of the register
    TIMER_A1->CTL &= ~(TIMER_A_CTL_MC__STOP);
}

/*
void TA0_N_IRQHandler(void) {
    TIMER_A0->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG; // clear the flag so that we aren't continually triggering it
    printf("this is working \n");
    // P2->OUT ^= BIT0; // toggle pin2.4 on / off depending on state, thus toggling whatever it is connected to since it is providing the power
}
*/

void TA1_N_IRQHandler(void) {
    TIMER_A1->CCTL[1] &= ~TIMER_A_CCTLN_CCIFG; // clear the flag so that we aren't continually triggering it
}



void config_speaker(void)
{
    P1->DIR |= BIT6;
    P1->OUT |= BIT6;
}

void config_button(void)
{
    P1->DIR &= ~BIT1; //define port 1.1 as input
    P1->DIR &= ~BIT4; //define port 1.4 as input

    P1->OUT |= BIT1; // port pin out configured for pullup resistor
    P1->OUT |= BIT4; // port pin out configured for pullup resistor

    P1->REN |= BIT1; // enable pullup/pulldown resistor
    P1->REN |= BIT4; // enable pullup/pulldown resistor

    //config S1 on the MSP432P401R SimpleLink Launchpad as a button interrupt
    //set up Button Interrupt

    P1->IE |= BIT1; //enable interrupt register P1.1
    P1->IE |= BIT4; //enable interrupt register P1.4

    P1->IES |= BIT1; //set IFG flag to high-to-low transition
    P1->IES |= BIT4; //set IFG flag to high-to-low transition

    P1->IFG &= ~BIT1; //clear interrupt flag
    P1->IFG &= ~BIT4; //clear interrupt flag
}

/* Configure NVIC for Interrupt Source */
void config_nvic_button(void)
{
    //configure the NVIC for the button interrupt source
    __NVIC_EnableIRQ(PORT1_IRQn);
}

void config_LEDs(void)
{
    P1->DIR |= BIT0;

    P2->DIR |= BIT0;
    P2->DIR |= BIT1;
    P2->DIR |= BIT2;

    P1->OUT |= BIT0;
    P2->OUT |= BIT0;
    P2->OUT |= BIT1;
    P2->OUT |= BIT2;
}

void random_LEDs(void)
{
    P1->OUT &= ~BIT0;
    int randRed = rand() % 10;
    int randGreen = rand() % 10;
    int randBlue = rand() % 10;
    if(randRed >= 5) {
        P2->OUT |= BIT0;
    }
    else {
        P2->OUT &= ~BIT0;
    }
    if(randGreen >= 5) {
        P2->OUT |= BIT1;
    }
    else {
        P2->OUT &= ~BIT1;
    }
    if(randBlue >= 5) {
        P2->OUT |= BIT2;
    }
    else {
        P2->OUT &= ~BIT2;
    }
}

void disable_LEDs(void)
{
    P1->OUT &= ~BIT0;

    P2->OUT &= ~BIT0;
    P2->OUT &= ~BIT1;
    P2->OUT &= ~BIT2;

}

void autonomous_LEDs()
{
    P1->OUT |= BIT0;

    P2->OUT &= ~BIT0;
    P2->OUT &= ~BIT1;
    P2->OUT &= ~BIT2;

}

void autonomous_mode()
{
    autonomous_LEDs();
}

void dance_mode(void)
{
    random_LEDs();
}








