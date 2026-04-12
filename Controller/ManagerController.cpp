#include "ManagerController.h"
#include "../utils/DataHelper.h"

void ManagerController::createCategory() {
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

void ManagerController::createProduct() {
    std::vector<Categories> listCate = cr.getAll();
    if (listCate.empty()) {
        mgrView.showMessage("No categories found!");
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

void ManagerController::showAllProducts() {
    mgrView.showAllProducts(pr.getAll());
}

void ManagerController::showAllCategories() {
    mgrView.showAllCategories(cr.getAll());
}

void ManagerController::run() {
    int choice;
    do {
        mgrView.showManagerMenu();
        choice = mgrView.getMenuChoice();

        switch (choice) {
            case 1: createCategory(); break;
            case 2: showAllCategories(); break;
            case 3: createProduct(); break;
            case 4: showAllProducts(); break;
            case 0: break;
            default: mgrView.showMessage("Invalid choice!"); break;
        }
    } while (choice != 0);
}