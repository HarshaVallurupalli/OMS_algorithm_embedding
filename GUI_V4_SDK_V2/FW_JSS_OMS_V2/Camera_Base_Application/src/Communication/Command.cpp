/***
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup command
 */
#include "Communication/Command.h"
#include <string.h>
#include "CommunicationConstants.h"
#include "Util/Util.h"
#include "TOF_COS_Config.h"

/**
 * @brief Constructor (with data)
 *
 * @param data Pointer to the received data buffer
 * @param size Size of the received data buffer
 */
Command::Command(const uint8_t *data, const uint32_t size)
{
  memcpy(this->data, data, size);
  this->size = size;
  this->stream = false;
}

/**
 * @brief Constructor (no data)
 */
Command::Command()
{
}

/**
 * @brief Prepare a command
 *
 * This function prepares the data when a command was received. I extracts the command and
 * data from the received buffer.
 *
 * @return Command received
 */
uint8_t Command::prepareCommand()
{
	uint16_t command = Util::getValueUint16BigEndian(data, CommunicationConstants::Command::INDEX);
	uint8_t returnCommand = UNKNOWN;
	int32_t userDataIndex = -1;
	stream = false;

	switch (command)
	{
		case CommunicationConstants::CommandList::COMMAND_GET_CAM1_DATA:
			returnCommand =  GET_CAM1_DATA;
			break;
		case CommunicationConstants::CommandList::COMMAND_GET_CAM2_DATA:
			returnCommand =  GET_CAM2_DATA;
			break;
		case CommunicationConstants::CommandList::COMMAND_GET_CAM3_DATA:
			returnCommand =  GET_CAM3_DATA;
			break;
		case CommunicationConstants::CommandList::COMMAND_GET_CAM4_DATA:
			returnCommand =  GET_CAM4_DATA;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_INT_TIMES:
			returnCommand =  SET_INT_TIMES;
			break;
		case CommunicationConstants::CommandList::COMMAND_GET_DISTANCE_AMPLITUDE:
			userDataIndex = CommunicationConstants::Command::SIZE + 1;
			stream = data[CommunicationConstants::Command::SIZE];
			returnCommand =  GET_DISTANCE_AMPLITUDE;
			break;
		case CommunicationConstants::CommandList::COMMAND_GET_DISTANCE:
			userDataIndex = CommunicationConstants::Command::SIZE + 1;
			stream = data[CommunicationConstants::Command::SIZE];
			returnCommand =  GET_DISTANCE;
			break;
		case CommunicationConstants::CommandList::COMMAND_GET_DCS:
		  userDataIndex = CommunicationConstants::Command::SIZE + 1;
		  stream = data[CommunicationConstants::Command::SIZE];
		  returnCommand =  GET_DCS;
		  break;
		  //Algorithm Edit
		case CommunicationConstants::CommandList::COMMAND_SET_ALGORITHM:
		  returnCommand =  SET_ALGORITHM_SETTINGS;
		  break;
		case CommunicationConstants::CommandList::COMMAND_SET_OFFSET:
			returnCommand =  SET_OFFSET;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_MIN_AMPLITUDE:
			returnCommand =  SET_MIN_AMPLITUDE;
			break;
		case CommunicationConstants::CommandList::COMMAND_GET_GRAYSCALE:
			userDataIndex = CommunicationConstants::Command::SIZE + 1;
			stream = data[CommunicationConstants::Command::SIZE];
			returnCommand =  GET_GRAYSCALE;
			break;
		case CommunicationConstants::CommandList::COMMAND_STOP_STREAM:
			returnCommand =  STOP_STREAM;
	    break;
		case CommunicationConstants::CommandList::COMMAND_CALIBRATE:
			returnCommand =  CALIBRATE_DRNU;
			break;
		case CommunicationConstants::CommandList::COMMAND_DELETE_CALIBRATION:
			returnCommand =  DELETE_CALIBRATION;
			break;
		case CommunicationConstants::CommandList::COMMAND_CALIBRATE_PRODUCTION:
			returnCommand =  CALIBRATE_PRODUCTION;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_FILTER:
			returnCommand = SET_FILTER_SETTINGS;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_MODULATION:
      returnCommand = SET_MODULATION;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_BINNING:
			returnCommand = SET_BINNING;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_ROI:
			returnCommand = SET_ROI;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_HDR:
			returnCommand = SET_HDR;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_SHUTTER_MODE:
			returnCommand = SET_SHUTTER_MODE;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_ABS:
			returnCommand = SET_ABS;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_COMPENSATION:
			returnCommand = SET_COMPENSATION;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_DLL_STEP:
			returnCommand = SET_DLL_STEP;
			break;
		case CommunicationConstants::CommandList::COMMAND_SHUTTER:
			returnCommand = SET_DLL_STEP;
			break;
		case CommunicationConstants::CommandList::COMMAND_DEBUG:
			returnCommand = DEBUG;
			break;
		case CommunicationConstants::CommandList::COMMAND_CALIBRATE_GRAYSCALE:
			returnCommand =  CALIBRATE_GRAYSCALE;
			break;
		case CommunicationConstants::CommandList::COMMAND_CALIBRATE_AMBIENT_LIGHT:
			returnCommand =  CALIBRATE_AMBIENT_LIGHT;
			break;
		case CommunicationConstants::CommandList::COMMAND_READ_FIRMWARE_RELEASE:
			returnCommand =  GET_FIRMWARE_RELEASE;
			break;
		case CommunicationConstants::CommandList::COMMAND_READ_CHIP_INFORMATION:
			returnCommand =  GET_CHIP_INFORMATION;
			break;
		case CommunicationConstants::CommandList::COMMAND_SET_DATA_IP_ADDRESS:
		  returnCommand =  SET_DATA_IP_ADDRESS;
		  break;
		case CommunicationConstants::CommandList::COMMAND_SET_GRAYSCALE_ILLUMINATION:
		   returnCommand =  SET_GRAYSCALE_ILLUMINATION;
		  break;
		case CommunicationConstants::CommandList::COMMAND_SEND_FIRMWARE_UPDATE:
		  returnCommand =  SEND_FIRMWARE_UPDATE;
		  break;
		default:
			break;
	}

	if (userDataIndex >= 0)
	{
	  userData.setData(&data[userDataIndex], (size - userDataIndex));
	}
	else
	{
	  userData.setData(nullptr, 0);
	}

	return returnCommand;
}

