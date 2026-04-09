//
// Created by ntt12 on 4/9/2026.
//

#ifndef POINT_OF_SALE_PAYMENT_H
#define POINT_OF_SALE_PAYMENT_H
#include <string>
#include <iostream>

class Payments {
private:
    int PayId, OrderId;
    double Amount;
    std::string Method;
public:
    Payments() : PayId(), OrderId(), Amount(0.0), Method("") {}

    int getPayId() const;
    int getOrderId() const;
    double getAmount() const;
    std::string getMethod() const;

    void setPayId(int newPayId);
    void setOrderId(int newOrderId);
    void setAmount(double newAmount);
    void setMethod(std::string newMethod);

    virtual void edit();
    virtual void display() const;
    virtual ~Payments() {}
};


#endif //POINT_OF_SALE_PAYMENT_H