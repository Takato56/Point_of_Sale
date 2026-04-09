//
// Created by admin on 4/7/2026.
//

#include "Employee.h"

void Employee::showInterface() {
}

void Employee::orderItem() {
}

int Employee::getId() const {
    return EmpId;
}

void Employee::setId(int id) {
    EmpId = id;
}

std::string Employee::getName() const {
    return EmpName;
}

void Employee::setName(std::string name) {
    EmpName = name;
}

std::string Employee::getPhoneNumber() const {
    return EmpPhoneNumber;
}

void Employee::setPhoneNumber(std::string phoneNumber) {
    EmpPhoneNumber = phoneNumber;
}

std::string Employee::getPinHash() const {
    return pinHash;
}

void Employee::setPinHash(std::string NewPinHash) {
    pinHash = NewPinHash;
}

Role Employee::getRole() const {
    return role;
}

void Employee::setRole(Role NewRole) {
    role = NewRole;
}

int Employee::getIsActive() const {
    return isActive;
}

void Employee::setIsActive(int NewIsActive) {
    isActive = NewIsActive;
}

std::string Employee::toString() {
    return EmpName;
}

void Employee::edit() {
    std::cout <<"Enter new employee name: ";
    std::cin.ignore();
    std::getline(std::cin, EmpName);
    std::cout << "Enter new phone number: ";
    std::getline(std::cin, EmpPhoneNumber);
}

void Employee::display() const{
    std::cout << EmpId;
}