/*
 * TIMER0.h
 *
 * Created: 25/04/2023 05:14:54 م
 *  Author: Abdelsattar
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
#include "data_types.h"

void TIMER0_Overflow_interrupt(void);
void TIMER2_Overflow_interrupt(void);
void TIMER0_CTC_interrupt(void);
void TIMER0_Wave_nonPWM(void);
void TIMER0_FastPWM(void);
void TIMER0_PhasecorrectPWM(void);

#endif /* TIMER0_H_ */