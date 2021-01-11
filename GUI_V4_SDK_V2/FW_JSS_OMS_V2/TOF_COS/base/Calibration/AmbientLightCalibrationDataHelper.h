/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup ambient_light_calibration_data_helper Data Helper
 * @ingroup ambient_light_calibration
 * @brief Helper Class to access the calibration data
 *
 * @{
 */
#ifndef AMBIENT_LIGHT_CALIBRATION_DATA_HELPER_H_
#define AMBIENT_LIGHT_CALIBRATION_DATA_HELPER_H_

#include "AmbientLightCalibrationTypes.h"

//! Helper Class to access the calibration data
/*!
 * This class helps to access the calibration data for the ambient light calibration.
 */
class AmbientLightCalibrationDataHelper
{
	public:
		AmbientLightCalibrationDataHelper(const uint32_t address);
		void addStorageInformation(ambientLightCalibration_t &ambientLightCalibration) const;
		bool checkDataValid() const;
		ambientLightCalibration_t *getData() const;

	private:
		uint32_t getChecksum(ambientLightCalibration_t &ambientLightCalibration) const;

		uint32_t address;                         ///<Stores the address of the calibration data
};

#endif /* AMBIENT_LIGHT_CALIBRATION_DATA_HELPER_H_ */

/** @} */
