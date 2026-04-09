#include "OrderItems.h"
#include <iostream>

int OrderItems::getOIId() const {
    return OIId;
}
int OrderItems::getOrderId() const {
    return OrderId;
}
int OrderItems::getProdId() const {
    return ProdId;
}
int OrderItems::getQuantity() const {
    return Quantity;
}
double OrderItems::getUnitPrice() const {
    return UnitPrice;
}
std::string OrderItems::getSizeLabel() const {
    return SizeLabel;
}
std::string OrderItems::getNote() const {
    return Note;
}

void OrderItems::setOIId(int newOIId) {
    OIId = newOIId;
}
void OrderItems::setOrderId(int newOrderId) {
    OrderId = newOrderId;
}
void OrderItems::setProdId(int newProdId) {
    ProdId = newProdId;
}
void OrderItems::setQuantity(int newQuantity) {
    Quantity = newQuantity;
}
void OrderItems::setUnitPrice(double newUnitPrice) {
    UnitPrice = newUnitPrice;
}
void OrderItems::setSizeLabel(std::string newSizeLabel) {
    SizeLabel = newSizeLabel;
}
void OrderItems::setNote(std::string newNote) {
    Note = newNote;
}

void OrderItems::edit() {
    std::cout << "Enter OIId: ";
    std::cin >> OIId;
    std::cout << "Enter OrderId: ";
    std::cin >> OrderId;
    std::cout << "Enter ProdId: ";
    std::cin >> ProdId;
    std::cout << "Enter Quantity: ";
    std::cin >> Quantity;
    std::cout << "Enter Unit Price: ";
    std::cin >> UnitPrice;
    std::cout << "Enter SizeLabel: ";
    std::cin.ignore();
    std::getline(std::cin, SizeLabel);
    std::cout << "Enter Note: ";
    std::getline(std::cin, Note);
}

void OrderItems::display() const {
    std::cout << "OIId: " << OIId << "\n";
    std::cout << "OrderId: " << OrderId << "\n";
    std::cout << "ProdId: " << ProdId << "\n";
    std::cout << "Quantity: " << Quantity << "\n";
    std::cout << "UnitPrice: " << UnitPrice << "\n";
    std::cout << "SizeLabel: " << SizeLabel << "\n";
    std::cout << "Note: " << Note << "\n";
}