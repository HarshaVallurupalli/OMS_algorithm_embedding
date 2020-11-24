#include "TraceMessage.h"
#include <string.h>
#include <xil_printf.h>
#include "tcp_trace_server/tcp_trace_server.h"

TraceMessage::TraceMessage()
{
  length = 0;
  memset(message, 0, maxMessageLength);
}

TraceMessage::~TraceMessage()
{
}

void TraceMessage::print(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	length = vsnprintf((char *)message, maxMessageLength, format, args);
	va_end(args);
}

bool TraceMessage::output(bool (*pWriteFunction)(const uint8_t *, const uint32_t))
{
  tcpTraceServerSend("%s", message);
	return true;
}

