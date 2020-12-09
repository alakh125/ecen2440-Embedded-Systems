/*
 * buzzer.c
 * Created by Team Spider Roomba
 * Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
 */

#include "buzzer.h"
#include "stdlib.h"
#include "stdio.h"


void config_speaker(void) {
  P2 ->DIR |= BIT4; //set as output
  P2 ->OUT |= BIT4; //set state for pin 2.4
  // P2 ->SEL0 |= BIT4; //allow timerA to control pwm
  // P2 ->SEL1 &= ~BIT4; //allow timerA to control pwm
}

void speaker_off(void) {
  P2 ->SEL0 &= ~BIT4; //remove timerA control of pwm to turn speaker off
}

void speaker_on(void) {
  P2 ->SEL0 |= BIT4; //allow timerA to control pwm to turn speaker on
}

void speaker_random(void) // randomly activate speaker using rand() and toggling of timerA control of pin 2.4
{ //basically run a random check, round up toward activating the speaker off a random chance, if below 0.5 then turn off.
  int randSPEAKER = rand() % 10;
  if(randSPEAKER >= 5) {
    P2->SEL0 |= BIT4;
  }
  else{
    P2->SEL0 &= ~BIT4;
  }
}
