/*
* @Author       : hiyoung
* @Date         : 2021/09/04 11:33:51
* @copyleft Apache 2.0
*/

#ifndef _REDIS_CONN_POOL_H_
#define _REDIS_CONN_POOL_H_

#include <hiredis/hiredis.h>
#include <semaphore.h>
#include <mutex>
#include <queue>
#include <assert.h>


class RedisConnPool
{
    public:
        static RedisConnPool *getInstance();
        redisContext *getConn();
        void freeConn(redisContext *conn);
        int getFreeConnCount();
        void init(const char *host, int port, int connSize);
        void close();
    private:
        static RedisConnPool *mInstance;
        RedisConnPool() = default;
        ~RedisConnPool();
        RedisConnPool(const RedisConnPool &other) = delete;
        RedisConnPool &operator=(const RedisConnPool &other) = delete;

        sem_t _sem;
        std::queue<redisContext *> _queue;
};


# endif // _REDIS_CONN_POOL_H_