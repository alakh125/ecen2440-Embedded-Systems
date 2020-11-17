#include "msp.h"
#include <stdint.h>



void PORT1_IRQHandler()
{
    ///
}

int main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;

            Delay(1000);
            P2->DIR |= BIT3;
            P2->OUT |= BIT3;
            P2->OUT &= ~BIT3;
            P2->IFG = 0; //clearing interrupt flag
            P2->IES &= ~BIT4;

}


void TA0_0_IRQHandler()
{
    ///
}

