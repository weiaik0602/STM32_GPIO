/*
 * timer.h
 *
 *  Created on: Nov 21, 2017
 *      Author: user1
 */

#ifndef TIMER_H_
#define TIMER_H_

#include <stdint.h>



//#define TIMER1_BASE_ADDR		0x40010000
//#define TIMER2_BASE_ADDR		0x40000000
//#define TIMER3_BASE_ADDR		0x40000400
//#define TIMER4_BASE_ADDR		0x40000800
//#define TIMER5_BASE_ADDR		0x40000C00
//#define TIMER6_BASE_ADDR		0x40001000
//#define TIMER7_BASE_ADDR		0x40001400
#define TIMER8_BASE_ADDR		0x40010400



typedef struct TimerReg TimerReg;

struct TimerReg{
	volatile uint32_t CR1;			//control reg 1
	volatile uint32_t CR2;
	volatile uint32_t SMCR;			//slave mode control reg
	volatile uint32_t DIER;			//DMA and Interrupt En
	volatile uint32_t SR;			//Status reg
	volatile uint32_t EGR;			//event generation
	volatile uint32_t CCMR1;		//capture/compare mode
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;			//capture/compare En
	volatile uint32_t CNT;			//counter

	volatile uint32_t PSC;			//prescale
	volatile uint32_t ARR;			//auto reload
	volatile uint32_t RCR;			//repetition counter reg
	volatile uint32_t CCR1;			//capture/compare reg
	volatile uint32_t CCR2;
	volatile uint32_t CCR3;
	volatile uint32_t CCR4;
	volatile uint32_t BDTR;			//break and dead time
	volatile uint32_t DCR;			//DMA control
	volatile uint32_t DMAR;			//DMA address

};


#define Timer8			((TimerReg *)(TIMER8_BASE_ADDR))

void enableTimer8();
void wait500ms();

#endif /* TIMER_H_ */
