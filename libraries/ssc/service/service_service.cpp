#include <service_service.hpp>

namespace service
{

// Service::~Service(){}

bool Service::processCLI(int argc, char** argv, const std::string serviceName) noexcept
{
    CLI::App app {serviceName};

    // handle common across all applications CLI options

    try
    {
        // flag: log level
        [[maybe_unused]] const auto logLevelOpt {app.add_option("--log-level", cliData.logLevel, "Logger level (0 - 7)")};
    
        // more application agnostic flags here ...
    } 
    catch(const std::exception& e)
    {
        spdlog::error("error in adding an option: {}", e.what());
        return false;
    }

    // handle application specific CLI options
    
    _processCLI(app);
    
    // parse

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        spdlog::error("CLI11 parse error: {}", app.exit(e));
        return false;
    }

    return true;
}

}
