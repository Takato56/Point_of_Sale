//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_MENU_H
#define POINT_OF_SALE_MENU_H
#include <vector>
#include "Product.h"
#include "Beverage.h"
class Menu {
private:
    std::vector<Product*> products;
    int beverageCount = 0;
public:
    void addProduct(Product* product) {
        if (dynamic_cast<Beverage*>(product)) {
            beverageCount++;
            products->set
        }
    }
    void editProduct(const std::string& name);
    void deleteProduct(const std::string& name);
};


#endif //POINT_OF_SALE_MENU_H