echo Running mips shellcode
qemu-mips-static ../outputs/shellcode_loader_mips.out ../outputs/elf_features_mipsbe.out.shellcode
echo Running intel x32 shellcode
qemu-i386-static ../outputs/shellcode_loader_intel_x32.out ../outputs/elf_features_intel_x32.out.shellcode
echo Running intel x64 shellcode
qemu-x86_64-static ../outputs/shellcode_loader_intel_x64.out ../outputs/elf_features_intel_x64.out.shellcode