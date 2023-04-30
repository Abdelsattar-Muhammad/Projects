/*
 * main.c
 *
 * Created: 01/05/2023 12:51:01 ص
 *  Author: Abdelsattar
 */ 



#include <avr/io.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "LCD.h"
#include "Ultrasonic.h"
int main(void)
{
	u16 distance;
	LCD_Init();
	Ultrasonic_init();


    while(1)
    {
	
		Ultrasonic_Trigger();
		_delay_us(10);
		distance=Ultrasonic_Read();
	
		if (distance<80)
		{
			LCD_Clear();
			_delay_ms(300);
			LCD_WriteSentence("Distance=");
			LCD_WriteChar(distance/10+48);
			LCD_WriteChar(distance%10+48);
			LCD_WriteSentence("cm");
			_delay_ms(1000);
		}
		else{
			LCD_Clear();
			LCD_WriteSentence("Out of range");
			_delay_ms(1000);
			
		}
		_delay_ms(1000);
		}

			
    }	
	