#ifndef MANAGER_MANAGER
#define MANAGER_MANAGER

#include <service_service.hpp>

#include <CLI/App.hpp>
#include <CLI/Config.hpp>
#include <CLI/Formatter.hpp>
#include <ScopeGuard.hpp>

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace manager
{

    class Manager : public service::Service // 'public' is needed here https://stackoverflow.com/a/22107030
    {
    public:
        Manager([[maybe_unused]] int argc, [[maybe_unused]] char **argv, [[maybe_unused]] const std::string serviceName)
            : Service(argc, argv, serviceName)
        {
            // this is a constructor

            finally
            {
                spdlog::info("exiting");
            };
        }

        inline void _processCLI([[maybe_unused]] CLI::App &app) noexcept
        {
            [[maybe_unused]] const auto logLevelOpt{app.add_option("--log-level", cliData.logLevel, "Logger level (0 - 7)")};
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

        [[nodiscard]] int test2(const int num) const noexcept;

        [[nodiscard]] int test3(const int num) noexcept;

        inline void testSanitizer() const noexcept
        {
            char *s = reinterpret_cast<char *>(std::malloc(100));
            std::strcpy(s, "Hello world!");
            printf("string is: %s\n", s);
            // no free
        }

    private:
        int anotherNum{0};
    };

}

#endif