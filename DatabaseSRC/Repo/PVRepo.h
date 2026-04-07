//
// Created by ntt12 on 4/7/2026.
//

#ifndef POINT_OF_SALE_PVREPO_H
#define POINT_OF_SALE_PVREPO_H
#include "../../DatabaseSRC/DBContext/DBContext.h"
#include <vector>
#include "../../ProductVariants.h"

class PVRepo {
private:
    DBContext& db;
public:
    PVRepo(DBContext& context) : db(context) {}
    void addPV(const ProductVariants& pv);
    std::vector<ProductVariants> getAll();
    ProductVariants getByID(const std::string& id);
    void update(const ProductVariants& pv);
    void remove(const std::string& id);
};


#endif //POINT_OF_SALE_PVREPO_H