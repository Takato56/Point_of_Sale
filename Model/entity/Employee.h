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
    int EmpId;
    std::string EmpName;
    std::string EmpPhoneNumber;
    std::string pinHash;
    std::string role;
    int isActive;
public:
    Employee() : EmpName(""), pinHash(""), role(), EmpPhoneNumber("") {}
    Employee(int id, std::string name, std::string phoneNumber, std::string pinHash, std::string role);
    virtual void showInterface();
    void orderItem();

    int getId() const;
    void setId(int id);
    std::string getName() const;
    void setName(std::string name);
    std::string getPhoneNumber() const;
    void setPhoneNumber(std::string phoneNumber);
    std::string getPinHash() const;
    void setPinHash(std::string pinHash);
    std::string getRole() const;
    void setRole(std::string role);
    int getIsActive() const;
    void setIsActive(int isActive);

    std::string toString();
    virtual void edit();
    virtual void display() const;
    virtual ~Employee() {}
};


#endif //POINT_OF_SALE_EMPLOYEE_H