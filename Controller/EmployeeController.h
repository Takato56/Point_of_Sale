#ifndef POINT_OF_SALE_EMPLOYEECONTROLLER_H
#define POINT_OF_SALE_EMPLOYEECONTROLLER_H

#include "../model/repository/CategoriesRepo.h"
#include "../model/repository/ProductRepo.h"
#include "../model/repository/CustomerRepo.h"
#include "../model/repository/OrderRepo.h"
#include "../model/repository/OrderItemRepo.h"
#include "../model/repository/PaymentRepo.h"
#include "../utils/DataHelper.h"
#include "../view/EmployeeView.h"
#include "../view/MenuView.h"
#include "../model/repository/ModifierRepo.h"
#include <vector>

#include "../Model/repository/DiscountRepo.h"

class EmployeeController {
private:
    DBContext db;
    std::vector<Categories> listCt;
    std::vector<Product> listPd;
    std::vector<Modifiers> listMd;

    // Views
    EmployeeView empView;
    MenuView menuView;

    // Repos
    OrderRepo odr;
    CustomerRepo cr;
    OrderItemsRepo oir;
    PaymentRepo payRepo;
    DiscountRepo dr;
    ModifierRepo mr;

    int currentStaffId = -1;
    bool orderCardUsed[20];
    int orderCardId[20];

    int findEmptyOrderCard() const;
    void freeOrderCard(int cardId);
    bool isOrderCardValid(int cardId) const;
    Orders getOrderByCardId(int cardId);
    double calcSizePrice(double basePrice, const std::string& sizeLabel) const;

public:
    explicit EmployeeController(DBContext& context)
        : db(context), odr(context), cr(context), oir(context), payRepo(context), dr(context), mr(context) {
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
    void takeOrderCard();
    void checkCustPoint();
    void syncOrderCards();
    void run();
};

#endif //POINT_OF_SALE_EMPLOYEECONTROLLER_H