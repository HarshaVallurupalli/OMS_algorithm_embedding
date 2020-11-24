/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup command Command
 * @ingroup communication
 *
 * @brief Helper class to get the data from the commands
 *
 * @{
 */
#ifndef COMMAND_H_
#define COMMAND_H_

#include "TOF_COS_IF.h"
#include <Communication/UserData.h>
#include "GlobalConstants.h"
#include <stdint.h>
#include "Modulation/Modulation.h"
#include "Binning/Binning.h"
#include "Hdr/Hdr.h"
#include "Roi/Roi.h"

//! Command helper class
/*!
 * Helper class to extract the data from the commands
 */
class Command
{
	public:
		Command(const uint8_t *data, const uint32_t size);
		Command();

		enum
		{
			SET_INT_TIMES,
			GET_DISTANCE,
	    GET_DISTANCE_AMPLITUDE,
	    GET_DCS,
	    SET_OFFSET,
	    SET_MIN_AMPLITUDE,
			SET_FILTER_SETTINGS,
			SET_MODULATION,
			SET_BINNING,
			SET_HDR,
			SET_ROI,
			SET_SHUTTER_MODE,
			SET_ABS,
			SET_COMPENSATION,
	    GET_GRAYSCALE,
	    STOP_STREAM,
			CALIBRATE_DRNU,
			CALIBRATE_GRAYSCALE,
			CALIBRATE_AMBIENT_LIGHT,
			CALIBRATE_PRODUCTION,
			DELETE_CALIBRATION,
			SHUTTER,
			SET_DLL_STEP,
			GET_CHIP_INFORMATION,
			GET_FIRMWARE_RELEASE,
			SET_DATA_IP_ADDRESS,
			SET_GRAYSCALE_ILLUMINATION,
			DEBUG,
			SEND_FIRMWARE_UPDATE,
			UNKNOWN,
			GET_CAM1_DATA,
			GET_CAM2_DATA,
			GET_CAM3_DATA,
			GET_CAM4_DATA,
			//Algorithm Edit
			SET_ALGORITHM_SETTINGS
		};

		uint8_t prepareCommand();
		uint16_t getMinAmplitude() const;
		int16_t getOffset() const;
		uint16_t getIntegrationTime3d(const uint8_t index) const;
		uint16_t getIntegrationTimeGrayscale() const;
		bool isStream() const;
		UserData *getUserData() const;
		TemporalFilterSettings getTemporalFilterSettings() const;
		bool getifAverageFilterEnabled() const;
		bool getifMedianFilterEnabled() const;
		uint16_t getEdgeFilterThreshold() const;
	    //Algorithm Edit
		uint16_t getMovementDetectionWindowSize() const;
		uint16_t getInterferenceDetectionLimit() const;
		bool getifInterferenceDetectionUseLastValue() const;
		uint16_t getTemporalEdgeFilterThresholdLow() const;
		uint16_t getTemporalEdgeFilterThresholdHigh() const;
		Modulation::ModulationFrequency getModulationFrequency() const;
		bool getifAutoModulationChannelEnabled() const;
		uint8_t getModulationChannel() const;
		bool getDrnuCalibrationOffsetOnly() const;
		uint8_t getDrnuCalibrationIndex() const;
		bool getDrnuCalibrationValidateOnly() const;
		Binning getBinning() const;
    Hdr getHdr() const;
    Roi getRoi() const;
    bool getifExternalShutterEnabled() const;
    bool getifAbsEnabled() const;
    bool getifDrnuCompensationEnabed() const;
    bool getifTemperatureCompensationEnabled() const;
    bool getifAmbientLightCompensationEnabled() const;
    bool getifGrayscaleCompensationEnabled() const;
    bool getifGrayscaleIlluminated() const;
    uint8_t getDllStep() const;
    uint8_t *getData();
    uint32_t getDataSize() const;





	private:
		uint32_t size;                                        ///<Size of the job
		uint8_t data[MAX_COMMUNICATION_PAYLOAD_SIZE];            ///<Data of the job
		bool stream;                               ///<Indicates if the data should stream
		UserData userData;                     ///<User data received with the command
};

#endif /* COMMAND_H_ */

/** @} */
