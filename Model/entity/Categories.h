#ifndef POINT_OF_SALE_CATEGORIES_H
#define POINT_OF_SALE_CATEGORIES_H
#include <string>
#include <iostream>

class Categories {
private:
    std::string cateName;
    int cateId = 0;
    int displayOrder = 0;
public:
    Categories() = default;
    Categories(const std::string& name, int id, int order);

    [[nodiscard]] const std::string& getCateName() const;
    [[nodiscard]] int getCateId() const;
    [[nodiscard]] int getDisplayOrder() const;

    void setCateName(const std::string& newCateName);
    void setCateId(int newCateId);
    void setDisplayOrder(int displayOrder);

    [[nodiscard]] std::string toString() const;

    virtual ~Categories() = default;
};

#endif //POINT_OF_SALE_CATEGORIES_H