#include "tof_cos_timestamp.h"
#include "hal/timestamp/timestamp.h"


uint32_t tofCosTimestampGetMsCounter()
{
	return timestampGetMsCounter();
}
