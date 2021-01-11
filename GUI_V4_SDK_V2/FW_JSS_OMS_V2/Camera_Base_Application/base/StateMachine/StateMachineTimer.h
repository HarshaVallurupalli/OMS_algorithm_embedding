/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup state_machine_timer Timer
 * @brief Timer functionality for the state machine
 * @ingroup state_machine
 *
 * @{
 */
#ifndef STATE_MACHINE_TIMER_H
#define STATE_MACHINE_TIMER_H

#include <stdint.h>

class SimpleTimer
{
	public:
		SimpleTimer();

		void start(const uint32_t value, const bool continuous = false);
		void restart();
		void stop();
		bool tick(const int32_t numTicks);

	private:
		int32_t actValue;
		int32_t initValue;
		bool continuous;
};

#endif /* STATE_MACHINE_TIMER_H */

/** @} */
