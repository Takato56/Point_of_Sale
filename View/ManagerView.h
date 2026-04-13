#ifndef POINT_OF_SALE_MANAGERVIEW_H
#define POINT_OF_SALE_MANAGERVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "../model/entity/Categories.h"
#include "../model/entity/Product.h"

class ManagerView {
public:
    void showManagerMenu() const;
    int getMenuChoice() const;

    std::string promptCategoryName() const;
    int promptDisplayOrder() const;

    int promptCategoryChoice(const std::vector<Categories>& categories) const;
    std::string promptProductName() const;
    int promptProductPrice() const;

    void showAllProducts(const std::vector<Product>& products) const;
    void showAllCategories(const std::vector<Categories>& categories) const;
    void showMessage(const std::string& msg) const;
};

#endif //POINT_OF_SALE_MANAGERVIEW_H