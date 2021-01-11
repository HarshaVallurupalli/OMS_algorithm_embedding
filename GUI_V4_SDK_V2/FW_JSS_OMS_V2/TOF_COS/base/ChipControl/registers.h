/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup registers Registers
 * @ingroup chip_control
 *
 * @brief Defines for the registers of the TOF imager.
 *
 * @{
 */

#ifndef REGISTERS_H
#define REGISTERS_H

/*** Registers ***/
#define IC_TYPE 0x00
#define IC_VERSION 0x01

#define EE_PAGE 0x10
#define EE_ADDR 0x11
#define EE_DATA 0x12

#define MT_0_HI 0x22
#define MT_0_MI 0x23
#define MT_0_LO 0x24
#define MT_1_HI 0x25
#define MT_1_MI 0x26
#define MT_1_LO 0x27
#define MT_2_HI 0x28
#define MT_2_MI 0x29
#define MT_2_LO 0x2A
#define MT_3_HI 0x2B
#define MT_3_MI 0x2C
#define MT_3_LO 0x2D

#define GRAYSCALE_READOUT_MODE        0x3A
#define MODULATION_CONTROL_GRAYSCALE  0x3C

#define SR_ADDRESS 0x40
#define SR_PROGRAM 0x47

#define DLL_STATUS 0x70
#define DLL_FINE_CTRL_EXT_HI 0x71
#define DLL_FINE_CTRL_EXT_LO 0x72
#define DLL_COARSE_CTRL_EXT  0x73
#define DLL_FINE_LOW_BANK_RB_HI 0x74
#define DLL_FINE_LOW_BANK_RB_LO 0x75
#define DLL_FINE_BANK_RB_HI 0x76
#define DLL_FINE_BANK_RB_LO 0x77
#define DLL_FINE_PAGE_RB 0x78
#define DLL_COARSE_RB 0x79
#define DLL_TEST_MODE 0x7A


#define TEMP_TOP_LEFT_REGISTER_HIGH 0x60
#define TEMP_TOP_LEFT_REGISTER_LOW 0x61

#define TEMP_TOP_RIGHT_REGISTER_HIGH 0x62
#define TEMP_TOP_RIGHT_REGISTER_LOW 0x63

#define TEMP_BOTTOM_LEFT_REGISTER_HIGH 0x64
#define TEMP_BOTTOM_LEFT_REGISTER_LOW 0x65

#define TEMP_BOTTOM_RIGHT_REGISTER_HIGH 0x66
#define TEMP_BOTTOM_RIGHT_REGISTER_LOW 0x67


#define CFG_MODE_CONTROL 0x7D
#define CFG_MODE_STATUS 0x7E

#define CLK_ENABLES           0x80
#define PLL_PRE_POST_DIVIDERS 0x81
#define PLL_FB_DIVIDER        0x82
#define SYS_CLK_DIVIDER       0x83
#define DLL_CLK_DIVIDER       0x84
#define MOD_CLK_DIVIDER       0x85
#define SEQ_CLK_DIVIDER       0x86
#define REFGEN_CLK_DIVIDER    0x87
#define ISOURCE_CLK_DIVIDER   0x88
#define TCMI_CLK_DIVIDER      0x89

#define DEMODULATION_DELAYS 0x8B

#define PN_POLY_HI	0x8C
#define PN_POLY_LO	0x8D

#define LED_DRIVER  0x90
#define SEQ_CONTROL 0x91
#define RESOLUTION_REDUCTION 0x94

#define ROI_TL_X_HI 0x96
#define ROI_TL_X_LO 0x97
#define ROI_BR_X_HI 0x98
#define ROI_BR_X_LO 0x99
#define ROI_TL_Y    0x9A
#define ROI_BR_Y    0x9B

#define INT_LEN_MGX_HI 0x9E
#define INT_LEN_MGX_LO 0x9F
#define INTM_HI 0xA0
#define INTM_LO 0xA1
#define INT_LEN_HI 0xA2
#define INT_LEN_LO 0xA3
#define SHUTTER_CONTROL 0xA4
#define MOD_CONTROL 0x92
#define DLL_EN_DEL_HI 0xA6
#define DLL_EN_DEL_LO 0xA7
#define DLL_EN_HI 0xA8
#define DLL_EN_LO 0xA9
#define DLL_MEASUREMENT_RATE_HI 0xAA
#define DLL_MEASUREMENT_RATE_LO 0xAB
#define DLL_CONTROL 0xAE
#define DLL_FILTER 0xAC

#define I2C_TCMI_CONTROL 0xCB
#define TCMI_POLARITY 0xCC

#define TEMP_TL_CAL1 0xE8
#define TEMP_TL_CAL2 0xE9
#define TEMP_TR_CAL1 0xEA
#define TEMP_TR_CAL2 0xEB
#define TEMP_BL_CAL1 0xEC
#define TEMP_BL_CAL2 0xED
#define TEMP_BR_CAL1 0xEE
#define TEMP_BR_CAL2 0xEF

#define CUSTOMER_ID  0xF5
#define WAFER_ID_MSB 0xF6
#define WAFER_ID_LSB 0xF7
#define CHIP_ID_MSB  0xF8
#define CHIP_ID_LSB  0xF9
#define PART_TYPE    0xFA
#define PART_VERSION 0xFB

/*** Values for the registers ***/
const uint8_t VALUE_MODE_3D                  = 0x34;  ///<Value to set the chip to 3D mode, register 0x92
const uint8_t VALUE_MODE_GRAYSCALE           = 0xC4;  ///<Value for grayscale mode, register 0x92
const uint8_t VALUE_MODE_DUALMGX             = 0x14;  ///<Value to set the chip to DualMGX mode, register 0x92

/***  Masks for the registers  ***/
const uint8_t MASK_SHUTTER                   = 0x01;  ///<Mask for Shutter in register 0xA4
const uint8_t MASK_DLL_BYPASS                = 0x01;  ///<Mask for DLL bypass bit at register 0xAE
const uint8_t MASK_DLL_CTRL_EXT              = 0x04;  ///<Mask for DLL external control at register 0xAE
const uint8_t MASK_LED_2                     = 0x20;  ///<Mask for Led 2 pin at register 0x90
const uint8_t MASK_LED                       = 0x04;  ///<Mask for Led pin at register 0x90
const uint8_t MASK_LED_INVERTED              = 0x02;  ///<Mask for Led pins inverted at register 0x90
const uint8_t MASK_EXTERNAL_MODULATION_CLOCK = 0x40;  ///<Mask for external Clock bit at register 0x80
const uint8_t MASK_MODULATION_CLOCK          = 0x1F;  ///<Mask for Modulation clock at register 0x85
const uint8_t MASK_VERTICAL_BINNING          = 0x20;  ///<Mask for vertical Binning at register 0x94
const uint8_t MASK_HORIZONTAL_BINNING        = 0x10;  ///<Mask for horizontal Binning at register 0x94
const uint8_t MASK_ROW_REDUCTION             = 0x04;  ///<Mask for row reduction to half at register 0x94
const uint8_t MASK_COLUMN_REDUCTION          = 0x01;  ///<Mask for column reduction to half at register 0x94
const uint8_t MASK_DUAL_MGX                  = 0x80;  ///<Mask for dual mgx mode at register 0x94
const uint8_t MASK_HDR                       = 0x08;  ///<Mask for the HDR
const uint8_t MASK_ABS_ENABLED               = 0x30;  ///<Mask for ABS enabled
const uint8_t MASK_LED_OFF_GRAYSCALE         = 0x20;  ///<Mask for illumination off during grayscale acquisition
const uint8_t MASK_LED_ON_GRAYSCALE          = 0x10;  ///<Mask for illumination on during grayscale acquisition

#endif // REGISTERS_H

/** @} */
