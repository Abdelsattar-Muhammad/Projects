/*
 * The_Safe.c
 *
 * Created: 23/04/2023 04:28:14 م
 *  Author: Abdelsattar
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "DIO.h"
#include "data_types.h"
#include "EEPROM.h"
#include "LCD.h"
#include "KEYPAD.h"
#define MAX_TRIES 3
#define DEFULT 0xFF
int main(void)
{
	LCD_Init();
	Keypad_init();
	
	u16 EEPROM_LOCATION[6]={0x10,0x11,0x12,0x13,0x14,0x15};
	u16 EEPROM_STATUS=0x09;
	u8 flag=0,i,check_pass=0,tries=MAX_TRIES ,val=NOT_PRESSED,arr[6]={0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
	
	if (EEPROM_Read(EEPROM_STATUS)==DEFULT)
	{
		LCD_WriteSentence("Set Passowrd :");
		LCD_Move_Cursor(2,1);
		for (i=0;i<=5;i++)
		{
			do 
			{
				val=Keypad_Read();	
				
			} while (val==NOT_PRESSED);
			LCD_WriteChar(val);
			_delay_ms(500);
			LCD_Move_Cursor(2,1+i);
			LCD_WriteChar('*');
			EEPROM_Write(EEPROM_LOCATION[i],val);
		} //end for
		EEPROM_Write(EEPROM_STATUS,0x00);
	}//end if
	while(flag==0)
	{
		LCD_Clear();
		_delay_ms(100);
		LCD_WriteSentence("Check Passowrd :");
		LCD_Move_Cursor(2,1);
		for (i=0;i<=5;i++)
		{
			do
			{
				arr[i]=Keypad_Read();
				
			} while (arr[i]==NOT_PRESSED);
			LCD_WriteChar(arr[i]);
			_delay_ms(500);
			LCD_Move_Cursor(2,1+i);
			LCD_WriteChar('*');
		} //end for
		
		for(i=0;i<=5;i++)
		{
			if (arr[i]==EEPROM_Read(EEPROM_LOCATION[i]))
			{
				check_pass++;
			}
			else
			{
				check_pass=0;
			}
			
		}
		if (check_pass==6 && tries>0)
		{
			LCD_Clear();
			_delay_ms(100);
			LCD_WriteSentence("Right Passowrd ");
			LCD_Move_Cursor(2,1);
			LCD_WriteSentence("Safe Opened");
			flag=1;
		}
		else
		{
			tries--;
			if (tries>0)
			{	LCD_Clear();
				_delay_ms(100);
				LCD_WriteSentence("Wrong Passowrd ");
				_delay_ms(200);
				LCD_Move_Cursor(2,1);
				LCD_WriteSentence("Tries Remain=");
				LCD_Move_Cursor(2,14);
				LCD_WriteChar(tries+48);
				_delay_ms(1000);
			}
			else
			{
				LCD_Clear();
				_delay_ms(100);
				LCD_WriteSentence("Wrong Passowrd ");
				_delay_ms(250);
				LCD_Clear();
				LCD_WriteSentence("Safe Closed ");
				LCD_Move_Cursor(2,1);
				LCD_WriteSentence("Wait ");
				
				for (i=10;i>=1;i--)
				{
					LCD_Move_Cursor(2,6);
					LCD_WriteChar((i/10)+48);
					LCD_WriteChar(i%10+48);
					_delay_ms(1000);
					tries=MAX_TRIES;
				}
				//flag=1;
			}
			
		}
	
	}
	
	
    while(1)
    {
		
       
    }
}