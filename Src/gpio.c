/*
 * gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#include "gpio.h"

uint32_t *gpioGMode=(uint32_t *)(GPIOG_BASE_ADDR+GPIO_MODE_OFF);
uint32_t *gpioGOSpeed=(uint32_t *)(GPIOG_BASE_ADDR+GPIO_OSPEED_OFF);
uint32_t *gpioGPupd=(uint32_t *)(GPIOG_BASE_ADDR+GPIO_PUPD_OFF);
uint32_t *gpioGOType=(uint32_t *)(GPIOG_BASE_ADDR+GPIO_OTYPE_OFF);
uint32_t *gpioGOd=(uint32_t *)(GPIOG_BASE_ADDR+GPIO_OD_OFF);

void gpioGConfig(int pin,int mode, int outDriveType,int pullType,int speed){
	///MODE configuration
	*gpioGMode &=~(3<<(pin*2));
	*gpioGMode |= mode<<(pin*2);

	///OSPEED configuration
	*gpioGOSpeed &=~(3<<(pin*2));
	*gpioGOSpeed |= speed<<(pin*2);

	//PullType configuration
	*gpioGPupd  &=~(3<<(pin*2));
	*gpioGPupd |= pullType<<(pin*2);

	//
	*gpioGOType  &=~(1<<(pin));
	*gpioGOType |= outDriveType<<(pin);
}

void gpioGWrite(int pin, int state){
	if(state==1){
		*gpioGOd |=1<<pin;
	}else{
		*gpioGOd &=~(1<<pin);
	}

}
