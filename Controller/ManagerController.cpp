#include "ManagerController.h"
#include "../utils/DataHelper.h"
#include <limits>

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
                    // case 2: editCategory(); break;
                    case 3: showAllCategories(); break;
                    // case 4: deleteCategory(); break;
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
                    // case 3: editProduct(); break;
                    // case 4: deleteProduct(); break;
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
                    // case 1: createEmployee(); break;
                    // case 2: showAllEmployees(); break;
                    // case 3: editEmployee(); break;
                    // case 4: deleteEmployee(); break;
                    default: std::cout << "Invalid choice!\n";
                }
                break;
            case 4:
                // checkIncome();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 0);
}