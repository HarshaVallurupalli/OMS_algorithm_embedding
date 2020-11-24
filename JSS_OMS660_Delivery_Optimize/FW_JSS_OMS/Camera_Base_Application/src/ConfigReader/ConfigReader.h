/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup config_reader Config Reader
 * @brief Helper class to read configuration strings, for example from SD card
 *
 * @{
 */
#ifndef CONFIG_READER_H_
#define CONFIG_READER_H_

#include <iostream>

using namespace std;


//! Config Reader
/*!
 * Helper class to read configuration strings, for example from SD card
 */
class ConfigReader
{
  public:
	  ConfigReader();
	  static string readValue(const char *file, const char *name);
};

#endif /* CONFIG_READER_H_ */

/** @} */
