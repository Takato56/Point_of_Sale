//
// Created by ntt12 on 4/14/2026.
//

#ifndef POINT_OF_SALE_MODIFIERREPO_H
#define POINT_OF_SALE_MODIFIERREPO_H
#include <vector>
#include "../database/DBContext.h"
#include "../../Model/entity/Modifiers.h"

class ModifierRepo {
private:
    DBContext& db;
public:
    ModifierRepo(DBContext& context) : db(context) {}
    void addModifier(const Modifiers& m);
    std::vector<Modifiers> getAll();
    Modifiers getByID(int id);
    void update(const Modifiers& modifier);
    void remove(int id);
};


#endif //POINT_OF_SALE_MODIFIERREPO_H