/*
 * tof_cos_io.h
 *
 *  Created on: 22.08.2019
 *      Author: mwi
 */

#ifndef TOF_COS_IO_H_
#define TOF_COS_IO_H_

void tofCosIoResetEpcChip();
void tofCosIoSetIlluminationEnabled(const bool enabled);
void tofCosIoArmExternalShutter();
void tofCosIoDisarmExternalShutter();
void tofCosIoEnableCalibrationLight();
void tofCosIoDisableCalibrationLight();

#endif /* TOF_COS_IO_H_ */
