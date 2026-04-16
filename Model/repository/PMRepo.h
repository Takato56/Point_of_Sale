#ifndef POINT_OF_SALE_PMREPO_H
#define POINT_OF_SALE_PMREPO_H
#include "../database/DBContext.h"
#include "../entity/ProductModifiers.h"
#include <vector>

class PMRepo {
private:
    DBContext& db;
public:
    explicit PMRepo(DBContext& context) : db(context) {}
    void addPM(const ProductModifiers& pm);
    std::vector<ProductModifiers> getAll();
    ProductModifiers getByID(int id);
    void update(const ProductModifiers& pm);
    void remove(int id);
};

#endif //POINT_OF_SALE_PMREPO_H