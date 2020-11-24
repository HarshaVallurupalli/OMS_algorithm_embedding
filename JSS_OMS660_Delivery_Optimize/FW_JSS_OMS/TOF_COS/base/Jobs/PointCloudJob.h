/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup pointcloud_job PointCloud Job
 * @brief Measurement/Capture Job of the TOF_COS
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef POINTCLOUD_JOB_H_
#define POINTCLOUD_JOB_H_

#include <stdint.h>
#include <TOF_COS_Context.h>
#include "TypeReturnValue.h"
#include "Calculation/CalculationParameters.h"
#include "DataAcquisition/DataAcquisition.h"
#include "ChipControl/ChipControl.h"
#include "RamManager/RamManager.h"
#include "Config/Config.h"
#include "Calculation/Calculation.h"
#include "AcquisitionMetaData/AcquisitionMetaData.h"

//! Abstract PointCloud Job
/*!
 * Offers the basic functionality for the PointCloud Jobs. For each type of acquisition data
 * a concrete job is required.
 */
class PointCloudJob
{
	public:
		PointCloudJob();
		static void setContext(class TOF_COS_Context *context);
		void startAcquisition();
		virtual uint8_t getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData) = 0;

	protected:
		uint8_t getStatus();
		void updateDataStructures();
		bool isTemporalHdrAcquisition() const;

		static class TOF_COS_Context *context;
		static CalculationParameters calculationParameters;
		static CalculationResults calculationResults;

	private:
		virtual void startAcquisitionInternal();
};

#endif /* POINTCLOUD_JOB_H_ */

/** @} */
