################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/trace/TraceLogger.cpp \
../src/trace/TraceLoggerInstance.cpp \
../src/trace/TraceMessage.cpp 

OBJS += \
./src/trace/TraceLogger.o \
./src/trace/TraceLoggerInstance.o \
./src/trace/TraceMessage.o 

CPP_DEPS += \
./src/trace/TraceLogger.d \
./src/trace/TraceLoggerInstance.d \
./src/trace/TraceMessage.d 


# Each subdirectory must supply rules for building sources it contributes
src/trace/%.o: ../src/trace/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -I../../standalone_bsp_0/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


