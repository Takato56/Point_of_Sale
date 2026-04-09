//
// Created by ntt12 on 4/8/2026.
//

#ifndef POINT_OF_SALE_EMPLOYEECONTROLLER_H
#define POINT_OF_SALE_EMPLOYEECONTROLLER_H
#include "../Model/Repo/CategoriesRepo.h"
#include "../Model/Repo/ProductRepo.h"
#include "../utils/DataHelper.h"
#include <iostream>
#include "MenuController.h"
#include "../Model/Repo/OrderRepo.h"

class EmployeeController {
private:
    DBContext db;
    std::vector<Categories> listCt;
    std::vector<Product> listPd;
    MenuController mc;
    OrderRepo odr;

public:
    EmployeeController(DBContext& context) : db(context), mc(context), odr(context) {}

    void loadData(const std::vector<Categories>& c, const std::vector<Product>& p);
    void createOrder();
    void createPayment();
    void takeOrderCard();
    void checkCustPoint();

};


#endif //POINT_OF_SALE_EMPLOYEECONTROLLER_H