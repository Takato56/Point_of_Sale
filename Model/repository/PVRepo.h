#ifndef POINT_OF_SALE_PVREPO_H
#define POINT_OF_SALE_PVREPO_H

#include "../database/DBContext.h"
#include <vector>
#include "../entity/ProductVariants.h"

class PVRepo {
private:
    DBContext& db;
public:
    PVRepo(DBContext& context) : db(context) {}

    void addPV(const ProductVariants& pv);
    std::vector<ProductVariants> getAll();
    std::vector<ProductVariants> getByProdID(int prodId);
    ProductVariants getByID(int id);
    void update(const ProductVariants& pv);
    void remove(int id);

    std::string sizeToString(Size s);
    Size stringToSize(const std::string& str);
};

#endif //POINT_OF_SALE_PVREPO_H