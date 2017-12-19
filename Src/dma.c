/*
 * dma.c
 *
 *  Created on: Dec 19, 2017
 *      Author: user1
 */

#include "dma.h"
/*
 *
 * DMA2 stream2 channel 4 USART RX
 * DMA2 stream7 channel 4 USART TX
 *
 *
 * Psize 1byte
 * Msize 1byte
 *
 * Mburst in 8 beats increment
 * FiFO_burst=1/2 threshold
 *
 * PINC=no
 * MINC=yes
 *
 * circular mode =no
 * double buffer =no
 *
 * priority =high
 *
 * flow control =DMA
 *
 * direction(TX)=m to p
 * direction(RX)=p to m
 *
 */

#define TRUE 	1
#define FALSE   0


int dataStreamCheckFlag(DmaReg *dma,int StreamNum,int Flag){
	volatile uint32_t *InteruptStatusReg=&dma->LISR;
	int upper16=FALSE;
	if(StreamNum > 3){
		InteruptStatusReg=&dma->HISR;
		StreamNum-=4;
	}
	if(StreamNum>2){
		upper16=TRUE;
		StreamNum-=2;
	}

	return (*InteruptStatusReg & (Flag<<(6*StreamNum + 16*upper16)));

}
void UartTxUsingDMA(char *str){
	MyDMA2->S[7].NDTR=strlen(str);
	MyDMA2->S[7].M0AR=str;
	MyDMA2->S[7].CR |=(EN);

}

void UartRxUsingDMA(uint32_t address){
	MyDMA2->S[7].NDTR=15;
	MyDMA2->S[2].M0AR=address;
	MyDMA2->S[2].CR |=(EN);
}
void setUpDMA4UART(){

	//enable in rcc
	enableDMA(DMA2_DEV);
	//stream2
	MyDMA2->S[2].CR &=~(EN);
	MyDMA2->S[2].CR =(CHSEL(4) | MBurstInc8 | Prio(3) | Msize(1) | Psize(1) | Minc | Dir(0));

	//stream7
	MyDMA2->S[7].CR &=~(EN);
	MyDMA2->S[7].CR =(CHSEL(4) | MBurstInc8 | Prio(3) | Msize(0) | Psize(0) | Minc | Dir(1) | Circ);

	MyDMA2->S[2].FCR |=1;
	MyDMA2->S[7].FCR |=1;


	MyDMA2->S[2].PAR =&(USART1->DR);
	MyDMA2->S[7].PAR =&(USART1->DR);

}
