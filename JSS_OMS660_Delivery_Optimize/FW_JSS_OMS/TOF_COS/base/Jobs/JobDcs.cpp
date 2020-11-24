/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup job_dcs
 *
 * @{
 */
#include <Jobs/JobDcs.h>
#include <Pixel/PixelToFDcs.h>

JobDcs::JobDcs()
{

}

/**
 * @brief Get DCS data
 *
 * This function acquires raw DCS data. The only thing applied to the data is sorting to have the image ready
 * to use.
 *
 * @param data Pointer to the pointer to the image data
 * @param acquisitionMetaData Reference to put meta data about the acquisition
 * @return status value from TypeReturnValue
 */
uint8_t JobDcs::getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData)
{
  //If not the desired data is in the memory, do a new acquisition
  if ((context->config->newAcquisitionRequired()) ||
        (context->dataAcquisition->hasAcquired(DataAcquisitionData_e::DATA_ACQUISITION_DATA_DCS) == false))
  {
    //Here start to acquire the image
    context->dataAcquisition->startDcs(false);
  }

  //These structures are needed for the further calculations
  updateDataStructures();

  //Pointer to write the results. The data will be directly sent without being copied
  uint8_t *targetBuffer = context->ramManager->getDoubleBufferedResultMemory();

  //Get the output including the interface overhead
  *data = context->ramManager->getOutputBuffer();

  uint32_t *dataDcs = nullptr;

  context->dataAcquisition->getDcsData(&dataDcs);

  //The DCS are just sorted. No other calculations
  context->calculation->rawDcsSorted(dataDcs, targetBuffer, calculationParameters, calculationResults);

  //Prepare already for the next acquisition
  context->ramManager->toggleOutputMemory();

  //Here start to acquire the image in the background
  context->dataAcquisition->startDcs(false);

  //Finalize the meta data
  context->acquisitionMetaData.sizeResult = context->acquisitionMetaData.acquisitionInfo.getFinalNumPixel() * sizeof(PixelToF_Dcs) * 4; //4DCS
  acquisitionMetaData = context->acquisitionMetaData;

  return getStatus();
}

/** @} */
