#include <Calibration/DrnuCalibrationDataHelper.h>
#include <Calibration/DrnuCalibrationTypes.h>
#include <TOF_COS_Constants.h>
#include "CRC/CRC.h"
#include "Modulation/Modulation.h"

///Limit in case of empty flash (all bits set)
static const uint8_t MAX_POSSIBLE_DLL_STEPS = 50;

//Limit in case of empty flash (all bits set)
static const uint32_t MAX_POSSIBLE_PIXELS = 100000;

/**
 * @brief Constructor
 *
 * @param Address Start address of the calibration data
 */
DrnuCalibrationDataHelper::DrnuCalibrationDataHelper(const uint32_t address)
{
  this->address = address;
}

/**
 * @brief Get header address
 *
 * Get the address of the calibration header
 *
 * @return Calibration header address
 */
uint32_t DrnuCalibrationDataHelper::getHeaderAddress()
{
  return address + ADDRESS_OFFSET_CALIBRATION_HEADER;
}

/**
 * @brief Get base header address
 *
 * Get the address of the calibration base header
 *
 * @return Calibration base header address
 */
uint32_t DrnuCalibrationDataHelper::getBaseHeaderAddress()
{
	return address + ADDRESS_OFFSET_BASE_HEADER;
}

/**
 * @brief Read the address of the error lookup table
 *
 * @return Pointer to the error lookup table
 */
int8_t *DrnuCalibrationDataHelper::getCalibrationDataAddress()
{
	int8_t *pCalibration = (int8_t *) (address + (4 * FLASH_WORD_SIZE));

	return pCalibration;
}

uint8_t DrnuCalibrationDataHelper::getNumStepsCalibrated() const
{
	calibrationHeaderV1_t *header = reinterpret_cast<calibrationHeaderV1_t *> (address + ADDRESS_OFFSET_CALIBRATION_HEADER);

	return header->numStepsCalibrated;
}

/**
 * @brief Read the range
 *
 * @return range
 */
uint16_t DrnuCalibrationDataHelper::getRange() const
{
	calibrationHeaderV1_t *header = reinterpret_cast<calibrationHeaderV1_t *> (address + ADDRESS_OFFSET_CALIBRATION_HEADER);

	return header->dllRange;
}

/**
 * @brief Read the atan offset
 *
 * @return atan offset
 */
uint16_t DrnuCalibrationDataHelper::getAtanOffset() const
{
	calibrationHeaderV1_t *header = reinterpret_cast<calibrationHeaderV1_t *> (address + ADDRESS_OFFSET_CALIBRATION_HEADER);

	return header->atanOffset;
}

/**
 * @brief Get the calibration size
 *
 * Just the calibration LUT size.
 *
 * Take care: for empty flash this is huge (all 0xFF)
 *
 * @return Calibration LUT size
 */
uint32_t DrnuCalibrationDataHelper::getCalibrationSize()
{
	calibrationHeaderV1_t *header = reinterpret_cast<calibrationHeaderV1_t *> (address + ADDRESS_OFFSET_CALIBRATION_HEADER);

	uint32_t calibrationSize = header->height * header->width * header->numStepsCalibrated;

	return calibrationSize;
}

/**
 * @brief Get the total calibration size for this calibration
 *
 * This includes:
 * - Header
 * - System offsets
 * - Calibration data
 *
 * @return Total calibration size
 */
uint32_t DrnuCalibrationDataHelper::getTotalCalibrationSize()
{
  uint32_t totalSize = sizeof(calibrationBaseHeaderV1_t) + sizeof(calibrationHeaderV1_t) + getCalibrationSize();

  return totalSize;
}

/**
 * @brief Check, if the Header is valid
 *
 * This function only checks, if the header is valid. Therefore a special token must be set in the header.
 *
 * @retval false Header data is not valid
 * @retval true Header data is valid
 * @return true/false header valid
 */
bool DrnuCalibrationDataHelper::checkHeaderValid()
{
	calibrationHeaderV1_t *calibrationHeader = reinterpret_cast<calibrationHeaderV1_t *> (address + ADDRESS_OFFSET_CALIBRATION_HEADER);

	if (calibrationHeader->magicToken != MAGIC_TOKEN_VALUE)
	{
		return false;
	}/*---------------- Cancel here ------------------------------------------->*/


	return true;
}


/**
 * @brief Check, if the Base Header is valid
 *
 * This function only checks, if the base header is valid. Therefore a special token must be set in the header.
 *
 * @retval false Header data is not valid
 * @retval true Header data is valid
 * @return true/false header valid
 */
bool DrnuCalibrationDataHelper::checkBaseHeaderValid()
{
	calibrationBaseHeaderV1_t *calibrationBaseHeader = reinterpret_cast<calibrationBaseHeaderV1_t *> (address + ADDRESS_OFFSET_BASE_HEADER);

	if (calibrationBaseHeader->magicToken != MAGIC_TOKEN_VALUE)
	{
		return false;
	}/*---------------- Cancel here ------------------------------------------->*/

	return true;
}

/**
 * @brief Read the calibration temperature
 *
 * @return Calibration temperature
 */
