//
// Created by admin on 4/7/2026.
//

#include "Employee.h"


Employee::Employee(int id, std::string name, std::string phoneNumber, std::string NewPinHash, std::string NewRole) {
    EmpId = id;
    EmpName = name;
    EmpPhoneNumber = phoneNumber;
    pinHash = NewPinHash;
    role = NewRole;
    isActive = true;
}

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

std::string Employee::getRole() const {
    return role;
}

void Employee::setRole(std::string NewRole) {
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