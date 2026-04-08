//
// Created by ntt12 on 4/8/2026.
//

#include "EmployeeController.h"

void EmployeeController::createProduct() {
    std::vector<Categories> listCate = cr.getAll();
    if (listCate.empty()) {
        std::cout << "No categories found!\n";
        return;
    }
    std::cout << "\n==========CATEGORIES==========\n";
    for (size_t i = 0; i < listCate.size(); i++) {
        std::cout << i + 1 <<". "<< listCate[i].getCateName()
                                 << " (ID: " << listCate[i].getCateId() << ")\n";
    }
    std::cout << "0. Exit";
    int CateChoice;
    std::cout << "\nChoice: ";  std::cin >> CateChoice;
    if (CateChoice == 0 || CateChoice > (int)listCate.size()) {
        std::cout << "Invalid choice!\n";
        return;
    }
    int selectedCateId = listCate[CateChoice - 1].getCateId();
    int prodId;
    int prodPrice;
    std::string prodName;
    std::cout << "Product ID: ";  std::cin >> prodId;
    std::cout << "Product Name: ";
    std::cin.ignore();
    std::getline(std::cin, prodName);
    std::cout << "Product price: ";  std::cin >> prodPrice;

    Product p;
    p.setProdId(prodId);
    p.setProdName(prodName);
    p.setCateId(selectedCateId);
    p.setProdPrice(prodPrice);

    pr.addProduct(p);
}