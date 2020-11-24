/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup calculation_parameters
 *
 * @{
 */
#include "CalculationParameters.h"
#include "Config/Config.h"
#include "TOF_COS_Context.h"
#include "DataAcquisition/DataAcquisition.h"

CalculationParameters::CalculationParameters()
{
  overrideFilter = 0;
	numPixel = 0;
	minAmplitude = 0;
	integrationTime3d = 0;
	integrationTimeGrayscale = 0;
	temperatureCompensationEnabled = true;
}

void CalculationParameters::getValues(TOF_COS_Context *context)
{
	acquisitionInfo = context->dataAcquisition->getAcquisitionInfo();

	minAmplitude = context->config->getMinAmplitude();
	numPixel = context->config->getNumPixel();
	integrationTime3d = context->config->getIntegrationTime3d(0);
	integrationTimeGrayscale = context->config->getIntegrationTimeGrayscale();
}




/** @} */
