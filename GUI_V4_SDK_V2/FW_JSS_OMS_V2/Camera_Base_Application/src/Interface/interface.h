/**
 * Copyright (C) 2016 Espros Photonics Corporation
 *
 * @defgroup interface Interface
 *
 * @brief Access to the interface
 *
 * @{
 */
#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <stdint.h>
#include <stdbool.h>
#include "Communication/Answer.h"
#include "SharedTypes.h"

///Return values
enum TypeInterfaceResult
{
	INTERFACE_RESULT_OK = 0,
	INTERFACE_RESULT_ERROR
};

//! Interface
/*!
 *  Interface class to communicate with the host.
 */
class Interface
{
	public:
		Interface();
		TypeInterfaceResult sendAnswer(Answer &answer, uint32_t destIp, bool sendTcpAnswer);
		TypeInterfaceResult init(const ipAddress_t ip, const ipAddress_t subnet, uint8_t macLastNumber);
		TypeInterfaceResult initDefault();
    void process(void);
    bool isBusy(void);
    bool cmdInterfaceIsBusy();

	private:
    bool initialized;
};

#endif /* INTERFACE_H_ */

/** @} */
