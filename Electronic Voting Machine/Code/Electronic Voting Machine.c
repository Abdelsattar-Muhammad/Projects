/*
 * Electronic_Voting_Machine.c
 *
 * Created: 22/04/2023 07:16:38 م
 *  Author: Abdelsattar
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO.h"
#include "Button.h"
#include "data_types.h"
#include <avr/io.h>
#define NOT_PRESSED 0xFF
int main(void)
{
	LCD_Init();
	LCD_WriteSentence("A=000 Votes");
	LCD_Move_Cursor(2,1);
	LCD_WriteSentence("B=000 Votes");
	LCD_Move_Cursor(3,1);
	LCD_WriteSentence("C=000 Votes");
	LCD_Move_Cursor(4,1);
	LCD_WriteSentence("D=000 Votes");
	Button_Pullup_initi(BPORT,PIN0);// Voting to A
	Button_Pullup_initi(BPORT,PIN1);// Voting to B
	Button_Pullup_initi(BPORT,PIN2);// Voting to C
	Button_Pullup_initi(BPORT,PIN3);// Voting to D
	Button_Pullup_initi(BPORT,PIN4);//  to REST all Voting
	u8 x=NOT_PRESSED,A=0,B=0,C=0,D=0;
    while(1)
    {
		if (Button_u8Read(BPORT,PIN0)==0)
		{
			A++;
			LCD_Move_Cursor(1,3);
			LCD_WriteChar((A/100)+48);
			LCD_WriteChar((A/10)%10+48);
			LCD_WriteChar((A%10)+48);
			
		}
		else if (Button_u8Read(BPORT,PIN1)==0)
		{
			B++;
			LCD_Move_Cursor(2,3);
			LCD_WriteChar((B/100)+48);
			LCD_WriteChar((B/10)%10+48);
			LCD_WriteChar((B%10)+48);
		}
		else if (Button_u8Read(BPORT,PIN2)==0)
		{
			C++;
			LCD_Move_Cursor(3,3);
			LCD_WriteChar((C/100)+48);
			LCD_WriteChar((C/10)%10+48);
			LCD_WriteChar((C%10)+48);
		}
		else if (Button_u8Read(BPORT,PIN3)==0)
		{
			D++;
			LCD_Move_Cursor(4,3);
			LCD_WriteChar((D/100)+48);
			LCD_WriteChar((D/10)%10+48);
			LCD_WriteChar((D%10)+48);
		}
		else if (Button_u8Read(BPORT,PIN4)==0)
		{
			LCD_Clear();
			LCD_WriteSentence("A=000 Votes");
			LCD_Move_Cursor(2,1);
			LCD_WriteSentence("B=000 Votes");
			LCD_Move_Cursor(3,1);
			LCD_WriteSentence("C=000 Votes");
			LCD_Move_Cursor(4,1);
			LCD_WriteSentence("D=000 Votes");
			A=0;
			B=0;
			C=0;
			D=0;
			}
		_delay_ms(200);
		
		
         
    }
}