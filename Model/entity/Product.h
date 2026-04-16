#ifndef POINT_OF_SALE_PRODUCT_H
#define POINT_OF_SALE_PRODUCT_H
#include <string>

class Product {
private:
    std::string prodName;
    int prodId = 0;
    int cateId = 0;
    int prodPrice = 0;
public:
    Product() = default;

    [[nodiscard]] const std::string& getProdName() const;
    [[nodiscard]] int getProdId() const;
    [[nodiscard]] int getProdPrice() const;
    [[nodiscard]] int getCateId() const;

    void setProdName(const std::string& newName);
    void setProdId(int newId);
    void setProdPrice(int newPrice);
    void setCateId(int newCateId);

    [[nodiscard]] std::string toString() const;

    virtual ~Product() = default;
};

#endif //POINT_OF_SALE_PRODUCT_H