/**
 * @brief Get the user data
 *
 * @return Pointer to the user data
 */
UserData * Command::getUserData() const
{
	return (UserData *)&userData;
}

/**
 * @brief Get the minimal amplitude value
 *
 * @return Minimal amplitude in lsb
 */
uint16_t Command::getMinAmplitude() const
{
	return Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Amplitude::INDEX_AMPLITUDE_0);
}

/**
 * @brief Get validate only flag
 *
 * If this flag is set only a validation shall be done.
 *
 * @return Validation only flag
 */
bool Command::getDrnuCalibrationValidateOnly() const
{
	return data[CommunicationConstants::CommandData::DrnuCalibration::INDEX_VALIDATE_ONLY];
}

/**
 * @brief Get offset only flag
 *
 * If this flag is set only an offset should be calibrated, e.g. for low modulation frequencies.
 *
 * @return Offset only flag
 */
bool Command::getDrnuCalibrationOffsetOnly() const
{
	return data[CommunicationConstants::CommandData::DrnuCalibration::INDEX_OFFSET_ONLY];
}

/**
 * @brief Get the Drnu calibration index
 *
 * This is the index which calibration should be done.
 *
 * @return Drnu calibration index
 */
uint8_t Command::getDrnuCalibrationIndex() const
{
	return data[CommunicationConstants::CommandData::DrnuCalibration::INDEX_CALIBRATION_INDEX];
}

/**
 * @brief Get the stream flag
 *
 * This flag indicates if data shoud be streamed. Only valid for measurement commands.
 *
 * @return offset in mm
 */
bool Command::isStream() const
{
  return stream;
}

