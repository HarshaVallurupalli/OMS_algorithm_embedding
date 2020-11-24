#ifndef TOF_COS_CONTEXT_H
#define TOF_COS_CONTEXT_H

#include "RamManager/RamManager.h"
#include "DrnuCompensation/DrnuCompensation.h"
#include "TemperatureCompensation/TemperatureCompensation.h"
#include "TOF_COS_Config.h"
#include "AcquisitionMetaData/AcquisitionMetaData.h"
#include "GrayscaleCompensation/GrayscaleCompensation.h"
#include "AmbientLightCompensation/AmbientLightCompensation.h"

class TOF_COS_Context
{
	public:
		TOF_COS_Context()
	  {
		  ramManager = nullptr;
		  dataAcquisition = nullptr;
		  chipControl = nullptr;
		  config = nullptr;
		  calculation = nullptr;
	  }

    class Config *config;
		class RamManager *ramManager;
		class DataAcquisition *dataAcquisition;
		class Calculation *calculation;
		class ChipControl *chipControl;

		AcquisitionMetaData acquisitionMetaData;
		DrnuCompensation drnuCompensation[TOF_COS_NUM_CALIBRATION];
		TemperatureCompensation temperatureCompensation[TOF_COS_NUM_CALIBRATION];
		AmbientLightCompensation ambientLightCompensation;
		GrayscaleCompensation grayscaleCompensation;
};

#endif /* TOF_COS_CONTEXT_H */
