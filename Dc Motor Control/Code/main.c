/*
 * MOTOR.c
 *
 * Created: 01/05/2023 02:20:54 ص
 *  Author: Abdelsattar
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "Button.h"
#include "data_types.h"
#include "std_macro.h"
#include "DIO.h"
#include "DC_Motor.h"
int main(void)
{
	Dc_Motor_init();
    while(1)
    {
		if (Button_u8Read(CONTROLS_PINS,FRONT_PIN)==0)
		{
			_delay_ms(250);
			do 
			{
				Dc_Motor_On(FRONT); //TURN ON MOTOR TO FRONT
				
			} while (Button_u8Read(CONTROLS_PINS,FRONT_PIN)==0);
			Dc_Motor_Off(); //TURN ON MOTOR
		}//END IF 
		
		else if(Button_u8Read(CONTROLS_PINS,BACK_PIN)==0)
		{
			_delay_ms(250);
			do
			{
				Dc_Motor_On(BACK); //TURN ON MOTOR TO BACK
				
			} while (Button_u8Read(CONTROLS_PINS,BACK_PIN)==0);
			Dc_Motor_Off(); //TURN ON MOTOR
		}//END ELSE IF
		else if(Button_u8Read(CONTROLS_PINS,RIGHT_PIN)==0)
		{
			_delay_ms(250);
			do
			{
				Dc_Motor_On(RIGHT); //TURN ON MOTOR TO RIGHT
				
			} while (Button_u8Read(CONTROLS_PINS,RIGHT_PIN)==0);
			Dc_Motor_Off(); //TURN ON MOTOR
		}//END ELSE IF
		else if(Button_u8Read(CONTROLS_PINS,LEFT_PIN)==0)
		{
			_delay_ms(250);
			do
			{
				Dc_Motor_On(LEFT); //TURN ON MOTOR TO LEFT
				
			} while (Button_u8Read(CONTROLS_PINS,LEFT_PIN)==0);
			Dc_Motor_Off(); //TURN ON MOTOR
		}//END ELSE IF
		
	}        
}
