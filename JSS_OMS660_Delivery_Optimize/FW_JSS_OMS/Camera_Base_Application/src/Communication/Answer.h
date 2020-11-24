/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup answer Answer
 * @ingroup communication
 *
 * @brief Creates packets to send to the host
 *
 * @{
 */
#ifndef ANSWER_H_
#define ANSWER_H_

#include "GlobalConstants.h"
#include <Communication/Header.h>
#include <stdint.h>

//! Answer
/*!
 * Creates packets to send to the host
 */
class Answer
{
	public:
		Answer();

		void sendAcknowledge();
		void sendError(const uint8_t errorNumber);
		void sendData(const uint8_t type, uint8_t *data, const uint32_t size);
		void sendChipInformation(const uint16_t chipId, const uint16_t waferId);
		void sendFirmwareRelease(const uint32_t release);
		void addHeader(TOF_COS_Epc660 &tofCos, const class AcquisitionMetaData &acquisitionMetaData, const class UserData *userData);

		uint8_t *getData() const;
		uint32_t getDataSize() const;
		uint8_t *getAnswer();
		uint8_t getAnswerSize() const;
		uint8_t getType() const;

	protected:
		uint8_t answer[MAX_COMMUNICATION_PAYLOAD_SIZE];  ///<Answer for the TCP socket
		uint8_t answerSize;                             ///<Size of the answer for the TCP socket
		uint8_t *data;                                   ///<Pointer to the data for the UDP socket
		uint32_t dataSize;                               ///<Size of the data for the UDP socket
		Header header;                                   ///<Helper to create the header
		uint8_t type;                                   ///<Data type

	private:

};

#endif /* ANSWER_H_ */

/** @} */
