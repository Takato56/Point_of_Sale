#ifndef POINT_OF_SALE_MANAGERVIEW_H
#define POINT_OF_SALE_MANAGERVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "../model/entity/Categories.h"
#include "../model/entity/Product.h"
#include "../model/entity/Staff.h"
#include "../model/entity/Orders.h"
#include "../model/entity/OrderItems.h"
#include "../model/entity/Payments.h"
#include "../model/entity/Discount.h"

class ManagerView {
public:
    void showManagerMenu() const;
    int getMenuChoice() const;
    void showCrudMenu(const std::string& entityName) const;

    // Category
    std::string promptCategoryName(const std::string &promptMessage) const;
    int promptDisplayOrder() const;
    int promptCategoryChoice(const std::vector<Categories>& categories, const std::string &promptMessage) const;
    int promptCategoryId() const;

    // Product
    std::string promptProductName() const;
    int promptProductPrice() const;
    int promptProductId() const;

    // Employee
    std::string promptEmployeeName() const;
    std::string promptEmployeePhone() const;
    std::string promptEmployeePin() const;
    int promptEmployeeRole() const;
    int promptEmployeeId() const;
    void showAllEmployees(const std::vector<Staff>& employees) const;

    // Income
    int showDatesAndSelect(const std::vector<std::string>& dates) const;
    int showOrdersAndSelect(const std::vector<Orders>& orders,
                            const std::vector<double>& totals) const;
    void showBillDetail(const Orders& order,
                        const std::vector<OrderItems>& items,
                        const std::vector<Payments>& payments,
                        double total) const;
    void showDailyIncome(const std::string& date, double income) const;

    // Discount
    int promptDiscountId() const;
    std::string promptDiscountCode() const;
    std::string promptDiscountType() const;
    int promptDiscountValue(const std::string& type) const;
    int promptDiscountIsActive() const;
    void showAllDiscounts(const std::vector<Discount>& discounts) const;

    void showMessage(const std::string& msg) const;
};

#endif //POINT_OF_SALE_MANAGERVIEW_H