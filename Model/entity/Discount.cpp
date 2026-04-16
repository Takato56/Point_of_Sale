#include "Discount.h"

int Discount::getDiscountId() const { return discountId; }
int Discount::getValue() const { return value; }
const std::string& Discount::getCode() const { return code; }
int Discount::getIsActive() const { return isActive; }
const std::string& Discount::getType() const { return type; }

void Discount::setDiscountId(int newDiscountId) { discountId = newDiscountId; }
void Discount::setValue(int newValue) { value = newValue; }
void Discount::setCode(const std::string& newCode) { code = newCode; }
void Discount::setIsActive(int newIsActive) { isActive = newIsActive; }
void Discount::setType(const std::string& newType) { type = newType; }