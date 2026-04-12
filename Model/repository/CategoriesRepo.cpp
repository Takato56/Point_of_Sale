//
// Created by ntt12 on 4/7/2026.
//

#include "CategoriesRepo.h"
#include "../../utils/DataHelper.h"

void CategoriesRepo::addCategories(const Categories& ct) {
    int newId = DataHelper::getNextId(db, "Categories", "CateId");

    std::string query =
    "INSERT INTO Categories (CateId, CateName, DisplayOrder) VALUES ('" +
        std::to_string(newId) + "', '" + ct.getCateName() + "', '" + ct.getDisplayOrder() + "');";

    db.execute(query);
    db.clearStmt();
}

std::vector<Categories> CategoriesRepo::getAll() {
    std::vector<Categories> list;
    db.execute("SELECT CateId, CateName, DisplayOrder FROM Categories;");
    SQLHSTMT stmt = db.getStmt();
    SQLINTEGER idBuffer;
    SQLCHAR CateName[50];
    SQLLEN cbId, cbName, cbDisplayOrder;
    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Categories ct;

        SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, sizeof(idBuffer), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, CateName, sizeof(CateName), &cbName);
        SQLGetData(stmt, 3, SQL_C_SLONG,&cbDisplayOrder , 0, &cbDisplayOrder);

        ct.setCateId((int)idBuffer);
        ct.setCateName((char*)CateName);
        ct.setDisplayOrder((int)cbDisplayOrder);

        list.push_back(ct);
    }
    db.clearStmt();
    return list;
}

Categories CategoriesRepo::getByID(const int id) {
    Categories ct;
    std::string query =
        "SELECT CateId, CateName, DisplayOrder FROM Categories WHERE CateId='" + std::to_string(id) + "';";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();
    if  (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER idBuffer;
        SQLCHAR CateName[50];
        SQLLEN cbId, cbName, cbDisplayOrder;

        SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, 0, &cbId);
        SQLGetData(stmt, 2, SQL_C_CHAR, CateName, sizeof(CateName), &cbName);
        SQLGetData(stmt, 3, SQL_C_SLONG,&cbDisplayOrder , 0, &cbDisplayOrder);

        ct.setCateId((int)idBuffer);
        ct.setCateName((char*)CateName);
        ct.setDisplayOrder((int)cbDisplayOrder);
    }
    db.clearStmt();
    return ct;
}

void CategoriesRepo::update(const Categories &ct) {
    std::string query =
        "UPDATE Categories SET CateName='" + ct.getCateName()+
        " WHERE CateId='" + std::to_string(ct.getCateId()) + "';";

    db.execute(query);
    db.clearStmt();
}

void CategoriesRepo::remove(const int id) {
    std::string query =
        "DELETE FROM Categories WHERE CateId='" + std::to_string(id) + "';";

    db.execute(query);
    db.clearStmt();
}
