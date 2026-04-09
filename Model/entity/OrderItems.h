#ifndef POINT_OF_SALE_ORDERITEMS_H
#define POINT_OF_SALE_ORDERITEMS_H
#include <string>

class OrderItems {
private:
    int OIId, OrderId, ProdId, Quantity;
    double UnitPrice;
    std::string SizeLabel;
    std::string Note;
public:
    OrderItems() : OIId(), OrderId(), ProdId(), Quantity(), UnitPrice(0.0), SizeLabel(""), Note("") {}

    int getOIId() const;
    int getOrderId() const;
    int getProdId() const;
    int getQuantity() const;
    double getUnitPrice() const;
    std::string getSizeLabel() const;
    std::string getNote() const;

    void setOIId(int newOIId);
    void setOrderId(int newOrderId);
    void setProdId(int newProdId);
    void setQuantity(int newQuantity);
    void setUnitPrice(double newUnitPrice);
    void setSizeLabel(std::string newSizeLabel);
    void setNote(std::string newNote);

    virtual void edit();
    virtual void display() const;
    virtual ~OrderItems() {}
};

#endif //POINT_OF_SALE_ORDERITEMS_H