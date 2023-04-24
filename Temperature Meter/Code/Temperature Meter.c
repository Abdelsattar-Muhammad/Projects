/*
 * Temperature_Meter.c
 *
 * Created: 24/04/2023 08:17:50 م
 *  Author: Abdelsattar
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "data_types.h"
#include "ADC.h"
#include "LCD.h"

int main(void)
{
	LCD_Init();
	ADC_init();
	u16 temp;
	LCD_WriteSentence("Temperature=");
	
    while(1)
    {
		temp=ADC_Read()*.25;
		
		if (temp<10)
		{
			LCD_Move_Cursor(1,13);
			LCD_WriteChar(temp+48);
			LCD_WriteChar(0xDF);
			LCD_WriteChar('C');
			LCD_WriteChar(0x20);
		} 
		else
		{
			LCD_Move_Cursor(1,13);
			LCD_WriteChar(temp/10+48);
			LCD_WriteChar(temp%10+48);
			LCD_WriteChar(0xDF);
			LCD_WriteChar('C');
		}
		
        
    }
}