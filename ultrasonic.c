/*
 * ultrasonic.c
 * Leveraged from Chandra's code, heavily edited to fit within our project
 * Created by Team Spider Roomba
 * Cyrus Sowdaey, Alakh Patel, Sonal Tamrakar, Nick Evans
 */

#include "msp.h"
#include "stdint.h"
#include "stdlib.h"
#include "stdio.h"
#include "main.h"


int miliseconds = 0;
int distance = 0;
long sensor = 0;
int A = 1;

static void Delay(uint32_t loop)
{
  volatile uint32_t i;
  for (i = 0 ; i < loop ; i++);
}
void config_usa(void) {
  P2->DIR &= ~BIT7;            // P2.7 as output
  P2->REN |= BIT7;            // P2.7 pull down enabled
  P2->OUT &= ~BIT7;            // P2.7 initial output Low
  P2->IFG = 0;                 //Set interrupt flag to 0
  P2->IE |= BIT7;               // Port 2.7 Interrupt enable
  P2->IES &= ~BIT7;             // Port 2.7 Interrupt edge select

  TIMER_A0->CCTL[0]= TIMER_A_CCTLN_CCIE;       // CCR0 interrupt enabled
  TIMER_A0->CCR[0] = 1000-1;                   // 1ms at 1mhz
  TIMER_A0->CTL = TIMER_A_CTL_TASSEL_2 | TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR;                  // SMCLK, upmode

  NVIC->ISER[1] = 1 << ((PORT2_IRQn) & 31);       // Very important to assign interrupts to the NVIC vector otherwise they would not
                                                  // considered
  NVIC->ISER[0] = 1 << ((TA0_0_IRQn) & 31);
}
int usonic(void)
{
  P2->DIR |= BIT6;          // trigger pin as output
  P2->OUT |= BIT6;          // generate pulse
  Delay(100);               // for 10us
  P2->OUT &= ~BIT6;         // stop pulse
  // P2->IFG = 0;              // clear P2 interrupt just in case anything happened before
  P2->IES &= ~BIT7;         // rising edge on ECHO pin
  Delay(20000);
  // distance =  sensor/ (float) 58.0;
  distance = sensor/435; // 58 converting ECHO length into cm
  // distance = distance/60;
  // distance = distance*4;
  return distance;

}

// Timer A0 interrupt service routine
void PORT2_IRQHandler(void)
{
  if(P2->IFG & BIT7)  //is there interrupt pending?
  {
    if(!(P2->IES & BIT7)) // is this the rising edge?
    {
      TIMER_A0->CTL |= TIMER_A_CTL_CLR;   // clears timer A
      miliseconds = 0;
      P2->IES |=  BIT7;  //falling edge
    }
    else
    {
      sensor = (long)miliseconds*1000 + (long)TIMER_A0->R;    //calculating ECHO length
      //            P1->OUT ^= BIT0;
      P2->IES &=  ~BIT7;  //falling edge
    }
    P2->IFG &= ~BIT7;             //clear flag
  }
}

void TA0_0_IRQHandler(void)
{
  int valstate = fstate();
  int valstate2 = fstate2();
  //Interrupt gets triggered for every clock cycle in SMCLK Mode counting number of pulses
  miliseconds++; //increases milisecond timer for ultrasonic sensor
  if(A == 1 && distance < 5 && valstate2 == 0 && valstate == 0) {
    A = 0; 
    P2 -> OUT |= BIT4;
  }
  else{
    A = 1;
    P2 -> OUT &= ~BIT4;
  }
  TIMER_A0->CCTL[0] &= ~TIMER_A_CCTLN_CCIFG; //Clear the capture/compare interrupt flag
}