/**
 * @brief Get the offset
 *
 * @return offset in mm
 */
int16_t Command::getOffset() const
{
return Util::getValueInt16BigEndian(data, CommunicationConstants::CommandData::Offset::INDEX_OFFSET);

}

/**
 * @brief Get the integration time for 3D
 *
 * @param index Index of the integration time
 * @return integration time in us
 */
uint16_t Command::getIntegrationTime3d(const uint8_t index) const
{
return Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::IntegrationTime::INDEX_INTEGRATION_TIME_3D + (index * sizeof(uint16_t)));

}

/**
 * @brief Get the integration time for grayscale
 *
 * @return integration time in us
 */
uint16_t Command::getIntegrationTimeGrayscale() const
{
	uint16_t integrationTime = (data[CommunicationConstants::CommandData::IntegrationTime::INDEX_INTEGRATION_TIME_GRAYACALE] << 8) | data[CommunicationConstants::CommandData::IntegrationTime::INDEX_INTEGRATION_TIME_GRAYACALE+1];
	return integrationTime;
}

/**
 * @brief Get the temporal filter settings
 *
 * @return temporal filter settings
 */
TemporalFilterSettings Command::getTemporalFilterSettings() const
{
  uint16_t threshold = Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Filter::INDEX_TEMPORAL_FILTER_THRESHOLD);
  uint16_t factor = Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Filter::INDEX_TEMPORAL_FILTER_FACTOR);
	TemporalFilterSettings settings(threshold, factor);

	return settings;
}

//Algorithm Edit
MovementDetectionAlgorithmSettings Command::getMovementDetectionAlgorithmSettings() const
{
  uint16_t windowSize = Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Algorithms::INDEX_MOVEMENT_DETECTION_WINDOW_SIZE);
  uint16_t imageType = Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Algorithms::INDEX_MOVEMENT_DETECTION_IMAGE_TYPE);
  MovementDetectionAlgorithmSettings settings(windowSize,imageType);
  return settings;
}
bool Command::getifSkeletonDetectionAlgorithmEnabled() const
{
  return Util::getifEnabled(data, CommunicationConstants::CommandData::Algorithms::INDEX_SKELETON_DETECTION_ENABLED);
}
/**
 * @brief Get average filter enabled/disabled
 *setAverageFilterEnabled()
 * @return Average filter enabled/disabled
 */
bool Command::getifAverageFilterEnabled() const
{
  return Util::getifEnabled(data, CommunicationConstants::CommandData::Filter::INDEX_AVERAGE_FILTER_ENABLED);
}



/**
 * @brief Get median filter enabled/disabled
 *
 * @return Median filter enabled/disabled
 */
bool Command::getifMedianFilterEnabled() const
{
	return Util::getifEnabled(data, CommunicationConstants::CommandData::Filter::INDEX_MEDIAN_FILTER_ENABLED);
}

/**
 * @brief Get the threshold of the edge filter
 *
 * @return Edge filter threshold
 */
uint16_t Command::getEdgeFilterThreshold() const
{
  return Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Filter::INDEX_EDGE_DETECTION_THRESHOLD);
}

/**
 * @brief Get the limit of the interference detection
 *
 * @return Limit for the interference detection
 */
uint16_t Command::getInterferenceDetectionLimit() const
{
	return Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Filter::INDEX_INTERFERENCE_DETECTION_LIMIT);
}

/**
 * @brief Get the use last value flag
 *
 * @return Use last value flag
 */
bool Command::getifInterferenceDetectionUseLastValue() const
{
	return Util::getifEnabled(data, CommunicationConstants::CommandData::Filter::INDEX_INTERFERENCE_DETECTION_USE_LAST_VALUE);
}

/**
 * @brief Get lower threshold for temporal edge filter
 *
 * @return Lower threshold for temporal edge filter
 */
uint16_t Command::getTemporalEdgeFilterThresholdLow() const
{
	return Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Filter::INDEX_TEMPORAL_EDGE_FILTER_THRESHOLD_LOW);
}

/**
 * @brief Get higher threshold for temporal edge filter
 *
 * @return Higher threshold for temporal edge filter
 */
