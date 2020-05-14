################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Disease.cpp \
../src/Person.cpp \
../src/Simulation.cpp \
../src/State.cpp \
../src/covidcpp.cpp 

OBJS += \
./src/Disease.o \
./src/Person.o \
./src/Simulation.o \
./src/State.o \
./src/covidcpp.o 

CPP_DEPS += \
./src/Disease.d \
./src/Person.d \
./src/Simulation.d \
./src/State.d \
./src/covidcpp.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


