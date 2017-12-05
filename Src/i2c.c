/*
 * i2c.c
 *
 *  Created on: Nov 28, 2017
 *      Author: user1
 */


#include "i2c.h"


void initI2c(void){

	 gpioConfig(GpioB,6,GPIO_MODE_AF,GPIO_OPEN_DRAIN,GPIO_PULL_UP,GPIO_VHI_SPEED);
	 gpioConfigAltFuncNum(GpioB,6,ALT_FUNC4);

	 gpioConfig(GpioB,7,GPIO_MODE_AF,GPIO_OPEN_DRAIN,GPIO_PULL_UP,GPIO_VHI_SPEED);
	 gpioConfigAltFuncNum(GpioB,7,ALT_FUNC4);

	 gpioConfig(GpioF,0,GPIO_MODE_AF,GPIO_OPEN_DRAIN,GPIO_PULL_UP,GPIO_VHI_SPEED);
	 gpioConfigAltFuncNum(GpioF,0,ALT_FUNC4);

	 gpioConfig(GpioF,1,GPIO_MODE_AF,GPIO_OPEN_DRAIN,GPIO_PULL_UP,GPIO_VHI_SPEED);
	 gpioConfigAltFuncNum(GpioF,1,ALT_FUNC4);

	 enableI2C(I2C1_DEV);
	 enableI2C(I2C2_DEV);


	I2c1->CR2 &= ~(0x3F);
	I2c1->CR2 |=20;			//10Mhz
	I2c1->CCR &= ~(0xFFFF);
	I2c1->CCR |=100;		//clock control
	I2c1->TRISE &= ~(0x1F);
	I2c1->TRISE |=21;		//rise time

	//
	I2c1->CR1 |=(1<<15);
	I2c1->CR1 &=~(1<<15);

	I2c1->CR1 |=1;			//enable i2c1
	I2c1->CR1 |= (1<<8);	//repeated start



}

