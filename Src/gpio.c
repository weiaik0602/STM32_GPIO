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
		SET_PIN(GpioG,pin);
		//GpioG->outData |=1<<pin;
	}else{
		RESET_PIN(GpioG,pin);
		//GpioG->outData &=~(1<<pin);
	}

}

void gpioConfig(GpioReg *gpio,int pin,int mode, int outDriveType,int pullType,int speed)
{
	///MODE configuration
	gpio->mode &=~(3<<(pin*2));
	gpio->mode |= mode<<(pin*2);

	///OSPEED configuration
	gpio->outSpeed &=~(3<<(pin*2));
	gpio->outSpeed |= speed<<(pin*2);

	//PullType configuration
	gpio->pullType  &=~(3<<(pin*2));
	gpio->pullType |= pullType<<(pin*2);

	//
	gpio->outType  &=~(1<<(pin));
	gpio->outType |= outDriveType<<(pin);
}
void gpioWrite(GpioReg *gpio,int pin, int state){
	if(state==1){
		SET_PIN(gpio,pin);
		//gpio->outData |=1<<pin;
	}else{
		RESET_PIN(gpio,pin);
		//gpio->outData &=~(1<<pin);
	}
}

int gpioRead(GpioReg *gpio,int pin){
	return (gpio->inData)&(1 <<pin);
}

void gpioLock(GpioReg *gpio,int pin){
	int lockstate;
	gpio->lock=(1<<16)|(1<<pin);
	gpio->lock=(0<<16)|(1<<pin);
	gpio->lock=(1<<16)|(1<<pin);
	lockstate=gpio->lock;
}

void gpioConfigAltFuncNum(GpioReg *gpio,int pin,int AF){
	 if(pin<7)
		 gpio->altFuncLow =  AF << (pin*4);
	 else
		 gpio->altFuncHigh = AF << (pin*4);
 }
