################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/Camera_Base_Application/src/DataTypes/CmdProcessorAnswer.cpp \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/Camera_Base_Application/src/DataTypes/CmdProcessorJob.cpp \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/Camera_Base_Application/src/DataTypes/UserData.cpp 

OBJS += \
./Camera_Base_Application/src/DataTypes/CmdProcessorAnswer.o \
./Camera_Base_Application/src/DataTypes/CmdProcessorJob.o \
./Camera_Base_Application/src/DataTypes/UserData.o 

CPP_DEPS += \
./Camera_Base_Application/src/DataTypes/CmdProcessorAnswer.d \
./Camera_Base_Application/src/DataTypes/CmdProcessorJob.d \
./Camera_Base_Application/src/DataTypes/UserData.d 


# Each subdirectory must supply rules for building sources it contributes
Camera_Base_Application/src/DataTypes/CmdProcessorAnswer.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/Camera_Base_Application/src/DataTypes/CmdProcessorAnswer.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Camera_Base_Application/src/DataTypes/CmdProcessorJob.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/Camera_Base_Application/src/DataTypes/CmdProcessorJob.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Camera_Base_Application/src/DataTypes/UserData.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/Camera_Base_Application/src/DataTypes/UserData.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


