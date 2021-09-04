/*
* @Author       : hiyoung
* @Date         : 2021/09/01 20:38:23
* @copyleft Apache 2.0
*/

#include <string>
#include <vector>
#include <unordered_map>
#include "base_service.pb.h"
#include <brpc/controller.h>
#include "../cppjieba/Jieba.hpp"

namespace NLP {

    const char* const DICT_PATH = "/home/liuhaiyang/project/BRPC/brpc_nlp_service/dict/jieba.dict.utf8";
    const char* const HMM_PATH = "/home/liuhaiyang/project/BRPC/brpc_nlp_service/dict/hmm_model.utf8";
    const char* const USER_DICT_PATH = "/home/liuhaiyang/project/BRPC/brpc_nlp_service/dict/user.dict.utf8";
    const char* const IDF_PATH = "/home/liuhaiyang/project/BRPC/brpc_nlp_service/dict/idf.utf8";
    const char* const STOP_WORD_PATH = "/home/liuhaiyang/project/BRPC/brpc_nlp_service/dict/stop_words.utf8";

    class SegmentServiceImp: public SegmentService
    {
        public:
            SegmentServiceImp(): jieba(DICT_PATH,
                HMM_PATH,
                USER_DICT_PATH,
                IDF_PATH,
                STOP_WORD_PATH) {
                
            };
            virtual ~SegmentServiceImp() {};
            void cut(
                google::protobuf::RpcController *cntl_base, 
                const SegmentRequest *request,
                SegmentResponse *response,
                google::protobuf::Closure *done)
            {
                brpc::ClosureGuard guard_done(done);

                brpc::Controller *cntl = static_cast<brpc::Controller *>(cntl_base);
                std::string sentence = request->sentence();
                LOG(INFO) << "sentence = " << sentence;

                std::vector<std::string> words;
                jieba.Cut(sentence, words, true);
                
                std::unordered_map<std::string, int> word_map;

                for (std::string w: words)
                {
                    // 去停用词。
                    if (jieba.extractor.stopWords_.count(w) != 0)
                    {
                        continue;
                    }

                    // 统计词在查询中的 TF
                    if (word_map.count(w) != 0)
                    {
                        word_map[w] = word_map[w] + 1;
                    }
                    else
                    {
                        word_map[w] = 1;
                    }
                }    
                
                for (auto it: word_map)
                {
                    auto res = response->add_result();
                    res->set_token(it.first);
                    res->set_tf(it.second);
                }
            }
        private:
            cppjieba::Jieba jieba;

    };
}
