/*
 * External_EEPRROM.c
 *
 * Created: 05/05/2023 04:53:39 م
 *  Author: Abdelsattar
 */ 
#include "External EEPRROM.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* This Functions Works with EEPROM 24C16*/
void External_EEPROM_Write(u16 address,u8 data)
{
	/*The address of  EEPROM 24C16 is 11bits */
	 u8 address1=(address>>7)&(0b00001110);//to get 3 MSB 
	 address1|=(0b10100000);
	 u8 address2=((address)&(0b11111110));
	I2C_vInit(100000);
	_delay_ms(300);
	I2C_Start();
	I2C_Write_address(address1);
	I2C_Write_Data(address2);
	I2C_Write_Data(data);
	I2C_Stop();
}
u8 External_EEPROM_Read(u16 address)
{
	u8 x;
	u8 address1=(address>>7)&(0b00001110);//to get 3 MSB
	address1|=(0b10100000);
	u8 address2=((address)&(0b11111110));
	I2C_vInit(100000);
	_delay_ms(300);
	I2C_Start();
	I2C_Write_address(address1);
	I2C_Write_Data(address2);
	I2C_Start();
	address1|=(0b10100001);
	I2C_Write_address(address1);
	x=I2C_Read_Data_With_NACK();
	I2C_Stop();
	return x;
}