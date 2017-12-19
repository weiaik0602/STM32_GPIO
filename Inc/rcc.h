/*
 * rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>



#define RCC_BASE_ADDR		0x40023800

#define A	0
#define B	1
#define C	2
#define D	3
#define E	4
#define F	5
#define G	6
#define H	7
#define I	8
#define J	9
#define K	10

typedef struct RccReg RccReg;

struct RccReg{
	volatile uint32_t CR;
	volatile uint32_t PLLCFGR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t AHB1RSTR;
	volatile uint32_t AHB2RSTR;
	volatile uint32_t AHB3RSTR;
	volatile uint32_t Reserved1;
	volatile uint32_t APB1RSTR;
	volatile uint32_t APB2RSTR;

	volatile uint32_t Reserved2;
	volatile uint32_t Reserved3;
	volatile uint32_t AHB1ENR;
	volatile uint32_t AHB2ENR;
	volatile uint32_t AHB3ENR;
	volatile uint32_t Reserved4;
	volatile uint32_t APB1ENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t Reserved5;
	volatile uint32_t Reserved6;

	volatile uint32_t AHB1LPENR;
	volatile uint32_t AHB2LPENR;
	volatile uint32_t AHB3LPENR;
	volatile uint32_t Reserved7;
	volatile uint32_t APB1LPENR;
	volatile uint32_t APB2LPENR;
	volatile uint32_t Reserved8;
	volatile uint32_t Reserved9;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;

	volatile uint32_t Reserved10;
	volatile uint32_t Reserved11;
	volatile uint32_t SSCGR;
	volatile uint32_t PLLI2SCFGR;
};
#define MCO_HSI_SRC		0
#define MCO_LSE_SRC		1
#define MCO_HSE_SRC		2
#define MCO_PLL_SRC		3

#define MCO_NO_DIV			0
#define MCO_DIV_BY_4		2
#define MCO_DIV_BY_5		7
#define MCO_DIV_BY_6		4
#define MCO_DIV_BY_7		5


#define I2C1_DEV		21
#define I2C2_DEV		22


#define DMA1_DEV		1
#define DMA2_DEV		2

#define rccSelectMco1src(x)				\
	do{									\
		Rcc->CFGR &= ~(3 << 21);		\
		Rcc->CFGR |= (x) << 21;			\
	}while(0)
#define rccSetMco1PreScaler(x)			\
	do{									\
		Rcc->CFGR &= ~(7 << 24);		\
		Rcc->CFGR |= (x) << 24;			\
	}while(0)


#define Rcc			((RccReg *)(RCC_BASE_ADDR))


void enableGpio(int Gpio);

void enableGpioG();
void enableGpioA();
void enableRng();
void enableTim8();
void enableUsart1();
void enableI2C(int pin);
void enableDMA(int pin);
#endif /* RCC_H_ */
