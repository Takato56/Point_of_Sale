//
// Created by admin on 4/7/2026.
//

#ifndef POINT_OF_SALE_EMPLOYEE_H
#define POINT_OF_SALE_EMPLOYEE_H
#include <iostream>
#include <string>
enum Role {
    Role_Staff = 1,
    Role_Manager = 2
};

class Employee {
    int EmpId;
    std::string EmpName;
    std::string EmpPhoneNumber;
    std::string pinHash;
    Role role;
    int isActive = 1;
public:
    Employee() : EmpId() ,EmpName(""), pinHash(""), role(), EmpPhoneNumber("") {}
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
    Role getRole() const;
    void setRole(Role newRole);
    int getIsActive() const;
    void setIsActive(int isActive);

    std::string toString();
    virtual void edit();
    virtual void display() const;
    virtual ~Employee() {}
};


#endif //POINT_OF_SALE_EMPLOYEE_H