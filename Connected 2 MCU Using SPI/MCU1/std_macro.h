/*
 * std_macro.h
 *
 * Created: 12/04/2023 04:31:32 م
 *  Author: Abdelsattar
 */ 


#ifndef STD_MACRO_H_
#define STD_MACRO_H_


#define REGISTER_SIZE 8
#define SET_BIT(reg,bit) reg |= (1<<bit)
#define CLR_BIT(reg,bit) reg &= (~(1<<bit))
#define TOGGLE_BIT(reg,bit) reg ^= (1<<bit)
#define READ_BIT(reg,bit) ((reg>>bit)&1)
#define ROL(reg,num) reg=(reg<<num)|(reg>>(REGISTER_SIZE-num))
#define ROR(reg,num) reg=(reg>>num)|(reg<<(REGISTER_SIZE-num))

#endif /* STD_MACRO_H_ */