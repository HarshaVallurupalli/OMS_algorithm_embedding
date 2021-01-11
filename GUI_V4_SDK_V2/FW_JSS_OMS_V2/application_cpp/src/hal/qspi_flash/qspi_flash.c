/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup qspi_flash
 */
#include "qspi_flash.h"
#include "xparameters.h"
#include "xil_printf.h"
#include <string.h>
#include <stdlib.h>
#include "xqspips_hw.h"
#include "xqspips.h"

/*
 * The following constants map to the XPAR parameters created in the
 * xparameters.h file. They are defined here, so that they could be easily changed.
 */
#define QSPI_DEVICE_ID		XPAR_XQSPIPS_0_DEVICE_ID

/*
 * Identification of Flash
 * Spansion:
 * Byte 0 is Manufacturer ID;
 * Byte 1 is Device ID - Memory Interface type - 0x20 or 0x02
 * Byte 2 is second byte of Device ID describes flash size:
 * 128Mbit : 0x18; 256Mbit : 0x19; 512Mbit : 0x20
 */

#define SPANSION_ID		                0x01

#define FLASH_SIZE_ID_128M		        0x18


/*
 * Size in bytes
 */
#define FLASH_SIZE_128M			0x1000000


/*
 * The following constants define the commands which may be sent to the FLASH
 * device.
 */
#define WRITE_STATUS_CMD	0x01
#define WRITE_CMD		      0x02
#define READ_CMD		      0x03
#define WRITE_DISABLE_CMD	0x04
#define READ_STATUS_CMD		0x05
#define WRITE_ENABLE_CMD	0x06
#define FAST_READ_CMD		  0x0B
#define DUAL_READ_CMD		  0x3B
#define QUAD_READ_CMD		  0x6B
#define BULK_ERASE_CMD		0xC7
#define	SEC_ERASE_CMD		  0xD8
#define READ_ID_CMD			  0x9F

/*
 * The following constants define the offsets within a FlashBuffer data
 * type for each kind of data.  Note that the read data offset is not the
 * same as the write data because the QSPI driver is designed to allow full
 * duplex transfers such that the number of bytes received is the number
 * sent and received.
 */
#define COMMAND_OFFSET		0 /* FLASH instruction */
#define ADDRESS_1_OFFSET	1 /* MSB byte of address to read or write */
#define ADDRESS_2_OFFSET	2 /* Middle byte of address to read or write */
#define ADDRESS_3_OFFSET	3 /* LSB byte of address to read or write */
#define DATA_OFFSET		    4 /* Start of Data for Read/Write */
#define DUMMY_OFFSET		  4 /* Dummy byte offset for fast, dual and quad reads */
#define DUMMY_SIZE		    1 /* Number of dummy bytes for fast, dual and quad reads */
#define RD_ID_SIZE		    4 /* Read ID command + 3 bytes ID response */
#define BULK_ERASE_SIZE		1 /* Bulk Erase command size */
#define SEC_ERASE_SIZE		4 /* Sector Erase command + Sector address */


/*
 * The following constants specify the extra bytes which are sent to the
 * FLASH on the QSPI interface, that are not data, but control information
 * which includes the command and address
 */
#define OVERHEAD_SIZE		  4

/*
 * The following defines are for dual flash interface.
 */
#define LQSPI_CR_FAST_QUAD_READ		0x0000006B /* Fast Quad Read output */
#define LQSPI_CR_1_DUMMY_BYTE		  0x00000100 /* 1 Dummy Byte between address and return data */

#define SINGLE_QSPI_CONFIG_QUAD_READ	(XQSPIPS_LQSPI_CR_LINEAR_MASK | \
					 LQSPI_CR_1_DUMMY_BYTE | \
					 LQSPI_CR_FAST_QUAD_READ)


/** Prototypes **/
static int8_t checkDevice(void);

/** Variables **/
static XQspiPs qspiInstance;           ///<Instance of the HAL driver
static XQspiPs *qspiInstancePtr;       ///<Pointer to the instance
static uint32_t qspiFlashSize;         ///<Stores the flash size
static uint32_t flashReadBaseAddress;  ///<Flash base address for linear reading
static const uint32_t pageSize = 256;  ///<This (const) variable contains the page size. Programming can only be done in pieces of this size.


/**
 * @brief Initialization
 *
 * This function initializes the controller for the QSPI interface.
 *
 * @param	None
 *
 * @retval STATUS_QSPI_FLASH_ERROR Initialization failed
 * @retval STATUS_QSPI_FLASH_OK Initialization successful
 * @return	Result of the initialization
 */
