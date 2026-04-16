#include "Categories.h"

Categories::Categories(const std::string& name, int cate_id, int display_order)
    : cateName(name), cateId(cate_id), displayOrder(display_order) {}

const std::string& Categories::getCateName() const {
    return cateName;
}

int Categories::getCateId() const {
    return cateId;
}

int Categories::getDisplayOrder() const {
    return displayOrder;
}

void Categories::setCateName(const std::string& newCateName) {
    cateName = newCateName;
}

void Categories::setCateId(int newCateId) {
    cateId = newCateId;
}

void Categories::setDisplayOrder(int newDisplayOrder) {
    displayOrder = newDisplayOrder;
}

std::string Categories::toString() const {
    return "ID: " + std::to_string(cateId) + " | Name: " + cateName;
}