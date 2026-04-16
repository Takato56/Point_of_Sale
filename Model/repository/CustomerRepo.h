#ifndef POINT_OF_SALE_CUSTOMERREPO_H
#define POINT_OF_SALE_CUSTOMERREPO_H
#include <vector>
#include "../database/DBContext.h"
#include "../entity/Customer.h"

class CustomerRepo {
private:
    DBContext& db;
public:
    explicit CustomerRepo(DBContext& context) : db(context) {}

    void addCustomer(const Customer& c);
    std::vector<Customer> getAll();
    Customer getByID(int id);
    Customer getByPhone(const std::string& phone);
    void update(const Customer& c);
    void remove(int id);
};

#endif //POINT_OF_SALE_CUSTOMERREPO_H