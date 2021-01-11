/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup sd_card SD Card driver
 * @ingroup hal
 *
 * @brief HAL for the SD Card
 *
 * @{
 */
#ifndef SD_CARD_H_
#define SD_CARD_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

int8_t sdCardInit(void);
bool sdCardIsAvailable(void);
int8_t sdCardWriteDataWriteUpdateFile(const char *data, const uint32_t size);
int8_t sdCardWriteData(const char *name, const char *data, const uint32_t size);
int8_t sdCardReadData(const char *name, char *data, const uint32_t size);

#ifdef __cplusplus
}
#endif

#endif /* SD_CARD_H_ */

/** @} */
