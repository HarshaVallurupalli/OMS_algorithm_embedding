/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup fpga FPGA
 * @ingroup hal
 *
 * @brief HAL for the FPGA
 *
 * @{
 */
#ifndef FPGA_H_
#define FPGA_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include "drivers/fpga_ctrl.h"

typedef struct
{
  uint16_t sensorWidth;
  uint16_t sensorHeight;
  uint16_t roi_x_TL;
  uint16_t roi_y_TL;
  uint16_t roi_x_BR;
  uint16_t roi_y_BR;
  uint16_t width;
  uint16_t height;
  uint32_t numBytes;
}fpgaAcquisitionSettings_t;

int8_t fpgaInit(void);


/************************************************************************
 * Acquisition functions
 ************************************************************************/
void fpgaStartGrayscale(volatile uint32_t *pDest_GS, volatile uint32_t *pDest_SORT, volatile uint32_t *pSGDesc, volatile uint32_t *pCalibration_GS, fpgaAcquisitionSettings_t acquisitionSettings);
void fpgaStartDistanceAmplitude(volatile uint32_t *pDest_GS, volatile uint32_t *pDest_DCS, volatile uint32_t *pDest_SORT, volatile uint32_t *pSGDesc, fpgaAcquisitionSettings_t acquisitionSettings);
void fpgaStartDualMGX(uint32_t *pDest_GS, uint32_t *pDest_DCS, uint32_t *pDest_SORT, uint32_t *pSGDesc, volatile uint32_t *pCalibration_GS, const volatile uint16_t width, const volatile uint16_t height, const uint32_t numBytes);
void fpgaStartDCS(volatile uint32_t *pDest, const volatile uint16_t width, const volatile uint16_t height, const uint32_t numBytes);
bool fpgaAcquisitionIsBusy(void);
bool fpgaDcsAcquisitionIsBusy(void);
int8_t fpgaWaitAcquisitionBlocking(const int32_t timeout);


/************************************************************************
 * Setup functions
 ************************************************************************/
void fpgaSetSensorSize(const uint16_t width, const uint16_t height);
void fpgaSetCorrectionAddress(const uint32_t address);
void fpgaSetDistanceRange(const uint32_t maxValue);
void fpgaSetDllStep(const uint32_t dllStep, const uint32_t nbofdllSteps);
uint32_t fpgaScaleDistance(const uint32_t distanceFullRange);
void fpgaSetEnabled(const bool enabled);
void fpgaSetImageBinningEnabled(const bool enabled);
void fpgaSetAdcOverflowDetection(const bool enabled);
void fpgaSetGrayscaleSubtractEnabled(const bool enabled);
bool fpgaGetGrayscaleSubtractEnabled(void);
void fpgaSetPreCorrectionOffsetEnabled(const bool enabled);
void fpgaSetPostCorrectionOffsetEnabled(const bool enabled);
void fpgaSetDistanceCorrectionEnabled(const bool enabled);
void fpgaSetInterferenceThreshold(const uint32_t threshold);
void fpgaSetAmbientLightCorrection(const uint32_t parameter);
void fpgaSetGrayscaleCompensationEnabled(const bool enabled);
bool fpgaGetGrayscaleCompensationEnabled(void);
void fpgaSetAmbientCorrectionEnabled(const bool enabled);
void fpgaSetMultiplierToOne();
void fpgaRegisterCallback(void(*callback)(void *), void *arg);
void fpgaSetPostCorrectionOffset(const int32_t offset);
void fpgaSetPreCorrectionOffset(const int32_t offset);


/************************************************************************
 * Status functions
 ************************************************************************/
fpgaDebug_t fpgaGetDebugData(void);

#ifdef __cplusplus
}
#endif

#endif /* FPGA_H_ */

/** @} */
