//
// Created by ntt12 on 4/3/2026.
//

#include "Beverage.h"

Beverage::Beverage(const std::string& n, std::string id, int p) : Product(n, id, p) {}

void Beverage::display() const {
    std::cout << "Drink: ";
    Product::display();
}

// double Beverage::calculatePrice() const {
//     if (size == "S")    return getProdPrice()*0.8;
//     if (size == "M")    return getProdPrice();
//     if (size == "L")    return getProdPrice()*1.2;
// }
