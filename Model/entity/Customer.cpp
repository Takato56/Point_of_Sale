//
// Created by ntt12 on 4/8/2026.
//

#include "Customer.h"

std::string Customer::getCustName() const {
    return CustName;
}
std::string Customer::getCustPhone() const {
    return CustPhone;
}
int Customer::getCustId() const {
    return CustId;
}
int Customer::getPoint() const {
    return Point;
}

void Customer::setCustName(const std::string newCustName) {
    CustName = newCustName;
}
void Customer::setCustPhone(const std::string newCustPhone) {
    CustPhone = newCustPhone;
}
void Customer::setCustId(const int newCustId) {
    CustId = newCustId;
}
void Customer::setPoint(const int newPoint) {
    Point = newPoint;
}

void Customer::edit() {
    std::cout <<"Enter new CustName: ";
    std::cin.ignore();
    std::getline(std::cin,CustName);
    std::cout << "Enter new phone: ";
    std::cin.ignore();
    std::getline(std::cin,CustPhone);
    std::cout << "Enter new cust id: "; std::cin >> CustId;
    std::cout << "Enter new point: "; std::cin >> Point;
}

std::string Customer::toString() const {
    return std::to_string(CustId) + " | " + CustName + " | " + CustPhone + " | " + std::to_string(Point);
}

Customer::~Customer() {
}
