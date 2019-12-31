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
   auto commangArgs = splitLine(command, ' ');

   auto cmd = commangArgs[0];

   if(isPrefix(cmd, "continue")) {
       continueExecution();
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
