/*
 * gpio.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#include "gpio.h"

void gpioGConfig(int pin,int mode, int outDriveType,int pullType,int speed){
	///MODE configuration
	GpioG->mode &=~(3<<(pin*2));
	GpioG->mode |= mode<<(pin*2);

	///OSPEED configuration
	GpioG->outSpeed &=~(3<<(pin*2));
	GpioG->outSpeed |= speed<<(pin*2);

	//PullType configuration
	GpioG->pullType  &=~(3<<(pin*2));
	GpioG->pullType |= pullType<<(pin*2);

	//
	GpioG->outType  &=~(1<<(pin));
	GpioG->outType |= outDriveType<<(pin);
}

void gpioGWrite(int pin, int state){
	if(state==1){
		GpioG->outData |=1<<pin;
	}else{
		GpioG->outData &=~(1<<pin);
	}

}
