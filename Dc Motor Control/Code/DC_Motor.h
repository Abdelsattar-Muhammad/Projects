/*
 * DC_Motor.h
 *
 * Created: 01/05/2023 01:03:48 م
 *  Author: Abdelsattar
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "data_types.h"
#include "DIO.h"

#define DC_MOTOR_PORT CPORT
#define IN1 0
#define IN2 1
#define EN1 2
#define IN3 3
#define IN4 4
#define EN2 5

#define CONTROLS_PINS DPORT
#define FRONT_PIN 0
#define BACK_PIN  1
#define RIGHT_PIN 2
#define LEFT_PIN  3

#define FRONT 0b00110110
#define	BACK  0b00101101
#define RIGHT 0b00000110
#define LEFT  0b00101000
void Dc_Motor_init(void);

void Dc_Motor_On(u8 Direction);

void Dc_Motor_Off(void);
#endif /* DC_MOTOR_H_ */