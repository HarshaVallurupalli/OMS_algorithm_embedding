/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup tof_cos_dme_fpga_camera DME FPGA Camera
 * @ingroup tof_cos
 * @brief Implementation for DME FPGA Camera
 *
 * @{
 */
#ifndef TOF_COS_JSS_OMS_CAMERA_H_
#define TOF_COS_JSS_OMS_CAMERA_H_

#include "TOF_COS_Epc660.h"



class TOF_COS_Instance: public TOF_COS_Epc660
{
	private:
		uint8_t calibrateProductionInternal() override;
		uint8_t calibrateGrayscaleInternal() override;
		uint8_t calibrateAmbientLightInternal() override;
		void initCalibrationSettings() override;

};

#endif /* TOF_COS_JSS_OMS_CAMERA_H_ */

/** @} */
