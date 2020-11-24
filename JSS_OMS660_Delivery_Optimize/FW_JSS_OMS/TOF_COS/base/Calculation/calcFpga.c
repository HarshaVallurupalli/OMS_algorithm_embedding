#include "calcFpga.h"
#include "drivers/fpga_ctrl.h"

/**
 * @brief Check if pixel has ADC overflow
 *
 * The adc overflow bit is masked from the FPGA result. The
 * FPGA makes the or for the four dcs.
 */
bool calcFpgaIsAdcOverflow(const uint32_t value)
{
	bool adcOverflow = (value & FPGA_RESULT_MASK_ADC_OVERFLOW);
	return adcOverflow;
}

/**
 * @brief Check if pixel is saturated
 *
 * The saturation bit is masked from the FPGA result. The
 * FPGA makes the or for the four saturation flags
 */
bool calcFpgaIsSaturated(const uint32_t value)
{
	bool saturated = (value & FPGA_RESULT_MASK_CHIP_SATURATION);
	return saturated;
}

/**
 * @brief Check if pixel is interfered
 *
 *
 */
bool calcFpgaIsInterfered(const uint32_t value)
{
	bool interfered = (value & FPGA_RESULT_MASK_INTERFERENCE);
	return interfered;
}

/**
 * @brief Calculate amplitude during normal operation
 *
 * Masks out the amplitude from the result received from the FPGA.
 *
 * @param value 32Bit value belonging to this pixel received from the FPGA
 * @return amplitude
 */
uint32_t calcFpgaAmplitude(const uint32_t value)
{
	uint32_t amplitude = ((value >> FPGA_RESULT_SHIFT_AMPLITUDE) & FPGA_RESULT_MASK_AMPLITUDE);
	return amplitude;
}

/**
 * @brief Calculate distance during normal operation
 *
 * Masks out the distance from the result received from the FPGA.
 *
 * @param value 32Bit value belonging to this pixel received from the FPGA
 * @return distance
 */
uint32_t calcFpgaDistanceNormal(const uint32_t value)
{
  uint32_t distance = ((value >> FPGA_RESULT_SHIFT_DISTANCE) & FPGA_RESULT_MASK_DISTANCE_NORMAL);
  return distance;
}

/**
 * @brief Calculate distance during calibration
 *
 * Masks out the distance from the result received from the FPGA.
 *
 * @param value 32Bit value belonging to this pixel received from the FPGA
 * @return distance
 */
uint32_t calcFpgaDistanceCalibration(const uint32_t value)
{
  uint32_t distance = ((value >> FPGA_RESULT_SHIFT_DISTANCE) & FPGA_RESULT_MASK_DISTANCE_CALIBRATION);
  return distance;
}