uint16_t DrnuCalibrationDataHelper::getCalibrationTemperature() const
{
	calibrationHeaderV1_t *header = reinterpret_cast<calibrationHeaderV1_t *> (address + ADDRESS_OFFSET_CALIBRATION_HEADER);

	return header->temperature;
}

/**
 * @brief Read the modulation frequency
 *
 * @return Value from Modulation::ModulationFrequency
 */
Modulation DrnuCalibrationDataHelper::getModulation() const
{
	Modulation modulation;

	calibrationHeaderV1_t *header = reinterpret_cast<calibrationHeaderV1_t *> (address + ADDRESS_OFFSET_CALIBRATION_HEADER);

	switch(header->modulationFrequency)
	{
	  case CALIBRATED_MODULATION_FREQUENCY_10MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_10MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_20MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_20MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_12MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_12MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_24MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_24MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_5MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_5MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_6MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_6MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_2_5MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_2_5MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_3MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_3MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_1_25MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_1_25MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_1_5MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_1_5MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_0_625MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_0_625MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_0_75MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_0_75MHZ;
	  	break;
	  case CALIBRATED_MODULATION_FREQUENCY_0_375MHZ:
	  	modulation = Modulation::ModulationFrequency::MODULATION_0_375MHZ;
	  	break;
	  default:
	  	modulation = Modulation::ModulationFrequency::MODULATION_10MHZ;
	  	break;
	}

	return modulation;
}

/**
 * @brief Store the header for the correction data
 *
 * This function has to be called when the calibration has been run without errors.
 * It stores the header data (version, crc) of the calibration data, so the data
 * can be read as valid.
 *
 * @return CALIBRATION_RESULT_ERROR Failed
 * @return CALIBRATION_RESULT_OK Success
 * @return Result of the procedure
 */
calibrationHeaderV1_t DrnuCalibrationDataHelper::createHeader(const DrnuCalibrationInfoData &calibrationInfo)
{
	//Put here a header on the stack and fill it with data. It is not possible to directly write to the header above
	calibrationHeaderV1_t header;
	header.version = DRNU_CALIBRATION_DATA_VERSION;
	header.width = calibrationInfo.roi.getWidth();
	header.height = calibrationInfo.roi.getHeight();;
	header.numStepsCalibrated = calibrationInfo.dllSteps;
	header.temperature = calibrationInfo.temperature;
	header.dllRange = calibrationInfo.dllRange;
	header.atanOffset = calibrationInfo.offset;

	switch(calibrationInfo.modulation.getModulationFrequency())
	{
	  case Modulation::MODULATION_10MHZ:
		  header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_10MHZ;
			break;
		case Modulation::MODULATION_20MHZ:
		  header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_20MHZ;
			break;
		case Modulation::MODULATION_12MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_12MHZ;
			break;
		case Modulation::MODULATION_24MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_24MHZ;
			break;
		case Modulation::MODULATION_5MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_5MHZ;
			break;
		case Modulation::MODULATION_6MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_6MHZ;
			break;
		case Modulation::MODULATION_2_5MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_2_5MHZ;
			break;
		case Modulation::MODULATION_3MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_3MHZ;
			break;
		case Modulation::MODULATION_1_25MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_1_25MHZ;
			break;
		case Modulation::MODULATION_1_5MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_1_5MHZ;
			break;
		case Modulation::MODULATION_0_625MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_0_625MHZ;
			break;
		case Modulation::MODULATION_0_75MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_0_75MHZ;
			break;
		case Modulation::MODULATION_0_375MHZ:
			header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_0_375MHZ;
			break;
		default:
		  header.modulationFrequency = CALIBRATED_MODULATION_FREQUENCY_10MHZ;
			break;
	}

	//Indicate that the header is valid
	header.magicToken = MAGIC_TOKEN_VALUE;

	return header;
}

calibrationBaseHeaderV1_t DrnuCalibrationDataHelper::createBaseHeader(const int16_t lowPowerOffset)
{
	calibrationBaseHeaderV1_t *calibrationHeader = reinterpret_cast<calibrationBaseHeaderV1_t *> (address + ADDRESS_OFFSET_CALIBRATION_HEADER);
	calibrationBaseHeaderV1_t header;

	header.lowPowerOffset = lowPowerOffset;
	header.magicToken = MAGIC_TOKEN_VALUE;

	uint32_t crc = CRC::startCrc32();

	//First accumulate the base header (here in the RAM)
	uint8_t *p = reinterpret_cast<uint8_t *>(&header);
	crc = CRC::accumulateCrc32(&p[sizeof(header.crc)], (sizeof(calibrationBaseHeaderV1_t) - sizeof(header.crc)), crc);

	//Then accumulate all the rest after the base header. This is already in the flash
	crc = CRC::accumulateCrc32(reinterpret_cast<uint8_t *>(calibrationHeader), (getTotalCalibrationSize() - sizeof(calibrationBaseHeaderV1_t)), crc);

	crc = CRC::finishCrc32(crc);

	header.crc = crc;

	return header;
}




