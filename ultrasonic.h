/*
 * ultrasonic.h
 * Leveraged from Chandra's code, heavily edited to fit within our project
 * Created by Team Spider Roomba
 * Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#include "msp.h"

int usonic(void); //leveraged from Chandra Kiran Saladi

void PORT2_IRQHandler(void); //interrupt trigger

void TA0_0_IRQHandler(int state); //IRQhandler for TA1

static void Delay(uint32_t loop); //time delay

void config_usa(void);
 


#endif 
