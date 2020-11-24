/***
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup temporal_filter
 */
#include "TemporalFilter.h"
#include <stdlib.h>

/**
 * @brief Constructor
 */
TemporalFilter::TemporalFilter()
{
	//this->factorActual = TEMPORAL_FILTER_FACTOR_MAX;
	//this->factorLast = 0;
	//this->threshold = 0;

	//init to values above, values below for test

	this->factorActual = 500;
	this->factorLast = 500;
	this->threshold = 300;
}

/**
 * @brief Set the settings
 *
 * @param TemporalFilterSettings class containing the wanted settings
 */
void TemporalFilter::setSettings(const TemporalFilterSettings settings)
{
	this->factorActual = settings.factor;

	if (this->factorActual > TEMPORAL_FILTER_FACTOR_MAX)
	{
		this->factorActual = TEMPORAL_FILTER_FACTOR_MAX;
	}

	this->factorLast = TEMPORAL_FILTER_FACTOR_MAX - settings.factor;
	this->threshold = settings.threshold;
}

/**
 * @brief Get the settings
 *
 * @return TemporalFilterSettings class containing the current settings
 */
TemporalFilterSettings TemporalFilter::getSettings() const
{
	TemporalFilterSettings settings(this->threshold, this->factorActual);

	return settings;
}

/**
 * @brief Read back, if the filter is enabled
 *
 * @retval true Filter is enabled
 * @retval false Filter is disabled
 * @return Filter enabled or disabled
 */
bool TemporalFilter::isEnabled() const
{
	if ((threshold == 0) ||
			(factorActual == 0) ||
			(factorActual >= TEMPORAL_FILTER_FACTOR_MAX))
	{
	  return false;
	}

	return true;
}

/**
 * @brief Filter
 *
 * Apply the filter on the given value
 *
 * @param actValue Actual value
 * @param lastValue Last value
 * @return Filtered value
 */
uint32_t TemporalFilter::filter(const uint32_t actValue, const uint32_t lastValue)
{
	uint32_t result = actValue;

	int32_t diff = actValue - lastValue;

	if (abs(diff) < threshold)
	{
		result = (((actValue * factorActual) + (lastValue * factorLast)) / TEMPORAL_FILTER_FACTOR_MAX);
	}

	return result;
}

/** @} */
