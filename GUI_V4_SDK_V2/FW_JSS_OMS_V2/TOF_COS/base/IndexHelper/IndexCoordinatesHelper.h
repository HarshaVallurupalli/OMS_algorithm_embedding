/*
 * IndexCoordinatesHelper.h
 *
 *  Created on: 03.06.2019
 *      Author: mwi
 */

#ifndef INDEX_COORDINATES_HELPER_H_
#define INDEX_COORDINATES_HELPER_H_

#include <stdint.h>

class IndexCoordinatesHelper
{
	public:
		static void indexToCoordinates(const uint32_t index, uint32_t width, uint32_t height, uint32_t &x, uint32_t &y);
};

#endif /* INDEX_COORDINATES_HELPER_H_ */
