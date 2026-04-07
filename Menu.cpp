//
// Created by ntt12 on 4/3/2026.
//

#include "Menu.h"

void Menu::addProduct(Product* newProducts) {
    menu.push_back(newProducts);
}

void Menu::editProduct(const std::string& name) {
    for (Product* product : menu) {
        if (product->getProdName() == name) {
            std::cout << "Product founded! Editing..." << std::endl;
            product->edit();
            return;
        }
    }
}

void Menu::deleteProduct(const std::string& name) {
    for (auto product = menu.begin(); product != menu.end(); ++product) {
        if ((*product)->getProdName() == name) {
            delete *product;
            menu.erase(product);
            std::cout << "Item deleted!\n" << std::endl;
            return;
        }
    }
}