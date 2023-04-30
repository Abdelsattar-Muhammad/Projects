/*
 * LED.c
 *
 * Created: 14/04/2023 05:23:46 ص
 *  Author: Abdelsattar
 */ 
#include "DIO.h"


void LED_init(u8 portName,u8 pinNumber)//initialization pin as output at given port
{
	DIO_vSetPinDir(portName,pinNumber,OUTPUT);
}//end function
void LED_On(u8 portName,u8 pinNumber)//turn ON LED
{
	DIO_vSetPinValue(portName,pinNumber,HIGH);
}//end function
void LED_Off(u8 portName,u8 pinNumber)//turn off LED
{
	DIO_vSetPinValue(portName,pinNumber,LOW);
}//end function
void LED_Toggle(u8 portName,u8 pinNumber)//toggle led
{
	DIO_vTogglePin(portName,pinNumber);
}//end function