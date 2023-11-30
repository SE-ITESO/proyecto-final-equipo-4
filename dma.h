/*
 * dma.h
 *
 *  Created on: 3 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */

#ifndef DMA_H_
#define DMA_H_


/**************************************************************************************************************
 *                                               Included files
 **************************************************************************************************************/

#include <stdio.h>
#include "fsl_edma.h"
#include "fsl_dmamux.h"
#include "pit.h"

/**************************************************************************************************************
 *                                           Functions declarations
 **************************************************************************************************************/

typedef enum{
	DMA_ContinuosTransfer,
	DMA_OneTransfer
}DMA_mode_t;


#define TCD_QUEUE_SIZE	1u
#define DMA_SOURCE 		58u				/** Source always enable */
#define DAC_ADDR 		0x400CC000u
#define DMA_CHANNEL		0

#define SRC_WIDTH 2u
#define SRC_OFFSET 2u
#define DEST_WIDTH 2u
#define DEST_OFFSET 0u
#define MINOR_LOOP 2u

void EDMA_Callback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);

void DMA_config(const uint16_t srcAddr[],uint16_t nbytes, DMA_mode_t transfer_mode);

uint8_t DMA_flag(void);


#endif /* DMA_H_ */
