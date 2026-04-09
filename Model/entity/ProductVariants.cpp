#include "ProductVariants.h"
#include <iostream>

Size ProductVariants::getSize() const {
    return size;
}

int ProductVariants::getPVId() const {
    return PVId;
}

int ProductVariants::getProdId() const {
    return ProdId;
}

void ProductVariants::setPVId(int newPVId) {
    PVId = newPVId;
}

void ProductVariants::setSize(Size newSize) {
    size = newSize;
}

void ProductVariants::setProdId(int newProdId) {
    ProdId = newProdId;
}

void ProductVariants::edit() {
    std::cout << "Enter PVId: ";
    std::cin >> PVId;
    std::cout << "Enter ProdId: ";
    std::cin >> ProdId;
}

void ProductVariants::display() const {
    std::cout << "PVId: " << PVId << "\n";
    std::cout << "ProdId: " << ProdId << "\n";
}

std::string ProductVariants::toString() const {
    return std::to_string(PVId) + " | " + std::to_string(ProdId);
}