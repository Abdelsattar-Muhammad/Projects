/*
 * Traffic_light.c
 *
 * Created: 26/04/2023 01:36:33 م
 *  Author: Abdelsattar
 */ 


#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "TIMER.h"
#include "LED.h"
#include "data_types.h"
#include "SEVEN_SEGMENT.h"

volatile u8 counter;


int main(void)
{
	u8 green=20,yallow=10,red=10;
	LCD_Init();
	SEVEN_SEG_initi(BPORT);
	SET_BIT(DDRD,PIN6);
	SET_BIT(DDRD,PIN7);
	LED_init(APORT,PIN0);
	LED_init(APORT,PIN1);
	LED_init(APORT,PIN2);
	TIMER2_Overflow_interrupt();
	LCD_WriteSentence("Remainig Time ");
	LCD_Move_Cursor(1,15);
    while(1)
    {
		
		green=20,yallow=10,red=20;
		LED_On(APORT,PIN0);
		while(green>=1)
		{
			
				green=20;
				green=green-counter;
				LCD_Move_Cursor(1,15);
				CLR_BIT(PORTD,6);
				SET_BIT(PORTD,7);
				SEVEN_SEG_Write(BPORT,green/10);
				_delay_ms(5);
				CLR_BIT(PORTD,7);
				SET_BIT(PORTD,6);
				SEVEN_SEG_Write(BPORT,green%10);
				_delay_ms(5);
				LCD_WriteChar(green/10+48);
				LCD_WriteChar(green%10+48);
			}
			counter=0;
		while(counter<=1)
		{
			
			CLR_BIT(PORTD,6);
			CLR_BIT(PORTD,7);
			_delay_ms(200);
			SET_BIT(PORTD,6);
			SET_BIT(PORTD,7);
			_delay_ms(200);
		}
		counter=0;
		LED_Off(APORT,PIN0);
		LED_On(APORT,PIN1);
		while (yallow>=1)
		{
			
			yallow=10;
			yallow=yallow-counter;
			LCD_Move_Cursor(1,15);
			CLR_BIT(PORTD,6);
			SET_BIT(PORTD,7);
			SEVEN_SEG_Write(BPORT,yallow/10);
			_delay_ms(5);
			CLR_BIT(PORTD,7);
			SET_BIT(PORTD,6);
			SEVEN_SEG_Write(BPORT,yallow%10);
			_delay_ms(5);
			LCD_WriteChar(yallow/10+48);
			LCD_WriteChar(yallow%10+48);
		}
			counter=0;
			while(counter<=1)
			{
				
				CLR_BIT(PORTD,6);
				CLR_BIT(PORTD,7);
				_delay_ms(200);
				SET_BIT(PORTD,6);
				SET_BIT(PORTD,7);
				_delay_ms(200);
			}
			counter=0;
		LED_Off(APORT,PIN1);
		LED_On(APORT,PIN2);
		while (red>=1)
		{
			
			
			red=20;
			red=red-counter;
			LCD_Move_Cursor(1,15);
			CLR_BIT(PORTD,6);
			SET_BIT(PORTD,7);
			SEVEN_SEG_Write(BPORT,red/10);
			_delay_ms(5);
			CLR_BIT(PORTD,7);
			SET_BIT(PORTD,6);
			SEVEN_SEG_Write(BPORT,red%10);
			_delay_ms(5);
			LCD_WriteChar(red/10+48);
			LCD_WriteChar(red%10+48);
		}
		LED_Off(APORT,PIN2);
		counter=0;
		while(counter<=1)
		{
			
			CLR_BIT(PORTD,6);
			CLR_BIT(PORTD,7);
			_delay_ms(200);
			SET_BIT(PORTD,6);
			SET_BIT(PORTD,7);
			_delay_ms(200);
		}
		counter=0;
        
    }
}
ISR(TIMER2_OVF_vect)
{
	counter++;
}