uint16_t Command::getTemporalEdgeFilterThresholdHigh() const
{
	return Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Filter::INDEX_TEMPORAL_EDGE_FILTER_THRESHOLD_HIGH);
}

/**
 * @brief Get the modulation frequency
 *
 * @return modulation frequency
 */
Modulation::ModulationFrequency Command::getModulationFrequency() const
{
  switch(data[CommunicationConstants::CommandData::Modulation::INDEX_FREQUENCY])
  {
    case CommunicationConstants::CommandData::Modulation::VALUE_12MHZ:
    	return Modulation::ModulationFrequency::MODULATION_12MHZ;
    	break;
    case CommunicationConstants::CommandData::Modulation::VALUE_24MHZ:
      return Modulation::ModulationFrequency::MODULATION_24MHZ;
      break;
#if (TOF_COS_USE_LOW_MODULATION_FREQUENCIES==1)
    case CommunicationConstants::CommandData::Modulation::VALUE_6MHZ:
      return Modulation::ModulationFrequency::MODULATION_6MHZ;
      break;
    case CommunicationConstants::CommandData::Modulation::VALUE_3MHZ:
      return Modulation::ModulationFrequency::MODULATION_3MHZ;
      break;
    case CommunicationConstants::CommandData::Modulation::VALUE_1_5MHZ:
    	return Modulation::ModulationFrequency::MODULATION_1_5MHZ;
    	break;
    case CommunicationConstants::CommandData::Modulation::VALUE_0_75MHZ:
    	return Modulation::ModulationFrequency::MODULATION_0_75MHZ;
    	break;
#endif
    default:
      return Modulation::ModulationFrequency::MODULATION_12MHZ;
    	break;
  }

  return Modulation::ModulationFrequency::MODULATION_12MHZ;
}

/**
 * @brief Get auto modulation channel enabled
 *
 * Auto modulation channel means that the modulation channel is automatically changed in case
 * of interference.
 *
 * @retval true Auto modulation channel enabled
 * @retval false Auto modulation channel disabled
 * @return Auto modulation channel enabled or disabled
 */
bool Command::getifAutoModulationChannelEnabled() const
{
	return Util::getifEnabled(data, CommunicationConstants::CommandData::Modulation::INDEX_CHANNEL_HOPPING);
}

/**
 * @brief Get the modulation channel
 *
 * @return Modulation channel
 */
uint8_t Command::getModulationChannel() const
{
	return data[CommunicationConstants::CommandData::Modulation::INDEX_CHANNEL];
}

/**
 * @brief Get binning
 *
 * @return Binning
 */
Binning Command::getBinning() const
{
  Binning binning;

  switch(data[CommunicationConstants::CommandData::Binning::INDEX])
  {
    case CommunicationConstants::CommandData::Binning::VALUE_NO_BINNING:
  	  binning = Binning::Binning_e::BINNING_NONE;
  	  break;
    case CommunicationConstants::CommandData::Binning::VALUE_BINNING_VERTICAL:
      binning = Binning::Binning_e::BINNING_VERTICAL;
    	break;
    case CommunicationConstants::CommandData::Binning::VALUE_BINNING_HORIZONTAL:
    	binning = Binning::Binning_e::BINNING_HORIZONTAL;
    	break;
    case CommunicationConstants::CommandData::Binning::VALUE_BINNING_BOTH:
    	binning = Binning::Binning_e::BINNING_VERTICAL_HORIZONTAL;
    	break;
    default:
  	  break;
  }

  return binning;
}

/**
 * @brief Get HDR
 *
 * @return HDR
 */
Hdr Command::getHdr() const
{
  Hdr hdr;

  //So far just set to spatial HDR or no HDR
  if(data[CommunicationConstants::CommandData::Hdr::INDEX])
  {
  	hdr = Hdr::HdrMode_e::HDR_MODE_SPATIAL;
  }

  return hdr;
}

/**
 * @brief Get ROI
 *
 * Region Of Interest
 *
 * @return ROI
 */
