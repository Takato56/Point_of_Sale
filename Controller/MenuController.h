//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_MENUCONTROLLER_H
#define POINT_OF_SALE_MENUCONTROLLER_H

#include <vector>

#include "../Model/entity/Categories.h"
#include "../model/Repo/ProductRepo.h"
#include "../model/Repo/CategoriesRepo.h"
#include "../model/DatabaseSRC/DBContext/DBContext.h"
#include "EmployeeController.h"
class MenuController {
private:
    ProductRepo pr;
    CategoriesRepo cr;
    EmployeeController ec;
public:
    MenuController(DBContext& db) : pr(db), cr(db), ec(db) {}
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
                case 1: ec.createProduct(); break;
                // case 1: createCategories(); break;
                case 2: getAllProduct(); break;
                //case 3: updateProduct(); break;
                //case 4: deleteProduct(); break;
            }

        } while (choice != 0);
    }           // entry point (like main)
    void createCategories() {
        int CateId;
        int DisplayOrder;
        std::string CateName;
        std::cout << "ID: ";  std::cin >> CateId;
        std::cout << "Name: ";
        std::cin.ignore();
        std::getline(std::cin, CateName);
        std::cout << "Display Order: ";  std::cin >> DisplayOrder;

        Categories ct(CateName, CateId, DisplayOrder);
        cr.addCategories(ct);

        std::cout << "Added!\n";
    }

    void getAllProduct() {
        std::vector<Product> products = pr.getAll();
        for (Product p : products) {
            std::cout<< p.toString()<< std::endl;
        }
    }

    void getAllCategories() {
        std::vector<Categories> ct = cr.getAll();
        for (Categories c : ct) {
            std::cout<< c.toString()<< std::endl;
        }
    }
    //void updateProduct();
    //void deleteProduct();
    //void chooseSize(){
    // std::string sizeChoice;
    //  cout << "Size S, M, L: "; getline(cin, sizeChoice);
    //}
};


#endif //POINT_OF_SALE_MENUCONTROLLER_H