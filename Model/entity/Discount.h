#ifndef POINT_OF_SALE_DISCOUNT_H
#define POINT_OF_SALE_DISCOUNT_H
#include <string>

class Discount {
private:
    int discountId = 0;
    int value = 0;
    std::string code;
    std::string type;
    int isActive = 1;
public:
    Discount() = default;

    [[nodiscard]] int getDiscountId() const;
    [[nodiscard]] int getValue() const;
    [[nodiscard]] const std::string& getCode() const;
    [[nodiscard]] int getIsActive() const;
    [[nodiscard]] const std::string& getType() const;

    void setDiscountId(int newDiscountId);
    void setValue(int newValue);
    void setCode(const std::string& newCode);
    void setIsActive(int newIsActive);
    void setType(const std::string& newType);

    virtual ~Discount() = default;
};

#endif //POINT_OF_SALE_DISCOUNT_H