//
// Created by ntt12 on 4/8/2026.
//

#ifndef POINT_OF_SALE_ORDERITEMS_H
#define POINT_OF_SALE_ORDERITEMS_H
#include <string>


class OrderItems {
private:
    int OIId, OrderId, PVId, Quantity, UnitPrice;
    std::string Note;
public:
    OrderItems() : OIId(), OrderId(), PVId(), Quantity(), UnitPrice(), Note("") {}

    int getOIId() const;
    int getOrderId() const;
    int getPVId() const;
    int getQuantity() const;
    int getUnitPrice() const;
    std::string getNote() const;

    void setOIId(int newOIId);
    void setOrderId(int newOrderId);
    void setPVId(int newPVId);
    void setQuantity(int newQuantity);
    void setUnitPrice(int newUnitPrice);
    void setNote(std::string newNote);

    virtual void edit();
    virtual void display() const;
    virtual ~OrderItems() {}
};


#endif //POINT_OF_SALE_ORDERITEMS_H