#include "TraceLogger.h"
#include "interface/interface.h"

TraceLogger::TraceLogger()
{
  traceWriteFunction = nullptr;
  messageNumber = 0;
}

TraceLogger::~TraceLogger()
{

}

void TraceLogger::print(const char *format, ...)
{
	va_list args;
	unsigned char buffer[256];

	va_start(args, format);
	(void)vsnprintf((char *)buffer, sizeof(buffer), format, args);
	va_end(args);

	messages[inputIndex.getIndex()].print("%s", buffer);
	inputIndex.inc();
	messageNumber++;

	//Directly try to output the first message
	processOutput();
}

void TraceLogger::setOutputFunction(bool (*pWriteFunction)(const uint8_t *, const uint32_t))
{
	if (pWriteFunction == nullptr)
	{
		return;
	}

	traceWriteFunction = pWriteFunction;
}

void TraceLogger::processOutput()
{
  //No write function set, do nothing
	if (traceWriteFunction == nullptr)
  {
  	//return;
  }

	//If input and output index are the same, don't do anything
	if (inputIndex.getIndex() == outputIndex.getIndex())
  {
  	return;
  }

	bool sent = messages[outputIndex.getIndex()].output(traceWriteFunction);
	if (sent)
	{
		outputIndex.inc();
	}
}

