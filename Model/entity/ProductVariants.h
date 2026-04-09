#ifndef POINT_OF_SALE_PRODUCTVARIANS_H
#define POINT_OF_SALE_PRODUCTVARIANS_H
#include <string>

enum Size {
    Small = 1,
    Medium = 2,
    Large = 3
};

class ProductVariants {
private:
    int PVId;
    Size size;
    int ProdId;
public:
    ProductVariants() : PVId(), size(), ProdId() {}

    Size getSize() const;
    int getPVId() const;
    int getProdId() const;

    void setPVId(int newPVId);
    void setSize(Size newSize);
    void setProdId(int newProdId);

    virtual void edit();
    virtual void display() const;
    virtual ~ProductVariants() {}

    std::string toString() const;
};

#endif //POINT_OF_SALE_PRODUCTVARIANS_H