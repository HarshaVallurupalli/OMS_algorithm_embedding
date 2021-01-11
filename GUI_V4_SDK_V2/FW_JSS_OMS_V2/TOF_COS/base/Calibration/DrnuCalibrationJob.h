/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup calibration_job Job
 * @brief Execution of the calibration
 * @ingroup calibration
 *
 * @{
 */
#ifndef BASE_CALIBRATION_CALIBRATIONJOB_H_
#define BASE_CALIBRATION_CALIBRATIONJOB_H_

#include <Calibration/Calibration_Calculation.h>
#include <Calibration/DrnuCalibration.h>
#include <Calibration/DrnuCalibrationInfoData.h>
#include <Calibration/DrnuCalibrationTypes.h>
#include <stdint.h>
#include "TypeReturnValue.h"
#include "DataAcquisition/DataAcquisition.h"
#include "RamManager/RamManager.h"
#include "Config/Config.h"
#include "ChipControl/ChipControl.h"
#include "TypeInternalReturnValue.h"
#include "MemoryInfo.h"

enum TypeTemperatureIndicator
{
	TEMPERATURE_OK,
	TEMPERATURE_TOO_HIGH,
	TEMPERATURE_TOO_LOW
};

//! Executes the calibration
/*!
 * This class is responsible of executing the calibration process.
 */
class DrnuCalibrationJob
{
	public:
		DrnuCalibrationJob(class TOF_COS_Context *context);

		TypeReturnValue calibrate(const MemoryInfo memoryInfo, const bool offsetOnly, const bool validateOnly);

	protected:
		class TOF_COS_Context *context;                        ///<Pointer to context class. Can point to mock class for unit tests.
		CalibrationCalculation *calibrationCalculation;        ///<Pointer to calibration calculation class. Can point to mock class for unit tests.
		DrnuCalibration *calibration;                          ///<Pointer to calibration helper class. Can point to mock class for unit tests.

	private:
		TypeInternalReturnValue calibrateStep(const uint8_t step, const int32_t range, const uint8_t dllSteps, const uint32_t wantedTemperature, TypeTemperatureIndicator &temperatureIndicator);
		TypeInternalReturnValue calibrateAllSteps(DrnuCalibrationInfoData &calibrationInfo, const bool offsetOnly);
		TypeInternalReturnValue verifyStep(const uint8_t step, const int32_t range, const uint8_t dllSteps);
		TypeInternalReturnValue verifyAllSteps(DrnuCalibrationInfoData &calibrationInfo);

		TypeTemperatureIndicator determineTemperatureIndicator(const int32_t temperatureDiff);
		TypeInternalReturnValue getOneMeasurement(const int32_t wantedTemperature);
		TypeInternalReturnValue waitForCoolDown(const int32_t wantedTemperature);
		uint32_t findRange(uint8_t &stepsNeeded, const int32_t temperature);
		int16_t findIntegrationTime();
		int32_t getStableTemperature();
		uint32_t getSpatialAverageAmplitude();
		uint32_t getAveragePixelDistance();
		int32_t getAveragePixelDistanceCalibrated();
		void printInfoData();

		CalibrationCalculation ownCalibrationCalculation;      ///<Instance of calibration calculation functions
		DrnuCalibration ownCalibration;                        ///<Instance of calibration helper class
		uint32_t maxSteps;                                     ///<Maximum number of DLL steps for the calibration
};

#endif /* BASE_CALIBRATION_CALIBRATIONJOB_H_ */

/** @} */
