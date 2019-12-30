#include <sstream>

#include <sys/types.h>
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
   auto args = splitLine(command, ' '); 

}


