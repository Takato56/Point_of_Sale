#ifndef POINT_OF_SALE_MODIFIERS_H
#define POINT_OF_SALE_MODIFIERS_H
#include <string>

class Modifiers {
private:
    int modId = 0;
    std::string modName;
    std::string modType;
    int extraCost = 0;
public:
    Modifiers() = default;

    [[nodiscard]] const std::string& getModName() const;
    [[nodiscard]] int getModId() const;
    [[nodiscard]] int getExtraCost() const;
    [[nodiscard]] const std::string& getModType() const;

    void setModName(const std::string& newName);
    void setModId(int newId);
    void setExtraCost(int newExtraCost);
    void setModType(const std::string& newModType);

    virtual ~Modifiers() = default;
};

#endif //POINT_OF_SALE_MODIFIERS_H