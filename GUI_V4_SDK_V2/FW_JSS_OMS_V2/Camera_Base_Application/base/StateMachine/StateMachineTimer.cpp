/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup state_machine_timer
 */
#include "StateMachineTimer.h"

SimpleTimer::SimpleTimer()
{
  actValue = 0;
  initValue = 0;
  continuous = false;
}

void SimpleTimer::start(const uint32_t value, const bool continuous)
{
	this->actValue = value;
	this->initValue = value;
  this->continuous = continuous;
}

void SimpleTimer::restart()
{
  actValue = initValue;
}

void SimpleTimer::stop()
{
  actValue = 0;
}

bool SimpleTimer::tick(const int32_t numTicks)
{
	bool timeOver = false;

	if (actValue > 0)
	{
		actValue -= numTicks;
	  if (actValue <= 0)
	  {
	    timeOver = true;
	    if (continuous)
	    {
	    	actValue = initValue;
	    }
	    else
	    {
	    	actValue = 0;
	    }
	  }
	}

	return timeOver;
}

/** @} */
