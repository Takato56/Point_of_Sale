//
// Created by ntt12 on 4/9/2026.
//

#include "Payments.h"

int Payments::getPayId() const {
    return PayId;
}
int Payments::getOrderId() const {
    return OrderId;
}
int Payments::getAmount() const {
    return Amount;
}
std::string Payments::getMethod() const {
    return Method;
}

void Payments::setPayId(int newPayId) {
    PayId = newPayId;
}
void Payments::setOrderId(int newOrderId) {
    OrderId = newOrderId;
}
void Payments::setAmount(int newAmount) {
    Amount = newAmount;
}
void Payments::setMethod(std::string newMethod) {
    Method = newMethod;
}

void Payments::edit() {
    std::cout <<"Enter new method: ";
    std::cin.ignore();
    std::getline(std::cin,Method);
    std::cout <<"Enter new amount: ";
    std::cin >> Amount;
}
void Payments::display() const {
    std::cout << PayId;
}
