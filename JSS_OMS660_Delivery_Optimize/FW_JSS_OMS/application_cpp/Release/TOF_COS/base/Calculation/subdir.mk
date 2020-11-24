################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/calcFpga.c 

CPP_SRCS += \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/Algorithm.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/Calculation.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/CalculationParameters.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/Filter.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/Iterator.cpp 

OBJS += \
./TOF_COS/base/Calculation/Algorithm.o \
./TOF_COS/base/Calculation/Calculation.o \
./TOF_COS/base/Calculation/CalculationParameters.o \
./TOF_COS/base/Calculation/Filter.o \
./TOF_COS/base/Calculation/Iterator.o \
./TOF_COS/base/Calculation/calcFpga.o 

C_DEPS += \
./TOF_COS/base/Calculation/calcFpga.d 

CPP_DEPS += \
./TOF_COS/base/Calculation/Algorithm.d \
./TOF_COS/base/Calculation/Calculation.d \
./TOF_COS/base/Calculation/CalculationParameters.d \
./TOF_COS/base/Calculation/Filter.d \
./TOF_COS/base/Calculation/Iterator.d 


# Each subdirectory must supply rules for building sources it contributes
TOF_COS/base/Calculation/Algorithm.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/Algorithm.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calculation/Calculation.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/Calculation.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calculation/CalculationParameters.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/CalculationParameters.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calculation/Filter.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/Filter.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calculation/Iterator.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/Iterator.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calculation/calcFpga.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calculation/calcFpga.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


