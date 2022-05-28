CFLAGS+=-fno-stack-protector -fPIE -fpic -static
#CFLAGS+=-nostartfiles --entry=main 
SELF_DIR := $(dir $(lastword $(MAKEFILE_LIST)))
include $(SELF_DIR)/compilers.mk

mips_%:
	$(MIPS_CC) $(CFLAGS) -BE $(subst mips_,,$@).c -o $(OUTPUT_DIRECTORY)$(subst mips_,,$@)_mipsbe.out
	python -m elf_to_shellcode ../outputs/$(OUTPUT_DIRECTORY)$(subst mips_,,$@)_mipsbe.out mips big no ../outputs/$(OUTPUT_DIRECTORY)$(subst mips_,,$@)_mipsbe.out.shellcode
intel_x32_%:
	$(X32_CC) $(CFLAGS) $(subst intel_x32_,,$@).c -o $(OUTPUT_DIRECTORY)$(subst intel_x32_,,$@)_intel_x32.out
	python -m elf_to_shellcode ../outputs/$(OUTPUT_DIRECTORY)$(subst intel_x32_,,$@)_intel_x32.out intel_x32 little glibc ../outputs/$(OUTPUT_DIRECTORY)$(subst intel_x32_,,$@)_intel_x32.out.shellcode

intel_x64_%:
	$(X64_CC) $(CFLAGS) $(subst intel_x64_,,$@).c -o $(OUTPUT_DIRECTORY)$(subst intel_x64_,,$@)_intel_x64.out
	python -m elf_to_shellcode ../outputs/$(OUTPUT_DIRECTORY)$(subst intel_x64_,,$@)_intel_x64.out intel_x64 little no ../outputs/$(OUTPUT_DIRECTORY)$(subst intel_x64_,,$@)_intel_x64.out.shellcode

arm_32_%:
	$(ARM_CC) $(CFLAGS) $(subst arm_32_,,$@).c -o $(OUTPUT_DIRECTORY)$(subst arm_32_,,$@)_arm_32.out
	python -m elf_to_shellcode ../outputs/$(OUTPUT_DIRECTORY)$(subst arm_32_,,$@)_arm_32.out arm_32 little no ../outputs/$(OUTPUT_DIRECTORY)$(subst arm_32_,,$@)_arm_32.out.shellcode
aarch64_%:
	$(AARCH64_CC) $(CFLAGS) $(subst aarch64_,,$@).c -o $(OUTPUT_DIRECTORY)$(subst aarch64_,,$@)_aarch64.out
	python -m elf_to_shellcode ../outputs/$(OUTPUT_DIRECTORY)$(subst aarch64_,,$@)_aarch64.out aarch64 little no ../outputs/$(OUTPUT_DIRECTORY)$(subst aarch64_,,$@)_aarch64.out.shellcode
