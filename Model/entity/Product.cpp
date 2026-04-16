#include "Product.h"

const std::string& Product::getProdName() const { return prodName; }
int Product::getProdId() const { return prodId; }
int Product::getCateId() const { return cateId; }
int Product::getProdPrice() const { return prodPrice; }

void Product::setProdName(const std::string& newName) { prodName = newName; }
void Product::setProdId(int newId) { prodId = newId; }
void Product::setCateId(int newCateId) { cateId = newCateId; }
void Product::setProdPrice(int newPrice) { prodPrice = newPrice; }

std::string Product::toString() const {
    return std::to_string(prodId) + " | " + prodName + " | " + std::to_string(prodPrice);
}