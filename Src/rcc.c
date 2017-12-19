/*
 * rcc.c
 *
 *  Created on: Oct 27, 2017
 *      Author: user1
 */


#include "rcc.h"
#include "gpio.h"



void enableGpio(int Gpio){
	int pin;
	switch(Gpio){
	case(A):pin=0;
			  break;
	case(B):pin=1;
			  break;
	case(C):pin=2;
			  break;
	case(D):pin=3;
			  break;
	case(E):pin=4;
			  break;
	case(F):pin=5;
			  break;
	case(G):pin=6;
			  break;
	}
	Rcc->AHB1RSTR &=~(1<<pin);
	Rcc->AHB1ENR |=(1<<pin);
}
void enableRng(void){
	//Unreset RNG
	Rcc-> AHB2RSTR &= ~(1 << 6);
	//Start clock of RNG
	Rcc-> AHB2ENR |= 1 << 6;
}

void enableTim8(void){
	Rcc->APB2RSTR &=~(1 << 1);
	Rcc->APB2ENR  |=(1 << 1);
}
void enableI2C(int pin){
	Rcc->APB1RSTR &=~(1<<pin);
	Rcc->APB1ENR  |=(1<<pin);
}

void enableUsart1(void){
	Rcc->APB2RSTR &=~(1 << 4);
	Rcc->APB2ENR  |=(1 << 4);
}

//DMA1_DEV for DMA1
//DMA2_DEV for DMA2
void enableDMA(int pin){
	Rcc->AHB1RSTR &=~(1<<(20+pin));
	Rcc->AHB1ENR |=(1<<(20+pin));
}
