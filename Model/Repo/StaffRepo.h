//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_STAFFREPO_H
#define POINT_OF_SALE_STAFFREPO_H
#include "../DatabaseSRC/DBContext/DBContext.h"
#include <vector>

#include "../../Model/entity/Employee.h"

class StaffRepo {
private:
    DBContext& db;
public:
    StaffRepo(DBContext& context) : db(context) {}
    // void addStaff();
};


#endif //POINT_OF_SALE_STAFFREPO_H