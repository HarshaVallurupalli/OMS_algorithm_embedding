#ifndef SRC_GLOBAL_H_
#define SRC_GLOBAL_H_

#include "xil_printf.h"

#ifdef __cplusplus
extern "C" {
#endif

#define TRACE(...) xil_printf(__VA_ARGS__);

//If 1, do some time measurements
#define TIME_MEASUREMENT 1

#ifdef __cplusplus
}
#endif

#endif /* SRC_GLOBAL_H_ */
