#include "leds.h"
#include "stdlib.h"
#include "stdio.h"

void config_LEDs(void)
{
    P1->DIR |= BIT0;

    P2->DIR |= BIT0;
    P2->DIR |= BIT1;
    P2->DIR |= BIT2;

    P1->OUT |= BIT0;
    P2->OUT |= BIT0;
    P2->OUT |= BIT1;
    P2->OUT |= BIT2;
}

void random_LEDs(void)
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

void disable_LEDs(void)
{
    P1->OUT &= ~BIT0;

    P2->OUT &= ~BIT0;
    P2->OUT &= ~BIT1;
    P2->OUT &= ~BIT2;

}

void autonomous_LEDs()
{
    P1->OUT |= BIT0;

    P2->OUT &= ~BIT0;
    P2->OUT &= ~BIT1;
    P2->OUT &= ~BIT2;

}
