#include <iostream>
#include <fstream>
#include <string>

#include "libweb/contact.hh"
#include "logger/logger.hh"

int main(void) {
    std::ifstream configuration(std::string(RESOURCES_PATH) + "configuration.json");
    project::Logger::configure(std::string(RESOURCES_PATH) + "log4cplus.properties");
    project::Logger logger("mainapp");
    if (configuration.is_open()) {
        std::string line;
        logger.logInfo("Configuration file found:");
        while(std::getline(configuration, line)) {
            std::cout << line << '\n';
        }
        configuration.close();
    } else {
        logger.logInfo("Configuration file not found.");
    }

    std::string test = getServerInfo("http://example.com");
    std::cout << test;

    return 0;
}