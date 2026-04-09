//
// Created by ntt12 on 4/9/2026.
//

#include "OrderDiscounts.h"

int OrderDiscounts::getODId() const {
    return ODId;
}
int OrderDiscounts::getOrderId() const {
    return OrderId;
}
int OrderDiscounts::getDiscountId() const {
    return DiscountId;
}
int OrderDiscounts::getAppliedValue() const {
    return appliedValue;
}

void OrderDiscounts::setODId(const int newODId) {
    ODId = newODId;
}
void OrderDiscounts::setOrderId(const int newOrderId) {
    OrderId = newOrderId;
}
void OrderDiscounts::setDiscountId(const int newDiscountId) {
    DiscountId = newDiscountId;
}
void OrderDiscounts::setAppliedValue(const int newAppliedValue) {
    appliedValue = newAppliedValue;
}

void OrderDiscounts::edit() {
    std::cout <<"Enter new value: "; std::cin >> appliedValue;
}
void OrderDiscounts::display() const {
    std::cout << ODId;
}