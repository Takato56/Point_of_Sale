//
// Created by ntt12 on 4/7/2026.
//

#ifndef POINT_OF_SALE_CATEGORIESREPO_H
#define POINT_OF_SALE_CATEGORIESREPO_H
#include <vector>
#include "../DBContext/DBContext.h"
#include "../../Model/entity/Categories.h"

class CategoriesRepo {
private:
    DBContext& db;
public:
    CategoriesRepo(DBContext& db) : db(db) {}
    void addCategories(const Categories& ct) {
        std::string query =
        "INSERT INTO Categories (CateId, CateName, DisplayOrder) VALUES ('" +
            std::to_string(ct.getCateId()) + "', '" + ct.getCateName() + "', '" + ct.getDisplayOrder() + "');";

        db.execute(query);
        db.clearStmt();
    }

    std::vector<Categories> getAll() {
        std::vector<Categories> list;
        db.execute("SELECT CateId, CateName FROM Categories;");
        SQLHSTMT stmt = db.getStmt();
        SQLINTEGER idBuffer;
        SQLCHAR CateName[50];
        SQLLEN cbId, cbName;
        while (SQLFetch(stmt) == SQL_SUCCESS) {
            Categories ct;

            SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, 0, &cbId);
            SQLGetData(stmt, 2, SQL_C_CHAR, CateName, sizeof(CateName), &cbName);

            ct.setCateId((int)idBuffer);
            ct.setCateName((char*)CateName);

            list.push_back(ct);
        }
        db.clearStmt();
        return list;
    }
};


#endif //POINT_OF_SALE_CATEGORIESREPO_H