/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup serdes Serializer Deserializer
 *
 * @brief Setup the Serializer and Deserializer
 *
 * @{
 */
#ifndef SER_DES_H_
#define SER_DES_H_

#include <stdint.h>
#include "hal/i2c_IF.h"
#define BASE_SER_ADDR 0x40 // base serializer I2C addr


class SerDes
{
	public:
		SerDes(i2c_IF &i2c);
		int8_t connect(uint8_t cam_num);
		void change_i2c_src_dst_A(uint8_t cam_num, uint8_t actual_addr, uint8_t new_addr);
		void change_i2c_src_dst_B(uint8_t cam_num, uint8_t actual_addr, uint8_t new_addr);
	private:
		i2c_IF &i2c;
};

#endif /* SER_DES_H_ */

/** @} */
