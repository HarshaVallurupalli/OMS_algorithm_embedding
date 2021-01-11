/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup fpga
 *
 * @{
 */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include "fpga.h"
#include "hal/timestamp/timestamp.h"
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/types.h>
#include <stdint.h>
#include "xgpio.h"
#include "xaxidma.h"
#include "xparameters.h"
#include "xscugic.h"
#include "drivers/reg_bank.h"
#include "drivers/fpga_ctrl.h"
#include <stdbool.h>

//Full range of 2pi with multiplier 1 = 2pi * (2 << 13)
#define FULL_RANGE_2PI 51470


/****  Xilinx specific data   ****/
XAxiDma AxiDma_SORT; // Sort

// interrupt signals
volatile int interrupt_SORTdone = 0;

//Data pointers
volatile uint32_t *pDataBuffer_GS;
volatile uint32_t *pDataBuffer_DCS;
volatile uint32_t *pDataBuffer_SORT;

//DMA transfer size
volatile uint32_t DMAnumBytes;

///Callback function to call when an image has been acquired
static void(*callbackFunction)(void *);

///Argument pointer to pass to the callback function
static void *callbackArg;

///Flag to indicate that DCS mode is used (raw DCS, no distance/amplitude calculations and compensations)
static bool dcsMode = false;

//This variable is defined in the file cpu.c
extern XScuGic INTCInst;

//Enum for the IP control block setup
enum
{
	CONTROL_BLOCK_MODE_GRAYSCALE = 1, CONTROL_BLOCK_MODE_TOF = 0, CONTROL_BLOCK_MODE_DCS = 2, CONTROL_BLOCK_MODE_DUALMGX = 3
};

/**
 * @brief Register callback
 *
 * The callback function gets called, when the image transfer to the RAM is finished
 *
 * @param callback Pointer to the callback function to call
 * @param arg Pointer to the argument that will be given to the callback
 */
void fpgaRegisterCallback(void(*callback)(void *), void *arg)
{
  callbackFunction = callback;
  callbackArg = arg;
}

/**
 * @brief Init the DMA for the sorting.
 *
 * Call this function at system start to init the xilinx dma.
 * Scatter Gatter DMA
 *
 * @retval -1 Error
 * @retval 0 OK
 * @return Result of the initialization
 */
int8_t initDmaSort(void) // SORT; W; SG
{

	XAxiDma_Config *CfgPtr;
	int Status;

	/* Initialize the XAxiDma device.
	 */
	CfgPtr = XAxiDma_LookupConfig(XPAR_AXI_DMA_SG_SORT_DEVICE_ID);
	if (!CfgPtr)
	{
		xil_printf("No config found for %d\r\n", XPAR_AXI_DMA_SG_SORT_DEVICE_ID);
		return -1;
	}

	Status = XAxiDma_CfgInitialize(&AxiDma_SORT, CfgPtr);
	if (Status != XST_SUCCESS)
	{
		xil_printf("Initialization failed %d\r\n", Status);
		return -1;
	}

	/* Enable interrupt for S2MM
	 */
	XAxiDma_IntrEnable(&AxiDma_SORT, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DEVICE_TO_DMA);
	XAxiDma_IntrDisable(&AxiDma_SORT, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DMA_TO_DEVICE);

	return 0;
}

/**
 * @brief Helper function to init the DMA interrupt
 *
 */
static int32_t initInterruptS2mm(XScuGic* p_intc_inst, int intc_device_id, XAxiDma* p_dma_inst, int s2mm_intr_id, Xil_ExceptionHandler handler)
{

	// Local variables
	int32_t            status = 0;

	// Set interrupt priorities and trigger type
	XScuGic_SetPriorityTriggerType(p_intc_inst, s2mm_intr_id, 0xA0, 0x3);

	// Connect handlers
	status = XScuGic_Connect(p_intc_inst, s2mm_intr_id, handler, p_dma_inst);
	if (status != XST_SUCCESS)
	{
		xil_printf("ERROR! Failed to connect DMAIntrHandler_DCSwrite to the interrupt controller.\r\n", status);
		return XST_FAILURE;
	}

	//Enable all interrupts
	XScuGic_Enable(p_intc_inst, s2mm_intr_id);

	//Initialize exception table and register the interrupt controller handler with exception table
	Xil_ExceptionInit();
	Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_INT, (Xil_ExceptionHandler)XScuGic_InterruptHandler, p_intc_inst);

	// Enable non-critical exceptions
	Xil_ExceptionEnable();

	return XST_SUCCESS;
}

