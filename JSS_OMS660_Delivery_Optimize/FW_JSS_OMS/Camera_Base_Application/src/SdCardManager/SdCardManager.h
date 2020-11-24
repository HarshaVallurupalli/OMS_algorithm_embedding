/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup sd_card_manager SD Card Manager
 * @brief Helper class to read settings from the SD card
 *
 * @{
 */
#ifndef SD_CARD_MANAGER_H_
#define SD_CARD_MANAGER_H_

#include "SharedTypes.h"
#include <iostream>


typedef enum
{
	SD_CARD_MANAGER_RESULT_OK,
	SD_CARD_MANAGER_RESULT_ERROR
}SdCardResult_e;


//! SD Card Manager
/*!
 * Helper class to read settings from the SD card
 */
class SdCardManager
{
  public:
	  SdCardManager();
	  void init();
	  SdCardResult_e readAll();
	  ipAddress_t getIpAddress();
	  ipAddress_t getSubnetMask();
	  uint32_t getMacLastNumber();

  private:
	  SdCardResult_e readIpSettings();
	  ipAddress_t extractIpAddress(std::string data);
	  uint32_t extractNumber(std::string data);


	  ipAddress_t ipAddress;
	  ipAddress_t subnetMask;
	  uint8_t macLastNumber;

};

#endif /* SD_CARD_MANAGER_H_ */

/** @} */
