/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup temporal_filter_constants Temporal filter constants
 * @brief Contstants for the temporal filter
 * @ingroup temporal_filter
 *
 * @{
 */
#ifndef TEMPORAL_FILTER_CONTSTANTS_H_
#define TEMPORAL_FILTER_CONTSTANTS_H_

///Maximum value for the factor of the temporal filter --> = 1.0
static const uint16_t TEMPORAL_FILTER_FACTOR_MAX = 1000;

///Default factor of the temporal filter at startup
static const uint16_t TEMPORAL_FILTER_FACTOR_DEFAULT = 1000;

///Default threshold of the temporal filter at startup
static const uint16_t TEMPORAL_FILTER_THRESHOLD_DEFAULT = 300;

#endif /* TEMPORAL_FILTER_CONTSTANTS_H_ */

/** @} */
