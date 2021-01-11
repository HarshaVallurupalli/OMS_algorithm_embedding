################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/TOF_COS/base/PointCloud/PointCloudToFAmplitude.cpp \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/TOF_COS/base/PointCloud/PointCloudToFDistAmpl.cpp \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/TOF_COS/base/PointCloud/PointCloudToFDistance.cpp \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/TOF_COS/base/PointCloud/PointCloudToFGrayscale.cpp 

OBJS += \
./TOF_COS/base/PointCloud/PointCloudToFAmplitude.o \
./TOF_COS/base/PointCloud/PointCloudToFDistAmpl.o \
./TOF_COS/base/PointCloud/PointCloudToFDistance.o \
./TOF_COS/base/PointCloud/PointCloudToFGrayscale.o 

CPP_DEPS += \
./TOF_COS/base/PointCloud/PointCloudToFAmplitude.d \
./TOF_COS/base/PointCloud/PointCloudToFDistAmpl.d \
./TOF_COS/base/PointCloud/PointCloudToFDistance.d \
./TOF_COS/base/PointCloud/PointCloudToFGrayscale.d 


# Each subdirectory must supply rules for building sources it contributes
TOF_COS/base/PointCloud/PointCloudToFAmplitude.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/TOF_COS/base/PointCloud/PointCloudToFAmplitude.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/PointCloud/PointCloudToFDistAmpl.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/TOF_COS/base/PointCloud/PointCloudToFDistAmpl.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/PointCloud/PointCloudToFDistance.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/TOF_COS/base/PointCloud/PointCloudToFDistance.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/PointCloud/PointCloudToFGrayscale.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/TOF_COS/base/PointCloud/PointCloudToFGrayscale.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


