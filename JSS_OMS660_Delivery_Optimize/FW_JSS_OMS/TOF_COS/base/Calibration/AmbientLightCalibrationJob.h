/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup ambient_light_calibration Ambient Light Calibration
 * @ingroup calibration
 * @defgroup ambient_light_calibration_job Ambient Light Calibration Job
 * @brief Execution of the ambient light calibration
 * @ingroup ambient_light_calibration
 *
 * @{
 */
#ifndef AMBIENTLIGHT_CALIBRATION_JOB_H_
#define AMBIENTLIGHT_CALIBRATION_JOB_H_

#include <stdint.h>
#include "ChipControl/ChipControl.h"
#include "Calibration_Calculation.h"
#include "TypeInternalReturnValue.h"
#include "AmbientLightCalibrationTypes.h"
#include "TOF_COS_Context.h"

//! Executes the ambient light calibration
/*!
 * This class is responsible of executing the ambient light calibration procedure.
 */
class AmbientLightCalibrationJob
{
  public:
		AmbientLightCalibrationJob(TOF_COS_Context *context);
		TypeInternalReturnValue calibrateAmbientLight(const uint32_t address, const uint32_t size);

	private:
		TypeInternalReturnValue getDcsValues(uint32_t &dcs0, uint32_t &dcs2, const bool omitChipConfig);
		TypeInternalReturnValue getDcsAverage(uint32_t &dcs0, uint32_t &dcs2, const bool omitChipConfig);
		void teardownSettings();
		void setupSettings();
		TypeInternalReturnValue calibrateAll();
		TypeInternalReturnValue run(ambientLightCalibrationEntry_t *ambientLightCalibrationEntry, const Binning binning);
		TypeInternalReturnValue StoreToCalibrationMemory();
		void storeCurrentData();

	  class TOF_COS_Context *context;
	  CalibrationCalculation *calibrationCalculation;
	  CalibrationCalculation ownCalibrationCalculation;
	  uint32_t calibrationMemoryAddress;
	  uint32_t calibrationMemorySize;
	  uint16_t integrationTimeLengthSetting1;
	  uint16_t integrationTimeMultiplierSetting1;
	  uint16_t integrationTime3d;
	  ambientLightCalibrationEntry_t *currentAmbientLightCalibrationEntry;
	  ambientLightCalibration_t ambientLightCalibrationData;

};

#endif /* AMBIENTLIGHT_CALIBRATION_JOB_H_ */

/** @} */
