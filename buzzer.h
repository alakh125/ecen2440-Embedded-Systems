#ifndef BUZZER_H_
#define BUZZER_H_

#include "msp.h"

// Created by Team Spider Roomba
 // Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans

void config_speaker(void); //configure speaker for use

void speaker_off(void); //turn speaker off for off mode

void speaker_on(void); //allow speaker to be used with timerA

void speaker_random(void); //randomly activate speaker for use with timerA

#endif
