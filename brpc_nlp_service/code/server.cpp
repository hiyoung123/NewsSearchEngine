/*
* @Author       : hiyoung
* @Date         : 2021/09/01 01:20:36
* @copyleft Apache 2.0
*/

#include <brpc/server.h>
#include "service/segment.hpp"
#include "service/recall.hpp"
#include "service/sort.hpp"

int main()
{
    brpc::Server server;

    NLP::SegmentServiceImp segment_service;
    if (server.AddService(&segment_service, brpc::SERVER_DOESNT_OWN_SERVICE) != 0)
    {
        LOG(INFO) << " Add segment service failed!";
        return 0;
    }

    NLP::RecallServiceImp recall_service;
    if (server.AddService(&recall_service, brpc::SERVER_DOESNT_OWN_SERVICE) != 0)
    {
        LOG(INFO) << " Add recall service failed!";
        return 0;
    }

    NLP::SortServiceImp sort_service;
    if (server.AddService(&sort_service, brpc::SERVER_DOESNT_OWN_SERVICE) != 0)
    {
        LOG(INFO) << " Add sort service failed!";
        return 0;
    }

    brpc::ServerOptions op;
    if (server.Start(8003, &op) != 0)
    {
        LOG(INFO) << " Start service failed!";
        return 0;
    }

    server.RunUntilAskedToQuit();
    return 0;
}