#include "CategoriesRepo.h"
#include "../../utils/DataHelper.h"

void CategoriesRepo::addCategories(const Categories& ct) {
    int newId = DataHelper::getNextId(db, "Categories", "CateId");

    std::string query =
        "INSERT INTO Categories (CateId, CateName, DisplayOrder) VALUES ("
        + std::to_string(newId) + ", '"
        + ct.getCateName() + "', "
        + std::to_string(ct.getDisplayOrder()) + ");";

    db.execute(query);
    db.clearStmt();
}

std::vector<Categories> CategoriesRepo::getAll() {
    std::vector<Categories> list;
    db.execute("SELECT CateId, CateName, DisplayOrder FROM Categories;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER idBuffer, displayOrderBuffer;
    SQLCHAR cateName[50];

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Categories ct;
        SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, sizeof(idBuffer), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, cateName, sizeof(cateName), NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &displayOrderBuffer, sizeof(displayOrderBuffer), NULL);

        ct.setCateId(static_cast<int>(idBuffer));
        ct.setCateName(reinterpret_cast<char*>(cateName));
        ct.setDisplayOrder(static_cast<int>(displayOrderBuffer));

        list.push_back(ct);
    }
    db.clearStmt();
    return list;
}

Categories CategoriesRepo::getByID(int id) {
    Categories ct;
    std::string query =
        "SELECT CateId, CateName, DisplayOrder FROM Categories WHERE CateId=" + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER idBuffer, displayOrderBuffer;
        SQLCHAR cateName[50];

        SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, sizeof(idBuffer), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, cateName, sizeof(cateName), NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &displayOrderBuffer, sizeof(displayOrderBuffer), NULL);

        ct.setCateId(static_cast<int>(idBuffer));
        ct.setCateName(reinterpret_cast<char*>(cateName));
        ct.setDisplayOrder(static_cast<int>(displayOrderBuffer));
    }
    db.clearStmt();
    return ct;
}

void CategoriesRepo::update(const Categories& ct) {
    std::string query =
        "UPDATE Categories SET CateName='"
        + ct.getCateName() + "', DisplayOrder="
        + std::to_string(ct.getDisplayOrder())
        + " WHERE CateId=" + std::to_string(ct.getCateId()) + ";";

    db.execute(query);
    db.clearStmt();
}

void CategoriesRepo::remove(int id) {
    std::string query = "DELETE FROM Categories WHERE CateId=" + std::to_string(id) + ";";
    db.execute(query);
    db.clearStmt();
}