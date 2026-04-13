#ifndef POINT_OF_SALE_PAYMENTREPO_H
#define POINT_OF_SALE_PAYMENTREPO_H

#include <vector>
#include "../database/DBContext.h"
#include "../entity/Payments.h"

class PaymentRepo {
private:
    DBContext& db;

public:
    PaymentRepo(DBContext& context) : db(context) {}

    void addPayment(const Payments& payment);
    std::vector<Payments> getAll();
    Payments getByID(int id);
    std::vector<Payments> getByOrderID(int orderId);
    void update(const Payments& payment);
    void remove(int id);
};

#endif //POINT_OF_SALE_PAYMENTREPO_H