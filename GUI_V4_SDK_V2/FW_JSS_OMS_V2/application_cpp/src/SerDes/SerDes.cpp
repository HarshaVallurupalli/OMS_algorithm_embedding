/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup serdes
 */
#include <SerDes/SerDes.h>
#include <sleep.h>
#include <stdint.h>

SerDes::SerDes(i2c_IF &i2c): i2c(i2c)
{

}

/**
 * @brief Establish connection
 *
 * This function configures the serializer and the deserializer to have a stable connection. Once configured,
 * the parameters are not changed anymore.
 *
 * @retval 0 Success
 * @retval -1 Error during configuration
 * @return Status
 */

#define BASE_SER_ADDR 0x40 // base serializer I2C addr

uint16_t CAMn_DES_ADDR[4] = {0x4A, 0X4E, 0X5A, 0X5E}; // current deserializer addresses
uint16_t CAMn_SER_ADDR[4] = {0x40, 0x40, 0x40, 0x40}; // new serializer addresses



/* I2C sensor address translation slot A
CAMn_SER_ADDR[cam_num]: serializer address
actual_addr: current address of the sensor
new_addr: new address for sensor
*/
void SerDes::change_i2c_src_dst_A(uint8_t cam_num, uint8_t actual_addr, uint8_t new_addr)
{
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x09, new_addr);
	usleep(10000);
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x0A, actual_addr);
	usleep(10000);
}

/* I2C sensor address translation slot B
CAMn_SER_ADDR[cam_num]: serializer address
actual_addr: current address of the sensor
new_addr: new address for sensor
*/
void SerDes::change_i2c_src_dst_B(uint8_t cam_num, uint8_t actual_addr, uint8_t new_addr)
{
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x0B, new_addr);
	usleep(10000);
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x0C, actual_addr);
	usleep(10000);
}


int8_t SerDes::connect(uint8_t cam_num)
{
	// config by MAXIM (Tom Brady), modified by ASC
	// hvsrc (0x06), enables reverse channel
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x06, 0x6F);
	usleep(10000);
	// i2cconfig (0x0D), sets base I2C
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x0D, 0xB6);
	usleep(10000);
	// assuming only one link is active
	// change remote device from base address to new address
/*	i2c.writeByte(old_ser_addr, 0x00, (uint8_t)CAMn_SER_ADDR[cam_num-1]);
	usleep(10000);*/
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x04, 0x43);
	usleep(10000);
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x08, 0x01);
	usleep(10000);
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x97, 0x5F);
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x9A, 0x19);
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x97, 0x62);
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x06, 0xEF);
	usleep(10000);
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x4D, 0x80);
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x07, 0xB5);
	usleep(10000);
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x07, 0xB5);
	usleep(10000);



	//Set Crossbar on Deserializer
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x65, 0xB4);    // crossbar_0
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x66, 0x56);    // crossbar_2
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x67, 0x73);    // crossbar_4
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x68, 0x21);    // crossbar_6
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x69, 0x0A);    // crossbar_8 (DCLK @ DATA0)
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x6A, 0x98);    // crossbar_10
	usleep(10000);
	i2c.writeByte(CAMn_DES_ADDR[cam_num-1], 0x6B, 0xCD);    // crossbar_12 (12/27, 13/28)
	usleep(10000);
///*
	//Set CrossBar on Serializer
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x2C, 0x0E);    // crossbar_12 -> use hsync (din14)
	usleep(10000);
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x3C, 0x1E);    // crossbar_28 -> hsync high bit, why not crossbar_12+15=27 as used in deserializer?
	usleep(10000);

	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x2D, 0x0F);    // crossbar_13 -> use vsync (din15)
	usleep(10000);
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x3D, 0x1F);    // crossbar_29 -> vsync high bit, why not crossbar_13+15=28 as used in deserializer?
	usleep(10000);
//*/
	// activate
	i2c.writeByte(CAMn_SER_ADDR[cam_num-1], 0x04, 0x83);
	usleep(10000);
    uint8_t data[2]={0,0};
    int8_t status = i2c.readByte(0x40, 0x00, data);
	usleep(10000);
    status = i2c.getAndClearStatus();

  return status;
}

/** @} */
