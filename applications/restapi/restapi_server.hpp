#include <pistache/endpoint.h>


namespace restapi {

struct Server : public Pistache::Http::Handler {
  HTTP_PROTOTYPE(Server)
  void onRequest(const Pistache::Http::Request&, Pistache::Http::ResponseWriter writer) override;
};

}