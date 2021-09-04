/*
* @Author       : hiyoung
* @Date         : 2021/09/02 00:09:00
* @copyleft Apache 2.0
*/

#include <math.h>
#include <algorithm> 
#include <vector>
#include <unordered_map>
#include "brpc/controller.h"
#include "base_service.pb.h"

namespace NLP {
    class SortServiceImp: public SortService
    {
        public:
            SortServiceImp() {};
            virtual ~SortServiceImp() {};
            void sort(
                google::protobuf::RpcController *cntl_base,
                const SortRequest *request,
                SortResponse *response,
                google::protobuf::Closure *done
            )
            {
                brpc::ClosureGuard guard_done(done);
                brpc::Controller *cntl = static_cast<brpc::Controller *>(cntl_base);

                std::unordered_map<int, float> doc_map;
                for (auto it: request->item())
                {
                    for (auto i: it.index_item())
                    {
                        LOG(INFO) << "Word = " << it.word() << " DF = " << it.df() << " qtf = " << it.qtf()
                        << " docid = " << i.docid() << " dtf = " << i.tf() << " dl = " << i.dl();
                        float score = bm25(it.qtf(), i.tf(), it.df(), i.dl(), 1000, 1.2, 1000, 0.5, 817);
                        doc_map[i.docid()] = doc_map[i.docid()] + score;
                    }
                }

                std::vector<std::pair<int, float>> vec;
                for (auto it: doc_map)
                {
                    LOG(INFO) << "docid = " << it.first << " socre = " << it.second;
                    vec.push_back(std::pair<int, float>(it.first, it.second) );
                }
                std::sort(vec.begin(), vec.end(), cmp);
                int num = 0;
                for (auto it: vec)
                {
                    if (num == 30)
                    {
                        break;
                    }
                    auto res = response->add_result();
                    res->set_docid(it.first);
                    res->set_score(it.second);
                    ++num;
                }
            }
            
        private:
            static float bm25(int qtf, int dtf, int df, int dl, int N, float k1, int k2, float b, int avdl)
            {
                return log(N/df) * ((k1+1)*dtf / ((1-b)+b*(dl/avdl))*k1 + dtf) * ((k2+1)*qtf / k2+qtf);
            }
            
            static bool cmp(std::pair<int, float> a, std::pair<int, float> b) {
                return a.second > b.second;
            }
    };
}