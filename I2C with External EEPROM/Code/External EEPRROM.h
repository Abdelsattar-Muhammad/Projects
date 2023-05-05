/*
 * External_EEPRROM.h
 *
 * Created: 05/05/2023 04:53:27 م
 *  Author: Abdelsattar
 */ 


#ifndef EXTERNAL EEPRROM_H_
#define EXTERNAL EEPRROM_H_
#include "I2C.h"
#include "data_types.h"

void External_EEPROM_Write(u16 address,u8 data);

u8 External_EEPROM_Read(u16 address);

#endif /* EXTERNAL EEPRROM_H_ */