include ../makefiles/generic.mk
OUTPUT_DIRECTORY=../outputs/
TESTS=mips_elf_features intel_x32_elf_features intel_x64_elf_features arm32_elf_features
TESTS+=aarch64_elf_features
TESTS+=no_libc_intel_x32_no_relocations no_libc_aarch64_no_relocations
C_FILES=sprintf.c
all: $(TESTS)


no_libc_intel_x32_%:
	$(X32_CC) -shared -DDYNAMIC_SUPPORT $(CFLAGS) -nolibc $(subst no_libc_intel_x32_,,$@).c -o $(OUTPUT_DIRECTORY)$(subst no_libc_intel_x32_,,$@)_intel_x32.out
	python3 -m elf_to_shellcode --input ../outputs/$(OUTPUT_DIRECTORY)$(subst no_libc_intel_x32_,,$@)_intel_x32.out --arch intel_x32 --endian little --output ../outputs/$(OUTPUT_DIRECTORY)$(subst no_libc_intel_x32_,,$@)_intel_x32.out.shellcode --loader-support dynamic

no_libc_aarch64_%:
	$(AARCH64_CC) -static $(CFLAGS) -nolibc $(subst no_libc_aarch64_,,$@).c -o $(OUTPUT_DIRECTORY)$(subst no_libc_aarch64_,,$@)_aarch64.out
	python3 -m elf_to_shellcode --input ../outputs/$(OUTPUT_DIRECTORY)$(subst no_libc_aarch64_,,$@)_aarch64.out --arch aarch64 --endian little --output ../outputs/$(OUTPUT_DIRECTORY)$(subst no_libc_aarch64_,,$@)_aarch64.out.shellcode
