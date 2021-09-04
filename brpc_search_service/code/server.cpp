#include <brpc/server.h>
#include "service/search.hpp"

int main()
{
    brpc::Server server;
    NLP::SearchServiceImp search_service;

    if (server.AddService(&search_service, brpc::SERVER_DOESNT_OWN_SERVICE) != 0)
    {
        LOG(INFO) << "Add search service failed! ";
        return 0;
    }

    brpc::ServerOptions op;
    if (server.Start(8004, &op) != 0)
    {
        LOG(INFO) << " Start service failed!";
        return 0;
    }

    server.RunUntilAskedToQuit();
    return 0;
}