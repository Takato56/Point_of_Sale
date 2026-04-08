//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_MENU_H
#define POINT_OF_SALE_MENU_H
#include <vector>
#include "../model/entity/Product.h"
class Menu {
private:
    std::vector<Product*> menu;
    int beverageCount = 0;
public:
    void addProduct(Product* newProducts);
    void editProduct(const std::string& name);
    void deleteProduct(const std::string& name);
};


#endif //POINT_OF_SALE_MENU_H