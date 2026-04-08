//
// Created by ntt12 on 4/3/2026.
//

#include "DBContext.h"
#include "DBContext.h"
void DBContext::showError(SQLHANDLE handle, SQLSMALLINT type) {
    SQLCHAR msg[256];
    if (SQLGetDiagRec(type, handle, 1, NULL, NULL, msg, sizeof(msg), NULL) == SQL_SUCCESS) {
        std::cout << "Error: " << msg << std::endl;
    }
}

bool DBContext::connect(const std::string &connStr) {
    if (!SQL_SUCCEEDED(SQLDriverConnect(
            dbc, NULL,
            (SQLCHAR*) connStr.c_str(),
            SQL_NTS, NULL,0, NULL,
            SQL_DRIVER_COMPLETE))) {

        showError(dbc, SQL_HANDLE_DBC);
        return false;
            }
    return true;
}

bool DBContext::execute(const std::string& query) {
    SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);

    if (!SQL_SUCCEEDED(SQLExecDirect(stmt, (SQLCHAR*)query.c_str(), SQL_NTS))) {
        showError(stmt, SQL_HANDLE_STMT);
        return false;
    }
    return true;
}

SQLHSTMT DBContext::getStmt() {
    return stmt;
}

void DBContext::clearStmt() {
    if (stmt) {
        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
        stmt = nullptr;
    }
}