#include <GlobalSettings.h>
#include <hal/i2c/i2cInstance.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "StateMachine/TofCamStateMachine.h"
#include "Interface/InterfaceInstance.h"
#include "tcp_cmd_handler/tcp_cmd_handler.h"
#include "udp_transfer/udp_transfer.h"
#include "hal/cpu/cpu.h"
#include "hal/sd_card/sd_card.h"
#include "queue/queue_c.h"
#include "trace/TraceLoggerInstance.h"
#include "hal/qspi_flash/qspi_flash.h"
#include "SdCardManager/SdCardManager.h"
#include "xgpio.h"
#include "xparameters.h"
#include "hal/io/IO.h"
#include "SerDes/SerDes.h"
#include "IoExpander/IoExpander.h"

#include "Camera_number/Camera_number.h"

//#include <cstdint>


///Timer variable. Increments every millisecond from the IRQ
extern int32_t stateMachineTimerEvents;


/**
 * @brief System Init function
 *
 * This function initializes all the sub modules in the ECU that need to be initialized before operation.
 */
static int8_t init(void)
{
	SdCardManager sdCardManager;

	int8_t status = cpuInit();
	if (status < 0)
	{
	  TRACE("Failed to init cpu\n");
	  return -1;
	}

	status = queueInit();
	if (status < 0)
	{
		TRACE("Failed to init queue\n");
		return -1;
	}

	//Read the configuration from SD card
	sdCardManager.init();
	SdCardResult_e result = sdCardManager.readAll();

	//If there was a configuration on the SD card, use that one. Else just do a default init.
	if (result == SdCardResult_e::SD_CARD_MANAGER_RESULT_OK)
	{
    TypeInterfaceResult interfaceResult = InterfaceInstance::getInstance().init(sdCardManager.getIpAddress(), sdCardManager.getSubnetMask(), sdCardManager.getMacLastNumber());
		if (interfaceResult != TypeInterfaceResult::INTERFACE_RESULT_OK)
		{
		  TRACE("Failed to init interface\n");
			return -1;
		}
	}
	else
	{
	  TypeInterfaceResult interfaceResult = InterfaceInstance::getInstance().initDefault();
		if (interfaceResult != TypeInterfaceResult::INTERFACE_RESULT_OK)
		{
		  TRACE("Failed to init interface\n");
		  return -1;
		}
	}

return 0;
}

/**
 * @brief Camera Init function
 *
 * This function initializes the I2C,camera power and SERDES link before operation of camera.
 */
static int8_t init(uint8_t cam_num)
{

	i2c_IF &i2c = i2cInstance::getInstance();
	i2c.init();

	IO_IF &io = IO::getInstance();

	//Enable the power of the OMS based on camera select
	switch(cam_num)
	{


		case CAM1:
			{
				io.setPowerEnabled(false);
				usleep(100000);
				io.setPowerEnabled(true);
				usleep(100000);
				Xil_Out32 (0x41240000, 0x0);
				Xil_Out32 (0x41230000, 0x0);
				usleep(100000);
			}
		break;

		case CAM2:
			{
				io.setPowerEnabled(false);
				usleep(100000);
				io.setPowerEnabled(true);
				usleep(100000);
			Xil_Out32 (0x41240000, 0x0);
			Xil_Out32 (0x41230000, 0x1);
			usleep(100000);
			}
		break;

		case CAM3:
			{
				io.setPowerEnabled(false);
				usleep(100000);
				io.setPowerEnabled(true);
				usleep(100000);
				Xil_Out32 (0x41240000, 0x1);
				Xil_Out32 (0x41230000, 0x0);
				usleep(100000);
			}
		break;

		case CAM4:
			{
				io.setPowerEnabled(false);
				usleep(100000);
				io.setPowerEnabled(true);
				usleep(100000);
				Xil_Out32 (0x41240000, 0x1);
				Xil_Out32 (0x41230000, 0x1);
				usleep(100000);
			}
		break;

		default://enable cam1 in default case
			{
				io.setPowerEnabled(false);
				usleep(100000);
				io.setPowerEnabled(true);
				usleep(100000);
				Xil_Out32 (0x41240000, 0x0);
				Xil_Out32 (0x41230000, 0x0);
				usleep(100000);
			}
		break;
	}

	//Config the serDes here based on camera selected. Later no new configuration is done
	SerDes serdes(i2c);
	int8_t status = serdes.connect(cam_num);


	if (status < 0)
	{
		return status;
	}

	return 0;
}


/*
 * @brief Main function of the system
 *
 * @param argc unused
 * @param argv unused
 * @return 0
 */
//
int main(int argc __attribute__((unused)), char* argv[] __attribute__((unused)))
{
	//ECU specific initializations
	int8_t status = init();

	if (status < 0)
	{
		TRACE("init failed\n");
		while(1);
	}

	//camera specific initializations
	status = init(CAM1);

	if (status < 0)
	{
		TRACE("camera init failed\n");
		while(1);
	}
/*
  //Copy the calibration data, just for special version
	char buffer[(4 * 32) + 50 * 320 * 240 * sizeof(uint8_t)]; //memory size of calibration data
	qspiFlashInit();
	sdCardReadData("Calibration.dat", buffer, sizeof(buffer));
	qspiFlashBulkErase();
	qspiFlashWrite(0, (const uint8_t *)buffer, sizeof(buffer));
*/

	//qspiFlashInit();
	//qspiFlashBulkErase(); //test
	//while(1);

	Camera_number* camera_number = Camera_number::getInstance();

	TofCamStateMachine stateMachine;

	while (1)
	{
		uint8_t cam_old   =   camera_number->get_old_cam_num();
		uint8_t cam_new   =   camera_number->get_new_cam_num();

		//check if a different camera was selected at the GUI and initialize the selected camera
		if((cam_new) != (cam_old))
		{
			//status = init(camera_number->get_new_cam_num());
			int8_t status = init(CAM1);
			if (status < 0)
			{
				TRACE("camera init failed\n");
				while(1);
			}

			// restart the StateMachine in powerup state
			stateMachine.setGenerateEventDataAvailable(false);
			stateMachine.setGenerateEventDataSent(false);
			stateMachine.changeState(stateMachine.powerUpState);

			camera_number->set_old_cam_num(camera_number->get_new_cam_num());
		}

		InterfaceInstance::getInstance().process();
		stateMachine.task();



			//stateMachineTimerEvents is incremented in the IRQ. Feed in the value into the state machine
		if (stateMachineTimerEvents)
		{
		  stateMachine.timerTick(stateMachineTimerEvents);
		  stateMachineTimerEvents = 0;
		}

			TraceLoggerInstance::getInstance()->processOutput();
	}


	return 0;
}
