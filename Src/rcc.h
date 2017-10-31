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



#define Rcc			((RccReg *)(RCC_BASE_ADDR))


void enableGpio(int Gpio);

void enableGpioG();
void enableGpioA();
void enableRng();
#endif /* RCC_H_ */
