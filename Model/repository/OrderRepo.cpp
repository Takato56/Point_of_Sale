#include "OrderRepo.h"
#include "../../utils/DataHelper.h"
#include <iostream>

void OrderRepo::addOrder(const Orders& order) {
    std::string query =
        "INSERT INTO Orders (OrderId, StaffId, CustId, OrderCardId) VALUES ("
        + std::to_string(order.getOrderId()) + ", "
        + std::to_string(order.getStaffId()) + ", "
        + std::to_string(order.getCustId()) + ", "
        + std::to_string(order.getOrderCardId()) + ");";

    std::cout << "[SQL LOG]: " << query << std::endl;
    db.execute(query);
    db.clearStmt();
}

std::vector<Orders> OrderRepo::getAll() {
    std::vector<Orders> list;
    db.execute("SELECT OrderId, StaffId, CustId, OrderCardId FROM Orders;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER orderId, staffId, custId, orderCardId;

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Orders o;
        SQLGetData(stmt, 1, SQL_C_SLONG, &orderId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &staffId, 0, NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &custId, 0, NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &orderCardId, 0, NULL);

        o.setOrderId((int)orderId);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);
        o.setOrderCardId((int)orderCardId);

        list.push_back(o);
    }

    db.clearStmt();
    return list;
}

Orders OrderRepo::getByID(int id) {
    Orders o;
    std::string query =
        "SELECT OrderId, StaffId, CustId, OrderCardId FROM Orders WHERE OrderId = "
        + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER orderId, staffId, custId, orderCardId;
        SQLGetData(stmt, 1, SQL_C_SLONG, &orderId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &staffId, 0, NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &custId, 0, NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &orderCardId, 0, NULL);

        o.setOrderId((int)orderId);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);
        o.setOrderCardId((int)orderCardId);
    }

    db.clearStmt();
    return o;
}

std::vector<Orders> OrderRepo::getByOrderCardID(int orderCardId) {
    std::vector<Orders> list;
    std::string query =
        "SELECT OrderId, StaffId, CustId, OrderCardId FROM Orders WHERE OrderCardId = "
        + std::to_string(orderCardId) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER orderId, staffId, custId, cardId;
    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Orders o;
        SQLGetData(stmt, 1, SQL_C_SLONG, &orderId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &staffId, 0, NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &custId, 0, NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &cardId, 0, NULL);

        o.setOrderId((int)orderId);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);
        o.setOrderCardId((int)cardId);

        list.push_back(o);
    }

    db.clearStmt();
    return list;
}

void OrderRepo::update(const Orders& order) {
    std::string query =
        "UPDATE Orders SET StaffId = " + std::to_string(order.getStaffId()) +
        ", CustId = " + std::to_string(order.getCustId()) +
        ", OrderCardId = " + std::to_string(order.getOrderCardId()) +
        " WHERE OrderId = " + std::to_string(order.getOrderId()) + ";";

    db.execute(query);
    db.clearStmt();
}

void OrderRepo::remove(int id) {
    std::string query = "DELETE FROM Orders WHERE OrderId = " + std::to_string(id) + ";";
    db.execute(query);
    db.clearStmt();
}