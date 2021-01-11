################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/base/PointCloud/PointCloudToFDistAmpl.cpp \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/base/PointCloud/PointCloudToFDistance.cpp \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/base/PointCloud/PointCloudToFGrayscale.cpp 

OBJS += \
./ToFAPI/base/PointCloud/PointCloudToFDistAmpl.o \
./ToFAPI/base/PointCloud/PointCloudToFDistance.o \
./ToFAPI/base/PointCloud/PointCloudToFGrayscale.o 

CPP_DEPS += \
./ToFAPI/base/PointCloud/PointCloudToFDistAmpl.d \
./ToFAPI/base/PointCloud/PointCloudToFDistance.d \
./ToFAPI/base/PointCloud/PointCloudToFGrayscale.d 


# Each subdirectory must supply rules for building sources it contributes
ToFAPI/base/PointCloud/PointCloudToFDistAmpl.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/base/PointCloud/PointCloudToFDistAmpl.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -I../../standalone_bsp_0/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ToFAPI/base/PointCloud/PointCloudToFDistance.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/base/PointCloud/PointCloudToFDistance.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -I../../standalone_bsp_0/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ToFAPI/base/PointCloud/PointCloudToFGrayscale.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/base/PointCloud/PointCloudToFGrayscale.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -I../../standalone_bsp_0/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


