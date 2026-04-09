#include "PaymentRepo.h"
#include "../../utils/DataHelper.h"
#include <iostream>

void PaymentRepo::addPayment(const Payments& payment) {
    int newId = DataHelper::getNextId(db, "Payments", "PayId");

    std::string query =
        "INSERT INTO Payments (PayId, OrderId, Method, Amount) VALUES ("
        + std::to_string(newId) + ", "
        + std::to_string(payment.getOrderId()) + ", '"
        + payment.getMethod() + "', "
        + std::to_string(payment.getAmount()) + ");";

    std::cout << "[SQL LOG]: " << query << std::endl;
    db.execute(query);
    db.clearStmt();
}

std::vector<Payments> PaymentRepo::getAll() {
    std::vector<Payments> list;
    db.execute("SELECT PayId, OrderId, Method, Amount FROM Payments;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER payId, orderId;
    SQLCHAR method[50];
    SQLDOUBLE amount;

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Payments p;
        SQLGetData(stmt, 1, SQL_C_SLONG, &payId, sizeof(payId), NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &orderId, sizeof(orderId), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, method, sizeof(method), NULL);
        SQLGetData(stmt, 4, SQL_C_DOUBLE, &amount, sizeof(amount), NULL);

        p.setPayId((int)payId);
        p.setOrderId((int)orderId);
        p.setMethod((char*)method);
        p.setAmount((double)amount);

        list.push_back(p);
    }

    db.clearStmt();
    return list;
}

Payments PaymentRepo::getByID(int id) {
    Payments p;
    std::string query =
        "SELECT PayId, OrderId, Method, Amount FROM Payments WHERE PayId = "
        + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER payId, orderId;
        SQLCHAR method[50];
        SQLDOUBLE amount;

        SQLGetData(stmt, 1, SQL_C_SLONG, &payId, sizeof(payId), NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &orderId, sizeof(orderId), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, method, sizeof(method), NULL);
        SQLGetData(stmt, 4, SQL_C_DOUBLE, &amount, sizeof(amount), NULL);

        p.setPayId((int)payId);
        p.setOrderId((int)orderId);
        p.setMethod((char*)method);
        p.setAmount((double)amount);
    }

    db.clearStmt();
    return p;
}

std::vector<Payments> PaymentRepo::getByOrderID(int orderId) {
    std::vector<Payments> list;
    std::string query =
        "SELECT PayId, OrderId, Method, Amount FROM Payments WHERE OrderId = "
        + std::to_string(orderId) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER payId;
    SQLCHAR method[50];
    SQLDOUBLE amount;

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Payments p;
        SQLGetData(stmt, 1, SQL_C_SLONG, &payId, sizeof(payId), NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &orderId, sizeof(orderId), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, method, sizeof(method), NULL);
        SQLGetData(stmt, 4, SQL_C_DOUBLE, &amount, sizeof(amount), NULL);

        p.setPayId((int)payId);
        p.setOrderId((int)orderId);
        p.setMethod((char*)method);
        p.setAmount((double)amount);

        list.push_back(p);
    }

    db.clearStmt();
    return list;
}

void PaymentRepo::update(const Payments& payment) {
    std::string query =
        "UPDATE Payments SET OrderId = " + std::to_string(payment.getOrderId()) +
        ", Method = '" + payment.getMethod() +
        "', Amount = " + std::to_string(payment.getAmount()) +
        " WHERE PayId = " + std::to_string(payment.getPayId()) + ";";

    db.execute(query);
    db.clearStmt();
}

void PaymentRepo::remove(int id) {
    std::string query = "DELETE FROM Payments WHERE PayId = " + std::to_string(id) + ";";
    db.execute(query);
    db.clearStmt();
}