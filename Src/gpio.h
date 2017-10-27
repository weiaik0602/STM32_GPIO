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
#define GPIO_MODE_OFF	0x0
#define GPIO_OSPEED_OFF	0x08
#define GPIO_OTYPE_OFF	0x04
#define GPIO_PUPD_OFF	0x0C
#define GPIO_ID_OFF		0x10
#define GPIO_OD_OFF		0x14
#define GPIO_BSR_OFF	0x18
#define GPIO_LCK_OFF	0x1C

//mode
#define GPIO_MODE_IN		 0
#define GPIO_MODE_OUT	 1
#define GPIO_MODE_AF		 2
#define GPIO_MODE_ANA 	 3

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




//export other variable modules
extern uint32_t *gpioGMode;
extern uint32_t *gpioGOSpeed;
extern uint32_t *gpioGPupd;
extern uint32_t *gpioGOd;


#endif /* GPIO_H_ */
