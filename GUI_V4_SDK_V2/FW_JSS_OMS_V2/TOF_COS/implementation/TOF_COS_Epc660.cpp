/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup tof_cos_epc660
 *
 * @{
 */
#include <Calibration/DrnuCalibrationJob.h>
#include <GlobalSettings.h>
#include <TOF_COS_Epc660.h>
#include "TOF_COS_Memory.h"
#include "Calibration/Calibration_Calculation.h"
#include "jobs/JobDistance.h"
#include "jobs/JobDistAmpl.h"
#include "jobs/JobGrayscale.h"
#include "tof_cos_calibration_memory.h"

static const int32_t PIXEL_TEMPERATURE_COEFFICIENT = static_cast<int32_t>((TOF_COS_TEMPERATURE_COEFFICIENT) * (double)(1 << TEMPERATURE_CALC_SHIFT));

TOF_COS_Epc660::TOF_COS_Epc660(): TOF_COS_Base(),
actConfig(actChipControl),
actDataAcquisition(&context)
{
	context.dataAcquisition = &actDataAcquisition;
	context.calculation = &actCalculation;
	context.chipControl = &actChipControl;
	context.config = &actConfig;
	context.ramManager = &actRamManager;
	sequencerProgrammer = &actSequencerProgrammer;

	PointCloudJob::setContext(&context);
}

/** @} */
