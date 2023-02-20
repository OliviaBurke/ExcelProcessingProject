#ifndef SERVICE_SERVICE
#define SERVICE_SERVICE

#include <service_cli_data.hpp>

#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>
#include <spdlog/spdlog.h>

#include <atomic>

namespace service
{

    class Service
    {
    protected:
        service::CLIData cliData;
        std::atomic<bool> terminate{false};
        std::atomic<bool> reloadConfig{false};

    public:
        Service([[maybe_unused]] int argc, [[maybe_unused]] char **argv, [[maybe_unused]] const std::string serviceName)
        {
            // process CLI arguments
            [[maybe_unused]] const bool cliFlagsProcessed{processCLI(argc, argv, serviceName)};
        }

        virtual ~Service(){};

        /**
         * @brief handle general CLI flags, then invoke CLI flag handling per application
         * @param argc
         * @param argv
         * @return all CLI handling success indicator
         */
        [[nodiscard]] bool processCLI(int argc, char **argv, const std::string serviceName) noexcept;

    protected:
        /**
         * @brief applications will define this for any specific flags
         * @param argc
         * @param argv
         */
        virtual void _processCLI(CLI::App &app) noexcept = 0;

    private:
        inline void handleSignals() noexcept
        {
        }

        /**
         * @brief test 1
         *
         * @param num generic number
         * @return int returns the argument passed in
         */
        [[nodiscard]] inline int test1(const int num) const noexcept
        {
            return num;
        }
    };

}

#endif // SERVICE_SERVICE