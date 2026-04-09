#include "OrderItemRepo.h"
#include "../../utils/DataHelper.h"
#include <iostream>

void OrderItemsRepo::addOrderItem(const OrderItems& item) {
    int newId = DataHelper::getNextId(db, "OrderItems", "OIId");

    std::string query =
        "INSERT INTO OrderItems (OIId, OrderId, ProdId, SizeLabel, Quantity, UnitPrice, Note) VALUES ("
        + std::to_string(newId) + ", "
        + std::to_string(item.getOrderId()) + ", "
        + std::to_string(item.getProdId()) + ", '"
        + item.getSizeLabel() + "', "
        + std::to_string(item.getQuantity()) + ", "
        + std::to_string(item.getUnitPrice()) + ", '"
        + item.getNote() + "');";

    std::cout << "[SQL LOG]: " << query << std::endl;
    db.execute(query);
    db.clearStmt();
}

std::vector<OrderItems> OrderItemsRepo::getAll() {
    std::vector<OrderItems> list;
    db.execute("SELECT OIId, OrderId, ProdId, SizeLabel, Quantity, UnitPrice, Note FROM OrderItems;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER oiId, orderId, prodId, quantity;
    SQLDOUBLE unitPrice;
    SQLCHAR sizeLabel[50], note[255];

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        OrderItems item;

        SQLGetData(stmt, 1, SQL_C_SLONG, &oiId, sizeof(oiId), NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &orderId, sizeof(orderId), NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &prodId, sizeof(prodId), NULL);
        SQLGetData(stmt, 4, SQL_C_CHAR, sizeLabel, sizeof(sizeLabel), NULL);
        SQLGetData(stmt, 5, SQL_C_SLONG, &quantity, sizeof(quantity), NULL);
        SQLGetData(stmt, 6, SQL_C_DOUBLE, &unitPrice, sizeof(unitPrice), NULL);
        SQLGetData(stmt, 7, SQL_C_CHAR, note, sizeof(note), NULL);

        item.setOIId((int)oiId);
        item.setOrderId((int)orderId);
        item.setProdId((int)prodId);
        item.setSizeLabel((char*)sizeLabel);
        item.setQuantity((int)quantity);
        item.setUnitPrice((double)unitPrice);
        item.setNote((char*)note);

        list.push_back(item);
    }

    db.clearStmt();
    return list;
}

std::vector<OrderItems> OrderItemsRepo::getByOrderID(int orderId) {
    std::vector<OrderItems> list;
    std::string query =
        "SELECT OIId, OrderId, ProdId, SizeLabel, Quantity, UnitPrice, Note "
        "FROM OrderItems WHERE OrderId = " + std::to_string(orderId) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER oiId, prodId, quantity;
    SQLDOUBLE unitPrice;
    SQLCHAR sizeLabel[50], note[255];

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        OrderItems item;

        SQLGetData(stmt, 1, SQL_C_SLONG, &oiId, sizeof(oiId), NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &orderId, sizeof(orderId), NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &prodId, sizeof(prodId), NULL);
        SQLGetData(stmt, 4, SQL_C_CHAR, sizeLabel, sizeof(sizeLabel), NULL);
        SQLGetData(stmt, 5, SQL_C_SLONG, &quantity, sizeof(quantity), NULL);
        SQLGetData(stmt, 6, SQL_C_DOUBLE, &unitPrice, sizeof(unitPrice), NULL);
        SQLGetData(stmt, 7, SQL_C_CHAR, note, sizeof(note), NULL);

        item.setOIId((int)oiId);
        item.setOrderId((int)orderId);
        item.setProdId((int)prodId);
        item.setSizeLabel((char*)sizeLabel);
        item.setQuantity((int)quantity);
        item.setUnitPrice((double)unitPrice);
        item.setNote((char*)note);

        list.push_back(item);
    }

    db.clearStmt();
    return list;
}

OrderItems OrderItemsRepo::getByID(int id) {
    OrderItems item;
    std::string query =
        "SELECT OIId, OrderId, ProdId, SizeLabel, Quantity, UnitPrice, Note "
        "FROM OrderItems WHERE OIId = " + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER oiId, orderId, prodId, quantity;
        SQLDOUBLE unitPrice;
        SQLCHAR sizeLabel[50], note[255];

        SQLGetData(stmt, 1, SQL_C_SLONG, &oiId, sizeof(oiId), NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &orderId, sizeof(orderId), NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &prodId, sizeof(prodId), NULL);
        SQLGetData(stmt, 4, SQL_C_CHAR, sizeLabel, sizeof(sizeLabel), NULL);
        SQLGetData(stmt, 5, SQL_C_SLONG, &quantity, sizeof(quantity), NULL);
        SQLGetData(stmt, 6, SQL_C_DOUBLE, &unitPrice, sizeof(unitPrice), NULL);
        SQLGetData(stmt, 7, SQL_C_CHAR, note, sizeof(note), NULL);

        item.setOIId((int)oiId);
        item.setOrderId((int)orderId);
        item.setProdId((int)prodId);
        item.setSizeLabel((char*)sizeLabel);
        item.setQuantity((int)quantity);
        item.setUnitPrice((double)unitPrice);
        item.setNote((char*)note);
    }

    db.clearStmt();
    return item;
}

void OrderItemsRepo::update(const OrderItems& item) {
    std::string query =
        "UPDATE OrderItems SET "
        "OrderId = " + std::to_string(item.getOrderId()) + ", "
        "ProdId = " + std::to_string(item.getProdId()) + ", "
        "SizeLabel = '" + item.getSizeLabel() + "', "
        "Quantity = " + std::to_string(item.getQuantity()) + ", "
        "UnitPrice = " + std::to_string(item.getUnitPrice()) + ", "
        "Note = '" + item.getNote() + "' "
        "WHERE OIId = " + std::to_string(item.getOIId()) + ";";

    db.execute(query);
    db.clearStmt();
}

void OrderItemsRepo::remove(int id) {
    std::string query =
        "DELETE FROM OrderItems WHERE OIId = " + std::to_string(id) + ";";

    db.execute(query);
    db.clearStmt();
}