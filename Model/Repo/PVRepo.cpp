#include "PVRepo.h"
#include "../../utils/DataHelper.h"

std::string PVRepo::sizeToString(Size s) {
    switch (s) {
        case Small:  return "Small";
        case Medium: return "Medium";
        case Large:  return "Large";
        default:     return "Unknown";
    }
}

Size PVRepo::stringToSize(const std::string& str) {
    if (str == "Small")  return Size::Small;
    if (str == "Medium") return Size::Medium;
    if (str == "Large")  return Size::Large;
    return Size::Small;
}

void PVRepo::addPV(const ProductVariants& pv) {
    int newId = DataHelper::getNextId(db, "ProductVariants", "PVId");

    std::string query =
        "INSERT INTO ProductVariants (PVId, ProdId, SizeLabel, Price) VALUES (" +
        std::to_string(newId) + ", " +
        std::to_string(pv.getProdId()) + ", '" +
        sizeToString(pv.getSize()) + "', " +
        std::to_string(pv.getPrice()) + ");";

    std::cout << "[SQL LOG]: " << query << std::endl;
    db.execute(query);
    db.clearStmt();
}
std::vector<ProductVariants> PVRepo::getAll() {
    std::vector<ProductVariants> list;
    db.execute("SELECT PVId, ProdId, SizeLabel, Price FROM ProductVariants;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER PVId, ProdId, Price;
    SQLCHAR SizeLabel[50];

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        ProductVariants pv;
        SQLGetData(stmt, 1, SQL_C_SLONG, &PVId, sizeof(PVId), NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &ProdId, sizeof(ProdId), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, SizeLabel, sizeof(SizeLabel), NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &Price, sizeof(Price), NULL);

        pv.setPVId((int)PVId);
        pv.setProdId((int)ProdId);
        std::string sizeStr((char*)SizeLabel);
        pv.setSize(stringToSize(sizeStr));
        pv.setPrice((int)Price);

        list.push_back(pv);
    }
    db.clearStmt();
    return list;
}
ProductVariants PVRepo::getByID(int id) {
    ProductVariants pv;
    std::string query = "SELECT PVId, ProdId, SizeLabel, Price FROM ProductVariants WHERE PVId = " + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();
    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER PVId, ProdId, Price;
        SQLCHAR SizeLabel[50];

        SQLGetData(stmt, 1, SQL_C_SLONG, &PVId, sizeof(PVId), NULL);
        SQLGetData(stmt, 2, SQL_C_SLONG, &ProdId, sizeof(ProdId), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, SizeLabel, sizeof(SizeLabel), NULL);
        SQLGetData(stmt, 4, SQL_C_SLONG, &Price, sizeof(Price), NULL);

        pv.setPVId((int)PVId);
        pv.setProdId((int)ProdId);
        std::string sizeStr((char*)SizeLabel);
        pv.setSize(stringToSize(sizeStr));
        pv.setPrice((int)Price);

    }
    db.clearStmt();
    return pv;
}

void PVRepo::update(const ProductVariants& pv) {
    std::string sizeStr = sizeToString(pv.getSize());
    std::string query =
            "UPDATE ProductVariants SET "
            "ProdId = " + std::to_string(pv.getProdId()) + ", "
            "SizeLabel = '" + sizeStr + "', "
            "Price = " + std::to_string(pv.getPrice()) +
            " WHERE PVId = " + std::to_string(pv.getPVId()) + ";";
    std::cout << "[SQL LOG]: " << query << std::endl;

    db.execute(query);
    db.clearStmt();
}

void PVRepo::remove(const int id) {
    std::string query = "DELETE FROM ProductVariants WHERE PVId = " + std::to_string(id) + ";";
    db.execute(query);
    db.clearStmt();
}