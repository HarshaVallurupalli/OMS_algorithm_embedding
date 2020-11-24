#include "InterfaceInstance.h"

static Interface interface;

InterfaceInstance::InterfaceInstance()
{
}

Interface &InterfaceInstance::getInstance()
{
	return interface;
}
