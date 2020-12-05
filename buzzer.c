#include "buzzer.h"
#include "stdlib.h"
#include "stdio.h"

void config_speaker(void) {
    P2 ->DIR |= BIT4;
    P2 ->OUT |= BIT4;
    P2 ->SEL0 |= BIT4; 
    P2 ->SEL1 &= ~BIT4;
}
