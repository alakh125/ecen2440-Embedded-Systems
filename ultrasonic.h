#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_


#include "msp.h"

int usonic(void); //leveraged from Chandra Kiran Saladi

void PORT2_IRQHandler(void); //interrupt trigger

void TA1_IRQHandler(void); //IRQhandler for TA1

static void Delay(uint32_t loop); //time delay
 


#endif 