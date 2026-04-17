#include "EmployeeController.h"
#include "../Model/repository/ProductRepo.h"

void EmployeeController::loadData(const std::vector<Categories>& c, const std::vector<Product>& p) {
    listCt = c;
    listPd = p;
}

void EmployeeController::showProductByCateId() {
    std::vector<Categories> listCate = cateRepo.getAll();
    std::vector<Product> listProd = prodRepo.getAll();
    menuView.showProductByCateId(listCate, listProd);
}

void EmployeeController::setCurrentStaffId(int staffId) {
    currentStaffId = staffId;
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
    int orderId = orderCardId[cardId - 1];

    if (orderId <= 0) {
        orderCardUsed[cardId - 1] = false;
        orderCardId[cardId - 1] = -1;
        return;
    }

    std::string sql = "UPDATE Orders SET Status = 1 WHERE OrderId = " + std::to_string(orderId);

    if (db.execute(sql)) {
        orderCardUsed[cardId - 1] = false;
        orderCardId[cardId - 1] = -1;

        empView.showMessage("OrderCard " + std::to_string(cardId) + " is now free.");
    } else {
        empView.showMessage("Error: Cannot update order status in Database!");
    }
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
    int customerId = checkCustPhone();

    bool isOrdering = true;
    std::vector<OrderItems> tempItems;

    while (isOrdering) {
        showProductByCateId();

        empView.showMessage("\n--- Enter Product ID to add, or 0 to STOP choosing items ---");
        int prodId = empView.promptProductId();
        if (prodId == 0) {
            isOrdering = false;
            break;
        }

        Product selectedProduct = ProductRepo(db).getByID(prodId);
        if (selectedProduct.getProdId() == 0) {
            empView.showMessage("Product not found! Please try again.");
            continue;
        }

        int sizeChoice = empView.promptSizeChoice();
        std::string sizeLabel;
        switch (sizeChoice) {
            case 1: sizeLabel = "S"; break;
            case 2: sizeLabel = "M"; break;
            case 3: sizeLabel = "L"; break;
            default:
                empView.showMessage("Invalid size! Item not added.");
                continue;
        }

        int quantity = empView.promptQuantity();
        if (quantity <= 0) {
            empView.showMessage("Invalid quantity!");
            continue;
        }

        std::string notes;
        empView.showMessage("\n--- Add Modifiers? (1. Yes / 0. No) ---");
        if (empView.getMenuChoice() == 1) {
            std::vector<Modifiers> allModifiers = ModifierRepo(db).getAll();

            while (true) {
                empView.showMessage("\n===== SELECT MODIFIER CATEGORY =====");
                empView.showMessage("1. Ice Options");
                empView.showMessage("2. Sugar Options");
                empView.showMessage("0. Finish");

                int catChoice = empView.getMenuChoice();
                if (catChoice == 0) break;

                std::string targetType = (catChoice == 1) ? "ice" : "sugar";
                std::vector<Modifiers> filteredList;
                for (const auto& m : allModifiers) {
                    if (m.getModType() == targetType) filteredList.push_back(m);
                }

                if (filteredList.empty()) {
                    empView.showMessage("No options available for this category.");
                    continue;
                }

                empView.showMessage("\n--- Select Option (1-" + std::to_string(filteredList.size()) + ") ---");
                for (size_t i = 0; i < filteredList.size(); ++i) {
                    empView.showMessage(std::to_string(i + 1) + ". " + filteredList[i].getModName());
                }
                empView.showMessage("0. Back to categories");

                int itemChoice = empView.getMenuChoice();
                if (itemChoice > 0 && itemChoice <= static_cast<int>(filteredList.size())) {
                    const Modifiers& selected = filteredList[itemChoice - 1];
                    if (!notes.empty()) notes += ", ";
                    notes += selected.getModName();
                    empView.showMessage(">> Added: " + selected.getModName());
                }
            }
        }

        OrderItems item;
        item.setProdId(prodId);
        item.setSizeLabel(sizeLabel);
        item.setQuantity(quantity);
        item.setUnitPrice(calcSizePrice(selectedProduct.getProdPrice(), sizeLabel));
        item.setNote(notes);

        tempItems.push_back(item);
        empView.showMessage("Added " + selectedProduct.getProdName() + " (" + sizeLabel + ") x" + std::to_string(quantity));

        empView.showMessage("\n1. Continue selecting more items");
        empView.showMessage("0. Finish and Place Order");
        if (empView.getMenuChoice() == 0) {
            isOrdering = false;
        }
    }

    if (tempItems.empty()) {
        empView.showMessage("No items selected. Order cancelled!");
        return;
    }

    int newOrderId = DataHelper::getNextId(db, "Orders", "OrderId");

    Orders o;
    o.setOrderId(newOrderId);
    o.setStaffId(currentStaffId);
    o.setCustId(customerId);
    o.setOrderCardId(cardId);
    odr.addOrder(o);

    for (auto& item : tempItems) {
        item.setOrderId(newOrderId);
        oir.addOrderItem(item);
    }

    orderCardUsed[cardId - 1] = true;
    orderCardId[cardId - 1] = newOrderId;

    empView.showMessage("Order created successfully!");
    empView.showMessage("OrderID: " + std::to_string(newOrderId) + " | OrderCard: " + std::to_string(cardId));
}

