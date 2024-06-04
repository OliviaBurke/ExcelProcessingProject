#include <httplib_httplib.hpp>

#include "spdlog/spdlog.h"

int
main([[maybe_unused]] int argc, [[maybe_unused]] char** argv)
{
    spdlog::info("nothing to see here");

    // HTTP
    httplib::Server svr;

    svr.Get("/hi", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("Hello World!", "text/plain");
    });

    svr.listen("0.0.0.0", 8080);
}