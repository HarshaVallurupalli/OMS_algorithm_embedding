/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup integration_time_finder Integration Time Finder
 * @brief Helper Class to finde the integration time
 * @ingroup calibration
 *
 * @{
 */
#ifndef INTEGRATION_TIME_FINDER_H_
#define INTEGRATION_TIME_FINDER_H_

#include <stdint.h>
#include "TypeReturnValue.h"
#include "ChipControl/ChipControl.h"
#include "Calibration_Calculation.h"
#include "TypeInternalReturnValue.h"
#include "TOF_COS_Context.h"

//! Finde the integration time
/*!
 * This class helps to find the required integration time for the calibration process
 */
class IntegrationTimeFinder
{
  public:
		static int16_t findIntegrationTime(TOF_COS_Context *context, CalibrationCalculation *calibrationCalculation, const uint32_t amplitudeTarget, const uint16_t integrationTimeMin, const uint16_t integrationTimeMax);

  private:
		static uint32_t getSpatialAverageAmplitude(TOF_COS_Context *context, CalibrationCalculation *calibrationCalculation);

};

#endif /* INTEGRATION_TIME_FINDER_H_ */

/** @} */
