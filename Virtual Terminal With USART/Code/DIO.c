/*
 * DIO.c
 * FOR ATMEGA32
 * Created: 12/04/2023 05:07:51 م
 *  Author: Abdelsattar
 */ 
#include "DIO.h"

void DIO_vSetPinDir(u8 PortName,u8 PinNumber,u8 Direction )
{
	if (OUTPUT==Direction)
	{
		switch(PortName)
		{
			case APORT:
			SET_BIT(DDRA,PinNumber);
			break;
			case BPORT:
			SET_BIT(DDRB,PinNumber);
			break;
			case CPORT:
			SET_BIT(DDRC,PinNumber);
			break;
			case DPORT:
			SET_BIT(DDRD,PinNumber);
			break;
			
		}//end switch
		
		
	} //end if 
	else
	{
		switch(PortName)
		{
			case APORT:
			CLR_BIT(DDRA,PinNumber);
			break;
			case BPORT:
			CLR_BIT(DDRB,PinNumber);
			break;
			case CPORT:
			CLR_BIT(DDRC,PinNumber);
			break;
			case DPORT:
			CLR_BIT(DDRD,PinNumber);
			break;
			}//end switch
		}//end else				
}//end Function

void DIO_vSetPortDir(u8 PortName,u8 Direction )
{
		switch(PortName)
		{
			case APORT:
			DDRA=Direction;
			break;
			case BPORT:
			DDRB=Direction;
			break;
			case CPORT:
			DDRC=Direction;
			break;
			case DPORT:
			DDRD=Direction;
			break;
			
		}//end switch
		
}//end Function

void DIO_vSetPinValue(u8 PortName,u8 PinNumber,u8 value)
{
	if (HIGH==value)
	{
		switch(PortName)
		{
			case APORT:
			SET_BIT(PORTA,PinNumber);
			break;
			case BPORT:
			SET_BIT(PORTB,PinNumber);
			break;
			case CPORT:
			SET_BIT(PORTC,PinNumber);
			break;
			case DPORT:
			SET_BIT(PORTD,PinNumber);
			break;
			
		}//end switch
		
		
	} //end if
	else
	{
		switch(PortName)
		{
			case APORT:
			CLR_BIT(PORTA,PinNumber);
			break;
			case BPORT:
			CLR_BIT(PORTB,PinNumber);
			break;
			case CPORT:
			CLR_BIT(PORTC,PinNumber);
			break;
			case DPORT:
			CLR_BIT(PORTD,PinNumber);
			break;
		}//end switch
	}//end else
}//end Function


void DIO_vSetPortValue(u8 PortName,u8 value)
{
		switch(PortName)
		{
			case APORT:
			PORTA=value;
			break;
			case BPORT:
			PORTB=value;
			break;
			case CPORT:
			PORTC=value;
			break;
			case DPORT:
			PORTD=value;
			break;
			
		}//end switch
		
}//end Function


u8 DIO_u8GetPortValue(u8 portName)
{
	u8 value=0;
	switch(portName)
	{
		case APORT:
		value=PINA;
		break;
		case BPORT:
		value=PINB;
		break;
		case CPORT:
		value=PINC;
		break;
		case DPORT:
		value=PIND;
		break;
	}//end switch
	return value;
}//end function

u8 DIO_u8GetPinValue(u8 portName,u8 pinNumber)
{
	u8 value=0;
	switch(portName)
	{
		case APORT:
		value=READ_BIT(PINA,pinNumber);
		break;
		case BPORT:
		value=READ_BIT(PINB,pinNumber);
		break;
		case CPORT:
		value=READ_BIT(PINC,pinNumber);
		break;
		case DPORT:
		value=READ_BIT(PIND,pinNumber);
		break;
	}//end switch
	return value;
}//end function


void DIO_vSetPortHighNibbleDir(u8 portName,u8 direction)
{
	if (OUTPUT==direction)
	{
		switch (portName)
		{
		case APORT:
		DDRA|=0xF0;
		break;
		case BPORT:
		DDRB|=0xF0;
		break;
		case CPORT:
		DDRC|=0xF0;
		break;
		case DPORT:
		DDRD|=0xF0;
		break;
		
		}//end switch
		
	} //end if
	else
	{
		switch (portName)
		{
			case APORT:
			DDRA&=0x0F;
			break;
			case BPORT:
			DDRB&=0x0F;
			break;
			case CPORT:
			DDRC&=0x0F;
			break;
			case DPORT:
			DDRD&=0x0F;
			break;
			}//end switch
	}//end else	
}//end function
void DIO_vSetPortLowNibbleDir(u8 portName,u8 direction)
{
	if (OUTPUT==direction)
	{
		switch (portName)
		{
			case APORT:
			DDRA|=0x0F;
			break;
			case BPORT:
			DDRB|=0x0F;
			break;
			case CPORT:
			DDRC|=0x0F;
			break;
			case DPORT:
			DDRD|=0x0F;
			break;
			
		}//end switch
		
	} //end if
	else
	{
		switch (portName)
		{
			case APORT:
			DDRA&=0xF0;
			break;
			case BPORT:
			DDRB&=0xF0;
			break;
			case CPORT:
			DDRC&=0xF0;
			break;
			case DPORT:
			DDRD&=0xF0;
			break;
		}//end switch
		
	}//end else
		}	//end function
		
void DIO_vSetPortHighNibbleValue(u8 portName,u8 value)
{
		switch(portName)
		{
			case APORT:
			PORTA=(PORTA&0x0F)|(0xF0&value<<4);
			break;
			case BPORT:
			PORTB=(PORTB&0x0F)|(0xF0&value<<4);
			break;
			case CPORT:
			PORTC=(PORTC&0x0F)|(0xF0&value<<4);
			break;
			case DPORT:
			PORTD=(PORTD&0x0F)|(0xF0&value<<4);
			break;
		}//end switch
	
}		//end function
void DIO_vSetPortLowNibbleValue(u8 portName,u8 value)
{
	switch(portName)
	{
		case APORT:
		PORTA=(PORTA&0xF0)|(0x0F&value);
		break;
		case BPORT:
		PORTB=(PORTB&0xF0)|(0x0F&value);
		break;
		case CPORT:
		PORTC=(PORTC&0xF0)|(0x0F&value);
		break;
		case DPORT:
		PORTD=(PORTD&0xF0)|(0x0F&value);
		break;
	}//end switch
	
}		//end function

void DIO_vSetPullupPin(u8 portName,u8 pinNumber)
{
	switch(portName)
	{
		case APORT:
		CLR_BIT(DDRA,pinNumber);
		SET_BIT(PORTA,pinNumber);
		break;
		case BPORT:
		CLR_BIT(DDRB,pinNumber);
		SET_BIT(PORTB,pinNumber);
		break;
		case CPORT:
		CLR_BIT(DDRC,pinNumber);
		SET_BIT(PORTC,pinNumber);
		break;
		case DPORT:
		CLR_BIT(DDRD,pinNumber);
		SET_BIT(PORTD,pinNumber);
		break;
	}//end switch
	
}		//end function
void DIO_vTogglePin(u8 portName,u8 pinNumber)
{
	switch(portName)
	{
		case APORT:
		TOGGLE_BIT(PORTA,pinNumber);
		break;
		case BPORT:
		TOGGLE_BIT(PORTB,pinNumber);
		break;
		case CPORT:
		TOGGLE_BIT(PORTC,pinNumber);
		break;
		case DPORT:
		TOGGLE_BIT(PORTD,pinNumber);
		break;
	}//end switch
	
}		//end function