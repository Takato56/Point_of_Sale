#ifndef POINT_OF_SALE_ORDERREPO_H
#define POINT_OF_SALE_ORDERREPO_H

#include <vector>
#include "../database/DBContext.h"
#include "../entity/Orders.h"

class OrderRepo {
private:
    DBContext& db;

public:
    OrderRepo(DBContext& context) : db(context) {}

    void addOrder(const Orders& order);
    std::vector<Orders> getAll();
    Orders getByID(int id);
    std::vector<Orders> getByOrderCardID(int orderCardId);
    void update(const Orders& order);
    void remove(int id);

    std::vector<std::string> getDistinctDates();
    std::vector<Orders> getByDate(const std::string& date);
};

#endif //POINT_OF_SALE_ORDERREPO_H