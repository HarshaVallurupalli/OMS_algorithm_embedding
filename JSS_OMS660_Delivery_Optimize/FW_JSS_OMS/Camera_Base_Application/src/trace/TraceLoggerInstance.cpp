#include "TraceLoggerInstance.h"



TraceLoggerInstance::TraceLoggerInstance()
{

}

TraceLoggerInstance::~TraceLoggerInstance()
{

}

TraceLogger *TraceLoggerInstance::getInstance()
{
	static TraceLogger traceLogger;
	return &traceLogger;
}

