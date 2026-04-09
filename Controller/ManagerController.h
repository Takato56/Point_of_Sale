//
// Created by ntt12 on 4/9/2026.
//

#ifndef POINT_OF_SALE_ADMINCONTROLLER_H
#define POINT_OF_SALE_ADMINCONTROLLER_H
#include "EmployeeController.h"


class ManagerController : public EmployeeController{
private:
    DBContext db;
    CategoriesRepo cr;
    ProductRepo pr;
public:
    ManagerController(DBContext& context) : EmployeeController(db), db(context), cr(context), pr(context) {
    }

    void createProduct();
};


#endif //POINT_OF_SALE_ADMINCONTROLLER_H