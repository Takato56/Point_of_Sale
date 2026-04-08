    //
    // Created by ntt12 on 4/3/2026.
    //

    #include "ProductRepo.h"
#include "../../utils/DataHelper.h"

    void ProductRepo::addProduct(const Product& pd) {
        int newId = DataHelper::getNextId(db, "Products", "ProdId");

        std::string query =
        "INSERT INTO Products (ProdID, CateId, ProdName, Price) VALUES (" +
        std::to_string(newId) + ", " +
        std::to_string(pd.getCateId()) + ", '" +
        pd.getProdName() + "', " +
        std::to_string(pd.getProdPrice()) + ");";

        std::cout << "[SQL LOG]: " << query << std::endl;
        db.execute(query);
        db.clearStmt();
    }

    std::vector<Product> ProductRepo::getAll() {
        std::vector<Product> list;
        db.execute("SELECT ProdId, CateId, ProdName, Price FROM Products;");
        SQLHSTMT stmt = db.getStmt();

        SQLINTEGER idBuffer, cateId, price;
        SQLCHAR prodName[50];

        while (SQLFetch(stmt) == SQL_SUCCESS) {
            Product pd;
            SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, 0, NULL);
            SQLGetData(stmt, 2, SQL_C_SLONG, &cateId, 0, NULL);
            SQLGetData(stmt, 3, SQL_C_CHAR, prodName, sizeof(prodName), NULL);
            SQLGetData(stmt, 4, SQL_C_SLONG, &price, 0, NULL);

            pd.setProdId((int)idBuffer);
            pd.setCateId((int)cateId);
            pd.setProdName((char*)prodName);
            pd.setProdPrice((int)price);

            list.push_back(pd);
        }
        db.clearStmt();
        return list;
    }

    Product ProductRepo::getByID(const int id) {
        Product pd;
        std::string query = "SELECT ProdId, CateId, ProdName, Price FROM Products WHERE ProdId = " + std::to_string(id) + ";";

        db.execute(query);
        SQLHSTMT stmt = db.getStmt();
        if (SQLFetch(stmt) == SQL_SUCCESS) {
            SQLINTEGER idBuf, cId, prc;
            SQLCHAR nameBuf[50];

            SQLGetData(stmt, 1, SQL_C_SLONG, &idBuf, 0, NULL);
            SQLGetData(stmt, 2, SQL_C_SLONG, &cId, 0, NULL);
            SQLGetData(stmt, 3, SQL_C_CHAR, nameBuf, sizeof(nameBuf), NULL);
            SQLGetData(stmt, 4, SQL_C_SLONG, &prc, 0, NULL);

            pd.setProdId((int)idBuf);
            pd.setCateId((int)cId);
            pd.setProdName((char*)nameBuf);
            pd.setProdPrice((int)prc);
        }
        db.clearStmt();
        return pd;
    }

    void ProductRepo::update(const Product& pd) {
        std::string query =
        "UPDATE Products SET ProdName = '" + pd.getProdName() +
        "', Price = " + std::to_string(pd.getProdPrice()) +
        ", CateId = " + std::to_string(pd.getCateId()) +
        " WHERE ProdId = " + std::to_string(pd.getProdId()) + ";";

        db.execute(query);
        db.clearStmt();
    }

    void ProductRepo::remove(int id) {
        std::string query = "DELETE FROM Products WHERE ProdId = " + std::to_string(id) + ";";
        db.execute(query);
        db.clearStmt();
    }