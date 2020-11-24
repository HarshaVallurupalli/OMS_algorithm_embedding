/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 *
 * @addtogroup ram_manager
 *
 * @{
 */
#include "RamManager.h"
#include "xil_cache.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Constructor
 *
 */
RamManager::RamManager()
{
  outputBuffer = nullptr;
  resultMemory0 = nullptr;
  resultMemory1 = nullptr;
  resultMemory = nullptr;
  lastResultMemory = nullptr;
  sgBuffer3d0 = nullptr;
  sgBuffer3d1 = nullptr;

  outputDoubleBufferingIndex = 0;
  startOffset = 0;
  height = 0;
  width = 0;
  sorted = true;
}

/**
 * @brief Init
 *
 * Call this before using this class. The image size and the pre and post bytes are configured.
 *
 * Pre bytes: Some bytes left empty in front of the image data
 * Post bytes: Some bytes left empty after the image data
 *
 * @param preBytes Number of pre bytes
 * @param postBytes Number of post bytes
 * @param width Image width
 * @param height Image height
 */
void RamManager::init(const uint32_t preBytes, const uint32_t postBytes, const uint16_t width, const uint16_t height)
{
	this->startOffset = preBytes;
	this->height = height;
	this->width = width;
	this->outputDoubleBufferingIndex = 0;

	this->outputBuffer = this->outputBuffer0;
	this->resultMemory0 = &(this->outputBuffer0[startOffset/4]); //StartOffset is in Bytes
	this->resultMemory1 = &(this->outputBuffer1[startOffset/4]); //StartOffset is in Bytes
	this->resultMemory = this->resultMemory0;
	this->lastResultMemory = this->resultMemory1;
	this->sgBuffer3d0 = this->sgBuffer3d0_0;
	this->sgBuffer3d1 = this->sgBuffer3d1_0;
	this->sgBufferGrayscale = this->sgBufferGrayscale0;
	this->resultBuffer3d0 = this->resultBuffer3d0_0;
	this->resultBuffer3d1 = this->resultBuffer3d1_0;
	this->resultBufferGrayscale = this->resultBufferGrayscale0;

	setupSorted();
}

/**
 * @brief Set size
 *
 * Needed if the ROI changes.
 *
 * @param width Image width
 * @param height Image height
 */
void RamManager::setSize(const uint16_t width, const uint16_t height)
{
  uint16_t currentWidth = this->width;
  uint16_t currentHeight = this->height;
	this->width = width;
  this->height = height;

  if ((currentWidth != width) || (currentHeight != height))
  {
  	if (sorted)
  	{
      setupSorted();
  	}
  	else
  	{
  	  setupUnsorted();
  	}
  }
}

/**
 * @brief Prepare for sorted images
 *
 * This function must be called to prepare for sorted images. This is the normal operation situation.
 */
void RamManager::setupSorted()
{
  // Init SG DMA Descriptors
	initSGDescriptorsSorted(this->sgBuffer3d0_0, this->resultBuffer3d0_0, height, width);
	initSGDescriptorsSorted(this->sgBuffer3d1_0, this->resultBuffer3d1_0, height, width);
	initSGDescriptorsSorted(this->sgBufferGrayscale0, this->resultBufferGrayscale0, height, width);

	initSGDescriptorsSorted(this->sgBuffer3d0_1, this->resultBuffer3d0_1, height, width);
	initSGDescriptorsSorted(this->sgBuffer3d1_1, this->resultBuffer3d1_1, height, width);
	initSGDescriptorsSorted(this->sgBufferGrayscale1, this->resultBufferGrayscale1, height, width);

	sorted = true;
}

/**
 * @brief Prepare for unsorted images
 *
 * This function must be called to prepare for unsorted images. This is used during calibration.
 */
void RamManager::setupUnsorted()
{
	// Init SG DMA Descriptors
	initSGDescriptorsUnsorted(this->sgBuffer3d0_0, this->resultBuffer3d0_0, height, width);
	initSGDescriptorsUnsorted(this->sgBuffer3d1_0, this->resultBuffer3d1_0, height, width);
	initSGDescriptorsUnsorted(this->sgBufferGrayscale0, this->resultBufferGrayscale0, height, width);

	initSGDescriptorsUnsorted(this->sgBuffer3d0_1, this->resultBuffer3d0_1, height, width);
	initSGDescriptorsUnsorted(this->sgBuffer3d1_1, this->resultBuffer3d1_1, height, width);
	initSGDescriptorsUnsorted(this->sgBufferGrayscale1, this->resultBufferGrayscale1, height, width);

	sorted = false;
}

/**
 * @brief Toggle the double buffer
 *
 * This function is called to toggle between the two double buffers.
 */
void RamManager::toggleOutputMemory()
{
  if (outputDoubleBufferingIndex == 0)
  {
  	outputDoubleBufferingIndex = 1;
  	outputBuffer = this->outputBuffer1;
  	resultMemory = this->resultMemory1;
  	lastResultMemory = this->resultMemory0;
  	sgBuffer3d0 = this->sgBuffer3d0_1;
  	sgBuffer3d1 = this->sgBuffer3d1_1;
  	sgBufferGrayscale = this->sgBufferGrayscale1;
  	resultBuffer3d0 = this->resultBuffer3d0_1;
  	resultBuffer3d1 = this->resultBuffer3d1_1;
  	resultBufferGrayscale = this->resultBufferGrayscale1;
  }
  else
  {
  	outputDoubleBufferingIndex = 0;
  	outputBuffer = this->outputBuffer0;
  	resultMemory = this->resultMemory0;
  	lastResultMemory = this->resultMemory1;
  	sgBuffer3d0 = this->sgBuffer3d0_0;
  	sgBuffer3d1 = this->sgBuffer3d1_0;
  	sgBufferGrayscale = this->sgBufferGrayscale0;
  	resultBuffer3d0 = this->resultBuffer3d0_0;
    resultBuffer3d1 = this->resultBuffer3d1_0;
  	resultBufferGrayscale = this->resultBufferGrayscale0;
  }
}

/**
 * @brief Get output buffer
 *
 * This function returns the output buffer. This is the buffer including the bytes for the
 * interface (pre and post bytes)
 *
 * @return Memory for the output buffer
 */
uint8_t *RamManager::getOutputBuffer() const
{
	return reinterpret_cast<uint8_t *>(outputBuffer);
}

uint8_t *RamManager::getDoubleBufferedResultMemory()
{
	return reinterpret_cast<uint8_t *>(resultMemory);
}

uint8_t *RamManager::getLastResultMemory()
{
	return reinterpret_cast<uint8_t *>(lastResultMemory);
}

uint32_t *RamManager::getInputMemoryGrayscale()
{
	return inputBufferGrayscale;
}

uint32_t *RamManager::getInputMemoryDCS()
{
	return inputBufferDcs;
}

uint32_t *RamManager::getSgMemory3d0()
{
	return sgBuffer3d0;
}

uint32_t *RamManager::getSgMemory3d1()
{
	return sgBuffer3d1;
}

uint32_t *RamManager::getSgMemoryGrayscale()
{
	return sgBufferGrayscale;
}

uint32_t *RamManager::getResultMemory3d0()
{
	return resultBuffer3d0;
}

uint32_t *RamManager::getResultMemory3d1()
{
	return resultBuffer3d1;
}

uint32_t *RamManager::getResultMemoryGrayscale()
{
	return resultBufferGrayscale;
}

/**
 * @brief Get the memory for a 32Bit output
 *
 * This function returns the memory for the 32Bit output.
 *
 * @return Memory for the 32Bit output
 */
uint32_t *RamManager::getOutputBuffer_32Bit()
{
	return outputBuffer0;
}

/**
 * @brief Init the scatter gather descriptors
 *
 * This function inits the scatter gather descriptors for a SORTED result.
 *
 * @param RamPtr Pointer to descriptor memory
 * @param TargetPtr Pointer to target memory
 * @param height Height of the image
 * @param width Width of the image
 */
void RamManager::initSGDescriptorsSorted(uint32_t * RamPtr, uint32_t * TargetPtr, const uint16_t height, const uint16_t width)
{
   int firstline = (height)/2-1; // 119 for 240pix

	// Init Ram to 0
	memset(RamPtr, 0, (height)*8*2*4);
	Xil_DCacheFlushRange((UINTPTR) RamPtr, (height)*8*2*4);

	for (uint16_t i = 0; i < height; i++)
	{
		if (i==height-1)
		{
			RamPtr[2*8*i]   = (uint32_t)&RamPtr[0];                                                                       // Next Descriptor
		}
		else
		{
			RamPtr[2*8*i]   = (uint32_t)&RamPtr[2*8*(i + 1)];                                                             // Next Descriptor
		}
		RamPtr[2*8*i+2] = (uint32_t)&TargetPtr[(firstline+(int)pow((double)-1,i-1)*(int)floor((double)i/2.0+0.5))*width]; // Buffer Address (where to start writting)
		RamPtr[2*8*i+6] = width*4;                                                                              // Control; b27: SOF, b26: EOF, 22:0: #Data to transfer
	}

	Xil_DCacheFlushRange((UINTPTR) RamPtr, (height)*8*2*4);	
}

/**
 * @brief Init the scatter gather descriptors
 *
 * This function inits the scatter gather descriptors for a UNSORTED result.
 *
 * @param RamPtr Pointer to descriptor memory
 * @param TargetPtr Pointer to target memory
 * @param height Height of the image
 * @param width Width of the image
 */
void RamManager::initSGDescriptorsUnsorted(uint32_t * RamPtr, uint32_t * TargetPtr, const uint16_t height, const uint16_t width)
{
	int firstline = (height)/2-1; // 119 for 240pix

	// Init Ram to 0
	memset(RamPtr, 0, (height)*8*2*4);
	Xil_DCacheFlushRange((UINTPTR) RamPtr, (height)*8*2*4);

	for (uint16_t i = 0; i < height; i++)
	{
		if (i==height-1)
		{
			RamPtr[2*8*i]   = (uint32_t)&RamPtr[0];                                                                       // Next Descriptor
		}
		else
		{
			RamPtr[2*8*i]   = (uint32_t)&RamPtr[2*8*(i + 1)];                                                             // Next Descriptor
		}
		RamPtr[2*8*i+2] = (uint32_t)&TargetPtr[i*width]; // Buffer Address (where to start writting)
		RamPtr[2*8*i+6] = width*4;                                                                              // Control; b27: SOF, b26: EOF, 22:0: #Data to transfer
	}

	Xil_DCacheFlushRange((UINTPTR) RamPtr, (height)*8*2*4);
}

/** @} */
