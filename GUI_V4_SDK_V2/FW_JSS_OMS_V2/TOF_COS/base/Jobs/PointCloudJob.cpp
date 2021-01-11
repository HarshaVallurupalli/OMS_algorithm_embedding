/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup pointcloud_job
 *
 * @{
 */
 
#include "PointCloudJob.h"

//Static variables
TOF_COS_Context *PointCloudJob::context;
CalculationParameters PointCloudJob::calculationParameters;
CalculationResults PointCloudJob::calculationResults;
 
PointCloudJob::PointCloudJob()
{

}
 
/**
 * @brief Get the status
 *
 * Used to detect, if an error has happened in the used classes like
 * - chip control
 * - data acquisition
 *
 * @return TOF_COS_STATUS_OK Everything ok
 * @return TOF_COS_STATUS_ERROR_SENSOR_COMMUNIATION Error while communicating with the TOF imager with I2C
 * @return TOF_COS_ERROR_DATA_ACQUISITION Error while receiving data from the TOF imager with TCMI
 */
uint8_t PointCloudJob::getStatus()
{
  TypeInternalReturnValue status = context->chipControl->getAndClearStatus();
  if (status != TypeInternalReturnValue::STATUS_OK)
  {
    return TypeReturnValue::TOF_COS_STATUS_ERROR_SENSOR_COMMUNICATION;
  }
  
  status = context->dataAcquisition->getAndClearStatus();
  if (status != TypeInternalReturnValue::STATUS_OK)
  {
    return TypeReturnValue::TOF_COS_STATUS_ERROR_DATA_ACQUISITION;
  }

  return TypeReturnValue::TOF_COS_STATUS_OK;
}

/**
 * @brief Check if temporal HDR is enabled
 *
 * @retval true Temporal HDR is enabled
 * @retval false Temporal HDR is disabled
 * @return Temporal HDR enabled or disabled
 */
bool PointCloudJob::isTemporalHdrAcquisition() const
{
  bool doTemporalHdrAcquisition = (context->config->getIntegrationTime3d(1) > 0) && (context->config->getHdr().isSpatialHdr() == false);

  return doTemporalHdrAcquisition;
}

/**
 * @brief Inject the context
 *
 * The context is common for all jobs, therefore static
 *
 * @param context Pointer to the context
 */
void PointCloudJob::setContext(class TOF_COS_Context *context)
{
   PointCloudJob::context = context;
}

/**
 * @brief Start a new acquisition
 *
 * This function starts a new acquisition. The acquisition is just started and this
 * function returns while the data is acquired in the background with DMA and interrupts.
 */
void PointCloudJob::startAcquisition()
{
  startAcquisitionInternal();
}

/**
 * @brief Start a new acquisition (internal)
 *
 * This function starts a new acquisition. The acquisition is just started and this
 * function returns while the data is acquired in the background with DMA and interrupts.
 *
 * This function may be overriden if a specific job needs a specific start acquisition function.
 */
void PointCloudJob::startAcquisitionInternal()
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
}

/**
 * @brief Update data structures
 *
 * This function updates two data structures:
 * - The calculation parameters; values needed for the calculations
 * - The acquisition meta data; information about the acquisition like ROI, binning, ...
 */
void PointCloudJob::updateDataStructures()
{
	//calculationParameters.overrideFilter = overrideFilter;

	calculationParameters.getValues(context);

	context->acquisitionMetaData.acquisitionInfo = context->dataAcquisition->getAcquisitionInfo();
	//context->acquisitionMetaDataInProgress.drnuCompensated = calculationParameters.drnuCompenationEnabled;
	context->acquisitionMetaData.temperatureCompensated = calculationParameters.temperatureCompensationEnabled;
	//context->acquisitionMetaDataInProgress.ambientLightCompensated = calculationParameters.ambientLightCompensationEnabled;
}

/** @} */
