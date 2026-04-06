//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_BEVERAGE_H
#define POINT_OF_SALE_BEVERAGE_H
#include "Product.h"


class Beverage : public Product {
private:
    std::string size;
public:
    Beverage(const std::string& n, std::string id, int p);
    void display() const override;
    double calculatePrice() const;
};


#endif //POINT_OF_SALE_BEVERAGE_H