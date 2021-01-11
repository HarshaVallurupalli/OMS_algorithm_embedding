/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @addtogroup led
 */
#include <Led/Led.h>
#include "IoExpander/IoExpanderInstance.h"


void Led::setPattern(const uint8_t pattern)
{
  IoExpander ioExpander = IoExpanderInstance::getInstance();

  ioExpander.setLedPattern(pattern);
}

/** @} */
