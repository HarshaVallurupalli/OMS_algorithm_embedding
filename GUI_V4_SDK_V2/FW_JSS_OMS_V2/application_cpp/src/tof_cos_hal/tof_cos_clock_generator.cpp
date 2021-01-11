/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup tof_cos_clock_generator
 *
 * @{
 */
#include <hal/i2c/i2cInstance.h>
#include "tof_cos_clock_generator.h"
#include "register_settings.h"
#include "GlobalConstants.h"


static const uint8_t DEVICE_ADDRESS_CLOCK_GENERATOR = 106;

static int8_t writeClock(const uint8_t *registers, const uint32_t size);


/**
 * @brief Init
 *
 * @return 0
 */
int8_t tofCosClockGeneratorInit()
{
	//Write default clock
	writeClock(register_list_96MHz, sizeof(register_list_96MHz));

  return 0;
}

/**
 * @brief Write frequency and channel
 *
 * Call this function to set the modulation frequency and the modulation channel.
 *
 * Modulation channel is not supported so far here
 *
 * @param clock Enum for the modulation clock input from the clock generator (base frequency)
 * @param channel Channel number
 * @retval 0 Success
 * @retval -1 Error
 * @return Result
 */
int8_t tofCosClockGeneratorWriteFrequency(const tofCosClockGeneratorClock_e clock)
{
  switch(clock)
  {
    case tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_96MHZ:
    	writeClock(register_list_96MHz, sizeof(register_list_96MHz));
  	  break;
    case tofCosClockGeneratorClock_e::TOF_COS_CLOCK_GENERATOR_48MHZ:
    	writeClock(register_list_48MHz, sizeof(register_list_48MHz));
    	break;
    default:
    	writeClock(register_list_96MHz, sizeof(register_list_96MHz));
    	break;
  }

	return 0;
}

/**
 * @brief Write the clocks
 *
 * This helper function loops through the registers and writes them into the clock generator.
 * The registers are stored as look-up tables.
 *
 * @param registers Pointer to the register values
 * @param size Size of the register list
 * @retval 0 Success
 * @retval -1 Error
 * @return Result
 */
int8_t writeClock(const uint8_t *registers, const uint32_t size)
{
  i2c_IF &i2c = i2cInstance::getInstance();

	for (uint32_t i = 0; i < size; i++)
	{
		int8_t status = i2c.writeByte(DEVICE_ADDRESS_CLOCK_GENERATOR, i, registers[i]);
	  if (status < 0)
	  {
	    return status;
	  }/* Cancel ------------------------------------------------> */
	}

	return 0;
}

/** @} */
