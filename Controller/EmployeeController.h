#ifndef POINT_OF_SALE_EMPLOYEECONTROLLER_H
#define POINT_OF_SALE_EMPLOYEECONTROLLER_H

#include "../Model/repository/CategoriesRepo.h"
#include "../Model/repository/ProductRepo.h"
#include "../Model/repository/CustomerRepo.h"
#include "../Model/repository/OrderRepo.h"
#include "../Model/repository/OrderItemRepo.h"
#include "../Model/repository/PaymentRepo.h"
#include "../Model/repository/ModifierRepo.h"
#include "../Model/repository/DiscountRepo.h"
#include "../utils/DataHelper.h"
#include "../View/EmployeeView.h"
#include "../View/MenuView.h"
#include <vector>
#include <array>

class EmployeeController {
protected:
    DBContext& db;
    std::vector<Categories> listCt;
    std::vector<Product> listPd;

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
    CategoriesRepo cateRepo;
    ProductRepo prodRepo;

    int currentStaffId = -1;
    std::array<bool, 20> orderCardUsed{};
    std::array<int, 20> orderCardId{};

    int findEmptyOrderCard() const;
    void freeOrderCard(int cardId);
    bool isOrderCardValid(int cardId) const;
    Orders getOrderByCardId(int cardId);
    double calcSizePrice(double basePrice, const std::string& sizeLabel) const;

    DBContext& getDB() { return db; }

public:
    explicit EmployeeController(DBContext& context)
        : db(context), odr(context), cr(context), oir(context),
          payRepo(context), dr(context), mr(context),
          cateRepo(context), prodRepo(context)
    {
        orderCardUsed.fill(false);
        orderCardId.fill(-1);
    }

    virtual ~EmployeeController() = default;

    int checkCustPhone();
    void setCurrentStaffId(int staffId);
    void loadData(const std::vector<Categories>& c, const std::vector<Product>& p);
    void showProductByCateId();
    void createOrder();
    void createPayment();
    void takeOrderCard();
    void checkCustPoint();
    void syncOrderCards();
    virtual void run();
};

#endif //POINT_OF_SALE_EMPLOYEECONTROLLER_H