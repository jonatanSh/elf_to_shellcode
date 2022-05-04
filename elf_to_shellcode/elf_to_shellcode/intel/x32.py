from elf_to_shellcode.elf_to_shellcode.lib.shellcode import Shellcode, create_make_shellcode


class IntelX32Shellcode(Shellcode):
    def __init__(self, elffile, shellcode_data, endian):
        super(IntelX32Shellcode, self).__init__(
            elffile=elffile,
            shellcode_data=shellcode_data,
            endian=endian,
            mini_loader_little_endian=None,
            mini_loader_big_endian=None,
            shellcode_table_magic=None,
            ptr_fmt="I"
        )

    def correct_symbols(self, shellcode_data):
        return shellcode_data


intel_x32_make_shellcode = create_make_shellcode(IntelX32Shellcode)