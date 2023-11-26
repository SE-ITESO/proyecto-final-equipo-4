/*
 * dma.c
 *
 *  Created on: 3 nov 2023
 *      Author: Arlette Uribe & Pablo Ramos
 */


#include "dma.h"

/**************************************************************************************************************
 *                                                Global variables
 **************************************************************************************************************/

volatile bool g_Transfer_Done = false;

AT_QUICKACCESS_SECTION_DATA_ALIGN(edma_tcd_t tcdMemoryPoolPtr[TCD_QUEUE_SIZE + 1], sizeof(edma_tcd_t));

edma_handle_t g_EDMA_Handle;

/**************************************************************************************************************
 *                                             Functions definitions
 **************************************************************************************************************/

void EDMA_Callback(edma_handle_t *handle, void *param, bool transferDone, uint32_t tcds)
{
    if (transferDone)
    {
        g_Transfer_Done = true;
    }
}


void DMA_config(uint16_t srcAddr[],uint16_t nbytes)
{
	edma_transfer_config_t transferConfig;
    edma_config_t userConfig;
    g_Transfer_Done = false;

    DMAMUX_Init(DMAMUX0);
    DMAMUX_SetSource(DMAMUX0,DMA_CHANNEL, DMA_SOURCE);
    DMAMUX_EnableChannel(DMAMUX0,DMA_CHANNEL);
    DMAMUX_EnablePeriodTrigger(DMAMUX0, DMA_CHANNEL);

    EDMA_GetDefaultConfig(&userConfig);
    EDMA_Init(DMA0, &userConfig);
    EDMA_CreateHandle(&g_EDMA_Handle,DMA0,DMA_CHANNEL);
    EDMA_SetCallback(&g_EDMA_Handle, EDMA_Callback, NULL);
    EDMA_ResetChannel(g_EDMA_Handle.base, g_EDMA_Handle.channel);


    EDMA_PrepareTransferConfig(&transferConfig,
    		   &srcAddr[0],						/* srcAddr */
			   SRC_WIDTH, 					    /* srcWidth en bytes */
			   SRC_OFFSET, 						/* source offset */
			   (void*)DAC_ADDR,					/* destAddr */
			   DEST_WIDTH,						/* desWidth en bytes */
			   DEST_OFFSET,               		/* dest offset */
			   MINOR_LOOP,             			/* minor loop bytes */
			   nbytes); 						/* major loop counts */

    EDMA_TcdSetMajorOffsetConfig(
		    		   tcdMemoryPoolPtr, 		/* param tcd A point to the TCD structure. */
		    		   0, 						/* param sourceOffset source address offset*/
					   0);						/* destOffset destination address offset */

   EDMA_TcdSetTransferConfig(tcdMemoryPoolPtr, &transferConfig, NULL);
   EDMA_TcdEnableInterrupts(&tcdMemoryPoolPtr[0], kEDMA_MajorInterruptEnable);
   EDMA_TcdEnableAutoStopRequest(&tcdMemoryPoolPtr[0], true); 	/* true: solo se hace una transferencia */
   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	   	/* false: se hacen múltiples transferencias */
   EDMA_InstallTCD(DMA0,DMA_CHANNEL, &tcdMemoryPoolPtr[0]);
   EDMA_EnableChannelRequest(DMA0,DMA_CHANNEL);

}
uint8_t DMA_flag(void){
	return g_Transfer_Done;
}
