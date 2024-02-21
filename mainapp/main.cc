#include <iostream>
#include <fstream>
#include <string>

#include "compile_defs.hh"
#include "libweb/libweb.hh"
#include "projectlogger/logger.hh"

int main(void) {
    std::ifstream configuration(RESOURCES_PATH + "configuration.json");
    project::Logger logger;
    if (configuration.is_open()) {
        std::string line;
        logger.logSomething("Configuration file found:");
        while(std::getline(configuration, line)) {
            std::cout << line << '\n';
        }
        configuration.close();
    } else {
        logger.logSomething("Configuration file not found.");
    }

    std::string test = getServerInfo("http://example.com");
    std::cout << test;

    return 0;
}