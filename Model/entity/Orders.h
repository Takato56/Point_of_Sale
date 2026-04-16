#ifndef POINT_OF_SALE_ORDERS_H
#define POINT_OF_SALE_ORDERS_H
#include <string>

class Orders {
private:
    int orderId = 0;
    int staffId = 0;
    int custId = 0;
    int orderCardId = 0;
    std::string createdAt;
    bool status = false;
public:
    Orders() = default;

    [[nodiscard]] int getOrderId() const;
    [[nodiscard]] int getStaffId() const;
    [[nodiscard]] int getCustId() const;
    [[nodiscard]] int getOrderCardId() const;
    [[nodiscard]] bool isPaid() const;
    [[nodiscard]] const std::string& getCreatedAt() const;

    void setOrderId(int newOrderId);
    void setStaffId(int newStaffId);
    void setCustId(int newCustId);
    void setOrderCardId(int newOrderCardId);
    void setCreatedAt(const std::string& newCreatedAt);
    void setStatus(bool newStatus);

    virtual ~Orders() = default;
};

#endif //POINT_OF_SALE_ORDERS_H