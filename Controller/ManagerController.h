#ifndef POINT_OF_SALE_MANAGERCONTROLLER_H
#define POINT_OF_SALE_MANAGERCONTROLLER_H

#include "EmployeeController.h"
#include "../Model/repository/DiscountRepo.h"
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
    DiscountRepo dr;

    // Category CRUD
    void addCategory();
    void viewAllCategories();
    void updateCategory();
    void deleteCategory();
    void categoryMenu();

    // Product CRUD
    void addProduct();
    void viewAllProducts();
    void showProductByCateId();
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

    // Discount CRUD
    void addDiscount();
    void viewAllDiscounts();
    void updateDiscount();
    void deleteDiscount();
    void discountMenu();

public:
    explicit ManagerController(DBContext& context)
        : EmployeeController(context), db(context),
          cr(context), pr(context), er(context),
          orderRepo(context), oiRepo(context), payRepo2(context), dr(context) {}

    void run();
};

#endif //POINT_OF_SALE_MANAGERCONTROLLER_H