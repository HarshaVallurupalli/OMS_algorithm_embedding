/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup config Config
 * @ingroup tof_cos
 * @brief Configuration class
 *
 * @{
 */
#ifndef CONFIG_H_
#define CONFIG_H_

#include "ChipControl/ChipControl.h"
#include <stdint.h>
#include "RoiSettings.h"
#include "ModulationSettings.h"
#include "BinningSettings.h"
#include "HdrSettings.h"
#include "GrayscaleIlluminationSettings.h"
#include "Calibration/MemoryInfo.h"


typedef enum
{
	CONFIG_TOF,
	CONFIG_GRAYSCALE,
	CONFIG_DCS,
	CONFIG_DUALMGX,
	CONFIG_NONE
}typeConfigMode;

//! Handles all the configuration needed.
/*!
 * This class is responsible for the configuration. For a concrete TOF imager a derived class must be created.
 */
class Config
{
	public:
		explicit Config(ChipControl &chipControl);

		TypeInternalReturnValue init();

		void setIntegrationTime3d(const uint16_t integrationTime, const uint8_t index);
		uint16_t getIntegrationTime3d(const uint8_t index) const;

		void setIntegrationTimeGrayscale(const uint16_t integrationTime);
		uint16_t getIntegrationTimeGrayscale() const;

		void setMinAmplitude(const uint16_t amplitude);
		uint16_t getMinAmplitude() const;

		void setOffset(const int16_t offset);
		int16_t getOffset() const;

		void setModulation(const Modulation modulation, const uint8_t index);
		Modulation getModulation(const uint8_t index) const;
		Modulation getModulation() const;
		void setModulationChannel(const bool autoChannelEnabled, const uint8_t channel);

		void setBinning(const Binning binning, const uint8_t index);
		Binning getBinning() const;

		void setRoi(const Roi roi);
		Roi getRoi();

		void setHdr(const Hdr hdr);
		Hdr getHdr();

		void setDllStep(const uint8_t step);
		uint8_t getDllStep() const;

		void setGrayscaleIlluminated(const bool enabled);
		bool getGrayscaleIlluminated() const;

		void setDrnuCompensationMemory(const uint32_t address, const uint32_t size, const uint8_t index);
		MemoryInfo getDrnuCompensationMemory(const uint8_t index) const;

		void setExternalShutter(const bool enabled);
		bool getExternalShutter() const;

		void setCompenationEnabled(const bool drnuCompensationEnabled, const bool temperatureCompensationEnabled, const bool ambientLightCompensationEnabled, const bool grayscaleCompensationEnabled);
		void setAmbientLightCompensationEnabled(const bool enabled);
		bool getDrnuCompensationEnabled() const;
		bool getTemperatureCompenastionEnabled() const;
		bool getAmbientLightCompensationEnabled() const;
		bool getGrayscaleCompensationEnabled() const;

		uint32_t getNumPixel() const;
		uint16_t getWidth() const;
		uint16_t getHeight() const;

		void loadBaseChipSettings();
		void load3dSettings(const uint8_t index);
		void loadGrayscaleSettings();
		void loadSettingsGrayscaleForTemperatureOnly();
		void loadIntegrationTimeDualMGX(const uint8_t index);
		void loadFpgaWithoutDrnuCompensation();

		bool is3d() const;
		bool isGrayscale() const;
		bool isDualMGX() const;
		int8_t getIndexCompensation() const;
		bool newAcquisitionRequired() const;

		static const uint8_t NUM_INTEGRATION_TIME = 3;
		static const uint8_t DEFAULT_INTEGRATION_TIME_3D = 30;
		static const uint8_t DEFAULT_INTEGRATION_TIME_GRAYSCALE = 10;

	protected:
		static const uint8_t MASK_DRNU_COMPENSATION = 0x01;
		static const uint8_t MASK_TEMPERATURE_COMPENSATION = 0x02;
		static const uint8_t MASK_AMBIENT_LIGHT_COMPENSATION = 0x04;
		static const uint8_t MASK_GRAYSCALE_COMPENSATION = 0x08;

		uint16_t integrationTime3D[NUM_INTEGRATION_TIME];            ///<Integration times for 3D in us
		uint16_t integrationTimeGrayscale;                           ///<Integration time for grayscale in us
		uint16_t minAmplitude;                                       ///<Minimal amplitude ni lsb
		int16_t offset;                                              ///<Offset in mm
		MemoryInfo drnuCompensationMemory[TOF_COS_NUM_CALIBRATION];  ///<Stores the addresses/sizes of the DRNU compensations
		typeConfigMode actualMode;                                   ///<Actual mode of the sensor
		bool Algorithm_enable;
		BinningSettings binningSettings;                             ///<Stores the binning settings
		RoiSettings roiSettings;                                     ///<Stores the ROI (region of interest) settings
		HdrSettings hdrSettings;                                     ///<HDR settings
		ModulationSettings modulationSettings;                       ///<Stores the modulation settings
		uint8_t compensationFlags;                                   ///<Flags for compensation settings
		ChipControl &chipControl;                                    ///<Chip Control class to control the chip
		bool newAcquisitionIsRequired;                               ///<Indicates that a new acquisition is required and the image data in the memory must be discarded
		bool externalShutter;                                        ///<If set, an external shutter for the imager is used
		uint8_t dllStep;                                             ///<Stores the current DLL step
		GrayscaleIlluminationSettings grayscaleIlluminationSettings; ///<True if grayscale image is illuminated

	private:
		void load3dMode();
		void setToGrayscale();
		void setToDualMGX();
		void loadBinning();
		void loadRoi();
		void loadHdr();
		void loadModulation();
		void loadGrayscaleIllumination();
};

#endif /* CONFIG_H_ */

/** @} */
