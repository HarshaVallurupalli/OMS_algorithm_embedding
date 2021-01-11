/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup ambient_light_calibration_data_helper
 *
 * @{
 */
#include <Calibration/AmbientLightCalibrationDataHelper.h>
#include "CRC/CRC.h"

AmbientLightCalibrationDataHelper::AmbientLightCalibrationDataHelper(const uint32_t address)
{
	this->address = address;
}

bool AmbientLightCalibrationDataHelper::checkDataValid() const
{
	ambientLightCalibration_t *ambientLightCalibration = reinterpret_cast<ambientLightCalibration_t *>(address);

	uint32_t crc = getChecksum(*ambientLightCalibration);

  if (crc != ambientLightCalibration->crc)
  {
  	return false;
  }

  return true;
}

uint32_t AmbientLightCalibrationDataHelper::getChecksum(ambientLightCalibration_t &ambientLightCalibration) const
{
	uint32_t crc = CRC::startCrc32();

  uint8_t *p = reinterpret_cast<uint8_t *>(&ambientLightCalibration.crc) + sizeof(ambientLightCalibration.crc);
  uint32_t size = sizeof(ambientLightCalibration_t) - sizeof(ambientLightCalibration.crc);

	//Accumulate AFTER the crc
	crc = CRC::accumulateCrc32(p, size, crc);

	crc = CRC::finishCrc32(crc);

	return crc;
}

/**
 * @brief Add storage information
 *
 * This function adds storage information to the calibration data, such as:
 * - CRC
 * - Version
 *
 * When this information is added, the calibration data can be stored in the calibration memory.
 *
 * @param ambientLightCalibration Reference to the ambient light calibration data
 */
void AmbientLightCalibrationDataHelper::addStorageInformation(ambientLightCalibration_t &ambientLightCalibration) const
{
	//First write all date needed, because they will be included in the checksum
	ambientLightCalibration.version = AMBIENT_LIGHT_CALIBRATION_DATA_VERSION;

	//Now get the checksum
	uint32_t crc = getChecksum(ambientLightCalibration);

	//It can be added to the struct now
	ambientLightCalibration.crc = crc;
}

/**
 * @brief Get data pointer
 *
 * This function returns the pointer to the calibration structure in the calibration memory. The
 * calibration information can directly be read from this structure.
 *
 * @return Pointer to the calibration structure in the calibration memory
 */
ambientLightCalibration_t *AmbientLightCalibrationDataHelper::getData() const
{
  ambientLightCalibration_t *ambientLightCalibration = reinterpret_cast<ambientLightCalibration_t *>(address);

  return ambientLightCalibration;
}
/** @} */