int8_t qspiFlashInit(void)
{
	XQspiPs_Config *QspiConfig;
	int32_t Status;

	qspiInstancePtr = &qspiInstance;

	/*
	 * Set up the base address for access
	 */
	flashReadBaseAddress = XPS_QSPI_LINEAR_BASEADDR;

	/*
	 * Initialize the QSPI driver so that it's ready to use
	 */
	QspiConfig = XQspiPs_LookupConfig(QSPI_DEVICE_ID);
	if (NULL == QspiConfig)
	{
		return STATUS_QSPI_FLASH_ERROR;
	}

	Status = XQspiPs_CfgInitialize(qspiInstancePtr, QspiConfig, QspiConfig->BaseAddress);
	if (Status != XST_SUCCESS)
	{
		return STATUS_QSPI_FLASH_ERROR;
	}

	/*
	 * Perform a self-test to check hardware build
	 */
	Status = XQspiPs_SelfTest(qspiInstancePtr);
	if (Status != XST_SUCCESS)
	{
		return STATUS_QSPI_FLASH_ERROR;
	}

	/*
	 * Set Manual Chip select options and drive HOLD_B pin high.
	 */
	XQspiPs_SetOptions(qspiInstancePtr, XQSPIPS_FORCE_SSELECT_OPTION | XQSPIPS_HOLD_B_DRIVE_OPTION);

	/*
	 * Set the prescaler for QSPI clock
	 */
	XQspiPs_SetClkPrescaler(qspiInstancePtr, XQSPIPS_CLK_PRESCALE_8);

	/*
	 * Assert the FLASH chip select.
	 */
	XQspiPs_SetSlaveSelect(qspiInstancePtr);

	/*
	 * Check for correct device
	 */
	Status = checkDevice();
	if (Status != STATUS_QSPI_FLASH_OK)
	{
		return STATUS_QSPI_FLASH_ERROR;
	}

	/*
	 * Single linear read
	 */
	XQspiPs_SetLqspiConfigReg(qspiInstancePtr, SINGLE_QSPI_CONFIG_QUAD_READ);

	/*
	 * Enable the controller
	 */
	XQspiPs_Enable(qspiInstancePtr);

	return STATUS_QSPI_FLASH_OK;
}

/**
 * @brief Check correct device
 *
 * This function reads serial FLASH ID connected to the SPI interface and checks for manufacturer
 * and size.
 *
 * @param	none
 *
 * @retval STATUS_QSPI_FLASH_ERROR Wrong device or other error
 * @retval STATUS_QSPI_FLASH_OK Correct device and working
 * @return	Result of the device check
 */
static int8_t checkDevice(void)
{
	uint8_t ReadBuffer[RD_ID_SIZE];
	uint8_t WriteBuffer[OVERHEAD_SIZE];
	uint32_t Status;

	/*
	 * Read ID in Auto mode.
	 */
	WriteBuffer[COMMAND_OFFSET] = READ_ID_CMD;
	WriteBuffer[ADDRESS_1_OFFSET] = 0x00; /* 3 dummy bytes */
	WriteBuffer[ADDRESS_2_OFFSET] = 0x00;
	WriteBuffer[ADDRESS_3_OFFSET] = 0x00;

	Status = XQspiPs_PolledTransfer(qspiInstancePtr, WriteBuffer, ReadBuffer, RD_ID_SIZE);
	if (Status != XST_SUCCESS)
	{
		return STATUS_QSPI_FLASH_ERROR;
	}

	/*
	 * Check manufacturer. This hal driver is only for one specific flash.
	 */
  if (ReadBuffer[1] != SPANSION_ID)
	{
		return STATUS_QSPI_FLASH_ERROR;
	}

	/*
	 * Get the flash size.
	 */
	if (ReadBuffer[3] != FLASH_SIZE_ID_128M)
	{
		return STATUS_QSPI_FLASH_ERROR;
	}

	qspiFlashSize = FLASH_SIZE_128M;


	return STATUS_QSPI_FLASH_OK;
}

/**
 * @brief Read data from the serial flash
 *
 * This function reads from the serial flash connected to the
 * QSPI interface. It reads it in linear mode.
 *
 * @param	address Contains the address to read data from in the FLASH.
 * @param readBuffer Pointer to the buffer, where the data from the flash has to be written to
 * @param	byteCount Contains the number of bytes to read.
 *
 * @retval STATUS_QSPI_FLASH_ERROR Read failed
 * @retval STATUS_QSPI_FLASH_OK Read successful
 * @return Result of the flash read
 */
