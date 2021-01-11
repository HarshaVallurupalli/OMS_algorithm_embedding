/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup calculation_parameters Calculation Parameters
 * @brief Parameters class for the calculations
 * @ingroup calculation
 *
 * @{
 */
#ifndef CALCULATION_PARAMETERS_H_
#define CALCULATION_PARAMETERS_H_

#include "ChipControl/ChipControl.h"
#include "Config/Config.h"
#include "AcquisitionInfo/AcquisitionInfo.h"


//! Calculation Parameters
/*!
 * Contains parameters needed for the calculation.
 */
class CalculationParameters
{
	public:
		CalculationParameters();
		void getValues(class TOF_COS_Context *context);

		AcquisitionInfo acquisitionInfo;
		uint32_t minAmplitude;               ///<Minimum amplitude
		uint32_t temperature;                ///<Actual chip temperature
		bool temperatureCompensationEnabled; ///<true, if the temperature compensation is enabled
		bool overrideFilter;                 ///<true, if the data can not be filtered, for example if the last image was taken a long time ago
		uint32_t numPixel;                   ///<Number of pixels
		uint32_t integrationTime3d;          ///<Integration time 3D that was used
		uint32_t integrationTimeGrayscale;   ///<Integration time grayscale that was used for the ambient light correction
};



#endif /* CALCULATION_PARAMETERS_H_ */

/** @} */
