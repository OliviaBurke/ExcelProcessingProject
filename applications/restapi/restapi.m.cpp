#include <httplib_httplib.hpp>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    // HTTP
    httplib::Server svr;

    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
    res.set_content("Hello World!", "text/plain");
    });

    svr.listen("0.0.0.0", 8080);
}