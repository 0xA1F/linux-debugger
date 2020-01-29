#ifndef REGISTER_H
#define REGISTER_H

#include <string>


enum class Register {
    rax, rbx, rcx, rdx,
    rds, rsi, rbp, rsp,
    r8,  r9,  r10, r11, 
    r12, r13, r14, r15,
    rip, rflags,    cs,
    orig_rax,  fs_base,
    fs, gs, ss, ds, es
};


constexpr std::size_t NumRegisters = 27;

struct RegDescriptor {
    Register reg;
    int DwarfRegister;
    std::string Name;
};

#endif
