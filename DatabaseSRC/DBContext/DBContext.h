//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_DBCONTEXT_H
#define POINT_OF_SALE_DBCONTEXT_H

#include <windows.h>
#include <sqlext.h>
#include <iostream>
#include <string>

#pragma comment(lib, "odbc32.lib")

class DBContext {
private:
    SQLHENV env{};
    SQLHDBC dbc{};
    SQLHSTMT stmt{};

    void showError(SQLHANDLE handle, SQLSMALLINT type);
public:
    DBContext() {
        SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
        SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);
        SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
    }
    bool connect(const std::string& connStr);
    bool execute(const std::string& query);
    SQLHSTMT getStmt();
    void clearStmt();

    ~DBContext() {
        clearStmt();
        if (dbc) {
            SQLDisconnect(dbc);
            SQLFreeHandle(SQL_HANDLE_DBC, dbc);
        }
        if (env) SQLFreeHandle(SQL_HANDLE_ENV, env);
    }
};
#endif //POINT_OF_SALE_DBCONTEXT_H