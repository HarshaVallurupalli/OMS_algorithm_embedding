#ifndef TRACE_TRACELOGGERINSTANCE_H_
#define TRACE_TRACELOGGERINSTANCE_H_

#include "TraceLogger.h"

class TraceLoggerInstance
{
	public:
		TraceLoggerInstance();
		virtual ~TraceLoggerInstance();

	  static TraceLogger *getInstance();
};

#endif /* TRACE_TRACELOGGERINSTANCE_H_ */
