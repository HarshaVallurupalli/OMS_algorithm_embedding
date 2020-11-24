/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup job_grayscale
 *
 * @{
 */
#include <Jobs/JobGrayscale.h>
#include <string.h>
#include "PixelToFGrayscale.h"

/**
 * @brief Start a new acquisition (internal)
 *
 * This function starts a new acquisition. The acquisition is just started and this
 * function returns while the data is acquired in the background with DMA and interrupts.
 */
void JobGrayscale::startAcquisitionInternal()
{
  //If not the desired data is in the memory, do a new acquisition
	if ((context->config->newAcquisitionRequired()) ||
		    (context->dataAcquisition->hasAcquired(DataAcquisitionData_e::DATA_ACQUISITION_DATA_GRAYSCALE) == false))
	{
		//Here start to acquire the image
	  context->dataAcquisition->startGrayscaleImage();
	}
}

/**
 * @brief Get grayscale data
 *
 * This function calculates grayscale data.
 *
 * @param data Pointer to the pointer to the image data
 * @param acquisitionMetaData Reference to put meta data about the acquisition
 * @return status value from TypeReturnValue
 */
uint8_t JobGrayscale::getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData)
{
	uint32_t numPixel = context->config->getNumPixel();

	//If not the desired data is in the memory, do a new acquisition
	if ((context->config->newAcquisitionRequired()) ||
	    (context->dataAcquisition->hasAcquired(DataAcquisitionData_e::DATA_ACQUISITION_DATA_GRAYSCALE) == false))
	{
	  //Here start to acquire the image
		context->dataAcquisition->startGrayscaleImage();
	}

	//These structures are needed for the further calculations
	updateDataStructures();

	//Get the Pointer to the grayscale data
	uint32_t *grayscaleData = nullptr;
	context->dataAcquisition->getGrayscaleData(&grayscaleData);

	//Pointer to write the results. The data will be directly sent without being copied
	uint16_t *resultBuffer = reinterpret_cast<uint16_t *>(context->ramManager->getDoubleBufferedResultMemory());

	//Feed in the data to the calculation. This converts it to 16Bits
	context->calculation->grayscale(grayscaleData, resultBuffer, numPixel);

  //Get the output including the interface overhead
	*data = context->ramManager->getOutputBuffer();

	context->acquisitionMetaData.sizeResult = context->config->getNumPixel() * sizeof(PixelToF_Grayscale);
	acquisitionMetaData = context->acquisitionMetaData;

	context->ramManager->toggleOutputMemory();

	//Debug test
	volatile fpgaDebug_t fpgaDebug = fpgaGetDebugData();

	//Here start to acquire the next image in the background
	context->dataAcquisition->startGrayscaleImage();

	return getStatus();
}

/** @} */
