//
// Created by ntt12 on 4/7/2026.
//

#include "../../Categories.h"

Categories::Categories(const std::string &name, int cate_id, int display_order)
    : CateName(name), CateId(cate_id), DisplayOrder(display_order) {}

std::string Categories::getCateName() const {
    return CateName;
}

int Categories::getCateId() const {
    return CateId;
}

std::string Categories::getDisplayOrder() const {
    return std::to_string(DisplayOrder);
}

void Categories::setCateName(const std::string newCateName) {
    CateName = newCateName;
}

void Categories::setCateId(const int newCateId) {
    CateId = newCateId;
}

void Categories::setDisplayOrder(const int newDisplayOrder) {
    DisplayOrder = newDisplayOrder;
}

void Categories::editCate() {
    std::cout << "Enter new name: "; std::getline(std::cin, CateName);
    // std::cout << "Enter new price: "; std::cin >> prodPrice;
}

void Categories::displayCate() const {
    std::cout << CateName << std::endl;
}

Categories::~Categories(){}