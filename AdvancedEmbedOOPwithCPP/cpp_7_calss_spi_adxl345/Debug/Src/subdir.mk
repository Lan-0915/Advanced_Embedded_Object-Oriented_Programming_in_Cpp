################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/ADC.cpp \
../Src/ADXL345.cpp \
../Src/FPU.cpp \
../Src/GPIO.cpp \
../Src/SPI.cpp \
../Src/Timebase.cpp \
../Src/main.cpp 

C_SRCS += \
../Src/syscalls.c \
../Src/sysmem.c 

C_DEPS += \
./Src/syscalls.d \
./Src/sysmem.d 

OBJS += \
./Src/ADC.o \
./Src/ADXL345.o \
./Src/FPU.o \
./Src/GPIO.o \
./Src/SPI.o \
./Src/Timebase.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

CPP_DEPS += \
./Src/ADC.d \
./Src/ADXL345.d \
./Src/FPU.d \
./Src/GPIO.d \
./Src/SPI.d \
./Src/Timebase.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.cpp Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m4 -std=gnu++14 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -I../Inc -I"G:/AdvancedEmbedOOPwithCPP/cpp_7_calss_spi_adxl345/chip_headers/CMSIS/Include" -I"G:/AdvancedEmbedOOPwithCPP/cpp_7_calss_spi_adxl345/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F411RE -DSTM32 -DSTM32F4 -DSTM32F411RETx -DSTM32F411xE -c -I../Inc -I"G:/AdvancedEmbedOOPwithCPP/cpp_7_calss_spi_adxl345/chip_headers/CMSIS/Include" -I"G:/AdvancedEmbedOOPwithCPP/cpp_7_calss_spi_adxl345/chip_headers/CMSIS/Device/ST/STM32F4xx/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC.cyclo ./Src/ADC.d ./Src/ADC.o ./Src/ADC.su ./Src/ADXL345.cyclo ./Src/ADXL345.d ./Src/ADXL345.o ./Src/ADXL345.su ./Src/FPU.cyclo ./Src/FPU.d ./Src/FPU.o ./Src/FPU.su ./Src/GPIO.cyclo ./Src/GPIO.d ./Src/GPIO.o ./Src/GPIO.su ./Src/SPI.cyclo ./Src/SPI.d ./Src/SPI.o ./Src/SPI.su ./Src/Timebase.cyclo ./Src/Timebase.d ./Src/Timebase.o ./Src/Timebase.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

