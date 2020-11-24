/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup data Data
 * @ingroup tof_cos
 * @brief Data definitions for the TOF_COS
 *
 * Defines which type of data is currently requested from the TOF_COS.
 *
 * @{
 */
#ifndef TOF_COS_DATA_H
#define TOF_COS_DATA_H

enum TOF_COS_Data_e
{
	DATA_DISTANCE,
	DATA_DISTANCE_AMPLITUDE,
	DATA_GRAYSCALE,
	DATA_DCS,
	DATA_NONE
};

#endif /* TOF_COS_DATA_H */

/** @} */
