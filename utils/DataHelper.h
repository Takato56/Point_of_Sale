//
// Created by ntt12 on 4/8/2026.
//

#ifndef POINT_OF_SALE_GETNEXTID_H
#define POINT_OF_SALE_GETNEXTID_H
#include "../model/database/DBContext.h"


class DataHelper {
public:
    static int getNextId(DBContext& db, const std::string& tableName, const std::string& columnName);

};


#endif //POINT_OF_SALE_GETNEXTID_H