/**
 * @brief Set the address of the distance correction data
 *
 * @param address Address of the distance correction data
 */
void fpgaSetCorrectionAddress(const uint32_t address)
{
  REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_DIST_CORR_ADDR, address);
}

/**
 * @brief Set the ALU values
 *
 * @param aluMin: Min value for atan2 input 8b
 * @param aluAmp: Amplitude multiplication value 12b
 * @param aluDist: Distance multiplication value 12b
 */
void fpgaSetAluValues(const uint32_t aluMin, const uint32_t aluAmp, const uint32_t aluDist)
{
	uint32_t regVal = (aluMin << FPGA_CONFIG_SHIFT_ALU_MIN) | (aluAmp << FPGA_CONFIG_SHIFT_ALU_AMP) | (aluDist << FPGA_CONFIG_SHIFT_ALU_DIST);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ALU_ADDR, regVal);
}

/**
 * @brief Set the ambient light correction settings
 *
 * The parameter is: INTM/KAL, 16 bits with 8 bits fixed point
 *
 * @param parameter Parameter to set
 */
void fpgaSetAmbientLightCorrection(const uint32_t parameter)
{
	uint32_t regVal = (parameter << FPGA_CONFIG_SHIFT_AMBIENT_LIGHT_COMPENSATION);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_AMBIENT_ADDR, regVal);
}

/**
 * @brief Set the temperature offset correction
 *
 * @param temperatureOffset offset
 */
void fpgaSetPreCorrectionOffset(const int32_t offset)
{
  REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_TEMP_ADDR, offset);
}

/**
 * @brief Set a fixed offset to use
 *
 * @param offset Offset to use
 */
void fpgaSetPostCorrectionOffset(const int32_t offset)
{
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_CONST_ADDR, offset);
}

/**
 * @brief set multiplier to one
 *
 * This function sets the multiplier / max value to one. this is used during calibration
 *
 */
void fpgaSetMultiplierToOne()
{
	fpgaSetDistanceRange(FULL_RANGE_2PI);
}

/**
 * @brief Set distance range
 *
 * This function sets the distance range; this is the overflow point.
 *
 * @param distanceRange distance range to set
 */
void fpgaSetDistanceRange(const uint32_t distanceRange)
{
	uint32_t tempReg = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,REG_BANK_S00_AXI_SLV_REG9_OFFSET);
	tempReg &= ~FPGA_CONFIG_MASK_DISTANCE_RANGE;
	tempReg |= (distanceRange << FPGA_CONFIG_SHIFT_DISTANCE_RANGE);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,REG_BANK_S00_AXI_SLV_REG9_OFFSET, tempReg);
}


/**
 * @brief Set interference threshold
 *
 * Threshold for the interference flag in the result.
 *
 * @param threshold Threshold to set
 */
void fpgaSetInterferenceThreshold(const uint32_t threshold)
{
  uint32_t tempReg = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,REG_BANK_S00_AXI_SLV_REG9_OFFSET);
  tempReg &= ~FPGA_CONFIG_MASK_INTERFERENCE;
  tempReg |= (threshold << FPGA_CONFIG_SHIFT_INTERFERENCE);
  REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,REG_BANK_S00_AXI_SLV_REG9_OFFSET, tempReg);
}

/**
 * @brief Get max value
 *
 * This function reads the max value for the distance
 *
 * @return maxValue max value of the distance
 */
uint32_t fpgaGetDistanceRange()
{
	uint32_t distanceRange = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,REG_BANK_S00_AXI_SLV_REG9_OFFSET);
	distanceRange = (distanceRange & FPGA_CONFIG_MASK_DISTANCE_RANGE) >> FPGA_CONFIG_SHIFT_DISTANCE_RANGE;

	return distanceRange;
}

