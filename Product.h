//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_PRODUCT_H
#define POINT_OF_SALE_PRODUCT_H
#include <string>
#include <iostream>
class Product {
private:
    std::string prodName;
    std::string prodId;
    int prodPrice;
public:
    Product(std::string n, int price);

    std::string getProdName() const;
    std::string getProdId() const;
    int getProdPrice() const;

    void setProdName(const std::string& newName);
    void setProdId(const std::string& newProdId);
    void setProdPrice(int price);

    virtual void edit();
    virtual void display() const;
    virtual ~Product() {}
};


#endif //POINT_OF_SALE_PRODUCT_H