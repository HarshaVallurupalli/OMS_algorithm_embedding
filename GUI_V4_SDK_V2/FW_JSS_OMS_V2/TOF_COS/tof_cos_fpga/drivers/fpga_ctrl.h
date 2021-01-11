/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup fpga_ctrl FPGA control
 *
 * @brief Bit Masks for the interface to the FPGA
 */
#ifndef DRIVERS_FPGA_CTRL_H_
#define DRIVERS_FPGA_CTRL_H_

#include "TOF_COS_Config.h"

//Masks for the result of the FPGA
#define FPGA_RESULT_SHIFT_DISTANCE                                 0
#define FPGA_RESULT_MASK_DISTANCE_CALIBRATION                 0xFFFF

#define FPGA_RESULT_SHIFT_AMPLITUDE                               16
#define FPGA_RESULT_MASK_AMPLITUDE                             0xFFF

//Remove code for old soft logic if not needed anymore
#if (OLD_SOFT_LOGIC==1)
#define FPGA_RESULT_MASK_DISTANCE_NORMAL                      0x3FFF
#define FPGA_RESULT_MASK_INTERFERENCE                     0x00008000
#define FPGA_RESULT_MASK_CHIP_SATURATION                  0x80000000
#define FPGA_RESULT_MASK_ADC_OVERFLOW                     0x40000000
#define FPGA_RESULT_MASK_BAD_PIXEL                        0x10000000
#else
#define FPGA_RESULT_MASK_DISTANCE_NORMAL                      0xFFFF
#define FPGA_RESULT_MASK_INTERFERENCE                     0x40000000
#define FPGA_RESULT_MASK_CHIP_SATURATION                  0x10000000
#define FPGA_RESULT_MASK_ADC_OVERFLOW                     0x20000000
#define FPGA_RESULT_MASK_BAD_PIXEL                        0x80000000
#endif


// DMA constants
#define FPGA_CONFIG_SG_DESCR_LENGTH                           0x3BC0

//Regbank
#define FPGA_CONFIG_CTRL_ADDR                REG_BANK_S00_AXI_SLV_REG0_OFFSET
#define FPGA_CONFIG_ALU_ADDR                 REG_BANK_S00_AXI_SLV_REG1_OFFSET
#define FPGA_CONFIG_AMBIENT_ADDR             REG_BANK_S00_AXI_SLV_REG2_OFFSET
#define FPGA_CONFIG_TEMP_ADDR                REG_BANK_S00_AXI_SLV_REG3_OFFSET
#define FPGA_CONFIG_DIST_DLL_ADDR            REG_BANK_S00_AXI_SLV_REG4_OFFSET
#define FPGA_CONFIG_DIST_STATUS_ADDR         REG_BANK_S00_AXI_SLV_REG5_OFFSET
#define FPGA_CONFIG_CONST_ADDR               REG_BANK_S00_AXI_SLV_REG6_OFFSET
#define FPGA_CONFIG_ENABLE_ADDR              REG_BANK_S00_AXI_SLV_REG7_OFFSET
#define FPGA_CONFIG_DIST_CORR_ADDR           REG_BANK_S00_AXI_SLV_REG8_OFFSET
#define FPGA_CONFIG_MULT_ADDR 				 REG_BANK_S00_AXI_SLV_REG9_OFFSET
#define FPGA_CONFIG_DCS_ADDR                 REG_BANK_S00_AXI_SLV_REG10_OFFSET
#define FPGA_CONFIG_GS_ADDR                  REG_BANK_S00_AXI_SLV_REG11_OFFSET
#define FPGA_CONFIG_DMA_STATUS_ADDR          REG_BANK_S00_AXI_SLV_REG12_OFFSET
#define FPGA_ROI_SETTINGS_ADDR               REG_BANK_S00_AXI_SLV_REG13_OFFSET
#define FPGA_FULL_ROI_ADDR                   REG_BANK_S00_AXI_SLV_REG14_OFFSET
#define FPGA_DEBUG_PXL_ADDR                  REG_BANK_S00_AXI_SLV_REG15_OFFSET

//Masks for the camera ctrl mode register
#define FPGA_CONFIG_SHIFT_NUM_PIXEL                               15
#define FPGA_CONFIG_MASK_RESET                                  0x01
#define FPGA_CONFIG_MASK_UPDATE                                 0x02
#define FPGA_CONFIG_MASK_BADPIX                                 0x20
#define FPGA_CONFIG_SHIFT_MODE                                     2
#define FPGA_CONFIG_SHIFT_PIXEL_PER_LINE                           6

#define FPGA_CONFIG_VAL_MODE_TOF             (0 << FPGA_CONFIG_SHIFT_MODE)
#define FPGA_CONFIG_VAL_MODE_GRAY            (1 << FPGA_CONFIG_SHIFT_MODE)
#define FPGA_CONFIG_VAL_MODE_DCS             (2 << FPGA_CONFIG_SHIFT_MODE)
#define FPGA_CONFIG_VAL_MODE_DUALMGX         (3 << FPGA_CONFIG_SHIFT_MODE) 

// Masks for the alu correction
#define FPGA_CONFIG_SHIFT_ALU_DIST                                 0
#define FPGA_CONFIG_SHIFT_ALU_AMP                                 12
#define FPGA_CONFIG_SHIFT_ALU_MIN                                 24

