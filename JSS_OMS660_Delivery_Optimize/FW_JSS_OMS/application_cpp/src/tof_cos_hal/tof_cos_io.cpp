#include <hal/i2c/i2cInstance.h>
#include "tof_cos_io.h"
#include "hal/IO_IF.h"
#include "hal/IO/IO.h"
#include <sleep.h>
#include "TraceSettings.h"

IO_IF &io = IO::getInstance();
i2c_IF &i2c = i2cInstance::getInstance();


void tofCosIoResetEpcChip()
{
	i2c.ioExpanderWriteRegister(20, 0x40, 0);
	usleep(100000);
	i2c.ioExpanderWriteRegister(20, 0x40, 1);
	usleep(100000);
	i2c.ioExpanderWriteRegister(20, 0x40, 0);
	usleep(100000);
}

void tofCosIoSetIlluminationEnabled(const bool enabled)
{
  if (enabled)
  {
  	i2c.ioExpanderWriteRegister(20, 0x80, 1);
  	//i2c.ioExpanderWriteRegister(20, 0x04, 1);
  }
  else
  {
  	i2c.ioExpanderWriteRegister(20, 0x80, 0);
  	//i2c.ioExpanderWriteRegister(20, 0x04, 0);
  }
}

void tofCosIoArmExternalShutter()
{
  //Not available here
}

void tofCosIoDisarmExternalShutter()
{
  //Not available here
}

void tofCosIoDisableCalibrationLight()
{
  //Special trace message so the GUI switches off the illumination
  TRACE("{0");
  usleep(2000000);
}

void tofCosIoEnableCalibrationLight()
{
  //Special trace message so the GUI switches on the illumination
  TRACE("{1");
  usleep(2000000);
}