void EmployeeController::createPayment() {
    empView.showOccupiedOrderCards(orderCardUsed.data(), orderCardId.data());

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

    double discountValue = 0.0;
    std::vector<Discount> allDiscounts = dr.getAll();
    std::vector<Discount> activeDiscounts;

    for (const auto& d : allDiscounts) {
        if (d.getIsActive()) {
            activeDiscounts.push_back(d);
        }
    }

    empView.showActiveDiscounts(activeDiscounts);
    int choice = empView.promptDiscountChoice();

    if (choice != 0) {
        Discount selectedDiscount = dr.getByID(choice);

        if (selectedDiscount.getDiscountId() != 0 && selectedDiscount.getIsActive()) {
            if (selectedDiscount.getType() == "Percentage") {
                discountValue = totalAmount * (selectedDiscount.getValue() / 100.0);
            } else {
                discountValue = selectedDiscount.getValue();
            }
            empView.showMessage("Discount applied successfully!");
        } else {
            empView.showMessage("Invalid discount selection!");
        }
    }

    double finalAmount = std::max(0.0, totalAmount - discountValue);

    empView.showOrderDetail(order, cardId, items, finalAmount);

    std::string method = empView.promptPaymentMethod();
    if (method.empty()) return;

    Payments payment;
    payment.setOrderId(order.getOrderId());
    payment.setMethod(method);
    payment.setAmount(finalAmount);
    payRepo.addPayment(payment);

    if (order.getCustId() > 0) {
        Customer customer = cr.getByID(order.getCustId());

        if (customer.getCustId() != 0) {
            int pointsToAdd = static_cast<int>(finalAmount / 1000.0);
            if (pointsToAdd > 0) {
                int newPoints = customer.getPoint() + pointsToAdd;
                customer.setPoint(newPoints);
                cr.update(customer);
                empView.showMessage("Added +" + std::to_string(pointsToAdd) +
                                    " points. Total: " + std::to_string(newPoints));
            }
        }
    }

    freeOrderCard(cardId);
    empView.showMessage("Payment completed. OrderCard " + std::to_string(cardId) + " is now free.");
}

void EmployeeController::takeOrderCard() {
    empView.showOccupiedOrderCards(orderCardUsed.data(), orderCardId.data());

    empView.showMessage("Enter Order Card ID to view details (or 0 to go back): ");
    int cardId;
    std::cin >> cardId;

    if (cardId > 0 && isOrderCardValid(cardId)) {
        if (orderCardUsed[cardId - 1]) {
            int orderId = orderCardId[cardId - 1];
            Orders order = odr.getByID(orderId);
            std::vector<OrderItems> items = oir.getByOrderID(orderId);

            double total = 0;
            for (const auto& item : items) {
                total += item.getQuantity() * item.getUnitPrice();
            }

            empView.showOrderDetail(order, cardId, items, total);
        } else {
            empView.showMessage("This card is currently empty.");
        }
    }
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

void EmployeeController::syncOrderCards() {
    std::vector<Orders> unpaidOrders = odr.getUnpaidOrders();

    for (const auto& order : unpaidOrders) {
        int cId = order.getOrderCardId();
        if (isOrderCardValid(cId)) {
            orderCardUsed[cId - 1] = true;
            orderCardId[cId - 1] = order.getOrderId();
        }
    }
}

void EmployeeController::run() {
    int choice;
    do {
        syncOrderCards();
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