#ifndef LOADER_GENERIC
#define LOADER_GENERIC

#define MAX_SEARCH_DEPTH 0x400


#if defined(__x86_64__) || defined(_M_X64)
    #include "./intel/x64.h"
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86)
    #include "./intel/x32.h"
#elif defined(__arm__)
    #include "./arm/arm32.h"
#elif defined(__aarch64__) || defined(_M_ARM64)
    #include "./arm/aarch64.h"
#elif defined(mips) || defined(__mips__) || defined(__mips)
    #include "./mips/mips.h"
#elif defined(__sh__)
    #error Not Supported
#elif defined(__powerpc) || defined(__powerpc__) || defined(__powerpc64__) || defined(__POWERPC__) || defined(__ppc__) || defined(__PPC__) || defined(_ARCH_PPC)
    #error Not Supported
#elif defined(__PPC64__) || defined(__ppc64__) || defined(_ARCH_PPC64)
    #error Not Supported
#elif defined(__sparc__) || defined(__sparc)
    #error Not Supported
#elif defined(__m68k__)
    #error Not Supported
#else
    #error Not Supported
#endif

typedef size_t loader_off_t;

struct table_entry {
    size_t size;
    loader_off_t f_offset;
    loader_off_t v_offset;
};
struct elf_information_struct {
    size_t elf_header_size;
    size_t loader_size;
};
struct relocation_table {
    size_t magic;
    size_t total_size;
    struct elf_information_struct elf_information;
};

struct entry_attributes {
    size_t attribute_1;
};

enum RELOCATION_ATTRIBUTES {
    IRELATIVE = 1,
    RELATIVE_TO_LOADER_BASE = 2,
    RELATIVE = 3,
};

typedef void * (*IRELATIVE_T)();


#ifndef TABLE_MAGIC
    #define resolve_table_magic GET_TABLE_MAGIC 
#else
    #define resolve_table_magic() {magic=TABLE_MAGIC;}
#endif

#define advance_pc_to_magic() {                                             \
    for(size_t i = 0; i < MAX_SEARCH_DEPTH; i+=ARCH_OPCODE_SIZE) {          \
        pc += ARCH_OPCODE_SIZE;                                             \
        if(*((size_t*)pc) == magic) {                                       \
            break;                                                          \
        }                                                                   \
    }                                                                       \
}                                                                           \

#define ERROR -1
#define OK 1

#ifndef ARCH_CALL_GET_PC
    #define ARCH_CALL_GET_PC "call get_pc_internal\n"
#endif

#define call_get_pc_generic() {     \
    asm(                            \
        ARCH_CALL_GET_PC            \
        : "=r"(pc) :                \
    );                              \
}                                   \

#ifndef call_get_pc
    #define call_get_pc call_get_pc_generic
#endif

#endif