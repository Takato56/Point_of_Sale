//
// Created by ntt12 on 4/8/2026.
//
#include "MenuController.h"
#include "EmployeeController.h"
#include "../utils/DataHelper.h"

void EmployeeController::loadData(const std::vector<Categories>& c, const std::vector<Product>& p) {
    listCt = c;
    listPd = p;
}

void EmployeeController::createOrder() {
    std::string CustPhone;
    int newOrderId = DataHelper::getNextId(db, "Orders", "OrderId");
    int selectedId = mc.showAndSelectCategories(listCt);
    mc.displayProductsByCategory(selectedId, listPd);

    int prodId;
    std::cout<<"\nEnter ProdId to add to Order(0 to cancel): "; std::cin>>prodId;
    if (prodId == 0) {
        std::cout<<"Order Cancelled!";
        return;
    }
    std::cout<<"Added Product " << prodId << " to order!" << std::endl;

    Orders o;
    o.setOrderId(newOrderId);
    int StaffId = 1, CustId = 1;

    o.setStaffId(StaffId);
    o.setCustId(CustId);

    odr.addOrder(o);
}
void EmployeeController::createPayment(){}
void EmployeeController::takeOrderCard(){}
void EmployeeController::checkCustPoint(){}