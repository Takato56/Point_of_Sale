//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_MENUCONTROLLER_H
#define POINT_OF_SALE_MENUCONTROLLER_H

#include <vector>
#include "ProductRepo.h"
class MenuController {
private:
    ProductRepo pr;
public:
    MenuController(DBContext& db) : pr(db) {}
    void run() {
        int choice;

        do {
            std::cout << "\n===== PRODUCT MENU =====\n";
            std::cout << "1. Add Product\n";
            std::cout << "2. View All\n";
            std::cout << "3. Update\n";
            std::cout << "4. Delete\n";
            std::cout << "0. Exit\n";
            std::cout << "Choose: ";
            std::cin >> choice;

            switch (choice) {
                case 1: createProduct(); break;
                case 2: getAllProduct(); break;
                    // case 3: updateStudent(); break;
                    // case 4: deleteStudent(); break;
            }

        } while (choice != 0);
    }           // entry point (like main)
    void createProduct() {
        std::string prodId, prodName;
        int prodPrice;

        std::cout << "ID: ";
        std::cin >> prodId;

        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, prodName);

        std::cout << "Price: ";
        std::cin >> prodPrice;

        Product s(prodId, prodName, prodPrice);
        pr.addProduct(s);

        std::cout << "Added!\n";
    }
    void getAllProduct() {
        std::vector<Product> products = pr.getAll();
        for (Product p : products) {
            std::cout<< p.toString()<< std::endl;
        }
    }
    // void updateStudent();
    // void deleteStudent();
};


#endif //POINT_OF_SALE_MENUCONTROLLER_H