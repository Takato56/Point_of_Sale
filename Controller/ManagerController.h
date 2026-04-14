#ifndef POINT_OF_SALE_MANAGERCONTROLLER_H
#define POINT_OF_SALE_MANAGERCONTROLLER_H

#include "EmployeeController.h"
#include "../view/ManagerView.h"
#include "../model/repository/EmployeeRepo.h"
#include "../model/repository/OrderRepo.h"
#include "../model/repository/OrderItemRepo.h"
#include "../model/repository/PaymentRepo.h"

class ManagerController : public EmployeeController {
private:
    DBContext db;
    CategoriesRepo cr;
    ProductRepo pr;
    EmployeeRepo er;
    OrderRepo orderRepo;
    OrderItemsRepo oiRepo;
    PaymentRepo payRepo2;
    ManagerView mgrView;

    // Category CRUD
    void addCategory();
    void viewAllCategories();
    void updateCategory();
    void deleteCategory();
    void categoryMenu();

    // Product CRUD
    void addProduct();
    void viewAllProducts();
    void updateProduct();
    void deleteProduct();
    void productMenu();

    // Employee CRUD
    void addEmployee();
    void viewAllEmployees();
    void updateEmployee();
    void deleteEmployee();
    void employeeMenu();

    // Income
    void checkIncome();

public:
    explicit ManagerController(DBContext& context)
        : EmployeeController(context), db(context),
          cr(context), pr(context), er(context),
          orderRepo(context), oiRepo(context), payRepo2(context) {}

    void run();
};

#endif //POINT_OF_SALE_MANAGERCONTROLLER_H