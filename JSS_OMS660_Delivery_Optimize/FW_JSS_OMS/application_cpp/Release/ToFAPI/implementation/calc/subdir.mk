################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/implementation/calc/calcFpga.c \
C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/implementation/calc/iterator_default.c 

OBJS += \
./ToFAPI/implementation/calc/calcFpga.o \
./ToFAPI/implementation/calc/iterator_default.o 

C_DEPS += \
./ToFAPI/implementation/calc/calcFpga.d \
./ToFAPI/implementation/calc/iterator_default.d 


# Each subdirectory must supply rules for building sources it contributes
ToFAPI/implementation/calc/calcFpga.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/implementation/calc/calcFpga.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -I../../standalone_bsp_0/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

ToFAPI/implementation/calc/iterator_default.o: C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/ToFAPI/implementation/calc/iterator_default.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -I../../standalone_bsp_0/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


