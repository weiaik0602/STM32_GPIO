/*
 * Syscfg.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user1
 */

#ifndef SYSCFG_H_
#define SYSCFG_H_

#include <stdint.h>
#include "rcc.h"

#define SYSCFG_BASE_ADDR	0x40013800


typedef struct SYSCFGReg SYSCFGReg;

struct SYSCFGReg{
	volatile uint32_t MEMRMP;
	volatile uint32_t PMC;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t CMPCR;
};


#define PORTA		0
#define PORTB		1
#define PORTC		2
#define PORTD		3
#define PORTE		4
#define PORTF		5
#define PORTG		6
#define PORTH		7

#define sysCfgSelectExtIntrGpio(bits)			\
				do{								\
				(SysCfg->EXTICR &= ~()
#define SYSCFG	((SYSCFGReg *)(SYSCFG_BASE_ADDR))

#define SYSCFG_EXTICR1(in)

#endif /* SYSCFG_H_ */
