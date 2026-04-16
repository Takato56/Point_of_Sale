#ifndef POINT_OF_SALE_ORDERITEMS_H
#define POINT_OF_SALE_ORDERITEMS_H
#include <string>

class OrderItems {
private:
    int oiId = 0;
    int orderId = 0;
    int prodId = 0;
    int quantity = 0;
    double unitPrice = 0.0;
    std::string sizeLabel;
    std::string note;
public:
    OrderItems() = default;

    [[nodiscard]] int getOIId() const;
    [[nodiscard]] int getOrderId() const;
    [[nodiscard]] int getProdId() const;
    [[nodiscard]] int getQuantity() const;
    [[nodiscard]] double getUnitPrice() const;
    [[nodiscard]] const std::string& getSizeLabel() const;
    [[nodiscard]] const std::string& getNote() const;

    void setOIId(int newOIId);
    void setOrderId(int newOrderId);
    void setProdId(int newProdId);
    void setQuantity(int newQuantity);
    void setUnitPrice(double newUnitPrice);
    void setSizeLabel(const std::string& newSizeLabel);
    void setNote(const std::string& newNote);

    virtual ~OrderItems() = default;
};

#endif //POINT_OF_SALE_ORDERITEMS_H