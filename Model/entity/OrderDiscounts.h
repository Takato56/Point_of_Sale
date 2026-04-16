#ifndef POINT_OF_SALE_ORDERDISCOUNTS_H
#define POINT_OF_SALE_ORDERDISCOUNTS_H

class OrderDiscounts {
private:
    int odId = 0;
    int orderId = 0;
    int discountId = 0;
    int appliedValue = 0;
public:
    OrderDiscounts() = default;

    [[nodiscard]] int getODId() const;
    [[nodiscard]] int getOrderId() const;
    [[nodiscard]] int getDiscountId() const;
    [[nodiscard]] int getAppliedValue() const;

    void setODId(int newODId);
    void setOrderId(int newOrderId);
    void setDiscountId(int newDiscountId);
    void setAppliedValue(int newAppliedValue);

    virtual ~OrderDiscounts() = default;
};

#endif //POINT_OF_SALE_ORDERDISCOUNTS_H