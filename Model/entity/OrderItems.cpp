#include "OrderItems.h"

int OrderItems::getOIId() const { return oiId; }
int OrderItems::getOrderId() const { return orderId; }
int OrderItems::getProdId() const { return prodId; }
int OrderItems::getQuantity() const { return quantity; }
double OrderItems::getUnitPrice() const { return unitPrice; }
const std::string& OrderItems::getSizeLabel() const { return sizeLabel; }
const std::string& OrderItems::getNote() const { return note; }

void OrderItems::setOIId(int newOIId) { oiId = newOIId; }
void OrderItems::setOrderId(int newOrderId) { orderId = newOrderId; }
void OrderItems::setProdId(int newProdId) { prodId = newProdId; }
void OrderItems::setQuantity(int newQuantity) { quantity = newQuantity; }
void OrderItems::setUnitPrice(double newUnitPrice) { unitPrice = newUnitPrice; }
void OrderItems::setSizeLabel(const std::string& newSizeLabel) { sizeLabel = newSizeLabel; }
void OrderItems::setNote(const std::string& newNote) { note = newNote; }