/*
* @Author       : hiyoung
* @Date         : 2021/09/01 20:38:15
* @copyleft Apache 2.0
*/

#include <fstream>
#include "base_service.pb.h"
#include <brpc/controller.h>
#include "../nlohmann/json.hpp"

namespace NLP {

    const char* const INVERT_INDEX_PATH = "/home/liuhaiyang/project/BRPC/brpc_nlp_service/news.json";

    class RecallServiceImp: public RecallService
    {
        public:
            RecallServiceImp() {
                load_invert_index();
            };
            virtual ~RecallServiceImp() {};
            void recall(
                google::protobuf::RpcController *cntl_base,
                const RecallRequest *request,
                RecallResponse *response,
                google::protobuf::Closure *done
            )
            {
                brpc::ClosureGuard guard_done(done);
                brpc::Controller *cntl = static_cast<brpc::Controller *>(cntl_base);
                for (auto word: request->tokens())
                {
                    if (!_json.contains(word)) {
                        LOG(INFO) << "not found the word " << word << " at invert index ";
                        continue;
                    }

                    LOG(INFO) << "request：" << word;
                    auto res = response->add_result();
                    res->set_word(word);
                    res->set_df(_json[word]["DF"]);
                    for (auto it: _json[word]["index_item"])
                    {
                        auto item = res->add_index_item();
                        item->set_docid(it["DocId"]);
                        item->set_tf(it["TF"]);
                        item->set_dl(it["dl"]);
                    }
                }
            }

            void load_invert_index() {
                std::ifstream i(INVERT_INDEX_PATH);
                i >> _json;
                LOG(INFO) << "加载倒排索引完成！";
            }

        private:
            nlohmann::json _json;

    };
}
