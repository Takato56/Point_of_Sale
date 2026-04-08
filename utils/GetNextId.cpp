//
// Created by ntt12 on 4/8/2026.
//

#include "GetNextId.h"

int GetNextId::getNextId() {
    int nextId = 1;
    db.execute("SELECT MAX(" +getColumn() + ") FROM" + getTable() + ";");
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