/**
 * @brief Convert bool to integer
 *
 * true is defined as != 0, even though its normally 1, so this function is responsible to make
 * sure that true --> 1, false --> 0
 *
 * @param value bool value
 * @retval 0 / 1 for false / true
 */
uint32_t boolToInteger(const bool value)
{
	if (value)
	{
		return 1;
	}

	return 0;
}

/**
 * @brief Enable/disable the grayscale compensation
 *
 * @param enabled Enable/disable grayscale compensation
 */
void fpgaSetGrayscaleCompensationEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.grayscaleCompensationEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Get grayscale compensation enabled
 *
 * @return grayscale compensation enabled
 */
bool fpgaGetGrayscaleCompensationEnabled(void)
{
  fpgaEnableRegister_u fpgaEnableRegister;
  fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);

  return fpgaEnableRegister.bits.grayscaleCompensationEnabled;
}

/**
 * @brief Enable/disable bad pixel correction on DCS level
 *
 * This is interpolating bad pixels
 *
 * @param enabled Enable/disable bad pixel correction
 */
void fpgaSetBadPixelInterpolationDCSEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.badpixelCorrectionDCSEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable interpolation of saturated pixel
 *
 * This is interpolating saturated pixels
 *
 * @param enabled Enable/disable interpolation of saturated pixel
 */
void fpgaSetRemoveSatPixEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.RemoveSatEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable interpolation of ADC saturated pixel
 *
 * This is interpolating ADC saturated pixels
 *
 * @param enabled Enable/disable interpolation of ADC saturated pixel
 */
void fpgaSetADCInterpolationEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.ADCInterEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable bad pixel correction on Distance level
 *
 * This is interpolating bad pixels
 *
 * @param enabled Enable/disable bad pixel correction
 */
void fpgaSetBadPixelInterpolationDistEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.badpixelCorrectionDistEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable image binning
 *
 * This is binning on DCS level
 *
 * @param enabled Enable/disable binning
 */
void fpgaSetImageBinningEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.imageBinningEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable adc overflow detection
 *
 * @param enabled Enable/disable adc overflow detection
 */
void fpgaSetAdcOverflowDetection(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.adcOverflowEnabled = boolToInteger(enabled);
	fpgaEnableRegister.bits.adcUnderflowEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable grayscale subtract
 *
 * @param enabled Enable/disable grayscale subtract
 */
void fpgaSetGrayscaleSubtractEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.grayscaleSubtractEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Get grayscale subtract enabled
 *
 * @return Grayscale subtract enabled/disabled
 */
bool fpgaGetGrayscaleSubtractEnabled(void)
{
  fpgaEnableRegister_u fpgaEnableRegister;
  fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
  return fpgaEnableRegister.bits.grayscaleSubtractEnabled;
}

/**
 * @brief Enable/disable pre correction offset
 *
 * @param enabled Enable/disable offset before the correction is done
 */
void fpgaSetPreCorrectionOffsetEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.preCorrectionOffsetEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable post correction offset
 *
 * @param enabled Enable/disable offset after the correction
 */
void fpgaSetPostCorrectionOffsetEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.postCorrectionOffsetEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable distance correction
 *
 * @param enabled Enable/disable distance correction
 */
void fpgaSetDistanceCorrectionEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.distanceCorrectionEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable ambient light correction
 *
 * @param enabled Enable/disable ambient light correction
 */
void fpgaSetAmbientCorrectionEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.ambientCorrectionEnabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Enable/disable the softlogic
 *
 * @param enabled Enable/disable
 */
void fpgaSetEnabled(const bool enabled)
{
	fpgaEnableRegister_u fpgaEnableRegister;
	fpgaEnableRegister.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR);
	fpgaEnableRegister.bits.enabled = boolToInteger(enabled);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_ENABLE_ADDR, fpgaEnableRegister.registerValue);
}

/**
 * @brief Set the DLL step
 *
 * @param dllStep DLL step
 */
void fpgaSetDllStep(const uint32_t dllStep, const uint32_t nbofdllSteps)
{
	// Distance correction DLL
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_DIST_DLL_ADDR, (nbofdllSteps << 16) + dllStep);

}

