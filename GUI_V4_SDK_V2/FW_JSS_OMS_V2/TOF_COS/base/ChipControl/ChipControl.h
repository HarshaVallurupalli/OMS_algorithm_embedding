/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup chip_control Chip Control
 * @ingroup tof_cos
 *
 * @brief Abstract ChipControl class
 *
 * @{
 */
#ifndef CHIP_CONTROL_H_
#define CHIP_CONTROL_H_

#include "ChipControl.h"
#include <stdbool.h>
#include <stdint.h>
#include "TypeInternalReturnValue.h"
#include "ChipControl/ChipControl.h"
#include <TOF_COS_Constants.h>

//! Abstract ChipControl class
/*!
 * This class is responsible for the common functionality to control the TOF imager. For a specific TOF imagers,
 * a sub class has to be implemented with some sensor specific functions.
 */
class ChipControl
{
  public:
		ChipControl();
		TypeInternalReturnValue setDeviceAddress(const uint16_t deviceAddress);
    void sendShutter();
    void setIntegrationTime(const uint16_t us, const uint32_t modulationClockInput);
    void setIntegrationTime1(const uint16_t us0, const uint16_t us1, const uint32_t modulationClockInput);
    virtual TypeInternalReturnValue initChip() = 0;

    void setTo3dUnShadowed();
    void setToGrayscaleUnShadowed();

    void setTo3dShadowed();
    void setToGrayscaleShadowed();
	void setToDualMGX();

	void setExternalModulationClock(const bool enabled);

    void setDCS(const uint8_t nDCS);
    void setDllManual(const bool manual);
    void setDllCoarseStepExt(const uint8_t step);
    void setVerticalBinning(const bool binning);
    void setHorizontalBinning(const bool binning);
    virtual void setRoi(const uint16_t xMin, const uint16_t yMin, const uint16_t xMax, const uint16_t yMax) = 0;
    virtual void setMinimalRoi() = 0;
    void setModClockDivider(const uint8_t divider);
    void setHdrMode(const bool enabled);
    void setAbs(const bool enabled);
    void setLedGrayscale(const bool enabled, const bool modulated);
    uint8_t readRegister(const uint8_t registerAddress);
    void writeRegister(const uint8_t registerAddress, const uint8_t value);
    TypeInternalReturnValue init();
    virtual int32_t readTemperature() = 0;
    uint16_t getChipId() const;
    uint16_t getWaferId() const;
    uint16_t getIntegrationTimeLength();
    uint16_t getIntegrationTimeMultiplier();
    void setIntegrationTimeRegisters(const uint16_t length, const uint16_t multiplier);

    TypeInternalReturnValue getAndClearStatus();

  protected:
    void setLed2Pin(const bool enabled);
    void setLedPin(const bool enabled);
    void setBypassDll(const bool enabled);
    void setManualDll(const bool manual);
    void setLedPinInveted(const bool inverted);
    void setDcsNumberOfImage(const uint32_t image, const uint32_t dcsNumber);

    ///This multiplier is used for the temperature calculation. It can be found in th data sheet. Here it is converted to a fix point value
    static const uint32_t TEMPERATURE_MULTIPLIER = (uint32_t) (0.134 * (double)(1 << TEMPERATURE_CALC_SHIFT));

    uint16_t deviceAddress;                            ///<I2C address of the device
  	uint8_t register0xD3;                              ///<Stores the register value at startup
  	uint8_t register0xD5;                              ///<Stores the register value at startup
  	uint8_t register0xE9;                              ///<Stores the register value at startup (DLL coefficient)
  	uint16_t chipId;                                   ///<Stores the chip id, read once at startup
  	uint16_t waferId;                                  ///<Stores the wafer if, read once at startup
  	uint8_t modulationClockDivider;                    ///Shadow register for the modulation clock divider
  	uint16_t integrationTimeMultiplier;                ///<Shadow register for the integration time multiplier


  private:
  	uint16_t readChipId();
  	uint16_t readWaferId();
  	void initRegisters();
  	void readFromEeprom(const uint8_t registerAddress, const uint32_t numBytes, uint8_t *pData);
  	virtual void initRegistersSpecific() = 0;
  	virtual void setRegistersToTof() = 0;
  	virtual void setRegistersToGrayscale() = 0;
};

#endif /* CHIP_CONTROL_H_ */

/** @} */
