//
// Created by admin on 4/11/2026.
//

#ifndef POINT_OF_SALE_EMPLOYEEVIEW_H
#define POINT_OF_SALE_EMPLOYEEVIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "../model/entity/OrderItems.h"
#include "../model/entity/Orders.h"
#include "../model/entity/Customer.h"
#include "../Model/entity/Discount.h"
#include "../Model/entity/Modifiers.h"

class EmployeeView {
public:
    void showStaffMenu() const;
    int getMenuChoice() const;

    void showAvailableOrderCards(const bool used[20]) const;
    void showOccupiedOrderCards(const bool used[20], const int cardIds[20]) const;

    void showOrderDetail(const Orders& order, int cardId,
                         const std::vector<OrderItems>& items, double total) const;

    int promptOrderCardToPay() const;
    int promptProductId() const;
    int promptSizeChoice() const;
    int promptQuantity() const;
    std::string promptPaymentMethod() const;
    std::string promptCustPhone() const;
    std::string promptCustName() const;

    void showCustomerInfo(const Customer& c) const;
    void showMessage(const std::string& msg) const;
    void showActiveDiscounts(const std::vector<Discount>& discounts) const;
    int promptDiscountChoice() const;
    void displayModifiers(const std::vector<Modifiers> &modifiers) const;
};

#endif //POINT_OF_SALE_EMPLOYEEVIEW_H