﻿/*
 * KEYPAD.h
 *
 * Created: 22/04/2023 06:31:08 م
 *  Author: Abdelsattar
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#define KEYPAD_PORT APORT
#define NOT_PRESSED 0xFF
#include "DIO.h"
#include "data_types.h"
u8 Keypad_Read(void);
void Keypad_init(void);



#endif /* KEYPAD_H_ */