/*
 * MCU1.c
 *
 * Created: 02/05/2023 11:24:21 م
 *  Author: Abdelsattar
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "UART.h"
#include "KEYPAD.h"
#include "data_types.h"
int main(void)
{
	u8 val;
	UART_vInit(9600);
	Keypad_init();
	 while(1)
    {
		do 
		{
			val=Keypad_Read();
		} while (val==NOT_PRESSED);
		UART_vSendChar(val);
		_delay_ms(250); //delay to avoid debouncing
       
    }
}