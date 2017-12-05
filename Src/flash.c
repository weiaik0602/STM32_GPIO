/*
 * flash.c
 *
 *  Created on: Dec 5, 2017
 *      Author: user1
 */

#include "flash.h"

int flashEraseSector(int sectorNum){
	if(sectorNum >11)
		sectorNum=sectorNum+4;
	//unlock
	Flash->KEYR=0x45670123;
	Flash->KEYR=0xCDEF89AB;
	//set sector number  //set to erase  //start to erase  //enable eopie
	Flash->CR =(sectorNum<<3 | FLASH_START | FLASH_SECTOR_ERASE| FLASH_EOP_INTERRUPT_EN);




	//check for failure
	if((Flash->SR>>16)==1)
		return (Flash->SR&0x01);

}


int flashEnableProgramming(int Psize){
	Flash->CR |=FLASH_PROG_ENABLE;
	Flash->CR &= ~(0x3<<8);
	Flash->CR |= (Psize<<8);
}

int flashDisableProgramming(){
	Flash->CR &=~FLASH_PROG_ENABLE;

}

int writeMessage(char *message,char *memoryToWrite){
	//strcpy(memoryToWrite,message);
	*memoryToWrite=*message;
}
