/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup tof_cos_sys_timer System Timer
 * @ingroup tof_cos_hal
 *
 * @brief HAL for the system timer
 *
 * @{
 */
#ifndef TOF_COS_SYS_TIMER_H_
#define TOF_COS_SYS_TIMER_H_

#include <stdint.h>

void tofCosSysTimerTickRegisterCallback(void(*callback)(void *), void *arg);
void tofCosSysTimerBlockingDelay(const uint32_t timeMs);

#endif /* TOF_COS_SYS_TIMER_H_ */

/** @} */
