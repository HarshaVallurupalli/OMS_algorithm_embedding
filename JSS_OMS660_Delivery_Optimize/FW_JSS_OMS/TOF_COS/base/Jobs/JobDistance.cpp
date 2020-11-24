/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup job_distance
 *
 * @{
 */
#include <Jobs/JobDistance.h>

JobDistance::JobDistance()
{

}

/**
 * @brief Get distance data
 *
 * This function calculates distance data. The soft logic in the FPGA has already calculated distance and amplitude
 * and has compensated the distance. Here these additional steps are done:
 * - Mark invalid pixels with special codes
 * - Spatial and temporal filtering if enabled
 * - Omit the amplitude data
 *
 * @param data Pointer to the pointer to the image data
 * @param acquisitionMetaData Reference to put meta data about the acquisition
 * @return status value from TypeReturnValue
 */
uint8_t JobDistance::getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData)
{
	bool doTemporalHdrAcquisition = isTemporalHdrAcquisition();

	//If not the desired data is in the memory, do a new acquisition
	if ((context->config->newAcquisitionRequired()) ||
			((doTemporalHdrAcquisition == true) && (context->dataAcquisition->hasAcquired(DataAcquisitionData_e::DATA_ACQUISITION_DATA_DUAL_INTEGRATION_TIME) == false)) ||
		  ((doTemporalHdrAcquisition == false) && (context->dataAcquisition->hasAcquired(DataAcquisitionData_e::DATA_ACQUISITION_DATA_SINGLE_INTEGRATION_TIME) == false)))
	{
		//Here start to acquire the image
	  context->dataAcquisition->start3dGrayscaleImage(doTemporalHdrAcquisition);
	}

	//These structures are needed for the further calculations
	updateDataStructures();

	//Pointer to write the results. The data will be directly sent without being copied
	uint8_t *targetBuffer = context->ramManager->getDoubleBufferedResultMemory();
	uint8_t *lastResultBuffer = context->ramManager->getLastResultMemory();

	//Get the output including the interface overhead
	*data = context->ramManager->getOutputBuffer();

	//Get both 3d Pointers anyway, regardless if both integration times are used or not
	uint32_t *buffer3d0 = nullptr;
	uint32_t *buffer3d1 = nullptr;
	context->dataAcquisition->get3dDataTemporalHdr(&buffer3d0, &buffer3d1);

	//Prepare already for the next acquisition
	context->ramManager->toggleOutputMemory();

	//Here start to acquire the next image in the background
	context->dataAcquisition->start3dGrayscaleImage(doTemporalHdrAcquisition);

	//The calculation depends on the number of integration times used --> time consuming
	if (doTemporalHdrAcquisition)
	{
		context->calculation->distDualIntegrationTime(buffer3d0, buffer3d1, lastResultBuffer, targetBuffer, calculationParameters, calculationResults);
	}
	else
	{
		context->calculation->distSingleIntegrationTime(buffer3d0, lastResultBuffer, targetBuffer, calculationParameters, calculationResults);
	}

	//Finalize the meta data
	context->acquisitionMetaData.sizeResult = context->acquisitionMetaData.acquisitionInfo.getFinalNumPixel() * sizeof(PixelToF_Distance);
	acquisitionMetaData = context->acquisitionMetaData;

	//Filter the data --> time consuming
	context->calculation->processFilterOnDistance(reinterpret_cast<uint8_t *>(targetBuffer), lastResultBuffer, calculationParameters, calculationResults);

	//Algorithm Edit
	context->calculation->processAlgorithmOnDistance(reinterpret_cast<uint8_t *>(targetBuffer), lastResultBuffer, calculationParameters, calculationResults);

	return getStatus();
}

/** @} */
