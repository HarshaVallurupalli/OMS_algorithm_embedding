/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup sequencer_programmer Sequencer Programmer
 * @ingroup tof_cos
 * @brief Class to reprogram the sequencer of the tof imager
 *
 * @{
 */
#ifndef CONFIG_SEQ_PROG_H_
#define CONFIG_SEQ_PROG_H_

#include <stdint.h>
#include "TypeInternalReturnValue.h"

//! Reprogram the sequencer of the TOF imager
/*!
 * To achieve a better performance, the sequencer program in the TOF imager can be reprogrammed. This class is
 * responsible to do this. It is done using a series of I2C commands.
 */
class SequencerProgrammer
{
	public:
		explicit SequencerProgrammer();
		TypeInternalReturnValue program(const uint16_t deviceAddress);

	private:
    int32_t parseValues(uint8_t *pDest, const int32_t maxValues, const char *line);
};


#endif /* CONFIG_SEQ_PROG_H_ */

/** @} */
