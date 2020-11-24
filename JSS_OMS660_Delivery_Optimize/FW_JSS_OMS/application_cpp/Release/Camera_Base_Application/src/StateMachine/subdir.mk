################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/Camera_Base_Application/src/StateMachine/StateMachineContext.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/Camera_Base_Application/src/StateMachine/TofCamState.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/Camera_Base_Application/src/StateMachine/TofCamStateMachine.cpp 

OBJS += \
./Camera_Base_Application/src/StateMachine/StateMachineContext.o \
./Camera_Base_Application/src/StateMachine/TofCamState.o \
./Camera_Base_Application/src/StateMachine/TofCamStateMachine.o 

CPP_DEPS += \
./Camera_Base_Application/src/StateMachine/StateMachineContext.d \
./Camera_Base_Application/src/StateMachine/TofCamState.d \
./Camera_Base_Application/src/StateMachine/TofCamStateMachine.d 


# Each subdirectory must supply rules for building sources it contributes
Camera_Base_Application/src/StateMachine/StateMachineContext.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/Camera_Base_Application/src/StateMachine/StateMachineContext.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Camera_Base_Application/src/StateMachine/TofCamState.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/Camera_Base_Application/src/StateMachine/TofCamState.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Camera_Base_Application/src/StateMachine/TofCamStateMachine.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/Camera_Base_Application/src/StateMachine/TofCamStateMachine.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

