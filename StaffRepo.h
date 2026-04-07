//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_STAFFREPO_H
#define POINT_OF_SALE_STAFFREPO_H
#include "DatabaseSRC/DBContext/DBContext.h"
#include <vector>

#include "Employee.h"

class StaffRepo {
    DBContext& db;
public:
    StaffRepo(DBContext& context);
    std::vector<Employee> getAll() {
        std::vector<Employee> list;
        db.execute("SELECT PinHash FROM Staffs;");
        SQLHSTMT stmt = db.getStmt();
        SQLPOINTER PinHash;
        while (SQLFetch(stmt) == SQL_SUCCESS) {
            Employee pd;

            SQLGetData(stmt, 4, SQL_C_CHAR, PinHash, sizeof(PinHash), NULL);

            pd.setPinHash((char*)PinHash);

            list.push_back(pd);
        }
        db.clearStmt();
        return list;
    }
};


#endif //POINT_OF_SALE_STAFFREPO_H