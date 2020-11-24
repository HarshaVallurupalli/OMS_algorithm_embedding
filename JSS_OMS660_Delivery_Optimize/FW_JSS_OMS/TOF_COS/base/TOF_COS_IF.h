/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup tof_cos TOF COS
 * @brief TOF Camera Operating System
 * @defgroup tof_cos_if Interface
 * @ingroup tof_cos
 * @brief Library to access Espros Time Of Flight sensors
 *
 * @{
 */
#ifndef TOF_COS_IF_H_
#define TOF_COS_IF_H_

#include "TypeReturnValue.h"
#include "TemporalFilter/TemporalFilterSettings.h"
#include <AcquisitionMetaData/AcquisitionMetaData.h>
#include "TOF_COS_Data.h"
#include <stdint.h>

//! TOF_COS Interface
/*!
 * Interface class for the TOF_COS
 *
 * This interface must be implemented for a concrete TOF_COS
 */
class TOF_COS_IF
{
	public:

		virtual void selectData(const TOF_COS_Data_e data) = 0;

		virtual uint8_t getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData) = 0;

		uint8_t init(const size_t mem_loc, const size_t mem_size);
		virtual bool acquisitionBusy() = 0;


		void setTemporalFilterSettings(const TemporalFilterSettings filterSettings);
		void setAverageFilterEnabled(const bool enabled);
		void setMedianFilterEnabled(const bool enabled);
		void setEdgeFilterSettings(const uint32_t threshold);

		//Algorithm Edit
		void setMovementDetectionSettings(const uint8_t WindowSize);

};

#endif /* TOF_COS_IF_H_ */

/** @} */
