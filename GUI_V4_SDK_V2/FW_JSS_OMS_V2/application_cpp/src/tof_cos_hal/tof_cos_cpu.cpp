#include "tof_cos_cpu.h"
#include "hal/cpu/cpu.h"

void tofCosCpuInvalidateDCachebyAddrU32(uint32_t *addr, int32_t dsize)
{
  cpuInvalidateDCachebyAddrU32(addr, dsize);
}

