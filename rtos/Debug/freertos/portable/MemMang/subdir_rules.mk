################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
freertos/portable/MemMang/%.obj: ../freertos/portable/MemMang/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"D:/ti/ccs1200/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/bin/cl430" -vmspx --data_model=restricted --use_hw_mpy=F5 --include_path="D:/ti/ccs1200/ccs/ccs_base/msp430/include" --include_path="C:/Users/USER/Documents/GitHub/Sistemas_Embarcados/rtos/freertos" --include_path="C:/Users/USER/Documents/GitHub/Sistemas_Embarcados/rtos/freertos/include" --include_path="C:/Users/USER/Documents/GitHub/Sistemas_Embarcados/rtos/freertos/portable/CCS/MSP430X" --include_path="C:/Users/USER/Documents/GitHub/Sistemas_Embarcados/rtos/freertos/portable/MemMang" --include_path="D:/ti/ccs1200/ccs/tools/compiler/ti-cgt-msp430_21.6.0.LTS/include" --advice:power=all --define=__MSP430F5529__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --silicon_errata=CPU21 --silicon_errata=CPU22 --silicon_errata=CPU23 --silicon_errata=CPU40 --preproc_with_compile --preproc_dependency="freertos/portable/MemMang/$(basename $(<F)).d_raw" --obj_directory="freertos/portable/MemMang" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


