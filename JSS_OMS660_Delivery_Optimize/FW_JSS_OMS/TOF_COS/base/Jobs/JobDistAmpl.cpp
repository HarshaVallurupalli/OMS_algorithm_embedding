/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup job_dist_ampl
 *
 * @{
 */
#include <Jobs/JobDistAmpl.h>
#include <sleep.h>


JobDistAmpl::JobDistAmpl()
{

}

/**
 * @brief Get distance and amplitude data
 *
 * This function calculates distance and amplitude data. The soft logic in the FPGA has already calculated distance and amplitude
 * and has compensated the distance. Here these additional steps are done:
 * - Mark invalid pixels with special codes
 * - Spatial and temporal filtering if enabled
 *
 * @param data Pointer to the pointer to the image data
 * @param acquisitionMetaData Reference to put meta data about the acquisition
 * @return status value from TypeReturnValue
 */
uint8_t JobDistAmpl::getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData)
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

  //Debug test
  volatile fpgaDebug_t fpgaDebug = fpgaGetDebugData();
  volatile uint32_t dcs0Corrected = context->ambientLightCompensation.getCorrectedValue(fpgaDebug.dcsRaw0, fpgaDebug.gsComp, acquisitionMetaData.acquisitionInfo.integrationTimeMultiplier);
  volatile uint32_t dcs1Corrected = context->ambientLightCompensation.getCorrectedValue(fpgaDebug.dcsRaw1, fpgaDebug.gsComp, acquisitionMetaData.acquisitionInfo.integrationTimeMultiplier);

	//Here start to acquire the next image in the background
  context->dataAcquisition->start3dGrayscaleImage(doTemporalHdrAcquisition);

  //The calculation depends on the number of integration times used --> time consuming
	if (doTemporalHdrAcquisition)
	{
		context->calculation->distAmpDualIntegrationTime(buffer3d0, buffer3d1, lastResultBuffer, targetBuffer, calculationParameters, calculationResults);
	}
	else
	{
		context->calculation->distAmpSingleIntegrationTime(buffer3d0, lastResultBuffer, targetBuffer, calculationParameters, calculationResults);
	}

	//Finalize the meta data
	context->acquisitionMetaData.sizeResult = context->acquisitionMetaData.acquisitionInfo.getFinalNumPixel() * sizeof(PixelToF_DistanceAmplitude);
	acquisitionMetaData = context->acquisitionMetaData;

	//Filter the data --> time consuming
	context->calculation->processFilterOnDistanceAmplitude(reinterpret_cast<uint8_t *>(targetBuffer), lastResultBuffer, calculationParameters, calculationResults);
	//Algorithm Edit
	context->calculation->processAlgorithmOnDistanceAmplitude(reinterpret_cast<uint8_t *>(targetBuffer), lastResultBuffer, calculationParameters, calculationResults);
	return getStatus();
}

/** @} */
