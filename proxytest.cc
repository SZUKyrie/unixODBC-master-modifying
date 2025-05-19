#include <sql.h>
#include <sqlext.h>
#include <iostream>

// Debug Command
// libtool --mode=compile g++ -g -O0 -I /usr/local/unixODBC/include -c proxytest.cc -o proxytest.lo
// libtool --mode=link g++ proxytest.lo /usr/local/unixODBC/lib/libodbc.la -o proxytest

int main() {
    SQLHENV hEnv; // 环境句柄
    SQLHDBC hDbc; // 连接句柄
    SQLHSTMT hStmt; // 语句句柄
    
    // 分配环境句柄
    auto ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
    std::cout << ret << std::endl;
    // 设置环境属性
    ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
    std::cout << ret << std::endl;
    
    // 分配连接句柄
    ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
    std::cout << ret << std::endl;

    // 连接数据源
    ret = SQLConnect(hDbc, (SQLCHAR*)"my_pg_db", SQL_NTS, (SQLCHAR*)"hyh", SQL_NTS, (SQLCHAR*)"", SQL_NTS);
    // ret = SQLConnect(hDbc, (SQLCHAR*)"YASTEST", SQL_NTS, (SQLCHAR*)"sys", SQL_NTS, (SQLCHAR*)"KyrieHe2005!", SQL_NTS);
    std::cout << ret << std::endl;

    
    // 分配语句句柄
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
    std::cout << ret << std::endl;

    // 执行SQL语句
    ret = SQLExecDirect(hStmt, (SQLCHAR*)"INSERT INTO test01 VALUES (8, 8)", SQL_NTS);
    // ret = SQLExecDirect(hStmt, (SQLCHAR*)"SELECT * FROM test01", SQL_NTS);
    std::cout << ret << std::endl;

    
    // 清理资源
    ret = SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
    std::cout << ret << std::endl;
    
    ret = SQLDisconnect(hDbc);
    std::cout << ret << std::endl;

    ret = SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
    std::cout << ret << std::endl;

    ret = SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
    std::cout << ret << std::endl;

    return 0;
}

