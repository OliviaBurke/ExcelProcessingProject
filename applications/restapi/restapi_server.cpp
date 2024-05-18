#include <restapi_server.hpp>

namespace restapi {

void
Server::onRequest(const Pistache::Http::Request&, Pistache::Http::ResponseWriter writer)
{
    writer.send(Pistache::Http::Code::Ok, "Hello, World!");
}

}  // namespace restapi