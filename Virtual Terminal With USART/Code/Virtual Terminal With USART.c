/*
 * Virtual_Terminal_With_USART.c
 *
 * Created: 03/05/2023 12:48:58 ص
 *  Author: Abdelsattar
 */ 



#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "UART.h"
#include "LCD.h"
#include "data_types.h"
int main(void)
{
	u8 data_recive;
	UART_vInit(9600);		
	LCD_Init();
	LCD_WriteSentence("Enter Data");
	LCD_Move_Cursor(2,1);
   
		while(1)
		{
			data_recive=UART_u8ReciveChar();
			if (data_recive==0x08) //if user Enter Back Space We will delete last character entered
			{
				LCD_WriteCommand(0x04); //shift cursor to left
				LCD_WriteCommand(0x10);	//shift cursor position to left
				LCD_WriteChar(0x20);	// write ' ' == Noting to delete character
				LCD_WriteCommand(0x06); //shift cursor to left again
				LCD_WriteCommand(0x14); //shift cursor position to left again
			} 
			else
			{
				
				LCD_WriteChar(data_recive);
			}
			
			
		
			
		}
	
	
    
}