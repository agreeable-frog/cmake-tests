#pragma once

#include <string>
#include <log4cplus/logger.h>

namespace project {
    class Logger {
    public:
        void logSomething(const std::string& log);
    };
}