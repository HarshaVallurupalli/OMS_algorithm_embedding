/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup user_data User Data
 * @ingroup communication
 *
 * @brief Stores the user data extracted from the command
 *
 * @{
 */
#ifndef USER_DATA_
#define USER_DATA_

#include <stdint.h>

//! User Data
/*!
 * Stores the user data extracted from the command
 */
class UserData
{
	public:
		UserData();
	  static const uint32_t MAX_SIZE = 1024;

	  void setData(const uint8_t *data, const uint32_t size);
	  void setData(const class UserData &userData);
	  uint8_t *getData() const;
	  uint32_t getSize() const;

	private:
    uint8_t data[MAX_SIZE];
    uint32_t size;
};

#endif /* USER_DATA_ */

/** @} */
