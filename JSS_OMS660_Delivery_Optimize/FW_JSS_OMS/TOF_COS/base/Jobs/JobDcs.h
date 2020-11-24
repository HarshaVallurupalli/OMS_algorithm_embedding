/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup job_dcs DCS data
 * @ingroup pointcloud_job
 *
 * @brief Capture DCS data
 * @{
 */
#ifndef JOB_DCS_H_
#define JOB_DCS_H_

#include <Jobs/PointCloudJob.h>

//! Get DCS
/*!
 * Implements all steps needed do get DCS data
 */
class JobDcs: public PointCloudJob
{
  public:
    JobDcs();
    uint8_t getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData);
};

#endif /* JOB_DCS_H_ */

/** @} */
