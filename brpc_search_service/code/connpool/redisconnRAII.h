/*
* @Author       : hiyoung
* @Date         : 2021/09/04 11:53:25
* @copyleft Apache 2.0
*/

#ifndef _REDIS_COON_RAII_H_
#define _REDIS_COON_RAII_H_

#include "redisconnpool.h"

class RedisConnRAII
{
    public:
        RedisConnRAII(redisContext **conn, RedisConnPool *pool)
        {
            *conn = pool->getConn();
            _conn = *conn;
            _pool = pool;
        }
        ~RedisConnRAII()
        {
            if (_conn)
            {
                _pool->freeConn(_conn);
            }
        }
    private:
        redisContext *_conn;
        RedisConnPool *_pool;
};

#endif // _REDIS_COON_RAII_H_