/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup tof_cos_base Base implementation
 * @ingroup tof_cos
 * @brief Implements the base functionality
 *
 * @{
 */
#ifndef TOF_COS_BASE_H_
#define TOF_COS_BASE_H_

#include <Calibration/DrnuCalibration.h>
#include <stdint.h>
#include <stddef.h>
#include <TOF_COS_IF.h>
#include <Jobs/JobDistance.h>
#include <Jobs/JobDistAmpl.h>
#include <Jobs/JobGrayscale.h>
#include <Jobs/JobDcs.h>
#include "Config/Config.h"
#include "RamManager/RamManager.h"
#include "DataAcquisition/DataAcquisition.h"
#include "Calculation/Calculation.h"
#include "ChipControl/ChipControl.h"
#include "SequencerProgrammer/SequencerProgrammer.h"
#include "Calibration/Calibration_Calculation.h"
#include "InterferenceDetection/InterferenceDetectionSettings.h"
#include "Hdr/Hdr.h"
#include "TypeInternalReturnValue.h"

//! TOF_COS functionality
/*!
 * Implements the whole functionality of the TOF_COS.
 */
class TOF_COS_Base: public TOF_COS_IF
{
	public:
		/*******************************************
	   Init
		********************************************/
		TOF_COS_Base();
		uint8_t init(const uint32_t preBytes, const uint32_t postBytes);
		void updateCalibrationData();

		/*******************************************
		 Acquisition
		********************************************/
		void startNextAcquisition();
		void selectData(const TOF_COS_Data_e data);
		TOF_COS_Data_e getSelectedDataType() const;
		uint8_t getData(uint8_t **data, AcquisitionMetaData &acquisitionMetaData);
		bool acquisitionBusy();

		/*******************************************
		 Setup
		********************************************/
		void setOffset(const int32_t offset);

		void setIntegrationTime3d(const uint16_t integrationTime, const uint8_t index);
		uint16_t getIntegrationTime3d(const uint8_t index);

		void setIntegrationTimeGrayscale(const uint32_t integrationTime);

		void setMinimalAmplitude(const uint32_t minAmplitude);

		void setRoi(const Roi roi);

		void setModulactionFrequency(Modulation::ModulationFrequency modulationFrequency);
		void setModulationChannel(const bool autoChannelEnabled, const uint8_t channel);

		void setBinning(const Binning binning);

		void setHdr(const Hdr hdr);

		void setCompensationEnabled(const bool drnuCompensationEnabled, const bool temperatureCompensationEnabled, const bool ambientLightCompensationEnabled, const bool grayscaleCompensationEnabled);

		void setAbs(const bool enabled);

		void setExternalShutter(const bool enabled);
		bool getExternalShutter() const;

		void setGrayscaleIlluminated(const bool enabled);
		bool getGrayscaleIlluminated() const;

       /*******************************************
        Filter
       ********************************************/
		void setInterferenceDetectionSettings(const InterferenceDetectionSettings interferenceDetectionSettings);

		void setTemporalFilterSettings(const TemporalFilterSettings filterSettings);

		void setAverageFilterEnabled(const bool enabled);

		void setMedianFilterEnabled(const bool enabled);

		void setEdgeFilterSettings(const uint32_t threshold);

		void setTemporalEdgeFilterSettings(const uint32_t thresholdLow, const uint32_t thresholdHigh);

	    /*******************************************
	     Algorithms
	    ********************************************/
		void setMovementDetectionAlgorithmSettings(const MovementDetectionAlgorithmSettings algorithmSettings);
		void setSkeletonDetectionAlgorithmEnabled(const bool enabled);


		/*******************************************
		Info
		********************************************/
	  uint16_t getChipId() const;
	  uint16_t getWaferId() const;

		/*******************************************
		 Calibration
		********************************************/
	  uint8_t calibrateDrnu(bool verifyOnly, const bool offsetOnly, const uint8_t index);
	  uint8_t calibrateProduction();
	  uint8_t calibrateGrayscale();
	  uint8_t calibrateAmbientLight();
	  uint8_t writeCalibrationToMemory();

	  /*******************************************
	  Debug
	  ********************************************/
	  void setDllStep(const uint8_t step);
	  void shutter();

	protected:
	  virtual void initCalibrationSettings();
	  void selectJob(PointCloudJob *job);
	  virtual void selectGrayscale();
	  virtual void selectDistance();
	  virtual void selectDistanceAmplitude();
	  virtual void selectDcs();
	  void updateDataType();
	  uint8_t calibrateGrayscale(const uint32_t address, const uint32_t size);
	  uint8_t calibrateAmbientLight(const uint32_t address, const uint32_t size);

	  JobDistAmpl jobDistanceAmplitude;
	  JobGrayscale jobGrayscale;
	  JobDistance jobDistance;
	  JobDcs jobDcs;
	  PointCloudJob *actJob;
	  TOF_COS_Context context;
	  TOF_COS_Data_e actDataType;
	  SequencerProgrammer *sequencerProgrammer;
	  TypeInternalReturnValue currentStatus;

	private:
	  uint8_t init();
	  virtual uint8_t calibrateProductionInternal() = 0;
	  virtual uint8_t calibrateGrayscaleInternal() = 0;
	  virtual uint8_t calibrateAmbientLightInternal() = 0;
};

#endif /* TOF_COS_BASE_H_ */

/** @} */
