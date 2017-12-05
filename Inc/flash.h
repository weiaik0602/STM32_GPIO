/*
 * flash.h
 *
 *  Created on: Dec 5, 2017
 *      Author: user1
 */

#ifndef FLASH_H_
#define FLASH_H_


#include <stdint.h>


#define FLASH_BASE_ADDR	0x40023C00



typedef struct FlashReg FlashReg;

struct FlashReg{
	volatile uint32_t ACR;  	//access control register
	volatile uint32_t KEYR;		//key register
	volatile uint32_t OPTKEYR;	//option key register
	volatile uint32_t SR;		//status register
	volatile uint32_t CR;		//control register
	volatile uint32_t OPTCR;	//option control register
	volatile uint32_t OPTCR1;	//option control register

};

#define Flash			((FlashReg *)(FLASH_BASE_ADDR))

#define FLASH_BYTE_SIZE			0
#define FLASH_HALFWORD_SIZE		1
#define FLASH_WORD_SIZE			2
#define FLASH_DOUBLEWORD_SIZE	3


#define FLASH_SECTOR_ERASE			(1<<1)
#define FLASH_START					(1<<16)
#define FLASH_PROG_ENABLE			(1)
#define FLASH_PROG_DISABLE			(0)
#define FLASH_EOP_INTERRUPT_EN      (1<<24)
#endif /* FLASH_H_ */
