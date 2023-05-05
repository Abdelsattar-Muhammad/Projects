/*
 * I2C_with_EEPROM.c
 *
 * Created: 05/05/2023 04:47:11 م
 *  Author: Abdelsattar
 */ 
 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "External EEPRROM.h"
#include <avr/io.h>
#include "data_types.h"
#include "LCD.h"
int main(void)
{	u8 x;
	LCD_Init();
	
	External_EEPROM_Write(0b11100011100,9);
	
	x=External_EEPROM_Read(0b11100011100);
	LCD_WriteChar(x+48);
	while(1)
	{
		
	}
	
	}