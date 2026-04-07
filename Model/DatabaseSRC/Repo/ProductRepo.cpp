    //
    // Created by ntt12 on 4/3/2026.
    //

    #include "ProductRepo.h"

    void ProductRepo::addProduct(const Product& pd) {
        std::string query =
            "INSERT INTO Products (ProdID, CateId, ProdName) VALUES "
            "(" + std::to_string(pd.getProdId()) + ", " + std::to_string(pd.getCateId()) +", '" + pd.getProdName() + "');";

        std::cout << query << std::endl;
        db.execute(query);
        db.clearStmt();
    }

    std::vector<Product> ProductRepo::getAll() {
        std::vector<Product> list;
        db.execute("SELECT ProdId, ProdName FROM PRODUCT;");
        SQLHSTMT stmt = db.getStmt();
        SQLINTEGER idBuffer[50];
        SQLCHAR ProdName[20];
        while (SQLFetch(stmt) == SQL_SUCCESS) {
            Product pd;

            SQLGetData(stmt, 1, SQL_C_CHAR, idBuffer, sizeof(idBuffer), NULL);
            SQLGetData(stmt, 3, SQL_C_CHAR, ProdName, sizeof(ProdName), NULL);

            pd.setProdId(*idBuffer);
            pd.setProdName((char*)ProdName);

            list.push_back(pd);
        }
        db.clearStmt();
        return list;
    }

    Product ProductRepo::getByID(const std::string& id) {
        Product pd;
        std::string query =
            "SELECT ProdId, ProdName, ProdPrice FROM PRODUCT WHERE ProdID='" + id + "';";

        db.execute(query);
        SQLHSTMT stmt = db.getStmt();
        if (SQLFetch(stmt) == SQL_SUCCESS) {
            SQLCHAR idBuffer[50];
            SQLCHAR ProdName[20];

            SQLGetData(stmt, 1, SQL_C_CHAR, idBuffer, sizeof(idBuffer), NULL);
            SQLGetData(stmt, 2, SQL_C_CHAR, ProdName, sizeof(ProdName), NULL);

            pd.setProdId(*idBuffer);
            pd.setProdName((char*)ProdName);
        }
        db.clearStmt();
        return pd;
    }

    void ProductRepo::update(const Product& pd) {
        std::string query =
            "UPDATE PRODUCT SET ProdName='" + pd.getProdName()+
            " WHERE ProdId='" + std::to_string(pd.getProdId()) + "';";

        db.execute(query);
        db.clearStmt();
    }

    void ProductRepo::remove(const std::string& id) {
        std::string query =
            "DELETE FROM PRODUCT WHERE ProdId='" + id + "';";

        db.execute(query);
        db.clearStmt();
    }