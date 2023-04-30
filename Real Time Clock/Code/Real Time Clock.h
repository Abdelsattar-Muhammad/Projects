/*
 * Real_Time_Clock.h
 *
 * Created: 28/04/2023 01:20:44 م
 *  Author: Abdelsattar
 */ 


#ifndef REAL TIME CLOCK_H_
#define REAL TIME CLOCK_H_
#include "DIO.h"

#define DATA_PORT	APORT 
#define ENABLE_PORT CPORT
#define EN1 0
#define EN2 1
#define EN3 2
#define EN4 3
#define EN5 4
#define EN6 5

void Enable_PINS_Dir(u8 Enable_Port )
{
	DIO_vSetPortDir(ENABLE_PORT,0b00111111);
}

void Enable_PIN(u8 PinNumber)
{
	DIO_vSetPinValue(ENABLE_PORT,PinNumber,HIGH);
}
void Disable_PIN(u8 PinNumber)
{
	DIO_vSetPinValue(ENABLE_PORT,PinNumber,LOW);
}

#endif /* REAL TIME CLOCK_H_ */