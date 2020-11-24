/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup tof_cos_epc660 EPC660
 * @ingroup tof_cos
 * @brief Instance Class for EPC660
 *
 * @{
 */
#ifndef TOF_COS_EPC660_H_
#define TOF_COS_EPC660_H_

#include <Calibration/DrnuCalibration.h>
#include <Config/Config.h>
#include <TOF_COS_Base.h>
#include "ChipControl/ChipControl.h"
#include "Calculation/Calculation.h"
#include "ChipControl/ChipControlEpc660.h"
#include "DataAcquisition/DataAcquisition.h"
#include "RamManager/RamManager.h"
#include "SequencerProgrammer/SequencerProgrammer.h"


class TOF_COS_Epc660: public TOF_COS_Base
{
	public:
		TOF_COS_Epc660();

	protected:
		Config actConfig;
		DataAcquisition actDataAcquisition;
		RamManager actRamManager;
		ChipControlEpc660 actChipControl;
		SequencerProgrammer actSequencerProgrammer;
		CalibrationCalculation actCalculation;

	private:
};

#endif /* TOF_COS_EPC660_H_ */

/** @} */
