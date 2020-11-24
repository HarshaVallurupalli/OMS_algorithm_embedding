/**************************************************************************************
* Copyright (C) 2019 Espros Photonics Corporation
*
* Open Source Software used:
* - Qt5: Copyright (C) 2019 The Qt Company
***************************************************************************************/

#ifndef EPC660_H_
#define EPC660_H_

namespace EPC660
{
  const uint32_t WIDTH = 320;
  const uint32_t HEIGTH = 240;
  const uint32_t NUM_PIXEL = WIDTH * HEIGTH;

  const uint32_t ROI_X_BORDER = 4;
  const uint32_t ROI_Y_BORDER = 6;
  const uint32_t ROI_X_MAX = 319;
  const uint32_t ROI_Y_MAX = 239;
  const uint32_t ROI_WIDTH_MIN = 6;
  const uint32_t ROI_HEIGHT_MIN = 2; 
}

#endif /* EPC660_H_ */
