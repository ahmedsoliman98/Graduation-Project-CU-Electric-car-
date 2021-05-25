/*
 * SectionA.c
 *
 * Created: 10/20/2020 10:38:17 PM
 *  Author: ahmedsoliman
 */ 
  
  
  #include "ATmega32A_Config.h"
  #include "ATmega32A_DIO_Config.h"
  #include "ATmega32A_Timers_Config.h"
  #include "ATmega32A_USART.h"
  #include "L298N_MotorDriver.h"
  #include "SectionA.h"
  #include <util/delay.h>

  #define Delay (5000)
  
  /* Motor Driver Input Pin to Control The Direction Of The Motor */
  MotorDriver motor = {GPIOA,PIN0, PIN1, PIN2, PIN3};
	  
 /* Set The Pin Of The Enable That Control The Speed Of The Motor Each One To The Timer To Control Each Side In Different Speed */
  TIMER_DATATYPE EnableA = {Timer0, Timer_PhaceCorrect_PWM_Mode, Timer_Fcpu_Div1024, Timer_No_Interrupt}; // connecting to the Left Side Motors
  TIMER_DATATYPE EnableB = {Timer2, Timer_PhaceCorrect_PWM_Mode, Timer_Fcpu_Div1024, Timer_No_Interrupt}; // connecting to the Right Side Motors
	
  /* Hold The Massage That Was Receive Form Bluetooth */
  unsigned char Bluetooth_Data ;
  
    void SectionA_Intit(void)
	{
		
		motor.MOTORNUM = Two_Motor;
		
		USART0.communicationMode = USART_Asyn_DoupleSpeed;
		USART0.communicationTerminal = USART_SingleProcessor;
		USART0.enableMode = USART_TxRx_Enable;
		USART0.interruptSource = USART_InterruptsDisable;
		USART0.dataFrame = USART_8bitData;
		USART0.frameControl = USART_ParityDisable_1Stop;
		USART0.baudRate = 9600;
		USART0.errorType = USART_NoError;

		USART_Intia();
		/* This Function Setup the 4 IN pin Of Motor Driver As an Output Pin and The Enable A and Enable B connecting To The Timer And Setup as Phase Correct PWM Inverted Mode */
		MotorDriver_Setup(motor,EnableA, EnableB);
	 
	}		
    void SectionA_Operate(void)
	{
		Bluetooth_Data = USART_ReadByte_Blocking();
		
		switch (Bluetooth_Data)
		{
			case 'F':
			Forward_Move();
			break;
			case 'B':
			Back_Move();
			break;
			case '1':
			Left_Move1();
			break;
			case '2':
			Left_Move2();
			break;
			case '3':
			Left_Move3();
			break;
			case '4':
			Right_Move1();
			break;
			case '5':
			Right_Move2();
			break;
			case '6':
			Right_Move3();
			break;
			default:
			STOP();
			break;
		}
	}
	
	
	void Forward_Move(void)
	{
		motor.MOVMENT = Forward;
		Motor_Direction(motor);
		Motor_Speed(EnableA, 255);
		Motor_Speed(EnableB, 255);
		_delay_ms(Delay);
		STOP();
	}

	void Back_Move(void)
	{
		motor.MOVMENT = Reverce;
		Motor_Direction(motor);
		Motor_Speed(EnableA, 255);
		Motor_Speed(EnableB, 255);
		_delay_ms(Delay);
		STOP();
	}

	void Left_Move1(void)
	{
		motor.MOVMENT = Forward;
		Motor_Direction(motor);
		Motor_Speed(EnableA, 180);
		Motor_Speed(EnableB, 255);
		_delay_ms(Delay);
		STOP();
	}
	
	void Left_Move2(void)
	{
		motor.MOVMENT = Forward;
		Motor_Direction(motor);
		Motor_Speed(EnableA, 90);
		Motor_Speed(EnableB, 255);
		_delay_ms(Delay);
		STOP();
	}
	
	void Left_Move3(void)
	{
		motor.MOVMENT = Forward;
		Motor_Direction(motor);
		Motor_Speed(EnableA, 50);
		Motor_Speed(EnableB, 255);
		_delay_ms(Delay);
		STOP();
	}

	void Right_Move1(void)
	{
		motor.MOVMENT = Forward;
		Motor_Direction(motor);
		Motor_Speed(EnableA, 255);
		Motor_Speed(EnableB, 180);
		_delay_ms(Delay);
		STOP();
	}
	
	void Right_Move2(void)
	{
		motor.MOVMENT = Forward;
		Motor_Direction(motor);
		Motor_Speed(EnableA, 255);
		Motor_Speed(EnableB, 90);
		_delay_ms(Delay);
		STOP();
	}
	
	void Right_Move3(void)
	{
		motor.MOVMENT = Forward;
		Motor_Direction(motor);
		Motor_Speed(EnableA, 255);
		Motor_Speed(EnableB, 50);
		_delay_ms(Delay);
		STOP();
	}

	void STOP (void)
	{
		motor.MOVMENT = Stop;
		Motor_Direction(motor);
		Motor_Speed(EnableA, 0);
		Motor_Speed(EnableB, 0);
	}





