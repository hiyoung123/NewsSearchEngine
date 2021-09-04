/*
* @Author       : hiyoung
* @Date         : 2021/09/04 11:33:43
* @copyleft Apache 2.0
*/

#ifndef _SQL_CONN_RAII_H_
#define _SQL_CONN_RAII_H_

#include "sqlconnpool.h"

class SqlConnRAII
{
    public:
        SqlConnRAII(MYSQL **conn, SqlConnPool *pool)
        {
            *conn = pool->getConn();
            _conn = *conn;
            _pool = pool;
        }
        ~SqlConnRAII()
        {
            if (_conn)
            {
                _pool->freeConn(_conn);
            }
        }
    private:
        MYSQL *_conn;
        SqlConnPool *_pool;
};

#endif // _SQL_CONN_RAII_H_