/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup hysteresis
 *
 * @{
 */
#include "Hysteresis.h"
#include "TypePixelCode.h"
#include "Confidence/Confidence.h"

static const uint8_t AMPLITUDE_HYSTERESIS = 20;                         ///<[lsb] Amplitude hysteresis when filter is on

Hysteresis::Hysteresis()
{
	this->hysteresis = AMPLITUDE_HYSTERESIS;
}

uint32_t Hysteresis::setMinAmplitude(const uint32_t amplitude, const bool squared, const bool enabled)
{
	if (squared)
	{
	  minAmplitude = Confidence::amplitudeToSquaredAmplitude(amplitude);
	  if (enabled)
	  {
	    minAmplitudeHysteresis = Confidence::amplitudeToSquaredAmplitude(amplitude + hysteresis);
	  }
	  else
	  {
	  	minAmplitudeHysteresis = minAmplitude;
	  }
	}
	else
	{
	  this->minAmplitude = amplitude;
	  if (enabled)
	  {
	  	this->minAmplitudeHysteresis = amplitude + hysteresis;
	  }
	  else
	  {
	    this->minAmplitudeHysteresis = minAmplitude;
	  }
	}

	return minAmplitude;
}

/**
 * @brief Minimal amplitude hysteresis
 *
 * Add a hysteresis for the minimum amplitude if in the last measurement the pixel had low amplitude.
 *
 * @param lastDistance Last distance value
 * @return amplitude limit
 */
uint32_t Hysteresis::calcMinAmplitudeWithHysteresis(const uint32_t lastDistance)
{
  uint32_t amplitudeLimit = minAmplitude;

  //No overflow detection here because of speed reasons
  if (lastDistance == TypePixelCode::PIXEL_CODE_LOW_AMPLITUDE)
	{
  	amplitudeLimit = minAmplitudeHysteresis;
	}

  return amplitudeLimit;
}


/** @} */
