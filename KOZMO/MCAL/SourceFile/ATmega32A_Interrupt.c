/*
 * ATmega32A_Interrupt.c
 *
 * Created: 10/5/2020 2:22:41 PM
 *  Author: ahmedsoliman
 */ 
  
  
  #include "ATmega32A_Config.h"
  #include "ATmega32A_DIO_Config.h"
  #include "ATmega32A_Interrupt.h"
  
  
  /* Vector 0 is the reset vector */
  /* External Interrupt Request 0 */
  #define INT0_vect            _VECTOR(1)
  #define INT0_vect_num        1

  /* External Interrupt Request 1 */
  #define INT1_vect            _VECTOR(2)
  #define INT1_vect_num        2

  /* External Interrupt Request 2 */
  #define INT2_vect            _VECTOR(3)
  #define INT2_vect_num        3
  
  /* interrupt RX complete in the USART communication */
  #define USART_RXC_vect           _VECTOR(13)
  #define USART_RXC_vect_num         13
  
  /* interrupt TX complete in the USART communication */
  #define USART_TXC_vect           _VECTOR(15)
  #define USART_TXC_vect_num         15
  
  /* interrupt UDRE data register empty in the USART communication */
  #define USART_UDRE_vect           _VECTOR(14)
  #define USART_UDRE_vect_num         14
  
  

  /* bits of The MCUCR register to Control INT0, INT1 */
  #define ISC00		(0)
  #define ISC01		(1)
  #define ISC10		(2)
  #define ISC11		(3)
  #define ISC2      (6)
  
  /* bits of The GICR register */
  #define INT0     (6)
  #define INT1     (7)
  #define INT2     (5)
  
  /* initiate the Pointer Of The Interrupt Function With NULL */
  void (* EXTINT0_ISR) (void) = NULL;
  void (* EXTINT1_ISR) (void) = NULL;
  void (* EXTINT2_ISR) (void) = NULL;
  
  
  

  ISR (INT0_vect,ISR_NESTED_ENABLE)
     {
		 if (EXTINT0_ISR != NULL)
		 {
			 EXTINT0_ISR();
		 }
	 }


	void EXTINT_InterruptInit(EXInterrupt_Source source,ExInterrupt_Modes Mode)
	{
		switch (source)
		{
			case EXINT_INT0 :
				 switch (Mode)
				 {
					 case EXINT_LowLevel :
						  RESET_Bit(MCUCR,ISC00);
						  RESET_Bit(MCUCR,ISC01);
						  break;
					 case EXINT_Toggle :
						  SET_Bit(MCUCR,ISC00);
						  RESET_Bit(MCUCR,ISC01);
						  break;
					 case EXINT_FallingEdge :
						  RESET_Bit(MCUCR,ISC00);
						  SET_Bit(MCUCR,ISC01);
						  break;
					 case EXINT_RisingEdge :
						  SET_Bit(MCUCR,ISC00);
						  SET_Bit(MCUCR,ISC01);
						  break;
				  }
				/* Enable THe InT 0 */
				SET_Bit(GICR,INT0);	
				break;
		  case EXINT_INT1 :
				 switch (Mode)
				 {
					 case EXINT_LowLevel :
						  RESET_Bit(MCUCR,ISC10);
						  RESET_Bit(MCUCR,ISC11);
						  break;
					 case EXINT_Toggle :
						  SET_Bit(MCUCR,ISC11);
						  RESET_Bit(MCUCR,ISC10);
						  break;
					 case EXINT_FallingEdge :
						  RESET_Bit(MCUCR,ISC11);
						  SET_Bit(MCUCR,ISC10);
						  break;
					 case EXINT_RisingEdge :
						  SET_Bit(MCUCR,ISC11);
						  SET_Bit(MCUCR,ISC10);
					break;
				 }
				 /* Enable THe InT 0 */
				 SET_Bit(GICR,INT1);
				 break;
		  case EXINT_INT2 :
			   switch (Mode)
			   {
				   case EXINT_FallingEdge :
						RESET_Bit(MCUCSR,ISC2);
						break;
				   case EXINT_RisingEdge :
						SET_Bit(MCUCSR,ISC2);
						break;
				  case EXINT_LowLevel :
				  case EXINT_Toggle :
				  break;
			   }
			   /* Enable THe InT 0 */
			   SET_Bit(GICR,INT2);
			   break;
		 default:
		      /* Error Handle */
		      break;
		   }
	}