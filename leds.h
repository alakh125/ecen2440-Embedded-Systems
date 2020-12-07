#ifndef LEDS_H_
#define LEDS_H_
// Created by Team Spider Roomba
 // Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
#include "msp.h"


void config_LEDs(void); // configure LEDs for function

void random_LEDs(void); // random LED mode

void disable_LEDs(void); //disable  LEDs for off mode

void autonomous_LEDs(int obstacle); //LED state for autonomous mdoe indication


#endif
