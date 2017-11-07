/*
 * EXTI.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user1
 */

#ifndef EXTI_H_
#define EXTI_H_

#include <stdint.h>

#define EXTI_BASE_ADDR	0x40013C00


typedef struct EXTIReg EXTIReg;

struct EXTIReg{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
};


#define EXTIntr						((EXTIReg *)(EXTI_BASE_ADDR))
#define EXTI_IMR_ENABLE(bit)		(EXTIntr->IMR |=(1<<bit))
#define EXTI_IMR_DISABLE(bit)		(EXTIntr->IMR &=~(1<<bit))
#define EXTI_EMR_ENABLE(bit)		(EXTIntr->EMR |=(1<<bit))
#define EXTI_EMR_DISABLE(bit)		(EXTIntr->EMR &=~(1<<bit))
#define EXTI_RTSR_ENABLE(bit)		(EXTIntr->RTSR|=(1<<bit))
#define EXTI_RTSR_DISABLE(bit)		(EXTIntr->RTSR &=~(1<<bit))
#define EXTI_FTSR_ENABLE(bit)		(EXTIntr->FTSR|=(1<<bit))
#define EXTI_FTSR_DISABLE(bit)		(EXTIntr->FTSR &=~(1<<bit))
#define EXTI_SWIER_ENABLE(bit)		(EXTIntr->SWIER|=(1<<bit))
#define EXTI_PR_READ(bit)			((EXTIntr->PR>>bit)&0x01)
#define EXTI_PR_CLR(bit)			(EXTIntr->PR|=(1<<bit))


#endif /* EXTI_H_ */
