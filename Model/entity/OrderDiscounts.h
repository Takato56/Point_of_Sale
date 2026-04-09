//
// Created by ntt12 on 4/9/2026.
//

#ifndef POINT_OF_SALE_ORDERDISCOUNTS_H
#define POINT_OF_SALE_ORDERDISCOUNTS_H
#include <iostream>

class OrderDiscounts {
private:
    int ODId, OrderId, DiscountId, appliedValue;
public:
    OrderDiscounts() : ODId(), OrderId(), DiscountId(), appliedValue() {}

    int getODId() const;
    int getOrderId() const;
    int getDiscountId() const;
    int getAppliedValue() const;

    void setODId(int newODId);
    void setOrderId(int newOrderId);
    void setDiscountId(int newDiscountId);
    void setAppliedValue(int newAppliedValue);

    virtual void edit();
    virtual void display() const;
    virtual ~OrderDiscounts() {}
};


#endif //POINT_OF_SALE_ORDERDISCOUNTS_H