//
// Created by admin on 4/7/2026.
//

#include "StaffRepo.h"

std::string StaffRepo::roleToString(Role r) {
    switch (r) {
        case Role_Staff:   return "Staff";
        case Role_Manager: return "Manager";
        default:      return "Staff";
    }
}

Role StaffRepo::stringToRole(const std::string& str) {
    if (str == "Staff")   return Role::Role_Staff;
    if (str == "Manager") return Role::Role_Manager;
    return Role::Role_Staff;
}

void StaffRepo::addStaff(Employee& employee) {
    int newId = DataHelper::getNextId(db, "Staffs", "StaffId");
    employee.setId(newId);
    std::string roleStr = roleToString(employee.getRole());

    if (roleStr != "Staff" && roleStr != "Manager") {
        roleStr = "Staff";
    }

    std::string query =
        "INSERT INTO Staffs (StaffId, StaffName, StaffPhone, PinHash, Role, isActive) VALUES ("
        + std::to_string(employee.getId()) + ", '"
        + employee.getName() + "', '"
        + employee.getPhoneNumber() + "', '"
        + employee.getPinHash() + "', '"
        + roleStr + "', "
        + std::to_string(employee.getIsActive()) + ");";

    db.execute(query);
    db.clearStmt();
}

std::vector<Employee> StaffRepo::getAll() {
    std::vector<Employee> list;
    db.execute("SELECT StaffId, StaffName, StaffPhone, PinHash, Role, isActive FROM Staffs;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER idBuffer, isActiveBuffer;
    SQLCHAR nameBuffer[100], phoneBuffer[10], pinHashBuffer[100], roleBuffer[10];

    while (SQLFetch(stmt) == SQL_SUCCESS) {
        Employee emp;

        SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, sizeof(idBuffer), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, nameBuffer, sizeof(nameBuffer), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, phoneBuffer, sizeof(phoneBuffer), NULL);
        SQLGetData(stmt, 4, SQL_C_CHAR, pinHashBuffer, sizeof(pinHashBuffer), NULL);
        SQLGetData(stmt, 5, SQL_C_CHAR, roleBuffer, sizeof(roleBuffer), NULL);
        SQLGetData(stmt, 6, SQL_C_SLONG, &isActiveBuffer, sizeof(isActiveBuffer), NULL);

        emp.setId((int)idBuffer);
        emp.setName((char*)nameBuffer);
        emp.setPhoneNumber((char*)phoneBuffer);
        emp.setPinHash((char*)pinHashBuffer);
        std::string roleStr((char*)roleBuffer);
        emp.setRole(stringToRole(roleStr));
        emp.setIsActive((int)isActiveBuffer);

        list.push_back(emp);
    }
    db.clearStmt();
    return list;
}

Employee StaffRepo::getById(int id) {
    Employee emp;
    std::string query =
        "SELECT StaffId, StaffName, StaffPhone, PinHash, Role, isActive FROM Staffs WHERE StaffId="
        + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER idBuffer, isActiveBuffer;
        SQLCHAR nameBuffer[50], phoneBuffer[10], pinHashBuffer[100], roleBuffer[10];

        SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, sizeof(idBuffer), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, nameBuffer, sizeof(nameBuffer), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, phoneBuffer, sizeof(phoneBuffer), NULL);
        SQLGetData(stmt, 4, SQL_C_CHAR, pinHashBuffer, sizeof(pinHashBuffer), NULL);
        SQLGetData(stmt, 5, SQL_C_CHAR, roleBuffer, sizeof(roleBuffer), NULL);
        SQLGetData(stmt, 6, SQL_C_SLONG, &isActiveBuffer, sizeof(isActiveBuffer), NULL);

        emp.setId((int)idBuffer);
        emp.setName((char*)nameBuffer);
        emp.setPhoneNumber((char*)phoneBuffer);
        emp.setPinHash((char*)pinHashBuffer);
        std::string roleStr((char*)roleBuffer);
        emp.setRole(stringToRole(roleStr));
        emp.setIsActive((int)isActiveBuffer);
    }
    db.clearStmt();
    return emp;
}

Employee StaffRepo::getByPhone(const std::string& phone) {
    Employee emp;
    std::string query =
        "SELECT StaffId, StaffName, StaffPhone, PinHash, Role, isActive FROM Staffs WHERE StaffPhone='"
        + phone + "';";
    db.execute(query);
    SQLHSTMT stmt = db.getStmt();
    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER idBuffer, isActiveBuffer;
        SQLCHAR nameBuffer[50], phoneBuffer[10], pinHashBuffer[100], roleBuffer[10];

        SQLGetData(stmt, 1, SQL_C_SLONG, &idBuffer, sizeof(idBuffer), NULL);
        SQLGetData(stmt, 2, SQL_C_CHAR, nameBuffer, sizeof(nameBuffer), NULL);
        SQLGetData(stmt, 3, SQL_C_CHAR, phoneBuffer, sizeof(phoneBuffer), NULL);
        SQLGetData(stmt, 4, SQL_C_CHAR, pinHashBuffer, sizeof(pinHashBuffer), NULL);
        SQLGetData(stmt, 5, SQL_C_CHAR, roleBuffer, sizeof(roleBuffer), NULL);
        SQLGetData(stmt, 6, SQL_C_SLONG, &isActiveBuffer, sizeof(isActiveBuffer), NULL);

        emp.setId((int)idBuffer);
        emp.setName((char*)nameBuffer);
        emp.setPhoneNumber((char*)phoneBuffer);
        emp.setPinHash((char*)pinHashBuffer);
        std::string roleStr((char*)roleBuffer);
        emp.setRole(stringToRole(roleStr));
        emp.setIsActive((int)isActiveBuffer);
    }
    db.clearStmt();
    return emp;
}

void StaffRepo::update(const Employee& employee) {
    std::string roleStr = roleToString(employee.getRole());
    std::string query =
        "UPDATE Staffs SET StaffName='" + employee.getName()
        + "', StaffPhone='" + employee.getPhoneNumber()
        + "', PinHash='" + employee.getPinHash()
        + "', Role='" + roleStr
        + "', isActive=" + std::to_string(employee.getIsActive())
        + " WHERE StaffId=" + std::to_string(employee.getId()) + ";";

    db.execute(query);
    db.clearStmt();
}

void StaffRepo::remove(int id) {
    std::string query =
        "DELETE FROM Staffs WHERE StaffId=" + std::to_string(id) + ";";

    db.execute(query);
    db.clearStmt();
}