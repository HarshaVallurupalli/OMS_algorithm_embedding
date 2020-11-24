/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup cpu CPU
 * @ingroup hal
 *
 * @brief HAL for CPU specific stuff
 *
 * @{
 */
#ifndef CPU_CPU_H_
#define CPU_CPU_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

int8_t cpuInit(void);
void cpuInvalidateDCachebyAddrU32(uint32_t *addr, int32_t dsize);
void cpuInvalidateDCachebyAddrU16(uint16_t *addr, int32_t dsize);
void cpuInvalidateDCachebyAddrU8(uint8_t *addr, int32_t dsize);

#ifdef __cplusplus
}
#endif

#endif /* CPU_CPU_H_ */

/** @} */
