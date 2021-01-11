/**
 * Copyright (C) 2016 Espros Photonics Corporation
 *
 * @defgroup io IO
 * @ingroup hal
 *
 * @brief HAL function to control the GPIO pins
 *
 * @{
 */
#ifndef IO_H_
#define IO_H_

#include "hal/IO_IF.h"
#include "xgpio.h"

//! IO class
/*!
 * HAL function so control the IOs
 */
#define DBPORT1 1
#define DBPORT2 2
#define DBPORT3 3
#define DBPORT4 4
class IO: public IO_IF
{
	public:
    	void setPowerEnabled(const bool enabled);
    	static IO_IF &getInstance();
    	void PoweronDaughterBoardPort(const uint8_t port);

	private:
		IO();
		void init();
		void initIfNotYetDone();
		bool initDone;

		XGpio SerDesGpio;  // Rst GPIO for cam

};

#endif /* IO_H_ */

/** @} */
