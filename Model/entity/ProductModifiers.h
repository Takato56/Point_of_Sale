#ifndef POINT_OF_SALE_PRODUCTMODIFIERS_H
#define POINT_OF_SALE_PRODUCTMODIFIERS_H

class ProductModifiers {
private:
    int pmId = 0;
    int prodId = 0;
    int modId = 0;
public:
    ProductModifiers() = default;

    [[nodiscard]] int getPMId() const;
    [[nodiscard]] int getProdId() const;
    [[nodiscard]] int getModId() const;

    void setPMId(int newPMId);
    void setProdId(int newProdId);
    void setModId(int newModId);

    virtual ~ProductModifiers() = default;
};

#endif //POINT_OF_SALE_PRODUCTMODIFIERS_H