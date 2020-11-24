/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup job_grayscale Grayscale Data
 * @ingroup pointcloud_job
 *
 * @brief Capture Grayscale Data
 *
 * @{
 */
#ifndef JOBGRAYSCALE_H_
#define JOBGRAYSCALE_H_

#include <Jobs/PointCloudJob.h>

//! Get grayscale
/*!
 * Implements all steps needed do get grayscale images.
 */
class JobGrayscale: public PointCloudJob
{
	public:
		uint8_t getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData);

	private:
		void startAcquisitionInternal() override;
};

#endif /* JOBGRAYSCALE_H_ */

/** @} */
