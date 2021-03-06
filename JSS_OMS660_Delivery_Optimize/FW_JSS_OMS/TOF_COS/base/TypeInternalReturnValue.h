/**
 * Copyright (C) 2017 Espros Photonics Corporation
 *
 * @defgroup type_internal_return_value Internal return value
 * @brief Return values for the classes in the TOF_COS
 * @ingroup tof_cos
 *
 * @{
 */
#ifndef TYPE_INTERNAL_RETURN_VALUE_H_
#define TYPE_INTERNAL_RETURN_VALUE_H_

enum TypeInternalReturnValue
{
	STATUS_OK = 0,
	STATUS_ERROR_GENERAL,
	STATUS_ERROR_TEMPERATURE_DIFFERENCE_TOO_HIGH,
	STATUS_ERROR_DEVICE_NOT_PRESENT,
	STATUS_ERROR_COMMUNICATION,
	STATUS_ERROR_DCMI,
	STATUS_ERROR_FLASH_MEMORY,
	STATUS_ERROR_FLASH_WRITE,
	STATUS_ERROR_NOT_INITIALIZED,
	STATUS_ERROR_FLASH_NOT_ERASED,
	STATUS_ERROR_TEMPERATURE_TOO_HIGH,
	STATUS_ERROR_TEMPERATURE_TOO_LOW,
	STATUS_ERROR_COMPENSATION,
	STATUS_ERROR_CLOCK_GENERATOR,
	STATUS_ERROR_INTEGRATION_TIME
};

#endif /* TYPE_INTERNAL_RETURN_VALUE_H_ */

/** @} */
