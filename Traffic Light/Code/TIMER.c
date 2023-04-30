/*
 * TIMER0.c
 *
 * Created: 25/04/2023 05:14:42 م
 *  Author: Abdelsattar
 */ 

#include "std_macro.h"
#include "TIMER.h"
#include "DIO.h"
#include <avr/interrupt.h>
void TIMER0_Overflow_interrupt(void)
{
	/* Set Clock Frequency */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/*Enable interrupt */
	sei();
	SET_BIT(TIMSK,TOIE0);
}
void TIMER0_CTC_interrupt(void)
{
		/* Set CTC Mode */
		SET_BIT(TCCR0,WGM01);
		/* Set Clock Frequency */
 		SET_BIT(TCCR0,CS00);
		SET_BIT(TCCR0,CS02);
		/*set OCR0 */
		OCR0=79;
		/*Enable interrupt */
		sei();
		SET_BIT(TIMSK,OCIE0);
		

} 

void TIMER0_Wave_nonPWM(void)
{
	/*Set PB3 As Output */
	DIO_vSetPinDir(BPORT,PIN3,OUTPUT);
	/* Set CTC Mode */
	SET_BIT(TCCR0,WGM01);
	/* Set Clock Frequency Foc0=Fmcu/2(1+OCR0)*N */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/*set OCR0 */
	OCR0=64;
	/* Set COM00 To toggle OC0 on Compare Match*/
	SET_BIT(TCCR0,COM00);
	
	
}

void TIMER0_FastPWM(void)
{
	/*Set PB3 As Output */
	DIO_vSetPinDir(BPORT,PIN3,OUTPUT);
	/* Set Fast PWM Mode */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/* Set Clock Frequency Foc0=Fmcu/2(1+OCR0)*N */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/*set OCR0 */
	OCR0=64;
	/* Set COM00 To Clear OC0 on Compare Match*/
	SET_BIT(TCCR0,COM01);
	
}

void TIMER0_PhasecorrectPWM(void)
{
	/*Set PB3 As Output */
	DIO_vSetPinDir(BPORT,PIN3,OUTPUT);
	/* Set Fast PWM Mode */
	SET_BIT(TCCR0,WGM00);
	/* Set Clock Frequency Foc0=Fmcu/2(1+OCR0)*N */
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS02);
	/*set OCR0 */
	OCR0=64;
	/* Set COM00 To Clear OC0 on Compare Match*/
	SET_BIT(TCCR0,COM01);
	
}


void TIMER2_Overflow_interrupt(void)
{
	
	SET_BIT(ASSR,AS2);
	/* Set Clock Frequency prescaler 128*/
	SET_BIT(TCCR2,CS20);
	SET_BIT(TCCR2,CS22);
	/*Enable interrupt */
	sei();
	SET_BIT(TIMSK,TOIE2);
	
	
} 