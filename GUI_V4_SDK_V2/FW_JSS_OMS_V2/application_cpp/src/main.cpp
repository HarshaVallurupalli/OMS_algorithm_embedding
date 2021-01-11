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
static int8_t HardwareInit(void)
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

	i2c_IF &i2c = i2cInstance::getInstance();
	i2c.init();
	}

return 0;
}

/**
 * @brief Camera Init function
 *
 * This function initializes the I2C,camera power and SERDES link before operation of camera.
 */
static int8_t CameraInit(uint8_t daughter_board_port)
{
	//Enable the power of the OMS based on camera selected
	IO_IF &io = IO::getInstance();
	io.PoweronDaughterBoardPort(daughter_board_port);

	//Config the serDes here based on camera selected. Later no new configuration is done
	i2c_IF &i2c = i2cInstance::getInstance();
	SerDes serdes(i2c);
	int8_t status = serdes.connect(daughter_board_port);

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
	int8_t status = HardwareInit();
   	if (status < 0)
	{
		TRACE("init failed\n");
		while(1);
	}

	//camera specific initializations
	status = CameraInit(CAM1);
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

	TofCamStateMachine stateMachine;
	while (1)
	{
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
