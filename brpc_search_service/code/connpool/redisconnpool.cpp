/*
* @Author       : hiyoung
* @Date         : 2021/09/04 11:38:14
* @copyleft Apache 2.0
*/

#include "redisconnpool.h"

std::mutex _rmtx;


RedisConnPool *RedisConnPool::mInstance = nullptr;

RedisConnPool *RedisConnPool::getInstance()
{
    if (mInstance == nullptr)
    {
        std::lock_guard<std::mutex> locker(_rmtx);
        if  (mInstance == nullptr)
        {
            mInstance = new RedisConnPool();
        }
    }
    return mInstance;
}

void RedisConnPool::init(const char *host, int port, int connSize)
{
    assert(connSize > 0);
    for (int i=0; i < connSize; ++i)
    {
        redisContext* conn = redisConnect(host, port);
        if (!conn)
        {
            return;
        }

        _queue.emplace(conn);
    }

    sem_init(&_sem, 0, connSize);
}

redisContext *RedisConnPool::getConn()
{
    redisContext *conn = nullptr;
    if (_queue.empty())
    {
        return conn;
    }
    sem_wait(&_sem);
    {
        std::lock_guard<std::mutex> locker(_rmtx);
        conn = _queue.front();
        _queue.pop();
    }
    return conn;
}

void RedisConnPool::freeConn(redisContext *conn)
{
    assert(conn);
    std::lock_guard<std::mutex> locker(_rmtx);
    _queue.emplace(conn);
    sem_post(&_sem);
}

void RedisConnPool::close()
{
    std::lock_guard<std::mutex> locker(_rmtx);
    while (!_queue.empty())
    {
        auto it = _queue.front();
        _queue.pop();
        redisFree(it);
    }
    // mysql_library_end();
}

int RedisConnPool::getFreeConnCount()
{
    std::lock_guard<std::mutex> locker(_rmtx);
    return _queue.size();
}

RedisConnPool::~RedisConnPool()
{
    close();
}