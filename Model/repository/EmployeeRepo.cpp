//
// Created by ntt12 on 4/8/2026.
//

#include "EmployeeRepo.h"
#include "../../utils/PasswordHasher.h"

void EmployeeRepo::addEmployee(Employee& employee) {
    int newId = DataHelper::getNextId(db, "Staffs", "StaffId");
    employee.setId(newId);

    std::string roleStr;
    switch (employee.getRole()) {
        case Manager: roleStr = "Manager"; break;
        default:      roleStr = "Staff";   break;
    }

    std::string query =
        "INSERT INTO Staffs (StaffId, StaffName, StaffPhone, PinHash, Role, isActive) VALUES ("
        + std::to_string(newId) + ", '"
        + employee.getName() + "', '"
        + employee.getPhoneNumber() + "', '"
        + employee.getPinHash() + "', '"
        + roleStr + "', "
        + std::to_string(employee.getIsActive()) + ");";

    db.execute(query);
    db.clearStmt();
}

std::vector<Employee> EmployeeRepo::getAll() {
    std::vector<Employee> list;
    db.execute("SELECT StaffId, StaffName, StaffPhone, PinHash, Role, isActive FROM Staffs;");
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
        emp.setRole(roleStr == "Manager" ? Manager : Staff);
        emp.setIsActive((int)isActiveBuffer);

        list.push_back(emp);
    }
    db.clearStmt();
    return list;
}

Employee EmployeeRepo::getById(int id) {
    Employee emp;
    std::string query =
        "SELECT StaffId, StaffName, StaffPhone, PinHash, Role, isActive FROM Staffs WHERE StaffId="
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
        std::string roleStr((char*)roleBuffer);
        emp.setRole(roleStr == "Manager" ? Manager : Staff);
        emp.setIsActive((int)isActiveBuffer);
    }
    db.clearStmt();
    return emp;
}

void EmployeeRepo::update(const Employee& e) {
    std::string roleStr;
    switch (e.getRole()) {
        case Manager: roleStr = "Manager"; break;
        default:      roleStr = "Staff";   break;
    }

    std::string query =
        "UPDATE Staffs SET StaffName='" + e.getName()
        + "', StaffPhone='" + e.getPhoneNumber()
        + "', Role='" + roleStr
        + "', isActive=" + std::to_string(e.getIsActive())
        + " WHERE StaffId=" + std::to_string(e.getId()) + ";";

    db.execute(query);
    db.clearStmt();
}

void EmployeeRepo::remove(int id) {
    std::string query =
        "DELETE FROM Staffs WHERE StaffId=" + std::to_string(id) + ";";

    db.execute(query);
    db.clearStmt();
}