int8_t qspiFlashRead(const uint32_t address, uint8_t *readBuffer, const uint32_t byteCount)
{
	/*
	 * Read from the flash in LQSPI mode.
	 */
	XQspiPs_SetOptions(qspiInstancePtr, XQSPIPS_LQSPI_MODE_OPTION |
	XQSPIPS_HOLD_B_DRIVE_OPTION);

	int32_t status = XQspiPs_LqspiRead(qspiInstancePtr, readBuffer, address, byteCount);

	if (status != XST_SUCCESS)
	{
		return STATUS_QSPI_FLASH_ERROR;
	}

	return STATUS_QSPI_FLASH_OK;
}

/**
 * @brief Erase the whole flash
 *
 * This function erases the whole flash using bulk erase command
 *
 * @param	None
 *
 * @retval STATUS_QSPI_FLASH_ERROR Erase failed
 * @retval STATUS_QSPI_FLASH_OK Erase successful
 * @return	Result of the erase procedure
 *
 */
int8_t qspiFlashBulkErase(void)
{
	int32_t status = 0;
	uint8_t WriteEnableCmd = { WRITE_ENABLE_CMD };
	uint8_t ReadStatusCmd[] = { READ_STATUS_CMD, 0 }; /* must send 2 bytes */
	uint8_t FlashStatus[2];
	uint8_t writeBuffer[OVERHEAD_SIZE];

	/*
	 * Set Manual Start and Manual Chip select options and drive the
	 * HOLD_B high.
	 */
	 XQspiPs_SetOptions(qspiInstancePtr, XQSPIPS_FORCE_SSELECT_OPTION |
						     XQSPIPS_MANUAL_START_OPTION |
						     XQSPIPS_HOLD_B_DRIVE_OPTION);

	/*
	 * Send the write enable command to the FLASH so that it can be
	 * written to, this needs to be sent as a seperate transfer
	 * before the erase
	 */
	status = XQspiPs_PolledTransfer(qspiInstancePtr, &WriteEnableCmd, NULL, sizeof(WriteEnableCmd));
	if (status != XST_SUCCESS)
	{
	  return STATUS_QSPI_FLASH_ERROR;
	}

	/*
	 * Setup the bulk erase command
	 */
	writeBuffer[COMMAND_OFFSET] = BULK_ERASE_CMD;

	/*
	 * Send the bulk erase command; no receive buffer is specified
	 * since there is nothing to receive
	 */
	status = XQspiPs_PolledTransfer(qspiInstancePtr, writeBuffer, NULL, BULK_ERASE_SIZE);
	if (status != XST_SUCCESS)
	{
	  return STATUS_QSPI_FLASH_ERROR;
	}

	/*
	 * Wait for the erase command to the FLASH to be completed
	 */
	while (1)
	{
		/*
		 * Poll the status register of the device to determine
		 * when it completes, by sending a read status command
		 * and receiving the status byte
		 */
		status = XQspiPs_PolledTransfer(qspiInstancePtr, ReadStatusCmd, FlashStatus, sizeof(ReadStatusCmd));
		if (status != XST_SUCCESS)
		{
		  return STATUS_QSPI_FLASH_ERROR;
		}

		/*
		 * If the status indicates the write is done, then stop
		 * waiting; if a value of 0xFF in the status byte is
		 * read from the device and this loop never exits, the
		 * device slave select is possibly incorrect such that
		 * the device status is not being read
		 */
		if ((FlashStatus[1] & 0x01) == 0)
		{
			break;
		}
	}

	return STATUS_QSPI_FLASH_OK;
}

/**
 * @brief Write one page into the flash
 *
 *
 * @param	address Contains the address to write data to in the FLASH.
 * @param writeBuffer Pointer to the source buffer with the data
 * @param	byteCount Contains the number of bytes to write, maximum one page
 *
 * @retval STATUS_QSPI_FLASH_ERROR Write failed
 * @retval STATUS_QSPI_FLASH_OK Write successful
 * @return	Result of the write procedure
 */
