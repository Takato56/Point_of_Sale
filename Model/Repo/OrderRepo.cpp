//
// Created by ntt12 on 4/9/2026.
//

#include "OrderRepo.h"
#include "../../utils/DataHelper.h"

void OrderRepo::addOrder(const Orders& order) {
    int newId = DataHelper::getNextId(db, "Orders", "OrderId");

    std::string query =
        "INSERT INTO Orders (OrderId, StaffId, CustId) VALUES (" +
        std::to_string(newId) + ", " +
        std::to_string(order.getStaffId()) + ", " +
        std::to_string(order.getCustId()) + ");";

    std::cout << "[SQL LOG]: " << query << std::endl;
    db.execute(query);
    db.clearStmt();
}

std::vector<Orders> OrderRepo::getAll() {
    std::vector<Orders> list;
    db.execute("SELECT OrderId, StaffId, CustId FROM Orders;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER orderId, staffId, custId;

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Orders o;
        SQLGetData(stmt, 1, SQL_C_SLONG, &orderId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &staffId, 0, NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &custId, 0, NULL);

        o.setOrderId((int)orderId);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);

        list.push_back(o);
    }

    db.clearStmt();
    return list;
}

Orders OrderRepo::getByID(int id) {
    Orders o;
    std::string query =
        "SELECT OrderId, StaffId, CustId FROM Orders WHERE OrderId = " + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER orderId, staffId, custId;

        SQLGetData(stmt, 1, SQL_C_SLONG, &orderId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &staffId, 0, NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &custId, 0, NULL);

        o.setOrderId((int)orderId);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);
    }

    db.clearStmt();
    return o;
}

void OrderRepo::update(const Orders& order) {
    std::string query =
        "UPDATE Orders SET StaffId = " + std::to_string(order.getStaffId()) +
        ", CustId = " + std::to_string(order.getCustId()) +
        " WHERE OrderId = " + std::to_string(order.getOrderId()) + ";";

    db.execute(query);
    db.clearStmt();
}

void OrderRepo::remove(int id) {
    std::string query = "DELETE FROM Orders WHERE OrderId = " + std::to_string(id) + ";";
    db.execute(query);
    db.clearStmt();
}