/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup epc_660 EPC 660 Constants
 * @ingroup tof_cos
 * @brief Constants for the EPC660 TOF imager
 *
 * @{
 */
#ifndef EPC660_H_
#define EPC660_H_

namespace EPC660
{
  const uint16_t WIDTH = 320;                        ///<Total with in pixels
  const uint16_t HEIGTH = 240;                       ///<Total height in pixels
  const uint32_t NUM_PIXEL = WIDTH * HEIGTH;         ///<Resulting number of pixels

  const uint8_t ROI_X_BORDER = 4;                   ///<Start point of the ROI. The imager has some dummy columns
  const uint8_t ROI_Y_BORDER = 6;                   ///<Start point of the ROI. The imager has some dummy rows
  const uint16_t ROI_X_MAX = 319;                    ///<Max x ROI value (0..this)
  const uint16_t ROI_Y_MAX = 239;                    ///<Max y ROI value (0..this)
  const uint8_t ROI_WIDTH_MIN = 6;                  ///<Minimal possible width
  const uint8_t ROI_HEIGHT_MIN = 2;                 ///<Minimal possible height
  const uint8_t ROI_Y_SETTING_MAX = 117;            ///<Max possible y ROI because of symmetrical ROI

  const uint32_t MODULATION_CLOCK = 96000000;        ///<Built-in modulation clock

  const uint8_t NUM_DLL_STEPS = 50;                  ///<Available number of DLL steps

  const bool SYMMETRICAL_ROI = true;                 ///<true means that the ROI is symmetrical to the x axis
}

#endif /* EPC660_H_ */

/** @} */