// Masks for the ambient compensation
#define FPGA_CONFIG_SHIFT_AMBIENT_LIGHT_COMPENSATION               0

// Masks for the temperature correction
#define FPGA_CONFIG_SHIFT_TEMP_VAL                                 0
#define FPGA_CONFIG_SHIFT_TEMP_SIGN                               16
#define FPGA_CONFIG_MASK_TEMP_SIGN                           0x10000

// Mask for the distance correction dll value_comp
//#define FPGA_CONFIG_SHIFT_DIST_DLL                                 0

// Mask for the base address for the distance correction table
//#define FPGA_CONFIG_SHIFT_DIST_RAM                                 0

// Masks for the distance correction status
//#define FPGA_CONFIG_SHIFT_DIST_FAIL_POS                            0
//#define FPGA_CONFIG_MASK_DIST_HIGH                           0x20000
//#define FPGA_CONFIG_MASK_DIST_LOW                            0x40000
//#define FPGA_CONFIG_SHIFT_DIST_INDEX                         0x80000

// Masks for the constant offset compensation
//#define FPGA_CONFIG_SHIFT_CONST_VAL                                0
//#define FPGA_CONFIG_SHIFT_CONST_SIGN                              16
//#define FPGA_CONFIG_MASK_CONST_SIGN                          0x10000

// Masks for the enable register
//#define FPGA_CONFIG_MASK_CTRL_EN                                0x01
//#define FPGA_CONFIG_MASK_TEMP_EN                                0x02
//#define FPGA_CONFIG_MASK_DIST_CORR_EN                           0x04
//#define FPGA_CONFIG_MASK_CONST_EN                               0x08
//#define FPGA_CONFIG_MASK_ADC_UNDER_EN                           0x10
//#define FPGA_CONFIG_MASK_ADC_OVER_EN                            0x20
//#define FPGA_CONFIG_MASK_GRAYSCALE_COMPENSATION_EN            0x2000

#define FPGA_CONFIG_MASK_INTERFERENCE                     0xFFFF0000
#define FPGA_CONFIG_SHIFT_INTERFERENCE                            16
#define FPGA_CONFIG_MASK_DISTANCE_RANGE                   0x0000FFFF
#define FPGA_CONFIG_SHIFT_DISTANCE_RANGE                           0

// debug unit
#define FPGA_DEBUG_SHIFT_PIXEL_INDEX                         15
#define FPGA_DEBUG_MASK_ENA                                  0x01



///Union for the enable register
typedef union
{
  uint32_t registerValue;
  struct
  {
    uint32_t enabled:1;
    uint32_t preCorrectionOffsetEnabled:1;
    uint32_t distanceCorrectionEnabled:1;
    uint32_t postCorrectionOffsetEnabled:1;
    uint32_t adcUnderflowEnabled:1;
    uint32_t adcOverflowEnabled:1;
    uint32_t grayscaleSubtractEnabled:1;
    uint32_t imageBinningEnabled:1;
    uint32_t ambientCorrectionEnabled:1;
	  uint32_t badpixelCorrectionDCSEnabled:1;
	  uint32_t badpixelCorrectionDistEnabled:1;
	  uint32_t RemoveSatEnabled:1;
	  uint32_t ADCInterEnabled:1;
    uint32_t grayscaleCompensationEnabled:1;
	  uint32_t reserved:18;
  }bits;
}fpgaEnableRegister_u;

///Union for the Full ROI register
typedef union
{
  uint32_t registerValue;
  struct
  {
    uint32_t width:9;
    uint32_t height:8;
    uint32_t reserved:15;
  }bits;
}fpgaFullRoi_u;

///Union for the current ROI settings
typedef union
{
  uint32_t registerValue;
  struct
  {
    uint32_t x_TL:9;
    uint32_t x_BR:9;
    uint32_t y_TL:7;
    uint32_t y_BR:7;
  }bits;
}fpgaRoi_u;

///Struct for the debug register
typedef struct
{
  uint32_t dcsRaw0;
  uint32_t dcsRaw1;
  uint32_t dcsRaw2;
  uint32_t dcsRaw3;
  uint32_t dcsAmb0;
  uint32_t dcsAmb1;
  uint32_t reserved0[2]; //8Bytes unused
  uint32_t distRaw;
  uint32_t distComp;
  uint32_t reserved1[2]; //8Bytes unused
  uint32_t gsRaw;
  uint32_t gsComp;
}fpgaDebug_t;

///Union for the DMA status register
typedef union
{
  uint32_t registerValue;
  struct
  {
    uint32_t dcsReady:1;
    uint32_t dcsBusy:1;
    uint32_t dcsDone:1;
    uint32_t reserved0:1;
    uint32_t gsRdy:1;
    uint32_t gsBusy:1;
    uint32_t gsDone:1;
    uint32_t reserved1:5;
    uint32_t dcsWrEofDone:1;
    uint32_t gsWrEofDone:1;
    uint32_t reserved2:18;
  }bits;
}fpgaDmaStatus_u;

#endif /* DRIVERS_FPGA_CTRL_H_ */

/** @} */
