#include <cstdint>
#include <unistd.h>
#include <sys/ptrace.h>


class Breakpoint {
    public:
        Breakpoint(pid_t pid, std::intptr_t addr):
            m_pid{pid}, m_addr{addr}, m_enabled{false}, m_saved_data{}
        {}

        void enable();
        void disable();

        auto isEnabled() const -> bool { return m_enabled; }
        auto getAddress() const -> std::intptr_t { return m_addr; }

    private:
        pid_t m_pid;
        std::intptr_t m_addr;
        bool m_enabled;
        std::uint8_t m_saved_data;
};
