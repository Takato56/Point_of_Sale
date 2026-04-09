//
// Created by ntt12 on 4/8/2026.
//

#ifndef POINT_OF_SALE_EMPLOYEEREPO_H
#define POINT_OF_SALE_EMPLOYEEREPO_H
#include <vector>

#include "../DatabaseSRC/DBContext/DBContext.h"
#include "../../utils/DataHelper.h"
#include "../entity/Employee.h"

class EmployeeRepo {
private:
    DBContext& db;
public:
    EmployeeRepo(DBContext& context) : db(context){}

    void addEmployee(Employee& employee);
    std::vector<Employee> getAll();
    Employee getById(int id);

    void update(const Employee& e);
    void remove(int id);

};


#endif //POINT_OF_SALE_EMPLOYEEREPO_H