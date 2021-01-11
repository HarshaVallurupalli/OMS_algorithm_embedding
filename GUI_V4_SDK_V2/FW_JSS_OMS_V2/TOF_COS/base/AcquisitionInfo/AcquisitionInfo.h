/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup acquisition_info Acquisition Info
 * @ingroup tof_cos
 * @brief Contains all information about the acquisition.
 *
 * Should be "attached" to the image data to have knowledge about the data, e.g. settings, ...
 *
 * @{
 */
#ifndef ACQUISITION_INFO_H_
#define ACQUISITION_INFO_H_

#include <stdint.h>
#include "TOF_COS_Constants.h"
#include "Modulation/Modulation.h"
#include "Roi/Roi.h"
#include "Binning/Binning.h"
#include "Hdr/Hdr.h"
#include <atomic>


//! Acquisition Info
/*!
 * Contains all information about the acquisition.
 */
#pragma pack(push,1)
class AcquisitionInfo
{
	public:
		int32_t temperature;                         ///<Temperature [°C shifted] at acquisition time
		uint16_t integrationTime3d;                  ///<Integration time 3d[us]
		uint16_t integrationTimeGrayscale;           ///<Integration time grayscale [us]
		uint8_t illumination;                        ///<Index of the illumination used
		uint16_t integrationTimeMultiplier;          ///<Integration time multiplier, needed for ambient light compensation
		Modulation modulation;                       ///<Modulation settings
		Roi roi;                                     ///<ROI settings
		Binning binning;                             ///<Binning settings (onchip)
		Hdr hdr;                                     ///<HDR settings (onchip)
		uint8_t dllStep;                             ///<DLL step set in the chip
		uint32_t getNumPixel() const;
		uint32_t getFinalNumPixel() const;
		uint16_t getWidth() const;
		uint16_t getHeight() const;
		uint16_t getFinalHeight() const;
		uint16_t getXMin() const;
		uint16_t getXMax() const;
		uint16_t getYMin() const;
		uint16_t getYMax() const;
};
#pragma pack(pop)

#endif /* ACQUISITION_INFO_H_ */

/** @} */
