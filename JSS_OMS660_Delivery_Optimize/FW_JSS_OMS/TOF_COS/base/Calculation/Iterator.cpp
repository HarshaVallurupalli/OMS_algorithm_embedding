/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 *
 * @addtogroup iterator
 *
 * @{
 */
#include "Iterator.h"

Iterator::Iterator()
{
  index = 0;
  nPxDcs = 0;
  h = 0;
  w = 0;
  x = 0;
  y = 0;
}

void Iterator::init(uint32_t numberOfPixelsPerDCS, uint16_t width, uint8_t height)
{
	nPxDcs = numberOfPixelsPerDCS;
	w = width;
	h = height;
	index = 0;
	x = 0;
	y = 0;
}

uint32_t Iterator::getNext()
{
	struct Position pos;
	if (x < w)
	{
		pos.x = x;
		pos.y = h / 2 - 1 - y;
	}
	else
	{
		pos.x = x - w;
		pos.y = h / 2 + y;
	}

	pos.indexMemory = index;
	pos.indexSorted = pos.y * w + pos.x;

	++x;
	if (x == 2 * w)
	{
		x = 0;
		++y;
	}
	++index;

	return pos.indexSorted;
}

/** @} */
