/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup config
 *
 * @{
 */
#include "Config.h"
#include "tof_cos_clock_generator.h"
#include "fpga.h"
#include "Calibration/DrnuCalibrationDataHelper.h"
#include "ChipSelection.h"


/**
 * @brief Constructor
 *
 * @param chipControl Reference to Chip Control class to use
 */
Config::Config(ChipControl &chipControl): chipControl(chipControl)
{
  for (uint8_t i = 0; i < NUM_INTEGRATION_TIME; i++)
  {
  	integrationTime3D[i] = DEFAULT_INTEGRATION_TIME_3D;
  }

  offset = 0;
  integrationTimeGrayscale = DEFAULT_INTEGRATION_TIME_GRAYSCALE;
  minAmplitude = 50;
  actualMode = CONFIG_NONE;
  newAcquisitionIsRequired = true;
  externalShutter = false;

  //Enable the compensations available in the system so far
  compensationFlags = (MASK_DRNU_COMPENSATION | MASK_TEMPERATURE_COMPENSATION); //| MASK_AMBIENT_LIGHT_COMPENSATION | MASK_GRAYSCALE_COMPENSATION);

  dllStep = TOF_COS_DLL_STEP_OPERATION;
}

/**
 * @brief Init
 *
 * @param Call before using this class
 */
TypeInternalReturnValue Config::init()
{
	int8_t status = tofCosClockGeneratorInit();
	if (status < 0)
	{
	  return TypeInternalReturnValue::STATUS_ERROR_CLOCK_GENERATOR;
	}

	return chipControl.initChip();
}

/**
 * @brief Set integration time 3D
 *
 * @param integration time in us
 * @param index Index of the integration time
 */
void Config::setIntegrationTime3d(const uint16_t integrationTime, const uint8_t index)
{
  if (index >= NUM_INTEGRATION_TIME)
  {
  	return;
  }

  //A new acquisition will be started
  actualMode = CONFIG_NONE;

  this->integrationTime3D[index] = integrationTime;
}

/**
 * @brief Get integration time 3D
 *
 * @param index Index of the integration time
 * @return Integration time in us
 */
uint16_t Config::getIntegrationTime3d(const uint8_t index) const
{
	if (index >= NUM_INTEGRATION_TIME)
	{
	  return 0;
	}

	return integrationTime3D[index];
}

/**
 * @brief Set integration time grayscale
 *
 * @param integration time in us
 */
void Config::setIntegrationTimeGrayscale(const uint16_t integrationTime)
{
  this->integrationTimeGrayscale = integrationTime;
}

/**
 * @brief Get integration time grayscale
 *
 * @return Integration time grayscale in us
 */
uint16_t Config::getIntegrationTimeGrayscale() const
{
  return integrationTimeGrayscale;
}

/**
 * @brief Set minimal amplitude
 *
 * @param amplitude Minimal amplitude in lsb
 */
void Config::setMinAmplitude(const uint16_t amplitude)
{
  this->minAmplitude = amplitude;
}

/**
 * @brief Get minimal amplitude
 *
 * @return Minimal amplitude in lsb
 */
uint16_t Config::getMinAmplitude() const
{
	return minAmplitude;
}

/**
 * @brief Set Offset
 *
 * @param offset Offset
 */
void Config::setOffset(const int16_t offset)
{
	this->offset = offset;
}

/**
 * @brief Get Offset
 *
 * @return Offset
 */
int16_t Config::getOffset() const
{
	return offset;
}

/**
 * @brief Set Modulation
 *
 * @param modulation Modulation settings
 * @param index Index of the settings
 */
void Config::setModulation(const Modulation modulation, const uint8_t index)
{
	this->modulationSettings.setModulation(modulation, index);
}

/**
 * @brief Get Modulation of selected settings
 *
 * @param index Index of the settings
 * @return Modulation settings
 */
Modulation Config::getModulation(const uint8_t index) const
{
	return modulationSettings.getModulation(index);
}

/**
 * @brief Get current used Modulation
 *
 * @return Modulation settings
 */
Modulation Config::getModulation() const
{
	return modulationSettings.getModulation(0);	 //Index 0 at the moment
}

/**
 * @brief Set Modulation Channel
 *
 * Each channel defines a modulation frequency that is slightly different to the base modulation frequency. This
 * helps to prevent interference by multiple cameras looking to the same target.
 *
 * @param autoChannelEnabled Set to true to enable automatic channel change in case of interference
 * @param channel Channel number
 */
void Config::setModulationChannel(const bool autoChannelEnabled, const uint8_t channel)
{
	Modulation::setAutoChannelEnabled(autoChannelEnabled);
	Modulation::setChannel(channel);

	newAcquisitionIsRequired = true;
}

/**
 * @brief Set Binning
 *
 * @param binning Binning settings
 * @param index Index of the settings
 */
void Config::setBinning(const Binning binning, const uint8_t index)
{
	this->binningSettings.setBinning(binning, index);

	newAcquisitionIsRequired = true;
}

/**
 * @brief Get Binning
 *
 * @return Binning settings
 */
Binning Config::getBinning() const
{
  return binningSettings.getBinning();
}

/**
 * @brief Set the ROI (region of interest of the sensor)
 *
 * For the current settings.
 *
 * @param roi Structure containing the roi
 */
void Config::setRoi(const Roi roi)
{
	Roi sensorRoi;

	sensorRoi.xMin = binningSettings.getBinning().getSensorRoiX(roi.xMin);
	sensorRoi.xMax = binningSettings.getBinning().getSensorRoiX(roi.xMax);
	sensorRoi.yMin = binningSettings.getBinning().getSensorRoiY(roi.yMin);
	sensorRoi.yMax = binningSettings.getBinning().getSensorRoiY(roi.yMin);

  this->roiSettings.setRoi(sensorRoi, 0); //settings 0 so far

	newAcquisitionIsRequired = true;
}

/**
 * @brief Get the ROI (region of interest of the sensor)
 *
 * @return roi Class containing the ROI
 */
Roi Config::getRoi()
{
	return roiSettings.getRoi();
}

/**
 * @brief Set the HDR
 *
 * @param hdr Class containing the HDR settings
 */
void Config::setHdr(const Hdr hdr)
{
  hdrSettings.setHdr(hdr);

  newAcquisitionIsRequired = true;
}

/**
 * @brief Get the HDR
 *
 * @return Class containing the HDR settings
 */
Hdr Config::getHdr()
{
	return hdrSettings.getHdr();
}

/**
 * @brief Set the DLL step
 *
 * @param step DLL step to set
 */
void Config::setDllStep(const uint8_t step)
{
	this->dllStep = step;
	chipControl.setDllCoarseStepExt(this->dllStep);
}

/**
 * @brief Get the DLL step
 *
 * @return DLL step
 */
uint8_t Config::getDllStep() const
{
	return dllStep;
}

/**
 * @brief Set grayscale illuminated
 *
 * If this is true, the illumination is on during grayscale acquisition.
 *
 * @param enabled Illumination enabled/disabled during grayscale acquisition
 */
void Config::setGrayscaleIlluminated(const bool enabled)
{
  grayscaleIlluminationSettings.setEnabled(enabled);
}

/**
 * @brief Get grayscale illuminated
 *
 * If this is true, the illumination is on during grayscale acquisition.
 *
 * @return Illumination enabled/disabled during grayscale acquisition
 */
bool Config::getGrayscaleIlluminated() const
{
  return grayscaleIlluminationSettings.getEnabled();
}

/**
 * @brief Set the DRNU compensation address/size for the selected compensation
 *
 * This is the address/size of the compensation in the memory
 *
 * @param address Compensation address in the memory
 * @param size Compensation size in the memory
 * @param index Index of the current compensation
 */
void Config::setDrnuCompensationMemory(uint32_t address, const uint32_t size, const uint8_t index)
{
	this->drnuCompensationMemory[index].address = address;
	this->drnuCompensationMemory[index].size = size;
}

/**
 * @brief Get the DRNU compensation address/size for given compensation
 *
 * This is the address/size of the compensation in the memory
 *
 * @param index Index of the compensation
 * @return Class containing information about the DRNU compensation memory
 */
MemoryInfo Config::getDrnuCompensationMemory(const uint8_t index) const
{
	return drnuCompensationMemory[index];
}

/**
 * @brief Set external shutter
 *
 * If this is set, the shutter is not done by the firmware, it is triggered
 * by an external input or a command.
 *
 * @param enabled External shutter enabled or not
 */
void Config::setExternalShutter(const bool enabled)
{
	this->externalShutter = enabled;
}

/**
 * @brief Get external shutter
 *
 * If this is set, the shutter is not done by the firmware, it is triggered
 * by an external input or a command.
 *
 * @return External shutter enabled or not
 */
bool Config::getExternalShutter() const
{
	return externalShutter;
}

/**
 * @brief Enable or disable the compensations
 *
 * @param drnuCompensationEnabled Enable/disable the DRNU compensation
 * @param temperatureCompensationEnabled Enable/disable the temperature compensation
 * @param ambientLightCompensationEnabled Enable/disable the ambient light compensation
 * @param grayscaleCompensationEnabled Enable/disable the grayscale compensation
 */
void Config::setCompenationEnabled(const bool drnuCompensationEnabled, const bool temperatureCompensationEnabled, const bool ambientLightCompensationEnabled, const bool grayscaleCompensationEnabled)
{
  compensationFlags = 0;

	if (drnuCompensationEnabled)
  {
  	compensationFlags |= MASK_DRNU_COMPENSATION;
  }

	if (temperatureCompensationEnabled)
	{
		compensationFlags |= MASK_TEMPERATURE_COMPENSATION;
	}

	setAmbientLightCompensationEnabled(ambientLightCompensationEnabled);

	if (grayscaleCompensationEnabled)
	{
		compensationFlags |= MASK_GRAYSCALE_COMPENSATION;
	}
}

/**
 * @brief Enable or disable the ambient light compensation
 *
 * @param enabled Enable/disable the ambient light compensation
 */
void Config::setAmbientLightCompensationEnabled(const bool enabled)
{
	if (enabled)
	{
		compensationFlags |= MASK_AMBIENT_LIGHT_COMPENSATION;
	}
	else
	{
		compensationFlags &= ~(MASK_AMBIENT_LIGHT_COMPENSATION);
	}
}

/**
 * @brief Get DRNU compensation enabled
 *
 * @retval true DRNU compensation enabled
 * @retval false DRNU compensation disabled
 * @return DRNU compensation enabled or disabled
 */
bool Config::getDrnuCompensationEnabled() const
{
	return (compensationFlags & MASK_DRNU_COMPENSATION);
}

/**
 * @brief Get temperature compensation enabled
 *
 * @retval true Temperature compensation enabled
 * @retval false Temperature compensation disabled
 * @return Temperature compensation enabled or disabled
 */
bool Config::getTemperatureCompenastionEnabled() const
{
	return (compensationFlags & MASK_TEMPERATURE_COMPENSATION);
}

/**
 * @brief Get ambient light compensation enabled
 *
 * @retval true Ambient light compensation enabled
 * @retval false Ambient light compensation disabled
 * @return Ambient light compensation enabled or disabled
 */
bool Config::getAmbientLightCompensationEnabled() const
{
	return (compensationFlags & MASK_AMBIENT_LIGHT_COMPENSATION);
}

/**
 * @brief Get grayscale compensation enabled
 *
 * @retval true Grayscale compensation enabled
 * @retval false Grayscale compensation disabled
 * @return Grayscale compensation enabled or disabled
 */
bool Config::getGrayscaleCompensationEnabled() const
{
	return (compensationFlags & MASK_GRAYSCALE_COMPENSATION);
}

/**
 * @brief Get number of pixels for actual settings
 *
 * @return Number of pixels for actual settings
 */
uint32_t Config::getNumPixel() const
{
  uint16_t width = getWidth();
	uint16_t height = getHeight();
	uint32_t numPixel = width * height;

	return numPixel;
}

/**
 * @brief Get image width
 *
 * This width is dependent of the actual settings.
 *
 * @return width
 */
uint16_t Config::getWidth() const
{
	return binningSettings.getBinnedWidth(roiSettings.getWidth());
}

/**
 * @brief Get image height
 *
 * This height is dependent of the actual settings.
 *
 * @return height
 */
uint16_t Config::getHeight() const
{
	return binningSettings.getBinnedHeight(roiSettings.getHeight());
}

/**
 * @brief Load base chip settings
 *
 * These are the settings that have an impact on image/data size and clocks and are common for grayscale and
 * 3D acquisition. It is important to have the same settings for 3D and grayscale acquisition so the image matches (e.g. the size)
 */
void Config::loadBaseChipSettings()
{
	loadBinning();

  loadRoi();

	loadModulation();

	loadHdr();

	loadGrayscaleIllumination();
}

/**
 * @brief Load 3D settings
 *
 * Configure chip for 3D operation
 *
 * @param index Index of the integration time to use
 */
void Config::load3dSettings(const uint8_t index)
{
	if (index >= NUM_INTEGRATION_TIME)
	{
	  return;
	}

	if (actualMode != CONFIG_TOF)
	{
		load3dMode();
	}

	if (hdrSettings.getHdr().isSpatialHdr())
  {
		chipControl.setIntegrationTime1(integrationTime3D[0], integrationTime3D[1], modulationSettings.getModulation().getModulationClockInput());
  }
	else
	{
	  chipControl.setIntegrationTime(integrationTime3D[index], modulationSettings.getModulation().getModulationClockInput());
	}

	newAcquisitionIsRequired = false;
}

/**
 * @brief Load grayscale
 *
 * Configure chip for grayscale operation
 *
 * @param index Index of the integration time to use
 */
void Config::loadGrayscaleSettings()
{
	if (actualMode != CONFIG_GRAYSCALE)
	{
		setToGrayscale();
	}

	chipControl.setIntegrationTime(integrationTimeGrayscale, modulationSettings.getModulation().getModulationClockInput());
}

/**
 * @brief Load grayscale for temperature measurement only
 *
 * Configures the chip like for grayscale but with minimal integration time and makes sure that
 * the chip will be reconfigured before the next acquisition.
 *
 * @param index Index of the integration time to use
 */
void Config::loadSettingsGrayscaleForTemperatureOnly()
{
	chipControl.setToGrayscaleUnShadowed();
	chipControl.setToGrayscaleShadowed();
	chipControl.setDCS(1);
	chipControl.setMinimalRoi();
	chipControl.setIntegrationTime(1, getModulation().getModulationClockInput());

	//Make sure that the chip will be reconfigured before the next acquisition
	roiSettings.setChanged();
	actualMode = CONFIG_NONE;
}


void Config::loadIntegrationTimeDualMGX(const uint8_t index)
{
	if (index >= NUM_INTEGRATION_TIME)
	{
	  return;
	}

	if (actualMode != CONFIG_DUALMGX)
	{
		setToDualMGX();
	}

	chipControl.setIntegrationTime(integrationTime3D[index], modulationSettings.getModulation().getModulationClockInput());
}

/**
 * @brief Load FPGA settings without compensation
 *
 * If no calibration/compensation is available, this function loads FPGA settings without compensation.
 */
void Config::loadFpgaWithoutDrnuCompensation()
{
  //Offset zero
	fpgaSetPreCorrectionOffset(0);

	//No calibration data
	fpgaSetCorrectionAddress(0);

	fpgaSetDllStep(0, 0);

	fpgaSetPreCorrectionOffsetEnabled(true);

	fpgaSetPostCorrectionOffsetEnabled(true);

	fpgaSetDistanceCorrectionEnabled(false);

	fpgaSetDistanceRange(modulationSettings.getModulation().getBaseDistanceRange());
}

/**
 * @brief Check, if set to 3D
 *
 * @retval true Chip is ready setup for 3D
 * @retval false Chip is not ready setup for 3D
 * @return Ready for 3D or not
 */
bool Config::is3d() const
{
	return (actualMode == CONFIG_TOF);
}

/**
 * @brief Check, if set to Grayscale
 *
 * @retval true Chip is ready setup for Grayscale
 * @retval false Chip is not ready setup for Grayscale
 * @return Ready for Grayscale or not
 */
bool Config::isGrayscale() const
{
	return (actualMode == CONFIG_GRAYSCALE);
}

/**
 * @brief Check, if set to DualMGX
 *
 * @retval true Chip is ready setup for DualMGX
 * @retval false Chip is not ready setup for DualMGX
 * @return Ready for DualMGX or not
 */
bool Config::isDualMGX() const
{
	return (actualMode == CONFIG_DUALMGX);
}

/**
 * @brief Get the index of the compensation
 *
 * This also detects, if there is a compensation available for the current settings. If this is
 * not the case, a negative value is returned.
 *
 * @retval -1 No compensation possible for the current settings
 * @return Index of the compensation
 */
int8_t Config::getIndexCompensation() const
{
  for (uint8_t i = 0; i < TOF_COS_NUM_CALIBRATION; i++)
	{
	  DrnuCalibrationDataHelper calibrationDataHelper(drnuCompensationMemory[i].address);

	  if ((calibrationDataHelper.checkHeaderValid()) &&
	  		(calibrationDataHelper.getModulation().getModulationFrequency() == modulationSettings.getModulation().getModulationFrequency()))

	  {
      return i;
	  }
	}

	return -1;
}

/**
 * @brief Read if a new acquisition is required
 *
 * This could be the case when settings change.
 *
 * @retval true New Acquisition is required
 * @retval false No new acquisition required. The
 * @return New acquisition required or not
 */
bool Config::newAcquisitionRequired() const
{
  return newAcquisitionIsRequired;
}

/**
 * @brief Setup chip for 3D mode
 *
 */
void Config::load3dMode()
{
	if (actualMode == CONFIG_TOF)
	{
		return;
	}/* Already in this mode, do not waste time with I2C commands -----------> */

	actualMode = CONFIG_TOF;

	chipControl.setTo3dShadowed();

	chipControl.setDCS(4);
}

/**
 * @brief Setup chip for grayscale mode
 *
 */
void Config::setToGrayscale()
{
	actualMode = CONFIG_GRAYSCALE;

	chipControl.setToGrayscaleShadowed();

	chipControl.setDCS(1);
}

void Config::setToDualMGX()
{
	actualMode = CONFIG_DUALMGX;
	chipControl.setToDualMGX();
	chipControl.setDCS(2);
}

/**
 * @brief Load binning settings
 *
 * This function loads the binning settings into the chip. If they have not changed, nothing is done.
 */
void Config::loadBinning()
{
  if (binningSettings.hasChanged() == false)
  {
  	return;
  }/* Settings not changed. Return, do not waste time with I2C commands */

	switch(binningSettings.getBinning().getValue())
  {
  case Binning::Binning_e::BINNING_NONE:
  	chipControl.setVerticalBinning(false);
  	chipControl.setHorizontalBinning(false);
  	break;
  case Binning::Binning_e::BINNING_VERTICAL:
    chipControl.setVerticalBinning(true);
    chipControl.setHorizontalBinning(false);
  	break;
  case Binning::Binning_e::BINNING_HORIZONTAL:
    chipControl.setVerticalBinning(false);
    chipControl.setHorizontalBinning(true);
  	break;
  case Binning::Binning_e::BINNING_VERTICAL_HORIZONTAL:
    chipControl.setVerticalBinning(true);
    chipControl.setHorizontalBinning(true);
  	break;
  default:
  	chipControl.setVerticalBinning(false);
  	chipControl.setHorizontalBinning(false);
  	break;
  }
}

/**
 * @brief Load ROI settings
 *
 * This function loads the ROI settings into the chip. If they have not changed, nothing is done.
 */
void Config::loadRoi()
{
  if (roiSettings.hasChanged() == false)
  {
  	return;
  }/* No change, do not waste time with I2C commands ----------------------> */

  chipControl.setRoi(roiSettings.getRoi().xMin, roiSettings.getRoi().yMin, roiSettings.getRoi().xMax, roiSettings.getRoi().yMax);
}

/**
 * @brief Load HDR settings
 *
 * This function loads the HDR settings into the chip. If they have not changed, nothing is done.
 */
void Config::loadHdr()
{
  if (hdrSettings.hasChanged() == false)
  {
  	return;
  }/* No change, do not waste time with I2C commands ----------------------> */


  chipControl.setHdrMode(hdrSettings.getHdr().isSpatialHdr());
}

/**
 * @brief Load modulation settings
 *
 * This function loads the modulation settings into the chip. If they have not changed, nothing is done.
 */
void Config::loadModulation()
{
  if ((modulationSettings.hasChanged() == false) && (Modulation::hasChanged() == false))
  {
    return;
  }/* Settings not changed. Return, do not waste time with I2C commands */


  chipControl.setModClockDivider(modulationSettings.getModulation().getChipDivider());

  fpgaSetDistanceRange(modulationSettings.getModulation().getDistanceRange());

  tofCosClockGeneratorWriteFrequency(modulationSettings.getModulation().getClock());
}

/**
 * @brief Load grayscale illumination settings
 *
 * This function loads the grayscale illumination settings into the chip. If they have not changed, nothing is done.
 */
void Config::loadGrayscaleIllumination()
{
  if (grayscaleIlluminationSettings.hasChanged())
  {
    chipControl.setLedGrayscale(grayscaleIlluminationSettings.getEnabled(), false);
  }
}

/** @} */
