################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/tof_cos_hal/subdir.mk
-include src/hal/timestamp/subdir.mk
-include src/hal/timer/subdir.mk
-include src/hal/sd_card/subdir.mk
-include src/hal/qspi_flash/subdir.mk
-include src/hal/io/subdir.mk
-include src/hal/i2c/subdir.mk
-include src/hal/cpu/subdir.mk
-include src/TOF_COS_Instance/subdir.mk
-include src/SerDes/subdir.mk
-include src/Led/subdir.mk
-include src/IoExpander/subdir.mk
-include src/Camera_number/subdir.mk
-include src/CalibrationMemory/subdir.mk
-include src/subdir.mk
-include TOF_COS/tof_cos_fpga/subdir.mk
-include TOF_COS/implementation/subdir.mk
-include TOF_COS/base/TemporalFilter/subdir.mk
-include TOF_COS/base/TemporalEdgeFilter/subdir.mk
-include TOF_COS/base/TemperatureCompensation/subdir.mk
-include TOF_COS/base/SequencerProgrammer/subdir.mk
-include TOF_COS/base/Roi/subdir.mk
-include TOF_COS/base/RamManager/subdir.mk
-include TOF_COS/base/QuickSort/subdir.mk
-include TOF_COS/base/Pixel/subdir.mk
-include TOF_COS/base/MovementDetectionAlgorithm/subdir.mk
-include TOF_COS/base/Modulation/subdir.mk
-include TOF_COS/base/Jobs/subdir.mk
-include TOF_COS/base/InterferenceDetection/subdir.mk
-include TOF_COS/base/IndexHelper/subdir.mk
-include TOF_COS/base/Hysteresis/subdir.mk
-include TOF_COS/base/Hdr/subdir.mk
-include TOF_COS/base/GrayscaleCompensation/subdir.mk
-include TOF_COS/base/EdgeFilter/subdir.mk
-include TOF_COS/base/DrnuCompensation/subdir.mk
-include TOF_COS/base/DataAcquisition/subdir.mk
-include TOF_COS/base/Config/subdir.mk
-include TOF_COS/base/Confidence/subdir.mk
-include TOF_COS/base/ChipControl/subdir.mk
-include TOF_COS/base/Calibration/subdir.mk
-include TOF_COS/base/Calculation/subdir.mk
-include TOF_COS/base/CRC/subdir.mk
-include TOF_COS/base/Binning/subdir.mk
-include TOF_COS/base/AmbientLightCompensation/subdir.mk
-include TOF_COS/base/AcquisitionMetaData/subdir.mk
-include TOF_COS/base/AcquisitionInfo/subdir.mk
-include Camera_Base_Application/src/udp_transfer/subdir.mk
-include Camera_Base_Application/src/trace/subdir.mk
-include Camera_Base_Application/src/tcp_trace_server/subdir.mk
-include Camera_Base_Application/src/tcp_cmd_handler/subdir.mk
-include Camera_Base_Application/src/queue/subdir.mk
-include Camera_Base_Application/src/Util/subdir.mk
-include Camera_Base_Application/src/StateMachine/States/subdir.mk
-include Camera_Base_Application/src/StateMachine/subdir.mk
-include Camera_Base_Application/src/SdCardManager/subdir.mk
-include Camera_Base_Application/src/Interface/subdir.mk
-include Camera_Base_Application/src/Integration_times/subdir.mk
-include Camera_Base_Application/src/ConfigReader/subdir.mk
-include Camera_Base_Application/src/Communication/subdir.mk
-include Camera_Base_Application/base/StateMachine/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
ELFSIZE += \
application_cpp.elf.size \


# All Target
all: pre-build main-build

# Main-build Target
main-build: application_cpp.elf secondary-outputs

# Tool invocations
application_cpp.elf: $(OBJS) ../src/lscript.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM v7 g++ linker'
	arm-none-eabi-g++ -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -Wl,-build-id=none -specs=Xilinx.spec -Wl,-T -Wl,../src/lscript.ld -L../../standalone_bsp_0/ps7_cortexa9_0/lib -o "application_cpp.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

application_cpp.elf.size: application_cpp.elf
	@echo 'Invoking: ARM v7 Print Size'
	arm-none-eabi-size application_cpp.elf  |tee "application_cpp.elf.size"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(EXECUTABLES)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS)$(ELFSIZE) application_cpp.elf
	-@echo ' '

pre-build:
	-a9-linaro-pre-build-step
	-@echo ' '

secondary-outputs: $(ELFSIZE)

.PHONY: all clean dependents
.SECONDARY: main-build pre-build

-include ../makefile.targets
