################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/StateMachine/States/StateError.cpp \
../src/StateMachine/States/StateIdle.cpp \
../src/StateMachine/States/StatePowerUp.cpp \
../src/StateMachine/States/StateProcessCommand.cpp \
../src/StateMachine/States/StateProcessLongCommand.cpp \
../src/StateMachine/States/StateStream.cpp 

OBJS += \
./src/StateMachine/States/StateError.o \
./src/StateMachine/States/StateIdle.o \
./src/StateMachine/States/StatePowerUp.o \
./src/StateMachine/States/StateProcessCommand.o \
./src/StateMachine/States/StateProcessLongCommand.o \
./src/StateMachine/States/StateStream.o 

CPP_DEPS += \
./src/StateMachine/States/StateError.d \
./src/StateMachine/States/StateIdle.d \
./src/StateMachine/States/StatePowerUp.d \
./src/StateMachine/States/StateProcessCommand.d \
./src/StateMachine/States/StateProcessLongCommand.d \
./src/StateMachine/States/StateStream.d 


# Each subdirectory must supply rules for building sources it contributes
src/StateMachine/States/%.o: ../src/StateMachine/States/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O3 -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/implementation" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/PointCloud" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Pixel" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/interface" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/src" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/inc" -I../../standalone_bsp_0/ps7_cortexa9_0/include -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/../ToFAPI/base/Job" -I"C:/Users/mwi/Project/PR_JSS_OMS/FW_JSS_OMS/application_cpp/base" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -std=c++0x -I../../standalone_bsp_0/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


