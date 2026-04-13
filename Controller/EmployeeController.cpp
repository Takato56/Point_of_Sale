#include "EmployeeController.h"
#include "../model/repository/ProductRepo.h"

void EmployeeController::loadData(const std::vector<Categories>& c, const std::vector<Product>& p) {
    listCt = c;
    listPd = p;
}

void EmployeeController::setCurrentStaffId(int StaffId) {
    currentStaffId = StaffId;
}

bool EmployeeController::isOrderCardValid(int cardId) const {
    return cardId >= 1 && cardId <= 20;
}

int EmployeeController::findEmptyOrderCard() const {
    for (int i = 0; i < 20; ++i) {
        if (!orderCardUsed[i]) return i + 1;
    }
    return -1;
}

void EmployeeController::freeOrderCard(int cardId) {
    if (!isOrderCardValid(cardId)) return;
    orderCardUsed[cardId - 1] = false;
    orderCardId[cardId - 1] = -1;
}

Orders EmployeeController::getOrderByCardId(int cardId) {
    std::vector<Orders> orders = odr.getByOrderCardID(cardId);
    if (orders.empty()) return Orders();
    return orders.front();
}

double EmployeeController::calcSizePrice(double basePrice, const std::string& sizeLabel) const {
    if (sizeLabel == "S") return basePrice * 0.8;
    if (sizeLabel == "M") return basePrice * 1.0;
    if (sizeLabel == "L") return basePrice * 1.2;
    return basePrice;
}

int EmployeeController::checkCustPhone() {
    std::string custPhone = empView.promptCustPhone();

    Customer existing = cr.getByPhone(custPhone);
    if (existing.getCustId() != 0) {
        return existing.getCustId();
    }

    empView.showMessage("Customer not found. Creating new customer...");

    Customer c;
    c.setCustPhone(custPhone);
    c.setCustName(empView.promptCustName());
    c.setPoint(0);

    cr.addCustomer(c);

    Customer created = cr.getByPhone(custPhone);
    return created.getCustId();
}

void EmployeeController::createOrder() {
    int cardId = findEmptyOrderCard();
    if (cardId == -1) {
        empView.showMessage("No empty order card available!");
        return;
    }

    empView.showMessage("Auto selected OrderCardID: " + std::to_string(cardId));

    int newOrderId = DataHelper::getNextId(db, "Orders", "OrderId");
    int selectedCateId = menuView.showAndSelectCategories(listCt);
    menuView.displayProductsByCategory(selectedCateId, listPd);

    int prodId = empView.promptProductId();
    if (prodId == 0) {
        empView.showMessage("Order Cancelled!");
        return;
    }

    Product selectedProduct = ProductRepo(db).getByID(prodId);
    if (selectedProduct.getProdId() == 0) {
        empView.showMessage("Product not found!");
        return;
    }

    int sizeChoice = empView.promptSizeChoice();

    std::string sizeLabel;
    switch (sizeChoice) {
        case 1: sizeLabel = "S"; break;
        case 2: sizeLabel = "M"; break;
        case 3: sizeLabel = "L"; break;
        default:
            empView.showMessage("Invalid size!");
            return;
    }

    int quantity = empView.promptQuantity();

    Orders o;
    o.setOrderId(newOrderId);
    o.setStaffId(currentStaffId);
    o.setCustId(checkCustPhone());
    o.setOrderCardId(cardId);
    odr.addOrder(o);

    OrderItems item;
    item.setOrderId(newOrderId);
    item.setProdId(prodId);
    item.setSizeLabel(sizeLabel);
    item.setQuantity(quantity);
    item.setUnitPrice(calcSizePrice(selectedProduct.getProdPrice(), sizeLabel));
    item.setNote("");
    oir.addOrderItem(item);

    orderCardUsed[cardId - 1] = true;
    orderCardId[cardId - 1] = newOrderId;

    empView.showMessage("Order created successfully. OrderID: " + std::to_string(newOrderId)
                        + " | OrderCardID: " + std::to_string(cardId));
}

void EmployeeController::createPayment() {
    empView.showOccupiedOrderCards(orderCardUsed, orderCardId);

    int cardId = empView.promptOrderCardToPay();

    if (!isOrderCardValid(cardId) || !orderCardUsed[cardId - 1]) {
        empView.showMessage("Order card is empty or invalid!");
        return;
    }

    int orderId = orderCardId[cardId - 1];
    Orders order = odr.getByID(orderId);
    if (order.getOrderId() == 0) {
        empView.showMessage("Order not found for this card!");
        return;
    }

    std::vector<OrderItems> items = oir.getByOrderID(order.getOrderId());
    if (items.empty()) {
        empView.showMessage("Order has no items!");
        return;
    }

    double totalAmount = 0.0;
    for (const auto& item : items) {
        totalAmount += item.getQuantity() * item.getUnitPrice();
    }

    empView.showOrderDetail(order, cardId, items, totalAmount);

    std::string method = empView.promptPaymentMethod();
    if (method.empty()) {
        empView.showMessage("Invalid payment method!");
        return;
    }

    Payments payment;
    payment.setOrderId(order.getOrderId());
    payment.setMethod(method);
    payment.setAmount(totalAmount);
    payRepo.addPayment(payment);

    freeOrderCard(cardId);
    empView.showMessage("Payment completed. OrderCard " + std::to_string(cardId) + " is now free.");
}

void EmployeeController::takeOrderCard() {
    empView.showOccupiedOrderCards(orderCardUsed, orderCardId);
}

void EmployeeController::checkCustPoint() {
    std::string phone = empView.promptCustPhone();

    Customer c = cr.getByPhone(phone);
    if (c.getCustId() == 0) {
        empView.showMessage("Customer not found.");
        return;
    }

    empView.showCustomerInfo(c);
}

void EmployeeController::run() {
    int choice;
    do {
        empView.showStaffMenu();
        choice = empView.getMenuChoice();

        switch (choice) {
            case 1:
                loadData(CategoriesRepo(db).getAll(), ProductRepo(db).getAll());
                createOrder();
                break;
            case 2: createPayment(); break;
            case 3: takeOrderCard(); break;
            case 4: checkCustPoint(); break;
            case 0: break;
            default: empView.showMessage("Invalid choice!"); break;
        }
    } while (choice != 0);
}