#include "ManagerController.h"
#include "../utils/DataHelper.h"
#include <limits>
#include "../Model/Repo/EmployeeRepo.h"

void ManagerController::createCategory() {
    int cateId = DataHelper::getNextId(db, "Categories", "CateId");

    std::string cateName;
    int displayOrder;

    std::cout << "Category name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, cateName);

    std::cout << "Display order: ";
    std::cin >> displayOrder;

    Categories ct;
    ct.setCateId(cateId);
    ct.setCateName(cateName);
    ct.setDisplayOrder(displayOrder);

    cr.addCategories(ct);

    std::cout << "Category created successfully.\n";
}
void ManagerController::editCategory() {
    int id;
    std::cout << "Enter Category ID to edit: ";
    std::cin >> id;
    Categories ct = cr.getByID(id);
    if (ct.getCateId() == 0) {
        std::cout << "Category not found!\n";
        return;
    }

    std::string newName;
    int newOrder;
    std::cout << "Current Name: " << ct.getCateName() << " -> New Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, newName);

    std::cout << "Current Order: " << ct.getDisplayOrder() << " -> New Order: ";
    std::cin >> newOrder;

    ct.setCateName(newName);
    ct.setDisplayOrder(newOrder);
    cr.update(ct);
    std::cout << "Category updated successfully.\n";
}
void ManagerController::deleteCategory() {
    int id;
    std::cout << "Enter Category ID to delete: ";
    std::cin >> id;
    // Lưu ý: Trong thực tế nên kiểm tra xem có Product nào thuộc Cate này không trước khi xóa
    cr.remove(id);
    std::cout << "Category deleted successfully.\n";
}
void ManagerController::createProduct() {
    std::vector<Categories> listCate = cr.getAll();
    if (listCate.empty()) {
        std::cout << "No categories found!\n";
        return;
    }

    std::cout << "\n========== CATEGORIES ==========\n";
    for (size_t i = 0; i < listCate.size(); i++) {
        std::cout << i + 1 << ". " << listCate[i].getCateName()
                  << " (ID: " << listCate[i].getCateId() << ")\n";
    }

    int cateChoice;
    std::cout << "Choose category: ";
    std::cin >> cateChoice;

    if (cateChoice < 1 || cateChoice > (int)listCate.size()) {
        std::cout << "Invalid choice!\n";
        return;
    }

    int selectedCateId = listCate[cateChoice - 1].getCateId();
    int autoProdId = DataHelper::getNextId(db, "Products", "ProdId");

    std::string prodName;
    int prodPrice;

    std::cout << "Product name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, prodName);

    std::cout << "Product base price: ";
    std::cin >> prodPrice;

    Product p;
    p.setProdId(autoProdId);
    p.setCateId(selectedCateId);
    p.setProdName(prodName);
    p.setProdPrice(prodPrice);

    pr.addProduct(p);

    std::cout << "Product created successfully.\n";
}
void ManagerController::editProduct() {
    int id;
    std::cout << "Enter Product ID to edit: ";
    std::cin >> id;
    Product p = pr.getByID(id);
    if (p.getProdId() == 0) {
        std::cout << "Product not found!\n";
        return;
    }

    std::string newName;
    double newPrice;
    std::cout << "Current Name: " << p.getProdName() << " -> New Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, newName);

    std::cout << "Current Price: " << p.getProdPrice() << " -> New Price: ";
    std::cin >> newPrice;

    p.setProdName(newName);
    p.setProdPrice(newPrice);
    pr.update(p);
    std::cout << "Product updated successfully.\n";
}
void ManagerController::deleteProduct() {
    int id;
    std::cout << "Enter Product ID to delete: ";
    std::cin >> id;
    pr.remove(id);
    std::cout << "Product deleted successfully.\n";
}
void ManagerController::showAllProducts() {
    std::vector<Product> products = pr.getAll();
    if (products.empty()) {
        std::cout << "No products found.\n";
        return;
    }

    std::cout << "\n========== PRODUCTS ==========\n";
    for (const auto& p : products) {
        std::cout << p.toString() << "\n";
    }
}
void ManagerController::showAllCategories() {
    std::vector<Categories> categories = cr.getAll();
    if (categories.empty()) {
        std::cout << "No categories found.\n";
        return;
    }

    std::cout << "\n========== CATEGORIES ==========\n";
    for (const auto& c : categories) {
        std::cout << c.toString() << "\n";
    }
}
void ManagerController::createEmployee() {
    int autoId = DataHelper::getNextId(db, "Staffs", "StaffId");
    std::string name;
    int roleChoice;

    std::cout << "\n----- Add New Employee -----\n";
    std::cout << "Employee Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);


    std::cout << "Select Role:\n";
    std::cout << "1. Admin\n";
    std::cout << "2. Staff\n";
    std::cout << "Choice: ";

    while (!(std::cin >> roleChoice) || (roleChoice != 1 && roleChoice != 2)) {
        std::cout << "Invalid choice! Please select 1 (Admin) or 2 (Staff): ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    // Ép kiểu từ int sang Role enum
    Role selectedRole = static_cast<Role>(roleChoice);

    Employee s;
    s.setId(autoId);
    s.setName(name);
    s.setRole(selectedRole);

    sr.addStaff(s);
    std::cout << "Employee [ " << name << " ] added successfully with Role: "
              << (selectedRole == Role_Manager ? "Manager" : "Staff") << "\n";
}
void ManagerController::editEmployee() {
    int id;
    std::cout << "Enter Employee ID to edit: ";
    std::cin >> id;

    // Giả sử sr trả về đối tượng Employee
    Employee e = sr.getByID(id);
    if (e.getId() == 0) {
        std::cout << "Employee not found!\n";
        return;
    }

    std::string newName, newPhone, newPass;
    int roleChoice;

    std::cout << "Current Name: " << e.getName() << " -> New Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, newName);

    std::cout << "Current Phone: " << e.getPhoneNumber() << " -> New Phone: ";
    std::getline(std::cin, newPhone);

    std::cout << "Enter New PIN/Password: ";
    std::cin >> newPass;

    // Hiển thị vai trò hiện tại dựa trên enum Role { Staff = 1, Manager = 2 }
    std::cout << "Current Role: " << (e.getRole() == Role_Staff ? "Staff" : "Manager") << "\n";
    std::cout << "Select New Role (1. Staff, 2. Manager): ";

    while (!(std::cin >> roleChoice) || (roleChoice != 1 && roleChoice != 2)) {
        std::cout << "Invalid choice! Select 1 for Staff or 2 for Manager: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    e.setName(newName);
    e.setPhoneNumber(newPhone);
    e.setPinHash(newPass); // Lưu ý: Nên dùng hàm băm password nếu có
    e.setRole(static_cast<Role>(roleChoice));

    sr.update(e);
    std::cout << "Employee [ " << newName << " ] updated successfully.\n";
}
void ManagerController::deleteEmployee() {
    int id;
    std::cout << "Enter Staff ID to delete: ";
    std::cin >> id;

    // Nên có bước xác nhận trước khi xóa
    char confirm;
    std::cout << "Are you sure you want to delete this employee? (y/n): ";
    std::cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        sr.remove(id);
        std::cout << "Employee deleted successfully.\n";
    } else {
        std::cout << "Deletion cancelled.\n";
    }
}
void ManagerController::showAllEmployees() {
    StaffRepo sr(db);
    std::vector<Employee> list = sr.getAll();
    std::cout << "\n========== EMPLOYEES ==========\n";
    for (const auto& s : list) {
        std::cout << "ID: " << s.getId() << " | Name: " << s.getName()
                  << " | Role: " << s.getRole() << "\n";
    }
}
void ManagerController::checkIncome() {
    PaymentRepo PaymentRepo(db);
    std::vector<Payments> payments = PaymentRepo.getAll();
    double total = 0;
    std::cout << "\n========== INCOME REPORT ==========\n";
    for (const auto& p : payments) {
        std::cout << "Order ID: " << p.getOrderId()
                  << " | Method: " << p.getMethod()
                  << " | Amount: " << p.getAmount() << "\n";
        total += p.getAmount();
    }
    std::cout << "-----------------------------------\n";
    std::cout << "TOTAL REVENUE: " << total << "\n";
}

void ManagerController::run() {
    int choice;
    do {
        std::cout << "\n===== MANAGER UI =====\n"
                     "1. Category\n"
                     "2. Product\n"
                     "3. Employee\n"
                     "4. Check Income\n"
                     "0. Exit\n"
                     "Choose: ";
        std::cin >> choice;
        int subChoice = 0;
        switch (choice) {
            case 1:
                std::cout << "1. Create Category\n";
                std::cout << "3. Show All Categories\n";
                std::cout << "2. Edit Category\n";
                std::cout << "4. Delete Category\n";
                std::cout << "Choose: "; std::cin >> subChoice;
                switch (subChoice) {
                    case 1: createCategory(); break;
                    case 2: editCategory(); break;
                    case 3: showAllCategories(); break;
                    case 4: deleteCategory(); break;
                    default: std::cout << "Invalid choice!\n";
                }
                break;
            case 2:
                std::cout << "1. Create Product\n"
                "2. Show All Products\n"
                "3. Edit Product\n"
                "4. Delete Product\n";
                std::cout << "Choose: "; std::cin >> subChoice;
                switch (subChoice) {
                    case 1: createProduct(); break;
                    case 2: showAllProducts(); break;
                    case 3: editProduct(); break;
                    case 4: deleteProduct(); break;
                    default: std::cout << "Invalid choice!\n";
                }
                break;
            case 3:
                std::cout << "1. Create Employee\n"
                "2. Show All Employee\n"
                "3. Edit Employee\n"
                "4. Delete Employee\n";
                std::cout << "Choose: "; std::cin >> subChoice;
                switch (subChoice) {
                    case 1: createEmployee(); break;
                    case 2: showAllEmployees(); break;
                    case 3: editEmployee(); break;
                    case 4: deleteEmployee(); break;
                    default: std::cout << "Invalid choice!\n";
                }
                break;
            case 4:
                checkIncome();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 0);
}