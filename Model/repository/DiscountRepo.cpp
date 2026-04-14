//
// Created by ntt12 on 4/14/2026.
//

#include "DiscountRepo.h"
#include "../../utils/DataHelper.h"

void DiscountRepo::addDiscount(Discount& d) {
    int newId = DataHelper::getNextId(db, "Discount", "DiscountId");
    d.setDiscountId(newId);

    std::string query =
    "INSERT INTO Discount (DiscountId, Code, Value, Type, isActive) VALUES ('" +
        std::to_string(newId) + "', '" +
        d.getCode() + "', '" +
        std::to_string(d.getValue()) + "', '" +
        d.getType() + "', '" +
        std::to_string(d.getIsActive()) + "');";

    db.execute(query);
    db.clearStmt();

}

std::vector<Discount> DiscountRepo::getAll() {
    std::vector<Discount> list;
    db.execute("SELECT DiscountId, Code, Value, Type, isActive FROM Discount;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER idBuffer, isActiveBuffer;
    SQLCHAR Code[50], Type[50];
    SQLDOUBLE ValueBuffer;
    SQLLEN cbId, cbCode, cbValue, cbType, cbIsActive;

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Discount d;

        SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, 0, &cbId);
        SQLGetData(stmt, 2, SQL_C_CHAR, Code, sizeof(Code), &cbCode);
        SQLGetData(stmt, 3, SQL_C_DOUBLE, &ValueBuffer, 0, &cbValue);
        SQLGetData(stmt, 4, SQL_C_CHAR, Type, sizeof(Type), &cbType);
        SQLGetData(stmt, 5, SQL_C_SLONG, &isActiveBuffer, 0, &cbIsActive);

        d.setDiscountId((int)idBuffer);
        d.setCode((char*)Code);
        d.setValue((double)ValueBuffer);
        d.setType((char*)Type);
        d.setIsActive((int)isActiveBuffer);

        list.push_back(d);
    }
    db.clearStmt();
    return list;
}

Discount DiscountRepo::getByID(const int id) {
    Discount d;
    std::string query =
        "SELECT DiscountId, Code, Value, Type, isActive FROM Discount WHERE DiscountId='" + std::to_string(id) + "';";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();
    if  (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER idBuffer;
        SQLCHAR Code[50];
        SQLCHAR Type[50];
        SQLDOUBLE Value;
        SQLLEN cbId, cbCode, cbType, cbIsActive, cbValue;

        SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, 0, &cbId);
        SQLGetData(stmt, 2, SQL_C_CHAR, Code, sizeof(Code), &cbCode);
        SQLGetData(stmt, 3, SQL_C_DOUBLE,&Value , sizeof(Value), &cbValue);
        SQLGetData(stmt, 4, SQL_C_CHAR, Type, sizeof(Type), &cbType);
        SQLGetData(stmt, 5, SQL_C_SLONG,&cbIsActive , 0, &cbIsActive);

        d.setDiscountId((int)idBuffer);
        d.setCode((char*)Code);
        d.setValue((double)Value);
        d.setType((char*)Type);
        d.setIsActive((int)cbIsActive);
    }
    db.clearStmt();
    return d;
}

void DiscountRepo::update(const Discount& d) {
    std::string query =
        "UPDATE Discount SET "
        "Code = '" + d.getCode() + "', "
        "Value = '" + std::to_string(d.getValue()) + "', "
        "Type = '" + d.getType() + "', "
        "isActive = '" + std::to_string(d.getIsActive()) + "' "
        "WHERE DiscountId = " + std::to_string(d.getDiscountId()) + ";";

    db.execute(query);
}

void DiscountRepo::remove(const int id) {
    std::string query = "DELETE FROM Discount WHERE DiscountId = " + std::to_string(id) + ";";
    db.execute(query);
    db.clearStmt();
}