/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup modulation Modulation
 * @brief Handle the modulation settings
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef MODULATION_H_
#define MODULATION_H_

#include <stdint.h>
#include "tof_cos_clock_generator.h"

//! Handle the modulation settings
/*!
 * This class is responsible to handle the modulation settings.
 */
class Modulation
{
	public:
    ///Simple enum for each base modulation frequency. The frequency may slightly change based to the used channel
		enum ModulationFrequency
    {
      MODULATION_10MHZ = 0,
	    MODULATION_20MHZ = 1,
			MODULATION_12MHZ = 2,
			MODULATION_24MHZ = 3,
			MODULATION_5MHZ = 4,
			MODULATION_6MHZ = 5,
			MODULATION_2_5MHZ = 6,
			MODULATION_3MHZ = 7,
			MODULATION_1_25MHZ = 8,
			MODULATION_1_5MHZ = 9,
			MODULATION_0_625MHZ = 10,
			MODULATION_0_75MHZ = 11,
			MODULATION_0_375MHZ = 12,
	    MODULATION_NOT_SET
    };

    Modulation();
    Modulation(const Modulation::ModulationFrequency frequency);
    Modulation &operator=(const Modulation::ModulationFrequency frequency);
    Modulation::ModulationFrequency getModulationFrequency() const;
    void setModulationFrequency(const Modulation::ModulationFrequency frequency);
    static void setChannel(const uint8_t channel);
    static void setAutoChannelEnabled(const bool enabled);
    static bool hasChanged();
    uint32_t getChannel() const;
    uint32_t getDistanceRange() const;
    uint16_t getBaseDistanceRange() const;
    uint8_t getChipDivider() const;
    uint32_t getClockGeneratorInputBaseFrequencyHz() const;
    uint32_t getModulationFrequencyHz() const;
    uint32_t getModulationClockInput() const;
    tofCosClockGeneratorClock_e getClock() const;
    bool getAutoChannelEnabled() const;
    float getRangeMultiplier() const;
    bool isInMillimeter() const;

	private:
    ModulationFrequency modulationFrequency;    ///<Modulation frequency. This can be independent for each instance
    static uint8_t channel;                    ///<Modulation channel --> the same for all instances, therefore it is static.
    static bool autoChannelEnabled;             ///<True, if the modulation channel should be automatically changed in case of interference --> the same for all instances, therefore static
    static bool changed;                        ///<True, if the static settings have changed
};

#endif /* MODULATION_H_ */

/** @} */
