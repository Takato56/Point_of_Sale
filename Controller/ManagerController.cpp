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
        std::cout << "\n===== MANAGER UI =====\n";
        std::cout << "1. Create Category\n";
        std::cout << "2. Show All Categories\n";
        std::cout << "3. Create Product\n";
        std::cout << "4. Show All Products\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                createCategory();
                break;
            case 2:
                showAllCategories();
                break;
            case 3:
                createProduct();
                break;
            case 4:
                showAllProducts();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 0);
}