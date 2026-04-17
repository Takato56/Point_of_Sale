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

// Hàm tính số bytes UTF-8 "thừa" (mỗi ký tự multibyte thêm 1 byte so với display width)
int utf8ExtraBytes(const std::string& s) {
    int extra = 0;
    for (unsigned char c : s) {
        if ((c & 0xC0) == 0x80) extra++; // continuation byte
    }
    return extra;
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
    std::cout << "\n" << std::string(58, '=') << "\n";
    std::cout << std::setw(38) << std::right << "DANH SÁCH THỰC ĐƠN" << "\n";
    std::cout << std::string(58, '=') << "\n";

    const int COL_ID   = 6;
    const int COL_NAME = 30;
    const int COL_PRICE_WIDTH = 5; // width của phần số giá

    for (const auto& cat : sortedCategories) {
        std::cout << "\n--- " << cat.getCateName() << " ---\n";

        bool hasProd = false;

        for (const auto& p : pd) {
            if (p.getCateId() == cat.getCateId()) {
                if (!hasProd) {
                    // Header: "Tên sản phẩm" cũng có dấu, cần bù bytes
                    std::string headerName = "Tên sản phẩm";
                    int headerExtra = utf8ExtraBytes(headerName);
                    std::cout << "  " << std::left
                              << std::setw(COL_ID) << "ID"
                              << std::setw(COL_NAME + headerExtra) << headerName
                              << std::right << "Giá bán" << "\n";
                    std::cout << "  " << std::string(48, '-') << "\n";
                    hasProd = true;
                }

                std::string name = p.getProdName();
                int extra = utf8ExtraBytes(name);

                std::cout << "  " << std::left
                          << std::setw(COL_ID) << p.getProdId()
                          << std::setw(COL_NAME + extra) << name  // bù bytes thừa
                          << std::right << std::setw(COL_PRICE_WIDTH) << (int)p.getProdPrice() << " VND\n";
            }
        }

        if (hasProd) {
            std::cout << "  " << std::string(48, '.') << "\n";
        }
    }

    std::cout << "\n" << std::string(58, '=') << "\n";
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