//
// Created by ntt12 on 4/8/2026.
//

#ifndef POINT_OF_SALE_GETNEXTID_H
#define POINT_OF_SALE_GETNEXTID_H
#include "../model/DatabaseSRC/DBContext/DBContext.h"


class GetNextId {
private:
    DBContext& db;
    std::string column, table;
public:
    GetNextId(DBContext& db) : db(db) {}
    std::string getColumn() { return column; }
    std::string getTable() { return table; }

    void setColumn(const std::string newColumn) { column = newColumn; }
    void setTable(const std::string newTable) { table = newTable; }
    int getNextId();
};


#endif //POINT_OF_SALE_GETNEXTID_H