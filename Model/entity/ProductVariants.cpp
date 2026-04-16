#include "ProductVariants.h"

Size ProductVariants::getSize() const { return size; }
int ProductVariants::getPVId() const { return pvId; }
int ProductVariants::getProdId() const { return prodId; }

void ProductVariants::setPVId(int newPVId) { pvId = newPVId; }
void ProductVariants::setSize(Size newSize) { size = newSize; }
void ProductVariants::setProdId(int newProdId) { prodId = newProdId; }

std::string ProductVariants::toString() const {
    return std::to_string(pvId) + " | " + std::to_string(prodId);
}