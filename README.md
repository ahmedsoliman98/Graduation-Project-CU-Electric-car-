# Graduation-Project-CU-Electric-car-
The main control unit of the fully electric car

 the project is to make a proto type to the fylly electrical car with feature of the self driving using the image processin so 
 we divide the project into to stages one is the driver case in this case we make a simulation to the manule case driving is to control the casr using a mobile application so the control
 unit have the UART communication protocol driver to make it able to communicate with the mobile using Bluetooth module 
 
 the Secound stage is the autonomous driving this case is used a real concurese feature by make another microcontroller "rasberry pi " responsible for the image processing the it 
 send the data to our main unit ATmega32A to dicide the motion function 
 
 motion function is divided to many varite in the speed depend on the data recieve from the other microcontroller control unit decide which one to opreate 
 forward and reverce unction have the car full speed in case of autonomous but in the left and right it divided into a three case for each direction each case different in the angle 
 that happen used PWM output differen in eac  side of motor using Timer 0 & 2 
