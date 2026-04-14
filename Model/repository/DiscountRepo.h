//
// Created by ntt12 on 4/14/2026.
//

#ifndef POINT_OF_SALE_DISCOUNTREPO_H
#define POINT_OF_SALE_DISCOUNTREPO_H
#include <vector>
#include "../database/DBContext.h"
#include "../../Model/entity/Discount.h"

class DiscountRepo {
private:
    DBContext& db;
public:
    DiscountRepo(DBContext& context) : db(context) {}

    void addDiscount(Discount& discount);
    std::vector<Discount> getAll();
    Discount getByID(int id);
    void update(const Discount& discount);
    void remove(int id);
};


#endif //POINT_OF_SALE_DISCOUNTREPO_H