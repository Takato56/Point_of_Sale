#include "ManagerController.h"
#include "../utils/DataHelper.h"
#include "../utils/PasswordHasher.h"

// ═══════════════════════════════════════════
//  CATEGORY CRUD
// ═══════════════════════════════════════════

void ManagerController::addCategory() {
    int cateId = DataHelper::getNextId(db, "Categories", "CateId");
    std::string cateName = mgrView.promptCategoryName();
    int displayOrder = mgrView.promptDisplayOrder();

    Categories ct;
    ct.setCateId(cateId);
    ct.setCateName(cateName);
    ct.setDisplayOrder(displayOrder);

    cr.addCategories(ct);
    mgrView.showMessage("Category created successfully.");
}

void ManagerController::viewAllCategories() {
    mgrView.showAllCategories(cr.getAll());
}

void ManagerController::updateCategory() {
    viewAllCategories();
    int id = mgrView.promptCategoryId();

    Categories ct = cr.getByID(id);
    if (ct.getCateId() == 0) {
        mgrView.showMessage("Category not found!");
        return;
    }

    mgrView.showMessage("Current name: " + ct.getCateName());
    std::string newName = mgrView.promptCategoryName();
    int newOrder = mgrView.promptDisplayOrder();

    ct.setCateName(newName);
    ct.setDisplayOrder(newOrder);
    cr.update(ct);
    mgrView.showMessage("Category updated successfully.");
}

void ManagerController::deleteCategory() {
    viewAllCategories();
    int id = mgrView.promptCategoryId();

    Categories ct = cr.getByID(id);
    if (ct.getCateId() == 0) {
        mgrView.showMessage("Category not found!");
        return;
    }

    cr.remove(id);
    mgrView.showMessage("Category deleted successfully.");
}

void ManagerController::categoryMenu() {
    int choice;
    do {
        mgrView.showCrudMenu("Category");
        choice = mgrView.getMenuChoice();

        switch (choice) {
            case 1: addCategory(); break;
            case 2: viewAllCategories(); break;
            case 3: updateCategory(); break;
            case 4: deleteCategory(); break;
            case 0: break;
            default: mgrView.showMessage("Invalid choice!"); break;
        }
    } while (choice != 0);
}

// ═══════════════════════════════════════════
//  PRODUCT CRUD
// ═══════════════════════════════════════════

void ManagerController::addProduct() {
    std::vector<Categories> listCate = cr.getAll();
    if (listCate.empty()) {
        mgrView.showMessage("No categories found! Create a category first.");
        return;
    }

    int cateChoice = mgrView.promptCategoryChoice(listCate);
    if (cateChoice < 1 || cateChoice > static_cast<int>(listCate.size())) {
        mgrView.showMessage("Invalid choice!");
        return;
    }

    int selectedCateId = listCate[cateChoice - 1].getCateId();
    int autoProdId = DataHelper::getNextId(db, "Products", "ProdId");

    std::string prodName = mgrView.promptProductName();
    int prodPrice = mgrView.promptProductPrice();

    Product p;
    p.setProdId(autoProdId);
    p.setCateId(selectedCateId);
    p.setProdName(prodName);
    p.setProdPrice(prodPrice);

    pr.addProduct(p);
    mgrView.showMessage("Product created successfully.");
}

void ManagerController::viewAllProducts() {
    mgrView.showAllProducts(pr.getAll());
}

void ManagerController::updateProduct() {
    viewAllProducts();
    int id = mgrView.promptProductId();

    Product p = pr.getByID(id);
    if (p.getProdId() == 0) {
        mgrView.showMessage("Product not found!");
        return;
    }

    mgrView.showMessage("Current: " + p.toString());

    std::vector<Categories> listCate = cr.getAll();
    if (!listCate.empty()) {
        mgrView.showMessage("Select new category (or same):");
        int cateChoice = mgrView.promptCategoryChoice(listCate);
        if (cateChoice >= 1 && cateChoice <= static_cast<int>(listCate.size())) {
            p.setCateId(listCate[cateChoice - 1].getCateId());
        }
    }

    std::string newName = mgrView.promptProductName();
    int newPrice = mgrView.promptProductPrice();

    p.setProdName(newName);
    p.setProdPrice(newPrice);
    pr.update(p);
    mgrView.showMessage("Product updated successfully.");
}

void ManagerController::deleteProduct() {
    viewAllProducts();
    int id = mgrView.promptProductId();

    Product p = pr.getByID(id);
    if (p.getProdId() == 0) {
        mgrView.showMessage("Product not found!");
        return;
    }

    pr.remove(id);
    mgrView.showMessage("Product deleted successfully.");
}

void ManagerController::productMenu() {
    int choice;
    do {
        mgrView.showCrudMenu("Product");
        choice = mgrView.getMenuChoice();

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewAllProducts(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 0: break;
            default: mgrView.showMessage("Invalid choice!"); break;
        }
    } while (choice != 0);
}