/**
 * @brief Helper function: Init the IP control block for the acquisition
 *
  * @param numPixel Expected number of pixels
 * @param width Width of the image in pixels
 * @param mode Mode of acquisition: TOF, Grayscale, DCS
 */
static void initFpgaControlBlock(const uint32_t numPixel, const uint32_t width, const int32_t mode)
{
//	//Reset
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_CTRL_ADDR, FPGA_CONFIG_MASK_RESET);
	usleep(10);
//
//	// Init bad pixel table calculations
//	uint32_t regVal = FPGA_CONFIG_MASK_BADPIX;
//	regVal |= (numPixel << FPGA_CONFIG_SHIFT_NUM_PIXEL);
//	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_CTRL_ADDR,  regVal);
//	usleep(200);

	//Init the control register to the value common for all modes
	uint32_t regVal = FPGA_CONFIG_MASK_UPDATE;

	switch (mode)
	{
	case CONTROL_BLOCK_MODE_GRAYSCALE:
		regVal |= (numPixel << FPGA_CONFIG_SHIFT_NUM_PIXEL);
		regVal |= (width << FPGA_CONFIG_SHIFT_PIXEL_PER_LINE); // Number of pixel per line
		regVal |= FPGA_CONFIG_VAL_MODE_GRAY;
		break;
	case CONTROL_BLOCK_MODE_TOF:
		regVal |= (numPixel << FPGA_CONFIG_SHIFT_NUM_PIXEL);
		regVal |= (width << FPGA_CONFIG_SHIFT_PIXEL_PER_LINE); // Number of pixel per line
		regVal |= FPGA_CONFIG_VAL_MODE_TOF;
		break;
	case CONTROL_BLOCK_MODE_DCS:
		regVal |= (numPixel << FPGA_CONFIG_SHIFT_NUM_PIXEL);
		regVal |= (width << FPGA_CONFIG_SHIFT_PIXEL_PER_LINE); // Number of pixel per line
		regVal |= FPGA_CONFIG_VAL_MODE_DCS;
		break;		
	case CONTROL_BLOCK_MODE_DUALMGX:
		regVal |= (numPixel << FPGA_CONFIG_SHIFT_NUM_PIXEL);
		regVal |= (width << FPGA_CONFIG_SHIFT_PIXEL_PER_LINE); // Number of pixel per line
		regVal |= FPGA_CONFIG_VAL_MODE_DUALMGX;
		break;
	default:
		regVal |= (numPixel << FPGA_CONFIG_SHIFT_NUM_PIXEL);
		regVal |= (width << FPGA_CONFIG_SHIFT_PIXEL_PER_LINE); // Number of pixel per line
		regVal |= FPGA_CONFIG_VAL_MODE_GRAY;
		break;
	}

	//Write the control register
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_CTRL_ADDR, regVal);
}

/**
 * @brief helper function to start the scatter gatter DMA
 *
 * @param pDest Pointer to the memory where the DMA writes data into
 * @param pSGDesc Pointer to the scatter gatter descriptors
 * @param numBytes Number of bytes to transfer
 */
