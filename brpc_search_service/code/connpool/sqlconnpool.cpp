
/*
* @Author       : hiyoung
* @Date         : 2021/09/04 11:33:22
* @copyleft Apache 2.0
*/

#include "sqlconnpool.h"

std::mutex _mtx;


SqlConnPool *SqlConnPool::mInstance = nullptr;

SqlConnPool *SqlConnPool::getInstance()
{
    if (mInstance == nullptr)
    {
        std::lock_guard<std::mutex> locker(_mtx);
        if  (mInstance == nullptr)
        {
            mInstance = new SqlConnPool();
        }
    }
    return mInstance;
}

void SqlConnPool::init(
    const char *host, int port, 
    const char *user, const char *password, 
    const char *dbName, int connSize
    )
{
    assert(connSize > 0);
    for (int i=0; i < connSize; ++i)
    {
        MYSQL *conn = mysql_init(nullptr);
        if (!conn)
        {
            return;
        }

        conn = mysql_real_connect(conn, host, user, password, dbName, port, nullptr, 0);
        if (!conn)
        {
            return;
        }

        _queue.emplace(conn);
    }

    sem_init(&_sem, 0, connSize);
}

MYSQL *SqlConnPool::getConn()
{
    MYSQL *conn = nullptr;
    if (_queue.empty())
    {
        return conn;
    }
    sem_wait(&_sem);
    {
        std::lock_guard<std::mutex> locker(_mtx);
        conn = _queue.front();
        _queue.pop();
    }
    return conn;
}

void SqlConnPool::freeConn(MYSQL *conn)
{
    assert(conn);
    std::lock_guard<std::mutex> locker(_mtx);
    _queue.emplace(conn);
    sem_post(&_sem);
}

void SqlConnPool::close()
{
    std::lock_guard<std::mutex> locker(_mtx);
    while (!_queue.empty())
    {
        auto it = _queue.front();
        _queue.pop();
        mysql_close(it);
    }
    mysql_library_end();
}

int SqlConnPool::getFreeConnCount()
{
    std::lock_guard<std::mutex> locker(_mtx);
    return _queue.size();
}

SqlConnPool::~SqlConnPool()
{
    close();
}