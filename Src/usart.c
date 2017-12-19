/*
 * usart.c
 *
 *  Created on: Dec 12, 2017
 *      Author: user1
 */

#include "usart.h"
#include "rcc.h"
/*
 *
 * PA10 --USART1 RX
 * PA9	--USART1 TX
 *
 *
 */
void enableUSART1(UsartReg *usart){
	// assuming is 1
	enableUsart1();
	settingUpBoudRate(usart,0xd,0x30);

	usart->CR1=(USARTEn|USARTOddParity|WordLength9|PCEEn|TEEn);
	//|TEEn
	usart->CR2 &=~(3<<12);
	usart->CR2	|=(2<<12);
	usart->CR1|=REEn;
	settingEnableDMA(usart);
}


void settingUpBoudRate(UsartReg *usart,int fraction,int mantissa){
	//USART1->BRR&=~(0x7);			// d48.516
	/*
	 * 0.516*8=4.128
	 * nearest is 4(100)
	 * fractional bit[2:0] is enuf to take 4
	 *
	 * 48=0x30
	 * put this into mantissa
	 */
	usart->BRR =((mantissa<<4)|(fraction));
	//USART1->BRR=rate;

}

void settingEnableDMA(UsartReg *usart){
	//for both Tx and Rx
	usart->CR3 |=(0x3<<6);
}



void USARTSendDataOut(UsartReg *usart,int dat){
	while((((usart->SR)>>7)&0x01)!=1){
		}
	usart->DR=dat;
}
void USARTSendCharDataOut(UsartReg *usart,char* dat){
	while((((usart->SR)>>7)&0x01)!=1){
		}
	usart->DR=*dat;
}
void USARTSendString(UsartReg *usart,char str[],int size){
	for(int i=0;i<size;i++){
	USARTSendCharDataOut(usart,&str[i]);
	}
}

uint8_t USARTReceiveData(UsartReg *usart,char *store){
	usart->CR1|=REEn;
	while((((usart->SR)>>5)&0x01)==0){
		//HAL_Delay(500);
		//return *store;
	}
	*store=(uint8_t)USART1->DR;
	return (uint8_t)USART1->DR;
}
int USARTReceiveUntilEnter(UsartReg *usart,char *str,char *store){
	//USART1->CR1|=REEn;
	*str=USARTReceiveData(usart,&store);
	int count =0;
	while(*str!=0xa){
		count++;
		str++;
		*str=USARTReceiveData(usart,&store);
	}
	*str=0;
	return count;
}



