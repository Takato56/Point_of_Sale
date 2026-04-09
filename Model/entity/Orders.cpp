//
// Created by ntt12 on 4/9/2026.
//

#include "Orders.h"

int Orders::getOrderId() const {
    return OrderId;
}
int Orders::getStaffId() const {
    return StaffId;
}
int Orders::getCustId() const {
    return CustId;
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

void Orders::edit() {
    std::cout <<"Enter new StaffId: "; std::cin >> StaffId;
    std::cout <<"Enter new CustId: "; std::cin >> CustId;
}
void Orders::display() const {
    std::cout << OrderId;
}