/*
 * MCU1.c
 *
 * Created: 04/05/2023 5:06:12 م
 *  Author: Abdelsattar
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>

#include "I2C.h"
#include "KEYPAD.h"
#include <avr/io.h>
#include "data_types.h"
int main(void)
{	
		Keypad_init();
			u8 val=0;
			I2C_vInit(100000);
		while(1)
		{
		
		do 
		{
			val=Keypad_Read();
		} while (val==NOT_PRESSED);
		_delay_ms(250); //delay to avoid debouncing
		I2C_Start();
		I2C_Write_address(0b11001100);
		I2C_Write_Data(val);
		I2C_Stop();
        
        }

		}