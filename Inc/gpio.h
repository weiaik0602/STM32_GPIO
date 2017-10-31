/*
 * gpio.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#ifndef GPIO_H_
#define GPIO_H_


#include <stdint.h>

//GPIO
#define GPIOA_BASE_ADDR	0x40020000
#define GPIOB_BASE_ADDR	0x40020400
#define GPIOC_BASE_ADDR	0x40020800
#define GPIOD_BASE_ADDR	0x40020C00
#define GPIOE_BASE_ADDR	0x40021000
#define GPIOF_BASE_ADDR	0x40021400
#define GPIOG_BASE_ADDR	0x40021800
#define GPIOH_BASE_ADDR	0x40021C00
#define GPIOI_BASE_ADDR	0x40022000


typedef struct GpioReg GpioReg;

struct GpioReg{
	volatile uint32_t mode;
	volatile uint32_t outType;
	volatile uint32_t outSpeed;
	volatile uint32_t pullType;
	volatile uint32_t inData;
	volatile uint32_t outData;
	volatile uint32_t bsr;
	volatile uint32_t lock;
	volatile uint32_t altFuncLow;
	volatile uint32_t altFuncHigh;
};

#define GpioA			((GpioReg *)(GPIOA_BASE_ADDR))
#define GpioB			((GpioReg *)(GPIOB_BASE_ADDR))
#define GpioC			((GpioReg *)(GPIOC_BASE_ADDR))
#define GpioD			((GpioReg *)(GPIOD_BASE_ADDR))
#define GpioE			((GpioReg *)(GPIOE_BASE_ADDR))
#define GpioF			((GpioReg *)(GPIOF_BASE_ADDR))
#define GpioG			((GpioReg *)(GPIOG_BASE_ADDR))
#define GpioH			((GpioReg *)(GPIOH_BASE_ADDR))
#define GpioI			((GpioReg *)(GPIOI_BASE_ADDR))

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


//macro
#define SET_PIN(gpio, pinNum)	(gpio->bsr=(1<<pinNum))
#define RESET_PIN(gpio, pinNum)	(gpio->bsr=(1<<(16+pinNum)))


void gpioConfig(GpioReg *gpio,int pin,int mode, int outDriveType,int pullType,int speed);
void gpioWrite(GpioReg *gpio,int pin, int state);

void gpioGConfig(int pin,int mode, int outDriveType,int pullType,int speed);
void gpioGWrite(int pin, int state);
int gpioRead(GpioReg *gpio,int pin);
void gpioLock(GpioReg *gpio,int pin);


#endif /* GPIO_H_ */
