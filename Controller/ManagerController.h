#ifndef POINT_OF_SALE_MANAGERCONTROLLER_H
#define POINT_OF_SALE_MANAGERCONTROLLER_H

#include "EmployeeController.h"
#include "../Model/repository/DiscountRepo.h"
#include "../View/ManagerView.h"
#include "../View/MenuView.h"
#include "../Model/repository/OrderRepo.h"
#include "../Model/repository/OrderItemRepo.h"
#include "../Model/repository/PaymentRepo.h"
#include "../Model/repository/StaffRepo.h"

class ManagerController : public EmployeeController {
private:
    CategoriesRepo mgrCateRepo;
    ProductRepo mgrProdRepo;
    StaffRepo mgrStaffRepo;
    OrderRepo mgrOrderRepo;
    OrderItemsRepo mgrOiRepo;
    PaymentRepo mgrPayRepo;
    ManagerView mgrView;
    DiscountRepo mgrDiscountRepo;

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

    // Discount CRUD
    void addDiscount();
    void viewAllDiscounts();
    void updateDiscount();
    void deleteDiscount();
    void discountMenu();

public:
    explicit ManagerController(DBContext& context)
        : EmployeeController(context),
          mgrCateRepo(context), mgrProdRepo(context), mgrStaffRepo(context),
          mgrOrderRepo(context), mgrOiRepo(context), mgrPayRepo(context),
          mgrDiscountRepo(context) {}

    void run() override;
};

#endif //POINT_OF_SALE_MANAGERCONTROLLER_H