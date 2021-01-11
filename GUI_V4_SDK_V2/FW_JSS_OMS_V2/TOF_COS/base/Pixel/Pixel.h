/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup pixel Pixel
 * @ingroup tof_cos
 *
 * @brief Represents one pixel of the ToF Imager
 *
 * @{
 */
#ifndef _PIXEL_H_
#define _PIXEL_H_

#include "TypePixelCode.h"
#include <stdint.h>

//! Pixel base class
/*!
 * Abstract, template class for pixels. Concrete pixel classes have to be created.
 */
template <class T>
class Pixel
{
	protected:
	  T pixel;

	public:
		Pixel();

		void setValue(const T value);
		bool getSaturated() const;
		bool getBadPixel() const;
};

#include <Pixel/Pixel.tpp> //Include this here at the end. Implementation of the template class.

#endif /* _PIXEL_H_ */

/** @} */
