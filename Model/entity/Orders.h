#ifndef POINT_OF_SALE_ORDERS_H
#define POINT_OF_SALE_ORDERS_H
#include <iostream>

class Orders {
private:
    int OrderId, StaffId, CustId, OrderCardId;
public:
    Orders() : OrderId(), StaffId(), CustId(), OrderCardId() {}

    int getOrderId() const;
    int getStaffId() const;
    int getCustId() const;
    int getOrderCardId() const;

    void setOrderId(int newOrderId);
    void setStaffId(int newStaffId);
    void setCustId(int newCustId);
    void setOrderCardId(int newOrderCardId);

    virtual void edit();
    virtual void display() const;

    virtual ~Orders(){}
};

#endif //POINT_OF_SALE_ORDERS_H