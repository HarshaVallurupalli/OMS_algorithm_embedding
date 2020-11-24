/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup roi ROI (Region Of Interest)
 * @brief Handle the ROI settings
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef ROI_H_
#define ROI_H_

#include <stddef.h>
#include <stdint.h>

//! Handle the ROI settings
/*!
 * This struct is responsible to handle the ROI settings.
 */
#pragma pack(push,1)
struct Roi
{
	public:
		Roi();
	  Roi(const uint16_t xMin, const uint16_t yMin, const uint16_t width, const uint16_t height);
	  bool operator ==(const Roi& lhs);
	  Roi getSubRoi(const Roi &roi);

	  uint16_t xMin;			  //!< x min point of the ROI
	  uint16_t yMin;        //!< y min point of the ROI
	  uint16_t xMax;        //!< x max point of the ROI
	  uint16_t yMax;			  //!< y max point of the ROI

	  uint32_t getNumPixel() const;
		uint16_t getWidth() const;
	  uint16_t getHeight() const;
};
#pragma pack(pop)

#endif /* ROI_H_ */

/** @} */
