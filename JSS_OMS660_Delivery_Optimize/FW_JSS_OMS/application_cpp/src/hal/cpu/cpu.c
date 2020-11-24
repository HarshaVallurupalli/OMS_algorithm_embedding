/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup cpu
 */
#include <GlobalSettings.h>
#include "cpu.h"
#include "xaxidma.h"
#include "xscugic.h"

XScuGic INTCInst;


/**
 * @brief  Init
 *
 * @retval 0 OK
 * @retval -1 Error
 * @return Result of the initialization
 */
int8_t cpuInit(void)
{
	XScuGic_Config* cfg_ptr;

	// Look up hardware configuration for device
	cfg_ptr = XScuGic_LookupConfig(XPAR_PS7_SCUGIC_0_DEVICE_ID);
	if (!cfg_ptr)
	{
	  return -1;
	}

	// Initialize driver
	int32_t status = XScuGic_CfgInitialize(&INTCInst, cfg_ptr, cfg_ptr->CpuBaseAddress);
	if (status != XST_SUCCESS)
	{
	  return -1;
	}


	Xil_ICacheEnable();
	Xil_DCacheEnable();

	return 0;
}

/**
 * @brief  Invalidate Dcache (32Bit address)
 *
 * @param  addr Pointer to the addr
 * @param size Size in bytes
 */
void cpuInvalidateDCachebyAddrU32(uint32_t *addr, int32_t dsize)
{
	Xil_DCacheFlushRange((UINTPTR) addr, dsize);
}

/**
 * @brief  Invalidate Dcache (16Bit address)
 *
 * @param  addr Pointer to the addr
 * @param size Size in bytes
 * @retval None
 */
void cpuInvalidateDCachebyAddrU16(uint16_t *addr, int32_t dsize)
{
	Xil_DCacheFlushRange((UINTPTR) addr, dsize);
}

/**
 * @brief  Invalidate Dcache (8Bit address)
 *
 * @param  addr Pointer to the addr
 * @param size Size in bytes
 * @retval None
 */
void cpuInvalidateDCachebyAddrU8(uint8_t *addr, int32_t dsize)
{
	Xil_DCacheFlushRange((UINTPTR) addr, dsize);
}

/** @} */
