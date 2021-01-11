/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup calibration_types Types
 * @brief Types for calibration
 * @ingroup calibration
 *
 * @{
 */
#ifndef BASE_CALIBRATION_CALIBRATION_TYPES_H_
#define BASE_CALIBRATION_CALIBRATION_TYPES_H_

#include <stdint.h>

///<This is the number of bytes that can be written to the flash at once only this number of bytes can be written at least on some processors. On other processors, this will be done also for compatibility
const uint32_t FLASH_WORD_SIZE = 32;

///<Multiplicator for the values in the DRNU LUT. The corrections need to be around +/- 30cm. Because the calculations are done in mm and the LUT has a range of
const uint32_t CALIBRATION_MULTIPLIER = 16;

///<Special value in the LUT for broken pixels
const int8_t DRNU_LUT_VALUE_BROKEN_PIXEL = -127;

///<Maximum number of broken pixels. Can not just be changed.
#define MAX_POSSIBLE_BROKEN_PIXELS 8

const int32_t DISTANCE_RANGE = 51471;                                                        ///<Distance range in the calibration data

//Do not change the numbers. 10MHz and 20MHz are historical
enum
{
	CALIBRATED_MODULATION_FREQUENCY_10MHZ = 0,
	CALIBRATED_MODULATION_FREQUENCY_20MHZ = 1,
	CALIBRATED_MODULATION_FREQUENCY_12MHZ = 2,
	CALIBRATED_MODULATION_FREQUENCY_24MHZ = 3,
	CALIBRATED_MODULATION_FREQUENCY_5MHZ = 4,
	CALIBRATED_MODULATION_FREQUENCY_6MHZ = 5,
	CALIBRATED_MODULATION_FREQUENCY_2_5MHZ = 6,
	CALIBRATED_MODULATION_FREQUENCY_3MHZ = 7,
  CALIBRATED_MODULATION_FREQUENCY_1_25MHZ = 8,
	CALIBRATED_MODULATION_FREQUENCY_1_5MHZ = 9,
	CALIBRATED_MODULATION_FREQUENCY_0_625MHZ = 10,
	CALIBRATED_MODULATION_FREQUENCY_0_75MHZ = 11,
	CALIBRATED_MODULATION_FREQUENCY_0_375MHZ = 12
};

///Calibration header. This struct is used to store the data in the flash. It is now allowed to be bigger than flashWordSize (32Byte)
#pragma pack(push,1)
typedef struct
{                                   //Offset    description
  uint32_t crc;                     ///<0 CRC checksum over the calibration data
	int16_t reserved0;                ///<4 earlier: System offset (with lens mounted), now not used anymore
	int16_t lowPowerOffset;           ///<6 Offset when setting the illumination to low power (not available for all illuminations)
	uint8_t reserved1[23];            ///<8 Fill to 32 Bytes
	uint8_t magicToken;               ///<31 Write to a special value when header is written
}calibrationBaseHeaderV1_t;
#pragma pack(pop)

///Calibration header. This struct is used to store the data in the flash. It is now allowed to be bigger than flashWordSize (32Byte)
typedef struct __attribute__((packed))
{
  uint8_t version;                  ///<0 Version of the calibration data
	uint16_t width;                   ///<1 Sensor/ROI width
	uint16_t height;                  ///<3 Sensor/ROI height
	uint8_t numStepsCalibrated;       ///<5 Number of DLL steps calibrated
	uint8_t numStepsRange;            ///<6 Number of DLL steps to get the range
	uint16_t temperature;             ///<7 Calibration temperature
	uint16_t atanOffset;              ///<9 Global offset for atan calculation
	uint16_t dllRange;                ///<11 The real DLL range for step 0 .. last step
	uint8_t modulationFrequency;      ///<13 Defines the calibrated modulation frequency
	uint8_t dllStep;                  ///<14 DLL step to work. Could be other then zero for optimization
	uint16_t roiX;                    ///<15 ROI X of calibration, maybe only part of the sensor is calibrated, 0 for whole sensor
	uint16_t roiY;                    ///<17 ROI Y of calibration, maybe only part of the sensor is calibrated, 0 for whole sensor
	uint8_t binning;                  ///<19 Stores the type of binning used for the calibration
	uint8_t illumination;             ///<20 Stores the illumination
	uint16_t integrationTime;         ///<21 Stores the integration time during calibration
	uint8_t digitalBinning;           ///<23 Stores the digital binning
	uint16_t dcs02SumLowAmplitude;    ///<24 DCS0 + DCS2 at low amplitude in the calibration box
	uint16_t dcs02SumHighAmplitude;   ///<26 DCS0 + DCS2 at high amplitude in the calibration box
	uint16_t dcs13SumLowAmplitude;    ///<28 DCS1 + DCS3 at low amplitude in the calibration box
	uint16_t dcs13SumHighAmplitude;   ///<30 DCS1 + DCS3 at high amplitude in the calibration box
	int16_t brokenPixels[MAX_POSSIBLE_BROKEN_PIXELS];    ///<32 Index of the broken pixels, -1 if not broken
	uint8_t reserved[15];             ///<48 Fill to 32 Bytes
	uint8_t magicToken;               ///<61 Write to a special value when header is written
}calibrationHeaderV1_t;

///Header for the frequency shift offset
#pragma pack(push,1)
typedef struct
{
  int16_t base[16];
  int8_t shift[50][16];
}frequencyShiftOffset_t;
#pragma pack(pop)

///If this value is written to the corresponding fields, this means that the struct contains valid data
static const uint8_t MAGIC_TOKEN_VALUE = 0xDE;

///Address offset of the base header
static const uint32_t ADDRESS_OFFSET_BASE_HEADER = 0;

///Address offset of the calibration header
static const uint32_t ADDRESS_OFFSET_CALIBRATION_HEADER = ADDRESS_OFFSET_BASE_HEADER + sizeof(calibrationBaseHeaderV1_t);

///Address offset of the frequency shift offset
static const uint32_t ADDRESS_OFFSET_FREQUENCY_SHIFT_OFFSET = ADDRESS_OFFSET_CALIBRATION_HEADER + sizeof(calibrationHeaderV1_t);

///Address offset of the calibration data for old firmware
static const uint32_t ADDRESS_OFFSET_CALIBRATION_DATA_V1 = ADDRESS_OFFSET_CALIBRATION_HEADER + sizeof(calibrationHeaderV1_t);

///Address offset of the calibration data
static const uint32_t ADDRESS_OFFSET_CALIBRATION_DATA = ADDRESS_OFFSET_FREQUENCY_SHIFT_OFFSET + sizeof(frequencyShiftOffset_t);

///This is the fixed size used for one DRNU calibration. This does not take into account the calibration LUT data that may change from calibration to calibration
static const uint32_t SIZE_DRNU_CALIBRATION_FIX = sizeof(calibrationBaseHeaderV1_t) + sizeof (calibrationHeaderV1_t) + sizeof(frequencyShiftOffset_t);

#endif /* BASE_CALIBRATION_CALIBRATION_TYPES_H_ */

/** @} */
