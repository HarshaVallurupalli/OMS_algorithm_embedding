/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup header Header
 * @ingroup communication
 * @brief Helper class to add header information to the data for the host.
 *
 * @{
 */
#ifndef HEADER_H_
#define HEADER_H_

#include <Communication/UserData.h>
#include <stdint.h>
#include "AcquisitionMetaData/AcquisitionMetaData.h"
#include "TOF_COS_Epc660.h"

//! Header
/*!
 * Helper class to add header information to the data for the host.
 */
class Header
{
	public:
		Header();

		void createHeader(uint8_t *data, TOF_COS_Epc660 &tofCos, const AcquisitionMetaData &acquisitionMetaData, const uint16_t type, const UserData *userData);

		uint16_t getStartOffset() const;
		uint32_t getActSize() const;

		static const uint16_t MAX_USER_BYTES = 1063;
		static const uint8_t HEADER_SIZE = 25;
		static const uint16_t MAX_HEADER_SIZE = HEADER_SIZE + MAX_USER_BYTES;
		static const uint8_t HEADER_VERSION = 2;

	private:
		uint16_t startOffset;
		uint32_t actSize;

};

#endif /* HEADER_H_ */

/** @} */
