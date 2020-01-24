/*
 * Interrupts.h
 *
 * Created: 21/01/2020 01:18:31 م
 *  Author: mo
 */


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "registers.h"
#include "timers.h"
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))
typedef void (*ptr_to_Fun)(void);
extern ptr_to_Fun INT0;
extern ptr_to_Fun INT1;
extern ptr_to_Fun INT2;
extern ptr_to_Fun TIMER2COMP;
extern ptr_to_Fun TIMER2OVF;
extern ptr_to_Fun TIMER1CAPT;
extern ptr_to_Fun TIMER1COMPA;
extern ptr_to_Fun TIMER1COMPB;
extern ptr_to_Fun TIMER1OVF;
extern ptr_to_Fun TIMER0COMP;
extern ptr_to_Fun TIMER0OVF;
extern ptr_to_Fun SPI_STC;
extern ptr_to_Fun USART_RXC;
extern ptr_to_Fun USART_UDRE;
extern ptr_to_Fun USART_TXC;
extern ptr_to_Fun ADC;
extern ptr_to_Fun EE_RDY;
extern ptr_to_Fun ANA_COMP;
extern ptr_to_Fun TWI_I2C;
extern ptr_to_Fun SPM_RDY;
extern void G_interrupt_Enable(void);
extern void G_interrupt_Disable(void);
extern volatile uint32_t u32_ovf_counter;

#endif /* INTERRUPTS_H_ */
