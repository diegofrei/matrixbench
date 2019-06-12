################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MatrixMicroBench_src/CRunner.c \
../MatrixMicroBench_src/EngineManager.c \
../MatrixMicroBench_src/ErrorManager.c \
../MatrixMicroBench_src/InfoManager.c \
../MatrixMicroBench_src/MemoryManager.c \
../MatrixMicroBench_src/ProfileManager.c \
../MatrixMicroBench_src/RunnerGround.c \
../MatrixMicroBench_src/RunnerSupport.c \
../MatrixMicroBench_src/StringManager.c \
../MatrixMicroBench_src/TextualRepresentation.c \
../MatrixMicroBench_src/ThreadManager.c 

OBJS += \
./MatrixMicroBench_src/CRunner.o \
./MatrixMicroBench_src/EngineManager.o \
./MatrixMicroBench_src/ErrorManager.o \
./MatrixMicroBench_src/InfoManager.o \
./MatrixMicroBench_src/MemoryManager.o \
./MatrixMicroBench_src/ProfileManager.o \
./MatrixMicroBench_src/RunnerGround.o \
./MatrixMicroBench_src/RunnerSupport.o \
./MatrixMicroBench_src/StringManager.o \
./MatrixMicroBench_src/TextualRepresentation.o \
./MatrixMicroBench_src/ThreadManager.o 

C_DEPS += \
./MatrixMicroBench_src/CRunner.d \
./MatrixMicroBench_src/EngineManager.d \
./MatrixMicroBench_src/ErrorManager.d \
./MatrixMicroBench_src/InfoManager.d \
./MatrixMicroBench_src/MemoryManager.d \
./MatrixMicroBench_src/ProfileManager.d \
./MatrixMicroBench_src/RunnerGround.d \
./MatrixMicroBench_src/RunnerSupport.d \
./MatrixMicroBench_src/StringManager.d \
./MatrixMicroBench_src/TextualRepresentation.d \
./MatrixMicroBench_src/ThreadManager.d 


# Each subdirectory must supply rules for building sources it contributes
MatrixMicroBench_src/%.o: ../MatrixMicroBench_src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"D:\Workspaces\Oxygen\_DSPE\dspe.bench.MatrixBenchMatrixMicroBench_c\csrc" -I"D:\Workspaces\Oxygen\_DSPE\dspe.bench.MatrixBenchMatrixMicroBench_c\MatrixMicroBench_src" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


