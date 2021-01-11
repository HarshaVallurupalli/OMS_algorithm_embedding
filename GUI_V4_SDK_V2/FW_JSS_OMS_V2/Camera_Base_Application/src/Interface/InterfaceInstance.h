#ifndef INTERFACE_INSTANCE_H_
#define INTERFACE_INSTANCE_H_

#include "Interface.h"

class InterfaceInstance
{
	public:
		InterfaceInstance();
		static Interface &getInstance();
};

#endif /* INTERFACE_INSTANCE_H_ */
