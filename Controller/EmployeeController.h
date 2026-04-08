//
// Created by ntt12 on 4/8/2026.
//

#ifndef POINT_OF_SALE_EMPLOYEECONTROLLER_H
#define POINT_OF_SALE_EMPLOYEECONTROLLER_H
#include "../Model/Repo/CategoriesRepo.h"
#include "../Model/Repo/ProductRepo.h"


class EmployeeController {
private:
    ProductRepo pr;
    CategoriesRepo cr;
public:
    EmployeeController(DBContext& db) : pr(db), cr(db) {}

    void createProduct();
};


#endif //POINT_OF_SALE_EMPLOYEECONTROLLER_H