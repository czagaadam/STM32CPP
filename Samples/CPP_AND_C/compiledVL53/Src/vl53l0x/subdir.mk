################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/vl53l0x/vl53l0x_api.c \
../Src/vl53l0x/vl53l0x_api_calibration.c \
../Src/vl53l0x/vl53l0x_api_core.c \
../Src/vl53l0x/vl53l0x_api_ranging.c \
../Src/vl53l0x/vl53l0x_api_strings.c \
../Src/vl53l0x/vl53l0x_i2c_platform.c \
../Src/vl53l0x/vl53l0x_platform.c \
../Src/vl53l0x/vl53l0x_platform_log.c 

OBJS += \
./Src/vl53l0x/vl53l0x_api.o \
./Src/vl53l0x/vl53l0x_api_calibration.o \
./Src/vl53l0x/vl53l0x_api_core.o \
./Src/vl53l0x/vl53l0x_api_ranging.o \
./Src/vl53l0x/vl53l0x_api_strings.o \
./Src/vl53l0x/vl53l0x_i2c_platform.o \
./Src/vl53l0x/vl53l0x_platform.o \
./Src/vl53l0x/vl53l0x_platform_log.o 

C_DEPS += \
./Src/vl53l0x/vl53l0x_api.d \
./Src/vl53l0x/vl53l0x_api_calibration.d \
./Src/vl53l0x/vl53l0x_api_core.d \
./Src/vl53l0x/vl53l0x_api_ranging.d \
./Src/vl53l0x/vl53l0x_api_strings.d \
./Src/vl53l0x/vl53l0x_i2c_platform.d \
./Src/vl53l0x/vl53l0x_platform.d \
./Src/vl53l0x/vl53l0x_platform_log.d 


# Each subdirectory must supply rules for building sources it contributes
Src/vl53l0x/%.o Src/vl53l0x/%.su Src/vl53l0x/%.cyclo: ../Src/vl53l0x/%.c Src/vl53l0x/subdir.mk
	arm-none-eabi-gcc -gdwarf-4 "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F429xx -c -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-vl53l0x

clean-Src-2f-vl53l0x:
	-$(RM) ./Src/vl53l0x/vl53l0x_api.cyclo ./Src/vl53l0x/vl53l0x_api.d ./Src/vl53l0x/vl53l0x_api.o ./Src/vl53l0x/vl53l0x_api.su ./Src/vl53l0x/vl53l0x_api_calibration.cyclo ./Src/vl53l0x/vl53l0x_api_calibration.d ./Src/vl53l0x/vl53l0x_api_calibration.o ./Src/vl53l0x/vl53l0x_api_calibration.su ./Src/vl53l0x/vl53l0x_api_core.cyclo ./Src/vl53l0x/vl53l0x_api_core.d ./Src/vl53l0x/vl53l0x_api_core.o ./Src/vl53l0x/vl53l0x_api_core.su ./Src/vl53l0x/vl53l0x_api_ranging.cyclo ./Src/vl53l0x/vl53l0x_api_ranging.d ./Src/vl53l0x/vl53l0x_api_ranging.o ./Src/vl53l0x/vl53l0x_api_ranging.su ./Src/vl53l0x/vl53l0x_api_strings.cyclo ./Src/vl53l0x/vl53l0x_api_strings.d ./Src/vl53l0x/vl53l0x_api_strings.o ./Src/vl53l0x/vl53l0x_api_strings.su ./Src/vl53l0x/vl53l0x_i2c_platform.cyclo ./Src/vl53l0x/vl53l0x_i2c_platform.d ./Src/vl53l0x/vl53l0x_i2c_platform.o ./Src/vl53l0x/vl53l0x_i2c_platform.su ./Src/vl53l0x/vl53l0x_platform.cyclo ./Src/vl53l0x/vl53l0x_platform.d ./Src/vl53l0x/vl53l0x_platform.o ./Src/vl53l0x/vl53l0x_platform.su ./Src/vl53l0x/vl53l0x_platform_log.cyclo ./Src/vl53l0x/vl53l0x_platform_log.d ./Src/vl53l0x/vl53l0x_platform_log.o ./Src/vl53l0x/vl53l0x_platform_log.su

.PHONY: clean-Src-2f-vl53l0x

