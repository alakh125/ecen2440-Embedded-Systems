#include "msp.h"
#include "stdio.h"
#include "stdlib.h"
#include "button.h"

volatile int state = 0;
volatile int state2 = 0;

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    //disable interrupts
    __disable_interrupt();

    config_button();
    config_nvic_button();
    config_LEDs();
    stop_pwmA0();
   // stop_pwmA1();
    config_pwm_timerA0();
 //   config_pwm_timerA1();
    NVIC_enableA0();
  //  NVIC_enableA1();
    start_pwmA0();
   // start_pwmA1();
    //enable interrupts
    __enable_interrupt();
    while(1) {
     while(state == 0 && state2 == 0)
     {
         // autonomous_LEDs();
         while(~TIMER_A0->CCTL[1] == 1) {
             printf("waiting \n");
         }
         P2->OUT ^= BIT0;
         printf("currently powered on and in autonomous mode \n");

     }
     while(state == 0 && state2 == 1)
          {
              printf("currently powered on and in dance mode \n");
              random_LEDs();
          }
     while(state == 1){
         printf("currently powered off \n");
         disable_LEDs();
    }
}
}

/* Port1 ISR */void PORT1_IRQHandler(void)

{
    volatile uint32_t j;
    if(P1->IFG &BIT1) { //check flag 1.1 to see if interrupt has been raised
    if(state == 1) {
        state &= ~state;
    }
    else {
        state = 1;
    }
    for(j = 0; j < 100000; j++) {
        }
    P1->IFG &= ~BIT1; //clear interrupt flag
    }
    if(P1->IFG &BIT4) { //check flag 1.4 to see if interrupt has been raised
        if(state2 == 1) {
            state2 &= ~state2;
            }
            else {
                state2 = 1;
            }
        for(j = 0; j < 100000; j++) {
            }
        P1->IFG &= ~BIT4; //clear interrupt flag
        }
}
