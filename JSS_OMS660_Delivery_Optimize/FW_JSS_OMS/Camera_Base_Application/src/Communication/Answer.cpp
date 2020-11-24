/***
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup answer
 */
#include "Communication/Answer.h"
#include "Communication/Header.h"
#include "Communication/UserData.h"
#include "CommunicationConstants.h"
#include "Util/Util.h"

/**
 * @brief Constructor
 */
Answer::Answer()
{
	dataSize = 0;
	data = nullptr;
	this->type = CommunicationConstants::DataType::DATA_DISTANCE;
}

/**
 * @brief Send acknowledge
 *
 */
void Answer::sendAcknowledge()
{
	this->data = nullptr;
	this->dataSize = 0;
	this->answer[CommunicationConstants::AnswerType::INDEX] = CommunicationConstants::AnswerType::ANSWER_ACK;
	this->answerSize = CommunicationConstants::Answer::SIZE + CommunicationConstants::AnswerData::Acknowledge::SIZE;
}

/**
 * @brief Send error
 *
 * @param errorNumber Error number to send
 */
void Answer::sendError(const uint8_t errorNumber)
{
	this->data = nullptr;
	this->dataSize = 0;
  this->answer[CommunicationConstants::AnswerType::INDEX] = CommunicationConstants::AnswerType::ANSWER_ERROR;
  Util::setValueUint16BigEndian(answer, 1, errorNumber);
	this->answerSize = CommunicationConstants::Answer::SIZE + CommunicationConstants::AnswerData::Error::SIZE;
}

/**
 * @brief Send chip information to the host
 *
 * @param chipId Chip ID to send
 * @param waferId Wafer ID to send
 */
void Answer::sendChipInformation(const uint16_t chipId, const uint16_t waferId)
{
  this->data = nullptr;
	this->dataSize = 0;
	this->answer[CommunicationConstants::AnswerType::INDEX] = CommunicationConstants::AnswerType::ANSWER_CHIP_INFORMATION;
	Util::setValueUint16BigEndian(answer, CommunicationConstants::AnswerData::ChipInformation::INDEX_WAFER_ID, waferId);
	Util::setValueUint16BigEndian(answer, CommunicationConstants::AnswerData::ChipInformation::INDEX_CHIP_ID, chipId);
  this->answerSize = CommunicationConstants::Answer::SIZE + CommunicationConstants::AnswerData::ChipInformation::SIZE;
}

/**
 * @brief Send the firmware release to the host
 *
 * @param release Firmware Release to send
 */
void Answer::sendFirmwareRelease(const uint32_t release)
{
  this->data = nullptr;
  this->dataSize = 0;
  this->answer[CommunicationConstants::AnswerType::INDEX] = CommunicationConstants::AnswerType::ANSWER_FIRMWARE_RELEASE;
  Util::setValueUint32BigEndian(answer, CommunicationConstants::AnswerData::FirmwareRelease::INDEX, release);
  this->answerSize = CommunicationConstants::Answer::SIZE + CommunicationConstants::AnswerData::FirmwareRelease::SIZE;
}

/**
 * @brief Send data
 *
 * Send image data to the host
 *
 * Take care: The data buffer needs to have space to add the header at the beginning
 *
 * @param type Type of the data
 * @param data Pointer to the data to send
 * @param size Size of the data to send
 */
void Answer::sendData(const uint8_t type, uint8_t *data, const uint32_t size)
{
  this->data = data;
	this->dataSize = size;
	this->type = type;
	this->answer[CommunicationConstants::AnswerType::INDEX] = CommunicationConstants::AnswerType::ANSWER_ACK;
	this->answerSize = 1;
}

/**
 * @brief Add the header
 *
 * @param tofCos Reference to the TOF_COS
 * @param acquisitionMetaData Reference to the acquisition meta data
 * @param userData Pointer to the user data received at the last command
 */
void Answer::addHeader(TOF_COS_Epc660 &tofCos, const class AcquisitionMetaData &acquisitionMetaData, const class UserData *userData)
{
  header.createHeader(this->data, tofCos, acquisitionMetaData, type, userData);
}

/**
 * @brief Get the image type
 *
 * The type was set with the function "sendData"
 *
 * @return Image type
 */
uint8_t Answer::getType() const
{
	return type;
}

/**
 * @brief Get the data
 *
 * This is the image data for the image channel, for example UDP
 *
 * @return Data
 */
uint8_t *Answer::getData() const
{
	if (data == nullptr)
	{
		return nullptr;
	}

	return &data[header.getStartOffset()];
}

/**
 * @brief Get the data size
 *
 * This is the image data for the image channel, for example UDP
 *
 * @return Data size
 */
uint32_t Answer::getDataSize() const
{
	return dataSize + header.getActSize();
}

/**
 * @brief Get the answer
 *
 * This is the data for the answer channel, for example TCP
 *
 * @return Answer
 */
uint8_t *Answer::getAnswer()
{
  return answer;
}

/**
 * @brief Get the answer size
 *
 * This is the size of the answer for the answer channel, for example TCP
 *
 * @return Answer size
 */
uint8_t Answer::getAnswerSize() const
{
	return answerSize;
}

/** @} */
