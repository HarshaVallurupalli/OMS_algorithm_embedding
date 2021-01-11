/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup acquisition_meta_data
 *
 * @{
 */
#include <AcquisitionMetaData/AcquisitionMetaData.h>

/**
 * @brief Helper function to calculate the temperature in centidegree
 *
 * Converts the temperature from the internal fixed point format to centidegree.
 *
 * Example: 35.34°C --> 3534
 *
 * @return Temperature in centidegree
 */
int32_t AcquisitionMetaData::getTemperatureCentiDegree() const
{
  int32_t temperatureCentiDegree = (100 * acquisitionInfo.temperature) >> TEMPERATURE_CALC_SHIFT;

	return temperatureCentiDegree;
}

/**
 * @brief Clear data
 *
 * Call before acquisition to clear everything needed to be cleared.
 */
void AcquisitionMetaData::clear()
{
	sizeResult = 0;
}

/** @} */
