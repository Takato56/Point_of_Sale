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
    std::vector<Product*> menu;
    int beverageCount = 0;
public:
    void addProduct(Product* newProducts) {
        menu.push_back(newProducts);
    }
    void editProduct(const std::string& name) {
        for (Product* product : menu) {
            if (product->getProdName() == name) {
                std::cout << "Product founded! Editing..." << std::endl;
                product->edit();
                return;
            }
        }
    }
    void deleteProduct(const std::string& name) {
        for (auto product = menu.begin(); product != menu.end(); ++product) {
            if ((*product)->getProdName() == name) {
                delete *product;
                menu.erase(product);
                std::cout << "Item deleted!\n" << std::endl;
                return;
            }
        }
    }
};


#endif //POINT_OF_SALE_MENU_H