/*
 * main.c
 * Created by Team Spider Roomba
 * Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
 */

#include "msp.h" // Include base MSP header file
#include "stdio.h" // Include Standard IO header file
#include <stdint.h> // declares integer types
#include "button.h" // Include Button functions header file
#include "leds.h" // Include LED configuration and functions header file
#include "buzzer.h" //Include Buzzer configuration header file.
#include "pwmTIMER.h" //Include timer and PWM configuration for pin 2.4,buzzer.
#include "ultrasonic.h" //Header file for the ultrasonic
#include "servo.h"
#include "pca9685.h"
#include "main.h"

int state = 0; //declare state, the state for determining on/off
int state2 = 0; // declare second state, determining mode to be autonomous or dance
volatile int distance1 = 0;

int fstate(void) {
  return state;
}
int fstate2(void) {
  return state2;
}

void main(void)
{
  WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     //stop watchdog timer for configuration
  //disable interrupts for configuration
  __disable_irq();
  // stop_pwmA0(); //run stop pwm to ensure proper config
  // config_pwm_timerA0(); //configure timerA0 for pwm to speaker
  //  start_pwmA0();
  config_LEDs(); //configure on-board LEDs to be usable
  config_speaker(); //configure speaker to be usable
  config_button(); //configure left side button
  config_button2(); //configure right side button
  config_nvic_button(); //configure NVIC for button interrupts
  config_usa();
  //enable interrupts
  __enable_irq();

  while(1) {
    //autonomous mode
    while(state == 0 && state2 == 0)
    {
      distance1 = usonic();
      printf("Distance = %d inches. Currently powered on and in autonomous mode \n",distance1);
      if(distance1 < 5 && distance1 >= 0){  // 0 <= distance1 <= 10 cm
        //something is in the way
        //speaker_on();
        standing();
        turn_right();
        autonomous_LEDs(1);
      }
      else if (distance1 >= 5){
        //no obstacles obstructing path
        //speaker_off();
        move_forward();
        standing();
        autonomous_LEDs(0);
        /* code */
      }
      else{
        //negative distance1 - US error
        //speaker_on();
        standing();
        autonomous_LEDs(0);
      }
    }
    while(state == 0 && state2 == 1){
      //The dance mode is "unsafe," meaning that the ultrasonic senor is not used to ensure that the robot can't run into obstacles or cause harm to itself
      //This is because we don't have an ultrasonic sensor in use, so ensuring safety would only allow us to choose from one possible direction or turning for the random 
      //movements.
      printf("Currently powered on and in dance mode \n"); //Display current mode
      random_LEDs(); //Run a random selection of LEDs on the onboard MSP RGB led, creating a party effect. 
      //speaker_random();
      random_movement();
    }
    while(state == 1) {
      printf("Currently off \n"); //Display current mode
      stop_pwmA0();
      disable_LEDs(); //Turn off all LEDs for power savings, as we are in the off state.  
      //speaker_off();  // turn speaker off for power savings and correct mode.
    }
  }
}
// Button IRQ Handler 
void PORT1_IRQHandler(void){
  // P2->IFG &= ~BIT7;
  volatile uint32_t j;

  if(P1->IFG &BIT1){
  //Check flag for pin 1.1
    if(state == 1) {
      state &= ~state; //toggle state off using bitwise operations
    }
    else {
      state = 1; // set state to 1 if it is not currently
    }
    for(j = 0; j < 100000; j++) { //Switch debouncing
    }
    P1->IFG &= ~BIT1; //Reset button 1.1 flag
  }
  if(P1->IFG &BIT4){
  //Check flag for pin 1.4
    if(state2 == 1) {
      state2 &= ~state2; //toggle state off using bitwise operations
    }
    else {
      state2 = 1; // set state to 1 if it is not currently
    }
    for(j = 0; j < 100000; j++) { //Switch debouncing
    }
    P1->IFG &= ~BIT4; //Reset button 1.4 flag
    }
}

