//
// Created by ntt12 on 4/7/2026.
//

#ifndef POINT_OF_SALE_PRODUCTVARIANS_H
#define POINT_OF_SALE_PRODUCTVARIANS_H
#include <string>

enum Size {
    Small,
    Medium,
    Large
};

class ProductVariants {
private:
    int PVId;
    Size size;
    int price;
    int ProdId;
public:
    ProductVariants() : PVId(), size(), price(), ProdId() {}

    Size getSize() const;
    int getPVId() const;
    int getPrice() const;
    int getProdId() const;

    void setPVId(int newPVId);
    void setSize(std::string newSize);
    void setPrice(int newPrice);
    void setProdId(int newProdId);

    virtual void edit();
    virtual void display() const;
    virtual ~ProductVariants() {}

    std::string toString() const;
};


#endif //POINT_OF_SALE_PRODUCTVARIANS_H