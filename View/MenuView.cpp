//
// Created by admin on 4/11/2026.
//

#include "MenuView.h"
#include <iomanip>
#include <algorithm>
#include <iostream>

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
    if (ct.empty()) {
        std::cout << "\n[!] Không có danh mục nào để hiển thị.\n";
        return;
    }

    // 1. Sắp xếp danh mục theo DisplayOrder
    std::vector<Categories> sortedCategories = ct;
    std::stable_sort(sortedCategories.begin(), sortedCategories.end(),
                     [](const Categories& a, const Categories& b) {
                         return a.getDisplayOrder() < b.getDisplayOrder();
                     });

    // 2. Tiêu đề tổng quát
    std::cout << "\n" << std::string(65, '=') << "\n";
    std::cout << std::setw(42) << std::right << "DANH SÁCH THỰC ĐƠN" << "\n";
    std::cout << std::string(65, '=') << "\n";

    for (const auto& cat : sortedCategories) {
        // In tên danh mục nổi bật (Ví dụ: --- CÀ PHÊ ---)
        std::cout << "\n--- " << cat.getCateName() << " ---\n";

        // Tiêu đề cột (chỉ in nếu danh mục có sản phẩm)
        bool hasProd = false;

        for (const auto& p : pd) {
            if (p.getCateId() == cat.getCateId()) {
                if (!hasProd) {
                    std::cout << std::left << std::setw(8) << "  ID"
                              << std::setw(35) << "Tên sản phẩm"
                              << "Giá bán" << "\n";
                    std::cout << "  " << std::string(55, '-') << "\n";
                    hasProd = true;
                }

                // In thông tin sản phẩm thẳng hàng
                std::cout << "  " << std::left
                          << std::setw(6)  << p.getProdId()
                          << std::setw(35) << p.getProdName()
                          << std::right << std::setw(8) << (int)p.getProdPrice() << " VND" << "\n";
            }
        }

        if (!hasProd) {
            std::cout << "  (Chưa có sản phẩm trong mục này)\n";
        } else {
            std::cout << "  " << std::string(55, '.') << "\n";
        }
    }

    std::cout << "\n" << std::string(65, '=') << "\n";
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