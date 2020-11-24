/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup header
 *
 * @{
 */
#include <Communication/Header.h>
#include <string.h>
#include "CommunicationConstants.h"
#include "Util/Util.h"

/**
 * @brief Constructor
 */
Header::Header()
{
  startOffset = 0;
  actSize = 0;
}

/**
 * @brief Create Header
 *
 * This function adds the header to the data. It therefore uses information from
 * - TOF_COS
 * - Acquisition Meta Data
 * - Image Type
 * - User Data
 *
 * Take care: There must be space available in the given buffer to add the header information.
 *
 * @param data Pointer to the data to add the header information
 * @param acquisitionMetaData Reference to the acquisition meta data
 * @param type Image type
 * @param userData Pointer to the user data received at the last command
 */
void Header::createHeader(uint8_t *data, TOF_COS_Epc660 &tofCos, const AcquisitionMetaData &acquisitionMetaData, const uint16_t type, const UserData *userData)
{
	/* This illustration shows the meaning of the variables                           */

	/*<------      headerSize + MAX_USER_BYTES           ------>                      */
	/*                        headerData      ¦      userData   ¦     measurementData */
	/*<------startOffset----->                                                        */
	/*                        <--   measurementDataOffset    -->                      */

	//Limit the userData to the maximum possible
	uint32_t copySize = userData->getSize();
	if (copySize > MAX_USER_BYTES)
	{
	  copySize = MAX_USER_BYTES;
	}

	startOffset = MAX_USER_BYTES - copySize;

	uint32_t measurementDataOffset = HEADER_SIZE + copySize;

	//Version
	data[startOffset + CommunicationConstants::Header::INDEX_VERSION] = HEADER_VERSION;

	//Type
	Util::setValueUint16BigEndian(data, (startOffset + CommunicationConstants::Header::INDEX_TYPE), type);

	//Size
	Util::setValueUint16BigEndian(data, (startOffset + CommunicationConstants::Header::INDEX_WIDTH), acquisitionMetaData.acquisitionInfo.getWidth());
	Util::setValueUint16BigEndian(data, (startOffset + CommunicationConstants::Header::INDEX_HEIGHT), acquisitionMetaData.acquisitionInfo.getHeight());

	//Origin
	Util::setValueUint16BigEndian(data, (startOffset + CommunicationConstants::Header::INDEX_ORIGIN_X), acquisitionMetaData.acquisitionInfo.roi.xMin);
	Util::setValueUint16BigEndian(data, (startOffset + CommunicationConstants::Header::INDEX_ORIGIN_Y), acquisitionMetaData.acquisitionInfo.roi.yMin);

	//Integration times
	Util::setValueUint16BigEndian(data, (startOffset + CommunicationConstants::Header::INDEX_INTEGRATION_TIME_3D_0), tofCos.getIntegrationTime3d(0));
	Util::setValueUint16BigEndian(data, (startOffset + CommunicationConstants::Header::INDEX_INTEGRATION_TIME_3D_1), tofCos.getIntegrationTime3d(1));

  //Copy the user Data
  memcpy(&data[startOffset + CommunicationConstants::Header::INDEX_USER_DATA], userData->getData(), copySize);

  //Data offset
  Util::setValueUint16BigEndian(data, (startOffset + CommunicationConstants::Header::INDEX_DATA_OFFSET), measurementDataOffset);

	actSize = measurementDataOffset;
}

/**
 * @brief Get the start offset
 *
 * This is the offset where the header data starts.
 *
 * @return Start offset
 */
uint16_t Header:: getStartOffset() const
{
  return startOffset;
}

/**
 * @brief Get the header size
 *
 * @return Header size
 */
uint32_t Header:: getActSize() const
{
  return actSize;
}

/** @} */
