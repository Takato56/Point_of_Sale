//
// Created by ntt12 on 4/3/2026.
//

#include "Product.h"

std::string Product::getProdName() const{
    return ProdName;
}

int Product::getProdId() const {
    return ProdId;
}

int Product::getCateId() const {
    return CateId;
}
int Product::getProdPrice() const {
    return ProdPrice;
}

void Product::setProdName(const std::string newName) {
    ProdName = newName;
}

void Product::setProdId(const int newId) {
    ProdId = newId;
}

void Product::setCateId(const int newCateId) {
    CateId = newCateId;
}

 void Product::setProdPrice(const int newPrice) {
     ProdPrice = newPrice;
}

void Product::edit() {
    std::cout << "Enter new name: ";
    std::cin.ignore();
    std::getline(std::cin, ProdName);
    std::cout << "Enter new price: "; std::cin >> ProdPrice;
}

void Product::display() const {
    std::cout << ProdName << std::endl;
}

std::string Product::toString() const {
    return ProdId + " | " + ProdName;
}
