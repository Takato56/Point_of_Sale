//
// Created by admin on 4/11/2026.
//

#include "ManagerView.h"
#include <limits>

void ManagerView::showManagerMenu() const {
    std::cout << "\n===== MANAGER UI =====\n";
    std::cout << "1. Category\n";
    std::cout << "2. Product\n";
    std::cout << "3. Employee\n";
    std::cout << "4. Check Income\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose: ";
}

int ManagerView::getMenuChoice() const {
    int choice;
    std::cin >> choice;
    return choice;
}

std::string ManagerView::promptCategoryName() const {
    std::string name;
    std::cout << "Category name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    return name;
}

int ManagerView::promptDisplayOrder() const {
    int order;
    std::cout << "Display order: ";
    std::cin >> order;
    return order;
}

int ManagerView::promptCategoryChoice(const std::vector<Categories>& categories) const {
    std::cout << "\n========== CATEGORIES ==========\n";
    for (size_t i = 0; i < categories.size(); i++) {
        std::cout << i + 1 << ". " << categories[i].getCateName()
                  << " (ID: " << categories[i].getCateId() << ")\n";
    }
    int choice;
    std::cout << "Choose category: ";
    std::cin >> choice;
    return choice;
}

std::string ManagerView::promptProductName() const {
    std::string name;
    std::cout << "Product name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    return name;
}

int ManagerView::promptProductPrice() const {
    int price;
    std::cout << "Product base price: ";
    std::cin >> price;
    return price;
}

void ManagerView::showAllProducts(const std::vector<Product>& products) const {
    if (products.empty()) {
        std::cout << "No products found.\n";
        return;
    }
    std::cout << "\n========== PRODUCTS ==========\n";
    for (const auto& p : products) {
        std::cout << p.toString() << "\n";
    }
}

void ManagerView::showAllCategories(const std::vector<Categories>& categories) const {
    if (categories.empty()) {
        std::cout << "No categories found.\n";
        return;
    }
    std::cout << "\n========== CATEGORIES ==========\n";
    for (const auto& c : categories) {
        std::cout << c.toString() << "\n";
    }
}

void ManagerView::showMessage(const std::string& msg) const {
    std::cout << msg << "\n";
}