/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup i2c1 I2C1
 * @ingroup i2c
 *
 * @brief HAL for the I2C1
 */
#ifndef HAL_I2C_I2C1_H_
#define HAL_I2C_I2C1_H_

#include "i2cBase.h"

//! I2C class
/*!
 * HAL function so control the I2C1
 */
class i2cInstance: public i2cBase
{
  public:
	  static i2c_IF &getInstance();

  private:
	  int8_t initHardware();
};

#endif /* HAL_I2C_I2C1_H_ */

/** @} */
