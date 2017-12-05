/*
 * i2c.h
 *
 *  Created on: Nov 28, 2017
 *      Author: user1
 */

#ifndef I2C_H_
#define I2C_H_

#include <stdint.h>
#include "rcc.h"
#include "gpio.h"


#define I2C1_BASE_ADDR		0x40005400
#define I2C2_BASE_ADDR		0x40005800
#define I2C3_BASE_ADDR		0x40005C00



typedef struct I2CReg I2CReg;

struct I2CReg{
	volatile uint32_t CR1;			//control reg 1
	volatile uint32_t CR2;
	volatile uint32_t OAR1;			//Own address register 1
	volatile uint32_t OAR2;			//Own address register 2
	volatile uint32_t DR;			//Data register
	volatile uint32_t SR1;			//Status register 2
	volatile uint32_t SR2;			//Status register 2
	volatile uint32_t CCR;			//Clock control register
	volatile uint32_t TRISE;		//TRISE register
	volatile uint32_t FLTR;			//FLTR register

};


#define I2c1			((I2CReg *)(I2C1_BASE_ADDR))
#define I2c2			((I2CReg *)(I2C2_BASE_ADDR))
#define I2c3			((I2CReg *)(I2C3_BASE_ADDR))


void initI2c();

#endif /* I2C_H_ */
