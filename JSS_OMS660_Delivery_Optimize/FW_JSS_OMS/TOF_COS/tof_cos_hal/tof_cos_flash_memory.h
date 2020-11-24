/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup tof_cos_flash_memory Flash Memory
 * @ingroup tof_cos_hal
 * @brief This is an abstraction layer for the flash memory used in the TOF_COS
 *
 *
 * @{
 */
#ifndef TOF_COS_FLASH_MEMORY_H_
#define TOF_COS_FLASH_MEMORY_H_

#include <stdint.h>

int32_t tofCosFlashMemoryInit(void);
int32_t tofCosFlashMemoryBulkErase(void);
int32_t tofCosFlashMemoryWrite(const uint32_t address, const uint8_t *writeBuffer, const uint32_t size);
int32_t tofCosFlashMemoryRead(const uint32_t address, uint8_t *readBuffer, const uint32_t size);

#endif /* TOF_COS_FLASH_MEMORY_H_ */

/** @} */
