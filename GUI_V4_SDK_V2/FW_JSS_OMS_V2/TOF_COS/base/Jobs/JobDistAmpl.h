/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup job_dist_ampl Distance and Amplitude
 * @ingroup pointcloud_job
 *
 * @brief Capture Distance and Amplitude data
 * @{
 */
#ifndef JOBDISTAMPL_H_
#define JOBDISTAMPL_H_

#include <Jobs/PointCloudJob.h>

//! Get distance and amplitude
/*!
 * Implements all steps needed do get distance and amplitude.
 */
class JobDistAmpl: public PointCloudJob
{
	public:
		JobDistAmpl();
		uint8_t getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData);
};

#endif /* JOBDISTAMPL_H_ */

/** @} */
