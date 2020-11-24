/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup modulation
 *
 * @{
 */
#include "Modulation.h"
#include "ChipSelection.h"

///Number of modulation channels. Each channel gives a slight change of the modulation frequency
static const uint8_t NUM_MODULATION_CHANNEL = 16;

//Static member variables
uint8_t Modulation::channel = 0;
bool Modulation::autoChannelEnabled = false;
bool Modulation::changed = true;

Modulation::Modulation()
{
	modulationFrequency = Modulation::MODULATION_10MHZ;
}

Modulation::Modulation(const Modulation::ModulationFrequency frequency)
{
  modulationFrequency = frequency;
}


/**
 * @brief Operator =
 *
 * @param frequency Modulation frequency
 * @return Reference to this
 */
Modulation &Modulation::operator=(const Modulation::ModulationFrequency frequency)
{
	modulationFrequency = frequency;
	return *this;
}

/**
 * @brief Set modulation frequency
 *
 *
 * @param frequency Frequency as enum, not as value
 */
void Modulation::setModulationFrequency(const Modulation::ModulationFrequency frequency)
{
  this->modulationFrequency = frequency;
}

/**
 * @brief Get modulation frequency
 *
 *
 * @return Modulation frequency as enum, not as value
 */
Modulation::ModulationFrequency Modulation::getModulationFrequency() const
{
	return modulationFrequency;
}

/**
 * @brief Set modulation channel
 *
 * @param channel Modulation channel
 */
void Modulation::setChannel(const uint8_t channel)
{
	Modulation::changed = true;
	Modulation::channel = channel;
}

/**
 * @brief Set auto channel
 *
 * If auto modulation channel is enabled, the device automatically changes the modulation frequency, if
 * interference is detected.
 *
 * @param enabled Enable or disable auto channel
 */
void Modulation::setAutoChannelEnabled(const bool enabled)
{
	Modulation::changed = true;
	Modulation::autoChannelEnabled = enabled;
}

/**
 * @brief Read, if static settings have changed
 *
 * Static settings are:
 * - auto modulation channel
 * - modulation channel
 *
 * @retval true Settings have changed
 * @retval false Settings did not change
 * @return Settings changed or not
 */
bool Modulation::hasChanged()
{
	bool modulationHasChanged = Modulation::changed;
	Modulation::changed = false;
	return modulationHasChanged;
}

/**
 * @brief Read the modulation channel
 *
 * @return Modulation channel
 */
uint32_t Modulation::getChannel() const
{
	return channel;
}

/**
 * @brief Read, if auto modulation channel is enabled
 *
 * @retval true Auto modulation channel enabled
 * @retval false Auto modulation channel disabled
 * @return Auto modulation channel enabled/disabled
 */
bool Modulation::getAutoChannelEnabled() const
{
  return autoChannelEnabled;
}

/**
 * @brief Get the base distance range
 *
 * Returns the base distance range, means the range for 10.0 MHz or 20.0MHz, not taking intou account
 * the modulation channel
 *
 * @return Distance range in mm
 */
uint16_t Modulation::getBaseDistanceRange() const
{
	uint16_t baseRange = 0;

	switch (modulationFrequency)
	{
	  case Modulation::MODULATION_24MHZ:
	  	baseRange = 6250; //mm
	  	break;
	  case Modulation::MODULATION_20MHZ:
	  	baseRange = 7500; //mm
	    break;
	  case Modulation::MODULATION_12MHZ:
	  	baseRange = 12500; //mm
	  	break;
	  case Modulation::MODULATION_10MHZ:
	  	baseRange = 15000; //mm
		  break;
	  case Modulation::MODULATION_6MHZ:
	  	baseRange = 25000; //mm
	  	break;
	  case Modulation::MODULATION_5MHZ:
	  	baseRange = 30000; //mm
	  	break;
	  case Modulation::MODULATION_3MHZ:
	  	baseRange = 50000; //mm
	  	break;
	  case Modulation::MODULATION_2_5MHZ:
	  	baseRange = 60000; //mm
	  	break;
	  case Modulation::MODULATION_1_5MHZ:
	  	baseRange = 10000; //cm
	  	break;
	  case Modulation::MODULATION_1_25MHZ:
	  	baseRange = 12000; //cm
	  	break;
	  case Modulation::MODULATION_0_75MHZ:
	  	baseRange = 20000; //cm
	  	break;
	  case Modulation::MODULATION_0_625MHZ:
	  	baseRange = 24000; //cm
	  	break;
	  case Modulation::MODULATION_0_375MHZ:
      baseRange = 40000; //cm
	  	break;
	  default:
	  	baseRange = 15000;
		  break;
	}

	return baseRange;
}

/**
 * @brief Get the distance range
 *
 * Returns the distance range for the current modulation settings. This is also dependent of the
 * selected modulation channel.
 *
 * @return Distance range in mm
 */
uint32_t Modulation::getDistanceRange() const
{
	uint16_t baseRange = getBaseDistanceRange();
	uint32_t baseFrequency = 10000000;

	switch (modulationFrequency)
	{
	  case Modulation::MODULATION_24MHZ:
	  	baseFrequency = 24000000;
		  break;
	  case Modulation::MODULATION_20MHZ:
	    baseFrequency = 20000000;
	    break;
	  case Modulation::MODULATION_12MHZ:
	  	baseFrequency = 12000000;
	    break;
	  case Modulation::MODULATION_10MHZ:
		  baseFrequency = 10000000;
		  break;
	  case Modulation::MODULATION_6MHZ:
	  	baseFrequency = 6000000;
	  	break;
	  case Modulation::MODULATION_5MHZ:
	  	baseFrequency = 5000000;
	  	break;
	  case Modulation::MODULATION_3MHZ:
	  	baseFrequency = 3000000;
	  	break;
	  case Modulation::MODULATION_2_5MHZ:
	  	baseFrequency = 2500000;
	  	break;
	  case Modulation::MODULATION_1_5MHZ:
	  	baseFrequency = 1500000;
	  	break;
	  case Modulation::MODULATION_1_25MHZ:
	  	baseFrequency = 1250000;
	  	break;
	  case Modulation::MODULATION_0_75MHZ:
	  	baseFrequency = 750000;
	  	break;
	  case Modulation::MODULATION_0_625MHZ:
	  	baseFrequency = 625000;
	  	break;
	  case Modulation::MODULATION_0_375MHZ:
	  	baseFrequency = 375000;
	  	break;
	  default:
		  break;
	}

	uint32_t currentFrequency = getModulationFrequencyHz();

	//Calculate the distance range using the relation between base frequency and current frequency. Use fixed point only.
	uint32_t distanceRange = ((baseFrequency >> 10) * baseRange) / (currentFrequency >> 10);

	return distanceRange;
}

float Modulation::getRangeMultiplier() const
{
  float baseRange = getBaseDistanceRange();
  float currentRange = getDistanceRange();

  float multiplier = currentRange / baseRange;

  return multiplier;
}

/**
 * @brief Read if in millimeter
 *
 * This function returns as flag, if the distance range is in millimeter. The normal distance ranges are in millimeter.
 * Only high distance ranges achieved at modulation frequencies of 1.5MHz and below give high ranges where the unit is cm.
 *
 * @retval true Distance is in millimeter
 * @retval false Distance is not in millimeter, it is in centimeter
 * @return Flag distance is in millimeter
 */
bool Modulation::isInMillimeter() const
{
  bool isMillimeter = true;
	switch (modulationFrequency)
	{
    case Modulation::MODULATION_1_5MHZ:
    	isMillimeter = false;
		  break;
		case Modulation::MODULATION_1_25MHZ:
			isMillimeter = false;
		  break;
		case Modulation::MODULATION_0_75MHZ:
			isMillimeter = false;
		  break;
		case Modulation::MODULATION_0_625MHZ:
			isMillimeter = false;
		  break;
		case Modulation::MODULATION_0_375MHZ:
			isMillimeter = false;
		  break;
		default:
			break;
	}

	return isMillimeter;
}

uint32_t Modulation::getClockGeneratorInputBaseFrequencyHz() const
{
  uint32_t inputFrequency = 80000000;

	switch (modulationFrequency)
	{
	  case Modulation::MODULATION_10MHZ:
		  inputFrequency = 40000000;
		  break;
	  case Modulation::MODULATION_12MHZ:
	  	inputFrequency = 48000000;
	    break;
	  case Modulation::MODULATION_20MHZ:
		  inputFrequency = 800000000;
			break;
	  case Modulation::MODULATION_24MHZ:
	  	inputFrequency = 96000000;
		  break;
	  case Modulation::MODULATION_5MHZ:
	  	inputFrequency = 20000000;
	  	break;
	  case Modulation::MODULATION_6MHZ:
	  	inputFrequency = 24000000;
		  break;
	  case Modulation::MODULATION_2_5MHZ:
	  	inputFrequency = 10000000;
	  	break;
	  case Modulation::MODULATION_3MHZ:
	  	inputFrequency = 12000000;
	  	break;
	  case Modulation::MODULATION_1_25MHZ:
	  	inputFrequency = 10000000;
	  	break;
	  case Modulation::MODULATION_1_5MHZ:
	  	inputFrequency = 12000000;
		  break;
	  case Modulation::MODULATION_0_625MHZ:
	  	inputFrequency = 12000000;
	  	break;
	  case Modulation::MODULATION_0_75MHZ:
	  	inputFrequency = 12000000;
		  break;
	  case Modulation::MODULATION_0_375MHZ:
	  	inputFrequency = 12000000;
		  break;
	  default:
	  	inputFrequency = 80000000;
		break;
	}

  return inputFrequency;
}

uint8_t Modulation::getChipDivider() const
{
  uint8_t divider = 1;

	switch (modulationFrequency)
	{
	  case Modulation::MODULATION_10MHZ:
	  	divider = 0;
		  break;
	  case Modulation::MODULATION_12MHZ:
	  	divider = 0;
	    break;
	  case Modulation::MODULATION_20MHZ:
	  	divider = 0;
			break;
	  case Modulation::MODULATION_24MHZ:
	  	divider = 0;
		  break;
	  case Modulation::MODULATION_5MHZ:
	  	divider = 0;
	  	break;
	  case Modulation::MODULATION_6MHZ:
	  	divider = 0;
		  break;
	  case Modulation::MODULATION_2_5MHZ:
	  	divider = 0;
	  	break;
	  case Modulation::MODULATION_3MHZ:
	  	divider = 0;
	  	break;
	  case Modulation::MODULATION_1_25MHZ:
	  	divider = 0;
	  	break;
	  case Modulation::MODULATION_1_5MHZ:
	  	divider = 1;
		  break;
	  case Modulation::MODULATION_0_625MHZ:
	  	divider = 3;
	  	break;
	  case Modulation::MODULATION_0_75MHZ:
	  	divider = 3;
		  break;
	  case Modulation::MODULATION_0_375MHZ:
	  	divider = 4;
		  break;
	  default:
	  	divider = 0;
		break;
	}

  return divider;
}

tofCosClockGeneratorClock_e Modulation::getClock() const
{
  tofCosClockGeneratorClock_e clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_96MHZ;

	switch (modulationFrequency)
	{
	  case Modulation::MODULATION_10MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_40MHZ;
		  break;
	  case Modulation::MODULATION_12MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_48MHZ;
	    break;
	  case Modulation::MODULATION_20MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_80MHZ;
			break;
	  case Modulation::MODULATION_24MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_96MHZ;
		  break;
	  case Modulation::MODULATION_5MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_20MHZ;
	  	break;
	  case Modulation::MODULATION_6MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_24MHZ;
		  break;
	  case Modulation::MODULATION_2_5MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_10MHZ;
	  	break;
	  case Modulation::MODULATION_3MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_12MHZ;
	  	break;
	  case Modulation::MODULATION_1_25MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_10MHZ;
	  	break;
	  case Modulation::MODULATION_1_5MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_12MHZ;
		  break;
	  case Modulation::MODULATION_0_625MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_10MHZ;
	  	break;
	  case Modulation::MODULATION_0_75MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_12MHZ;
		  break;
	  case Modulation::MODULATION_0_375MHZ:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_12MHZ;
		  break;
	  default:
	  	clock = tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_96MHZ;
		  break;
	}

  return clock;
}

/**
 * @brief Get the modulation frequency
 *
 * This function returns the modulation frequency of the LED
 *
 * @return Modulation frequency of the LED in Hz
 */
uint32_t Modulation::getModulationFrequencyHz() const
{
	uint8_t divider = 8;

	switch (modulationFrequency)
	{
	  case Modulation::MODULATION_10MHZ:
	  	//no break
	  case Modulation::MODULATION_12MHZ:
	  	divider = 4;
			break;
		case Modulation::MODULATION_20MHZ:
			//no break
		case Modulation::MODULATION_24MHZ:
			divider = 4;
			break;
		case Modulation::MODULATION_5MHZ:
	    //no break
		case Modulation::MODULATION_6MHZ:
			divider = 4;
			break;
		case Modulation::MODULATION_2_5MHZ:
			//no break
		case Modulation::MODULATION_3MHZ:
			divider = 4;
			break;
		case Modulation::MODULATION_1_25MHZ:
		  //no break
		case Modulation::MODULATION_1_5MHZ:
      divider = 8;
			break;
		case Modulation::MODULATION_0_625MHZ:
			//no break
		case Modulation::MODULATION_0_75MHZ:
      divider = 16;
			break;
		case Modulation::MODULATION_0_375MHZ:
			divider = 16;
			break;
		default:
			divider = 4;
			break;
  }

	uint32_t resultingFrequency = getModulationClockInput() / divider;

	return resultingFrequency;
}

/**
 * @brief Get the modulation clock input
 *
 * This function returns the modulation clock input. This is the clock that the clock generator feeds into
 * the TOF imager. It is not the modulation clock in the LEDs.
 * This clock is dependent of the modulation channel.
 *
 * @return Modulation clock input in Hz
 */
uint32_t Modulation::getModulationClockInput() const
{
	uint32_t baseFrequency = getClockGeneratorInputBaseFrequencyHz();
	uint32_t diffPerChannel = 200000;

	uint32_t resultingFrequency = baseFrequency;

	//Important: channel 0 is directly the baseFrequency, so in the middle one frequency must be skipped
	if (channel > 0)
	{
		if ((NUM_MODULATION_CHANNEL / 2) >= channel)
		{
			resultingFrequency = baseFrequency + (channel - (NUM_MODULATION_CHANNEL / 2) - 1) * diffPerChannel; //the -1 forces the skip
		}
		else
		{
			resultingFrequency = baseFrequency + (channel - (NUM_MODULATION_CHANNEL / 2)) * diffPerChannel;
		}
	}

	return resultingFrequency;
}

/** @} */
