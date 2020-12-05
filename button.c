/*
 * button.c
 *
 *  Created on: Sep 30, 2020
 *      Author:
 */

#include "button.h"

/* Configure the S1 Button */
void config_button(void)
{
    //config S1 on the MSP432P401R SimpleLink Launchpad as a button interrupt
    //set up Button Interrupt
   P1->DIR &= ~BIT1;            // Input
   P1->OUT |= BIT1;             // Select Bit1 /PULL-Up resistor
   P1->REN |= BIT1;             //Pull up  enabled
   P1->IES |= BIT1;             // PxIFG is set with High-to-low transition
   P1->IFG =0;                  //Clear flag
   P1 ->IE |= BIT1;             //Interrupt enabled
}
void config_button2(void)
{
    //config S1 on the MSP432P401R SimpleLink Launchpad as a button interrupt
    //set up Button Interrupt
   P1->DIR &= ~BIT4;            // Input
   P1->OUT |= BIT4;             // Select Bit1 /PULL-Up resistor
   P1->REN |= BIT4;             //Pull up  enabled
   P1->IES |= BIT4;             // PxIFG is set with High-to-low transition
   P1->IFG =0;                  //Clear flag
   P1 ->IE |= BIT4;             //Interrupt enabled
}

/* Configure NVIC for Interrupt Source */
void config_nvic_button(void)
{
    __NVIC_EnableIRQ(PORT1_IRQn);
    //configure the NVIC for the button interrupt source
}