// ═══════════════════════════════════════════
//  EMPLOYEE CRUD
// ═══════════════════════════════════════════

void ManagerController::addEmployee() {
    std::string name = mgrView.promptEmployeeName();
    std::string phone = mgrView.promptEmployeePhone();
    std::string pin = mgrView.promptEmployeePin();
    int roleChoice = mgrView.promptEmployeeRole();

    Employee emp;
    emp.setName(name);
    emp.setPhoneNumber(phone);
    emp.setPinHash(PasswordHasher::hash(pin));
    emp.setRole(roleChoice == 2 ? Manager : Staff);
    emp.setIsActive(1);

    er.addEmployee(emp);
    mgrView.showMessage("Employee added successfully. ID: " + std::to_string(emp.getId()));
}

void ManagerController::viewAllEmployees() {
    mgrView.showAllEmployees(er.getAll());
}

void ManagerController::updateEmployee() {
    viewAllEmployees();
    int id = mgrView.promptEmployeeId();

    Employee emp = er.getById(id);
    if (emp.getId() == 0) {
        mgrView.showMessage("Employee not found!");
        return;
    }

    mgrView.showMessage("Updating: " + emp.getName());

    std::string newName = mgrView.promptEmployeeName();
    std::string newPhone = mgrView.promptEmployeePhone();
    int newRole = mgrView.promptEmployeeRole();

    emp.setName(newName);
    emp.setPhoneNumber(newPhone);
    emp.setRole(newRole == 2 ? Manager : Staff);

    er.update(emp);
    mgrView.showMessage("Employee updated successfully.");
}

void ManagerController::deleteEmployee() {
    viewAllEmployees();
    int id = mgrView.promptEmployeeId();

    Employee emp = er.getById(id);
    if (emp.getId() == 0) {
        mgrView.showMessage("Employee not found!");
        return;
    }

    er.remove(id);
    mgrView.showMessage("Employee deleted successfully.");
}

void ManagerController::employeeMenu() {
    int choice;
    do {
        mgrView.showCrudMenu("Employee");
        choice = mgrView.getMenuChoice();

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewAllEmployees(); break;
            case 3: updateEmployee(); break;
            case 4: deleteEmployee(); break;
            case 0: break;
            default: mgrView.showMessage("Invalid choice!"); break;
        }
    } while (choice != 0);
}

// ═══════════════════════════════════════════
//  CHECK INCOME
// ═══════════════════════════════════════════

void ManagerController::checkIncome() {
    // Step 1: Show all dates with income
    std::vector<std::string> dates = orderRepo.getDistinctDates();
    int dateChoice = mgrView.showDatesAndSelect(dates);

    if (dateChoice == 0 || dateChoice < 0 || dateChoice > static_cast<int>(dates.size())) {
        return;
    }

    std::string selectedDate = dates[dateChoice - 1];

    // Step 2: Get all orders on that date, calc totals
    std::vector<Orders> dayOrders = orderRepo.getByDate(selectedDate);
    std::vector<double> totals;
    double dailyIncome = 0.0;

    for (const auto& order : dayOrders) {
        std::vector<OrderItems> items = oiRepo.getByOrderID(order.getOrderId());
        double orderTotal = 0.0;
        for (const auto& item : items) {
            orderTotal += item.getQuantity() * item.getUnitPrice();
        }
        totals.push_back(orderTotal);
        dailyIncome += orderTotal;
    }

    mgrView.showDailyIncome(selectedDate, dailyIncome);

    // Step 3: Let user pick a bill
    int billChoice = mgrView.showOrdersAndSelect(dayOrders, totals);

    if (billChoice == 0 || billChoice < 0 || billChoice > static_cast<int>(dayOrders.size())) {
        return;
    }

    // Step 4: Show full bill detail
    Orders selectedOrder = dayOrders[billChoice - 1];
    std::vector<OrderItems> items = oiRepo.getByOrderID(selectedOrder.getOrderId());
    std::vector<Payments> payments = payRepo2.getByOrderID(selectedOrder.getOrderId());

    mgrView.showBillDetail(selectedOrder, items, payments, totals[billChoice - 1]);
}

// ═══════════════════════════════════════════
//  MAIN RUN LOOP
// ═══════════════════════════════════════════

void ManagerController::run() {
    int choice;
    do {
        mgrView.showManagerMenu();
        choice = mgrView.getMenuChoice();

        switch (choice) {
            case 1: categoryMenu(); break;
            case 2: productMenu(); break;
            case 3: employeeMenu(); break;
            case 4: checkIncome(); break;
            case 0: break;
            default: mgrView.showMessage("Invalid choice!"); break;
        }
    } while (choice != 0);
}