static void getImageWithSGDma(volatile uint32_t *pDest, volatile uint32_t *pSGDesc, const uint32_t numBytes)
{
	//This flush has to be done, otherwise the DMA transfer does not work
	Xil_DCacheFlushRange((UINTPTR) pDest, numBytes);

	// GS Sort DMA
	(void) XAxiDma_Reset(&AxiDma_SORT);

	// Reset SORT DMA
	(void) XAxiDma_WriteReg(XPAR_AXI_DMA_SG_SORT_BASEADDR, (XAXIDMA_RX_OFFSET + XAXIDMA_CR_OFFSET),0x04);
	(void) XAxiDma_WriteReg(XPAR_AXI_DMA_SG_SORT_BASEADDR, (XAXIDMA_RX_OFFSET + XAXIDMA_CR_OFFSET),0x00);
	
	 // Set DMAs to cyclic mode
	(void) XAxiDma_SelectCyclicMode(&AxiDma_SORT, XAXIDMA_DEVICE_TO_DMA, TRUE);

	// Set Current Descriptor
	(void) XAxiDma_WriteReg(XPAR_AXI_DMA_SG_SORT_BASEADDR,XAXIDMA_RX_OFFSET + XAXIDMA_CDESC_MSB_OFFSET, 0x0);
	(void) XAxiDma_WriteReg(XPAR_AXI_DMA_SG_SORT_BASEADDR,XAXIDMA_RX_OFFSET + XAXIDMA_CDESC_OFFSET, (u32)pSGDesc);

	// Start DMA & Enable Interrupts
	(void) XAxiDma_WriteReg(XPAR_AXI_DMA_SG_SORT_BASEADDR, (XAXIDMA_RX_OFFSET + XAXIDMA_CR_OFFSET),XAXIDMA_IRQ_ALL_MASK+0x11); // Start DMA -> 0x11 for cyclic mode and start

	// Set Tail descriptor to really start DMA (Cyclic mode)
	(void) XAxiDma_WriteReg(XPAR_AXI_DMA_SG_SORT_BASEADDR,XAXIDMA_RX_OFFSET + XAXIDMA_TDESC_MSB_OFFSET, 0x0);
	(void) XAxiDma_WriteReg(XPAR_AXI_DMA_SG_SORT_BASEADDR,XAXIDMA_RX_OFFSET + XAXIDMA_TDESC_OFFSET, (u32)pSGDesc+FPGA_CONFIG_SG_DESCR_LENGTH);
}

/**
 * @brief Set sensor size
 *
 * This is needed to set the size of the full sensor. Later if a ROI is used, the soft logic can automatically
 * use the compensation data of the ROI.
 *
 * @param width Width of the sensor in pixels
 * @param height Height of the sensor in pixels
 */
void fpgaSetSensorSize(const uint32_t width, const uint32_t height)
{
  fpgaFullRoi_u fpgaFullRoi;

  fpgaFullRoi.registerValue = 0;
  fpgaFullRoi.bits.height = height;
  fpgaFullRoi.bits.width = width;

  REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_FULL_ROI_ADDR, fpgaFullRoi.registerValue);
}

/**
 * @brief Set ROI
 *
 * This is needed so the soft logic knows which calibration data to use.
 *
 * @param x_TL X coordinate top left
 * @param y_TL Y coordinate top left
 * @param x_BR X coordinate bottom right
 * @param y_BR Y coordinate bottom right
 */
static void fpgaSetRoi(const uint32_t x_TL, const uint32_t y_TL, const uint32_t x_BR, const uint32_t y_BR)
{
  fpgaRoi_u fpgaRoi;

  fpgaRoi.bits.x_BR = x_BR;
  fpgaRoi.bits.x_TL = x_TL;
  fpgaRoi.bits.y_BR = y_BR;
  fpgaRoi.bits.y_TL = y_TL;

  REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_ROI_SETTINGS_ADDR, fpgaRoi.registerValue);
}

/**
 * @brief Start acquisition of a grayscale image
 *
 * This function starts the acquisition of a grayscale image. It just setups the DMAs. No shutter is
 * sent to the sensor.
 *
 *
 * @param pDest_GS Pointer to the buffer for the grayscale data
 * @param pDest_DCS Pointer to the buffer for the DCS data
 * @param pDest_SORT Pointer to the result data (sorted)
 * @param pSGDesc Pointer to the scatter gatter DMA desriptors
 * @param pCalibration_GS Pointer to the calibration date for grayscale
 * @param acquisitionSettings Struct containing the settings needed for the acquisition in the soft logic
 * @return 0
 */
void fpgaStartGrayscale(volatile uint32_t *pDest_GS, volatile uint32_t *pDest_SORT, volatile uint32_t *pSGDesc, volatile uint32_t *pCalibration_GS, fpgaAcquisitionSettings_t acquisitionSettings)
{
  uint32_t numPixel = acquisitionSettings.width * acquisitionSettings.height;

	interrupt_SORTdone = 0;

	initFpgaControlBlock(numPixel, acquisitionSettings.width, CONTROL_BLOCK_MODE_GRAYSCALE);

	pDataBuffer_GS = pDest_GS;
	DMAnumBytes = acquisitionSettings.numBytes;

	// Set DMA Addresses
	//We use the DCS address for the grayscale calibration data
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,FPGA_CONFIG_DCS_ADDR, pCalibration_GS);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,FPGA_CONFIG_GS_ADDR, pDataBuffer_GS);

	getImageWithSGDma(pDest_SORT, pSGDesc, acquisitionSettings.numBytes);

	dcsMode = false;

	Xil_DCacheFlushRange((UINTPTR) pDest_GS, acquisitionSettings.numBytes);
	Xil_DCacheFlushRange((UINTPTR) pDest_SORT, acquisitionSettings.numBytes);

}

