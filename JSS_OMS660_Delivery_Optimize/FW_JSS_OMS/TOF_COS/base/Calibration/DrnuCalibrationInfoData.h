/*
 * DrnuCalibrationInfoData.h
 *
 *  Created on: 14.08.2019
 *      Author: mwi
 */

#ifndef DRNU_CALIBRATION_INFO_DATA_H_
#define DRNU_CALIBRATION_INFO_DATA_H_

#include <stdint.h>
#include "Modulation/Modulation.h"
#include "Roi/Roi.h"

///Internal struct to store meta data during calibration
struct DrnuCalibrationInfoData
{
	public:
		DrnuCalibrationInfoData();

		uint32_t temperature;
    uint16_t offset;
    uint8_t dllSteps;
    uint32_t dllRange;
    Modulation modulation;
    Roi roi;
};


#endif /* DRNU_CALIBRATION_INFO_DATA_H_ */
