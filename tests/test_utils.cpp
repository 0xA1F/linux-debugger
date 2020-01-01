#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "utils.hpp"


TEST_SUITE("test utils") {
    TEST_CASE("test line split") {
        std::string line = "Linux\\Debugger|TestC@se";
        REQUIRE_EQ(std::vector<std::string> {"Linux\\Debugger", "TestC@se"},
                  splitLine(line, '|'));
        REQUIRE_NE(std::vector<std::string> {"Linux", "Debugger", "TestC@se"},
                  splitLine(line, '\\'));
    }
    TEST_CASE("test prefix") {
        std::string line = "command run";
        REQUIRE_EQ(true, isPrefix("command ", line));
        REQUIRE_NE(true, isPrefix(line, "command "));
        REQUIRE_EQ(true, isPrefix("comm", line));
        REQUIRE_NE(true, isPrefix(line, "comm"));
    }
}
