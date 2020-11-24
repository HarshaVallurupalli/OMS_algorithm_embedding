/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup timestamp
 */
#include "timestamp.h"
#include "xtime_l.h"
#include "xparameters.h"
#include "xil_types.h"
#include "xpseudo_asm.h"
#include "xreg_cortexa9.h"
#include "sleep.h"

/* Global Timer is always clocked at half of the CPU frequency */
#define COUNTS_PER_MSECOND  (XPAR_CPU_CORTEXA9_CORE_CLOCK_FREQ_HZ / (2U*1000U))
#define COUNTS_PER_USECOND (XPAR_CPU_CORTEXA9_CORE_CLOCK_FREQ_HZ / (2U*1000000U))

///Stores the timestamp when function "timestampStart" is called
static XTime timeStart;

static void timestampStart(void);

/**
 * @brief Init
 *
 * Call before using this module
 *
 * @return 0
 */
int8_t timestampInit(void)
{
	timestampStart();

	return 0;
}

/**
 * @brief Store the start timestamp
 *
 * Stores the start timestamp. The goal is to later have a difference between the current timestamp
 * and the start timestamp.
 */
static void timestampStart(void)
{
  XTime_GetTime(&timeStart);
}

/**
 * @brief Get the difference in milliseconds
 *
 * Gives the difference to the start timestamp in milliseconds.
 *
 * @return Difference in milliseconds
 */
uint32_t timestampGetDiffMs(void)
{
	XTime timeNow;
	XTime_GetTime(&timeNow);

	XTime diffTime = (timeNow - timeStart) / COUNTS_PER_MSECOND;

	return (uint32_t)diffTime;
}

/**
 * @brief Get the current timestamp in milliseconds
 *
 * @return Timestamp in milliseconds
 */
uint32_t timestampGetMsCounter()
{
	XTime timeNow;
	XTime_GetTime(&timeNow);

	return (timeNow / COUNTS_PER_MSECOND);
}

/**
 * @brief Get the difference in microseconds
 *
 * Gives the difference to the start timestamp in mocroseconds.
 *
 * @return Difference in microseconds
 */
uint32_t timestampGetUsCounter()
{
	XTime timeNow;
	XTime_GetTime(&timeNow);

	return (timeNow / COUNTS_PER_USECOND);
}

/** @} */
