#include <iostream>
#include <fstream>
#include <string>

#include "compile_defs.hh"
#include "libweb/libweb.hh"

int main(void) {
    std::ifstream configuration(RESOURCES_PATH + "configuration.json");
    if (configuration.is_open()) {
        std::string line;
        std::cout << "Configuration file found :\n";
        while(std::getline(configuration, line)) {
            std::cout << line << '\n';
        }
        configuration.close();
    } else {
        std::cout << "Configuration file not found.\n";
    }

    std::string test = getServerInfo("http://example.com");
    std::cout << test;

    return 0;
}