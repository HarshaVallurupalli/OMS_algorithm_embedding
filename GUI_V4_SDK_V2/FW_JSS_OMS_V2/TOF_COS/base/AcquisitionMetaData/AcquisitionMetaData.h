/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup acquisition_meta_data Acquisition Meta Data
 * @ingroup tof_cos
 *
 * @brief Contains meta information about the acquisition.
 *
 * @{
 */
#ifndef ACQUISITION_META_DATA_H_
#define ACQUISITION_META_DATA_H_

#include <stdint.h>
#include "TOF_COS_Constants.h"
#include "Modulation/Modulation.h"
#include "Roi/Roi.h"
#include "Binning/Binning.h"
#include "AcquisitionInfo/AcquisitionInfo.h"
#include "Pixel/PixelToFDistanceAmplitude.h"

//! Acquisition Meta Data
/*!
 * Contains meta information about the acquisition.
 */
class AcquisitionMetaData
{
	public:
		uint32_t sizeResult;                               ///<Resulting data size [Bytes] of the output data
		AcquisitionInfo acquisitionInfo;                   ///<All information about the acquisition
		bool drnuCompensated;                              ///<Flag to indicate if the data is DRNU compensated
		bool temperatureCompensated;                       ///<Flag to indicate if the data is temperature compensated
		bool ambientLightCompensated;                      ///<Flag to indicate if the data is ambient light compensated
		int32_t getTemperatureCentiDegree() const;
		void clear();
};

#endif //ACQUISITION_META_DATA_H_

/** @} */
