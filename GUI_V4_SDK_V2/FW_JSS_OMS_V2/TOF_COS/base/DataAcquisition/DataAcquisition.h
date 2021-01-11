/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup data_acquisition Data Acquisition
 * @ingroup tof_cos
 *
 * @brief Class to acquire the data from the tof imager
 *
 * @{
 */
#ifndef DATA_ACQUISITION_H_
#define DATA_ACQUISITION_H_

#include <stdint.h>
#include "TypeInternalReturnValue.h"
#include "TOF_COS_Context.h"
#include "AcquisitionInfo/AcquisitionInfo.h"
#include "fpga.h"

///Enum defining the state of the IRQ state machine
enum DataAcquisitionState_e
{
	DATA_ACQUISITION_STATE_IDLE = 0,
	DATA_ACQUISITION_STATE_3D_GRAYSCALE,
	DATA_ACQUISITION_STATE_GRAYSCALE_ONLY,
	DATA_ACQUISITION_STATE_3D_FIRST_INTEGRATION_TIME,
	DATA_ACQUISITION_STATE_3D_SECOND_INTEGRATION_TIME,
	DATA_ACQUISITION_STATE_3D_ONLY,
	DATA_ACQUISITION_STATE_DCS_POLLING
};

///Enum defining the currently acquired data
enum DataAcquisitionData_e
{
	DATA_ACQUISITION_DATA_NONE,
	DATA_ACQUISITION_DATA_DUAL_INTEGRATION_TIME,
	DATA_ACQUISITION_DATA_SINGLE_INTEGRATION_TIME,
	DATA_ACQUISITION_DATA_GRAYSCALE,
	DATA_ACQUISITION_DATA_DCS
};

//! Responsible to acquire the data from the tof imager
/*!
 * This class offers the functionality to acquire the data from the tof imager.
 */
class DataAcquisition
{
	public:
		DataAcquisition(TOF_COS_Context *context);
		TypeInternalReturnValue init();

		void startGrayscaleImage();
		void start3dGrayscaleImage(const bool dualIntegrationTime);
		void start3dImageForCalibration();
		void startDcs(const bool omitChipConfig);

		bool isFinished();
		TypeInternalReturnValue waitBlocking();
		bool hasAcquired(const DataAcquisitionData_e data);
		void clear();

		void get3dData(uint32_t **data);
		void get3dDataTemporalHdr(uint32_t **data0, uint32_t **data1);
		void getGrayscaleData(uint32_t **data);
		void getDcsData(uint32_t **data);

		AcquisitionInfo getAcquisitionInfo() const;

		TypeInternalReturnValue getAndClearStatus();

	protected:
		//These variables are used in the interrupt
		volatile uint32_t *memoryGrayscaleOrDcs;                      ///<Memory used for grayscale or DCS data: Normally grayscale data. In case of DCS only readout it is used for the DCS data (but not processed by the soft logic)
		volatile uint32_t *memoryDcs;                                 ///<Memory for the DCS data in normal operation

		volatile uint32_t *memoryResultGrayscale;                     ///<Result memory for grayscale data
		volatile uint32_t *memoryResult3d0;                           ///<Result memory for 3D data (double buffer 0)
		volatile uint32_t *memoryResult3d1;                           ///<Result memory for 3D data (double buffer 1)

		volatile uint32_t *memorySgGrayscale;                         ///<Scatter Gatter DMA memory for grayscale
		volatile uint32_t *memorySg3d0;                               ///<Scatter Gatter DMA memory for 3D data 0
		volatile uint32_t *memorySg3d1;                               ///<Scatter Gatter DMA memory for 3D data 1

		static const uint32_t DCMI_TIMEOUT = 500;                     ///<Timeout in ms for DCMI acquisitions
		TypeInternalReturnValue status;                               ///<Variable containing the status of this class
		uint32_t timestampAtAcquisition;                              ///<Stores the timestamp of the last acquisition. Used to detect, if the last measurement is too old to use it for themporal filtering
		uint32_t timestampAtTemperatureMeasurement;                   ///<Stores the timestamp of the last temperature measurement. Used to detect, if the last measurement is too old to use it for the temporal filter
		volatile int8_t indexCompensation;                           ///<Stores the index of the compensation to use
		TOF_COS_Context *context;                                     ///<Pointer to the context

	private:
		static void interruptCallback(void *arg);
		void processInterrupt();
		bool dataIsTooOld(const uint32_t timestamp);
		void updateMetaData();
		void updatePointers();
		void updateAcquisitionSettings(const uint32_t bytesPerPixel);
		void setupGrayscaleAmbientLightCompensationSettings();

		volatile DataAcquisitionState_e state;                        ///<Current state of the IRQ state machine
		volatile DataAcquisitionData_e data;                          ///<Current acquired data
		volatile bool dualIntegrationTime;                            ///<true in case of dual integration time
		volatile bool temperatureCompensationEnabled;                 ///<true if temperature compensation is enabled
		volatile bool doTemperatureFilter;                            ///<true if the temperature should be filtered
		AcquisitionInfo acquisitionInfo;                              ///<Stores the information about the last acquisition
    volatile fpgaAcquisitionSettings_t fpgaAcquisitionSettings;   ///<Stores the acquisition settings for the FPGA soft logic

		const uint32_t MAX_VALID_DATA_TIME = 500;                     ///<[ms] Time the data acquired in the background by the DMA is valid. After this time, the data is not used.
};

#endif /* DATA_ACQUISITION_H_ */

/** @} */
