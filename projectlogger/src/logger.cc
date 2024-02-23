#include "projectlogger/logger.hh"

#include <iostream>

project::Logger::Logger(const std::string& name) {
    log4cplus::PropertyConfigurator::doConfigure(LOG_CONFIG_FILE_PATH);
    _logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT(name));
}

void project::Logger::logInfo(const std::string& text) {
    LOG4CPLUS_INFO(_logger, LOG4CPLUS_TEXT(text));
}