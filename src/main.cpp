#include <iostream>
#include <unistd.h>
#include <sys/ptrace.h>

#include "debugger.hpp"


void executeDebuggee(const std::string& prog)
{
    if (ptrace(PTRACE_TRACEME, 0, 0, 0) < 0) {
        std::cerr << "Error in ptrace\n";
        return;
    }
    execl(prog.c_str(), prog.c_str(), nullptr);
}


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
        executeDebuggee(prog);
    }

    else if (pid >= 1) {
        // we are in the parent process
        // execute debugger
        Debugger dbg{prog, pid};
        dbg.run();
    }
}
