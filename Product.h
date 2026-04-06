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
    Product() : prodId(""), prodName(""), prodPrice(0) {}

    Product(const std::string& n, std::string id, int p) : prodName(n), prodId(id), prodPrice(p) {}

    std::string getProdName() const;
    std::string getProdId() const;
    int getProdPrice() const;

    void setProdName(std::string newName);
    void setProdId(std::string newId);
    void setProdPrice(int price);

    virtual void edit();
    virtual void display() const;
    virtual ~Product() {}

    std::string toString() const;
};


#endif //POINT_OF_SALE_PRODUCT_H