/*
 * L298N_MotorDriver.c
 *
 * Created: 10/10/2020 1:22:45 PM
 *  Author: ahmedsoliman
 */ 
  
  
  #include "ATmega32A_Config.h"
  #include "ATmega32A_DIO_Config.h"
  #include "ATmega32A_Timers_Config.h"
  #include "L298N_MotorDriver.h"
  
  
  
  
  
  void MotorDriver_Setup(MotorDriver PINS, TIMER_DATATYPE EN1, TIMER_DATATYPE EN2)
  {
	  DIO_pinConfiguration(PINS.DriverPORT,PINS.MOTOR_INA1,Output);
	  DIO_pinConfiguration(PINS.DriverPORT,PINS.MOTOR_INA2,Output);
	  DIO_pinConfiguration(PINS.DriverPORT,PINS.MOTOR_INA3,Output);
	  DIO_pinConfiguration(PINS.DriverPORT,PINS.MOTOR_INA4,Output);
	  TIMER_INTIATE(EN1);
	  TIMER_INTIATE(EN2);
	  /* Setup the PWM Signal Get Out From The OCR0,2 as Inverted Mode and the Initial Value of the Compare Match is 0 */
	  TIMER_WAVEGEN_PHACECORRECTPWM(EN1, ClearUp_SetDowen_PCPWM, 0);
	  TIMER_WAVEGEN_PHACECORRECTPWM(EN2, ClearUp_SetDowen_PCPWM, 0);
  }
  
  
  
  void Motor_Direction(MotorDriver motordirection)
  {
	  switch (motordirection.MOTORNUM)
	  {
		  case Two_Motor :
		  /* in This Case Motor A is the Back Motor that give The Main Motion To The Robot And Th Motor B is Direction Motor */
		        switch(motordirection.MOVMENT)
				{
				    case Forward:
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA1,HIGH);
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA2,LOW);
						 DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA3,HIGH);
						 DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA4,LOW);
						 break;
					case Reverce:
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA1,LOW);
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA2,HIGH);
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA3,LOW);
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA4,HIGH);
						 break;
					case Stop:
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA1,LOW);
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA2,LOW);
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA3,LOW);
					     DIO_pinWrite(motordirection.DriverPORT,motordirection.MOTOR_INA4,LOW);
						 break;
					default:
					       /* Handle The Error Function */
						   break;
				}	
	      default:
	             /* Handle The Error Function */
	             break;			 				
	  }		  
  }
  
  
  void Motor_Speed(TIMER_DATATYPE EnableX, char Speed_Value)
  {
	  switch(EnableX.timer_Number)
	  {
		  case Timer0 :
		               OCR0 = Speed_Value ;
					   break;
		  case Timer2 :
		              OCR2 = Speed_Value;
					  break;
		  default:
		        /* Handle Error */
				break; 
	  }		  
  }