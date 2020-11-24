/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup io
 */
#include "GlobalSettings.h"
#include "hal/io/IO.h"
#include <sleep.h>

/**
 * @brief Constructor
 *
 */
IO::IO()
{
	initDone = false;
}

/**
 * @brief Init the hardware
 *
 * This function actually initializes the hardware.
 */
void IO::init()
{
	int status;
	// SerDes GPIO cam1
	status = XGpio_Initialize(&SerDesGpio, XPAR_AXI_GPIO_POWER_RESET_DEVICE_ID);
	if (status != XST_SUCCESS)
	{
	  return;
	}
	// Set the direction to output
	XGpio_SetDataDirection(&SerDesGpio, 1, 0x00);


	}

/**
 * @brief Init the hardware
 *
 * This function does the needed initialization of the hardware. It only does it, if it is
 * not yet done. The intention is to prevent the need of an external/public init function.
 */
void IO::initIfNotYetDone()
{
	if (initDone == false)
	{
		initDone = true;
		init();
	}
}

/**
 * @brief Set the power of the OMS
 *
 * This function controls the power to the OMS
 *
 * @param enabled Flag power enabled or not
 */
void IO::setPowerEnabled(const bool enabled)
{
	initIfNotYetDone();

	if (enabled)
  {
  	XGpio_DiscreteWrite(&SerDesGpio, 1, 0xFF);

  	//Delay to let the OMS startup
  	usleep(300000);
  }
  else
  {
  	XGpio_DiscreteWrite(&SerDesGpio, 1, 0x00);
  }
}

/**
 * @brief Get the instance
 *
 * Creates one instance of the IO class.
 *
 * @return Reference to the instance
 */
IO_IF &IO::getInstance()
{
	static IO io;
	return io;
}

/** @} */
