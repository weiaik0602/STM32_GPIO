/*
 * usart.h
 *
 *  Created on: Dec 12, 2017
 *      Author: user1
 */

#ifndef USART_H_
#define USART_H_


#include <stdint.h>
#include <stdio.h>
//USART
#define USART1_BASE_ADDR	0x40011000



typedef struct UsartReg UsartReg;

struct UsartReg{
	volatile uint32_t SR;		//status reg
	volatile uint32_t DR;		//data reg
	volatile uint32_t BRR;		//Baud rate register
	volatile uint32_t CR1;		//control reg
	volatile uint32_t CR2;		//control reg
	volatile uint32_t CR3;		//control reg
	volatile uint32_t GTPR;		//Guard time and prescaler register
};

#define USART1			((UsartReg *)(USART1_BASE_ADDR))

//CR1
#define USARTEn			(1<<13)
#define USARTOddParity	(1<<9)
#define WordLength9		(1<<12)
#define OverSampling8	(1<<15)
#define TEEn				(1<<3)
#define REEn				(1<<2)
#define PCEEn			(1<<10)
//CR2
#define OneStopBit		(0x00<<12)
#define HalfStopBit		(0x01<<12)
#define TwoStopBit		(0x10<<12)
#define OneHalfStopBit	(0x11<<12)



void enableUSART1(UsartReg *usart);
void settingUpBoudRate(UsartReg *usart,int fraction,int mantissa);
void USARTSendDataOut(UsartReg *usart,int dat);
void USARTSendCharDataOut(UsartReg *usart,char* dat);
void USARTSendString(UsartReg *usart,char str[],int size);
uint8_t USARTReceiveData(UsartReg *usart,char *store);
int USARTReceiveUntilEnter(UsartReg *usart,char *str,char *store);
void settingEnableDMA(UsartReg *usart);



#endif /* USART_H_ */
