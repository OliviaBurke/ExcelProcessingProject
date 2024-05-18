#include <restapi_server.hpp>


// #include <pistache/endpoint.h>
// #include <pistache/http.h>

int main([[maybe_unused]] int argc, [[maybe_unused]] char **argv)
{
    Pistache::Http::listenAndServe<restapi::Server>(Pistache::Address("*:9080"));
}