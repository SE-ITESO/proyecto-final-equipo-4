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
#include "config.h"

/**************************************************************************************************************
 *                                           Functions declarations
 **************************************************************************************************************/

void EDMA_Callback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds);

void DMA_config(uint16_t srcAddr[],uint16_t nbytes);

uint8_t DMA_flag(void);


#endif /* DMA_H_ */
