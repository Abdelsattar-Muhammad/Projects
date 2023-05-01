/*
 * DC_Motor.c
 *
 * Created: 01/05/2023 01:03:24 م
 *  Author: Abdelsattar
 */ 


#include <avr/io.h>
#include "DC_Motor.h"
#include "DIO.h"
#include "Button.h"
void Dc_Motor_init(void)
{
	DIO_vSetPortDir(DC_MOTOR_PORT,0x3F);//0b00111111
	Button_Pullup_initi(CONTROLS_PINS,FRONT_PIN);
	Button_Pullup_initi(CONTROLS_PINS,BACK_PIN);
	Button_Pullup_initi(CONTROLS_PINS,RIGHT_PIN);
	Button_Pullup_initi(CONTROLS_PINS,LEFT_PIN);
}

void Dc_Motor_On(u8 Direction)
{	
	DIO_vSetPortValue(DC_MOTOR_PORT,Direction);
}
void Dc_Motor_Off(void)
{
	DIO_vSetPortValue(DC_MOTOR_PORT,0x00);
}