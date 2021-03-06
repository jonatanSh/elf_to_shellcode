#ifndef LOADER_ARM_X64
#define LOADER_ARM_X64
typedef unsigned long long size_t;

#define ARCH_OPCODE_SIZE 2
#define TABLE_MAGIC 0x8899aabbccddeeff
#define ARCH_CALL_GET_PC "bl get_pc_internal\n"

#define get_pc() {      \
    asm(                            \
        "bl get_pc_internal\n"      \
        "b next\n"                  \
        "get_pc_internal:\n"        \
        "mov %0, lr\n"              \
        "ret\n"                     \
        "next:\n"                   \
        : "=r"(pc) :               \
                                    \
    );                              \
}                                   \

#define call_main(main_ptr, argc, argv, envp) {                           \
   register size_t x0 asm("x0") = (size_t)(main_ptr); \
   asm(                                                 \
        "add sp,sp, #-8\n"                              \
        "str lr, [sp]\n"                                \
        "blr x0\n"                                     \
        "ldr lr, [sp]\n"                                \
        "add sp, sp, #8\n"                              \
        :  :                                            \
        "r"(x0)                                         \
   );                                                   \
}                                                       \


#endif