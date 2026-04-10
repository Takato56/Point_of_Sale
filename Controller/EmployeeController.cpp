#include "EmployeeController.h"
#include "../utils/DataHelper.h"
#include "../Model/Repo/ProductRepo.h"
#include <limits>

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

void EmployeeController::showAvailableOrderCard() const {
    std::cout << "\n===== AVAILABLE ORDER CARDS =====\n";
    bool found = false;
    for (int i = 0; i < 20; ++i) {
        if (!orderCardUsed[i]) {
            std::cout << "OrderCard " << (i + 1) << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No empty order cards available.\n";
    }
}

void EmployeeController::showOccupiedOrderCards() const {
    std::cout << "\n===== OCCUPIED ORDER CARDS =====\n";
    bool found = false;
    for (int i = 0; i < 20; ++i) {
        if (orderCardUsed[i]) {
            std::cout << "OrderCard " << (i + 1)
                      << " | OrderId: " << orderCardId[i] << "\n";
            found = true;
        }
    }
    if (!found) {
        std::cout << "No occupied order cards.\n";
    }
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
    std::string custPhone;
    std::cout << "Enter CustPhone: ";
    std::cin >> custPhone;

    Customer existing = cr.getByPhone(custPhone);
    if (existing.getCustId() != 0) {
        return existing.getCustId();
    }

    std::cout << "Customer not found. Creating new customer...\n";

    Customer c;
    c.setCustPhone(custPhone);

    std::string custName;
    std::cout << "Enter CustName: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, custName);

    c.setCustName(custName);
    c.setPoint(0);

    cr.addCustomer(c);

    Customer created = cr.getByPhone(custPhone);
    return created.getCustId();
}

void EmployeeController::createOrder() {
    int cardId = findEmptyOrderCard();
    if (cardId == -1) {
        std::cout << "No empty order card available!\n";
        return;
    }

    std::cout << "Auto selected OrderCardID: " << cardId << "\n";

    int newOrderId = DataHelper::getNextId(db, "Orders", "OrderId");
    int selectedCateId = mc.showAndSelectCategories(listCt);
    mc.displayProductsByCategory(selectedCateId, listPd);

    int prodId;
    std::cout << "\nEnter ProdId to add to Order(0 to cancel): ";
    std::cin >> prodId;
    if (prodId == 0) {
        std::cout << "Order Cancelled!\n";
        return;
    }

    Product selectedProduct = ProductRepo(db).getByID(prodId);
    if (selectedProduct.getProdId() == 0) {
        std::cout << "Product not found!\n";
        return;
    }

    std::cout << "\nChoose size:\n";
    std::cout << "1. S\n";
    std::cout << "2. M\n";
    std::cout << "3. L\n";
    std::cout << "Choice: ";

    int sizeChoice;
    std::cin >> sizeChoice;

    std::string sizeLabel;
    switch (sizeChoice) {
        case 1: sizeLabel = "S"; break;
        case 2: sizeLabel = "M"; break;
        case 3: sizeLabel = "L"; break;
        default:
            std::cout << "Invalid size!\n";
            return;
    }

    int quantity;
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

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

    std::cout << "Order created successfully. OrderID: " << newOrderId
              << " | OrderCardID: " << cardId << "\n";
}

void EmployeeController::createPayment() {
    showOccupiedOrderCards();

    int cardId;
    std::cout << "Enter OrderCardID to pay: ";
    std::cin >> cardId;

    if (!isOrderCardValid(cardId) || !orderCardUsed[cardId - 1]) {
        std::cout << "Order card is empty or invalid!\n";
        return;
    }

    // Use the exact OrderId stored in memory when the order was created
    int orderId = orderCardId[cardId - 1];
    Orders order = odr.getByID(orderId);
    if (order.getOrderId() == 0) {
        std::cout << "Order not found for this card!\n";
        return;
    }

    std::vector<OrderItems> items = oir.getByOrderID(order.getOrderId());
    if (items.empty()) {
        std::cout << "Order has no items!\n";
        return;
    }

    double totalAmount = 0.0;
    std::cout << "\n===== ORDER DETAIL =====\n";
    std::cout << "OrderId: " << order.getOrderId()
              << " | OrderCardId: " << cardId << "\n";

    for (const auto& item : items) {
        double lineTotal = item.getQuantity() * item.getUnitPrice();
        totalAmount += lineTotal;

        std::cout << "ProdId: " << item.getProdId()
                  << " | Size: " << item.getSizeLabel()
                  << " | Qty: " << item.getQuantity()
                  << " | UnitPrice: " << item.getUnitPrice()
                  << " | LineTotal: " << lineTotal << "\n";
    }

    std::cout << "TOTAL: " << totalAmount << "\n";

    std::string method;
    std::cout << "Enter payment method (C/Cash, M/Card): ";
    {
        std::string input; std::cin >> input;
        if (input == "C" || input == "Cash") method = "Cash";
        else if (input == "M" || input == "Card") method = "Card";
        else {
            std::cout << "Invalid payment method!\n";
            return;
        }
    }

    Payments payment;
    payment.setOrderId(order.getOrderId());
    payment.setMethod(method);
    payment.setAmount(totalAmount);
    payRepo.addPayment(payment);

    freeOrderCard(cardId);

    std::cout << "Payment completed. OrderCard " << cardId << " is now free.\n";

    int custId = order.getCustId();
    if (custId > 0) {
        Customer cust = cr.getByID(custId);
        if (cust.getCustId() != 0) {
            int earnedPoint = static_cast<int>(totalAmount / 10000);
            int currentPoint = cust.getPoint();
            cust.setPoint(currentPoint + earnedPoint);
            cr.update(cust);
        }
    }
}

void EmployeeController::takeOrderCard() const {
    showOccupiedOrderCards();
}

void EmployeeController::checkCustPoint() {
    std::string phone;
    std::cout << "Enter CustPhone: ";
    std::cin >> phone;

    Customer c = cr.getByPhone(phone);
    if (c.getCustId() == 0) {
        std::cout << "Customer not found.\n";
        return;
    }

    std::cout << "Customer: " << c.getCustName() << "\n";
    std::cout << "Phone: " << c.getCustPhone() << "\n";
    std::cout << "Point: " << c.getPoint() << "\n";
}

void EmployeeController::run() {
    int choice;
    do {
        std::cout << "\n===== STAFF UI =====\n";
        std::cout << "1. Create Order\n";
        std::cout << "2. Pay Order (Close Table)\n";
        std::cout << "3. Call Order Card\n";
        std::cout << "4. Check Customer Point\n";
        std::cout << "0. Exit\n";
        std::cout << "Choose: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadData(CategoriesRepo(db).getAll(), ProductRepo(db).getAll());
                createOrder();
                break;
            case 2:
                createPayment();
                break;
            case 3:
                takeOrderCard();
                break;
            case 4:
                checkCustPoint();
                break;
            case 0:
                break;
            default:
                std::cout << "Invalid choice!\n";
                break;
        }
    } while (choice != 0);
}