/***
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @addtogroup sd_card
 */
#include "xparameters.h"	/* SDK generated parameters */
#include "xsdps.h"		/* SD device driver */
#include "xil_printf.h"
#include "ff.h"
#include "xil_cache.h"
#include "xplatform_info.h"
#include <stdbool.h>
#include <stdio.h>
#include "sd_card.h"

//prototypes
static int init(void);
static const char *workingFolder = "TOFCam_660";

//global variables
static FATFS fatfs;
static bool cardAvailable = false;  ///<true, if a SD card is available


/**
 * @brief Write data to absolute path
 *
 * @param path Path where to write the data on the disk
 * @param data Data to write
 * @param size Size of the data to write
 */
static int8_t writeDataAbsolutePath(const char *path, const char *data, const uint32_t size)
{
  FIL file;

  int status = f_open(&file, path, FA_CREATE_ALWAYS | FA_WRITE | FA_READ);
  if (status != FR_OK)
  {
    return -1;
  }/** Cancel here ------------------------------------------> */
  f_lseek(&file, 0);
  unsigned int bytesWritten;
  f_write(&file, data, size, &bytesWritten);
  f_close(&file);

  return 0;
}

/**
 * @brief Write an update file
 *
 * This is the boot image created in the SDK. This offers an easy update system but without safety
 * in case of power fail during update. In that case the SD card needs to be removed and written in a computer.
 *
 * @param data Data to write
 * @param size Size of the data to write
 */
int8_t sdCardWriteDataWriteUpdateFile(const char *data, const uint32_t size)
{
  char tempPath[256];
  snprintf(tempPath, sizeof(tempPath), "%s", "BOOT.bin");

  int8_t status = writeDataAbsolutePath(tempPath, data, size);

  return status;
}

/**
 * @brief Write a file to the SD card
 *
 * Write a file to the SD card into the main folder of the camera, for example "TOFCam_660"
 *
 * @param name Name of the file to create
 * @param data Data to write
 * @param size Size of the data to write
 */
int8_t sdCardWriteData(const char *name, const char *data, const uint32_t size)
{
	//Just enough space
  char tempPath[256];
  snprintf(tempPath, sizeof(tempPath), "%s/%s", workingFolder, name);

  return writeDataAbsolutePath(tempPath, data, size);
}

/**
 * @brief Read a file from the SD card
 *
 * Write a file from the SD card from the main folder of the camera, for example "TOFCam_660"
 *
 * @param name Name of the file to read
 * @param data Pointer where the data can be copied
 * @param size Size of the data buffer = maximum possible data to read
 */
int8_t sdCardReadData(const char *name, char *data, const uint32_t size)
{
	FIL file;

	//Just enough space
  char tempPath[256];
  snprintf(tempPath, sizeof(tempPath), "%s/%s", workingFolder, name);

	int status = f_open(&file, tempPath,  FA_READ);
	if (status != FR_OK)
	{
		return -1;
	}/** Cancel here ------------------------------------------> */
	f_lseek(&file, 0);
	unsigned int bytesRead;
	f_read(&file, data, size, &bytesRead);
	f_close(&file);

	return 0;
}

/*
 * @brief Read if card is available
 *
 * Call this function before using the SD card.
 *
 * @retval true Card is available
 * @retval false No card available
 * @return Card available or not
 */
bool sdCardIsAvailable(void)
{
	return cardAvailable;
}

/*
 * @brief init function
 *
 * Call this function before using the sd card.
 *
 * @retval -1 Error
 * @retval 0 SD card ready to use
 * @return result
 */
int8_t sdCardInit(void)
{
	int32_t Status;

	Status = init();
	if (Status != XST_SUCCESS)
	{
		xil_printf("Error or no card present \r\n");
		return -1;
	}

	xil_printf("sd card mounted successfully \r\n");


	cardAvailable = true;

	return 0;
}

/*
 * @brief private init function
 *
 * Initialize the file system and check, if a card is present
 *
 * @retval XST_FAILURE Error
 * @retval XST_SUCCESS SD card ready to use
 * @return result
 */
static int init(void)
{
	FRESULT Res;
	/*
	 * To test logical drive 0, Path should be "0:/"
	 * For logical drive 1, Path should be "1:/"
	 */
	TCHAR *Path = "0:/";

	/*
	 * Register volume work area, initialize device
	 */
	Res = f_mount(&fatfs, Path, 0);

	if (Res != FR_OK)
	{
		return XST_FAILURE;
	}

	//Open directory to check, if a sd card is present. If there is no card, the f_opendir function needs too much time to do it later, so check it here
	DIR d;
	Res = f_opendir(&d, workingFolder);
	if (Res != 0)
	{
		return XST_FAILURE;
	}

	f_closedir(&d);

	return XST_SUCCESS;
}

/** @} */
