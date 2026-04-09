//
// Created by ntt12 on 4/9/2026.
//

#ifndef POINT_OF_SALE_ORDERREPO_H
#define POINT_OF_SALE_ORDERREPO_H

#include <vector>
#include "../DatabaseSRC/DBContext/DBContext.h"
#include "../entity/Orders.h"

class OrderRepo {
private:
    DBContext& db;

public:
    OrderRepo(DBContext& context) : db(context) {}

    void addOrder(const Orders& order);
    std::vector<Orders> getAll();
    Orders getByID(int id);
    void update(const Orders& order);
    void remove(int id);
};

#endif //POINT_OF_SALE_ORDERREPO_H