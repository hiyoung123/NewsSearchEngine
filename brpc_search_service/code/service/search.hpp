/*
* @Author       : hiyoung
* @Date         : 2021/09/04 11:56:47
* @copyleft Apache 2.0
*/

#include "service.pb.h"
#include <unordered_map>
#include <string>
#include <mysql/mysql.h>
#include "base_service.pb.h"
#include <brpc/controller.h>
#include <brpc/channel.h>
#include "../connpool/sqlconnpool.h"
#include "../connpool/sqlconnRAII.h"
#include "../connpool/redisconnpool.h"
#include "../connpool/redisconnRAII.h"

namespace NLP {
    class SearchServiceImp: public SearchService
    {
        public:
            SearchServiceImp() {
                nlp_client.Init("10.77.200.63:8003", &op);
                _sql_pool->init("10.77.200.63", 3306, "root", "liuhaiyang210", "webserver", 5);
                _redis_pool->init("10.77.200.63", 6379, 5);
            };

            virtual ~SearchServiceImp() {};
            void query(
                google::protobuf::RpcController *cntl_base,
                const SearchRequest *request,
                SearchResponse *response,
                google::protobuf::Closure *done
            )
            {
                brpc::ClosureGuard guard_done(done);
                brpc::Controller *cntl = static_cast<brpc::Controller *>(cntl_base);
                LOG(INFO) << "query = " << request->query();

                // 分词处理
                NLP::SegmentRequest segment_request;
                NLP::SegmentResponse segment_response;
                NLP::SegmentService_Stub segment_stub(&nlp_client);
                
                brpc::Controller req_cntl;
                segment_request.set_sentence(request->query());
                segment_stub.cut(&req_cntl, &segment_request, &segment_response, NULL);

                redisContext* rconn;
                RedisConnRAII(&rconn,  RedisConnPool::getInstance());
                std::unordered_map<std::string, int> qtf_map;
                for (auto it: segment_response.result())
                {
                    LOG(INFO) << "word = " << it.token() << " qtf = " << it.tf();
                    qtf_map[it.token()] = it.tf();

                    // 添加热门查询到redis
                    redisReply *reply;
                    std::string sql = "ZINCRBY myzset 1 " + it.token();
                    reply = (redisReply*)redisCommand(rconn, sql.c_str());
                    freeReplyObject(reply);
                }
                
                // 召回处理
                NLP::RecallRequest recall_request;
                NLP::RecallResponse recall_response;
                NLP::RecallService_Stub recall_stub(&nlp_client);

                req_cntl.Reset();
                for (auto it: segment_response.result())
                {
                    recall_request.add_tokens(it.token());
                }
                recall_stub.recall(&req_cntl, &recall_request, &recall_response, NULL);
                // for (auto it: recall_response.result())
                // {
                //     LOG(INFO) << "word = " << it.word() << " df = " << it.df();
                //     for (auto i: it.index_item())
                //     {
                //         LOG(INFO) << "docid = " << i.docid() << " dtf = " << i.tf() << " dl = " << i.dl();
                //     }
                // }

                // 排序处理
                NLP::SortRequest sort_request;
                NLP::SortResponse sort_response;
                NLP::SortService_Stub sort_stub(&nlp_client);

                req_cntl.Reset();
                for (auto it: recall_response.result())
                {
                    auto req = sort_request.add_item();
                    req->set_word(it.word());
                    req->set_df(it.df());
                    req->set_qtf(qtf_map[it.word()]);
                    for (auto item: it.index_item())
                    {
                        auto i = req->add_index_item();
                        i->set_docid(item.docid());
                        i->set_tf(item.tf());
                        i->set_dl(item.dl());
                    }
                }
                sort_stub.sort(&req_cntl, &sort_request, &sort_response, NULL);
                
                MYSQL* conn;
                SqlConnRAII(&conn,  SqlConnPool::getInstance());
                for (auto item: sort_response.result())
                {
                    LOG(INFO) << "DocId = " << item.docid() << " Score = " << item.score();
                    // 查询 mysql
                    MYSQL_RES *res = nullptr;
                    mysql_query(conn, "SET NAMES UTF8");
                    std::string sql = "select * from news where id = " + intToString(item.docid()) + ";";
                    if(mysql_query(conn, sql.c_str())) { 
                        mysql_free_result(res);
                        continue;
                    }
                    res = mysql_store_result(conn);
                    while(MYSQL_ROW row = mysql_fetch_row(res)) {
                        // 结果返回
                        LOG(INFO) << "DocId = " << item.docid() << " title = " << row[1];
                        auto res = response->add_result();
                        res->set_docid(item.docid());
                        res->set_score(item.score());
                        res->set_title(row[1]);
                        res->set_content(row[2]);
                        res->set_url(row[3]);
                    }
                    mysql_free_result(res);
                }
            }

            void hot(
                google::protobuf::RpcController *cntl_base,
                const SearchHotRequest *request,
                SearchHotResponse *response,
                google::protobuf::Closure *done
            )
            {
                brpc::ClosureGuard guard_done(done);
                brpc::Controller *cntl = static_cast<brpc::Controller *>(cntl_base);

                redisContext* rconn;
                RedisConnRAII(&rconn,  RedisConnPool::getInstance());

                redisReply *reply;
                std::string sql = "zrevrange myzset 0 5";
                reply = (redisReply*)redisCommand(rconn, sql.c_str());
                for (int i=0; i < reply->elements; ++i)
                {
                    auto it = reply->element[i];
                    response->add_result(it->str);
                }
                freeReplyObject(reply);
            }

        private:
            brpc::Channel nlp_client;
            brpc::ChannelOptions op;
            SqlConnPool *_sql_pool = SqlConnPool::getInstance();
            RedisConnPool *_redis_pool = RedisConnPool::getInstance();
            std::string intToString(int v)
            {
                char buf[32] = {0};
                snprintf(buf, sizeof(buf), "%u", v);
            
                std::string str = buf;
                return str;
            }
    };
}