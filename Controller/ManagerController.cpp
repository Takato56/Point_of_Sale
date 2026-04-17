#include "ManagerController.h"
#include "../utils/DataHelper.h"
#include "../utils/PasswordHasher.h"
#include <iomanip>
#include <regex>

// ═══════════════════════════════════════════
//  CATEGORY CRUD
// ═══════════════════════════════════════════

void ManagerController::addCategory() {
    int cateId = DataHelper::getNextId(getDB(), "Categories", "CateId");
    std::string cateName = mgrView.promptCategoryName();
    int displayOrder = mgrView.promptDisplayOrder();

    Categories ct;
    ct.setCateId(cateId);
    ct.setCateName(cateName);
    ct.setDisplayOrder(displayOrder);

    mgrCateRepo.addCategories(ct);
    mgrView.showMessage("Category created successfully.");
}

void ManagerController::viewAllCategories() {
    menuView.showAllCategories(mgrCateRepo.getAll());
}

void ManagerController::updateCategory() {
    viewAllCategories();
    int id = mgrView.promptCategoryId();

    Categories ct = mgrCateRepo.getByID(id);
    if (ct.getCateId() == 0) {
        mgrView.showMessage("Category not found!");
        return;
    }

    mgrView.showMessage("Current name: " + ct.getCateName());
    std::string newName = mgrView.promptCategoryName();
    int newOrder = mgrView.promptDisplayOrder();

    ct.setCateName(newName);
    ct.setDisplayOrder(newOrder);
    mgrCateRepo.update(ct);
    mgrView.showMessage("Category updated successfully.");
}

void ManagerController::deleteCategory() {
    viewAllCategories();
    int id = mgrView.promptCategoryId();

    Categories ct = mgrCateRepo.getByID(id);
    if (ct.getCateId() == 0) {
        mgrView.showMessage("Category not found!");
        return;
    }

    mgrCateRepo.remove(id);
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
    std::vector<Categories> listCate = mgrCateRepo.getAll();
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
    int autoProdId = DataHelper::getNextId(getDB(), "Products", "ProdId");

    std::string prodName = mgrView.promptProductName();
    int prodPrice = mgrView.promptProductPrice();

    Product p;
    p.setProdId(autoProdId);
    p.setCateId(selectedCateId);
    p.setProdName(prodName);
    p.setProdPrice(prodPrice);

    mgrProdRepo.addProduct(p);
    mgrView.showMessage("Product created successfully.");
}

void ManagerController::viewAllProducts() {
    showProductByCateId();
}

void ManagerController::updateProduct() {
    showProductByCateId();
    int id = mgrView.promptProductId();

    Product p = mgrProdRepo.getByID(id);
    if (p.getProdId() == 0) {
        mgrView.showMessage("Product not found!");
        return;
    }

    mgrView.showMessage("Current: " + p.toString());

    std::vector<Categories> listCate = mgrCateRepo.getAll();
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
    mgrProdRepo.update(p);
    mgrView.showMessage("Product updated successfully.");
}

void ManagerController::deleteProduct() {
    showProductByCateId();
    int id = mgrView.promptProductId();

    Product p = mgrProdRepo.getByID(id);
    if (p.getProdId() == 0) {
        mgrView.showMessage("Product not found!");
        return;
    }

    mgrProdRepo.remove(id);
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
    std::string phone;

    Staff existing;
    const std::regex phonePattern("^0[0-9]{9}$");
    do {
        phone = mgrView.promptEmployeePhone();
        existing = mgrStaffRepo.getByPhone(phone);
        if (existing.getPhoneNumber() == phone)
            mgrView.showMessage("This phone number already exists, please enter a different phone.");
        if (!std::regex_match(phone, phonePattern))
            mgrView.showMessage("Invalid phone number. Please enter a valid phone number (e.g., 0123456789).");
    } while (existing.getPhoneNumber() == phone || !std::regex_match(phone, phonePattern));

    const std::regex pinPattern("^[0-9]{6}$");
    std::string pin;
    do {
        pin = mgrView.promptEmployeePin();
        if (!std::regex_match(pin, pinPattern)) {
            mgrView.showMessage("Invalid PIN code. Please enter a valid PIN code (e.g., 123456).");
        }
    } while (!std::regex_match(pin, pinPattern));

    int roleChoice = mgrView.promptEmployeeRole();

    Staff newStf;
    newStf.setName(name);
    newStf.setPhoneNumber(phone);
    newStf.setPinHash(PasswordHasher::hash(pin));
    newStf.setRole(roleChoice == 2 ? Role_Manager : Role_Staff);
    newStf.setIsActive(1);

    mgrStaffRepo.addStaff(newStf);
    mgrView.showMessage("Employee added successfully. ID: " + std::to_string(newStf.getId()));
}

void ManagerController::viewAllEmployees() {
    mgrView.showAllEmployees(mgrStaffRepo.getAll());
}

