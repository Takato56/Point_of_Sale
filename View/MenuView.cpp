//
// Created by admin on 4/11/2026.
//

#include "MenuView.h"

int MenuView::showAndSelectCategories(const std::vector<Categories>& ct) const {
    std::cout << "\n===== CATEGORIES =====" << std::endl;
    for (const auto& cate : ct) {
        std::cout << "[" << cate.getCateId() << "] " << cate.getCateName() << std::endl;
    }

    int choice;
    std::cout << "Choose Category ID: ";
    std::cin >> choice;
    return choice;
}

void MenuView::displayProductsByCategory(int cateId, const std::vector<Product>& pd) const {
    std::cout << "\n===== PRODUCT IN CATEGORIES =====" << std::endl;
    bool found = false;
    for (const auto& prod : pd) {
        if (prod.getCateId() == cateId) {
            std::cout << "ID: " << prod.getProdId() << " | " << prod.getProdName() << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Product not exist" << std::endl;
    }
}