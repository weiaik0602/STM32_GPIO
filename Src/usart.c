/*
 * usart.c
 *
 *  Created on: Dec 12, 2017
 *      Author: user1
 */

#include "usart.h"
#include "rcc.h"

void enableUSART1(){
	enableUsart1();
	settingUpBoudRate(0xd,0x30);

	USART1->CR1=(USARTEn|USARTOddParity|WordLength9|PCEEn|TEEn);
	//|TEEn
	USART1->CR2 &=~(3<<12);
	USART1->CR2	|=(2<<12);
}


void settingUpBoudRate(int fraction,int mantissa){
	//USART1->BRR&=~(0x7);			// d48.516
	/*
	 * 0.516*8=4.128
	 * nearest is 4(100)
	 * fractional bit[2:0] is enuf to take 4
	 *
	 * 48=0x30
	 * put this into mantissa
	 */
	USART1->BRR =((mantissa<<4)|(fraction));
	//USART1->BRR=rate;

}
void USARTSendDataOut(int dat){
	while((((USART1->SR)>>7)&0x01)!=1){
		}
	USART1->DR=dat;
}
void USARTSendCharDataOut(char* dat){
	while((((USART1->SR)>>7)&0x01)!=1){
	}
	USART1->DR=*dat;

}
void USARTSendString(char str[],int size){
	for(int i=0;i<size;i++){
	USARTSendCharDataOut(&str[i]);
	}
}

uint8_t USARTReceiveData(char *store){
	USART1->CR1|=REEn;
	while((((USART1->SR)>>5)&0x01)==0){
		HAL_Delay(500);
		return *store;
	}
	*store=(uint8_t)USART1->DR;
	return (uint8_t)USART1->DR;
}
int USARTReceiveUntilEnter(char *str,char *store){
	//USART1->CR1|=REEn;
	*str=USARTReceiveData(&store);
	int count =0;
	while(*str!=0xa){
		count++;
		str++;
		*str=USARTReceiveData(&store);
	}
	*str=0;
	return count;
}



