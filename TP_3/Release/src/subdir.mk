################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/Employee.c \
../src/TP_3.c \
../src/parser.c \
../src/utn.c 

OBJS += \
./src/Controller.o \
./src/Employee.o \
./src/TP_3.o \
./src/parser.o \
./src/utn.o 

C_DEPS += \
./src/Controller.d \
./src/Employee.d \
./src/TP_3.d \
./src/parser.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


