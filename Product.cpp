//
// Created by ntt12 on 4/3/2026.
//

#include "Product.h"

std::string Product::getProdName() const{
    return prodName;
}

std::string Product::getProdId() const {
    return prodId;
}

int Product::getProdPrice() const {
    return prodPrice;
}

void Product::setProdName(const std::string newName) {
    prodName = newName;
}

void Product::setProdId(const std::string newId) {
    prodId = newId;
}

void Product::setProdPrice(int price) {
    prodPrice = price;
}

void Product::edit() {
    std::cout << "Enter new name: "; std::getline(std::cin, prodName);
    std::cout << "Enter new price: "; std::cin >> prodPrice;
}

void Product::display() const {
    std::cout << prodName << " - " << prodPrice << std::endl;
}

std::string Product::toString() const {
    return prodId + " | " + prodName + " | " + std::to_string(prodPrice);
}