static int8_t writePage(const uint32_t address, const uint8_t *data, const uint32_t byteCount)
{
	int32_t status = STATUS_QSPI_FLASH_OK;
	uint8_t WriteEnableCmd = { WRITE_ENABLE_CMD };
	uint8_t ReadStatusCmd[] = { READ_STATUS_CMD, 0 }; /* must send 2 bytes */
	uint8_t FlashStatus[2];
	uint32_t bytesToSend = byteCount + OVERHEAD_SIZE;

  /*
	 * Create a temporary buffer. This is needed, because at the beginning (before the bytes to send) the command bytes for the flash are required. Otherwise the
	 * HAL library must be changed to do that in a layer below.
	 */
  uint8_t tempBuffer[bytesToSend];


	/*
	 * Set Manual Start and Manual Chip select options and drive the
	 * HOLD_B high.
	 */
	XQspiPs_SetOptions(qspiInstancePtr, XQSPIPS_FORCE_SSELECT_OPTION |
	XQSPIPS_MANUAL_START_OPTION |
	XQSPIPS_HOLD_B_DRIVE_OPTION);

  /*
	 * Setup the write command with the specified address and data for the
	 * FLASH
	 */
	tempBuffer[COMMAND_OFFSET] = WRITE_CMD;
	tempBuffer[ADDRESS_1_OFFSET] = (uint8_t)((address & 0xFF0000) >> 16);
	tempBuffer[ADDRESS_2_OFFSET] = (uint8_t)((address & 0xFF00) >> 8);
	tempBuffer[ADDRESS_3_OFFSET] = (uint8_t)(address & 0xFF);

	memcpy(&tempBuffer[OVERHEAD_SIZE], data, byteCount);

	/*
	 * Send the write enable command to the FLASH so that it can be
	 * written to, this needs to be sent as a separate transfer before
	 * the write
	 */
  status = XQspiPs_PolledTransfer(qspiInstancePtr, &WriteEnableCmd, NULL, sizeof(WriteEnableCmd));
  if (status != XST_SUCCESS)
  {
  	return STATUS_QSPI_FLASH_ERROR;
  }

	/*
	 * Send the write command, address, and data to the FLASH to be
	 * written, no receive buffer is specified since there is nothing to
	 * receive
	 */
  status = XQspiPs_PolledTransfer(qspiInstancePtr, tempBuffer, NULL, bytesToSend);
  if (status != XST_SUCCESS)
  {
    return STATUS_QSPI_FLASH_ERROR;
  }

	/*
	 * Wait for the write command to the FLASH to be completed, it takes
	 * some time for the data to be written
	 */
  while (1)
	{
	 /*
		* Poll the status register of the FLASH to determine when it
		* completes, by sending a read status command and receiving the
		* status byte
		*/
  	status = XQspiPs_PolledTransfer(qspiInstancePtr, ReadStatusCmd, FlashStatus, sizeof(ReadStatusCmd));
  	if (status != XST_SUCCESS)
  	{
  	  return STATUS_QSPI_FLASH_ERROR;
  	}

	 /*
		* If the status indicates the write is done, then stop waiting,
		* if a value of 0xFF in the status byte is read from the
		* device and this loop never exits, the device slave select is
		* possibly incorrect such that the device status is not being
		* read
		*/
    if ((FlashStatus[1] & 0x01) == 0)
		{
		  break;
		}
	}

  return STATUS_QSPI_FLASH_OK;
}


/**
 * @brief Write data into the flash
 *
 * This function writes to the serial FLASH connected to the QSPI interface.
 * The data is divided in pages and written to the flash.
 *
 * @param	address Contains the address to write data to in the FLASH.
 * @param writeBuffer Pointer to the source buffer with the data
 * @param	byteCount Contains the number of bytes to write.
 *
 * @retval STATUS_QSPI_FLASH_ERROR Write failed
 * @retval STATUS_QSPI_FLASH_OK Write successful
 * @return	Result of the write procedure
 */
int8_t qspiFlashWrite(const uint32_t address, const uint8_t *writeBuffer, const uint32_t byteCount)
{
	int8_t status = STATUS_QSPI_FLASH_OK;;
	int32_t bytesToSend = 0;
	uint32_t remainingBytes = byteCount;
	uint32_t actAddress = address;

	uint32_t index = 0;
	while(remainingBytes > 0)
	{
		if (remainingBytes < pageSize)
		{
			bytesToSend = remainingBytes;
		}
		else
		{
			bytesToSend = pageSize;
		}

		status = writePage(actAddress, &writeBuffer[index], bytesToSend);
		if (status != STATUS_QSPI_FLASH_OK)
		{
			/*Write page failed, exit here ------------------------------------->*/
			break;
		}

		index += bytesToSend;
		remainingBytes -= bytesToSend;
		actAddress += bytesToSend;
	}

	return status;
}

/** @} */
