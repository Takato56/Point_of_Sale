//
// Created by ntt12 on 4/9/2026.
//

#include "CustomerRepo.h"
#include "../../utils/DataHelper.h"


void CustomerRepo::addCustomer(const Customer& c) {
    int newId = DataHelper::getNextId(db, "Customers", "CustId");

    std::string query =
        "INSERT INTO Customers (CustId, CustName, CustPhone, Point) VALUES ("
        + std::to_string(newId) + ", '"
        + c.getCustName() + "', '"
        + c.getCustPhone() + "', "
        + std::to_string(c.getPoint()) + ");";

    std::cout << "[SQL LOG]: " << query << std::endl;
    db.execute(query);
    db.clearStmt();
}

std::vector<Customer> CustomerRepo::getAll() {
    std::vector<Customer> list;
    db.execute("SELECT CustId, CustName, CustPhone, Point FROM Customer;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER CustId, Point;
    SQLCHAR CustName[50], CustPhone[50];

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Customer c;
        SQLGetData(stmt, 1, SQL_C_SLONG, &CustId, sizeof(CustId), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, CustName, sizeof(CustName), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, CustPhone, sizeof(CustPhone), NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &Point, sizeof(Point), NULL);

        c.setCustId((int)CustId);
        c.setCustName((char*)CustName);
        c.setCustPhone((char*)CustPhone);
        c.setPoint((int)Point);

        list.push_back(c);
    }
    db.clearStmt();
    return list;
}
Customer CustomerRepo::getByID(const int id) {
    Customer c;
    std::string query = "SELECT CustId, CustName, CustPhone, Point FROM Customers WHERE CustId= " + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();
    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER CustId, Point;
        SQLCHAR CustName[50], CustPhone[50];

        SQLGetData(stmt, 1, SQL_C_SLONG, &CustId, sizeof(CustId), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, CustName, sizeof(CustName), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, CustPhone, sizeof(CustPhone), NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &Point, sizeof(Point), NULL);

        c.setCustId((int)CustId);
        c.setCustName((char*)CustName);
        c.setCustPhone((char*)CustPhone);
        c.setPoint((int)Point);
    }
    db.clearStmt();
    return c;
}

Customer CustomerRepo::getByPhone(const std::string& phone) {
    Customer c;
    std::string query = "SELECT CustId, CustName, CustPhone, Point FROM Customers WHERE CustPhone= '" + phone + "';";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();
    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER CustId, Point;
        SQLCHAR CustName[50], CustPhone[50];

        SQLGetData(stmt, 1, SQL_C_SLONG, &CustId, sizeof(CustId), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, CustName, sizeof(CustName), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, CustPhone, sizeof(CustPhone), NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &Point, sizeof(Point), NULL);

        c.setCustId((int)CustId);
        c.setCustName((char*)CustName);
        c.setCustPhone((char*)CustPhone);
        c.setPoint((int)Point);
    }
    db.clearStmt();
    return c;
}

void CustomerRepo::update(const Customer& c) {
    std::string query =
        "UPDATE Customers SET CustId = '" + std::to_string(c.getCustId()) +
        "', CustName = " + c.getCustName() +
        ", CustPhone = " + c.getCustPhone() +
        ", Point = " + std::to_string(c.getPoint()) + ";";
        " WHERE CustId = " + std::to_string(c.getCustId()) + ";";

    db.execute(query);
    db.clearStmt();
}
void remove(int id);