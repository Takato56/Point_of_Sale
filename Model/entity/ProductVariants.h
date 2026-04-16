#ifndef POINT_OF_SALE_PRODUCTVARIANTS_H
#define POINT_OF_SALE_PRODUCTVARIANTS_H
#include <string>

enum Size {
    Small = 1,
    Medium = 2,
    Large = 3
};

class ProductVariants {
private:
    int pvId = 0;
    Size size = Small;
    int prodId = 0;
public:
    ProductVariants() = default;

    [[nodiscard]] Size getSize() const;
    [[nodiscard]] int getPVId() const;
    [[nodiscard]] int getProdId() const;

    void setPVId(int newPVId);
    void setSize(Size newSize);
    void setProdId(int newProdId);

    [[nodiscard]] std::string toString() const;

    virtual ~ProductVariants() = default;
};

#endif //POINT_OF_SALE_PRODUCTVARIANTS_H