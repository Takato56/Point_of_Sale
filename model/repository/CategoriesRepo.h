#ifndef POINT_OF_SALE_CATEGORIESREPO_H
#define POINT_OF_SALE_CATEGORIESREPO_H
#include <vector>
#include "../database/DBContext.h"
#include "../entity/Categories.h"

class CategoriesRepo {
private:
    DBContext& db;
public:
    explicit CategoriesRepo(DBContext& db) : db(db) {}
    void addCategories(const Categories& ct);
    std::vector<Categories> getAll();
    Categories getByID(int id);
    void update(const Categories& ct);
    void remove(int id);
};

#endif //POINT_OF_SALE_CATEGORIESREPO_H