/**
 * @brief Start the acquisition of distance and amplitude
 *
 * This function starts the acquisition of distance and amplitude.
 *
 * @param pDest_GS Pointer to the buffer for the grayscale data
 * @param pDest_DCS Pointer to the buffer for the DCS data
 * @param pDest_SORT Pointer to the result data (sorted)
 * @param pSGDesc Pointer to the scatter gatter DMA desriptors
 * @param acquisitionSettings Struct containing the settings needed for the acquisition in the soft logic
 * @return 0
 */
void fpgaStartDistanceAmplitude(volatile uint32_t *pDest_GS, volatile uint32_t *pDest_DCS, volatile uint32_t *pDest_SORT, volatile uint32_t *pSGDesc, fpgaAcquisitionSettings_t acquisitionSettings)
{
	uint32_t numPixel = acquisitionSettings.width * acquisitionSettings.height;

	interrupt_SORTdone = 0;

	initFpgaControlBlock(numPixel, acquisitionSettings.width, CONTROL_BLOCK_MODE_TOF);

	//Set the size of the whole sensor (full ROI)
	//fpgaSetSensorSize(acquisitionSettings.width, acquisitionSettings.height);

	//Set the ROI. Not yet implemented. Use test values here.
	//fpgaSetRoi(0, 0, 319, 119);

	pDataBuffer_GS = pDest_GS;
	pDataBuffer_DCS = pDest_DCS;
	DMAnumBytes = acquisitionSettings.numBytes;

	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,FPGA_CONFIG_DCS_ADDR, pDataBuffer_DCS);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,FPGA_CONFIG_GS_ADDR, pDataBuffer_GS);

	dcsMode = false;

	Xil_DCacheFlushRange((UINTPTR) pDest_DCS, acquisitionSettings.numBytes);
	Xil_DCacheFlushRange((UINTPTR) pDest_SORT, acquisitionSettings.numBytes);

	getImageWithSGDma(pDest_SORT, pSGDesc, acquisitionSettings.numBytes);

}

void fpgaStartDualMGX(uint32_t *pDest_GS, uint32_t *pDest_DCS, uint32_t *pDest_SORT, uint32_t *pSGDesc, const volatile uint32_t width, const volatile uint32_t height, const uint32_t numBytes)
{
	interrupt_SORTdone = 0;

	uint32_t numPixel = numBytes / sizeof(uint32_t);

	initFpgaControlBlock(numPixel, width, CONTROL_BLOCK_MODE_DUALMGX);

	pDataBuffer_GS = pDest_GS;
	pDataBuffer_DCS = pDest_DCS;
	DMAnumBytes = numBytes;

	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,FPGA_CONFIG_DCS_ADDR, pDataBuffer_DCS);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,FPGA_CONFIG_GS_ADDR, pDataBuffer_GS);

	dcsMode = false;

	Xil_DCacheFlushRange((UINTPTR) pDest_DCS, numBytes);
	Xil_DCacheFlushRange((UINTPTR) pDest_SORT, numBytes);

	getImageWithSGDma(pDest_SORT, pSGDesc, numBytes);

}

/**
 * @brief Start the acquisition of raw DCSs
 *
 * This function starts the acquisition of raw DCS data.
 *
 * @param pDest Pointer to the destinaction buffer
 * @param width Width of the image in pixels
 * @param height Height of the image in pixels
 * @param numBytes number of bytes for all DCS images
 * @return 0
 */
