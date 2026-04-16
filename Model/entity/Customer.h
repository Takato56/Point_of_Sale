#ifndef POINT_OF_SALE_CUSTOMER_H
#define POINT_OF_SALE_CUSTOMER_H
#include <string>

class Customer {
private:
    int custId = 0;
    int point = 0;
    std::string custName;
    std::string custPhone;
public:
    Customer() = default;

    [[nodiscard]] const std::string& getCustName() const;
    [[nodiscard]] const std::string& getCustPhone() const;
    [[nodiscard]] int getCustId() const;
    [[nodiscard]] int getPoint() const;

    void setCustName(const std::string& newCustName);
    void setCustPhone(const std::string& newCustPhone);
    void setCustId(int newCustId);
    void setPoint(int newPoint);

    [[nodiscard]] std::string toString() const;

    virtual ~Customer() = default;
};

#endif //POINT_OF_SALE_CUSTOMER_H