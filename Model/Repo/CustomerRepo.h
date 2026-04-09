//
// Created by ntt12 on 4/9/2026.
//

#ifndef POINT_OF_SALE_CUSTOMERREPO_H
#define POINT_OF_SALE_CUSTOMERREPO_H
#include <vector>

#include "../DatabaseSRC/DBContext/DBContext.h"
#include "../entity/Customer.h"

class CustomerRepo {
private:
    DBContext& db;
public:
    CustomerRepo(DBContext& context) : db(context) {}

    void addCustomer(const Customer& c);

    std::vector<Customer> getAll();
    Customer getByID(int id);
    void update(const Customer& c);
    void remove(int id);
};


#endif //POINT_OF_SALE_CUSTOMERREPO_H