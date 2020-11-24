/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup timer Timer
 * @ingroup hal
 *
 * @brief HAL for the Timer
 *
 * @{
 */
#ifndef TIMER_H_
#define TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

void timerBlockingDelay(const uint32_t timeMs);

#ifdef __cplusplus
}
#endif

#endif // TIMER_H_

/** @} */
