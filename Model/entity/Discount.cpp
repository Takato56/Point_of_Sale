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
int Discount::getIsActive() const {
    return isActive;
}

std::string Discount::getType() const {
    return Type;
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
void Discount::setIsActive(const int newIsActive) {
    isActive = newIsActive;
}
void Discount::setType(const std::string newType) {
    Type = newType;
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