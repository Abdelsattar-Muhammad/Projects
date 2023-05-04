/*
 * MCU2.c
 *
 * Created: 04/05/2023 5:09:33 م
 *  Author: Abdelsattar
 */ 

	
#define	 F_CPU 8000000UL
#include <util/delay.h>
#include "I2C.h"
#include "LCD.h"
#include <avr/io.h>
#include "data_types.h"
int main(void)
{
	LCD_Init();
	u8 data_recive=0;
	LCD_WriteSentence("Enter Data");
	LCD_Move_Cursor(2,1);
	I2C_Set_address(0b11001100);
	while(1)
		{
			data_recive=I2C_Read_Data();
		
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