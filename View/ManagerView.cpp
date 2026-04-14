//
// Created by admin on 4/11/2026.
//

#include "ManagerView.h"
#include <limits>
#include <iomanip>

void ManagerView::showManagerMenu() const {
    std::cout << "\n===== MANAGER UI =====\n";
    std::cout << "1. Categories\n";
    std::cout << "2. Product\n";
    std::cout << "3. Employee\n";
    std::cout << "4. Check Income\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose: ";
}

int ManagerView::getMenuChoice() const {
    int choice;
    std::cin >> choice;
    return choice;
}

void ManagerView::showCrudMenu(const std::string& entityName) const {
    std::cout << "\n===== " << entityName << " MANAGEMENT =====\n";
    std::cout << "1. Add " << entityName << "\n";
    std::cout << "2. View All " << entityName << "\n";
    std::cout << "3. Update " << entityName << "\n";
    std::cout << "4. Delete " << entityName << "\n";
    std::cout << "0. Back\n";
    std::cout << "Choose: ";
}

// ─── Category ───

std::string ManagerView::promptCategoryName() const {
    std::string name;
    std::cout << "Category name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    return name;
}

int ManagerView::promptDisplayOrder() const {
    int order;
    std::cout << "Display order: ";
    std::cin >> order;
    return order;
}

int ManagerView::promptCategoryChoice(const std::vector<Categories>& categories) const {
    std::cout << "\n========== CATEGORIES ==========\n";
    for (size_t i = 0; i < categories.size(); i++) {
        std::cout << i + 1 << ". " << categories[i].getCateName()
                  << " (ID: " << categories[i].getCateId() << ")\n";
    }
    int choice;
    std::cout << "Choose category: ";
    std::cin >> choice;
    return choice;
}

int ManagerView::promptCategoryId() const {
    int id;
    std::cout << "Enter Category ID: ";
    std::cin >> id;
    return id;
}

void ManagerView::showAllCategories(const std::vector<Categories>& categories) const {
    if (categories.empty()) {
        std::cout << "No categories found.\n";
        return;
    }
    std::cout << "\n========== CATEGORIES ==========\n";
    for (const auto& c : categories) {
        std::cout << c.toString() << "\n";
    }
}

// ─── Product ───

std::string ManagerView::promptProductName() const {
    std::string name;
    std::cout << "Product name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    return name;
}

int ManagerView::promptProductPrice() const {
    int price;
    std::cout << "Product base price: ";
    std::cin >> price;
    return price;
}

int ManagerView::promptProductId() const {
    int id;
    std::cout << "Enter Product ID: ";
    std::cin >> id;
    return id;
}

void ManagerView::showAllProducts(const std::vector<Product>& products) const {
    if (products.empty()) {
        std::cout << "No products found.\n";
        return;
    }
    std::cout << "\n========== PRODUCTS ==========\n";
    for (const auto& p : products) {
        std::cout << p.toString() << "\n";
    }
}

// ─── Employee ───

std::string ManagerView::promptEmployeeName() const {
    std::string name;
    std::cout << "Employee name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    return name;
}

std::string ManagerView::promptEmployeePhone() const {
    std::string phone;
    std::cout << "Employee phone: ";
    std::cin >> phone;
    return phone;
}

std::string ManagerView::promptEmployeePin() const {
    std::string pin;
    std::cout << "Employee PIN: ";
    std::cin >> pin;
    return pin;
}

int ManagerView::promptEmployeeRole() const {
    int role;
    std::cout << "Role (1 = Staff, 2 = Manager): ";
    std::cin >> role;
    return role;
}

int ManagerView::promptEmployeeId() const {
    int id;
    std::cout << "Enter Employee ID: ";
    std::cin >> id;
    return id;
}

void ManagerView::showAllEmployees(const std::vector<Employee>& employees) const {
    if (employees.empty()) {
        std::cout << "No employees found.\n";
        return;
    }
    std::cout << "\n========== EMPLOYEES ==========\n";
    for (const auto& e : employees) {
        std::string roleStr = (e.getRole() == Manager) ? "Manager" : "Staff";
        std::string activeStr = e.getIsActive() ? "Active" : "Inactive";
        std::cout << "ID: " << e.getId()
                  << " | " << e.getName()
                  << " | " << e.getPhoneNumber()
                  << " | " << roleStr
                  << " | " << activeStr << "\n";
    }
}

// ─── Income ───

int ManagerView::showDatesAndSelect(const std::vector<std::string>& dates) const {
    if (dates.empty()) {
        std::cout << "No income data found.\n";
        return 0;
    }
    std::cout << "\n========== INCOME BY DATE ==========\n";
    for (size_t i = 0; i < dates.size(); i++) {
        std::cout << i + 1 << ". " << dates[i] << "\n";
    }
    std::cout << "0. Back\n";
    std::cout << "Select a day: ";
    int choice;
    std::cin >> choice;
    return choice;
}

int ManagerView::showOrdersAndSelect(const std::vector<Orders>& orders,
                                     const std::vector<double>& totals) const {
    if (orders.empty()) {
        std::cout << "No orders on this day.\n";
        return 0;
    }
    std::cout << "\n========== BILLS ==========\n";
    for (size_t i = 0; i < orders.size(); i++) {
        std::cout << i + 1 << ". OrderID: " << orders[i].getOrderId()
                  << " | Total: " << std::fixed << std::setprecision(2) << totals[i]
                  << " | Time: " << orders[i].getCreatedAt() << "\n";
    }
    std::cout << "0. Back\n";
    std::cout << "Select a bill: ";
    int choice;
    std::cin >> choice;
    return choice;
}

void ManagerView::showBillDetail(const Orders& order,
                                 const std::vector<OrderItems>& items,
                                 const std::vector<Payments>& payments,
                                 double total) const {
    std::cout << "\n========== BILL DETAIL ==========\n";
    std::cout << "OrderID: " << order.getOrderId()
              << " | StaffID: " << order.getStaffId()
              << " | CustID: " << order.getCustId()
              << " | Created: " << order.getCreatedAt() << "\n";

    std::cout << "\n--- Items ---\n";
    for (const auto& item : items) {
        double lineTotal = item.getQuantity() * item.getUnitPrice();
        std::cout << "  ProdID: " << item.getProdId()
                  << " | Size: " << item.getSizeLabel()
                  << " | Qty: " << item.getQuantity()
                  << " | UnitPrice: " << std::fixed << std::setprecision(2) << item.getUnitPrice()
                  << " | Subtotal: " << lineTotal << "\n";
    }

    std::cout << "\n--- Payment ---\n";
    for (const auto& pay : payments) {
        std::cout << "  PayID: " << pay.getPayId()
                  << " | Method: " << pay.getMethod()
                  << " | Amount: " << std::fixed << std::setprecision(2) << pay.getAmount() << "\n";
    }

    std::cout << "\nTOTAL: " << std::fixed << std::setprecision(2) << total << "\n";
}

void ManagerView::showDailyIncome(const std::string& date, double income) const {
    std::cout << "  >> Income on " << date << ": "
              << std::fixed << std::setprecision(2) << income << "\n";
}

void ManagerView::showMessage(const std::string& msg) const {
    std::cout << msg << "\n";
}