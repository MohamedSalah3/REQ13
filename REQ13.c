/*
 * REQ13.c
 *
 * Created: 24/01/2020 11:46:05 م
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
uint32_t volatile u32_ovf_counter=0;
uint8_t Prescaler_Value=0;
int main(void)
{
	timer0Init(T0_NORMAL_MODE,T0_OC0_DIS,T0_PRESCALER_8 ,0,0,T0_INTERRUPT_NORMAL);
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	pushButtonInit(BTN_0);

	while(1)
	{
		if (pushButtonGetStatus(BTN_0))
		{
		Led_On(LED_3);
		timer0Start();
		timer0DelayMs(1000);
		}
		else
		{
		Led_Off(LED_3);
		Led_On(LED_1);
		timer0Start();
		timer0DelayMs(1000);
		Led_Off(LED_1);
		Led_On(LED_3);
		timer0Start();
		timer0DelayMs(1000);
		Led_Off(LED_3);
		Led_On(LED_2);
		timer0Start();
		timer0DelayMs(1000);
		Led_Off(LED_2);
			
		}
	}
	
}	