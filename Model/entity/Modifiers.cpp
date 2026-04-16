#include "Modifiers.h"

const std::string& Modifiers::getModName() const { return modName; }
int Modifiers::getModId() const { return modId; }
int Modifiers::getExtraCost() const { return extraCost; }
const std::string& Modifiers::getModType() const { return modType; }

void Modifiers::setModName(const std::string& newName) { modName = newName; }
void Modifiers::setModId(int newId) { modId = newId; }
void Modifiers::setExtraCost(int newExtraCost) { extraCost = newExtraCost; }
void Modifiers::setModType(const std::string& newModType) { modType = newModType; }