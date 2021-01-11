/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup ram_manager RAM manager
 * @ingroup tof_cos
 * @brief Manager for the RAM memory
 *
 * This module manages the RAM used for the data acquisition and the ressults. It
 * also handles the double buffering.
 *
 * @{
 */
#ifndef RAM_MANAGER_RAM_MANAGER_H_
#define RAM_MANAGER_RAM_MANAGER_H_

#include <stdint.h>
#include <stddef.h>
#include "ChipSelection.h"

class RamManager
{
	public:
		RamManager();

		void init(const uint32_t preBytes, const uint32_t postBytes, const uint16_t width, const uint16_t height);
		void setSize(const uint16_t width, const uint16_t height);
		void setupSorted();
		void setupUnsorted();

		void toggleOutputMemory();

		uint8_t *getDoubleBufferedResultMemory();
		uint8_t *getLastResultMemory();

		uint32_t *getResultMemory3d0();
		uint32_t *getResultMemory3d1();
		uint32_t *getResultMemoryGrayscale();

    uint32_t *getInputMemoryGrayscale();
	  uint32_t *getInputMemoryDCS();

	  uint32_t *getSgMemory3d0();
	  uint32_t *getSgMemory3d1();
	  uint32_t *getSgMemoryGrayscale();

    uint8_t *getOutputBuffer() const;
    uint32_t *getOutputBuffer_32Bit();

	private:
    static const uint32_t COMMUNICATION_OVERHEAD = 4096;

    //Double buffer 0 scatterGatter
    uint32_t sgBuffer3d0_0[EPC660::HEIGTH * 16] __attribute__ ((aligned (64)));                               ///Buffer for scatterGatter DMA for temporary 3D data 0 (for dual integration time)
    uint32_t sgBuffer3d1_0[EPC660::HEIGTH * 16] __attribute__ ((aligned (64)));                               ///Buffer for scatterGatter DMA for temporary 3D data 1 (for dual integration time)
    uint32_t sgBufferGrayscale0[EPC660::HEIGTH * 16] __attribute__ ((aligned (64)));                          ///Buffer for scatterGatter DMA for grayscale data

    //Double buffer 1 scatterGatter
    uint32_t sgBuffer3d0_1[EPC660::HEIGTH * 16] __attribute__ ((aligned (64)));                               ///Buffer for scatterGatter DMA for temporary 3D data 0 (for dual integration time)
    uint32_t sgBuffer3d1_1[EPC660::HEIGTH * 16] __attribute__ ((aligned (64)));                               ///Buffer for scatterGatter DMA for temporary 3D data 1 (for dual integration time)
    uint32_t sgBufferGrayscale1[EPC660::HEIGTH * 16] __attribute__ ((aligned (64)));                          ///Buffer for scatterGatter DMA for grayscale data

    uint32_t inputBufferDcs[EPC660::NUM_PIXEL]  __attribute__ ((aligned (64)));                               ///Buffer for the DCSs
    uint32_t inputBufferGrayscale[EPC660::NUM_PIXEL * 4]  __attribute__ ((aligned (64)));                     ///* 4 for raw DCS mode

    //Double buffer 0 output
    uint32_t outputBuffer0[EPC660::NUM_PIXEL * 2 + COMMUNICATION_OVERHEAD]  __attribute__ ((aligned (64)));   ///big enough to also store DCS data (*2 because it is 32Bit data, else *4 would be needed), in addition extra space for communication overhead

    //Double buffer 1 output
    uint32_t outputBuffer1[EPC660::NUM_PIXEL * 2 + COMMUNICATION_OVERHEAD]  __attribute__ ((aligned (64)));   ///big enough to also store DCS data (*2 because it is 32Bit data, else *4 would be needed), in addition extra space for communication overhea

    //Double buffer 0 3D/grayscale
    uint32_t resultBuffer3d0_0[EPC660::NUM_PIXEL]  __attribute__ ((aligned (64)));                            ///Temporary buffer for the 3d data integration time 0, no communication overhead
    uint32_t resultBuffer3d1_0[EPC660::NUM_PIXEL]  __attribute__ ((aligned (64)));                            ///Temporary buffer for the 3d data integration time 1, no communication overhead
    uint32_t resultBufferGrayscale0[EPC660::NUM_PIXEL]  __attribute__ ((aligned (64)));                       ///Temporary buffer for grayscale, no communication overhead

    //Double buffer 1 3D/grayscale
    uint32_t resultBuffer3d0_1[EPC660::NUM_PIXEL]  __attribute__ ((aligned (64)));                            ///Temporary buffer for the 3d data integration time 0, no communication overhead
    uint32_t resultBuffer3d1_1[EPC660::NUM_PIXEL]  __attribute__ ((aligned (64)));                            ///Temporary buffer for the 3d data integration time 1, no communication overhead
    uint32_t resultBufferGrayscale1[EPC660::NUM_PIXEL]  __attribute__ ((aligned (64)));                       ///Temporary buffer for grayscale, no communication overhead


    uint32_t *outputBuffer;                 ///<Output buffer for the interface including the interface overhead
    uint32_t *resultMemory0;                ///<Memory 0 for the result excluding the interface overhead
    uint32_t *resultMemory1;                ///<Memory 1 for the result excluding the interface overhead
    uint32_t *resultMemory;                 ///<Pointer to the actual result memory
    uint32_t *lastResultMemory;             ///<Pointer to the last result memory
    uint32_t *sgBuffer3d0;                  ///<Pointer to the actual SG buffer for 3D0
    uint32_t *sgBuffer3d1;                  ///<Pointer to the actual SG buffer for 3D1
    uint32_t *sgBufferGrayscale;            ///<Pointer to the actual SG buffer for grayscale
    uint32_t *resultBuffer3d0;              ///<Pointer to the actual result buffer for 3D0
    uint32_t *resultBuffer3d1;              ///<Pointer to the actual result buffer for 3D1
    uint32_t *resultBufferGrayscale;        ///<Pointer to the actual result buffer for grayscale

    uint32_t outputDoubleBufferingIndex;    ///<Index for double buffering for the output

    uint32_t startOffset;                   ///<Start offset for the measurement data. This helps so a header can be added before the measurement datan
    uint16_t width;                         ///<Image width
	  uint16_t height;                        ///<Image height
	  bool sorted;                            ///<true if the image is sorted
	
	  void initSGDescriptorsSorted(uint32_t * RamPtr, uint32_t * TargetPtr, const uint16_t height, const uint16_t width); ///<Create Descriptors for SG DMA
	  void initSGDescriptorsUnsorted(uint32_t * RamPtr, uint32_t * TargetPtr, const uint16_t height, const uint16_t width);
};

#endif /* RAM_MANAGER_RAM_MANAGER_H_ */

/** @} */
