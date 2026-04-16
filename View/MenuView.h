#ifndef POINT_OF_SALE_MENUVIEW_H
#define POINT_OF_SALE_MENUVIEW_H

#include <iostream>
#include <vector>
#include "../Model/entity/Categories.h"
#include "../Model/entity/Product.h"

class MenuView {
public:
    int showAndSelectCategories(const std::vector<Categories>& ct) const;
    void displayProductsByCategory(int cateId, const std::vector<Product>& pd) const;
    void showProductByCateId(const std::vector<Categories>& ct, const std::vector<Product>& pd) const;
    void showAllCategories(const std::vector<Categories>& categories) const;
};

#endif //POINT_OF_SALE_MENUVIEW_H