void ManagerController::updateEmployee() {
    viewAllEmployees();
    int id = mgrView.promptEmployeeId();

    Staff stf = mgrStaffRepo.getById(id);
    if (stf.getId() == 0) {
        mgrView.showMessage("Employee not found!");
        return;
    }

    mgrView.showMessage("Updating: " + stf.getName());

    std::string newName = mgrView.promptEmployeeName();
    std::string newPhone = mgrView.promptEmployeePhone();
    int newRole = mgrView.promptEmployeeRole();

    stf.setName(newName);
    stf.setPhoneNumber(newPhone);
    stf.setRole(newRole == 2 ? Role_Manager : Role_Staff);

    mgrStaffRepo.update(stf);
    mgrView.showMessage("Employee updated successfully.");
}

void ManagerController::deleteEmployee() {
    viewAllEmployees();
    int id = mgrView.promptEmployeeId();

    Staff stf = mgrStaffRepo.getById(id);
    if (stf.getId() == 0) {
        mgrView.showMessage("Employee not found!");
        return;
    }

    mgrStaffRepo.remove(id);
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
    std::vector<std::string> dates = mgrOrderRepo.getDistinctDates();

    if (dates.empty()) {
        mgrView.showMessage("No data available.");
        return;
    }

    int dateChoice = mgrView.showDatesAndSelect(dates);
    if (dateChoice <= 0 || dateChoice > static_cast<int>(dates.size())) {
        mgrView.showMessage("Invalid Date ID selected!");
        return;
    }

    std::string selectedDate = dates[dateChoice - 1];
    std::vector<Orders> dayOrders = mgrOrderRepo.getByDate(selectedDate);
    std::vector<double> totals;
    double dailyIncome = 0.0;

    for (const auto& order : dayOrders) {
        std::vector<OrderItems> items = mgrOiRepo.getByOrderID(order.getOrderId());
        double orderTotal = 0.0;
        for (const auto& item : items) {
            orderTotal += item.getQuantity() * item.getUnitPrice();
        }
        totals.push_back(orderTotal);
        dailyIncome += orderTotal;
    }

    mgrView.showDailyIncome(selectedDate, dailyIncome);

    int billChoice = mgrView.showOrdersAndSelect(dayOrders, totals);
    if (billChoice <= 0 || billChoice > static_cast<int>(dayOrders.size())) {
        mgrView.showMessage("Invalid Order ID selected!");
        return;
    }

    Orders selectedOrder = dayOrders[billChoice - 1];
    std::vector<OrderItems> items = mgrOiRepo.getByOrderID(selectedOrder.getOrderId());
    std::vector<Payments> payments = mgrPayRepo.getByOrderID(selectedOrder.getOrderId());

    mgrView.showBillDetail(selectedOrder, items, payments, totals[billChoice - 1]);
}

// ═══════════════════════════════════════════
//  DISCOUNT CRUD
// ═══════════════════════════════════════════

void ManagerController::addDiscount() {
    std::string code = mgrView.promptDiscountCode();
    std::string type = mgrView.promptDiscountType();
    int value = mgrView.promptDiscountValue(type);

    Discount d;
    d.setCode(code);
    d.setValue(value);
    d.setType(type);
    d.setIsActive(1);

    mgrDiscountRepo.addDiscount(d);
    mgrView.showMessage("Discount added successfully. ID: " + std::to_string(d.getDiscountId()));
}

void ManagerController::viewAllDiscounts() {
    mgrView.showAllDiscounts(mgrDiscountRepo.getAll());
}

void ManagerController::updateDiscount() {
    viewAllDiscounts();
    int id = mgrView.promptDiscountId();

    Discount d = mgrDiscountRepo.getByID(id);
    if (d.getDiscountId() == 0) {
        mgrView.showMessage("Discount not found!");
        return;
    }

    mgrView.showMessage("Updating: " + d.getCode());

    std::string newCode = mgrView.promptDiscountCode();
    std::string newType = mgrView.promptDiscountType();
    int newValue = mgrView.promptDiscountValue(newType);

    d.setCode(newCode);
    d.setType(newType);
    d.setValue(newValue);

    mgrDiscountRepo.update(d);
    mgrView.showMessage("Discount updated successfully.");
}

void ManagerController::deleteDiscount() {
    viewAllDiscounts();
    int id = mgrView.promptDiscountId();

    Discount d = mgrDiscountRepo.getByID(id);
    if (d.getDiscountId() == 0) {
        mgrView.showMessage("Discount not found!");
        return;
    }

    mgrDiscountRepo.remove(id);
    mgrView.showMessage("Discount deleted successfully.");
}

void ManagerController::discountMenu() {
    int choice;
    do {
        mgrView.showCrudMenu("Discount");
        choice = mgrView.getMenuChoice();

        switch (choice) {
            case 1: addDiscount(); break;
            case 2: viewAllDiscounts(); break;
            case 3: updateDiscount(); break;
            case 4: deleteDiscount(); break;
            case 0: break;
            default: mgrView.showMessage("Invalid choice!"); break;
        }
    } while (choice != 0);
}

void ManagerController::openEmployeeMenu() {
    this->setCurrentStaffId(this->currentStaffId);
    EmployeeController::run();
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
            case 4: discountMenu(); break;
            case 5: checkIncome(); break;
            case 6: openEmployeeMenu(); break;
            case 0: break;
            default: mgrView.showMessage("Invalid choice!"); break;
        }
    } while (choice != 0);
}