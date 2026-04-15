//
// Created by ntt12 on 4/14/2026.
//

#include "ModifierRepo.h"
#include "../../utils/DataHelper.h"
#include <iostream>

void ModifierRepo::addModifier(const Modifiers &m) {
    std::string query =
        "INSERT INTO Modifiers (ModifierId, Name, Price) VALUES ("
        + std::to_string(m.getModId()) + ", "
        + m.getModName() + ", "
        + std::to_string(m.getExtraCost()) + ");";

    std::cout << "[SQL LOG]: " << query << std::endl;
    db.execute(query);
    db.clearStmt();
}

std::vector<Modifiers> ModifierRepo::getAll() {
    std::vector<Modifiers> list;
    db.execute("SELECT ModId, ModName, ExtraCost, Type FROM Modifiers;");
    SQLHSTMT stmt = db.getStmt();

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Modifiers m;
        SQLINTEGER modId, extraCost;
        SQLCHAR modName[50], modType[20];
        SQLGetData(stmt, 1, SQL_C_SLONG, &modId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, &modName, sizeof(modName), NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &extraCost, 0, NULL);
        SQLGetData(stmt, 4, SQL_C_CHAR, modType, sizeof(modType), NULL);

        m.setModId((int)modId);
        m.setModName((char*)modName);
        m.setExtraCost((int)extraCost);
        m.setModType((char*)modType);
        list.push_back(m);
    }

    db.clearStmt();
    return list;
}

Modifiers ModifierRepo::getByID(int id) {
    Modifiers m;
    std::string query =
        "SELECT ModId, ModName, ExtraCost FROM Modifiers WHERE ModId = "
        + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER modId, extraCost;
        SQLCHAR modName[50];
        SQLGetData(stmt, 1, SQL_C_SLONG, &modId, 0, NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, &modName, sizeof(modName), NULL);
        SQLGetData(stmt, 3, SQL_C_SLONG, &extraCost, 0, NULL);

        m.setModId((int)modId);
        m.setModName((char*)modName);
        m.setExtraCost((int)extraCost);
    }

    db.clearStmt();
    return m;
}

void ModifierRepo::update(const Modifiers &m) {
    std::string query =
        "UPDATE Modifiers SET "
        "ModId = " + std::to_string(m.getModId()) + ", "
        "ModName = '" + m.getModName() + "', "
        "ExtraCost = " + std::to_string(m.getExtraCost()) + " "
        "WHERE ModId = " + std::to_string(m.getModId()) + ";";
}

void ModifierRepo::remove(int id) {
    std::string query = "DELETE FROM Modifiers WHERE ModId = " + std::to_string(id) + ";";
    db.execute(query);
    db.clearStmt();
}
