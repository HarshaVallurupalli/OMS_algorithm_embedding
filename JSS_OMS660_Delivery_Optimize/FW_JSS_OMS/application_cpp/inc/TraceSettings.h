#ifndef TRACESETTINGS_H_
#define TRACESETTINGS_H_

///If trace is desired, set to 1
#define TRACE_ENABLED 1

#if (TRACE_ENABLED==1)
  #include "trace/TraceLoggerInstance.h"
  #define TRACE(...) TraceLoggerInstance::getInstance()->print(__VA_ARGS__)
#else
  #define TRACE(...)
#endif


#endif /* TRACESETTINGS_H_ */
