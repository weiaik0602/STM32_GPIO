/*
 * SysTick.h
 *
 *  Created on: Nov 7, 2017
 *      Author: user1
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include <stdint.h>

#define SYSTICK_BASE_ADDR	0xE000E010


#define SYSTICK_EN				1
#define SYSTICK_INTR_EN			(1<<1)
#define SYSTICK_PROC_CLK_SRC	(1<<2)
#define SYSTICK_CNTR_OVRFLOW	(1<<16)



typedef struct SysTickReg SysTickReg;

struct SysTickReg{
	volatile uint32_t CTRL;
	volatile uint32_t LOAD;
	volatile uint32_t VAL;
	volatile uint32_t CALIB;
};
#define Tick						((SysTickReg *)(SYSTICK_BASE_ADDR))
#define sysTickEnable()				(Tick->CTRL	|= SYSTICK_EN)
#define sysTickDisable()			(Tick->CTRL  &= ~(SYSTICK_EN))
#define sysTickIntrEnable()			(Tick->CTRL	|= SYSTICK_INTR_EN)
#define sysTickIntrDisable()		(Tick->LOAD	&= ~(SYSTICK_INTR_EN))
#define sysTickSetReload(x)			(Tick->LOAD	=(x))
#define sysTickReadCounter()		(Tick->VAL)
#define sysTickClrCounter(x)		(Tick->VAL	=0xbadface)
#define sysTickFullSpeed()			(Tick->CTRL	|=SYSTICK_PROC_CLK_SRC)
#define sysTickPrescaleSpeed()		(Tick->CTRL	&=~(SYSTICK_PROC_CLK_SRC))
#define sysTickHasExpired()			((Tick->CTRL	>>16)&0x01)




#endif /* SYSTICK_H_ */
