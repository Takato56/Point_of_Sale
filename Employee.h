//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_EMPLOYEE_H
#define POINT_OF_SALE_EMPLOYEE_H
#include <iostream>
#include <string>


class Employee {
    std::string name;
    std::string pinHash;
public:
    Employee();
    virtual void showInterface();
    void orderItem();
    std::string getPinHash();
    void setPinHash(std::string pinHash);
    std::string getName();
    void setName(std::string name);
    std::string toString();
};


#endif //POINT_OF_SALE_EMPLOYEE_H