/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup sd_card_manager
 *
 * @{
 */
#include "SdCardManager.h"
#include "ConfigReader/ConfigReader.h"
#include "hal/sd_card/sd_card.h"
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;



static const char *FILE_NAME_IP_SETTINGS = "ethconfig.cfg";

SdCardManager::SdCardManager()
{

}

void SdCardManager::init()
{
	sdCardInit();
}

SdCardResult_e SdCardManager::readAll()
{
  return readIpSettings();
}

ipAddress_t SdCardManager::extractIpAddress(string data)
{
	uint32_t value[4];
	uint32_t counter = 0;

	std::replace(data.begin(), data.end(), '.', ' ');

	std::stringstream ss;

	/* Storing the whole string into string stream */
	ss << data;

	/* Running loop till the end of the stream */
	string temp;
	while (!ss.eof())
	{

		/* extracting word by word from stream */
		ss >> temp;

		/* Checking the given word is integer or not */
		if (stringstream(temp) >> value[counter])
			counter++;

		/* To save from space at the end of string */
		temp = "";
	}

	ipAddress_t address;
	address.val0 = value[0];
	address.val1 = value[1];
	address.val2 = value[2];
	address.val3 = value[3];

	return address;
}

uint32_t SdCardManager::extractNumber(string data)
{
	uint32_t value[4];
	uint32_t counter = 0;

	std::replace(data.begin(), data.end(), '.', ' ');

	std::stringstream ss;

	/* Storing the whole string into string stream */
	ss << data;

	/* Running loop till the end of the stream */
	string temp;
	while (!ss.eof())
	{

		/* extracting word by word from stream */
		ss >> temp;

		/* Checking the given word is integer or not */
		if (stringstream(temp) >> value[counter])
			counter++;

		/* To save from space at the end of string */
		temp = "";
	}

	return value[0];
}

SdCardResult_e SdCardManager::readIpSettings()
{
	char tempBuffer[256];
	int8_t status = sdCardReadData(FILE_NAME_IP_SETTINGS, tempBuffer, sizeof(tempBuffer));
	if (status < 0)
	{
		return SdCardResult_e::SD_CARD_MANAGER_RESULT_ERROR;
	}/* Cancel here ----------------------------------------------------> */

	std::string ip = ConfigReader::readValue(tempBuffer, "ip");
	std::string subnet = ConfigReader::readValue(tempBuffer, "subnet");
	std::string mac = ConfigReader::readValue(tempBuffer, "mac");

	ipAddress = extractIpAddress(ip);
	subnetMask = extractIpAddress(subnet);
	macLastNumber = extractNumber(mac);

	return SdCardResult_e::SD_CARD_MANAGER_RESULT_OK;
}

ipAddress_t SdCardManager::getIpAddress()
{
  return ipAddress;
}

ipAddress_t SdCardManager::getSubnetMask()
{
  return subnetMask;
}

uint32_t SdCardManager::getMacLastNumber()
{
	return macLastNumber;
}
