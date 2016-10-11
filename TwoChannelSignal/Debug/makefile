################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: TwoChannelSignal

# Tool invocations
TwoChannelSignal: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	arm-linux-gnueabihf-gcc-4.7 -L/usr/arm‐linux‐gnueabihf/lib -L/home/ihsangokhun/Desktop/BeagleBone/MyPru/API -mfloat-abi=hard -o "TwoChannelSignal" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) TwoChannelSignal
	-@echo ' '

post-build:
	-scp TwoChannelSignal  root@192.168.10.29:/home/ihsangokhun/shareFolder/PRU_Trainings/Two_Channel_Signal
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
