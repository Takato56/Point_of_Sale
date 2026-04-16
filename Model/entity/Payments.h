#ifndef POINT_OF_SALE_PAYMENT_H
#define POINT_OF_SALE_PAYMENT_H
#include <string>

class Payments {
private:
    int payId = 0;
    int orderId = 0;
    double amount = 0.0;
    std::string method;
public:
    Payments() = default;

    [[nodiscard]] int getPayId() const;
    [[nodiscard]] int getOrderId() const;
    [[nodiscard]] double getAmount() const;
    [[nodiscard]] const std::string& getMethod() const;

    void setPayId(int newPayId);
    void setOrderId(int newOrderId);
    void setAmount(double newAmount);
    void setMethod(const std::string& newMethod);

    virtual ~Payments() = default;
};

#endif //POINT_OF_SALE_PAYMENT_H