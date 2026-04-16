//
// Created by admin on 4/11/2026.
//

#include "MenuView.h"
#include <iomanip>
#include <algorithm>

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

void MenuView::showProductByCateId(const std::vector<Categories>& ct, const std::vector<Product>& pd) const {
    // Create a copy of categories to sort by displayOrder
    std::vector<Categories> sortedCategories = ct;

    // Sort by displayOrder (stable sort maintains database order for duplicates)
    std::stable_sort(sortedCategories.begin(), sortedCategories.end(),
                     [](const Categories& a, const Categories& b) {
                         return a.getDisplayOrder() < b.getDisplayOrder();
                     });

    for (const auto& cat : sortedCategories) {
        std::cout << "\n" << cat.getCateName() << "\n";
        bool found = false;

        for (const auto& p : pd) {
            if (p.getCateId() == cat.getCateId()) {
                std::cout << "  -> " << p.toString() << "\n";
                found = true;
            }
        }

        if (!found) {
            std::cout << "  (No products in this category)\n";
        }
    }
}

void MenuView::showAllCategories(const std::vector<Categories>& categories) const {
    if (categories.empty()) {
        std::cout << "\n[!] No categories found.\n";
        return;
    }

    // Increased the line width to 55 to fit the new column
    std::cout << "\n" << std::string(55, '=') << "\n";
    std::cout << std::left
              << std::setw(10) << "ID"
              << std::setw(25) << "CATEGORY NAME"
              << "DISPLAY ORDER" << "\n";
    std::cout << std::string(55, '-') << "\n";

    for (const auto& c : categories) {
        std::cout << std::left
                  << std::setw(10) << c.getCateId()
                  << std::setw(25) << c.getCateName()
                  << c.getDisplayOrder() << "\n";
    }

    std::cout << std::string(55, '=') << "\n";
}