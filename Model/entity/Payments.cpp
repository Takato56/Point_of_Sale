#include "Payments.h"

int Payments::getPayId() const { return payId; }
int Payments::getOrderId() const { return orderId; }
double Payments::getAmount() const { return amount; }
const std::string& Payments::getMethod() const { return method; }

void Payments::setPayId(int newPayId) { payId = newPayId; }
void Payments::setOrderId(int newOrderId) { orderId = newOrderId; }
void Payments::setAmount(double newAmount) { amount = newAmount; }
void Payments::setMethod(const std::string& newMethod) { method = newMethod; }