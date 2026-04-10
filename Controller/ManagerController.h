#ifndef POINT_OF_SALE_ADMINCONTROLLER_H
#define POINT_OF_SALE_ADMINCONTROLLER_H

#include "EmployeeController.h"
#include "../Model/Repo/StaffRepo.h"
class ManagerController : public EmployeeController {
private:
    DBContext db;
    CategoriesRepo cr;
    ProductRepo pr;
    StaffRepo sr;

public:
    explicit ManagerController(DBContext& context)
        : EmployeeController(context), db(context), cr(context), pr(context), sr(context) {}

    void createCategory();
    void editCategory();
    void deleteCategory();
    void showAllCategories();

    void createProduct();
    void editProduct();
    void deleteProduct();
    void showAllProducts();

    void createEmployee();
    void editEmployee();
    void deleteEmployee();
    void showAllEmployees();

    void checkIncome();
    void run();
};

#endif //POINT_OF_SALE_ADMINCONTROLLER_H