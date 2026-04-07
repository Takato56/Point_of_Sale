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
    std::string getPinHash() {
        return pinHash;
    }
    void setPinHash(std::string pinHash) {
        this->pinHash = pinHash;
    }
    std::string getName() {
        return name;
    }
    void setName(std::string name) {
        this->name = name;
    }
    std::string toString() {
        return "Employee Name: " + this->getName() + "\nEmployee Pin: " + this->getPinHash() + "\n--------------------------------------------------\n";
    };
};


#endif //POINT_OF_SALE_EMPLOYEE_H