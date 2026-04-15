//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_STAFFREPO_H
#define POINT_OF_SALE_STAFFREPO_H
#include "../database/DBContext.h"
#include "../../utils/DataHelper.h"
#include <vector>
#include "../../Model/entity/Employee.h"

class StaffRepo {
private:
    DBContext& db;
public:
    StaffRepo(DBContext& context) : db(context) {}
    void addStaff(Employee& employee);
    std::vector<Employee> getAll();
    Employee getById(int id);
    Employee getByPhone(const std::string& phone);
    void update(const Employee& employee);
    void remove(int id);

    std::string roleToString(Role r);
    Role stringToRole(const std::string& str);
};


#endif //POINT_OF_SALE_STAFFREPO_H