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
    int prodId;
    int CateId;
public:
    Product() : prodId(), prodName(""), CateId() {}

    Product(const std::string& n, int id) : prodName(n), prodId(id) {}

    std::string getProdName() const;
    int getProdId() const;
    int getProdPrice() const;
    int getCateId() const;

    void setProdName(std::string newName);
    void setProdId(int newId);
    void setProdPrice(int price);
    void setCateId(int newCateId);

    virtual void edit();
    virtual void display() const;
    virtual ~Product() {}

    std::string toString() const;
};


#endif //POINT_OF_SALE_PRODUCT_H