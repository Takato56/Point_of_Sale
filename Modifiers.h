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
    std::string ModName;
    int ExtraCost;
public:
    Modifiers() : ModId(), ModName(""), ExtraCost() {}

    std::string getModName() const;
    int getModId() const;
    int getExtraCost() const;

    void setModName(std::string newName);
    void setModId(int newId);
    void setExtraCost(int newExtraCost);

    virtual void edit();
    virtual void display() const;
    virtual ~Modifiers() {}
};


#endif //POINT_OF_SALE_MODIFIERS_H