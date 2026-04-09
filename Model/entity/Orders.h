//
// Created by ntt12 on 4/9/2026.
//

#ifndef POINT_OF_SALE_ORDERS_H
#define POINT_OF_SALE_ORDERS_H
#include <iostream>

class Orders {
private:
    int OrderId, StaffId, CustId;
public:
    Orders() : OrderId(), StaffId(), CustId() {}

    int getOrderId() const;
    int getStaffId() const;
    int getCustId() const;

    void setOrderId(int newOrderId);
    void setStaffId(int newStaffId);
    void setCustId(int newCustId);

    virtual void edit();
    virtual void display() const;

    virtual ~Orders(){}
};


#endif //POINT_OF_SALE_ORDERS_H