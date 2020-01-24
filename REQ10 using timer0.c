/*
 * REQ8_APP.c
 *
 * Created: 18/01/2020 09:38:18 م
 *  Author: mo
 */

#include "timers.h"
#include "Interrupts.h"
#include "registers.h"
#include "gpio.h"
#include "softwareDelay.h"
#include "led.h"
#include "ledConfig.h"
#include "pushButton.h"
#include "pushButtonConfig.h"
#include "std_types.h"
#define MAX 10
#define START 0

uint8_t Prescaler_Value=0;
volatile uint32_t u32_ovf_counter=0;
int main(void)
{
	uint8_t local_counter=START;
	Led_Init(LED_0);
	//Led_Init(LED_1); /*Debugging*/
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8 ,0,0,T0_INTERRUPT_NORMAL);
	pushButtonInit(BTN_0);
    while(1)
    {
	if (pushButtonGetStatus(BTN_0))
	{
	Led_On(LED_0);
	for(local_counter = START;local_counter<MAX;local_counter++)
{
timer0Start();
timer0DelayMs(100);
//softwareDelayMs(500);
		if (pushButtonGetStatus(BTN_0))
		{/*debuging Method To know if Led 0 is taking one or two second if
			LEd 1 is on then LED 0 takes 2 seconds
			*/
/*Led_On(LED_1);*/
timer0Start();
timer0DelayMs(1000);
 //	softwareDelayMs(1000);
		}
	}
	}
	else
	{
	Led_Off(LED_0);
	/*Led_Off(LED_1);*/
	}


	}
}
