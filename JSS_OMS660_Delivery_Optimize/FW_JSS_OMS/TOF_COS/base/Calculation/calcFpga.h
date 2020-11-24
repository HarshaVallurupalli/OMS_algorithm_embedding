#ifndef TOFAPI_IMPLEMENTATION_CALC_CALCFPGA_H_
#define TOFAPI_IMPLEMENTATION_CALC_CALCFPGA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>

bool calcFpgaIsAdcOverflow(const uint32_t value);
bool calcFpgaIsSaturated(const uint32_t value);
uint32_t calcFpgaAmplitude(const uint32_t value);
bool calcFpgaIsInterfered(const uint32_t value);
uint32_t calcFpgaDistanceNormal(const uint32_t value);
uint32_t calcFpgaDistanceCalibration(const uint32_t value);

#ifdef __cplusplus
}
#endif


#endif /* TOFAPI_IMPLEMENTATION_CALC_CALCFPGA_H_ */
