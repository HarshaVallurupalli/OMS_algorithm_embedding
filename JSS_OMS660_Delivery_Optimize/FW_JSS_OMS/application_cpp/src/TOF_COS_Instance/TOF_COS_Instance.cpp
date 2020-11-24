/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 *
 * @addtogroup tof_cos_dme_fpga_camera
 *
 * @{
 */
#include <TOF_COS_Instance/TOF_COS_Instance.h>
#include "TOF_COS_Memory.h"
#include "tof_cos_calibration_memory.h"
#include "TraceSettings.h"


static const int32_t PIXEL_TEMPERATURE_COEFFICIENT = static_cast<int32_t>((TOF_COS_TEMPERATURE_COEFFICIENT) * (double)(1 << TEMPERATURE_CALC_SHIFT));

/**
 * @brief Init
 *
 * This function overrides the function in the base class. It initializes the calibration data.
 */
void TOF_COS_Instance::initCalibrationSettings()
{
	//Config
	context.config->setDrnuCompensationMemory(tofCosCalibrationMemoryGetStartAddress() + TOF_COS_CALIBRATION_DRNU_DATA_0_OFFSET, TOF_COS_CALIBRATION_DRNU_DATA_0_SIZE, 0);

	//DRNU compenation
	context.drnuCompensation[0].setCalibrationAddress(tofCosCalibrationMemoryGetStartAddress() + TOF_COS_CALIBRATION_DRNU_DATA_0_OFFSET);
	context.temperatureCompensation[0].setCalibrationAddress(tofCosCalibrationMemoryGetStartAddress() + TOF_COS_CALIBRATION_DRNU_DATA_0_OFFSET);
	context.temperatureCompensation[0].setTemperatureCoefficient(PIXEL_TEMPERATURE_COEFFICIENT);

	//Grayscale compensation
	context.grayscaleCompensation.setCalibrationAddress(tofCosCalibrationMemoryGetStartAddress() + TOF_COS_CALIBRATION_GRAYSCALE_OFFSET);

	//Ambient Light compensation
	context.ambientLightCompensation.setCalibrationAddress(tofCosCalibrationMemoryGetStartAddress() + TOF_COS_CALIBRATION_AMBIENT_LIGHT_OFFSET);
}

/**
 * @brief Production calibration
 *
 * This function runs the specific production calibration for the DME FPGA camera.
 * 12 and 24MHz are fully calibrated, the other frequencies are calibrated only with an offset.
 *
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Instance::calibrateProductionInternal()
{
  uint8_t status = TypeReturnValue::TOF_COS_STATUS_OK;

  TRACE("--->Production Calibration\r\n");

  TRACE("--->Calibration 0: full DRNU\r\n");
  setModulactionFrequency(Modulation::MODULATION_24MHZ);
  status = calibrateDrnu(false, false, 0);
  if (status != TOF_COS_STATUS_OK)
  {
  	TRACE("--->Failed\r\n");
  	return status;
  }/*  Cancel, error ---------------------------------------------> */
  TRACE("--->Done\r\n");

  TRACE("--->Calibration Grayscale\r\n");
  status = calibrateGrayscale();
  if (status != TOF_COS_STATUS_OK)
  {
    return status;
  }/*  Cancel, error ---------------------------------------------> */
  TRACE("--->Done\r\n");

  TRACE("--->Calibration Ambient Light\r\n");
  calibrateAmbientLight();
  if (status != TOF_COS_STATUS_OK)
  {
    return status;
  }/*  Cancel, error ---------------------------------------------> */
  TRACE("--->Done\r\n");


  TRACE("--->Write to Calibration Memory\r\n");
  status = writeCalibrationToMemory();
  if (status != TOF_COS_STATUS_OK)
  {
    TRACE("--->Failed\r\n");
    return status;
  }/*  Cancel, error ---------------------------------------------> */


  TRACE("--->Finished\r\n");

  return status;
}

/**
 * @brief Grayscale calibration
 *
 * This function runs the specific grayscale calibration for this camera.
 *
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Instance::calibrateGrayscaleInternal()
{
  return calibrateGrayscale(tofCosCalibrationMemoryGetStartAddress() + TOF_COS_CALIBRATION_GRAYSCALE_OFFSET, TOF_COS_CALIBRATION_GRAYSCALE_SIZE);
}

/**
 * @brief Ambient light calibration
 *
 * This function runs the specific ambient light calibration for this camera.
 *
 * @return Value from TypeReturnValue
 */
uint8_t TOF_COS_Instance::calibrateAmbientLightInternal()
{
  return calibrateAmbientLight(tofCosCalibrationMemoryGetStartAddress() + TOF_COS_CALIBRATION_AMBIENT_LIGHT_OFFSET, TOF_COS_CALIBRATION_AMBIENT_LIGHT_SIZE);
}

/** @} */
