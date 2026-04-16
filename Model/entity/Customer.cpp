#include "Customer.h"

const std::string& Customer::getCustName() const { return custName; }
const std::string& Customer::getCustPhone() const { return custPhone; }
int Customer::getCustId() const { return custId; }
int Customer::getPoint() const { return point; }

void Customer::setCustName(const std::string& newCustName) { custName = newCustName; }
void Customer::setCustPhone(const std::string& newCustPhone) { custPhone = newCustPhone; }
void Customer::setCustId(int newCustId) { custId = newCustId; }
void Customer::setPoint(int newPoint) { point = newPoint; }

std::string Customer::toString() const {
    return std::to_string(custId) + " | " + custName + " | " + custPhone + " | " + std::to_string(point);
}