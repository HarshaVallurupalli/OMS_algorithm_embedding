/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup io_expander_instance
 */
#include <hal/i2c/i2cInstance.h>
#include <IoExpander/IoExpanderInstance.h>

/**
 * @brief Get the instance
 *
 * @return Reference to the IO expander
 */
IoExpander &IoExpanderInstance::getInstance()
{
	static IoExpander ioExpander(i2cInstance::getInstance());

	return ioExpander;
}

/** @} */
