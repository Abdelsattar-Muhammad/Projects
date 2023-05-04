/*
 * MCU2.c
 *
 * Created: 02/05/2023 11:29:33 م
 *  Author: Abdelsattar
 */ 


#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "SPI.h"
#include "LCD.h"
#include "data_types.h"
int main(void)
{
	u8 data_recive;
	SPI_Init_Slave();
	LCD_Init();
	LCD_WriteSentence("Enter Data");
	LCD_Move_Cursor(2,1);
   	while(1)
		{
			data_recive=SPI_Slave_Receive_Byte();
			if (data_recive!='C') // 'C' == C in keypad we will use it to clear screen
			{
				LCD_WriteChar(data_recive);
				
			} 
			else
			{
				LCD_Clear();
				LCD_WriteSentence("Enter Data");
				LCD_Move_Cursor(2,1);
			}
			
		}

	
    
}