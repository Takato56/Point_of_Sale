#include "CustomerRepo.h"
#include "../../utils/DataHelper.h"
#include <iostream>

void CustomerRepo::addCustomer(const Customer& c) {
    int newId = DataHelper::getNextId(db, "Customers", "CustId");

    std::string query =
        "INSERT INTO Customers (CustId, CustName, CustPhone, Point) VALUES ("
        + std::to_string(newId) + ", '"
        + c.getCustName() + "', '"
        + c.getCustPhone() + "', "
        + std::to_string(c.getPoint()) + ");";

    db.execute(query);
    db.clearStmt();
}

std::vector<Customer> CustomerRepo::getAll() {
    std::vector<Customer> list;
    db.execute("SELECT CustId, CustName, CustPhone, Point FROM Customers;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER custId, point;
    SQLCHAR custName[50], custPhone[50];

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Customer c;
        SQLGetData(stmt, 1, SQL_C_SLONG, &custId, sizeof(custId), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, custName, sizeof(custName), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, custPhone, sizeof(custPhone), NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &point, sizeof(point), NULL);

        c.setCustId(static_cast<int>(custId));
        c.setCustName(reinterpret_cast<char*>(custName));
        c.setCustPhone(reinterpret_cast<char*>(custPhone));
        c.setPoint(static_cast<int>(point));

        list.push_back(c);
    }
    db.clearStmt();
    return list;
}

Customer CustomerRepo::getByID(int id) {
    Customer c;
    std::string query = "SELECT CustId, CustName, CustPhone, Point FROM Customers WHERE CustId=" + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();
    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER custId, point;
        SQLCHAR custName[50], custPhone[50];

        SQLGetData(stmt, 1, SQL_C_SLONG, &custId, sizeof(custId), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, custName, sizeof(custName), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, custPhone, sizeof(custPhone), NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &point, sizeof(point), NULL);

        c.setCustId(static_cast<int>(custId));
        c.setCustName(reinterpret_cast<char*>(custName));
        c.setCustPhone(reinterpret_cast<char*>(custPhone));
        c.setPoint(static_cast<int>(point));
    }
    db.clearStmt();
    return c;
}

Customer CustomerRepo::getByPhone(const std::string& phone) {
    Customer c;
    std::string query = "SELECT CustId, CustName, CustPhone, Point FROM Customers WHERE CustPhone='" + phone + "';";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();
    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER custId, point;
        SQLCHAR custName[50], custPhone[50];

        SQLGetData(stmt, 1, SQL_C_SLONG, &custId, sizeof(custId), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, custName, sizeof(custName), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, custPhone, sizeof(custPhone), NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &point, sizeof(point), NULL);

        c.setCustId(static_cast<int>(custId));
        c.setCustName(reinterpret_cast<char*>(custName));
        c.setCustPhone(reinterpret_cast<char*>(custPhone));
        c.setPoint(static_cast<int>(point));
    }
    db.clearStmt();
    return c;
}

void CustomerRepo::update(const Customer& c) {
    std::string query =
        "UPDATE Customers SET "
        "CustName='" + c.getCustName() + "', "
        "CustPhone='" + c.getCustPhone() + "', "
        "Point=" + std::to_string(c.getPoint()) +
        " WHERE CustId=" + std::to_string(c.getCustId()) + ";";

    db.execute(query);
    db.clearStmt();
}

void CustomerRepo::remove(int id) {
    std::string query = "DELETE FROM Customers WHERE CustId=" + std::to_string(id) + ";";
    db.execute(query);
    db.clearStmt();
}