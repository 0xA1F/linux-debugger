#include <iostream>
#include <sstream>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

#include "linenoise.h"

#include "debugger.hpp"
#include "utils.hpp"


void Debugger::run() {
    int wait_status;
    auto options = 0;

    waitpid(m_pid, &wait_status, options);
    
    char* line = nullptr;
    while((line = linenoise("ldb> ")) != nullptr) {
        handleCommand(line); 
        linenoiseHistoryAdd(line); 
        linenoiseFree(line);
    }
}

void Debugger::handleCommand(const std::string& command) {
   auto commandArgs = splitLine(command, ' ');

   auto cmd = commandArgs[0];

   if(isPrefix(cmd, "continue")) {
       continueExecution();
   }
   else if (isPrefix(cmd, "break")) {
       std::string addr {commandArgs[1], 2}; //assume that the address is in 0xADDRESS format
       setBreakpointAtAddress(std::stol(addr, 0, 16));
   }
   else if (isPrefix(cmd, "exit")) {
       exit(0);
   }
   else {
       std::cerr << "Unknown command: " << cmd << "\n";
   }
}


void Debugger::continueExecution() {
    ptrace(PTRACE_CONT, m_pid, nullptr, nullptr);

    int wait_status;

    auto options = 0;

    waitpid(m_pid, &wait_status, options);
}


void Debugger::setBreakpointAtAddress(const std::intptr_t address) {
    std::cout << "Set breakpoint at address 0x" << std::hex << address << "\n";
    Breakpoint bp {m_pid, address};
    bp.enable();
    m_breakpoints.insert({address, bp});
}



