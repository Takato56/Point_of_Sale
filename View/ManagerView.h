#ifndef POINT_OF_SALE_MANAGERVIEW_H
#define POINT_OF_SALE_MANAGERVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "../model/entity/Categories.h"
#include "../model/entity/Product.h"
#include "../model/entity/Employee.h"
#include "../model/entity/Orders.h"
#include "../model/entity/OrderItems.h"
#include "../model/entity/Payments.h"

class ManagerView {
public:
    // Main menu
    void showManagerMenu() const;
    int getMenuChoice() const;

    // CRUD sub-menu (reusable for Categories, Product, Employee)
    void showCrudMenu(const std::string& entityName) const;

    // ─── Category prompts ───
    std::string promptCategoryName() const;
    int promptDisplayOrder() const;
    int promptCategoryChoice(const std::vector<Categories>& categories) const;
    int promptCategoryId() const;
    void showAllCategories(const std::vector<Categories>& categories) const;

    // ─── Product prompts ───
    std::string promptProductName() const;
    int promptProductPrice() const;
    int promptProductId() const;
    void showProductByCateId(const std::vector<Categories>& ct, const std::vector<Product>& pd) const;

    // ─── Employee prompts ───
    std::string promptEmployeeName() const;
    std::string promptEmployeePhone() const;
    std::string promptEmployeePin() const;
    int promptEmployeeRole() const;
    int promptEmployeeId() const;
    void showAllEmployees(const std::vector<Employee>& employees) const;

    // ─── Income / Bill display ───
    int showDatesAndSelect(const std::vector<std::string>& dates) const;
    int showOrdersAndSelect(const std::vector<Orders>& orders,
                            const std::vector<double>& totals) const;
    void showBillDetail(const Orders& order,
                        const std::vector<OrderItems>& items,
                        const std::vector<Payments>& payments,
                        double total) const;
    void showDailyIncome(const std::string& date, double income) const;

    // Generic
    void showMessage(const std::string& msg) const;

    void showAllProducts(const std::vector<Product> & ct);
};

#endif //POINT_OF_SALE_MANAGERVIEW_H