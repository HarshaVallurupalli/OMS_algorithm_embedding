/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup tof_cos_sys_timer
 *
 * @{
 */
#include "tof_cos_sys_timer.h"
#include "hal/timer/timer.h"

/**
 * @brief Register callback
 *
 * The callback function gets called every millisecond
 *
 * @param callback Pointer to the callback function to call
 * @param arg Pointer to the argument that will be given to the callback
 */
void tofCosSysTimerTickRegisterCallback(void(*callback)(void *), void *arg)
{
	//TODO: implement if needed
}

/**
 * @brief Blocking delay for the given time
 *
 * @param timeMs Time to block in ms
 */
void tofCosSysTimerBlockingDelay(const uint32_t timeMs)
{
  timerBlockingDelay(timeMs);
}

/** @} */
