/*
 * rcc.h
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */

#ifndef RCC_H_
#define RCC_H_

#include <stdint.h>



#define RCC_BASE_ADDR		0x40023800
#define RCC_AHB1RST_OFF		0x10
#define RCC_AHB1EN_OFF		0x30



extern uint32_t *rccAhb1Rst;
extern uint32_t *rccAhb1En;



void enableGpioG();
void enableGpioA();
#endif /* RCC_H_ */
