#include "OrderDiscounts.h"

int OrderDiscounts::getODId() const { return odId; }
int OrderDiscounts::getOrderId() const { return orderId; }
int OrderDiscounts::getDiscountId() const { return discountId; }
int OrderDiscounts::getAppliedValue() const { return appliedValue; }

void OrderDiscounts::setODId(int newODId) { odId = newODId; }
void OrderDiscounts::setOrderId(int newOrderId) { orderId = newOrderId; }
void OrderDiscounts::setDiscountId(int newDiscountId) { discountId = newDiscountId; }
void OrderDiscounts::setAppliedValue(int newAppliedValue) { appliedValue = newAppliedValue; }