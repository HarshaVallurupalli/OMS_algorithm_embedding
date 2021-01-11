/**
p * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup ambient_light_calibration_types Types
 * @brief Types and constants for the Ambient Light calibration
 * @ingroup ambient_light_calibration
 *
 * @{
 */
#ifndef AMBIENT_LIGHT_CALIBRATION_TYPES_H_
#define AMBIENT_LIGHT_CALIBRATION_TYPES_H_

#include <stdint.h>

///Ambient light calibration
#pragma pack(push,1)
typedef struct
{
	uint16_t dcs0WithAlSetting1;
	uint16_t dcs2WithAlSetting1;
	uint16_t dcs0WithAlSetting2;
	uint16_t dcs2WithAlSetting2;
	uint16_t dcs0NoAl;
	uint16_t dcs2NoAl;
	uint16_t integrationTime3d;
	uint16_t integrationTimeGrayscale;
	int32_t kalFactor;
	uint8_t reserved[9];
}ambientLightCalibrationEntry_t;
#pragma pack(pop)

#pragma pack(push,1)
typedef struct
{
	uint32_t crc;
	uint8_t version;
	uint8_t reserved;
	ambientLightCalibrationEntry_t calibration;
}ambientLightCalibration_t;
#pragma pack(pop)


const uint8_t AMBIENT_LIGHT_CALIBRATION_DATA_VERSION = 1;

#endif /* AMBIENT_LIGHT_CALIBRATION_TYPES_H_ */

/** @} */
