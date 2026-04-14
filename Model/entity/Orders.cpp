#include "Orders.h"
#include <iostream>

int Orders::getOrderId() const {
    return OrderId;
}
int Orders::getStaffId() const {
    return StaffId;
}
int Orders::getCustId() const {
    return CustId;
}
int Orders::getOrderCardId() const {
    return OrderCardId;
}

std::string Orders::getCreatedAt() const {
    return CreatedAt;
}

void Orders::setOrderId(const int newOrderId) {
    OrderId = newOrderId;
}
void Orders::setStaffId(const int newStaffId) {
    StaffId = newStaffId;
}
void Orders::setCustId(const int newCustId) {
    CustId = newCustId;
}
void Orders::setOrderCardId(const int newOrderCardId) {
    OrderCardId = newOrderCardId;
}
void Orders::setCreatedAt(const std::string newCreatedAt) {
    CreatedAt = newCreatedAt;
}

void Orders::edit() {
    std::cout << "Enter new StaffId: ";
    std::cin >> StaffId;
    std::cout << "Enter new CustId: ";
    std::cin >> CustId;
    std::cout << "Enter new OrderCardId: ";
    std::cin >> OrderCardId;
}

void Orders::display() const {
    std::cout << "OrderId: " << OrderId << "\n";
    std::cout << "StaffId: " << StaffId << "\n";
    std::cout << "CustId: " << CustId << "\n";
    std::cout << "OrderCardId: " << OrderCardId << "\n";
}