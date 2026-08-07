################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-241935502: ../c2000.syscfg
	@echo 'SysConfig - building file: "$<"'
	"C:/ti/ccs2051/ccs/utils/sysconfig_1.27.1/sysconfig_cli.bat" -s "C:/ti/C2000Ware_5_04_00_00/.metadata/sdk.json" -d "F28004x" -p "F28004x_64PM" -r "F28004x_64PM" --script "C:/Users/90541/workspace_ccstheia/Charger_Firmware_v1.1/c2000.syscfg" --context "system" -o "syscfg" --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-241935502 ../c2000.syscfg
syscfg/board.h: build-241935502
syscfg/board.cmd.genlibs: build-241935502
syscfg/board.opt: build-241935502
syscfg/board.json: build-241935502
syscfg/pinmux.csv: build-241935502
syscfg/epwm.dot: build-241935502
syscfg/adc.dot: build-241935502
syscfg/c2000ware_libraries.cmd.genlibs: build-241935502
syscfg/c2000ware_libraries.opt: build-241935502
syscfg/c2000ware_libraries.c: build-241935502
syscfg/c2000ware_libraries.h: build-241935502
syscfg/clocktree.h: build-241935502
syscfg: build-241935502

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --fp_mode=relaxed --include_path="C:/Users/90541/workspace_ccstheia/Charger_Firmware_v1.1" --include_path="C:/ti/C2000Ware_5_04_00_00" --include_path="C:/Users/90541/workspace_ccstheia/Charger_Firmware_v1.1/device" --include_path="C:/ti/C2000Ware_5_04_00_00/driverlib/f28004x/driverlib/" --include_path="C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/include" --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="C:/Users/90541/workspace_ccstheia/Charger_Firmware_v1.1/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'C2000 Compiler - building file: "$<"'
	"C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --tmu_support=tmu0 --vcu_support=vcu0 -Ooff --fp_mode=relaxed --include_path="C:/Users/90541/workspace_ccstheia/Charger_Firmware_v1.1" --include_path="C:/ti/C2000Ware_5_04_00_00" --include_path="C:/Users/90541/workspace_ccstheia/Charger_Firmware_v1.1/device" --include_path="C:/ti/C2000Ware_5_04_00_00/driverlib/f28004x/driverlib/" --include_path="C:/ti/ccs2051/ccs/tools/compiler/ti-cgt-c2000_25.11.0.LTS/include" --define=DEBUG --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="C:/Users/90541/workspace_ccstheia/Charger_Firmware_v1.1/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


