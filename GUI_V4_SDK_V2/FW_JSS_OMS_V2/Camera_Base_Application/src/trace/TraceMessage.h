#ifndef TRACE_TRACEMESSAGE_H_
#define TRACE_TRACEMESSAGE_H_

#include <stdint.h>
#include <stdarg.h>
#include <stdio.h>

class TraceMessage
{
	public:
		TraceMessage();
		virtual ~TraceMessage();
		void print(const char *format, ...);
		bool output(bool (*pWriteFunction)(const uint8_t *, const uint32_t));

	private:
		static const uint32_t maxMessageLength = 128;
		uint32_t length;
		uint8_t message[maxMessageLength];
};

#endif /* TRACE_TRACEMESSAGE_H_ */
