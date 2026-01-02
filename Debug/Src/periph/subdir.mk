################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/periph/buzzer.c \
../Src/periph/input.c \
../Src/periph/led.c 

OBJS += \
./Src/periph/buzzer.o \
./Src/periph/input.o \
./Src/periph/led.o 

C_DEPS += \
./Src/periph/buzzer.d \
./Src/periph/input.d \
./Src/periph/led.d 


# Each subdirectory must supply rules for building sources it contributes
Src/periph/%.o Src/periph/%.su Src/periph/%.cyclo: ../Src/periph/%.c Src/periph/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/CMSIS/Include" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/STM32F401RE_StdPeriph_Driver/inc" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Drivers/STM32F401RE_StdPeriph_Driver/src" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/button" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/buzzer" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/flash" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/led" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/rtos" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/sensor" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/serial" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Middle/ucglib" -I"C:/ThuVien_SDK_1.0.3_NUCLEO-F401RE-master/shared/Utilities" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Inc" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src/drivers" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src/game" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src/gfx" -I"C:/Users/TDCOM/Downloads/Flappy-bird-game-master (2)/Flappy-bird-game-master/Src/periph" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src-2f-periph

clean-Src-2f-periph:
	-$(RM) ./Src/periph/buzzer.cyclo ./Src/periph/buzzer.d ./Src/periph/buzzer.o ./Src/periph/buzzer.su ./Src/periph/input.cyclo ./Src/periph/input.d ./Src/periph/input.o ./Src/periph/input.su ./Src/periph/led.cyclo ./Src/periph/led.d ./Src/periph/led.o ./Src/periph/led.su

.PHONY: clean-Src-2f-periph

