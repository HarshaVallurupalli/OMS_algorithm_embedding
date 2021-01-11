/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup delay_helper Delay Helper
 * @brief Helper class for the delay because of temperature during calibration
 * @ingroup calibration
 *
 * @{
 */
#ifndef BASE_CALIBRATION_DELAYHELPER_H_
#define BASE_CALIBRATION_DELAYHELPER_H_

#include <stdint.h>

//! Helper class for the calibration
/*!
 * This is a small helper class used in the calibration process. It's responsible for the delay time
 * when the temperature of the TOF imager is not in the desired range.
 */
class DelayHelper
{
	public:
		DelayHelper();
		virtual ~DelayHelper();

		void increase();
		void decrease();
		int32_t getDelay() const;
		bool maxDelayReached();

	private:
		int32_t delay;   ///<stores the actual delay
};

#endif /* BASE_CALIBRATION_DELAYHELPER_H_ */

/** @} */
