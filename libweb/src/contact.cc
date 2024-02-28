#include "libweb/contact.hh"

#include <sstream>
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>


std::string getServerInfo(const std::string& serverIp) {
    try {
        // That's all that is needed to do cleanup of used resources (RAII style).
        curlpp::Cleanup myCleanup;

        // Our request to be sent.
        curlpp::Easy myRequest;

        // Set the URL.
        myRequest.setOpt<curlpp::options::Url>(serverIp);

        // Send request and get a result.
        // By default the result goes to standard output.
        std::ostringstream os;
        curlpp::options::WriteStream ws(&os);
        myRequest.setOpt(ws);
        
        myRequest.perform();

        return os.str();
    }

    catch (curlpp::RuntimeError& e) {
        std::cout << e.what() << std::endl;
        return "";
    }

    catch (curlpp::LogicError& e) {
        std::cout << e.what() << std::endl;
        return "";
    }
}