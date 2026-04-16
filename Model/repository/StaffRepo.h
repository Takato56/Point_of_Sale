//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_STAFFREPO_H
#define POINT_OF_SALE_STAFFREPO_H
#include "../database/DBContext.h"
#include "../../utils/DataHelper.h"
#include <vector>
#include "../../Model/entity/Staff.h"

class StaffRepo {
private:
    DBContext& db;
public:
    StaffRepo(DBContext& context) : db(context) {}
    void addStaff(Staff& employee);
    std::vector<Staff> getAll();
    Staff getById(int id);
    Staff getByPhone(const std::string& phone);
    void update(const Staff& employee);
    void remove(int id);

    std::string roleToString(Role r);
    Role stringToRole(const std::string& str);
};


#endif //POINT_OF_SALE_STAFFREPO_H