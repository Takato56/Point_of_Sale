//
// Created by ntt12 on 4/8/2026.
//

#include "DataHelper.h"

int DataHelper::getNextId(DBContext& db, const std::string& tableName, const std::string& columnName) {
    int nextId = 1;
    std::string query = "SELECT MAX(" + columnName + ") FROM " + tableName + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER maxId;
    SQLLEN cbMaxId;

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLGetData(stmt, 1, SQL_C_SLONG, &maxId, 0, &cbMaxId);
        if (cbMaxId != SQL_NULL_DATA) {
            nextId = (int)maxId + 1;
        }
    }
    db.clearStmt();
    return nextId;
}