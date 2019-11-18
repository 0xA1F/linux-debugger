#include <iostream>
#include <unistd.h>
#include <sys/ptrace.h>

#include "debugger.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Program name not specified";
        return -1;
    }

    auto prog = argv[1];
    auto pid = fork();

    if (pid == 0) {
        // we are in the child process
        // execute debuggee
        // enable debuggee control in parent process
        ptrace(PTRACE_TRACEME, 0, nullptr, nullptr);
        // execute debuggee
        execl(prog, prog, nullptr);
    }

    else if (pid >= 1) {
        // we are in the parent process
        // execute debugger
        Debugger dbg{prog, pid};
        dbg.run();
    }
}
