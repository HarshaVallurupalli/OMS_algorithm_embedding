/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup sequencer_programmer
 *
 * @{
 */
#include "SequencerProgrammer.h"
#include "seq_prog_type.h" ///include this before "seq_prog_list.h"
#include "seq_prog_list.h"
#include <stdlib.h>
#include <stdio.h>
#include "tof_cos_i2c.h"
#include "tof_cos_sys_timer.h"

SequencerProgrammer::SequencerProgrammer()
{

}

int32_t SequencerProgrammer::parseValues(uint8_t *pDest, const int32_t maxValues, const char *line)
{
	unsigned int value;
	int numValue = 0;
	char *pAct = (char *) line;

	for (int i = 0; i < maxValues; i++)
	{
		int num = sscanf(pAct, "%x", &value);

		if (num > 0)
		{
			pDest[numValue] = value;
			numValue++;
			while ((*pAct != ' ') && (*pAct != 0))
			{
				pAct++;
			}
			if (*pAct == ' ')
			{
				pAct++;
			}
			else
			{
				break;
			}
		}
	}
  return numValue;
}

TypeInternalReturnValue SequencerProgrammer::program(const uint16_t deviceAddress)
{
	TypeInternalReturnValue result = TypeInternalReturnValue::STATUS_OK;

	unsigned char valueList[16];

	//Get the number of entries
	int numEntry = sizeof(sequenceList) / sizeof(sequenceEntry_t);

	for (int i = 0; i < numEntry; i++)
	{
		int numValue = parseValues(valueList, sizeof(valueList), sequenceList[i].text);

    //There must be at least 2 values: A register address and a value to write
		if (numValue >= 2)
		{
			//value[0] is the register address, value[1] ... is the data
			unsigned char registerAddress = valueList[0];
		  unsigned int bytesToWrite = numValue - 1; //Because one value is the registerAddress

		  //Write it to the chip
			int32_t status = tofCosI2cWriteBuffer(deviceAddress, registerAddress, bytesToWrite, &valueList[1]);
		  if (status != 0)
		  {
		  	result = TypeInternalReturnValue::STATUS_ERROR_GENERAL;
		  	break;
		  }

		  //Do this delay for systems with a SerDes system. On other systems this would not be needed but id does not matter
		  tofCosSysTimerBlockingDelay(10);
		}
	}

	return result;
}

/** @} */
