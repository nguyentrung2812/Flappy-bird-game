################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/flash.c 

OBJS += \
./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/flash.o 

C_DEPS += \
./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/flash.d 


# Each subdirectory must supply rules for building sources it contributes
ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/flash.o: C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/flash.c ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/CMSIS/Include" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/STM32F401RE_StdPeriph_Driver/src" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/button" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/buzzer" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/led" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/sensor" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/serial" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/ucglib" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Utilities" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Inc" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src/drivers" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src/game" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src/gfx" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src/periph" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThuVien_SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2d-master-2f-shared-2f-Middle-2f-flash

clean-ThuVien_SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2d-master-2f-shared-2f-Middle-2f-flash:
	-$(RM) ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/flash.cyclo ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/flash.d ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/flash.o ./ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash/flash.su

.PHONY: clean-ThuVien_SDK_1-2e-0-2e-3_NUCLEO-2d-F401RE-2d-master-2f-shared-2f-Middle-2f-flash

