#ifndef POINT_OF_SALE_ORDERITEMSREPO_H
#define POINT_OF_SALE_ORDERITEMSREPO_H

#include <vector>
#include "../database/DBContext.h"
#include "../entity/OrderItems.h"

class OrderItemsRepo {
private:
    DBContext& db;

public:
    explicit OrderItemsRepo(DBContext& context) : db(context) {}

    void addOrderItem(const OrderItems& item);
    std::vector<OrderItems> getAll();
    std::vector<OrderItems> getByOrderID(int orderId);
    OrderItems getByID(int id);
    void update(const OrderItems& item);
    void remove(int id);
};

#endif //POINT_OF_SALE_ORDERITEMSREPO_H