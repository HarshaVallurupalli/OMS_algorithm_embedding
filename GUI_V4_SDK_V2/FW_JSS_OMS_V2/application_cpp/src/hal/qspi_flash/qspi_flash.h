/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup qspi_flash QSPI Flash
 * @ingroup hal
 *
 * @brief HAL function to control the QSPI Flash
 *
 * This code bases on the examples of Xilinx, but it is limited to work only with the Spansion Flash, that
 * is on the microzed board. This makes it easier. If it should be extended to other manufacturer or sizes, the
 * code could be extended like in the example.
 *
 * @{
 */
#ifndef ___QSPI_FLASH_H___
#define ___QSPI_FLASH_H___

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

enum
{
	STATUS_QSPI_FLASH_OK = 0,
	STATUS_QSPI_FLASH_ERROR = -1
};

int8_t qspiFlashInit(void);
int8_t qspiFlashBulkErase(void);
int8_t qspiFlashWrite(const uint32_t address, const uint8_t *writeBuffer, const uint32_t byteCount);
int8_t qspiFlashRead(const uint32_t address, uint8_t *readBuffer, const uint32_t byteCount);


#ifdef __cplusplus
}
#endif


#endif /* ___QSPI_FLASH_H___ */

/** @} */
