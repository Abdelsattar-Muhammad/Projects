/*
 * MCU1.c
 *
 * Created: 02/05/2023 11:24:21 م
 *  Author: Abdelsattar
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "SPI.h"
#include "KEYPAD.h"
#include "data_types.h"
int main(void)
{
	u8 val;
	SPI_Init_Master();
	Keypad_init();
	 while(1)
    {
		do 
		{
			val=Keypad_Read();
		} while (val==NOT_PRESSED);
		SPI_Master_Send_Byte(val);
		_delay_ms(250); //delay to avoid debouncing
       
    }
}