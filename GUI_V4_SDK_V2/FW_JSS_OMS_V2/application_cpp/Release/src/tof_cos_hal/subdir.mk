################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/tof_cos_hal/tof_cos_calibration_memory.cpp \
../src/tof_cos_hal/tof_cos_clock_generator.cpp \
../src/tof_cos_hal/tof_cos_cpu.cpp \
../src/tof_cos_hal/tof_cos_i2c.cpp \
../src/tof_cos_hal/tof_cos_io.cpp \
../src/tof_cos_hal/tof_cos_sys_timer.cpp \
../src/tof_cos_hal/tof_cos_timestamp.cpp 

OBJS += \
./src/tof_cos_hal/tof_cos_calibration_memory.o \
./src/tof_cos_hal/tof_cos_clock_generator.o \
./src/tof_cos_hal/tof_cos_cpu.o \
./src/tof_cos_hal/tof_cos_i2c.o \
./src/tof_cos_hal/tof_cos_io.o \
./src/tof_cos_hal/tof_cos_sys_timer.o \
./src/tof_cos_hal/tof_cos_timestamp.o 

CPP_DEPS += \
./src/tof_cos_hal/tof_cos_calibration_memory.d \
./src/tof_cos_hal/tof_cos_clock_generator.d \
./src/tof_cos_hal/tof_cos_cpu.d \
./src/tof_cos_hal/tof_cos_i2c.d \
./src/tof_cos_hal/tof_cos_io.d \
./src/tof_cos_hal/tof_cos_sys_timer.d \
./src/tof_cos_hal/tof_cos_timestamp.d 


# Each subdirectory must supply rules for building sources it contributes
src/tof_cos_hal/%.o: ../src/tof_cos_hal/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


