#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <string>
#include <unordered_map>
#include <vector>
#include <unistd.h>

#include "breakpoint.hpp"

class Debugger {
    public:
        Debugger(std::string prog_name, pid_t pid)
            : m_prog_name{std::move(prog_name)}, m_pid{pid} {}

        void run();
        void handleCommand(const std::string& command);
        void continueExecution();
        void setBreakpointAtAddress(const std::intptr_t address);

    private:
        std::string m_prog_name;
        pid_t m_pid;
        std::unordered_map<std::intptr_t, Breakpoint> m_breakpoints;
        
};

#endif
