#include "Staff.h"

int Staff::getId() const { return stfId; }
void Staff::setId(int id) { stfId = id; }

const std::string& Staff::getName() const { return stfName; }
void Staff::setName(const std::string& name) { stfName = name; }

const std::string& Staff::getPhoneNumber() const { return stfPhoneNumber; }
void Staff::setPhoneNumber(const std::string& phoneNumber) { stfPhoneNumber = phoneNumber; }

const std::string& Staff::getPinHash() const { return pinHash; }
void Staff::setPinHash(const std::string& newPinHash) { pinHash = newPinHash; }

Role Staff::getRole() const { return role; }
void Staff::setRole(Role newRole) { role = newRole; }

int Staff::getIsActive() const { return isActive; }
void Staff::setIsActive(int newIsActive) { isActive = newIsActive; }

std::string Staff::toString() const { return stfName; }