Roi Command::getRoi() const
{
  uint16_t x0 = Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Roi::INDEX_X0);
  uint16_t y0 = Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Roi::INDEX_Y0);
  uint16_t x1 = Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Roi::INDEX_X1);
  uint16_t y1 = Util::getValueUint16BigEndian(data, CommunicationConstants::CommandData::Roi::INDEX_Y1);

  uint16_t width = x1 - x0 + 1;
  uint16_t height = y1 - y0 + 1;

  Roi roi(x0, y0, width, height);

  return roi;
}

/**
 * @brief Get external shutter enabled
 *
 * @retval true External shutter enabled
 * @retval false External shutter disabled
 * @return External shutter enabled or disabled
 */
bool Command::getifExternalShutterEnabled() const
{
	return Util::getifEnabled(data, CommunicationConstants::CommandData::ShutterMode::INDEX);
}

/**
 * @brief Get ABS enabled
 *
 * @retval true ABS enabled
 * @retval false ABS disabled
 * @return ABS enabled or disabled
 */
bool Command::getifAbsEnabled() const
{
	return Util::getifEnabled(data, CommunicationConstants::CommandData::Abs::INDEX);
}

/**
 * @brief Get DRNU Compensation enabled
 *
 * @retval true DRNU Compensation enabled
 * @retval false DRNU Compensation disabled
 * @return DRNU Compensation enabled or disabled
 */
bool Command::getifDrnuCompensationEnabed() const
{
	return Util::getifEnabled(data, CommunicationConstants::CommandData::Compensation::INDEX_DRNU_COMPENSATION_ENABLED);
}

/**
 * @brief Get Temperature Compensation enabled
 *
 * @retval true Temperature Compensation enabled
 * @retval false Temperature Compensation disabled
 * @return Temperature Compensation enabled or disabled
 */
bool Command::getifTemperatureCompensationEnabled() const
{
	return Util::getifEnabled(data, CommunicationConstants::CommandData::Compensation::INDEX_TEMPERATURE_COMPENSATION_ENABLED);
}

/**
 * @brief Get Ambient Light Compensation enabled
 *
 * @retval true Ambient Light Compensation enabled
 * @retval false Ambient Light Compensation disabled
 * @return Ambient Light Compensation enabled or disabled
 */
bool Command::getifAmbientLightCompensationEnabled() const
{
	return Util::getifEnabled(data, CommunicationConstants::CommandData::Compensation::INDEX_AMBIENT_LIGHT_COMPENSATION_ENABLED);
}

/**
 * @brief Get Grayscale Compensation enabled
 *
 * @retval true Grayscale Compensation enabled
 * @retval false Grayscale Compensation disabled
 * @return Grayscale Compensation enabled or disabled
 */
bool Command::getifGrayscaleCompensationEnabled() const
{
	return Util::getifEnabled(data, CommunicationConstants::CommandData::Compensation::INDEX_GRAYSCALE_COMPENSATION_ENABLED);
}

/**
 * @brief Get Grayscale illuminated
 *
 * @retval true Grayscale image is illuminated
 * @retval false Grayscale image is not illuminated
 * @return Grayscale image illuminated or not
 */
bool Command::getifGrayscaleIlluminated() const
{
  return Util::getifEnabled(data, CommunicationConstants::CommandData::GrayscaleIllumination::INDEX);
}

/**
 * @brief Get DLL step
 *
 * @return DLL step
 */
uint8_t Command::getDllStep() const
{
	return data[CommunicationConstants::CommandData::DllStep::INDEX];
}

/**
 * @brief Get Pointer to the data
 *
 * Mainly used for debug commands.
 *
 * @return Pointer to the received data
 */
uint8_t *Command::getData()
{
  return &data[CommunicationConstants::Command::INDEX_DATA];
}

/**
 * @brief Get Size of the data
 *
 * Data without command
 *
 * @return Size of the data
 */
uint32_t Command::getDataSize() const
{
  if (size >= CommunicationConstants::Command::SIZE)
  {
    return size - CommunicationConstants::Command::SIZE;
  }

  return 0;
}

/** @} */
