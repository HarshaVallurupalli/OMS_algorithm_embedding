/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup memory_info Memory Info
 * @brief Helper Class containing information about the (calibration) memory
 * @ingroup calibration
 *
 * @{
 */
#ifndef MEMORY_INFO_H_
#define MEMORY_INFO_H_

#include <stdint.h>

//! Memory Info
/*!
 * Helper Class containing information about the (calibration) memory
 */
class MemoryInfo
{
	public:
		uint32_t address;    ///<Address of the memory
		uint32_t size;       ///<Size of the memory
};

#endif /* MEMORY_INFO_H_ */

/** @} */
