/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup timer
 */
#include "timer.h"
#include "sleep.h"

/**
 * @brief Do a blocking delay
 *
 * This function blocks for the given amount of milliseconds.
 *
 * @param timeMs Time in ms to block
 */
void timerBlockingDelay(const uint32_t timeMs)
{
  usleep(timeMs * 1000);
}

/** @} */