void fpgaStartDCS(volatile uint32_t *pDest, const volatile uint16_t width, const volatile uint16_t height, const uint32_t numBytes)
{
	uint32_t numPixel = numBytes / sizeof(uint32_t) / 4; // Programm size of 1 DCS

	initFpgaControlBlock(numPixel, width, CONTROL_BLOCK_MODE_DCS);

	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR,FPGA_CONFIG_GS_ADDR, pDest);

	//Write gsWrEofDone flag to 1 to clear it. It will be set at the end of the DCS acquisition. The DCS mode uses the GS blocks and therefore the GS bit is used and not the DCS bit
	fpgaDmaStatus_u fpgaDmaStatus;
	fpgaDmaStatus.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_DMA_STATUS_ADDR);
	fpgaDmaStatus.bits.gsWrEofDone = 1;
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_DMA_STATUS_ADDR, fpgaDmaStatus.registerValue);

	dcsMode = true;

	Xil_DCacheFlushRange((UINTPTR) pDest, numBytes);

}

/**
 * @brief Read if FPGA acquisition is busy
 *
 * This function returns if the FPGA acquisition is busy or not. This must be handled different
 * in case of DCS mode (polled) or distance/amplitude/grayscale (interrupt driven).
 *
 * @retval true Acquisition busy
 * @retval false Acquisition not busy
 * @return Acquisition busy or not
 */
bool fpgaAcquisitionIsBusy(void)
{
	if ((dcsMode == false) && (interrupt_SORTdone == 0))
	{
		return true;
	}
	else if ((dcsMode) && fpgaDcsAcquisitionIsBusy())
	{
	  return true;
	}

	return false;
}

/**
 * @brief Read if FPGA DCS acquisition is busy
 *
 * This function returns if the FPGA DCS acquisition is busy or not. This is
 * an extra function just for DCS mode.
 *
 * @retval true Acquisition busy
 * @retval false Acquisition not busy
 * @return Acquisition busy or not
 */
bool fpgaDcsAcquisitionIsBusy(void)
{
  fpgaDmaStatus_u fpgaDmaStatus;

  fpgaDmaStatus.registerValue = REG_BANK_mReadReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_DMA_STATUS_ADDR);

  //The DCS mode uses the GS blocks and therefore the GS bit is used and not the DCS bit
  if (fpgaDmaStatus.bits.gsWrEofDone == 0)
  {
    return true;
  }

  return false;
}

/**
 * @brief Wait for DCMI
 *
 * This function does a blocking wait until the DCMI reception of the data is finished.
 *
 * @param timeout Timeout in milliseconds
 * @retval -1 Transfer timed out
 * @retval 0 Transfer ok
 * @return Wait ok or not
 */
int8_t fpgaWaitAcquisitionBlocking(const int32_t timeout)
{
	int32_t timestampAtStart = timestampGetMsCounter();

	while (fpgaAcquisitionIsBusy())
	{
		int32_t timeStampNow = timestampGetMsCounter();

		if ((timeStampNow - timestampAtStart) > timeout)
		{
			return -1;
		} /* timeout, cancel -----------------------------------> */
	}

	return 0;
}

/**
 * @brief Read the FPGA debug data
 *
 * This is useful to check the calculations done in the FPGA.
 *
 * @return FPGA debug structure containing the calculation data
 */
fpgaDebug_t fpgaGetDebugData(void)
{
#ifdef XPAR_AXI_BRAM_CTRL_DBG_UNIT_S_AXI_BASEADDR
  fpgaDebug_t *fpgaDebug = (fpgaDebug_t *)XPAR_AXI_BRAM_CTRL_DBG_UNIT_S_AXI_BASEADDR;

  Xil_DCacheFlushRange((UINTPTR) fpgaDebug, sizeof(fpgaDebug));

  return *fpgaDebug;
#else
  fpgaDebug_t fpgaDebug;
  return fpgaDebug;
#endif
}

/**
 * @brief IRQ handler for sorting IRQ
 *
 * Get's called at the end; when this function is called, all the data is in the RAM.
 */
