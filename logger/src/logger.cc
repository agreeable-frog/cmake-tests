#include "logger/logger.hh"

#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>
#include <iostream>

bool project::Logger::_configured = false;

void project::Logger::configure(const std::string& configFilePath) {
    log4cplus::PropertyConfigurator::doConfigure(configFilePath);
    _configured = true;
}

project::Logger::Logger(const std::string& name) {
    if (!_configured) throw std::runtime_error("log4cplus not configured!");
    _logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(name));
}

void project::Logger::logInfo(const std::string& text) {
    LOG4CPLUS_INFO(_logger, LOG4CPLUS_TEXT(text));
}