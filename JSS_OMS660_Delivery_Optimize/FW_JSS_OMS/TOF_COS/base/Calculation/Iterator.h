/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @defgroup iterator Iterator
 * @ingroup calculation
 * @brief Helper class to do the pixel sorting
 *
 * @{
 */
#ifndef ITERATOR_H_
#define ITERATOR_H_

#include <stdint.h>
#include <stdbool.h>

struct Position
{
	uint16_t x;
	uint8_t y;
	uint32_t indexMemory;
	uint32_t indexSorted;
};

class Iterator
{
  public:
	  Iterator();
	  void init(uint32_t numberOfPixelsPerDCS, uint16_t width, uint8_t height);
    uint32_t getNext();

  private:
    uint32_t index;
    uint32_t nPxDcs;
    uint16_t h;
    uint16_t w;
    uint32_t x;
    uint32_t y;
};

#endif /* ITERATOR_H_ */

/** @} */
