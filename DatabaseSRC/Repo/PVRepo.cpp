//
// Created by ntt12 on 4/7/2026.
//

#include "PVRepo.h"

void PVRepo::addPV(const ProductVariants& pv) {
    std::string query =
        "INSERT INTO ProductVariants (PVId, ProdId, SizeLabel, Price) VALUES "
        "(" + std::to_string(pv.getPVId()) + ", " + std::to_string(pv.getProdId()) + "," + pv.getSize() + "," + std::to_string(pv.getPrice()) + ")" "');";

    std::cout << query << std::endl;
    db.execute(query);
    db.clearStmt();
}
std::vector<ProductVariants> PVRepo::getAll() {
    std::vector<ProductVariants> list;
    db.execute("SELECT PVId, ProdId, SizeLabel, Price FROM ProductVariants;");
    SQLHSTMT stmt = db.getStmt();
    SQLCHAR SizeLabel[1];
    SQLLEN pvId, pvPId, pvSize, pvPrice;
    while (SQLFetch(stmt) == SQL_SUCCESS) {
        ProductVariants pv;

        SQLGetData(stmt, 1, SQL_C_CHAR, &pvId, sizeof(pvId), &pvId);
        SQLGetData(stmt, 2, SQL_C_CHAR, &pvPId, sizeof(pvPId), &pvPId);
        SQLGetData(stmt, 3, SQL_C_CHAR, SizeLabel, sizeof(SizeLabel), &pvSize);
        SQLGetData(stmt, 4, SQL_C_CHAR, &pvPrice, sizeof(pvPrice), &pvPrice);

        pv.setPVId((int)pvId);
        pv.setProdId((int)pvPId);
        pv.setSize((char*)pvSize);
        pv.setPrice((int)pvPrice);

        list.push_back(pv);
    }
    db.clearStmt();
    return list;
}
ProductVariants PVRepo::getByID(const std::string& id) {
    ProductVariants pv;
    std::string query =
        "SELECT CateId, CateName, DisplayOrder FROM Categories WHERE CateId='" + id + "';";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();
    if  (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLCHAR SizeLabel[1];
        SQLLEN pvId, pvPId, pvSize, pvPrice;

        SQLGetData(stmt, 1, SQL_C_CHAR, &pvId, sizeof(pvId), &pvId);
        SQLGetData(stmt, 2, SQL_C_CHAR, &pvPId, sizeof(pvPId), &pvPId);
        SQLGetData(stmt, 3, SQL_C_CHAR, SizeLabel, sizeof(SizeLabel), &pvSize);
        SQLGetData(stmt, 4, SQL_C_CHAR, &pvPrice, sizeof(pvPrice), &pvPrice);

        pv.setPVId((int)pvId);
        pv.setProdId((int)pvPId);
        pv.setSize((char*)pvSize);
        pv.setPrice((int)pvPrice);
    }
    db.clearStmt();
    return pv;
}
void PVRepo::update(const ProductVariants& pv) {
    std::string query =
        "UPDATE ProductVariants SET SizeLabel='" + pv.getSize()+
        " WHERE PVId='" + std::to_string(pv.getPVId()) + "';";

    db.execute(query);
    db.clearStmt();
}
void PVRepo::remove(const std::string& id) {
    std::string query =
        "DELETE FROM ProductVariants WHERE PVId='" + id + "';";

    db.execute(query);
    db.clearStmt();
}