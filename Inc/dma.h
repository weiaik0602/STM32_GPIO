/*
 * dma.h
 *
 *  Created on: Dec 19, 2017
 *      Author: user1
 */

#ifndef DMA_H_
#define DMA_H_



#include <stdint.h>
#include <stdio.h>
#include "rcc.h"
#include "usart.h"
//USART
#define DMA1_BASE_ADDR	0x40026000
#define DMA2_BASE_ADDR	0x40026400
#define MyDMA1			((DmaReg *)(DMA1_BASE_ADDR))
#define MyDMA2			((DmaReg *)(DMA2_BASE_ADDR))


typedef struct DmaStreamReg DmaStreamReg;
struct DmaStreamReg{
	volatile uint32_t CR;
	volatile uint32_t NDTR;
	volatile uint32_t PAR;
	volatile uint32_t M0AR;
	volatile uint32_t M1AR;
	volatile uint32_t FCR;
};

typedef struct DmaReg DmaReg;

struct DmaReg{
	volatile uint32_t LISR;
	volatile uint32_t HISR;
	volatile uint32_t LIFCR;
	volatile uint32_t HIFCR;
	DmaStreamReg	S[8];
};

//flags
#define TCIF			1<<5
#define HTIF			1<<4
#define TEIF			1<<3
#define DMEIF			1<<2
#define FEIF			1<<0

//Stream control reg
#define EN				1
#define CHSEL(val)		(val<<25)
#define MBurstSingle	(0<<23)
#define MBurstInc4		(1<<23)
#define MBurstInc8		(2<<23)
#define MBurstInc16		(3<<23)
#define PBurstSingle	(0<<21)
#define PBurstInc4		(1<<21)
#define PBurstInc8		(2<<21)
#define PBurstInc16		(3<<21)
#define Prio(val)		(val<<16)
#define Pincos			(1<<15)
#define Msize(val)		(val<<13)
#define Psize(val)		(val<<11)
#define Minc			(1<<10)
#define Pinc			(1<<9)
#define Circ			(1<<8)
#define Dir(dir)		(dir<<6)
#define Pfctrl			(1<<5)		//default is DMA, set this is peripheral

//MACRO
#define dmaStreamHasTransferCompleted(d,s)				\
								dataStreamCheckFlag(d,s,TCIF)
#define dmaStreamHasHalfTransferCompleted(d,s)				\
								dataStreamCheckFlag(d,s,HTIF)
#define dmaStreaIsTransferError(d,s)				\
								dataStreamCheckFlag(d,s,TEIF)
#define dmaStreamIsDirectModeError(d,s)				\
								dataStreamCheckFlag(d,s,DMEIF)
#define dmaStreamIsFIFOError(d,s)				\
								dataStreamCheckFlag(d,s,FEIF)

void UartTxUsingDMA(char *str);
void DMA4UART();
int dataStreamCheckFlag(DmaReg *dma,int StreamNum,int Flag);
#endif /* DMA_H_ */
