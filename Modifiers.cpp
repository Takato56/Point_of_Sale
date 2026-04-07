//
// Created by ntt12 on 4/7/2026.
//

#include "Modifiers.h"

std::string Modifiers::getModName() const {
    return ModName;
}
int Modifiers::getModId() const {
    return ModId;
}
int Modifiers::getExtraCost() const {
    return ExtraCost;
}

void Modifiers::setModName(const std::string newName) {
    ModName = newName;
}
void Modifiers::setModId(const int newId) {
    ModId = newId;
}
void Modifiers::setExtraCost(const int newExtraCost) {
    ExtraCost = newExtraCost;
}

void Modifiers::edit() {
    std::cout << "Enter new modifier name: ";
    std::cin.ignore();
    std::getline(std::cin, ModName);
}
void Modifiers::display() const {
    std::cout << ModName << std::endl;
}