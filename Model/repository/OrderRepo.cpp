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
    SQLCHAR createdAt[50];

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Orders o;
        SQLGetData(stmt, 1, SQL_C_SLONG, &orderId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &staffId, 0, NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &custId, 0, NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &orderCardId, 0, NULL);
        SQLGetData(stmt, 5, SQL_C_CHAR, createdAt, sizeof(createdAt), NULL);

        o.setOrderId((int)orderId);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);
        o.setOrderCardId((int)orderCardId);
        o.setCreatedAt((char*)createdAt);

        list.push_back(o);
    }

    db.clearStmt();
    return list;
}

Orders OrderRepo::getByID(int id) {
    Orders o;
    std::string query =
        "SELECT OrderId, StaffId, CustId, OrderCardId, CreatedAt FROM Orders WHERE OrderId = "
        + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER orderId, staffId, custId, orderCardId;
        SQLCHAR createdAt[50];
        SQLGetData(stmt, 1, SQL_C_SLONG, &orderId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &staffId, 0, NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &custId, 0, NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &orderCardId, 0, NULL);
        SQLGetData(stmt, 5, SQL_C_CHAR, createdAt, sizeof(createdAt), NULL);

        o.setOrderId((int)orderId);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);
        o.setOrderCardId((int)orderCardId);
        o.setCreatedAt((char*)createdAt);
    }

    db.clearStmt();
    return o;
}

std::vector<Orders> OrderRepo::getByOrderCardID(int orderCardId) {
    std::vector<Orders> list;
    std::string query =
        "SELECT OrderId, StaffId, CustId, OrderCardId, CreatedAt FROM Orders WHERE OrderCardId = "
        + std::to_string(orderCardId) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER orderId, staffId, custId, cardId;
    SQLCHAR createdAt[50];
    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Orders o;
        SQLGetData(stmt, 1, SQL_C_SLONG, &orderId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &staffId, 0, NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &custId, 0, NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &cardId, 0, NULL);
        SQLGetData(stmt, 5, SQL_C_CHAR, createdAt, sizeof(createdAt), NULL);

        o.setOrderId((int)orderId);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);
        o.setOrderCardId((int)cardId);
        o.setCreatedAt((char*)createdAt);

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

std::vector<std::string> OrderRepo::getDistinctDates() {
    std::vector<std::string> dates;
    std::string query =
        "SELECT DISTINCT CONVERT(VARCHAR(10), CreatedAt, 120) AS OrderDate "
        "FROM Orders WHERE CreatedAt IS NOT NULL "
        "ORDER BY OrderDate DESC;";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    SQLCHAR dateBuf[20];
    while (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLGetData(stmt, 1, SQL_C_CHAR, dateBuf, sizeof(dateBuf), NULL);
        dates.emplace_back((char*)dateBuf);
    }

    db.clearStmt();
    return dates;
}

std::vector<Orders> OrderRepo::getByDate(const std::string& date) {
    std::vector<Orders> list;
    std::string query =
        "SELECT OrderId, StaffId, CustId, OrderCardId, CreatedAt "
        "FROM Orders WHERE CONVERT(VARCHAR(10), CreatedAt, 120) = '" + date + "';";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER orderId, staffId, custId, orderCardId;
    SQLCHAR createdAt[20];

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Orders o;
        SQLGetData(stmt, 1, SQL_C_SLONG, &orderId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &staffId, 0, NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &custId, 0, NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &orderCardId, 0, NULL);
        SQLGetData(stmt, 5, SQL_C_CHAR, createdAt, sizeof(createdAt), NULL);

        o.setOrderId((int)orderId);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);
        o.setOrderCardId((int)orderCardId);
        o.setCreatedAt((char*)createdAt);

        list.push_back(o);
    }

    db.clearStmt();
    return list;
}

std::vector<Orders> OrderRepo::getUnpaidOrders() {
    std::vector<Orders> list;
    std::string sql = "SELECT o.OrderId, o.StaffId, o.CustId, o.OrderCardId "
                      "FROM Orders o "
                      "LEFT JOIN Payments p ON o.OrderId = p.OrderId "
                      "WHERE o.Status = 0;";

    db.execute(sql);
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER id, staffId, custId, cardId;
    SQLLEN cbId, cbStaff, cbCust, cbCard;

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Orders o;

        SQLGetData(stmt, 1, SQL_C_LONG, &id, sizeof(id), &cbId);
        SQLGetData(stmt, 2, SQL_C_LONG, &staffId, sizeof(staffId), &cbStaff);
        SQLGetData(stmt, 3, SQL_C_LONG, &custId, sizeof(custId), &cbCust);
        SQLGetData(stmt, 4, SQL_C_LONG, &cardId, sizeof(cardId), &cbCard);

        o.setOrderId((int)id);
        o.setStaffId((int)staffId);
        o.setCustId((int)custId);
        o.setOrderCardId((int)cardId);

        list.push_back(o);
    }
    db.clearStmt();
    return list;
}
