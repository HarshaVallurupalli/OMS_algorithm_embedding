/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @addtogroup user_data
 *
 * @{
 */
#include <Communication/UserData.h>
#include <string.h>

/**
 * @brief Constructor
 */
UserData::UserData()
{
	size = 0;
}

/**
 * @brief Set the data
 *
 * With buffer and size
 *
 * @param data Pointer to the data
 * @param size Size of the data
 */
void UserData::setData(const uint8_t *data, const uint32_t size)
{
	memcpy(this->data, data, size);
	this->size = size;
}

/**
 * @brief Set the data
 *
 * With another instance of user data
 *
 * @param userData Reference to the user data
 */
void UserData::setData(const class UserData &userData)
{
	memcpy(this->data, userData.data, userData.size);
	this->size = userData.size;
}

/**
 * @brief Get the data
 *
 * @Return Pointer to the data
 */
uint8_t *UserData::getData() const
{
	return (uint8_t *)data;
}

/**
 * @brief Get the data size
 *
 * @Return Data size
 */
uint32_t UserData::getSize() const
{
	return size;
}

/** @} */
