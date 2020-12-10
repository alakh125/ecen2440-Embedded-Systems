/*
 * leds.c
 * Created by Team Spider Roomba
 * Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
 */

#include "leds.h"
#include "stdlib.h"
#include "stdio.h"

void config_LEDs(void)
{
  P1->DIR |= BIT0; //define onboard LED 1.0 as output

  P2->DIR |= BIT0; //define onboard LED 2.0 as output
  P2->DIR |= BIT1; //define onboard LED 2.1 as output
  P2->DIR |= BIT2; //define onboard LED 2.2 as output

  P1->OUT |= BIT0; //set default state
  P2->OUT |= BIT0; //set default state
  P2->OUT |= BIT1; //set default state
  P2->OUT |= BIT2; //set default state
}

void random_LEDs(void) //run a random loop to determine state of each individual R-G-B LED for dance mode
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

void disable_LEDs(void) //disable LEDs by changing bits, disable ALL leds onboard
{
  P1->OUT &= ~BIT0;

  P2->OUT &= ~BIT0;
  P2->OUT &= ~BIT1;
  P2->OUT &= ~BIT2;
}

void autonomous_LEDs(int obstacle) //enable 1.0 to indicate autonomous mode, disable RGB LED, but enable blue IF too close to an object.
{
  P1->OUT |= BIT0;

  P2->OUT &= ~BIT0;
  P2->OUT &= ~BIT1;

  if(obstacle == 1){
    P2->OUT |= BIT2;
    //flash RGB LED if there is a nearby obstacle
  }
  else{
    P2->OUT &= ~BIT2;
  }
}
