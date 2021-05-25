/*
 * ATmega32A_Interrupt.h
 *
 * Created: 10/5/2020 2:22:19 PM
 *  Author: ahmedsoliman
 */ 


#ifndef ATMEGA32A_INTERRUPT_H_
#define ATMEGA32A_INTERRUPT_H_


	#include "StandardDataType.h"

	typedef enum
	{
		EXINT_LowLevel,
		EXINT_Toggle,
		EXINT_FallingEdge,
		EXINT_RisingEdge,
	}ExInterrupt_Modes;


	typedef enum
	{
		EXINT_INT0,
		EXINT_INT1,
		EXINT_INT2,
	}EXInterrupt_Source;


	extern void (* EXTINT0_ISR) (void);
	extern void (* EXTINT1_ISR) (void);
	extern void (* EXTINT2_ISR) (void);
	void EXTINT_InterruptInit(EXInterrupt_Source source,ExInterrupt_Modes Mode);


#endif /* ATMEGA32A_INTERRUPT_H_ */