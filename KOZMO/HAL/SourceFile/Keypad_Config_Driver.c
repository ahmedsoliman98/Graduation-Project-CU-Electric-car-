/*
 * Keypad_Config_Driver.c
 *
 * Created: 11/1/2020 12:45:55 PM
 *  Author: ahmedsoliman
 */ 


 #include "ATmega32A_DIO_Config.h"
 #include "ATmega32A_DIO_Config.h"
 #include "StandardDataType.h"
 #include "Keypad_Config_Driver.h"
 #include <util/delay.h>
 
 
 #define DELAY_FOR_BOUNCING (50)
 
 static unsigned char CheckData(MATRIX_COL col)
 {
	 if (DIO_pinRead(KEYPAD_REG,PINRW1))
	 {
		 _delay_ms(DELAY_FOR_BOUNCING);
		 if(DIO_pinRead(KEYPAD_REG,PINRW1))
		 {
			 return( Data[col,ROW1] );
		 }			 
	 }
	 else if (DIO_pinRead(KEYPAD_REG,PINRW2))
	 {
		 _delay_ms(DELAY_FOR_BOUNCING);
		 if(DIO_pinRead(KEYPAD_REG,PINRW2))
		 {
			 return( Data[col,ROW2] );
		 }
	 }
	 else if (DIO_pinRead(KEYPAD_REG,PINRW3))
	 {
		 _delay_ms(DELAY_FOR_BOUNCING);
		 if(DIO_pinRead(KEYPAD_REG,PINRW3))
		 {
			 return( Data[col,ROW3] );
		 }
	 }
	 else if (DIO_pinRead(KEYPAD_REG,PINRW4))
	 {
		 _delay_ms(DELAY_FOR_BOUNCING);
		 if(DIO_pinRead(KEYPAD_REG,PINRW4))
		 {
			 return( Data[col,ROW4] );
		 }
	 }
 }
 
 void keypad_Intiat (void)
 {
	 /* Set the all pins of the Keypad input  */
	 DIO_portConfiguration(KEYPAD_REG,0x00);
	 
 }
 
 
 unsigned char keypad_Read(void)
 {
	 unsigned char DataRead = 0x00;
	 /* CHECK IN THE COLUM 1 */
	 DIO_pinConfiguration(KEYPAD_REG,PINCL1,Output);
	 DIO_pinWrite(KEYPAD_REG,PINCL1,HIGH);
	 DataRead = CheckData(COL1);
	 DIO_pinConfiguration(KEYPAD_REG,PINCL1,InputFloat);
	 
	 /* CHECK IN THE COLUM 2 */
	 DIO_pinConfiguration(KEYPAD_REG,PINCL2,Output);
	 DIO_pinWrite(KEYPAD_REG,PINCL2,HIGH);
	 DataRead = CheckData(COL2);
	 DIO_pinConfiguration(KEYPAD_REG,PINCL2,InputFloat);
	 
	 /* CHECK IN THE COLUM 3 */
	 DIO_pinConfiguration(KEYPAD_REG,PINCL3,Output);
	 DIO_pinWrite(KEYPAD_REG,PINCL3,HIGH);
	 DataRead = CheckData(COL3);
	 DIO_pinConfiguration(KEYPAD_REG,PINCL3,InputFloat);
	 
	 /* CHECK IN THE COLUM 4 */
	 DIO_pinConfiguration(KEYPAD_REG,PINCL3,Output);
	 DIO_pinWrite(KEYPAD_REG,PINCL3,HIGH);
	 DataRead = CheckData(COL4);
	 DIO_pinConfiguration(KEYPAD_REG,PINCL3,InputFloat);
	 
	 return DataRead;
 }