################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../csrc/MatrixBenchMatrixMicroBench_Application.c \
../csrc/MatrixBenchMatrixMicroBench_Configuration.c \
../csrc/MatrixBenchMatrixMultiplier_Block_CImplementation.c \
../csrc/MatrixBenchMatrixMultiplier_CImplementation.c \
../csrc/MatrixBenchMatrixMultiplier_SoftwareUnit.c \
../csrc/MatrixBenchMatrixSource_Block_CImplementation.c \
../csrc/MatrixBenchMatrixSource_CImplementation.c \
../csrc/MatrixBenchMatrixSource_SoftwareUnit.c \
../csrc/MatrixBenchMatrixTarget_Block_CImplementation.c \
../csrc/MatrixBenchMatrixTarget_CImplementation.c \
../csrc/MatrixBenchMatrixTarget_SoftwareUnit.c \
../csrc/MatrixBenchMatrix_PointerGate.c \
../csrc/MicroBenchCounter_StandardGate.c \
../csrc/MicroBenchEvaluator_Block_CImplementation.c \
../csrc/MicroBenchEvaluator_CImplementation.c \
../csrc/MicroBenchEvaluator_SoftwareUnit.c \
../csrc/MicroBenchFlag_StandardGate.c \
../csrc/MicroBenchNumSamples_StandardGate.c \
../csrc/MicroBenchSamplesPerSecond_StandardGate.c \
../csrc/MicroBenchSignalsCount_StandardGate.c \
../csrc/MicroBenchTime_StandardGate.c 

OBJS += \
./csrc/MatrixBenchMatrixMicroBench_Application.o \
./csrc/MatrixBenchMatrixMicroBench_Configuration.o \
./csrc/MatrixBenchMatrixMultiplier_Block_CImplementation.o \
./csrc/MatrixBenchMatrixMultiplier_CImplementation.o \
./csrc/MatrixBenchMatrixMultiplier_SoftwareUnit.o \
./csrc/MatrixBenchMatrixSource_Block_CImplementation.o \
./csrc/MatrixBenchMatrixSource_CImplementation.o \
./csrc/MatrixBenchMatrixSource_SoftwareUnit.o \
./csrc/MatrixBenchMatrixTarget_Block_CImplementation.o \
./csrc/MatrixBenchMatrixTarget_CImplementation.o \
./csrc/MatrixBenchMatrixTarget_SoftwareUnit.o \
./csrc/MatrixBenchMatrix_PointerGate.o \
./csrc/MicroBenchCounter_StandardGate.o \
./csrc/MicroBenchEvaluator_Block_CImplementation.o \
./csrc/MicroBenchEvaluator_CImplementation.o \
./csrc/MicroBenchEvaluator_SoftwareUnit.o \
./csrc/MicroBenchFlag_StandardGate.o \
./csrc/MicroBenchNumSamples_StandardGate.o \
./csrc/MicroBenchSamplesPerSecond_StandardGate.o \
./csrc/MicroBenchSignalsCount_StandardGate.o \
./csrc/MicroBenchTime_StandardGate.o 

C_DEPS += \
./csrc/MatrixBenchMatrixMicroBench_Application.d \
./csrc/MatrixBenchMatrixMicroBench_Configuration.d \
./csrc/MatrixBenchMatrixMultiplier_Block_CImplementation.d \
./csrc/MatrixBenchMatrixMultiplier_CImplementation.d \
./csrc/MatrixBenchMatrixMultiplier_SoftwareUnit.d \
./csrc/MatrixBenchMatrixSource_Block_CImplementation.d \
./csrc/MatrixBenchMatrixSource_CImplementation.d \
./csrc/MatrixBenchMatrixSource_SoftwareUnit.d \
./csrc/MatrixBenchMatrixTarget_Block_CImplementation.d \
./csrc/MatrixBenchMatrixTarget_CImplementation.d \
./csrc/MatrixBenchMatrixTarget_SoftwareUnit.d \
./csrc/MatrixBenchMatrix_PointerGate.d \
./csrc/MicroBenchCounter_StandardGate.d \
./csrc/MicroBenchEvaluator_Block_CImplementation.d \
./csrc/MicroBenchEvaluator_CImplementation.d \
./csrc/MicroBenchEvaluator_SoftwareUnit.d \
./csrc/MicroBenchFlag_StandardGate.d \
./csrc/MicroBenchNumSamples_StandardGate.d \
./csrc/MicroBenchSamplesPerSecond_StandardGate.d \
./csrc/MicroBenchSignalsCount_StandardGate.d \
./csrc/MicroBenchTime_StandardGate.d 


# Each subdirectory must supply rules for building sources it contributes
csrc/%.o: ../csrc/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"../csrc" -I"../MatrixMicroBench_src" -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


