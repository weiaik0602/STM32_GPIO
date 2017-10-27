/*
 * gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#ifndef GPIO_H_
#define GPIO_H_


#include <stdint.h>

#define GPIOG_BASE_ADDR	0x40021800


typedef struct GpioReg GpioReg;

struct GpioReg{
	volatile uint32_t mode;
	volatile uint32_t outType;
	volatile uint32_t outSpeed;
	volatile uint32_t pullType;
	volatile uint32_t inData;
	volatile uint32_t outData;
	volatile uint32_t bitData;
	volatile uint32_t lock;
	volatile uint32_t altFuncLow;
	volatile uint32_t altFuncHigh;
};

#define GpioG			((GpioReg *)(GPIOG_BASE_ADDR))
//mode
#define GPIO_MODE_IN		 0
#define GPIO_MODE_OUT		 1
#define GPIO_MODE_AF		 2
#define GPIO_MODE_ANA 		 3

//pin output drive type
#define GPIO_PUSH_PULL	 	0
#define GPIO_OPEN_DRAIN 	1

//speed
#define GPIO_LOW_SPEED	 	0
#define GPIO_MED_SPEED	 	1
#define GPIO_HI_SPEED	 	2
#define GPIO_VHI_SPEED	 	3

//pull type
#define GPIO_NO_PULL	 	0
#define GPIO_PULL_UP	 	1
#define GPIO_PULL_DOWN	 	2
#define GPIO_RESERVED	 	3

#endif /* GPIO_H_ */
