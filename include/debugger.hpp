#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <string>
#include <vector>
#include <unistd.h>

class Debugger {
    public:
        Debugger(std::string prog_name, pid_t pid)
            : m_prog_name{std::move(prog_name)}, m_pid{pid} {}

        void run();
        void handleCommand(const std::string& command);
        void continueExecution();

    private:
        std::string m_prog_name;
        pid_t m_pid;
        
};

#endif
