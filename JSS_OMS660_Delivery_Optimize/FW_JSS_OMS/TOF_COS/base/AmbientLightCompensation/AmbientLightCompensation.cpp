/*
 * AmbientLightCompensation.cpp
 *
 *  Created on: 18.10.2019
 *      Author: mwi
 */

#include <AmbientLightCompensation/AmbientLightCompensation.h>
#include "Calibration/AmbientLightCalibrationTypes.h"
#include "fpga.h"

/**
 * @brief Constructor
 */
AmbientLightCompensation::AmbientLightCompensation()
{
	kalFactor = 20;
	intMultiplier = 1;
}

/**
 * @brief Set the calibration data address
 *
 * Call this before running any grayscale compensation
 *
 * @param address Address of the grayscale calibration (in the flash)
 */
void AmbientLightCompensation::setCalibrationAddress(const uint32_t address)
{
	ambientLightCalibration_t *ambientLightCalibration = reinterpret_cast<ambientLightCalibration_t *>(address);

	//kalFactor = ambientLightCalibration->calibration.kalFactor;
}

/**
 * @brief Load the FPGA
 *
 * Load the FPGA with data needed for the compensation. The FPGA does the compensation on the fly so this
 * needs to be done before the data acquisition.
 *
 * @param integrationTimeMultiplier Integration time multiplier settings from the TOF imager
 */
void AmbientLightCompensation::loadFpga(const uint16_t integrationTimeMultiplier)
{
  uint32_t ambientLightCompensationParameter = (integrationTimeMultiplier << 8) / kalFactor;

  fpgaSetAmbientLightCorrection(ambientLightCompensationParameter);
}

/**
 * @brief Get corrected DCS value
 *
 * This function is mainly used to check the calculations in the FPGA.
 *
 * @param dcs Current DCS value
 * @param grayscale Current grayscale value
 * @param integrationTimeMultiplier Integration time multiplier settings from the TOF imager
 */
uint32_t AmbientLightCompensation::getCorrectedValue(const uint32_t dcs, const uint32_t grayscale, const uint16_t integrationTimeMultiplier)
{
  uint32_t valueToSubtract = (grayscale * integrationTimeMultiplier) / kalFactor;

  uint32_t dcsCorrected = dcs - valueToSubtract;

  return dcsCorrected;
}
