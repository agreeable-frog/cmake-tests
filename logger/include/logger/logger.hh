#pragma once

#include <string>
#include <log4cplus/initializer.h>
#include <log4cplus/logger.h>

namespace project {
    class Logger {
    private:
        static bool _configured;
        log4cplus::Initializer _initializer;
        log4cplus::Logger _logger;
    public:
        static void configure(const std::string& configFilePath);
        Logger(const std::string& name);
        void logInfo(const std::string& text);
    };
}