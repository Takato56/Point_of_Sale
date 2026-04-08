//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_EMPLOYEE_H
#define POINT_OF_SALE_EMPLOYEE_H
#include <iostream>
#include <string>
enum Role {
    Staff = 1,
    Manager = 2
};

class Employee {
    std::string EmpName;
    std::string pinHash;
    Role role;
    std::string EmpPhone;
public:
    Employee() : EmpName(""), pinHash(""), role(), EmpPhone("") {}

    std::string getEmployeeName() const;
    std::string getEmployeePhone() const;
    Role getRole() const;
    std::string getPinHash() const;

    void setEmpName(std::string newEmpName);
    void setEmpPhone(std::string newEmpPhone);
    void setRole(Role newRole);
    void setPinHash(std::string newPinHash);

    virtual void edit();
    // virtual void display() const;
    virtual ~Employee() {}
};


#endif //POINT_OF_SALE_EMPLOYEE_H