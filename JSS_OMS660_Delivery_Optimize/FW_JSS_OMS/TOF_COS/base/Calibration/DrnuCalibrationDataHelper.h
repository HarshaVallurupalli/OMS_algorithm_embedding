/*
 * DrnuCalibrationDataHelper.h
 *
 *  Created on: 14.08.2019
 *      Author: mwi
 */

#ifndef DRNU_CALIBRATION_DATA_HELPER_H_
#define DRNU_CALIBRATION_DATA_HELPER_H_

#include <Calibration/DrnuCalibrationInfoData.h>
#include <Calibration/DrnuCalibrationTypes.h>
#include <stdint.h>

//! Helper class for the calibration data
/*!
 * This class offers helper functions needed in different classes, for example Calculation and Calibration
 */
class DrnuCalibrationDataHelper
{
	public:
		explicit DrnuCalibrationDataHelper(const uint32_t address);

		int8_t *getCalibrationDataAddress();
		uint32_t getBaseHeaderAddress();
		uint32_t getHeaderAddress();
		bool checkHeaderValid();
		bool checkBaseHeaderValid();
		uint16_t getCalibrationTemperature() const;
		uint8_t getNumStepsCalibrated() const;
		uint16_t getRange() const;
		Modulation getModulation() const;
		uint16_t getAtanOffset() const;

		static calibrationHeaderV1_t createHeader(const DrnuCalibrationInfoData &calibrationInfo);
		calibrationBaseHeaderV1_t createBaseHeader(const int16_t lowPowerOffset);

	private:
		static const uint8_t DRNU_CALIBRATION_DATA_VERSION = 2;           ///<Version of the calibration data. This helps to detect, if they change.

		uint32_t getTotalCalibrationSize();
		uint32_t getCalibrationSize();
	  uint32_t address;
};



#endif /* DRNU_CALIBRATION_DATA_HELPER_H_ */
