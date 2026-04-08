//
// Created by ntt12 on 4/8/2026.
//

#include "ProductModifiers.h"

int ProductModifiers::getPMId() const {
    return PMId;
}
int ProductModifiers::getProdId() const {
    return ProdId;
}
int ProductModifiers::getModId() const {
    return ModId;
}

void ProductModifiers::setPMId(const int newPMId) {
    PMId = newPMId;
}
void ProductModifiers::setProdId(const int newProdId) {
    ProdId = newProdId;
}
void ProductModifiers::setModId(const int newModId) {
    ModId = newModId;
}

void ProductModifiers::edit() {
    std::cout << "Enter new product modifier ID: "; std::cin >> ProdId;
}
void ProductModifiers::display() const {
    std::cout << "Product modifier ID: " << getProdId() << std::endl;
}
