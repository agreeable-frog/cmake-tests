#include "projectlogger/logger.hh"

#include <iostream>

void project::Logger::logSomething(const std::string& log) {
    std::cout << log << '\n';
}