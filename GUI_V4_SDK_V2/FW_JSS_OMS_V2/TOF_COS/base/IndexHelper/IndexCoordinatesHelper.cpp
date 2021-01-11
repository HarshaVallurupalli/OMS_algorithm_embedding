/*
 * IndexCoordinatesHelper.cpp
 *
 *  Created on: 03.06.2019
 *      Author: mwi
 */

#include <IndexHelper/IndexCoordinatesHelper.h>

void IndexCoordinatesHelper::indexToCoordinates(const uint32_t index, uint32_t width, uint32_t height, uint32_t &x, uint32_t &y)
{
	y = index / width;
  x = index % width;
}
