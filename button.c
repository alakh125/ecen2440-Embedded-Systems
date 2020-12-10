/*
 * button.c
 * Created by Team Spider Roomba
 * Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
 */



#include "button.h"

//Configure Button 1.1
void config_button(void) 
{
  //set up Button Interrupt
  P1->DIR &= ~BIT1;            // Set as Input
  P1->OUT |= BIT1;             // Enable pullup resistor
  P1->REN |= BIT1;             //Pull up enabled
  P1->IES |= BIT1;             //Set to High-to-low transition
  P1->IFG =0;                  //Clear flag
  P1 ->IE |= BIT1;             //Interrupt enabled
}
//Configure Button 1.4
void config_button2(void)
{
  //set up Button Interrupt
  P1->DIR &= ~BIT4;            // Input
  P1->OUT |= BIT4;             // Enable pullup resistor
  P1->REN |= BIT4;             //Pull up  enabled
  P1->IES |= BIT4;             //Set to High-to-low transition
  P1->IFG =0;                  //Clear flag
  P1 ->IE |= BIT4;             //Interrupt enabled
}

//Config NVIC
void config_nvic_button(void)
{
  __NVIC_EnableIRQ(PORT1_IRQn);// Assign interrupts to the NVIC vector
  __NVIC_SetPriority(PORT1_IRQn, 1); // Set high priority, over other interrupts like port2 and timerA0
}


