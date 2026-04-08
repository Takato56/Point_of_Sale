//
// Created by ntt12 on 4/7/2026.
//

#include "ProductVariants.h"

#include <iostream>
#include <ostream>

Size ProductVariants::getSize() const {
    return size;
}
int ProductVariants::getPVId() const {
    return PVId;
}
int ProductVariants::getPrice() const {
    return price;
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
void ProductVariants::setPrice(int newPrice) {
    price = newPrice;
}
void ProductVariants::setProdId(int newProdId) {
    ProdId = newProdId;
}

void ProductVariants::edit() {
    int input;
    std::cout << "Enter new product variances size: ";
    std::cin >> input;
    size = static_cast<Size>(input);
}
void ProductVariants::display() const {
    std::cout << size << std::endl;
}

std::string ProductVariants::toString() const{
    return std::to_string(PVId);
}