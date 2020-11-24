/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup timestamp Timestamp
 * @ingroup hal
 *
 * @brief HAL for the timestamp
 */

#ifndef TIMESTAMP_H_
#define TIMESTAMP_H_

#include <stdint.h>

int8_t timestampInit(void);
uint32_t timestampGetDiffMs(void);
uint32_t timestampGetMsCounter();
uint32_t timestampGetUsCounter();

#endif /* TIMESTAMP_H_ */

/** @} */
