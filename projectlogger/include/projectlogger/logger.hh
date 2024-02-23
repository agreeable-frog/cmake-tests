#pragma once

#include <string>
#include <log4cplus/initializer.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/logger.h>

namespace project {
    class Logger {
    private:
        log4cplus::Initializer _initializer;
        log4cplus::Logger _logger;
    public:
        Logger(const std::string& configFilePath);
        void logInfo(const std::string& text);
    };
}