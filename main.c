/*
 * main.c
 *
 *  Created on: Jun 16, 2020
 *      Author: Tyler Davidson
 *     Updated: Aug, 13, 2020
 *    Modified: Sep 28, 2020
 * Modified by: Arielle Blum
 *
 */

#include "msp.h"
#include "stdio.h"

#include "button.h"
#include "leds.h"
#include "buzzer.h"
#include "pwmTIMER.h"

/**
 * main.c
 */

volatile int state = 0;
volatile int state2 = 0;

void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer
    //disable interrupts
    __disable_irq();

   stop_pwmA0();
   config_pwm_timerA0(); 
   start_pwmA0();

   config_LEDs();
   config_speaker();
   config_button();
   config_button2();
   config_nvic_button();

    //enable interrupts
    __enable_irq();

    while(1) {

      while(state == 0 && state2 == 0)
      {
        printf("currently powered on and in autonomous mode \n");
        autonomous_LEDs();
      }
      while(state == 0 && state2 == 1){
        printf("currently powered on and in dance mode \n");
        random_LEDs();
      }
      while(state == 1) {
        printf("currently off \n");
        disable_LEDs();      
      }
    }
}

/* Port1 ISR */
void PORT1_IRQHandler(void)
{
    volatile uint32_t j;
    if(P1->IFG &BIT1){
      printf("state = %d",state);
    //Check flag
      if(state == 1) {
        state &= ~state;
      }
      else {
        state = 1;
      }
      for(j = 0; j < 100000; j++) {
      }
      P1->IFG &= ~BIT1;
    }
    if(P1->IFG &BIT4){
    //Check flag
    printf("state2 = %d",state2);
      if(state2 == 1) {
        state2 &= ~state2;
      }
      else {
        state2 = 1;
      }
      for(j = 0; j < 100000; j++) {
      }
      P1->IFG &= ~BIT4;
    }
 
}

