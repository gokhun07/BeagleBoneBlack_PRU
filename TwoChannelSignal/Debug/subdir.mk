################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c \
/home/ihsangokhun/Desktop/BeagleBone/MyPru/API-SRC/prussdrv.c \
../runPru.c \
../signal.c 

OBJS += \
./main.o \
./prussdrv.o \
./runPru.o \
./signal.o 

C_DEPS += \
./main.d \
./prussdrv.d \
./runPru.d \
./signal.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc-4.7 -I/usr/arm‐linux‐gnueabihf/include -I/home/ihsangokhun/Desktop/BeagleBone/MyPru/API -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

prussdrv.o: /home/ihsangokhun/Desktop/BeagleBone/MyPru/API-SRC/prussdrv.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc-4.7 -I/usr/arm‐linux‐gnueabihf/include -I/home/ihsangokhun/Desktop/BeagleBone/MyPru/API -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


