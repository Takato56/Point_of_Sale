//
// Created by ntt12 on 4/9/2026.
//

#ifndef POINT_OF_SALE_DISCOUNT_H
#define POINT_OF_SALE_DISCOUNT_H
#include <iostream>
#include <string>

class Discount {
private:
    int DiscountId, Value;
    std::string Code, Type;
    int isActive = 1;
public:
    Discount() : DiscountId(), Value(), Code("") {}

    int getDiscountId() const;
    int getValue() const;
    std::string getCode() const;
    int getIsActive() const;
    std::string getType() const;

    void setDiscountId(int newDiscountId);
    void setValue(int newValue);
    void setCode(std::string newCode);
    void setIsActive(int newIsActive);
    void setType(std::string newType);

    virtual void edit();
    virtual void display() const;
    virtual ~Discount() {}
};


#endif //POINT_OF_SALE_DISCOUNT_H