/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup i2c1
 */
#include <GlobalSettings.h>
#include <hal/i2c/i2cInstance.h>
#include "xparameters.h"

#define IIC_DEVICE_ID		XPAR_XIICPS_1_DEVICE_ID   ///<The device ID of the i2c device
#define IIC_SCLK_RATE		                 400000   ///<i2c clock

/**
 * @brief Get instance reference to I2C1
 *
 * @return Reference to I2C1
 */
i2c_IF &i2cInstance::getInstance()
{
	static i2cInstance i2c1Instance;
	return i2c1Instance;
}

/**
 * @brief Init the hardware
 *
 * This function does the required initialization to have the I2C hardware ran.
 *
 * @retval 0 OK
 * @return 0 if there was no error, else a negative number
 */
int8_t i2cInstance::initHardware()
{
	int32_t Status;
	XIicPs_Config *Config;

	/*
	 * Initialize the IIC driver so that it's ready to use
	 * Look up the configuration in the config table,
	 * then initialize it.
	 */
	Config = XIicPs_LookupConfig(IIC_DEVICE_ID);
	if (NULL == Config)
	{
		return -1;
	}

	Status = XIicPs_CfgInitialize(&Iic, Config, Config->BaseAddress);
	if (Status != XST_SUCCESS)
	{
		return -1;
	}

	/*
	 * Perform a self-test to ensure that the hardware was built correctly.
	 */
	Status = XIicPs_SelfTest(&Iic);
	if (Status != XST_SUCCESS)
	{
		return -1;
	}

	/*
	 * Set the IIC serial clock rate.
	 */
	XIicPs_SetSClk(&Iic, IIC_SCLK_RATE);

	XIicPs_SetOptions(&Iic, XIICPS_7_BIT_ADDR_OPTION);

	return 0;
}

/** @} */
