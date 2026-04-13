#ifndef POINT_OF_SALE_MANAGERCONTROLLER_H
#define POINT_OF_SALE_MANAGERCONTROLLER_H

#include "EmployeeController.h"
#include "../view/ManagerView.h"

class ManagerController : public EmployeeController {
private:
    DBContext db;
    CategoriesRepo cr;
    ProductRepo pr;
    ManagerView mgrView;

public:
    explicit ManagerController(DBContext& context)
        : EmployeeController(context), db(context), cr(context), pr(context) {}

    void createCategory();
    void createProduct();
    void showAllProducts();
    void showAllCategories();
    void run();
};

#endif //POINT_OF_SALE_MANAGERCONTROLLER_H