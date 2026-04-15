//
// Created by ntt12 on 4/7/2026.
//

#ifndef POINT_OF_SALE_MODIFIERS_H
#define POINT_OF_SALE_MODIFIERS_H
#include <string>
#include <iostream>

class Modifiers {
private:
    int ModId;
    std::string ModName, ModType;
    int ExtraCost;
public:
    Modifiers() : ModId(), ModName(""), ExtraCost(), ModType("") {}

    std::string getModName() const;
    int getModId() const;
    int getExtraCost() const;
    std::string getModType() const;

    void setModName(std::string newName);
    void setModId(int newId);
    void setExtraCost(int newExtraCost);
    void setModType(std::string newModType);

    virtual void edit();
    virtual void display() const;
    virtual ~Modifiers() {}
};


#endif //POINT_OF_SALE_MODIFIERS_H