################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/AmbientLightCalibrationDataHelper.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/AmbientLightCalibrationJob.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/Calibration_Calculation.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DelayHelper.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DrnuCalibration.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DrnuCalibrationDataHelper.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DrnuCalibrationInfoData.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DrnuCalibrationJob.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/GrayscaleCalibrationCalculation.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/GrayscaleCalibrationJob.cpp \
C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/IntegrationTimeFinder.cpp 

OBJS += \
./TOF_COS/base/Calibration/AmbientLightCalibrationDataHelper.o \
./TOF_COS/base/Calibration/AmbientLightCalibrationJob.o \
./TOF_COS/base/Calibration/Calibration_Calculation.o \
./TOF_COS/base/Calibration/DelayHelper.o \
./TOF_COS/base/Calibration/DrnuCalibration.o \
./TOF_COS/base/Calibration/DrnuCalibrationDataHelper.o \
./TOF_COS/base/Calibration/DrnuCalibrationInfoData.o \
./TOF_COS/base/Calibration/DrnuCalibrationJob.o \
./TOF_COS/base/Calibration/GrayscaleCalibrationCalculation.o \
./TOF_COS/base/Calibration/GrayscaleCalibrationJob.o \
./TOF_COS/base/Calibration/IntegrationTimeFinder.o 

CPP_DEPS += \
./TOF_COS/base/Calibration/AmbientLightCalibrationDataHelper.d \
./TOF_COS/base/Calibration/AmbientLightCalibrationJob.d \
./TOF_COS/base/Calibration/Calibration_Calculation.d \
./TOF_COS/base/Calibration/DelayHelper.d \
./TOF_COS/base/Calibration/DrnuCalibration.d \
./TOF_COS/base/Calibration/DrnuCalibrationDataHelper.d \
./TOF_COS/base/Calibration/DrnuCalibrationInfoData.d \
./TOF_COS/base/Calibration/DrnuCalibrationJob.d \
./TOF_COS/base/Calibration/GrayscaleCalibrationCalculation.d \
./TOF_COS/base/Calibration/GrayscaleCalibrationJob.d \
./TOF_COS/base/Calibration/IntegrationTimeFinder.d 


# Each subdirectory must supply rules for building sources it contributes
TOF_COS/base/Calibration/AmbientLightCalibrationDataHelper.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/AmbientLightCalibrationDataHelper.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/AmbientLightCalibrationJob.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/AmbientLightCalibrationJob.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/Calibration_Calculation.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/Calibration_Calculation.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/DelayHelper.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DelayHelper.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/DrnuCalibration.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DrnuCalibration.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/DrnuCalibrationDataHelper.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DrnuCalibrationDataHelper.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/DrnuCalibrationInfoData.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DrnuCalibrationInfoData.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/DrnuCalibrationJob.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/DrnuCalibrationJob.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/GrayscaleCalibrationCalculation.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/GrayscaleCalibrationCalculation.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/GrayscaleCalibrationJob.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/GrayscaleCalibrationJob.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

TOF_COS/base/Calibration/IntegrationTimeFinder.o: C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/TOF_COS/base/Calibration/IntegrationTimeFinder.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -DUNIT_TEST_VIRTUAL="" -Wall -O3 -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/interface" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/PointCloud" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Pixel" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/base/Job" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/base" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/inc" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/implementation" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_hal" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../TOF_COS/tof_cos_fpga" -I"C:/JSS_OMS660_Delivery_Optimize/FW_JSS_OMS/application_cpp/../Camera_Base_Application/src/StateMachine" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


