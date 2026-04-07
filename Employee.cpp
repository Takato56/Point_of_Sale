//
// Created by admin on 4/7/2026.
//

#include "Employee.h"

std::string Employee::getPinHash() {
    return pinHash;
}

void Employee::setPinHash(std::string pinHash) {
    this->pinHash = pinHash;
}

std::string Employee::getName() {
    return name;
}

void Employee::setName(std::string name) {
    this->name = name;
}

std::string Employee::toString() {
    return "Employee Name: " + this->getName() + "\nEmployee Pin: " + this->getPinHash() + "\n--------------------------------------------------\n";
};