static void DMAIntrHandler_SORT(void *CallBackRef)
{
	interrupt_SORTdone = 1;

	// Disable Interrupts
	XAxiDma_IntrDisable(&AxiDma_SORT, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DEVICE_TO_DMA);

	// Get and ACK Interrupts
	u32 irq_status = XAxiDma_IntrGetIrq(&AxiDma_SORT, XAXIDMA_DEVICE_TO_DMA);
	XAxiDma_IntrAckIrq(&AxiDma_SORT, irq_status, XAXIDMA_DEVICE_TO_DMA);

	// Reenable Interrupts
	XAxiDma_IntrEnable(&AxiDma_SORT, XAXIDMA_IRQ_ALL_MASK, XAXIDMA_DEVICE_TO_DMA);

	//Notify the receiver with the callback
	callbackFunction(callbackArg);
}

/**
 * @brief Scale a distance
 *
 * Scale a distance that is at full range to the current range
 *
 * @param distanceFullRange Distance in full range of the FPGA ALU
 * @return Distance in current range (e.g. mm)
 */
uint32_t fpgaScaleDistance(const uint32_t distanceFullRange)
{
  uint32_t result =  (fpgaGetDistanceRange() * distanceFullRange) / FULL_RANGE_2PI;

  return result;
}

/**
 * @brief Set the debug unit
 *
 * Defines the pixel that shall be sampled at every processing block and written to a bram
 *
 * @param pixel index to sample
 */
void fpgaSetDebugPixel(const uint32_t pxlIndex)
{
	uint32_t regVal = (pxlIndex << FPGA_DEBUG_SHIFT_PIXEL_INDEX) | FPGA_DEBUG_MASK_ENA;
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_DEBUG_PXL_ADDR, regVal);
}

/**
 * @brief Initialize this module
 *
 * Call this function before using the FPGA calculations and data acquisition.
 *
 * @retval -1 Init error
 * @retval 0 Init ok
 * @return Result of the initialization
 */
int8_t fpgaInit(void)
{
  int32_t status;

	//Initialize the DMA device.
	status = initDmaSort();
	if (status < 0)
	{
	  return -1;
	}

	// Init interrupts
	status = initInterruptS2mm(&INTCInst,XPAR_PS7_SCUGIC_0_DEVICE_ID,&AxiDma_SORT,XPAR_FABRIC_AXI_DMA_SG_SORT_S2MM_INTROUT_INTR,(Xil_InterruptHandler)DMAIntrHandler_SORT);

	fpgaSetAluValues(0xFF, 0x800, 0x800);
	fpgaSetAmbientLightCorrection((1 * 256) / 40); //Test value with intm = 1 and kal = 40
	fpgaSetPreCorrectionOffset(0);
	fpgaSetDllStep(0x0405, 0x32);
	fpgaSetPostCorrectionOffset(0);

	fpgaSetAdcOverflowDetection(true);
	fpgaSetGrayscaleSubtractEnabled(false);
	fpgaSetPostCorrectionOffsetEnabled(true);
	fpgaSetPreCorrectionOffsetEnabled(true);
	fpgaSetImageBinningEnabled(false);
	fpgaSetDistanceCorrectionEnabled(false);
	fpgaSetEnabled(true);
	fpgaSetAmbientCorrectionEnabled(false);
	fpgaSetBadPixelInterpolationDistEnabled(false);
	fpgaSetBadPixelInterpolationDCSEnabled(false);
	fpgaSetRemoveSatPixEnabled(false); // Up to 2 saturated pixels in a row can be compensated
	fpgaSetADCInterpolationEnabled(false); // Up to 2 ADC saturated pixels can be compensated

	fpgaSetCorrectionAddress(0); //No address
	fpgaSetDistanceRange(12500); //Default, will be set later

	fpgaSetInterferenceThreshold(200);
	fpgaSetGrayscaleCompensationEnabled(false);


	fpgaSetDebugPixel(10*320+160); 	// define debug pixel


	// Init bad pixel table calculations
	uint32_t regVal = FPGA_CONFIG_MASK_BADPIX;
	regVal |= ((320*240) << FPGA_CONFIG_SHIFT_NUM_PIXEL);
	REG_BANK_mWriteReg(XPAR_REG_BANK_0_S00_AXI_BASEADDR, FPGA_CONFIG_CTRL_ADDR,  regVal);
	usleep(1000);

	return 0;
}

/** @} */
