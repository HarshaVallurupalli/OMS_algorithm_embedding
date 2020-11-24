/**
 * Copyright (C) 2018 Espros Photonics Corporation
 *
 * @defgroup hdr HDR
 * @brief Handle the hdr Settings
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef HDR_H_
#define HDR_H_

//! Handle the hdr settings
/*!
 * This class is responsible to handle the hdr settings.
 */
class Hdr
{
	public:
		enum HdrMode_e
		{
		  HDR_MODE_NONE = 0,
			HDR_MODE_SPATIAL = 1,
			HDR_MODE_TEMPORAL = 2
		};

		Hdr();
		Hdr(const Hdr::HdrMode_e hdr);
		bool isTemporalHdr() const;
		bool isSpatialHdr() const;
		Hdr &operator=(const Hdr::HdrMode_e hdr);
		Hdr::HdrMode_e getValue() const;

	private:
		HdrMode_e mode;
};

#endif /* HDR_H_ */

/** @} */
