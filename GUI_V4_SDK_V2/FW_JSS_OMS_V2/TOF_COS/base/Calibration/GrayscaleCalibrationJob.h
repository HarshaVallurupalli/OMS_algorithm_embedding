/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup grayscale_calibration Grayscale Calibration
 * @ingroup calibration
 * @defgroup grayscale_calibration_job Grayscale Calibration Job
 * @brief Execution of the grayscale calibration
 * @ingroup grayscale_calibration
 *
 * @{
 */
#ifndef GRAYSCALE_CALIBRATION_JOB_H_
#define GRAYSCALE_CALIBRATION_JOB_H_

#include <Calibration/DrnuCalibrationTypes.h>
#include <stdint.h>
#include "TypeReturnValue.h"
#include "Calibration_Calculation.h"
#include "TypeInternalReturnValue.h"
#include "GrayscaleCalibrationCalculation.h"
#include "TOF_COS_Context.h"

//! Executes the grayscale calibration
/*!
 * This class is responsible of executing the grayscale calibration process.
 */
class GrayscaleCalibrationJob
{
  public:
		GrayscaleCalibrationJob(TOF_COS_Context *context);
		TypeInternalReturnValue calibrateGrayscale(const uint32_t address, const uint32_t size);

  private:
		void teardownSettings();
		void setupSettings();
		TypeInternalReturnValue getTemporalAverage(uint32_t *pData, const uint32_t numPixel);
		int32_t limitToRange(const int32_t value, const int32_t minValue, const int32_t maxValue);
		uint32_t getSpatialAverage(const uint32_t numPixel);
		int16_t findIntegrationTime(const uint32_t numPixel);
		TypeInternalReturnValue calculateAndStoreTable(const uint32_t *bufferDark, const uint32_t *bufferHalfLight, const uint32_t spatialAverage, const uint32_t numPixel);
		TypeInternalReturnValue run();

		class TOF_COS_Context *context;
		CalibrationCalculation *calibrationCalculation;
		CalibrationCalculation ownCalibrationCalculation;
		GrayscaleCalibrationCalculation grayscaleCalculation;
		uint32_t calibrationMemoryAddress;
		uint32_t calibrationMemorySize;
};

#endif /* GRAYSCALE_CALIBRATION_JOB_H_ */

/** @} */
