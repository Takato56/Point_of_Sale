//
// Created by admin on 4/7/2026.
//

#include "StaffRepo.h"

std::string StaffRepo::roleToString(Role r) {
    switch (r) {
        case Staff :  return "Staff";
        case Manager : return "Manager";
        default:     return "Unknown";
    }
}

Role StaffRepo::stringToRole(const std::string& str) {
    if (str == "Staff")  return Role::Staff;
    if (str == "Manager") return Role::Manager;
    return Role::Staff;
}

void StaffRepo::addStaff(const Employee& employee) {
    std::string query =
        "INSERT INTO Staff (EmpId, EmpName, EmpPhoneNumber, PinHash, Role, IsActive) VALUES ("
        + std::to_string(employee.getId()) + ", '"
        + employee.getName() + "', '"
        + employee.getPhoneNumber() + "', '"
        + employee.getPinHash() + "', '"
        + roleToString(employee.getRole()) + "', "
        + std::to_string(employee.getIsActive()) + ");";

    db.execute(query);
    db.clearStmt();
}

std::vector<Employee> StaffRepo::getAll() {
    std::vector<Employee> list;
    db.execute("SELECT EmpId, EmpName, EmpPhoneNumber, PinHash, Role, IsActive FROM Staff;");
    SQLHSTMT stmt = db.getStmt();

    SQLINTEGER idBuffer, isActiveBuffer;
    SQLCHAR nameBuffer[100], phoneBuffer[50], pinHashBuffer[256], roleBuffer[50];

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
        emp.setRole(stringToRole(roleBuffer));
        emp.setIsActive((int)isActiveBuffer);

        list.push_back(emp);
    }
    db.clearStmt();
    return list;
}

Employee StaffRepo::getByID(int id) {
    Employee emp;
    std::string query =
        "SELECT EmpId, EmpName, EmpPhoneNumber, PinHash, Role, IsActive FROM Staff WHERE EmpId="
        + std::to_string(id) + ";";

    db.execute(query);
    SQLHSTMT stmt = db.getStmt();

    if (SQLFetch(stmt) == SQL_SUCCESS) {
        SQLINTEGER idBuffer, isActiveBuffer;
        SQLCHAR nameBuffer[100], phoneBuffer[50], pinHashBuffer[256], roleBuffer[50];

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
        emp.setRole((char*)roleBuffer);
        emp.setIsActive((int)isActiveBuffer);
    }
    db.clearStmt();
    return emp;
}

void StaffRepo::update(const Employee& employee) {
    std::string query =
        "UPDATE Staff SET EmpName='" + employee.getName()
        + "', EmpPhoneNumber='" + employee.getPhoneNumber()
        + "', PinHash='" + employee.getPinHash()
        + "', Role='" + employee.getRole()
        + "', IsActive=" + std::to_string(employee.getIsActive())
        + " WHERE EmpId=" + std::to_string(employee.getId()) + ";";

    db.execute(query);
    db.clearStmt();
}

void StaffRepo::remove(int id) {
    std::string query =
        "DELETE FROM Staff WHERE EmpId=" + std::to_string(id) + ";";

    db.execute(query);
    db.clearStmt();
}