//
// Created by ntt12 on 4/3/2026.
//

#ifndef POINT_OF_SALE_PRODUCTREPO_H
#define POINT_OF_SALE_PRODUCTREPO_H

#include "Product.h"
#include <vector>
#include "DatabaseSRC/DBContext/DBContext.h"
class ProductRepo {
private:
    DBContext& db;
public:
    ProductRepo(DBContext& context) : db(context) {}
    void addProduct(const Product& pd) {
        std::string query =
            "INSERT INTO PRODUCT (ProdID, ProdName, ProdPrice) VALUES ('" +
            pd.getProdId() + "', '" +
            pd.getProdName() + "', " +
            std::to_string(pd.getProdPrice()) + ");";

        db.execute(query);
        db.clearStmt();
    }

    std::vector<Product> getAll() {
        std::vector<Product> list;
        db.execute("SELECT ProdID, ProdName, ProdPrice FROM PRODUCT;");
        SQLHSTMT stmt = db.getStmt();
        SQLCHAR idBuffer[50];
        SQLCHAR ProdName[20];
        SQLINTEGER ProdPrice;
        while (SQLFetch(stmt) == SQL_SUCCESS) {
            Product pd;

            SQLGetData(stmt, 1, SQL_C_CHAR, idBuffer, sizeof(idBuffer), NULL);
            SQLGetData(stmt, 2, SQL_C_CHAR, ProdName, sizeof(ProdName), NULL);
            SQLGetData(stmt, 3, SQL_C_LONG, &ProdPrice, 0, NULL);

            pd.setProdId((char*)idBuffer);
            pd.setProdName((char*)ProdName);
            pd.setProdPrice(ProdPrice);

            list.push_back(pd);
        }
        db.clearStmt();
        return list;
    }
    Product getByID(const std::string& id) {
        Product pd;
        std::string query =
            "SELECT ProdID, ProdName, ProdPrice FROM PRODUCT WHERE ProdID='" + id + "';";

        db.execute(query);
        SQLHSTMT stmt = db.getStmt();
        if (SQLFetch(stmt) == SQL_SUCCESS) {
            SQLCHAR idBuffer[50];
            SQLCHAR ProdName[20];
            SQLINTEGER ProdPrice;

            SQLGetData(stmt, 1, SQL_C_CHAR, idBuffer, sizeof(idBuffer), NULL);
            SQLGetData(stmt, 2, SQL_C_CHAR, ProdName, sizeof(ProdName), NULL);
            SQLGetData(stmt, 3, SQL_C_LONG, &ProdPrice, 0, NULL);

            pd.setProdId((char*)idBuffer);
            pd.setProdName((char*)ProdName);
            pd.setProdPrice(ProdPrice);
        }
        db.clearStmt();
        return pd;
    }
    void update(const Product& pd) {
        std::string query =
            "UPDATE PRODUCT SET ProdName='" + pd.getProdName()+
            "', ProdPrice=" + std::to_string(pd.getProdPrice()) +
            " WHERE ProdID='" + pd.getProdId() + "';";

        db.execute(query);
        db.clearStmt();
    }
    void remove(const std::string& id) {
        std::string query =
            "DELETE FROM PRODUCT WHERE ProdID='" + id + "';";

        db.execute(query);
        db.clearStmt();
    }
};

#endif //POINT_OF_SALE_PRODUCTREPO_H