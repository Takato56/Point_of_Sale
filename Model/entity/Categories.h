//
// Created by ntt12 on 4/7/2026.
//

#ifndef POINT_OF_SALE_CATEGORIES_H
#define POINT_OF_SALE_CATEGORIES_H
#include <string>
#include <iostream>

class Categories {
private:
    std::string CateName;
    int CateId;
    int DisplayOrder;
public:
    Categories() : CateName(""), CateId(), DisplayOrder() {}

    Categories(const std::string &name, int id, int order);

    std::string getCateName() const;
    int getCateId() const;
    std::string getDisplayOrder() const;

    void setCateName(std::string newCateName);
    void setCateId(int newCateId);
    void setDisplayOrder(int displayOrder);

    virtual void editCate();
    virtual void displayCate() const;
    virtual ~Categories();

    std::string toString() const {
        return "ID: " + std::to_string(CateId) + " | Name: " + CateName;
    }
};


#endif //POINT_OF_SALE_CATEGORIES_H