#ifndef POINT_OF_SALE_EMPLOYEECONTROLLER_H
#define POINT_OF_SALE_EMPLOYEECONTROLLER_H

#include "../Model/Repo/CategoriesRepo.h"
#include "../Model/Repo/ProductRepo.h"
#include "../utils/DataHelper.h"
#include <iostream>
#include <vector>
#include "MenuController.h"
#include "../Model/Repo/CustomerRepo.h"
#include "../Model/Repo/OrderRepo.h"
#include "../Model/Repo/OrderItemRepo.h"
#include "../Model/Repo/PaymentRepo.h"

class EmployeeController {
private:
    DBContext db;
    std::vector<Categories> listCt;
    std::vector<Product> listPd;
    MenuController mc;
    OrderRepo odr;
    CustomerRepo cr;
    OrderItemsRepo oir;
    PaymentRepo payRepo;
    int currentStaffId = -1;

    bool orderCardUsed[20];
    int orderCardId[20];

    int findEmptyOrderCard() const;
    void showAvailableOrderCard() const;
    void showOccupiedOrderCards() const;
    void freeOrderCard(int cardId);
    bool isOrderCardValid(int cardId) const;
    Orders getOrderByCardId(int cardId);

    double calcSizePrice(double basePrice, const std::string& sizeLabel) const;

public:
    explicit EmployeeController(DBContext& context)
        : db(context), mc(context), odr(context), cr(context), oir(context), payRepo(context) {
        for (int i = 0; i < 20; ++i) {
            orderCardUsed[i] = false;
            orderCardId[i] = -1;
        }
    }

    int checkCustPhone();
    void setCurrentStaffId(int StaffId);
    void loadData(const std::vector<Categories>& c, const std::vector<Product>& p);
    void createOrder();
    void createPayment();
    void takeOrderCard() const;
    void checkCustPoint();
    void run();
};

#endif //POINT_OF_SALE_EMPLOYEECONTROLLER_H