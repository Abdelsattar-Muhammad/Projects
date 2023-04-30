/*
 * Real_Time_Clock.c
 *
 * Created: 28/04/2023 01:09:06 م
 *  Author: Abdelsattar
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "TIMER.h"
#include "data_types.h"
#include "SEVEN_SEGMENT.h"
#include "std_macro.h"
#include "Real Time Clock.h"
#include "External Interrupt.h"
#include "LCD.h"
#include "KEYPAD.h"
volatile u8 seconds=0;
#include "DIO.h"
int main(void)
{
	u8 minuts=0,hours=0,first_digit,second_digit; 
	SEVEN_SEG_initi(DATA_PORT);
	TIMER2_Overflow_interrupt();
	Enable_PINS_Dir(ENABLE_PORT);
	External_interrupt_Init(INT0);
	External_interrupt_Init(INT1);
	LCD_Init();
	Keypad_init();
	LCD_WriteSentence("To adjust Time");
	LCD_Move_Cursor(2,1);
	LCD_WriteSentence("Press 1");
	while(1)
	{
		
		if (Keypad_Read()!=NOT_PRESSED)
		{
			if (Keypad_Read()=='1')
			{
				LCD_Clear();
				LCD_WriteSentence("seconds --");
				_delay_ms(250);
				LCD_Move_Cursor(1,9);
				do 
				{
					first_digit=Keypad_Read();
					} while (first_digit==NOT_PRESSED);
				LCD_WriteChar(first_digit);
				_delay_ms(500);
				do
				{
					second_digit=Keypad_Read();
				} while (second_digit==NOT_PRESSED);
				LCD_WriteChar(second_digit);
				_delay_ms(500);
				
				seconds=(first_digit-48)*10+(second_digit-48);
				
				LCD_Clear();
				LCD_WriteSentence("minuts --");
				LCD_Move_Cursor(1,8);
				_delay_ms(500);
				do
				{
					first_digit=Keypad_Read();
				} while (first_digit==NOT_PRESSED);
				LCD_WriteChar(first_digit);
				_delay_ms(500);
				do
				{
					second_digit=Keypad_Read();
				} while (second_digit==NOT_PRESSED);
				LCD_WriteChar(second_digit);
				_delay_ms(500);
				minuts=(first_digit-48)*10+(second_digit-48);
				LCD_Clear();
				LCD_WriteSentence("hours --");
				_delay_ms(500);
				LCD_Move_Cursor(1,7);
				do
				{
					first_digit=Keypad_Read();
				} while (first_digit==NOT_PRESSED);
				LCD_WriteChar(first_digit);
				_delay_ms(500);
				do
				{
					second_digit=Keypad_Read();
				} while (second_digit==NOT_PRESSED);
				LCD_WriteChar(second_digit);
				_delay_ms(500);
				hours=(first_digit-48)*10+(second_digit-48);
				_delay_ms(500);
				LCD_Clear();
				
				LCD_WriteSentence("To adjust Time");
				LCD_Move_Cursor(2,1);
				LCD_WriteSentence("Press 1");
				
			} 
			else
			{
				LCD_Clear();
				_delay_ms(200);
				LCD_WriteSentence("Wrong Choise");
				_delay_ms(500);
				LCD_Clear();
				
				LCD_WriteSentence("To adjust Time");
				LCD_Move_Cursor(2,1);
				LCD_WriteSentence("Press 1");
				
			}
			
		}
		//Set First 7-Segment
		Disable_PIN(EN1);
		Enable_PIN(EN2);
		Enable_PIN(EN3);
		Enable_PIN(EN4);
		Enable_PIN(EN5);
		Enable_PIN(EN6);
		SEVEN_SEG_Write(DATA_PORT,seconds%10);
		_delay_ms(5);
		//Set Second 7-Segment
		Disable_PIN(EN2);
		Enable_PIN(EN1);
		Enable_PIN(EN3);
		Enable_PIN(EN4);
		Enable_PIN(EN5);
		Enable_PIN(EN6);
		SEVEN_SEG_Write(DATA_PORT,seconds/10);
		_delay_ms(5);
		//Set Third 7-Segment
		Disable_PIN(EN3);
		Enable_PIN(EN1);
		Enable_PIN(EN2);
		Enable_PIN(EN4);
		Enable_PIN(EN5);
		Enable_PIN(EN6);
		SEVEN_SEG_Write(DATA_PORT,minuts%10);
		_delay_ms(5);
		//Set Fourth 7-Segment
		Disable_PIN(EN4);
		Enable_PIN(EN1);
		Enable_PIN(EN2);
		Enable_PIN(EN3);
		Enable_PIN(EN5);
		Enable_PIN(EN6);
		SEVEN_SEG_Write(DATA_PORT,minuts/10);
		_delay_ms(5);
		//Set Fifth 7-Segment
		Disable_PIN(EN5);
		Enable_PIN(EN1);
		Enable_PIN(EN2);
		Enable_PIN(EN3);
		Enable_PIN(EN4);
		Enable_PIN(EN6);
		SEVEN_SEG_Write(DATA_PORT,hours%10);
		_delay_ms(5);
		//Set Sexth 7-Segment
		Disable_PIN(EN6);
		Enable_PIN(EN1);
		Enable_PIN(EN2);
		Enable_PIN(EN3);
		Enable_PIN(EN4);
		Enable_PIN(EN5);
		SEVEN_SEG_Write(DATA_PORT,hours/10);
		_delay_ms(5);
		
		if (seconds>=60)
		{
			seconds=0;
			minuts++;
		}
		if (minuts>=60)
		{
			minuts=0;
			hours++;
		}
		if (hours>=24)
		{
			hours=0;
		}
		
	}	
}


ISR(TIMER2_OVF_vect)
{
		seconds++;
	}
	
ISR(INT0_vect)
{
CLR_BIT(TIMSK,TOIE2);	
}	
ISR(INT1_vect)
{
	SET_BIT(TIMSK,TOIE2);
}