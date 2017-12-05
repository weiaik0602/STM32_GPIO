/*
 * timer.c
 *
 *  Created on: Nov 21, 2017
 *      Author: user1
 */
#include "timer.h"
#include "rcc.h"

void enableTimer8(){
	//enable timer 8 , unreset,enable clk
	enableTim8();


	//configure max counter at ARR
	Timer8->ARR =5000;
	//configure prescale
	Timer8->PSC =18000;
	//select clock source
	Timer8->SMCR	&= ~(7);
	//enable timer8
	Timer8->CR1 |= 1;

}

void initTimer8Channel1(){
	//configure timer8 channel 1 (PC6)enable portc , set pin as alt func3

}
void initTimer8Channel3(){
	//configure timer8 channel 1 (PC8)enable port c, set pin as alt func3
}
void wait500ms(){

	while((Timer8->SR&0x01)!=1){

	}
	Timer8->SR &=~(0x01);
}
