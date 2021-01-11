/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup job_distance Distance Data
 * @ingroup pointcloud_job
 *
 * @brief Capture Distance Data
 *
 * @{
 */
#ifndef JOBDISTANCE_H_
#define JOBDISTANCE_H_

#include <Jobs/PointCloudJob.h>

//! Get distance
/*!
 * Implements all steps needed do get the distance.
 */
class JobDistance: public PointCloudJob
{
	public:
		JobDistance();
		uint8_t getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData);
};

#endif /* JOBDISTANCE_H_ */

/** @} */
