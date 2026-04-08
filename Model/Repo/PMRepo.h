//
// Created by ntt12 on 4/8/2026.
//

#ifndef POINT_OF_SALE_PMREPO_H
#define POINT_OF_SALE_PMREPO_H
#include "../DatabaseSRC/DBContext/DBContext.h"
#include "../entity/ProductModifiers.h"
#include <vector>
class PMRepo {
private:
    DBContext& db;
public:
    PMRepo(DBContext& context) : db(context) {}
    void addPM(const ProductModifiers& pm);
    std::vector<ProductModifiers> getAll();
    ProductModifiers getByID(const std::string& id);
    virtual void update(const ProductModifiers& pm);
    virtual void remove(const std::string& id);

    virtual ~PMRepo();
};


#endif //POINT_OF_SALE_PMREPO_H