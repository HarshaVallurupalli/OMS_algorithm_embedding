/**
 * Copyright (C) 2019 Espros Photonics Corporation
 *
 * @defgroup io_expander_instance Instance
 * @ingroup io_expander
 *
 * @brief Creates an instance of the IO expander and returns a reference to that
 *
 * @{
 */
#ifndef IO_EXPANDER_INSTANCE_H_
#define IO_EXPANDER_INSTANCE_H_

#include "IoExpander.h"

//! IO Expander Instance
/*!
 * Creates an instance of the IO expander and returns a reference to that
 */
class IoExpanderInstance
{
	public:
		static IoExpander &getInstance();
};

#endif /* IO_EXPANDER_INSTANCE_H_ */

/** @} */
