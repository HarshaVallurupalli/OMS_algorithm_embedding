/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup config_reader
 *
 * @{
 */
#include <ConfigReader/ConfigReader.h>


ConfigReader::ConfigReader()
{

}

string ConfigReader::readValue(const char *file, const char *name)
{
	string input(file);
  string patternToSearch(name);

  patternToSearch += "=";

	int32_t index = input.find(patternToSearch);

	if (index < 0)
	{
		return nullptr;
	}

	int32_t indexOfValue = index+patternToSearch.length();

  int32_t endIndex = input.find("\r");
  if (endIndex < 0)
  {
    endIndex = input.length() - 1;
  }
  else
  {
  	endIndex -= 1;
  }

  string result = input.substr(indexOfValue, endIndex);

  int32_t len = result.length();

  return result;
}

/** @} */
