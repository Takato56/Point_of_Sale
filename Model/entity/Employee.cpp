//
// Created by admin on 4/7/2026.
//

#include "Employee.h"
std::string Employee::getEmployeeName() const {
    return EmpName;
}

std::string Employee::getEmployeePhone() const {
    return EmpPhone;
}
Role Employee::getRole() const {
    return role;
}
std::string Employee::getPinHash() const {
    return pinHash;
}

void Employee::setEmpName(std::string newEmpName) {
    EmpName = newEmpName;
}
void Employee::setEmpPhone(std::string newEmpPhone) {
    EmpPhone = newEmpPhone;
}
void Employee::setRole(Role newRole) {
    role = newRole;
}
void Employee::setPinHash(std::string newPinHash) {
    pinHash = newPinHash;
}

void Employee::edit() {
    std::cout << "" << std::endl;
}
// void Employee::display()