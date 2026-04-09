//
// Created by ntt12 on 4/8/2026.
//

#include "OrderItems.h"

#include <iostream>
#include <ostream>

int OrderItems::getOIId() const {
    return OIId;
}
int OrderItems::getOrderId() const {
    return OrderId;
}
int OrderItems::getPVId() const {
    return PVId;
}
int OrderItems::getQuantity() const {
    return Quantity;
}
int OrderItems::getUnitPrice() const {
    return UnitPrice;
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
void OrderItems::setPVId(int newPVId) {
    PVId = newPVId;
}
void OrderItems::setQuantity(int newQuantity) {
    Quantity = newQuantity;
}
void OrderItems::setUnitPrice(int newUnitPrice) {
    UnitPrice = newUnitPrice;
}
void OrderItems::setNote(std::string newNote) {
    Note = newNote;
}

void OrderItems::edit() {
    std::cout<<"Enter OIId: "; std::cin>>OIId;
    std::cout<<"Enter Order Id: "; std::cin>>OrderId;
    std::cout<<"Enter PVId: "; std::cin>>PVId;
    std::cout<<"Enter Quantity: "; std::cin>>Quantity;
    std::cout<<"Enter Unit Price: "; std::cin>>UnitPrice;
    std::cout<<"Enter Note: ";
    std::cin.ignore();
    std::getline(std::cin,Note);
}
void OrderItems::display() const {
    std::cout<<"OI Id: "<<OIId<<std::endl;
    std::cout<<"Order Id: "<<OrderId<<std::endl;
    std::cout<<"PV Id: "<<PVId<<std::endl;
    std::cout<<"Quantity: "<<Quantity<<std::endl;
    std::cout<<"Unit Price: "<<UnitPrice<<std::endl;
    std::cout<<"Note: ";
}