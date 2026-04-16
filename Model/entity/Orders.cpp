#include "Orders.h"

int Orders::getOrderId() const { return orderId; }
int Orders::getStaffId() const { return staffId; }
int Orders::getCustId() const { return custId; }
int Orders::getOrderCardId() const { return orderCardId; }
const std::string& Orders::getCreatedAt() const { return createdAt; }
bool Orders::isPaid() const { return status; }

void Orders::setOrderId(int newOrderId) { orderId = newOrderId; }
void Orders::setStaffId(int newStaffId) { staffId = newStaffId; }
void Orders::setCustId(int newCustId) { custId = newCustId; }
void Orders::setOrderCardId(int newOrderCardId) { orderCardId = newOrderCardId; }
void Orders::setCreatedAt(const std::string& newCreatedAt) { createdAt = newCreatedAt; }
void Orders::setStatus(bool newStatus) { status = newStatus; }