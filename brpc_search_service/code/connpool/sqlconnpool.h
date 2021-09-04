/*
* @Author       : hiyoung
* @Date         : 2021/09/04 11:33:30
* @copyleft Apache 2.0
*/

#ifndef __SQLCONNPOOL_H_
#define __SQLCONNPOOL_H_

#include <mysql/mysql.h>
#include <semaphore.h>
#include <mutex>
#include <queue>
#include <assert.h>


class SqlConnPool
{
    public:
        static SqlConnPool *getInstance();
        MYSQL* getConn();
        void freeConn(MYSQL *conn);
        int getFreeConnCount();
        void init(const char *host, int port, const char *user, const char *password, const char *dbName, int connSize);
        void close();
    private:
        static SqlConnPool *mInstance;
        SqlConnPool() = default;
        ~SqlConnPool();
        SqlConnPool(const SqlConnPool &other) = delete;
        SqlConnPool &operator=(const SqlConnPool &other) = delete;

        sem_t _sem;
        std::queue<MYSQL *> _queue;
};

#endif // __SQLCONNPOOL_H_