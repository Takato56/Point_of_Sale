//
// Created by ntt12 on 4/7/2026.
//

#ifndef POINT_OF_SALE_CATEGORIESREPO_H
#define POINT_OF_SALE_CATEGORIESREPO_H
#include <vector>
#include "../database/DBContext.h"
#include "../../Model/entity/Categories.h"

class CategoriesRepo {
private:
    DBContext& db;
public:
    CategoriesRepo(DBContext& db) : db(db) {}
    void addCategories(const Categories& ct);
    std::vector<Categories> getAll();
    Categories getByID(const int id);
    void update(const Categories& ct);
    void remove(const int id);
};


#endif //POINT_OF_SALE_CATEGORIESREPO_H