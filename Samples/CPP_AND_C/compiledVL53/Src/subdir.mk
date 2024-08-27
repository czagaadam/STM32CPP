################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/vl53l0x.c \
../Src/vl53l0xHandlerClass.c 

OBJS += \
./Src/vl53l0x.o \
./Src/vl53l0xHandlerClass.o 

C_DEPS += \
./Src/vl53l0x.d \
./Src/vl53l0xHandlerClass.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc -gdwarf-4 "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/vl53l0x.cyclo ./Src/vl53l0x.d ./Src/vl53l0x.o ./Src/vl53l0x.su ./Src/vl53l0xHandlerClass.cyclo ./Src/vl53l0xHandlerClass.d ./Src/vl53l0xHandlerClass.o ./Src/vl53l0xHandlerClass.su

.PHONY: clean-Src

