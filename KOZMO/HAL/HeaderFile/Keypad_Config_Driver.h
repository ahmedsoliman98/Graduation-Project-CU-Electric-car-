
/*
 *
 * @file <Keypad_Config_Driver.h>
 * @brief <This is a Header File for theKeypad Driver Which Eanbles User to use the Keypad Module>
 *
 * Preprocessor Driver To Configure the Keypad 
 * @APIS
 *					  Keypad_Setup()		< Setup Keypad port and pin via MCAL >
 *						returns   void 
 *						Takes	  void 
 *					  Keypad_Read()	 <allow the user to send data from the keypad to Mc>	
 *                      returns   unsigned char
 *                      Takes         void
 * 	
 * @authors <ahmedsoliman>
 * @date <11/1/2020 12:45:55 PM>
 *
 */



#ifndef KEYPAD_CONFIG_DRIVER_H_
#define KEYPAD_CONFIG_DRIVER_H_


  /* Define The columns and Rows used in the Array */
   typedef enum
   {
	    COL1 ,
		COL2 ,
		COL3 ,
		COL4 ,
   }MATRIX_COL;		
   
   typedef enum
   {
	   ROW1 ,
	   ROW2 ,
	   ROW3 ,
	   ROW4 ,
   }MATRIX_ROW;
   
   /* HW connection */
   #define PINRW1    PIN0
   #define PINRW2    PIN1
   #define PINRW3    PIN2
   #define PINRW4    PIN3
   
   #define PINCL1    PIN4
   #define PINCL2    PIN5
   #define PINCL3    PIN6
   #define PINCL4    PIN7
   
   #define KEYPAD_REG  GPIOA
   
   /* Keypad Matrix Data 4 x 4 */
   extern unsigned char Data[4][4] = {'1','2','3','A',
									  '4','5','6','B',
									  '7','8','9','C',
									  '*','0','#','D'};
							 
	void keypad_Intiat (void);
	unsigned char keypad_Read(void);


#endif /* KEYPAD_CONFIG_DRIVER_H_ */