#ifndef POINT_OF_SALE_ORDERS_H
#define POINT_OF_SALE_ORDERS_H
#include <iostream>

class Orders {
private:
    int OrderId, StaffId, CustId, OrderCardId;
    std::string CreatedAt;
    bool Status;
public:
    Orders() : OrderId(), StaffId(), CustId(), OrderCardId(), CreatedAt(""), Status(false) {}

    int getOrderId() const;
    int getStaffId() const;
    int getCustId() const;
    int getOrderCardId() const;
    bool isPaid() const;

    std::string getCreatedAt() const;

    void setOrderId(int newOrderId);
    void setStaffId(int newStaffId);
    void setCustId(int newCustId);
    void setOrderCardId(int newOrderCardId);
    void setCreatedAt(std::string newCreatedAt);
    void setStatus(bool newStatus);

    virtual void edit();
    virtual void display() const;

    virtual ~Orders(){}
};

#endif //POINT_OF_SALE_ORDERS_H