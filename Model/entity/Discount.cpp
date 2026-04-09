//
// Created by ntt12 on 4/9/2026.
//

#include "Discount.h"

int Discount::getDiscountId() const {
    return DiscountId;
}
int Discount::getValue() const {
    return Value;
}
std::string Discount::getCode() const {
    return Code;
}

void Discount::setDiscountId(const int newDiscountId) {
    DiscountId = newDiscountId;
}
void Discount::setValue(const int newValue) {
    Value = newValue;
}
void Discount::setCode(const std::string newCode) {
    Code = newCode;
}

void Discount::edit() {
    std::cout <<"Enter new discount code: ";
    std::cin.ignore();
    std::getline(std::cin,Code);
    std::cout <<"Enter new discount value: ";
    std::cin >> Value;
}
void Discount::display() const {
    std::cout << DiscountId;
}