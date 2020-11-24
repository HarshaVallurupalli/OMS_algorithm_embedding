#ifndef TRACE_TRACELOGGER_H_
#define TRACE_TRACELOGGER_H_

#include <stdint.h>
#include "TraceMessage.h"

static const uint32_t numMessage = 10;

class TraceLoggerIndex
{
	public:
		TraceLoggerIndex()
	  {
	    index = 0;
	  }

		void inc()
		{
			index++;
			if (index >= numMessage)
			{
				index = 0;
			}
		}

		uint32_t getIndex()
		{
			return index;
		}

	private:
		uint32_t index;
};

class TraceLogger
{
	public:
		TraceLogger();
		virtual ~TraceLogger();
		void print(const char *format, ...);
		void processOutput();
		void setOutputFunction(bool (*pWriteFunction)(const uint8_t *, const uint32_t));

	private:
		bool (*traceWriteFunction)(const uint8_t *, const uint32_t);
    TraceMessage messages[numMessage];
    TraceLoggerIndex inputIndex;
    TraceLoggerIndex outputIndex;
    uint32_t messageNumber;
};

#endif /* TRACE_TRACELOGGER_H_ */
