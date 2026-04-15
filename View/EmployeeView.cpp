//
// Created by admin on 4/11/2026.
//

#include "EmployeeView.h"
#include <limits>

void EmployeeView::showStaffMenu() const {
    std::cout << "\n===== STAFF UI =====\n";
    std::cout << "1. Create Order\n";
    std::cout << "2. Pay Order (Close Table)\n";
    std::cout << "3. Call Order Card\n";
    std::cout << "4. Check Customer Point\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose: ";
}

int EmployeeView::getMenuChoice() const {
    int choice;
    std::cin >> choice;
    return choice;
}

void EmployeeView::showAvailableOrderCards(const bool used[20]) const {
    std::cout << "\n===== AVAILABLE ORDER CARDS =====\n";
    bool found = false;
    for (int i = 0; i < 20; ++i) {
        if (!used[i]) {
            std::cout << "OrderCard " << (i + 1) << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No empty order cards available.\n";
    }
}

void EmployeeView::showOccupiedOrderCards(const bool used[20], const int cardIds[20]) const {
    std::cout << "\n===== OCCUPIED ORDER CARDS =====\n";
    bool found = false;
    for (int i = 0; i < 20; ++i) {
        if (used[i]) {
            std::cout << "OrderCard " << (i + 1)
                      << " | OrderId: " << cardIds[i] << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No occupied order cards.\n";
    }
}

void EmployeeView::showOrderDetail(const Orders& order, int cardId,
                                    const std::vector<OrderItems>& items, double total) const {
    std::cout << "\n===== ORDER DETAIL =====\n";
    std::cout << "OrderId: " << order.getOrderId()
              << " | OrderCardId: " << cardId << "\n";

    for (const auto& item : items) {
        double lineTotal = item.getQuantity() * item.getUnitPrice();
        std::cout << "ProdId: " << item.getProdId()
                  << " | Size: " << item.getSizeLabel()
                  << " | Qty: " << item.getQuantity()
                  << " | UnitPrice: " << item.getUnitPrice()
                  << " | LineTotal: " << lineTotal << "\n";
    }
    std::cout << "TOTAL: " << total << "\n";
}

int EmployeeView::promptOrderCardToPay() const {
    int cardId;
    std::cout << "Enter OrderCardID to pay: ";
    std::cin >> cardId;
    return cardId;
}

int EmployeeView::promptProductId() const {
    int prodId;
    std::cout << "\nEnter ProdId to add to Order(0 to cancel): ";
    std::cin >> prodId;
    return prodId;
}

int EmployeeView::promptSizeChoice() const {
    std::cout << "\nChoose size:\n";
    std::cout << "1. S\n2. M\n3. L\n";
    std::cout << "Choice: ";
    int choice;
    std::cin >> choice;
    return choice;
}

int EmployeeView::promptQuantity() const {
    int qty;
    std::cout << "Enter quantity: ";
    std::cin >> qty;
    return qty;
}

std::string EmployeeView::promptPaymentMethod() const {
    std::string input;
    std::cout << "Enter payment method (C/Cash, M/Card): ";
    std::cin >> input;
    if (input == "C" || input == "Cash") return "Cash";
    if (input == "M" || input == "Card") return "Card";
    return "";
}

std::string EmployeeView::promptCustPhone() const {
    std::string phone;
    std::cout << "Enter CustPhone: ";
    std::cin >> phone;
    return phone;
}

std::string EmployeeView::promptCustName() const {
    std::string name;
    std::cout << "Enter CustName: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    return name;
}

void EmployeeView::showCustomerInfo(const Customer& c) const {
    std::cout << "Customer: " << c.getCustName() << "\n";
    std::cout << "Phone: " << c.getCustPhone() << "\n";
    std::cout << "Point: " << c.getPoint() << "\n";
}

void EmployeeView::showMessage(const std::string& msg) const {
    std::cout << msg << "\n";
}

void EmployeeView::showActiveDiscounts(const std::vector<Discount>& discounts) const {
    std::cout << "\n--- Available Discounts ---\n";
    std::cout << "0. No Discount\n";

    for (const auto& d : discounts) {
        std::cout << d.getDiscountId() << ". Code: " << d.getCode()
                  << " (" << d.getValue()
                  << (d.getType() == "Percentage" ? "%" : " USD") << " off)\n";
    }
}

int EmployeeView::promptDiscountChoice() const {
    int choice;
    std::cout << "Select Discount ID (or 0 to skip): ";
    std::cin >> choice;
    return choice;
}

void EmployeeView::displayModifiers(const std::vector<Modifiers>& modifiers) const{
    std::cout << "\n--- Available Modifiers ---" << std::endl;
    for (const auto& mod : modifiers) {
        std::cout << mod.getModId() << ". " << mod.getModName() << " (+" << mod.getExtraCost() << "đ)" << std::endl;
    }
}