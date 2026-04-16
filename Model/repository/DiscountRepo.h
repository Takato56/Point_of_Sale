#ifndef POINT_OF_SALE_DISCOUNTREPO_H
#define POINT_OF_SALE_DISCOUNTREPO_H
#include <vector>
#include "../database/DBContext.h"
#include "../entity/Discount.h"

class DiscountRepo {
private:
    DBContext& db;
public:
    explicit DiscountRepo(DBContext& context) : db(context) {}

    void addDiscount(Discount& discount);
    std::vector<Discount> getAll();
    Discount getByID(int id);
    void update(const Discount& discount);
    void remove(int id);
};

#endif //POINT_OF_SALE_DISCOUNTREPO_H