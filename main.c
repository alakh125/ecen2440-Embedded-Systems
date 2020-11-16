#include "msp.h"
#include "pwm.h"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
    stop_pwm();
	config_pwm_timer();
	config_pwm_gpio();
    start_pwm();
    while(1)
    {
        printf("Banana \n");
    }
}
