//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_MANAGER_H
#define POINT_OF_SALE_MANAGER_H
#include "Employee.h"


class Manager : public Employee {
public:
    Manager();
    Manager(const Employee& employee) : Employee(employee) {};

};


#endif //POINT_OF_SALE_MANAGER_H