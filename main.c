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
#include "i2c.h"
#include "stIMU.h"
#include "stdio.h"

#include "button.h"
#include "leds.h"

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
   config_LEDs();
   config_button();
   config_button2();
   config_nvic_button();

    //enable interrupts
    __enable_irq();

/*
    I2C_OPEN_STRUCT_TypeDef i2c_open_struct;

    i2c_open_struct.uca10 = 0;                              //no self 10-bit Address
    i2c_open_struct.ucsla10 = 0;                            //no 10-bit Addressing
    i2c_open_struct.ucmm = 0;                               //No Multi-Controller
    i2c_open_struct.ucmst = EUSCI_B_CTLW0_MST;              //Controller Mode
    i2c_open_struct.ucsselx = EUSCI_B_CTLW0_SSEL__SMCLK;    //SMCLK to be selected (3MHz)
    i2c_open_struct.ucbrx = 30;                             //Prescaler for Selected Clock.
                                                            //(100kHz)

     //This sets up the I2C driver to operate with the correct settings.
     //EUSCI_B0 uses P1.7 as SCL and P1.6 as SDA
     i2c_open(EUSCI_B0, &i2c_open_struct);

     config_LIS3MDL();

     uint16_t mx, my, mz;
     uint8_t data;
     int i;
*/
    while(1) {
      //Neutral Position
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
    if(P1->IFG &BIT1 /*&& P1->IFG ~&BIT4*/){
      printf("state = %d",state);
    //Check flag
      if(state == 1) {
        state &= ~state;
      }
      else {
        state = 1;
      }
      // Delay for switch debounce, can use __no_operation() instead if you want!
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
      // Delay for switch debounce, can use __no_operation() instead if you want!
      for(j = 0; j < 100000; j++) {
      }
      P1->IFG &= ~BIT4;
    }
 
      //end of interrupt, what needs to happen here?
}

