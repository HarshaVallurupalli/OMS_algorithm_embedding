/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup tof_cos_clock_generator Clock Generator
 * @ingroup tof_cos_hal
 *
 * @brief Functions to access the clock generator
 *
 * @{
 */
#ifndef TOF_COS_CLOCK_GENERATOR_H_
#define TOF_COS_CLOCK_GENERATOR_H_

#include <stdint.h>

typedef enum
{
	TOF_COS_CLOCK_GENERATOR_96MHZ,
	TOF_COS_CLOCK_GENERATOR_80MHZ,
	TOF_COS_CLOCK_GENERATOR_48MHZ,
	TOF_COS_CLOCK_GENERATOR_40MHZ,
	TOF_COS_CLOCK_GENERATOR_24MHZ,
	TOF_COS_CLOCK_GENERATOR_20MHZ,
	TOF_COS_CLOCK_GENERATOR_12MHZ,
	TOF_COS_CLOCK_GENERATOR_10MHZ
}tofCosClockGeneratorClock_e;

int8_t tofCosClockGeneratorInit();
int8_t tofCosClockGeneratorWriteFrequency(const tofCosClockGeneratorClock_e clock);


#endif /* TOF_COS_CLOCK_GENERATOR_H_ */

/** @} */
