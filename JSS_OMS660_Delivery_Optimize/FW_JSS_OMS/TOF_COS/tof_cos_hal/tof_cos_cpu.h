/*
 * tof_cos_cpu.h
 *
 *  Created on: 22.08.2019
 *      Author: mwi
 */

#ifndef TOF_COS_CPU_H_
#define TOF_COS_CPU_H_

#include <stdint.h>

void tofCosCpuInvalidateDCachebyAddrU32(uint32_t *addr, int32_t dsize);


#endif /* TOF_COS_CPU_H_ */
